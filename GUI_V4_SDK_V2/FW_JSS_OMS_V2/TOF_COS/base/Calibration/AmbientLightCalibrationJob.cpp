/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 *
 * @addtogroup ambient_light_calibration_job
 *
 * @{
 */
#include "tof_cos_io.h"
#include "tof_cos_calibration_memory.h"
#include "AmbientLightCalibrationJob.h"
#include "AmbientLightCalibrationDataHelper.h"
#include "IntegrationTimeFinder.h"
#include "ChipSelection.h"
#include "TraceSettings.h"
#include "DataAcquisition/DataAcquisition.h"
#include <string.h>


///DLL step to run the measurements
static const uint8_t DLL_STEP_TO_RUN = 10;

///Target amplitude in LSB
static const uint16_t AMPLITUDE_TARGET = 400;

///Min. integration time for calibration = starting point
static const uint8_t INTEGRATION_TIME_AMBIENT_LIGHT_MIN = 10;

///Max. integration time for calibration
static const uint16_t INTEGRATION_TIME_AMBIENT_LIGHT_MAX = 2000;

///Number of images for the average
static const uint8_t NUM_IMAGES_AVERAGE = 50;

///ROI
static const uint8_t ROI_WIDTH = 20;
static const uint8_t ROI_HEIGHT = 20;

///Grayscale amplitude used in calculation of KAL factor
static const uint16_t GRAYSCALE_AMPLITUDE = 1000;

/**
 * @brief Constructor
 *
 * @param context Pointer to the context
 */
AmbientLightCalibrationJob::AmbientLightCalibrationJob(TOF_COS_Context *context):
context(context)
{
	calibrationCalculation = &ownCalibrationCalculation;
}

/**
 * @brief Calibrate ambient light
 *
 * @return Value from TypeInternalReturnValue
 */
TypeInternalReturnValue AmbientLightCalibrationJob::calibrateAmbientLight(const uint32_t address, const uint32_t size)
{
	TRACE("\r\nAmbient Light Calibration started..");

	this->calibrationMemoryAddress = address;
	this->calibrationMemorySize = size;

	setupSettings();

	TypeInternalReturnValue status = calibrateAll();

  teardownSettings();

  TRACE("Done, status=%d", status);
  TRACE("\r\n");

  return status;
}

/**
 * @brief Run the ambient light calibration
 *
 * This function runs the ambient light calibration and stores the data into the flash.
 *
 * @return Value from TypeInternalReturnValue
 */
TypeInternalReturnValue AmbientLightCalibrationJob::calibrateAll()
{
	ambientLightCalibration_t ambientLightCalibrationData;
	TypeInternalReturnValue status = run(&ambientLightCalibrationData.calibration, Binning(Binning::Binning_e::BINNING_NONE));
	if (status != TypeInternalReturnValue::STATUS_OK)
	{
		return status;;
	}/* Failed -----------------------------------------------------------------> */

	//Store the struct to flash
  AmbientLightCalibrationDataHelper helper(calibrationMemoryAddress);
  helper.addStorageInformation(ambientLightCalibrationData);

  tofCosCalibrationMemorySetCurrentAddress(calibrationMemoryAddress);
  uint8_t *pData = reinterpret_cast<uint8_t *>(&ambientLightCalibrationData);
  for (uint32_t i = 0; i < sizeof(ambientLightCalibration_t); i++)
  {
  	int32_t statusFlash = tofCosCalibrationMemoryAddByte(pData[i]);
  	if (statusFlash < 0)
  	{
  	  return TypeInternalReturnValue::STATUS_ERROR_FLASH_WRITE;
  	}/* Failed -----------------------------------------------------------------> */
  }

  return TypeInternalReturnValue::STATUS_OK;
}

/**
 * @brief Get the average of DCS0 and DCS2 over one image
 *
 * This function acquires one image and calculates average for DCS0 and DCS2.
 *
 * @param dcs0 Reference for the DCS0 value
 * @param dcs2 Reference for the DCS2 value
 * @param omitChipConfig Set to true to omit the chip configuration before the acquisition
 * @return Value from TypeInternalReturnValue
 */
TypeInternalReturnValue AmbientLightCalibrationJob::getDcsValues(uint32_t &dcs0, uint32_t &dcs2, const bool omitChipConfig)
{
	uint32_t *dataDcs = nullptr;

	uint32_t numPixel = context->config->getNumPixel();

	context->dataAcquisition->startDcs(omitChipConfig);

	//DCS data comes to the grayscale buffer
	context->dataAcquisition->getDcsData(&dataDcs);

	//DCS order is here 0, 2, 1, 3, so we need index 0 and 1
	dcs0 = calibrationCalculation->dcsAverage(dataDcs, numPixel, 0);
	dcs2 = calibrationCalculation->dcsAverage(dataDcs, numPixel, 1);

  return TypeInternalReturnValue::STATUS_OK;
}

/**
 * @brief Get the average of DCS0 and DCS2 over multiple images
 *
 * This function acquires 50 images and calculates the average for DCS0 and DCS2.
 *
 * @param dcs0 Reference for the DCS0 value
 * @param dcs1 Reference for the DCS1 value
 * @param omitChipConfig Set to true to omit the chip configuration before the acquisition
 * @return Value from TypeInternalReturnValue
 */
TypeInternalReturnValue AmbientLightCalibrationJob::getDcsAverage(uint32_t &dcs0, uint32_t &dcs2, const bool omitChipConfig)
{
  uint32_t dcs0Sum = 0;
  uint32_t dcs2Sum = 0;

	for (uint32_t i = 0; i < NUM_IMAGES_AVERAGE; i++)
  {
  	uint32_t dcs0Current = 0;
  	uint32_t dcs2Current = 0;
  	TypeInternalReturnValue status = getDcsValues(dcs0Current, dcs2Current, omitChipConfig);
  	if (status != TypeInternalReturnValue::STATUS_OK)
  	{
  	  return status;
  	}/* Failed -----------------------------------------------------> */

  	dcs0Sum += dcs0Current;
  	dcs2Sum += dcs2Current;
  }

	dcs0 = dcs0Sum / NUM_IMAGES_AVERAGE;
	dcs2 = dcs2Sum / NUM_IMAGES_AVERAGE;

	return TypeInternalReturnValue::STATUS_OK;
}

/**
 * @brief Restore the settings
 *
 * This function restores all settings for operation.
 */
void AmbientLightCalibrationJob::teardownSettings()
{
	context->chipControl->setDllCoarseStepExt(TOF_COS_DLL_STEP_OPERATION);

	context->config->setRoi(Roi());
}

/**
 * @brief Prepare the settings
 *
 * This function prepares all settings to run the calibration.
 */
void AmbientLightCalibrationJob::setupSettings()
{
  context->chipControl->setDllCoarseStepExt(DLL_STEP_TO_RUN);

  //Set the ROI to the center of the sensor
	Roi roiToUse((WIDTH - ROI_WIDTH) / 2, (HEIGTH - ROI_HEIGHT) / 2, ROI_WIDTH, ROI_HEIGHT);

  context->config->setRoi(roiToUse);

	//24MHz
	context->config->setModulation(Modulation(Modulation::ModulationFrequency::MODULATION_24MHZ), 0);
}

/**
 * @brief Run the calibration
 *
 * This is the main function of the class and runs the whole ambient light calibration.
 *
 * @param ambientLightCalibrationEntry
 * @param binning Selected type of binning
 * @return Value from TypeInternalReturnValue
 */
TypeInternalReturnValue AmbientLightCalibrationJob::run(ambientLightCalibrationEntry_t *ambientLightCalibrationEntry, const Binning binning)
{
	if (tofCosCalibrationMemoryCheckErased(calibrationMemoryAddress, calibrationMemorySize) < 0)
	{
	  return TypeInternalReturnValue::STATUS_ERROR_FLASH_NOT_ERASED;
	  /* Flash not erased -----------------------------------------> */
	}

 /*******************************************************************
	* Setup binning
	*******************************************************************/
	context->config->setBinning(binning, 0);

	tofCosIoDisableCalibrationLight();

 /*******************************************************************
  * Find the integration time for 400lsb amplitude
  *******************************************************************/
  int16_t integrationTime3d = IntegrationTimeFinder::findIntegrationTime(context, calibrationCalculation, AMPLITUDE_TARGET, INTEGRATION_TIME_AMBIENT_LIGHT_MIN, INTEGRATION_TIME_AMBIENT_LIGHT_MAX);
  if (integrationTime3d < 0)
  {
    return TypeInternalReturnValue::STATUS_ERROR_INTEGRATION_TIME;
  }/* Failed to get integration time -----------------------------------------> */


 /********************************************************************
  * Config
  ********************************************************************/
  context->config->setIntegrationTime3d(integrationTime3d, 0);
  context->config->load3dSettings(0);


 /********************************************************************
  * Get the values for no ambient light
  ********************************************************************/
  uint32_t dcs0NoAl = 0;
  uint32_t dcs2NoAl = 0;
  TypeInternalReturnValue status = getDcsAverage(dcs0NoAl, dcs2NoAl, false);
  if (status != TypeInternalReturnValue::STATUS_OK)
  {
    return status;
  }/* Failed -----------------------------------------------------------------> */

  uint16_t integrationTimeLengthSetting1 = context->chipControl->getIntegrationTimeLength();
  uint16_t integrationTimeMultiplierSetting1 = context->chipControl->getIntegrationTimeMultiplier();

  tofCosIoEnableCalibrationLight();


 /********************************************************************
  * Get the values with ambient light setting 1
  ********************************************************************/
  uint32_t dcs0WithAlSetting1 = 0;
  uint32_t dcs2WithAlSetting1 = 0;
  status = getDcsAverage(dcs0WithAlSetting1, dcs2WithAlSetting1, false);
  if (status != TypeInternalReturnValue::STATUS_OK)
  {
    return status;
  }/* Failed -----------------------------------------------------------------> */


 /********************************************************************
  * Calculate the new settings for the integration time registers
  ********************************************************************/
  uint16_t integrationTimeLengthSetting2 = (integrationTimeLengthSetting1 + 1) / 4 - 1;
  uint16_t integrationTimeMultiplierSetting2 = 4 * integrationTimeMultiplierSetting1;
  context->chipControl->setIntegrationTimeRegisters(integrationTimeLengthSetting2, integrationTimeMultiplierSetting2);


 /********************************************************************
  * Get the values with ambient light setting 2
  ********************************************************************/
  uint32_t dcs0WithAlSetting2 = 0;
  uint32_t dcs2WithAlSetting2 = 0;
  status = getDcsAverage(dcs0WithAlSetting2, dcs2WithAlSetting2, true);
  if (status != TypeInternalReturnValue::STATUS_OK)
  {
    return status;
  }/* Failed -----------------------------------------------------------------> */


  tofCosIoDisableCalibrationLight();


 /********************************************************************
  * Calculate the factor
  ********************************************************************/
  int32_t d0Setting1 = dcs0WithAlSetting1 - dcs0NoAl;
  int32_t d2Setting1 = dcs2WithAlSetting1 - dcs2NoAl;
  int32_t d0Setting2 = dcs0WithAlSetting2 - dcs0NoAl;
  int32_t d2Setting2 = dcs2WithAlSetting2 - dcs2NoAl;

  int32_t slope = ((d0Setting2 - d2Setting2) - (d0Setting1 - d2Setting1)) / 3;
  int32_t kalFactor = GRAYSCALE_AMPLITUDE / slope;


 /********************************************************************
  * Store the data
  ********************************************************************/
  //Fill the struct. Later only the KAL factor is needed. But because we have a whole flash word anyway, we store also the measured values
  ambientLightCalibrationEntry->dcs0NoAl = dcs0NoAl;
  ambientLightCalibrationEntry->dcs2NoAl = dcs2NoAl;
  ambientLightCalibrationEntry->dcs0WithAlSetting1 = dcs0WithAlSetting1;
  ambientLightCalibrationEntry->dcs0WithAlSetting2 = dcs0WithAlSetting2;
  ambientLightCalibrationEntry->dcs2WithAlSetting1 = dcs2WithAlSetting1;
  ambientLightCalibrationEntry->dcs2WithAlSetting2 = dcs2WithAlSetting2;
  ambientLightCalibrationEntry->integrationTime3d = integrationTime3d;
  ambientLightCalibrationEntry->integrationTimeGrayscale = 200; //Set to a fixed value at the moment
  ambientLightCalibrationEntry->kalFactor = kalFactor;

  TRACE("kal = %u\r\n", kalFactor);

  return TypeInternalReturnValue::STATUS_OK;
}


/** @} */
