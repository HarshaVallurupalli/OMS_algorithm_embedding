/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 *
 * @addtogroup grayscale_calibration_job
 *
 * @{
 */
#include "tof_cos_calibration_memory.h"
#include "GrayscaleCalibrationJob.h"
#include "Calibration/GrayscaleCalibrationTypes.h"
#include "TraceSettings.h"
#include "DataAcquisition/DataAcquisition.h"

///Number of images for the average
static const uint8_t NUM_IMAGES_AVERAGE = 50;

///Minimal integration time [us]
static const uint8_t INTEGRATION_TIME_GRAYSCALE_MIN = 1;

///Maximal integration time [us]
static const uint16_t INTEGRATION_TIME_GRAYSCALE_MAX = 2000; //300;

///Increment of the integration time [us]
static const uint8_t INTEGRATION_TIME_GRAYSCALE_INC_MIN = 1;

///Target grayscale value for 50% --> 2048 + (2048 / 2)
static const uint16_t GRAYSCALE_TARGET = 3072;

///<Maximum value possible in the DSNU LUT
static const int8_t MAX_DSNU_LUT_VALUE = 6;

///<Minimum value possible in the DSNU LUT
static const int8_t MIN_DSNU_LUT_VALUE = -7;

///<Maximum value possible in the PRNU LUT
static const int8_t MAX_PRNU_LUT_VALUE = 6;

///<Minimum value possible in the PRNU LUT
static const int8_t MIN_PRNU_LUT_VALUE = -7;

/**
 * @brief Constructor
 *
 * @param context Pointer to the context
 */
GrayscaleCalibrationJob::GrayscaleCalibrationJob(TOF_COS_Context *context):
context(context)
{
	calibrationCalculation = &ownCalibrationCalculation;
}

/**
 * @brief Calibrate grayscale
 *
 * This is the top level function to call from outside the class.
 *
 * @param address Address of the calibration memory
 * @param size Size of the calibration memory
 * @return Value from TypeInternalReturnValue
 */
TypeInternalReturnValue GrayscaleCalibrationJob::calibrateGrayscale(const uint32_t address, const uint32_t size)
{
	this->calibrationMemoryAddress = address;
	this->calibrationMemorySize = size;

	TRACE("\r\nGrayscale Calibration started..");

	setupSettings();

	TypeInternalReturnValue status = run();

	teardownSettings();

	TRACE("Done, status = %d", status);
	TRACE("\r\n");

	return status;
}

/**
 * @brief Restore the settings
 *
 * This function restores all settings for operation.
 */
void GrayscaleCalibrationJob::teardownSettings()
{
  context->ramManager->setupSorted();
}

/**
 * @brief Prepare the settings
 *
 * This function prepares all settings to run the calibration.
 */
void GrayscaleCalibrationJob::setupSettings()
{
	//Set to full ROI
	context->config->setRoi(Roi());

	//No binning
	context->config->setBinning(Binning::Binning_e::BINNING_NONE, 0);

	context->ramManager->setupUnsorted();
}

/**
 * @brief Get the spatial average
 *
 * This function acquires a grayscale image and calculates the spatial average.
 *
 * @param numPixel Number of pixels
 */
uint32_t GrayscaleCalibrationJob::getSpatialAverage(const uint32_t numPixel)
{
  //Start grayscale image
	context->dataAcquisition->startGrayscaleImage();

	//Wait blocking for the data
	uint32_t *inputDataGrayscale = nullptr;
	context->dataAcquisition->getGrayscaleData(&inputDataGrayscale);

	//Calculate the average
	uint32_t average = grayscaleCalculation.grayscaleSpatialAverage(inputDataGrayscale, numPixel);

  return average;
}

/**
 * @brief Find the required integration time for the calibration
 *
 * The target is to find an integration time with a big enough amplitude.
 * The minimum integration time is set and then the integration time is increased until the amplitude
 * reaches the required value.
 *
 * @param numPixel Number of pixels
 * @retval -1 Failed
 * @return Integration time in us or negative value in case of error
 */
int16_t GrayscaleCalibrationJob::findIntegrationTime(const uint32_t numPixel)
{
	//Start with a low integration time
	uint16_t integrationTime = INTEGRATION_TIME_GRAYSCALE_MIN;
	bool goodAmplitude = false;

	while (goodAmplitude == false)
	{
		context->config->setIntegrationTimeGrayscale(integrationTime);

		//Take the average pixel
		uint32_t spatialAverage = getSpatialAverage(numPixel);

		//Cancel, if no average found --> all Pixels invalid
		if (spatialAverage == 0)
		{
			return -1;
		}/*** Exit here ---------------------------------------------> ***/

		//At the moment just look at the median pixel
		if (spatialAverage < GRAYSCALE_TARGET)
		{
			//Amplitude too low, increase it up to a certain value and then cancel
			if (integrationTime < INTEGRATION_TIME_GRAYSCALE_MAX)
			{
				integrationTime += INTEGRATION_TIME_GRAYSCALE_INC_MIN;
			}
			else
			{
				return -1;
				/*** Exit here ------------------------------------------> ***/
			}
		}
		else
		{
			goodAmplitude = true;
		}
	}
	return integrationTime;
}

/**
 * @brief Get the temporal average
 *
 * This function acquires multiple grayscale images and calculates the temporal average per pixel.
 *
 * @param pData Pointer to the data to store the average
 * @param numPixel Number of pixels
 * @return Value from TypeInternalReturnValue
 */
TypeInternalReturnValue GrayscaleCalibrationJob::getTemporalAverage(uint32_t *pData, const uint32_t numPixel)
{
  //This is needed to init for the average calculation
	grayscaleCalculation.grayscaleTemporalAveragePrepare(numPixel, pData);

  for (uint8_t i = 0; i < NUM_IMAGES_AVERAGE; i++)
	{
  	context->dataAcquisition->startGrayscaleImage();

  	uint32_t *inputDataGrayscale = nullptr;
  	context->dataAcquisition->getGrayscaleData(&inputDataGrayscale);

		//Here just sum up. The average is calculated later by dividing.
		grayscaleCalculation.grayscaleTemporalAverageSumUp(inputDataGrayscale, numPixel);
	}

  //Here the average is calculated from the sums
	grayscaleCalculation.grayscaleTemporalAverageCalculate(numPixel);

	//Check, if there was an error during data acquisition
	TypeInternalReturnValue status = context->dataAcquisition->getAndClearStatus();

	return status;
}

/**
 * @brief Helper function to limit to a range
 *
 * @param value Input value
 * @param minValue Minimum value to set
 * @param maxValue Maximum value to set
 * @return Value in limited range
 */
int32_t GrayscaleCalibrationJob::limitToRange(const int32_t value, const int32_t minValue, const int32_t maxValue)
{
	int32_t resultingValue = value;

	if (resultingValue < minValue)
	{
		resultingValue = minValue;
	}
	else if (resultingValue > maxValue)
	{
		resultingValue = maxValue;
	}

	return resultingValue;
}

/**
 * @brief Calculate the table entries
 *
 * This function calculates the table entries and stores them into the flash.
 *
 * @param bufferDark Pointer to the image data without illumination
 * @param bufferHalfLight Pointer to the image with 50% illumination
 * @param spatialAverage Spatial average at 50% illumination
 * @param numPixel Number of pixels
 * @return Value from TypeInternalReturnValue
 */
TypeInternalReturnValue GrayscaleCalibrationJob::calculateAndStoreTable(const uint32_t *bufferDark, const uint32_t *bufferHalfLight, const uint32_t spatialAverage, const uint32_t numPixel)
{
  tofCosCalibrationMemorySetCurrentAddress(calibrationMemoryAddress);

	for (uint32_t i = 0; i < numPixel; i++)
  {
    uint32_t currentPixelDark = bufferDark[i];
    uint32_t currentPixelHalfLight = bufferHalfLight[i];

    int32_t dsnu = currentPixelDark - VALUE_PIXEL_NO_LIGHT;
    int32_t prnu = currentPixelHalfLight - dsnu - VALUE_PIXEL_HALF_LIGHT;

    dsnu /= CALIBRATION_DATA_DIVIDER;
    prnu /= CALIBRATION_DATA_DIVIDER;

    //Limit to prevent overflow
    dsnu = limitToRange(dsnu, MIN_DSNU_LUT_VALUE, MAX_DSNU_LUT_VALUE);
    prnu = limitToRange(prnu, MIN_PRNU_LUT_VALUE, MAX_PRNU_LUT_VALUE);

    grayscaleCalibration_u value;
    value.nibbles.low_dsnu = dsnu;
    value.nibbles.high_prnu = prnu;

    //Combine to one byte
    uint8_t byteToWrite = value.value;

    int8_t status = tofCosCalibrationMemoryAddByte(byteToWrite);
    if (status < 0)
    {
      return TypeInternalReturnValue::STATUS_ERROR_FLASH_WRITE;
    }/* Flash write failed, cancel -----------------------------------------------> */
  }

	return TypeInternalReturnValue::STATUS_OK;
}

/**
 * @brief Run the calibration
 *
 * This is the main function of the class and runs the whole grayscale calibration.
 *
 * @return Value from TypeInternalReturnValue
 */
TypeInternalReturnValue GrayscaleCalibrationJob::run()
{
	if (tofCosCalibrationMemoryCheckErased(calibrationMemoryAddress, calibrationMemorySize) < 0)
	{
	  return TypeInternalReturnValue::STATUS_ERROR_FLASH_NOT_ERASED;
		/* Flash not erased -----------------------------------------> */
	}


	uint32_t numPixel = context->config->getNumPixel();
  TypeInternalReturnValue status = TypeInternalReturnValue::STATUS_OK;
	uint8_t *resultBuffer = context->ramManager->getDoubleBufferedResultMemory();
  uint32_t *bufferDark = reinterpret_cast<uint32_t *>(resultBuffer);
  uint32_t *bufferHalfLight = reinterpret_cast<uint32_t *>(context->ramManager->getLastResultMemory());

 /*******************************************************************
  * Get the temporal average without illumination
  *******************************************************************/
  context->config->setIntegrationTimeGrayscale(0);

  status = getTemporalAverage(bufferDark, numPixel);
  if (status != TypeInternalReturnValue::STATUS_OK)
  {
    return status;
  }/* Failed, cancel ----------------------------------------------------------> */


  //Enable the illumination during grayscale acquisition
  context->chipControl->setLedGrayscale(true, false);


 /*******************************************************************
  * Find integration time for the required amplitude
  *******************************************************************/
  uint16_t integrationTime = findIntegrationTime(numPixel);
  if (integrationTime < 0)
  {
    return TypeInternalReturnValue::STATUS_ERROR_INTEGRATION_TIME;
  }/* Failed, cancel ----------------------------------------------------------> */

  context->config->setIntegrationTimeGrayscale(integrationTime);


 /*******************************************************************
  * Get the temporal average with illumination at 50%
  *******************************************************************/
  status = getTemporalAverage(bufferHalfLight, numPixel);
  if (status != TypeInternalReturnValue::STATUS_OK)
  {
    return status;
  }/* Failed, cancel ----------------------------------------------------------> */
  uint32_t spatialAverage = getSpatialAverage(numPixel);


  //Disable the illumination during grayscale acquisition
  context->chipControl->setLedGrayscale(false, false);


 /*******************************************************************
  * Calculate and store everything
  *******************************************************************/
  status = calculateAndStoreTable(bufferDark, bufferHalfLight, spatialAverage, numPixel);
  if (status != TypeInternalReturnValue::STATUS_OK)
  {
    return status;
  }/* Failed, cancel ----------------------------------------------------------> */

	return TypeInternalReturnValue::STATUS_OK;
}

/** @} */
