/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 *
 * @addtogroup data_acquisition
 *
 * @{
 */
#include "fpga.h"
#include "DataAcquisition.h"
#include <stdint.h>
#include "Config/Config.h"
#include "tof_cos_cpu.h"
#include "tof_cos_timestamp.h"
#include "tof_cos_io.h"
#include "tof_cos_sys_timer.h"
#include "ChipControl/ChipControl.h"
#include "RamManager/RamManager.h"
#include "Calculation/Calculation.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief Constructor
 *
 * @param context Pointer to the context
 */
DataAcquisition::DataAcquisition(TOF_COS_Context *context):
context(context)
{
  state = DataAcquisitionState_e::DATA_ACQUISITION_STATE_IDLE;
  data = DataAcquisitionData_e::DATA_ACQUISITION_DATA_NONE;
  status = TypeInternalReturnValue::STATUS_OK;
  temperatureCompensationEnabled = false;
  doTemperatureFilter = false;
  timestampAtTemperatureMeasurement = 0;
  timestampAtAcquisition = 0;

  fpgaRegisterCallback(DataAcquisition::interruptCallback, this);
}

/**
 * @brief Init
 *
 * Call this function before using this class.
 *
 * @retval STATUS_OK Init OK
 * @retval STATUS_ERROR_DCMI Init failed
 * @return Init result
 */
TypeInternalReturnValue DataAcquisition::init()
{
	int8_t status = fpgaInit();
	if (status < 0)
	{
		return TypeInternalReturnValue::STATUS_ERROR_DCMI;
		/*** Exit here -------------------------------------------> ***/
	}
	return TypeInternalReturnValue::STATUS_OK;
}

/**
 * @brief Update meta data
 *
 * Updates the meta data at acquisition time.
 */
void DataAcquisition::updateMetaData()
{
	acquisitionInfo.roi = context->config->getRoi();
	//acquisitionInfo.illumination = context->config->getIndexIllumination();
	//acquisitionInfo.integrationTime3d = context->config->getIntegrationTime3d();
	acquisitionInfo.integrationTimeGrayscale = context->config->getIntegrationTimeGrayscale();
	acquisitionInfo.integrationTimeMultiplier = context->chipControl->getIntegrationTimeMultiplier();
	//acquisitionInfo.modulation = context->config->getModulation();
	acquisitionInfo.binning = context->config->getBinning();
	//acquisitionInfo.hdr = context->config->getHdr();
	//acquisitionInfo.digitalBinning = context->config->getDigitalBinning();
	acquisitionInfo.dllStep = context->config->getDllStep();
}

/**
 * @brief Update pointers
 *
 * Call this function, if the pointers to the memory need to change or for initialization.
 *
 * @param ramManager Reference to the Ram Manager which gives all the pointers
 */
void DataAcquisition::updatePointers()
{
  memoryGrayscaleOrDcs = context->ramManager->getInputMemoryGrayscale();
	memoryDcs = context->ramManager->getInputMemoryDCS();

	memoryResultGrayscale = context->ramManager->getResultMemoryGrayscale();
	memoryResult3d0 = context->ramManager->getResultMemory3d0();
	memoryResult3d1 = context->ramManager->getResultMemory3d1();

	memorySgGrayscale = context->ramManager->getSgMemoryGrayscale();
	memorySg3d0 = context->ramManager->getSgMemory3d0();
	memorySg3d1 = context->ramManager->getSgMemory3d1();
}

/**
 * @brief Update Acquisition settings
 *
 * The settings needed for the acquisition with the FPGA soft logic are updated here.
 * Specially the things regarding the selected ROI are important.
 *
 * @param bytesPerPixel Number of bytes per pixel
 */
void DataAcquisition::updateAcquisitionSettings(const uint32_t bytesPerPixel)
{
  fpgaAcquisitionSettings.width = context->config->getWidth();
  fpgaAcquisitionSettings.height = context->config->getHeight();
  fpgaAcquisitionSettings.sensorHeight = context->config->getBinning().getBinnedHeight(HEIGTH);
  fpgaAcquisitionSettings.sensorWidth = context->config->getBinning().getBinnedWidth(WIDTH);
  fpgaAcquisitionSettings.numBytes = context->config->getNumPixel() * bytesPerPixel;
}

/**
 * @brief Prepare the soft logic compensations
 *
 * This procedure prepares the soft logic for the compensations:
 * - Grayscale
 * - Ambient Light
 */
void DataAcquisition::setupGrayscaleAmbientLightCompensationSettings()
{
  if (context->config->getAmbientLightCompensationEnabled())
  {
    //Subtract only works and only is needed if compensation is disabled.
    fpgaSetGrayscaleCompensationEnabled(true);
    fpgaSetGrayscaleSubtractEnabled(false);

    context->ambientLightCompensation.loadFpga(context->chipControl->getIntegrationTimeMultiplier());
    fpgaSetAmbientCorrectionEnabled(true);
  }
  else if (context->config->getGrayscaleCompensationEnabled())
  {
    fpgaSetGrayscaleCompensationEnabled(true);
    fpgaSetGrayscaleSubtractEnabled(false);
    fpgaSetAmbientCorrectionEnabled(false);
  }
  else
  {
    //Subtract seems not to work properly in the soft logic, so do not use it
    fpgaSetGrayscaleCompensationEnabled(false);
    fpgaSetGrayscaleSubtractEnabled(false);
    fpgaSetAmbientCorrectionEnabled(false);
  }
}

/**
 * @brief Start an interrupt controlled grayscale acquisition
 *
 * This function starts an acquisition grayscale data. When the data is in the memory, an
 * interrupt will occur.
 */
void DataAcquisition::startGrayscaleImage()
{
  //Wait in case of an image is acquired in the background
	(void)waitBlocking();

	updatePointers();
	updateMetaData();

	//Base settings for grayscale and 3D that have an impact on image/data size
	context->config->loadBaseChipSettings();

	//Write the settings that do not have a shadow register
	context->chipControl->setToGrayscaleUnShadowed();

	//Load the specific grayscale settings
	context->config->loadGrayscaleSettings();

	//Update RAM manager
	context->ramManager->setSize(context->config->getWidth(), context->config->getHeight());

	//Store settings needed in the soft logic / in the IRQ routine
	updateAcquisitionSettings(sizeof(uint32_t));

	state = DataAcquisitionState_e::DATA_ACQUISITION_STATE_GRAYSCALE_ONLY;
	data = DataAcquisitionData_e::DATA_ACQUISITION_DATA_NONE;

	//Get the grayscale compensation address from the grayscale calibration
	volatile uint32_t *pCalibration_GS = context->grayscaleCompensation.getCalibrationAddress();

	setupGrayscaleAmbientLightCompensationSettings();

	fpgaStartGrayscale(memoryGrayscaleOrDcs, memoryResultGrayscale, memorySgGrayscale, pCalibration_GS, const_cast<fpgaAcquisitionSettings_t &>(fpgaAcquisitionSettings));

	timestampAtAcquisition = tofCosTimestampGetMsCounter();

	if (context->config->getExternalShutter() == false)
	{
	  context->chipControl->sendShutter();
	}
}

/**
 * @brief Start an interrupt controlled 3D/grayscale acquisition
 *
 * This function starts acquisitions of 3D data and grayscale data. The first acquisition is grayscale
 * and is started here. The following acquisitions are started in the interrupt function. The grayscale
 * acquisition is used to read the temperature and to do ambient light compensation.
 *
 * @param dualIntegrationTime true, if two integration times should be used
 */
void DataAcquisition::start3dGrayscaleImage(const bool dualIntegrationTime)
{
	bool doDrnuCompensation = true;

	//Wait in case of an image is acquired in the background
	(void)waitBlocking();

	//Preparation
	updatePointers();
	updateMetaData();
	context->ramManager->setSize(context->config->getWidth(), context->config->getHeight());
	int32_t totalOffset = context->config->getOffset();
	temperatureCompensationEnabled = context->config->getTemperatureCompenastionEnabled();

	//Filter the temperature for the temperature compensation only if the last measurement was not to long ago
	if (dataIsTooOld(timestampAtTemperatureMeasurement))
	{
		doTemperatureFilter = false;
	}
	else
	{
		doTemperatureFilter = true;
	}

	//Check for compensation
	indexCompensation = context->config->getIndexCompensation();
  if ((indexCompensation < 0) || (context->config->getDrnuCompensationEnabled() == false))
  {
  	doDrnuCompensation = false;
  }

  //Setup the system depending on the compensation settings
	if (context->config->getAmbientLightCompensationEnabled())
	{
    //Base settings for grayscale and 3D that have an impact on image/data size
		context->config->loadBaseChipSettings();

		//Write the settings that do not have a shadow register
		context->chipControl->setToGrayscaleUnShadowed();

		//Load the specific grayscale settings
		context->config->loadGrayscaleSettings();
	}
	else if (doDrnuCompensation)
	{
		if (temperatureCompensationEnabled)
		{
		  //Load these settings to get the smallest image possible with the shortest integration time; --> just to read the temperature
		  context->config->loadSettingsGrayscaleForTemperatureOnly();

		  context->chipControl->sendShutter();
		}

		//While the acquisition is ongoing, write the values that have shadow registers in the chip.
		context->config->loadBaseChipSettings();
		context->config->load3dSettings(0);

		if (temperatureCompensationEnabled)
		{
		  //Do a delay that is enough so that the chip has sent all data --> we don't use the data
		  usleep(500);

		  //Now the temperature is available
		  acquisitionInfo.temperature = context->chipControl->readTemperature();

		  //Now the offset can be calculated because the temperature is available
		  totalOffset += context->temperatureCompensation[indexCompensation].getTemperatureOffset(acquisitionInfo.temperature, acquisitionInfo.dllStep, true, doTemperatureFilter);
		}

		totalOffset += context->drnuCompensation[indexCompensation].getOffset();

		context->chipControl->setTo3dUnShadowed();
	}
	else
	{
		context->config->loadBaseChipSettings();

		context->chipControl->setTo3dUnShadowed();

    context->config->load3dSettings(0);
	}


	//If DRNU compensation is enabled, let it configure the FPGA. Else let the config class configure the FPGA without compensation
	if (doDrnuCompensation == false)
	{
	  context->config->loadFpgaWithoutDrnuCompensation();
	}
	else
	{
    context->drnuCompensation[indexCompensation].loadFpga();
	}

	//Store settings needed in the soft logic / in the IRQ routine
	updateAcquisitionSettings(sizeof(uint32_t));

	this->dualIntegrationTime = dualIntegrationTime;
	data = DataAcquisitionData_e::DATA_ACQUISITION_DATA_NONE;

	setupGrayscaleAmbientLightCompensationSettings();

  //Arm the FPGA
	if (context->config->getAmbientLightCompensationEnabled())
	{
		//Get the grayscale compensation address from the grayscale calibration
		volatile uint32_t *pCalibration_GS = context->grayscaleCompensation.getCalibrationAddress();

		fpgaStartGrayscale(memoryGrayscaleOrDcs, memoryResultGrayscale, memorySgGrayscale, pCalibration_GS, const_cast<fpgaAcquisitionSettings_t &>(fpgaAcquisitionSettings));

		state = DataAcquisitionState_e::DATA_ACQUISITION_STATE_3D_GRAYSCALE;
	}
	else
	{
		//Set the offset here already because we start directly with the 3D image
		fpgaSetPostCorrectionOffset(totalOffset);

		fpgaStartDistanceAmplitude(memoryGrayscaleOrDcs, memoryDcs, memoryResult3d0, memorySg3d0, const_cast<fpgaAcquisitionSettings_t &>(fpgaAcquisitionSettings));

		state = DataAcquisitionState_e::DATA_ACQUISITION_STATE_3D_FIRST_INTEGRATION_TIME;
	}


	timestampAtAcquisition = tofCosTimestampGetMsCounter();
	timestampAtTemperatureMeasurement = tofCosTimestampGetMsCounter();

	//Do the shutter only if it is not set to external
	if (context->config->getExternalShutter() == false)
	{
	  tofCosIoDisarmExternalShutter();

		context->chipControl->sendShutter();

		if (context->config->getAmbientLightCompensationEnabled())
		{
		  //Already load the settings for the 3D while the acquisition has started. The chip has shadow registers to store the new settings.
	    context->config->load3dSettings(0);
		}
		else if (dualIntegrationTime)
		{
		  context->config->load3dSettings(1);
		}
	}
	else
	{
	  tofCosIoArmExternalShutter();
	}
}

/**
 * @brief Start an interrupt controlled acquisition
 *
 * This function starts acquisitions of 3D data without compensation. This is used during the calibration procedure. When the data is in the memory, an
 * interrupt will occur.
 */
void DataAcquisition::start3dImageForCalibration()
{
	//Wait in case of an image is acquired in the background
	(void) waitBlocking();

	//Base settings for grayscale and 3D that have an impact on image/data size
	context->config->loadBaseChipSettings();

	//Write the settings that do not have a shadow register
	context->chipControl->setTo3dUnShadowed();

	//Update the settings
	context->config->load3dSettings(0);

	//The Offset here has to be set before the acquisition, because the FPGA does this on the fly
	fpgaSetPostCorrectionOffset(0);

	updatePointers();
	updateMetaData();

	context->ramManager->setSize(context->config->getWidth(), context->config->getHeight());

  //Store settings needed in the soft logic / in the IRQ routine
  updateAcquisitionSettings(sizeof(uint32_t));

	this->dualIntegrationTime = false;

	state = DataAcquisitionState_e::DATA_ACQUISITION_STATE_3D_ONLY;
	data = DataAcquisitionData_e::DATA_ACQUISITION_DATA_NONE;

	//Disable all compensations
	fpgaSetGrayscaleCompensationEnabled(false);
	fpgaSetGrayscaleSubtractEnabled(false);
	fpgaSetAmbientCorrectionEnabled(false);

	fpgaStartDistanceAmplitude(memoryGrayscaleOrDcs, memoryDcs, memoryResult3d0, memorySg3d0, const_cast<fpgaAcquisitionSettings_t &>(fpgaAcquisitionSettings));

	timestampAtAcquisition = tofCosTimestampGetMsCounter();

	if (context->config->getExternalShutter() == false)
	{
	  context->chipControl->sendShutter();
	}
}

/**
 * @brief Start an interrupt controlled acquisition of DCS only data
 *
 * This function starts acquisitions of 3D DCS data. This is used during the calibration procedure.
 *
 * So far this is a blocking procedure because there is no interrupt possibility yet.
 *
 * @param omitChipConfig Set to true to omit the configuration of the chip
 */
void DataAcquisition::startDcs(const bool omitChipConfig)
{
  //Wait in case of an image is acquired in the background
	(void) waitBlocking();

	if (omitChipConfig == false)
	{
	  //Base settings for grayscale and 3D that have an impact on image/data size
	  context->config->loadBaseChipSettings();

	  //Write the settings that do not have a shadow register
	  context->chipControl->setTo3dUnShadowed();

	  //Update the settings
	  context->config->load3dSettings(0);
	}

	//The Offset here has to be set before the acquisition, because the FPGA does this on the fly
	fpgaSetPostCorrectionOffset(0);

	updatePointers();
	updateMetaData();

	context->ramManager->setSize(context->config->getWidth(), context->config->getHeight());

  //Store settings needed in the soft logic / in the IRQ routine
  updateAcquisitionSettings(sizeof(uint32_t) * 4); //4DCS

	this->dualIntegrationTime = false;

	state = DataAcquisitionState_e::DATA_ACQUISITION_STATE_DCS_POLLING;
	data = DataAcquisitionData_e::DATA_ACQUISITION_DATA_NONE;

	//Disable all compensations
	fpgaSetGrayscaleCompensationEnabled(false);
	fpgaSetGrayscaleSubtractEnabled(false);
	fpgaSetAmbientCorrectionEnabled(false);

	fpgaStartDCS(memoryGrayscaleOrDcs, fpgaAcquisitionSettings.width, fpgaAcquisitionSettings.height, fpgaAcquisitionSettings.numBytes);

	timestampAtAcquisition = tofCosTimestampGetMsCounter();

	if (context->config->getExternalShutter() == false)
	{
	  context->chipControl->sendShutter();
	}
}

/**
 * @brief Read back if the acquisition is finished
 *
 * @retval true Acquisition is finished
 * @retval false Acquisition still busy
 * @return Acquisition finished or not
 */
bool DataAcquisition::isFinished()
{
	//The DCS mode works with polling while the other modes work interrupt driven. So here we have to handle two situations
  if (state == DataAcquisitionState_e::DATA_ACQUISITION_STATE_DCS_POLLING)
	{
	  //Here finish the acquisition with invalidating the cache
    if (fpgaAcquisitionIsBusy() == false)
	  {
	    state = DataAcquisitionState_e::DATA_ACQUISITION_STATE_IDLE;
	    data = DataAcquisitionData_e::DATA_ACQUISITION_DATA_DCS;
	    tofCosCpuInvalidateDCachebyAddrU32((uint32_t *)memoryGrayscaleOrDcs, fpgaAcquisitionSettings.numBytes);
	    return true;
	  }
	  else
	  {
	    return false;
	  }
	}
	else if (state == DataAcquisitionState_e::DATA_ACQUISITION_STATE_IDLE)
	{
		return true;
	}

	return false;
}

/**
 * @brief Wait until the acquisition is finished in a blocking way
 *
 * @retval TypeInternalReturnValue::STATUS_ERROR_DCMI Acquisition timed out
 * @retval TypeInternalReturnValue::STATUS_ERROR_DCMI Acquisition finished normally
 * @return Acquisition status
 */
TypeInternalReturnValue DataAcquisition::waitBlocking()
{
	while ((isFinished() == false) &&
				   (dataIsTooOld(timestampAtAcquisition) == false))
	{
	}

	int8_t status = fpgaWaitAcquisitionBlocking(DCMI_TIMEOUT);
	if (status < 0)
	{
	  return TypeInternalReturnValue::STATUS_ERROR_DCMI;
	}/*** Exit here -------------------------------------------> ***/


  return TypeInternalReturnValue::STATUS_OK;
}

/**
 * @brief Read back, if the desired data is in the memory
 *
 * If the data is too old (too much time passed since acquisition), it is not used any more.
 *
 * @param data Data desired data type
 * @retval true Desired data type is in the memory
 * @retval false Desired data type is not in the memory or is too old
 * @return Desired data type in memory or not
 */
bool DataAcquisition::hasAcquired(const DataAcquisitionData_e data)
{
  //Too much time has passed since the acquisition. So do not use the data.
	if ((context->config->getExternalShutter() == false) && (dataIsTooOld(timestampAtAcquisition)))
  {
  	return false;
  }/* ------------------------------------------------->*/

	//Not the desired type
	if (this->data == data)
  {
  	return true;
  }/* ------------------------------------------------->*/

  return false;
}

/**
 * @brief Clear the data
 *
 * Call this function if there is already data acquired and it should be cleared.
 */
void DataAcquisition::clear()
{
	data = DataAcquisitionData_e::DATA_ACQUISITION_DATA_NONE;
}

/**
 * @brief Get the pointer to the 3D data
 *
 * When the acquisition is still running, this function blocks, until the data is ready.
 *
 * @param data Pointer to the pointer to set the 3D data
 */
void DataAcquisition::get3dData(uint32_t **data)
{
  //Wait in case of an image is acquired in the background
	(void)waitBlocking();

	*data = const_cast<uint32_t *>(memoryResult3d0);
}

/**
 * @brief Get the pointer to the 3D data for temporal HDR
 *
 * When the acquisition is still running, this function blocks, until the data is ready.
 *
 * @param data0 Pointer to the pointer to set the data from the first integration time
 * @param data1 Pointer to the pointer to set the data from the second integration time
 */
void DataAcquisition::get3dDataTemporalHdr(uint32_t **data0, uint32_t **data1)
{
	//Wait in case of an image is acquired in the background
	(void)waitBlocking();

	*data0 = (uint32_t *)(memoryResult3d0);
	*data1 = (uint32_t *)(memoryResult3d1);
}

/**
 * @brief Get the pointer to the grayscale data
 *
 * When the acquisition is still running, this function blocks, until the data is ready.
 *
 * @param data Pointer to the pointer to set the grayscale data
 */
void DataAcquisition::getGrayscaleData(uint32_t **data)
{
	//Wait in case of an image is acquired in the background
	(void)waitBlocking();

	*data = (uint32_t *)(memoryResultGrayscale);
}

/**
 * @brief Get the pointer to the dcs data
 *
 * When the acquisition is still running, this function blocks, until the data is ready.
 *
 * @param data Pointer to the pointer to set the dcs data
 */
void DataAcquisition::getDcsData(uint32_t **data)
{
	//Wait in case of an image is acquired in the background
	(void)waitBlocking();

  *data = (uint32_t *)(memoryGrayscaleOrDcs);
}

/**
 * @brief Get the error and clear it
 *
 * This function reads if there was an error in this class and automatically
 * resets the error after reading.
 *
 * @return Status value from TypeInternalReturnValue
 */
TypeInternalReturnValue DataAcquisition::getAndClearStatus()
{
  TypeInternalReturnValue statusToReturn = status;
  status = TypeInternalReturnValue::STATUS_OK;
  return statusToReturn;
}

/**
 * @brief Read, if the acquired data is too old
 *
 * @param timestamp Timestamp at acquisition
 * @retval true Data is too old
 * @retval false Data is still valid
 * @return Data too old or not
 */
bool DataAcquisition::dataIsTooOld(const uint32_t timestamp)
{
	uint32_t actTimestamp = tofCosTimestampGetMsCounter();

	if ((actTimestamp - timestamp) > MAX_VALID_DATA_TIME)
	{
		return true;
	}

	return false;
}

/**
 * @brief Get acquisition info
 *
 * Get a copy of the acquisition info.
 *
 * @return acquisition info copy
 */
AcquisitionInfo DataAcquisition::getAcquisitionInfo() const
{
	return acquisitionInfo;
}

/**
 * @brief Process interrupt
 *
 * This function must be called by the static function "interruptCallback" in the interrupt. Here the scheduling of the
 * images is done. For example when the grayscale image is acquired, the 3D image is started.
 * When this function is called, always an image has just been captured to the RAM.
 */
void DataAcquisition::processInterrupt()
{
  switch(state)
  {
    case DataAcquisitionState_e::DATA_ACQUISITION_STATE_IDLE:
      //Do nothing, should not happen
  	  break;
    case DataAcquisitionState_e::DATA_ACQUISITION_STATE_3D_GRAYSCALE:
    {
    	tofCosCpuInvalidateDCachebyAddrU32((uint32_t *)memoryResultGrayscale, fpgaAcquisitionSettings.numBytes);

    	//The temperature must be read here, because it is internally read during the grayscale acquisition
    	acquisitionInfo.temperature = context->chipControl->readTemperature();

    	int32_t totalOffset = context->config->getOffset();

    	//When a compensation is active, also add the temperature offset
    	if (indexCompensation >= 0)
    	{
    		if (temperatureCompensationEnabled)
    		{
    		  totalOffset += context->temperatureCompensation[indexCompensation].getTemperatureOffset(acquisitionInfo.temperature, acquisitionInfo.dllStep, true, doTemperatureFilter);
    		}
    	  totalOffset += context->drnuCompensation[indexCompensation].getOffset();
    	}

    	//The Offset here has to be set before the acquisition, because the FPGA does this on the fly
    	fpgaSetPostCorrectionOffset(totalOffset);

    	//Write the settings that do not have a shadow register
    	context->chipControl->setTo3dUnShadowed();

    	//Load integration time 0. If it is already loaded, no I2C command will be sent
    	context->config->load3dSettings(0);

    	context->ambientLightCompensation.loadFpga(context->chipControl->getIntegrationTimeMultiplier());

  	  fpgaStartDistanceAmplitude(memoryGrayscaleOrDcs, memoryDcs, memoryResult3d0, memorySg3d0, const_cast<fpgaAcquisitionSettings_t &>(fpgaAcquisitionSettings));
  	  context->chipControl->sendShutter();

  	  //Already load the next settings. The TOF chip has shadow registers to store them.
  	  if (dualIntegrationTime)
  	  {
  	  	context->config->load3dSettings(1);
  	  }
  	  else
  	  {
  	    context->config->loadGrayscaleSettings();
  	  }

  	  state = DataAcquisitionState_e::DATA_ACQUISITION_STATE_3D_FIRST_INTEGRATION_TIME;
  	  break;
    }
    case DataAcquisitionState_e::DATA_ACQUISITION_STATE_3D_FIRST_INTEGRATION_TIME:
    	tofCosCpuInvalidateDCachebyAddrU32((uint32_t *)memoryResult3d0, fpgaAcquisitionSettings.numBytes);
  	  if (dualIntegrationTime)
  	  {
  	  	//Load integration time 1. If it is already loaded, no I2C command will be sent
  	  	context->config->load3dSettings(1);

  	  	context->ambientLightCompensation.loadFpga(context->chipControl->getIntegrationTimeMultiplier());

  		  fpgaStartDistanceAmplitude(memoryGrayscaleOrDcs, memoryDcs, memoryResult3d1, memorySg3d1, const_cast<fpgaAcquisitionSettings_t &>(fpgaAcquisitionSettings));
  		  context->chipControl->sendShutter();

  		  //Already load the next settings. The TOF chip has shadow registers to store them.
  		  context->config->loadGrayscaleSettings();

  		  state = DataAcquisitionState_e::DATA_ACQUISITION_STATE_3D_SECOND_INTEGRATION_TIME;
  	  }
  	  else
  	  {
  	  	data = DataAcquisitionData_e::DATA_ACQUISITION_DATA_SINGLE_INTEGRATION_TIME;
  	  	state = DataAcquisitionState_e::DATA_ACQUISITION_STATE_IDLE;
  	  }
  	  break;
    case DataAcquisitionState_e::DATA_ACQUISITION_STATE_3D_SECOND_INTEGRATION_TIME:
    	tofCosCpuInvalidateDCachebyAddrU32((uint32_t *)memoryResult3d1, fpgaAcquisitionSettings.numBytes);
    	data = DataAcquisitionData_e::DATA_ACQUISITION_DATA_DUAL_INTEGRATION_TIME;
    	state = DataAcquisitionState_e::DATA_ACQUISITION_STATE_IDLE;
      break;
    case DataAcquisitionState_e::DATA_ACQUISITION_STATE_3D_ONLY:
    	tofCosCpuInvalidateDCachebyAddrU32((uint32_t *)memoryResult3d0, fpgaAcquisitionSettings.numBytes);
    	data = DataAcquisitionData_e::DATA_ACQUISITION_DATA_SINGLE_INTEGRATION_TIME;
    	state = DataAcquisitionState_e::DATA_ACQUISITION_STATE_IDLE;
    	break;
    case DataAcquisitionState_e::DATA_ACQUISITION_STATE_GRAYSCALE_ONLY:
    	tofCosCpuInvalidateDCachebyAddrU32((uint32_t *)memoryResultGrayscale, fpgaAcquisitionSettings.numBytes);
    	data = DataAcquisitionData_e::DATA_ACQUISITION_DATA_GRAYSCALE;
    	state = DataAcquisitionState_e::DATA_ACQUISITION_STATE_IDLE;
    	break;
    default:
  	  break;
  }
}

/**
 * @brief Interrupt callback
 *
 * This static function is given to the C driver as pointer. It will be called in the
 * interrupt with the given argument. This argument must be the pointer to the instance (this pointer).
 *
 * @param arg Pointer to the instance
 */
void DataAcquisition::interruptCallback(void *arg)
{
  DataAcquisition *acquisition = (DataAcquisition *)arg;

  acquisition->processInterrupt();
}

/** @} */
