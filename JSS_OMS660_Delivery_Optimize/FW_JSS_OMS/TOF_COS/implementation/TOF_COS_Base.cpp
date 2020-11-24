/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 *
 * @addtogroup tof_cos_base
 *
 * @{
 */
#include <Calibration/DrnuCalibrationJob.h>
#include <GlobalSettings.h>
#include "fpga.h"
#include <TOF_COS_Base.h>
#include <TOF_COS_Constants.h>
#include "jobs/JobDistance.h"
#include "jobs/JobDistAmpl.h"
#include "jobs/JobGrayscale.h"
#include "tof_cos_io.h"
#include "tof_cos_calibration_memory.h"
#include "Calibration/GrayscaleCalibrationJob.h"
#include "Calibration/AmbientLightCalibrationJob.h"
#include <unistd.h>

/**
 * @brief Constructor
 *
 */
TOF_COS_Base::TOF_COS_Base()
{
  sequencerProgrammer = nullptr;
  actJob = &jobDistance;
  actDataType = TOF_COS_Data_e::DATA_NONE;
}

/**
 * @brief Init
 *
 * This function must be called before using the TOF_COS.
 *
 * @param preBytes Number of bytes before the measurement data
 * @param postBytes Number of bytes after the measurement data
 * @return Result of the initialization, value of TypeReturnValue
 */
uint8_t TOF_COS_Base::init(const uint32_t preBytes, const uint32_t postBytes)
{
  context.ramManager->init(preBytes, postBytes, WIDTH, HEIGTH);

	return init();
}

/**
 * @brief Update the calibration data
 *
 * This function is called at system start. It is mainly used on systems where
 * the calibration data is not available at init time of the TOF_COS.
 * For example on a system with detached camera head and SerDes communication system.
 */
void TOF_COS_Base::updateCalibrationData()
{
	initCalibrationSettings();
}

/**
 * @brief Start the next acquisition
 *
 * Call this function to start the next acquisition with the settings previously set.
 */
void TOF_COS_Base::startNextAcquisition()
{
  actJob->startAcquisition();
}

/**
 * @brief Select the data
 *
 * Call this function before the acquisition (startNextAcquisition) to select, which kind of data should
 * be acquired.
 *
 * @param data Data type to select (value of TOF_COS_DATA_e)
 */
void TOF_COS_Base::selectData(const TOF_COS_Data_e data)
{
  if (data != this->actDataType)
	{
	  this->actDataType = data;
	  updateDataType();
	}
}

/**
 * @brief Get the current selected data type
 *
 * This inidcates, if it is set to distance, distance amplitude, ...
 *
 * @return Value from TOF_COS_DATA_e
 */
TOF_COS_Data_e TOF_COS_Base::getSelectedDataType() const
{
	return actDataType;
}

/**
 * @brief Get the data
 *
 * Call this function to pick-up the data.
 *
 * @param data Pointer to the pointer to the data
 * @param acquisitionMetaData Reference to the acquisition meta data containing informations about the acqusition
 * @return Value from TypeReturnValue
 */
uint8_t TOF_COS_Base::getData(uint8_t **data, AcquisitionMetaData &acquisitionMetaData)
{
  return actJob->getData(data, acquisitionMetaData);
}

/**
 * @brief Read, if the acquisition is still busy
 *
 * As long as it is busy, do not start a new acquisition
 *
 * @retval true Acquisition is still running
 * @retval false Acquisition is finished
 * @return Acquisition busy or not
 */
bool TOF_COS_Base::acquisitionBusy()
{
	return !(context.dataAcquisition->isFinished());
}

/**
 * @brief Set a global offset
 *
 * This function sets a global offset for the distance. It is the same for all pixels.
 *
 * @param offset Offset in mm
 */
void TOF_COS_Base::setOffset(const int32_t offset)
{
	context.config->setOffset(offset);
}

/**
 * @brief Set an integration time 3D
 *
 * This function sets one of the integration times for 3D.
 *
 * @param integrationTime Integration time in micro seconds
 * @param index Index of the integration time to set (0..1)
 */
void TOF_COS_Base::setIntegrationTime3d(const uint16_t integrationTime, const uint8_t index)
{
	context.config->setIntegrationTime3d(integrationTime, index);
}

/**
 * @brief Read an integration time 3D
 *
 * Returns the integration time 3D for the given index of the current illumination.
 *
 * @param index Index of the integration time
 * @return Integration time in us
 */
uint16_t TOF_COS_Base::getIntegrationTime3d(const uint8_t index)
{
  return context.config->getIntegrationTime3d(index);
}

/**
 * @brief Set an integration time grayscale
 *
 * This function sets the integration time for grayscale.
 *
 * @param integrationTime Integration time in micro seconds
 */
void TOF_COS_Base::setIntegrationTimeGrayscale(const uint32_t integrationTime)
{
	context.config->setIntegrationTimeGrayscale(integrationTime);
}

/**
 * @brief Set the minimal amplitude
 *
 * Pixels with an amplitude below this limit are marked as low amplitude.
 *
 * @param minAmplitude Minimal amplitude in lsb to set
 */
void TOF_COS_Base::setMinimalAmplitude(const uint32_t minAmplitude)
{
	context.config->setMinAmplitude(minAmplitude);
}

/**
 * @brief Set Roi (Region Of Interest)
 *
 * @param roi Class containing the wanted Roi
 */
void TOF_COS_Base::setRoi(const Roi roi)
{
	context.config->setRoi(roi);
}

/**
 * @brief Set the modulation frequency
 *
 * @param modulationFrequency Modulation frequency as enum
 */
void TOF_COS_Base::setModulactionFrequency(Modulation::ModulationFrequency modulationFrequency)
{
	//At the moment use index 0
	Modulation modulation = context.config->getModulation(0);
	modulation = modulationFrequency;
	context.config->setModulation(modulation, 0);
}

/**
 * @brief Set the modulation channel
 *
 * This modulation channel slightly changes the modulation frequency to prevent the inferference from another
 * TOF camera.
 *
 * @param autoChannelEnabled Automatic modulation channel enabled or disabled
 * @param channel Modulation channel, 0..15
 */
void TOF_COS_Base::setModulationChannel(const bool autoChannelEnabled, const uint8_t channel)
{
	context.config->setModulationChannel(autoChannelEnabled, channel);
}

/**
 * @brief Set the binning
 *
 * @param binning Class containing the binning settings
 */
void TOF_COS_Base::setBinning(const Binning binning)
{
	context.config->setBinning(binning, 0);
}

/**
 * @brief Set the HDR settings
 *
 * @param hdr HDR settings class
 */
void TOF_COS_Base::setHdr(const Hdr hdr)
{
	context.config->setHdr(hdr);
}

/**
 * @brief Enable or disable the compensations
 *
 * @param drnuCompensationEnabled Enable or disable the DRNU compensation (Distance Response Non Uniformity)
 * @param temperatureCompensationEnabled Enable or disable the temperature compensation
 * @param ambientLightCompensationEnabled Enable or disable the ambient light compensation
 * @param grayscaleCompeensationEnabled Enable or disable the grayscale compensation
 */
void TOF_COS_Base::setCompensationEnabled(const bool drnuCompensationEnabled, const bool temperatureCompensationEnabled, const bool ambientLightCompensationEnabled, const bool grayscaleCompensationEnabled)
{
  context.config->setCompenationEnabled(drnuCompensationEnabled, temperatureCompensationEnabled, ambientLightCompensationEnabled, grayscaleCompensationEnabled);
}

/**
 * @brief Set the ABS
 *
 * Enable or disable the ABS.
 *
 * @param enabled Flag for the ABS
 */
void TOF_COS_Base::setAbs(const bool enabled)
{
  context.chipControl->setAbs(enabled);
}

/**
 * @brief Set the external shutter
 *
 * Enable or disable the external shutter
 *
 * @param enabled Flag for the external shutter
 */
void TOF_COS_Base::setExternalShutter(const bool enabled)
{
  context.config->setExternalShutter(enabled);
  context.dataAcquisition->clear();
}

/**
 * @brief Get external shutter
 *
 * Enable or disable the external shutter
 *
 * @return Flag for the external shutter
 */
bool TOF_COS_Base::getExternalShutter() const
{
	return context.config->getExternalShutter();
}

/**
 * @brief Set grayscale illuminated
 *
 * If this is true, the illumination is on during grayscale acquisition.
 *
 * @param enabled Illumination enabled/disabled during grayscale acquisition
 */
void TOF_COS_Base::setGrayscaleIlluminated(const bool enabled)
{
  context.config->setGrayscaleIlluminated(enabled);
}

/**
 * @brief Get grayscale illuminated
 *
 * If this is true, the illumination is on during grayscale acquisition.
 *
 * @return Illumination enabled/disabled during grayscale acquisition
 */
bool TOF_COS_Base::getGrayscaleIlluminated() const
{
  return context.config->getGrayscaleIlluminated();
}

/**
 * @brief Set the interference detection settings
 *
 * Interference detection is used to detect interference by another camera or motion blur.
 *
 * @param interferenceDetectionSettings Class containing the interference detection settings
 */
void TOF_COS_Base::setInterferenceDetectionSettings(const InterferenceDetectionSettings interferenceDetectionSettings)
{
  context.calculation->setInterferenceDetectionSettings(interferenceDetectionSettings);
}

/**
 * @brief Set the temporal filter settings for each pixel
 *
 * This function sets the temporal filter settings that are applied for each pixel.
 *
 * @param filterSettings Class containing the filter settings
 */
void TOF_COS_Base::setTemporalFilterSettings(const TemporalFilterSettings filterSettings)
{
  context.calculation->setTemporalFilterSettings(filterSettings);
}

/**
 * @brief Enable or disable the average filter
 *
 * @param enabled Average filter enabled or disabled
 */
void TOF_COS_Base::setAverageFilterEnabled(const bool enabled)
{
  context.calculation->setAverageFilterEnabled(enabled);
}

/**
 * @brief Enable or disable the median filter
 *
 * @param enabled Median filter enabled or disabled
 */
void TOF_COS_Base::setMedianFilterEnabled(const bool enabled)
{
  context.calculation->setMedianFilterEnabled(enabled);
}

/**
 * @brief Set edge filter settings
 *
 * If the threshold is zero, the edge filter is disabled. If the threshold is higher
 * than zero, the edge filter is enabled and the threshold is used as threshold for edge detection.
 *
 * @param threshold Threshold for the edge filter in mm, zero for edge filter disabled
 */
void TOF_COS_Base::setEdgeFilterSettings(const uint32_t threshold)
{
  context.calculation->setEdgeFilterSettings(threshold);
}

//Algorithm Edit
void TOF_COS_Base::setMovementDetectionSettings(bool enable,const uint16_t WindowSize)
{
  context.calculation->setMovementDetectionSettings(enable,WindowSize);
}

/**
 * @brief Set temporal edge filter settings
 *
 * If one of the thresholds is zero, the filter is disabled.
 *
 * @param thresholdLow Lower threshold
 * @param thresholdHigh Higher threshold
 */
void TOF_COS_Base::setTemporalEdgeFilterSettings(const uint32_t thresholdLow, const uint32_t thresholdHigh)
{
  context.calculation->setTemporalEdgeFilterSettings(thresholdLow, thresholdHigh);
}

/**
 * @brief Get the chip ID of the TOF imager
 *
 * This chip ID is read at init.
 *
 * @return Chip ID
 */
uint16_t TOF_COS_Base::getChipId() const
{
  return context.chipControl->getChipId();
}

/**
 * @brief Get the wafer ID of the TOF imager
 *
 * This wafer ID is read at init.
 *
 * @return Wafer ID
 */
uint16_t TOF_COS_Base::getWaferId() const
{
	return context.chipControl->getWaferId();
}

/**
 * @brief Run the DRNU calibration
 *
 * This function runs the DRNU calibration. This is done blocking and will take a long time.
 *
 * @param verifyOnly Set to true to run only a verification
 * @param offsetOnly Set to true to run only an offset calibration
 * @param index Index of the calibration
 * @return Value from TypeReturnValue
 */
uint8_t TOF_COS_Base::calibrateDrnu(bool verifyOnly, const bool offsetOnly, const uint8_t index)
{
	context.config->setOffset(0);

	DrnuCalibrationJob calibrationJob(&context);

  return calibrationJob.calibrate(context.config->getDrnuCompensationMemory(index), offsetOnly, verifyOnly);
}

/**
 * @brief Run production calibration
 *
 * This function runs the production calibration. This is done blocking and will take a long time.
 * The specific implementation of the production calibration is in a new class extending this class here so
 * this can be implemented specific for each camera system.
 *
 * @return Value from TypeReturnValue
 */
uint8_t TOF_COS_Base::calibrateProduction()
{
  return calibrateProductionInternal();
}

/**
 * @brief Run grayscale calibration
 *
 * This function runs the grayscale calibration. This is done blocking and will take some seconds.
 * The specific implementation of the grayscale calibration is in a new class extending this class here so
 * this can be implemented specific for each camera system.
 *
 * @return Value from TypeReturnValue
 */
uint8_t TOF_COS_Base::calibrateGrayscale()
{
  return calibrateGrayscaleInternal();
}

/**
 * @brief Run ambient light calibration
 *
 * This function runs the ambient light calibration. This is done blocking and will take some seconds.
 * The specific implementation of the ambient light calibration is in a new class extending this class here so
 * this can be implemented specific for each camera system.
 *
 * @return Value from TypeReturnValue
 */
uint8_t TOF_COS_Base::calibrateAmbientLight()
{
  return calibrateAmbientLightInternal();
}

/**
 * @brief Write the calibration from RAM to flash
 *
 * All the calibration data is written from RAM to flash. This must be done
 * at the end after calibration.
 *
 * @return Value from TypeReturnValue
 */
uint8_t TOF_COS_Base::writeCalibrationToMemory()
{
  int32_t status = tofCosCalibrationMemoryWriteToDevice();
  if (status < 0)
  {
  	return TypeReturnValue::TOF_COS_STATUS_ERROR_CALIBRATION_MEMORY;
  }

  return TypeReturnValue::TOF_COS_STATUS_OK;
}

/**
 * @brief Set the DLL step
 *
 * Set the DLL step
 *
 * @param step DLL step to set
 */
void TOF_COS_Base::setDllStep(const uint8_t step)
{
  context.config->setDllStep(step);
}

/**
 * @brief Execute one shutter
 *
 * Only for debugging purposes when the system is set to external shutter to test the shutter.
 */
void TOF_COS_Base::shutter()
{
  context.chipControl->sendShutter();
}

/**
 * @brief Init specific
 *
 * This function here is empty. It may be overwritten by a sub class where specific initialization
 * is required --> template pattern.
 */
void TOF_COS_Base::initCalibrationSettings()
{
  //Here nothing is done. May be overwritten by a sub class.
}

/**
 * @brief Select a job
 *
 * Each type of acquisition is managed by a job class. The change of the current job is handled
 * in this function.
 *
 * @param job Pointer to the new job
 */
void TOF_COS_Base::selectJob(PointCloudJob *job)
{
	if ((actJob == nullptr) || (actJob != job))
	{
	  actJob = job;
	}
}

/**
 * @brief Select grayscale
 *
 * This function does the setup for grayscale. It may be overwritten by
 * sub classes.
 */
void TOF_COS_Base::selectGrayscale()
{
  selectJob(&jobGrayscale);
}

/**
 * @brief Select distance
 *
 * This function does the setup for distance. It may be overwritten by
 * sub classes.
 */
void TOF_COS_Base::selectDistance()
{
	selectJob(&jobDistance);
}

/**
 * @brief Select distance and amplitude
 *
 * This function does the setup for distance amplitude. It may be overwritten by
 * sub classes.
 */
void TOF_COS_Base::selectDistanceAmplitude()
{
	selectJob(&jobDistanceAmplitude);
}

/**
 * @brief Select DCS
 *
 * This function does the setup for DCS data. It may be overwritten by
 * sub classes.
 */
void TOF_COS_Base::selectDcs()
{
  selectJob(&jobDcs);
}

/**
 * @brief Setup internal structures
 *
 * This is an internal helper function to setup the internal structures to be prepared
 * for the acquisition of the next data.
 */
void TOF_COS_Base::updateDataType()
{
  switch(actDataType)
  {
    case TOF_COS_Data_e::DATA_DISTANCE:
      selectDistance();
    	break;
    case TOF_COS_Data_e::DATA_DISTANCE_AMPLITUDE:
      selectDistanceAmplitude();
    	break;
    case TOF_COS_Data_e::DATA_GRAYSCALE:
      selectGrayscale();
    	break;
    case TOF_COS_Data_e::DATA_DCS:
      selectDcs();
      break;
    default:
    	break;
  }
}

/**
 * @brief Calibrate the grayscale
 *
 * Run the grayscale calibration. This will block for some seconds.
 *
 * @param address Address of the grayscale calibration
 * @param size Maximal size of the grayscale calibration
 * @return Value from TypeReturnValue
 */
uint8_t TOF_COS_Base::calibrateGrayscale(const uint32_t address, const uint32_t size)
{
  GrayscaleCalibrationJob grayscaleCalibrationJob(&context);

  //Disable interference detection
  context.calculation->setInterferenceDetectionSettings(InterferenceDetectionSettings(false, false, 0));

  currentStatus = grayscaleCalibrationJob.calibrateGrayscale(address, size);
  if (currentStatus != TypeInternalReturnValue::STATUS_OK)
  {
  	return TypeReturnValue::TOF_COS_STATUS_ERROR_CALIBRATION_GRAYSCALE;
  }/* Cancel, error -----------------------------------------------------------> */

  return TypeReturnValue::TOF_COS_STATUS_OK;
}

/**
 * @brief Calibrate the ambient light
 *
 * Run the ambient light calibration. This will block for some seconds.
 *
 * @param address Address of the ambient light calibration
 * @param size Maximal size of the ambient light calibration
 * @return Value from TypeReturnValue
 */
uint8_t TOF_COS_Base::calibrateAmbientLight(const uint32_t address, const uint32_t size)
{
  AmbientLightCalibrationJob ambientLightCalibrationJob(&context);

	//Disable interference detection
	context.calculation->setInterferenceDetectionSettings(InterferenceDetectionSettings(false, false, 0));

	currentStatus = ambientLightCalibrationJob.calibrateAmbientLight(address, size);
	if (currentStatus != TypeInternalReturnValue::STATUS_OK)
	{
	  return TypeReturnValue::TOF_COS_STATUS_ERROR_CALIBRATION_AMBIENT_LIGHT;
	}/* Cancel, error -----------------------------------------------------------> */

	return TypeReturnValue::TOF_COS_STATUS_OK;
}

/**
 * @brief Init
 *
 * This function must be called before using the TOF_COS.
 *
 * @return Result of the initialization, value of TypeReturnValue
 */
uint8_t TOF_COS_Base::init()
{
	TypeInternalReturnValue status;

	int32_t calibrationMemoryStatus = tofCosCalibrationMemoryInit();
  if (calibrationMemoryStatus < 0)
  {
    return TOF_COS_STATUS_ERROR_CALIBRATION_MEMORY;
  } /*** Exit here -----------------------------------> ***/

	status = context.dataAcquisition->init();
	if (status != TypeInternalReturnValue::STATUS_OK)
	{
		return TOF_COS_STATUS_ERROR_GENERAL;
	} /*** Exit here -----------------------------------> ***/

	status = context.chipControl->init();
	if (status != TypeInternalReturnValue::STATUS_OK)
	{
		return TOF_COS_STATUS_ERROR_SENSOR_COMMUNICATION;
	}/*** Exit here -----------------------------------> ***/

	status = context.chipControl->setDeviceAddress(TOF_COS_DEVICE_ADDRESS_TOF_IMAGER);
	if (status != TypeInternalReturnValue::STATUS_OK)
	{
		return TOF_COS_STATUS_ERROR_SENSOR_COMMUNICATION;
	}/*** Exit here -----------------------------------> ***/

	status = sequencerProgrammer->program(TOF_COS_DEVICE_ADDRESS_TOF_IMAGER);
	if (status != TypeInternalReturnValue::STATUS_OK)
	{
		return TypeReturnValue::TOF_COS_STATUS_ERROR_SENSOR_COMMUNICATION;
	}/*** Exit here -----------------------------------> ***/

	status = context.config->init();
	if (status != TypeInternalReturnValue::STATUS_OK)
	{
		return TOF_COS_STATUS_ERROR_GENERAL;
	} /*** Exit here -----------------------------------> ***/

	context.calculation->init();

	//Inject grayscale compensation, remove later if this works in the soft logic
	context.calculation->setGrayscaleCompensation(&context.grayscaleCompensation);

	initCalibrationSettings();

	tofCosIoSetIlluminationEnabled(true);

	return TOF_COS_STATUS_OK;
}

/** @} */
