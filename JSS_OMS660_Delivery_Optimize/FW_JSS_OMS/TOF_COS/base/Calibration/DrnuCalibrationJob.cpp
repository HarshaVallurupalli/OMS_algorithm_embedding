/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 *
 * @addtogroup calibration_job
 *
 * @{
 */
#include <Calibration/DrnuCalibrationDataHelper.h>
#include <Calibration/DrnuCalibrationJob.h>
#include <GlobalSettings.h>
#include "TypeReturnValue.h"
#include "DelayHelper.h"
#include "TraceSettings.h"
#include <math.h>
#include <TOF_COS_Constants.h>
#include "TOF_COS_Config.h"
#include <TOF_COS_Context.h>
#include "tof_cos_sys_timer.h"
#include "ChipSelection.h"


const uint8_t INTEGRATION_TIME_MIN = 10;                                                    ///<[us] Min. integration time for calibration = starting point
const uint16_t INTEGRATION_TIME_MAX = 2000;                                                  ///<[us] Max. integration time for calibration
const uint8_t INTEGRATION_TIME_INC = 5;                                                     ///<[us] Inc. of integration time
const uint8_t AVERAGE_NUM_VALUES = 30; //75                                                 ///<Number of values for the average
const uint8_t MIN_TEMPERATURE_IMAGES = 200;                                                 ///<Min. number of images captured at the beginning to get a stable temperature
const uint16_t MAX_TEMPERATURE_IMAGES = 10000;                                               ///<Max. number of images captured at the beginning to get a stable temperature
const int32_t TEMPERATURE_MAX_AVERAGE_DIFF = (0.5 * (double)(1 << TEMPERATURE_CALC_SHIFT));  ///<= 0.5°C << 10, max. allowed difference at calibration time
const int32_t MIN_TARGET_TEMPERATURE = (33.0 * (double)(1 << TEMPERATURE_CALC_SHIFT));       ///<= 35°C << 10, min temperature calibration
const int32_t MAX_TARGET_TEMPERATURE_DIFF = (0.5 * (double)(1 << TEMPERATURE_CALC_SHIFT));   ///<= If the temperature diff is smaller than this during NUM_IMAGES_MODULO_TEMPERATURE_TEST the temperature measurement procedure is stopped
const int32_t MAX_TEMPERATURE_DELTA_HEATUP = (5.0 * (double)(1 << TEMPERATURE_CALC_SHIFT));  ///<= Maximum delta of temperature from start
const uint8_t NUM_IMAGES_MODULO_PRINT_TEMPERATURE = 200;                                    ///<When the number of images modulo this gives zero, the temperature is printed. Useful when the calibration temperature is being found
const uint16_t NUM_IMAGES_MODULO_TEMPERATURE_TEST =  600;                                    ///<If the temperature does not increase more than "MAX_TARGET_TEMPERATUE_DIFF" during this number of images, the temperature measurement procedure is stopped
const uint8_t CALIBRATION_ATTEMPTS = 5;                                                     ///<Number of attempts for calibration
const uint16_t ATTEMPTS_COOL_DOWN = 10000;                                                   ///<Number of grayscale images/temperature measurements maximum taken to cool down
const uint16_t ATTEMPTS_MEASUREMENT = 10000;                                                 ///<Number of Images maximum taken for one measurement in the desired temperature range

DrnuCalibrationJob::DrnuCalibrationJob(class TOF_COS_Context *context):
context(context),
calibrationCalculation(&ownCalibrationCalculation),
calibration(&ownCalibration)
{
  maxSteps = 0;
}

/**
 * @brief Find the real number of DLL steps
 *
 * This function walks through as much as needed DLL steps to get the required range.
 *
 * @param wantedRange Wanted range in mm
 * @retval 0 Failed
 * @return Number of DLL steps
 */
uint32_t DrnuCalibrationJob::findRange(uint8_t &stepsNeeded, const int32_t temperature)
{
	uint8_t numDllSteps = 0;
	uint32_t multiplier = 0;
	uint32_t range = 0;
	int32_t distances[NUM_DLL_STEPS]; //Just for the log

	//Set to DLL step 0
	context->chipControl->setDllCoarseStepExt(0);

	//Get average and store this
	uint32_t firstValue = getAveragePixelDistance();
	int32_t lastValue = firstValue;
	uint32_t distanceDone = 0;

	//Store for log
	distances[0] = firstValue;

	//Loop over a maximum possible number of DLL steps
	for (numDllSteps = 1; numDllSteps < NUM_DLL_STEPS; numDllSteps++)
	{
		context->chipControl->setDllCoarseStepExt(numDllSteps);

		int32_t actValue = getAveragePixelDistance();

		//Store for log
		distances[numDllSteps] = actValue;

		//Handle the wrap, so that the value always gets higher, even when it starts already at almost the maximum of the atan range
		if (actValue < lastValue)
		{
			multiplier++;
		}
		lastValue = actValue;

		//Generate a summed value = whole distance made
		int32_t summedValue = actValue + DISTANCE_RANGE * multiplier;

		//Calculate the difference to the first value without dll shift
		distanceDone = summedValue - firstValue;

		//As long as the range is not reached, store the step
		if (distanceDone < DISTANCE_RANGE)
		{
		  range = distanceDone;
			stepsNeeded = numDllSteps + 1;
		}
	}

	//Print a log with all steps
	TRACE("\r\n");
	for (uint32_t i = 0; i < numDllSteps; i++)
	{
	  TRACE("  step[%u] = %d\r\n", i, distances[i]);
	}

	return range;
}

/**
 * @brief Get the average pixel distance
 *
 * This function gets the average distance of all (valid) pixels with the current settings.
 *
 * @retval -1 Failed
 * @return Average distance in mm
 */
uint32_t DrnuCalibrationJob::getAveragePixelDistance()
{
	//Start the acquisition
	context->dataAcquisition->start3dImageForCalibration();

	//Wait for finished. This also gives the status
	TypeInternalReturnValue status = context->dataAcquisition->waitBlocking();
	if (status != TypeInternalReturnValue::STATUS_OK)
	{
		return -1;
	}/*** Exit here -------------------------------------------> ***/

	//Get the data
	uint32_t *data3d = nullptr;
	context->dataAcquisition->get3dData(&data3d);

	//Use the calculation class to calculate the average
	uint32_t numPixel = context->config->getNumPixel();
	uint32_t average = calibrationCalculation->calcDistAverage(data3d, numPixel, false);

	return average;
}

/**
 * @brief Get the average pixel distance
 *
 * This function gets the average compensated distance of all (valid) pixels with the current settings.
 *
 * @retval -1 Failed
 * @return Average distance in mm
 */
int32_t DrnuCalibrationJob::getAveragePixelDistanceCalibrated()
{
	uint32_t average = 0;

	for (uint8_t i = 0; i < 50; i++)
	{
	//Start the acquisition
	context->dataAcquisition->start3dGrayscaleImage(false);

	//Wait for finished. This also gives the status.
	TypeInternalReturnValue status = context->dataAcquisition->waitBlocking();
	if (status != TypeInternalReturnValue::STATUS_OK)
	{
		return -1;
	}/*** Exit here -------------------------------------------> ***/

	//Get the data
	uint32_t *data3d = nullptr;
	context->dataAcquisition->get3dData(&data3d);

	//Use the calculation class to calculate the average
	uint32_t numPixel = context->config->getNumPixel();
	average = calibrationCalculation->calcDistAverage(data3d, numPixel, true);
	}

	return average;
}

/**
 * @brief Get spatial average amplitude
 *
 * This function gets the spatial average amplitude of all pixels.
 *
 * @retval 0 Failed
 * @return Spatial average amplitude in lsb
 */
uint32_t DrnuCalibrationJob::getSpatialAverageAmplitude()
{
	//Start the acquisition
	context->dataAcquisition->start3dImageForCalibration();

	//Wait for finished. This also gives the status. This also gets a grayscale image.
	TypeInternalReturnValue status = context->dataAcquisition->waitBlocking();
	if (status != TypeInternalReturnValue::STATUS_OK)
	{
	  return 0;
		/*** Exit here ---------------------------------------------> ***/
	}

	//Get the data
	uint32_t *data3d = nullptr;
	context->dataAcquisition->get3dData(&data3d);

	uint32_t numPixel = context->config->getNumPixel();

	uint16_t *resultBuffer = reinterpret_cast<uint16_t*>(context->ramManager->getOutputBuffer_32Bit());

	//Take the median pixel
	uint32_t medianPixel = calibrationCalculation->amplitudeSpatialAverage(data3d, numPixel, resultBuffer);

  return medianPixel;
}

/**
 * @brief Find the required integration time for the calibration
 *
 * The target is to find an integration time with a big enough amplitude.
 *
 * @retval -1 Failed
 * @return Integration time in us
 */
int16_t DrnuCalibrationJob::findIntegrationTime()
{
	//Start with a low integration time
	uint16_t integrationTime = INTEGRATION_TIME_MIN;
	bool goodAmplitude = false;

	while (goodAmplitude == false)
	{
		context->config->setIntegrationTime3d(integrationTime, 0);

		//Take the median pixel
		uint32_t medianPixel = getSpatialAverageAmplitude();

		//Cancel, if no median found --> all Pixels invalid
		if (medianPixel == 0)
		{
			return -1;
		}/*** Exit here ---------------------------------------------> ***/

		//At the moment just look at the median pixel
		if (medianPixel < DRNU_CALIBRATION_AMPLITUDE_TARGET)
		{
			//Amplitude too low, increase it up to a certain value and then cancel
			if (integrationTime < INTEGRATION_TIME_MAX)
			{
				integrationTime += INTEGRATION_TIME_INC;
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
 * @brief Get a stable temperature
 *
 * This function makes a lot of images until a certain temperature is reached and it is stable. This temperature
 * is the temperature to use for the calibration.
 *
 * @retval 0 Failed to get a stable temperature
 * @return Temperature
 */
int32_t DrnuCalibrationJob::getStableTemperature()
{
	uint32_t *resultBuffer = reinterpret_cast<uint32_t*>(context->ramManager->getOutputBuffer_32Bit());
	uint32_t numPixel = context->config->getNumPixel();

	int32_t finalTemperature = 0;
	uint32_t numGoodMeasurements = 0;
	int32_t lastTemperature = 0;
	int32_t firstTemperature = -100; //Init to negative value

	calibrationCalculation->prepareForDistAverage(numPixel, 0, 0, resultBuffer);

	//Limit this procedure to a maximum number of attempts
	for (uint16_t numImages = 0; numImages < MAX_TEMPERATURE_IMAGES; numImages++)
	{
		//Start the 3D acquisition
		context->dataAcquisition->start3dImageForCalibration();

		//Start the grayscale acquisition; this waits blocking first
		context->dataAcquisition->startGrayscaleImage();

		//Wait for finished. This also gives the status.
		TypeInternalReturnValue status = context->dataAcquisition->waitBlocking();
	  if (status != TypeInternalReturnValue::STATUS_OK)
	  {
	  	TRACE("Failed to get grayscale image\r\n");
	  	return 0;
	  } /*** Exit here -------------------------------------------> ***/


	  //Get the data
	  uint32_t *data3d = nullptr;
	  context->dataAcquisition->get3dData(&data3d);

	  //Calculate the distance. Not needed, but done to simulate the time needed for the calculations
	  calibrationCalculation->calcDistAndSumUp(data3d, 0, false);

	  //Sum up the temperature
	  int32_t actTemperature = context->chipControl->readTemperature();

	  //A minimum number of images has to be done
	  if (numImages > MIN_TEMPERATURE_IMAGES)
	  {
	  	//A minimum temperature is required
	    if (actTemperature >= MIN_TARGET_TEMPERATURE)
	  	{
	      numGoodMeasurements++;

	      //The first time the temperature reaches MIN_TARGET_TEMPERATURE, store this value
	      if (firstTemperature < 0)
	      {
	        firstTemperature = actTemperature;
	      }

	      //If the difference to the first temperature is high enough, that's good too --> For systems that heat up fast
	      int32_t diffToFirstTemperature = actTemperature - firstTemperature;
	      if (diffToFirstTemperature > MAX_TEMPERATURE_DELTA_HEATUP)
	      {
	        finalTemperature = actTemperature;
	        break;
	        /* Temperature is ok, cancel here ----------------------------------------------> */
	      }

	      //Test if the temperature difference is smaller than a certain value --> For system that heat up slowly
	      if ((numGoodMeasurements % NUM_IMAGES_MODULO_TEMPERATURE_TEST) == 0)
	      {
	        int32_t diff = actTemperature - lastTemperature;

	        if ((diff > 0) && (diff < MAX_TARGET_TEMPERATURE_DIFF))
	        {
	          finalTemperature = actTemperature;
	          break;
	          /* Temperature is ok, cancel here ----------------------------------------------> */
	        }

	        lastTemperature = actTemperature;
	      }
	  	}
	  	else
	  	{
	  	  numGoodMeasurements = 0;
	  	}
	  }

	  //During search, print the temperature from time to time
	  if ((numImages % NUM_IMAGES_MODULO_PRINT_TEMPERATURE) == 0)
	 	{
	 	  TRACE("%u..", (actTemperature >> TEMPERATURE_CALC_SHIFT));
	 	}
	}

	return finalTemperature;
}

/**
 * @brief Helper function to characterize the temperature
 *
 * This function determines the temperature indicator during the calibration. It defines,
 * if the temperature is OK, too low or too high.
 *
 * @param temperatureDiff Fixed point difference from actual temperature to the wanted temperature
 * @retval TypeTemperatureIndicator::TEMPERATURE_OK The temperature is ok
 * @retval TypeTemperatureIndicator::TEMPERATURE_TOO_HIGH the temperature is too high
 * @retval TypeTemperatureIndicator::TEMPERATURE_TOO_LOW the temperature is too low
 * @return Indicator of the temperature
 */
TypeTemperatureIndicator DrnuCalibrationJob::determineTemperatureIndicator(const int32_t temperatureDiff)
{
	TypeTemperatureIndicator temperatureIndicator;

	if (abs(temperatureDiff) < TEMPERATURE_MAX_AVERAGE_DIFF)
	{
	  temperatureIndicator = TypeTemperatureIndicator::TEMPERATURE_OK;
	}
	else
	{
	  if (temperatureDiff > 0)
		{
		  temperatureIndicator = TypeTemperatureIndicator::TEMPERATURE_TOO_HIGH;
		}
		else
		{
		  temperatureIndicator = TypeTemperatureIndicator::TEMPERATURE_TOO_LOW;
		}
	}

	return temperatureIndicator;
}

/**
 * @brief Wait for cool down
 *
 * This function waits until the temperature is below a limit. It therefore continuously makes
 * grayscale images and reads the temperature. If the temperature is too high, a delay is made
 * to prevent heat-up caused by the grayscale image.
 * If the cool down is not reached after some attempts, the procedure is stopped.
 *
 * @param wantedTemperature Wanted temperature for calibration
 * @return Value from TypeInternalReturnValue
 */
TypeInternalReturnValue DrnuCalibrationJob::waitForCoolDown(const int32_t wantedTemperature)
{
	int32_t temperatureLimit = wantedTemperature - TEMPERATURE_MAX_AVERAGE_DIFF;
	uint32_t cooldownTime = 1000;

	for (uint16_t attempts = 0; attempts < ATTEMPTS_COOL_DOWN; attempts++)
	{
		//Start the 3D acquisition
		context->dataAcquisition->start3dImageForCalibration();

		//Start the grayscale acquisition; this waits blocking first
		context->dataAcquisition->startGrayscaleImage();

		//Wait for finished. This also gives the status.
		TypeInternalReturnValue status = context->dataAcquisition->waitBlocking();
	  if (status != TypeInternalReturnValue::STATUS_OK)
	  {
	    return TypeInternalReturnValue::STATUS_ERROR_GENERAL;
	  } /*** Exit here -----------------------------------> ***/

	  int32_t actTemperature = context->chipControl->readTemperature();

		if (actTemperature < temperatureLimit)
	  {
	  	return TypeInternalReturnValue::STATUS_OK;
	  }/* Success ----------------------------------------------------------------------------> */
	  else
	  {
	  	//Let the system cool down
	  	tofCosSysTimerBlockingDelay(cooldownTime);
	  	if (cooldownTime < 10000)
	  	{
	  	  cooldownTime += 100;
	  	}
	  }
	}

	return TypeInternalReturnValue::STATUS_ERROR_TEMPERATURE_TOO_HIGH;
}

/**
 * @brief Get one image at wanted temperature
 *
 * This function gets one image at the wanted temperature. If the temperature is too high, an error
 * is returned.
 * If the temperature is too low, the image is repeated, until the required temperature is reached
 * or a maximum number of attempts is reached.
 *
 * @param wantedTemperature Wanted temperature for calibration
 * @retval TypeInternalReturnValue::STATUS_ERROR_TEMPERATURE_TOO_HIGH Temperature too high, first cool down
 * @retval TypeInternalReturnValue::STATUS_ERROR_TEMPERATURE_TOO_LOW Temperature could not be reached
 * @retval TypeInternalReturnValue::STATUS_OK Ok, one measurement read
 * @return Value from TypeInternalReturnValue
 */
TypeInternalReturnValue DrnuCalibrationJob::getOneMeasurement(const int32_t wantedTemperature)
{
	bool heatUp = false;
	uint16_t currentIntegrationTime = context->config->getIntegrationTime3d(0);
	uint16_t heatUpIntegrationTime = (currentIntegrationTime * 10) / 9;

	for (uint16_t i = 0; i < ATTEMPTS_MEASUREMENT; i++)
	{
	  //Start the 3D acquisition
		context->dataAcquisition->start3dImageForCalibration();

		//Start the grayscale acquisition; this waits blocking first
		context->dataAcquisition->startGrayscaleImage();

		//Wait for finished. This also gives the status.
		TypeInternalReturnValue status = context->dataAcquisition->waitBlocking();
		if (status != TypeInternalReturnValue::STATUS_OK)
		{
		  return TypeInternalReturnValue::STATUS_ERROR_GENERAL;
		} /*** Exit here -----------------------------------> ***/


		int32_t actTemperature = context->chipControl->readTemperature();

	  int32_t tempDiff = actTemperature - wantedTemperature;

	  TypeTemperatureIndicator temperatureIndicator = determineTemperatureIndicator(tempDiff);

    if (temperatureIndicator == TypeTemperatureIndicator::TEMPERATURE_TOO_HIGH)
    {
    	if (heatUp)
    	{
    	  heatUp = false;
    	  context->config->setIntegrationTime3d(currentIntegrationTime, 0);
    	}
    	else
    	{
    	  return TypeInternalReturnValue::STATUS_ERROR_TEMPERATURE_TOO_HIGH;
    	}
    }
    else if (temperatureIndicator == TypeTemperatureIndicator::TEMPERATURE_TOO_LOW)
    {
    	heatUp = true;
      context->config->setIntegrationTime3d(heatUpIntegrationTime, 0);
    }
    else
    {
    	if (heatUp)
    	{
    		heatUp = false;
    		context->config->setIntegrationTime3d(currentIntegrationTime, 0);
    	}
    	else
    	{
    	  return TypeInternalReturnValue::STATUS_OK;
    	}
    }
  }

	return TypeInternalReturnValue::STATUS_ERROR_TEMPERATURE_TOO_LOW;
}

/**
 * @brief Execute the calibration for one DLL step
 *
 * This function executes the calibration for one DLL step.
 *
 * @param step DLL step
 * @param range Range for all DLL steps in mm
 * @param dllSteps Total number of DLL steps
 * @param wantedTemperature Wanted temperature for the calibration, measured at the beginning
 * @param temperatureIndicator Indicates, if the temperature is OK, too low or too high
 * @retval STATUS_ERROR_GENERAL Calibration of step failed
 * @retval STATUS_OK Calibration of step successful
 * @return Result of this calibration step
 */
TypeInternalReturnValue DrnuCalibrationJob::calibrateStep(const uint8_t step, const int32_t range, const uint8_t dllSteps, const uint32_t wantedTemperature, TypeTemperatureIndicator &temperatureIndicator)
{
	TRACE("calibrate step %02u ", step);

	//Set DLL to step
	context->chipControl->setDllCoarseStepExt(step);

	//Get the startValue. This is the average distance of all pixels
	int32_t averageValue = getAveragePixelDistance();
	if (averageValue < 0)
	{
	  TRACE("calibrateStep failed to get averageValue\r\n");
		return TypeInternalReturnValue::STATUS_ERROR_GENERAL;
	}/*** Exit here -------------------------------------------> ***/

	TRACE("averageValue = %05u, ", averageValue);

	//Get the memory buffers
	uint32_t *resultBuffer = reinterpret_cast<uint32_t*>(context->ramManager->getOutputBuffer_32Bit());
	uint32_t numPixel = context->config->getNumPixel();

	calibrationCalculation->prepareForDistAverage(numPixel, averageValue, wantedTemperature, resultBuffer);

	//Get xxx images and sum the distance up
	uint8_t numValue = 0;
	bool coolDown = true;
	while(numValue < AVERAGE_NUM_VALUES)
	{
		if (coolDown)
		{
		  TypeInternalReturnValue status = waitForCoolDown(wantedTemperature);
			if (status != TypeInternalReturnValue::STATUS_OK)
			{
			  return status;
			}/* Cancel, error ----------------------------------------------------------------------> */
		}

		TypeInternalReturnValue status = getOneMeasurement(wantedTemperature);

		if (status == TypeInternalReturnValue::STATUS_OK)
		{
		  //Get the data
	    uint32_t *data3d = nullptr;
	    context->dataAcquisition->get3dData(&data3d);

	    int32_t actTemperature = context->chipControl->readTemperature();

	    //Calculate the distance
	    calibrationCalculation->calcDistAndSumUp(data3d, actTemperature, false);

	    numValue++;

	    coolDown = false;
		}
		else if (status == TypeInternalReturnValue::STATUS_ERROR_TEMPERATURE_TOO_HIGH)
		{
	    coolDown = true;
		}
		else
		{
		  return status;
		}/* Cancel, error ----------------------------------------------------------------------> */
	}

	//Calculate the average per pixel. Turn back with the artificial offset
	calibrationCalculation->calcAveragePerValidPixel();

	//Calculate the actual set distance
	uint32_t setDistance = (range * step) / (dllSteps - 1);

	uint32_t averageTemperature = calibrationCalculation->getAverageTemperature();
	int32_t tempDiff = calibrationCalculation->getTemperatureDiff();

	temperatureIndicator = determineTemperatureIndicator(tempDiff);

	if (temperatureIndicator == TypeTemperatureIndicator::TEMPERATURE_OK)
	{
		TRACE("set distance = %05u, temp = %u, min = %5u, max = %5u ", setDistance, (averageTemperature >> TEMPERATURE_CALC_SHIFT), calibrationCalculation->getMinDistance(), calibrationCalculation->getMaxDistance());

		TRACE("distance[0] = %u ", resultBuffer[0]);
		//call the calibration routine
		calibration->calibrateStep(reinterpret_cast<uint8_t *>(resultBuffer), setDistance, step);
	}
	else
	{
		TRACE("temperature not OK: %u, retry", (averageTemperature >> TEMPERATURE_CALC_SHIFT));
	}

	TRACE("\r\n");
	return TypeInternalReturnValue::STATUS_OK;
}

/**
 * @brief Verify one step
 *
 * This function verifies one step
 *
 * @param step DLL step
 * @param range Range for all DLL steps in mm
 * @param dllSteps Total number of DLL steps
 *
 * @retval STATUS_ERROR_GENERAL Verification of step failed
 * @retval STATUS_OK Verification of step successful
 * @return Result of this verification step
 */
TypeInternalReturnValue DrnuCalibrationJob::verifyStep(const uint8_t step, const int32_t range, const uint8_t dllSteps)
{
	TRACE("verify step %02u ", step);

	//Set DLL to step
	context->chipControl->setDllCoarseStepExt(step);

	//Get the startValue. This is the average distance of all pixels
	int32_t averageValue = getAveragePixelDistance();
	if (averageValue < 0)
	{
	  TRACE("verifyStep failed to get averageValue\r\n");
		return TypeInternalReturnValue::STATUS_ERROR_GENERAL;
	}/*** Exit here -------------------------------------------> ***/

	//Get the memory buffers
	uint32_t *resultBuffer = reinterpret_cast<uint32_t*>(context->ramManager->getOutputBuffer_32Bit());
	uint32_t numPixel = context->config->getNumPixel();

	calibrationCalculation->prepareForDistAverage(numPixel, averageValue, 0, resultBuffer);

	//Get xxx images and sum the distance up
	for (uint8_t i = 0; i < AVERAGE_NUM_VALUES; i++)
	{
		//Start the 3D acquisition
		context->dataAcquisition->start3dGrayscaleImage(false);

		//Wait for finished. This also gives the status.
		TypeInternalReturnValue status = context->dataAcquisition->waitBlocking();
	  if (status != TypeInternalReturnValue::STATUS_OK)
	  {
	    return TypeInternalReturnValue::STATUS_ERROR_GENERAL;
	  } /*** Exit here -----------------------------------> ***/

	  int32_t actTemperature = context->chipControl->readTemperature();

	  //Get the data
	  uint32_t *data3d = nullptr;
	  context->dataAcquisition->get3dData(&data3d);

	  //Calculate the distance
	  calibrationCalculation->calcDistAndSumUp(data3d, actTemperature, true);
	}

	//Calculate the average per pixel. Turn back with the artificial offset
	calibrationCalculation->calcAveragePerValidPixel();

	//Calculate the actual set distance
	uint32_t setDistance = (range * step) / (dllSteps - 1);

	setDistance = calibrationCalculation->scaleSetDistance(setDistance);

	uint32_t averageDistance = calibrationCalculation->getAverageDistance();
	int32_t averageDiff = setDistance - averageDistance;

	uint32_t minDistance = calibrationCalculation->getMinDistance();
	uint32_t maxDistance = calibrationCalculation->getMaxDistance();

	TRACE("averageDistance = %5u, setDistance = %5u, minDistance = %5u, maxDistance = %5u, averageDiff = %5d", averageDistance, setDistance, minDistance, maxDistance, averageDiff);
	TRACE("\r\n");
	return TypeInternalReturnValue::STATUS_OK;
}

/**
 * @brief Calibrate all steps
 *
 * This function executes the main part of the calibration. It runs the calibration of all steps and tries to hold a constant temperature
 * over all steps.
 *
 * @retval STATUS_ERROR_TEMPERATURE_DIFFERENCE_TOO_HIGH Temperature was not stable enough
 * @retval STATUS_OK calibration OK
 * @return Result of the calibration
 */
TypeInternalReturnValue DrnuCalibrationJob::calibrateAllSteps(DrnuCalibrationInfoData &calibrationInfo, const bool offsetOnly)
{
	TypeInternalReturnValue status;

	/***********************************
	 * Prepare
	 ***********************************/
	calibrationInfo.modulation = context->config->getModulation();

	//Prepare for calibration
	calibrationCalculation->prepareForCalibration();


	//Images need to be unsorted for calibration
	context->ramManager->setupUnsorted();

	calibrationCalculation->setCalibrationDistanceRange(DISTANCE_RANGE);


	/***********************************
	 * Calibration temperature
	 ***********************************/
	TRACE("Get calibration temperature...");
	//Get the wanted temperature to be about in the range. This is to prevent a lot of trial and error loops at calibration
	calibrationInfo.temperature = getStableTemperature();
  if (calibrationInfo.temperature == 0)
  {
  	TRACE("Failed\r\n");
  	return TypeInternalReturnValue::STATUS_ERROR_GENERAL;
  } /*** escape here               ------------------------> ***/
	TRACE("temperature = %u\r\n", (calibrationInfo.temperature >> TEMPERATURE_CALC_SHIFT));


	/***********************************
	 * Offset --> maybe only until here
	 ***********************************/
	//Set the offset of the atan calculation to zero
	calibrationCalculation->setOffset(0);

	//Get the average pixel value at DLL step 0. This gives the offset for the atan calculation. So there is (almost) no offset anymore later
	context->chipControl->setDllCoarseStepExt(0);

	uint32_t offset = getAveragePixelDistance();
	if (offset < 0)
	{
	  return TypeInternalReturnValue::STATUS_ERROR_GENERAL;
	} /*** escape here               ------------------------> ***/

	TRACE("atan offset = %d, ", offset);

	//Set the offset to the atan calculation --> be ware of the negative sign
	calibrationCalculation->setOffset(-offset);

	//In the calibration class store the offset as it is
	calibrationInfo.offset = offset;

	if (offsetOnly)
	{
		TRACE("Offset only calibration, finished...");
		return TypeInternalReturnValue::STATUS_OK;
	}/*** Finish here, only offset -------------------------> ***/


	/***********************************
	 * DLL range
	 ***********************************/
	TRACE("Get number of DLL steps...");
	//Find the number of needed DLL steps. This can be different depending on requirements or sensor.
	uint32_t dllRange = findRange(calibrationInfo.dllSteps, calibrationInfo.temperature);
	if (dllRange == 0)
	{
    TRACE("failed\r\n");
		return TypeInternalReturnValue::STATUS_ERROR_GENERAL;
		/*** escape here               ------------------------> ***/
	}

	if (calibrationInfo.dllSteps > maxSteps)
	{
		TRACE("too many, detected = %u, max = %u\r\n", calibrationInfo.dllSteps, maxSteps);
		return TypeInternalReturnValue::STATUS_ERROR_GENERAL;
		/*** escape here               ------------------------> ***/
	}

	calibrationInfo.dllRange = dllRange;
	TRACE("Range = %u, steps = %u\r\n", calibrationInfo.dllRange, calibrationInfo.dllSteps);


	/***********************************
	 * Calibration
	***********************************/
	//Calibrate each step
	uint8_t step = 0;
	TypeTemperatureIndicator temperatureIndicator = TypeTemperatureIndicator::TEMPERATURE_OK;
	DelayHelper delayHelper;
	while (step < calibrationInfo.dllSteps)
	{
    status = calibrateStep(step, calibrationInfo.dllRange, calibrationInfo.dllSteps, calibrationInfo.temperature, temperatureIndicator);
		if (status != TypeInternalReturnValue::STATUS_OK)
		{
			return status;
		}/*** Cancel the procedure here ------------------------> ***/

		//Temperature OK
		if (temperatureIndicator == TypeTemperatureIndicator::TEMPERATURE_OK)
		{
			//Increase the step
			step++;
		}
		//If the temperature is too high, do a delay --> Sensor gets colder.
		else if (temperatureIndicator == TypeTemperatureIndicator::TEMPERATURE_TOO_HIGH)
		{
		  delayHelper.increase();
		}
		//Temperature too low
		else
		{
		  //Decrease the delay
			delayHelper.decrease();
		}

		tofCosSysTimerBlockingDelay(delayHelper.getDelay());


		//Stop, if the delay is high and the temperature is still too high
    if (delayHelper.maxDelayReached())
		{
      return TypeInternalReturnValue::STATUS_ERROR_TEMPERATURE_DIFFERENCE_TOO_HIGH;
		}/*** Cancel the procedure here ------------------------> ***/
	}

	return TypeInternalReturnValue::STATUS_OK;
}

/**
 * @brief Verify all steps
 *
 * This function verifies each dll step that was calibrated.
 *
 * @retval STATUS_OK calibration OK
 * @return Value from TypeInternalReturnValue
 */
TypeInternalReturnValue DrnuCalibrationJob::verifyAllSteps(DrnuCalibrationInfoData &calibrationInfo)
{
	TypeInternalReturnValue status = TypeInternalReturnValue::STATUS_OK;

	context->ramManager->setupSorted();

	int8_t indexCompensation = context->config->getIndexCompensation();
	if (indexCompensation < 0)
	{
		TRACE("failed to get index of compensation\r\n");
	  return TypeInternalReturnValue::STATUS_ERROR_COMPENSATION;
	}/*** Cancel the procedure here ------------------------> ***/


	//Update the calibration data because it is used now
	context->drnuCompensation[indexCompensation].update();
	context->temperatureCompensation[indexCompensation].update();

	//Set the compensation to verification mode
	context->drnuCompensation[indexCompensation].setVerificationModeEnabled(true);

	DrnuCalibrationDataHelper calibrationDataHelper(context->config->getDrnuCompensationMemory(indexCompensation).address);

	uint8_t numSteps = calibrationDataHelper.getNumStepsCalibrated();

	for (uint8_t step = 0; step < numSteps; step++)
	{
		status = verifyStep(step, calibrationDataHelper.getRange(), numSteps);
		if (status != TypeInternalReturnValue::STATUS_OK)
		{
		  break;
		}/*** Cancel the procedure here ------------------------> ***/
	}

	context->drnuCompensation[indexCompensation].setVerificationModeEnabled(false);

	return status;
}

/**
 * @brief Calibrate the sensor
 *
 * This function has to be called to calibrate the sensor. This calibration has to be done in the
 * calibration box and without optics. The calibration is blocking and returns if it is finished
 * or if an error occurred. The calibration can take some minutes to complete.
 *
 * @param memoryInfo Class containing information about the calibration memory
 * @param offsetOnly Set to true to only calibrate the offset
 * @param validateOnly Set to true to only validate
 * @retval Status_ErrorGeneral Error occurred
 * @retval Status_Ok Calibration successfully done
 * @return Result of the calibration
 */
TypeReturnValue DrnuCalibrationJob::calibrate(const MemoryInfo memoryInfo, const bool offsetOnly, const bool validateOnly)
{
	TRACE("Calibration started: ");

	printInfoData();

	TRACE("\r\n");

	calibration->setup(memoryInfo.address);

	//The maximum possible steps for the calibration
	maxSteps = memoryInfo.size / NUM_PIXEL;

	//Configure the calibration class
	calibration->setParameters(DISTANCE_RANGE, CALIBRATION_MULTIPLIER, context->config->getNumPixel());

	//Set the grayscale integration time to a low value. It is only used for temperature measurement
  context->config->setIntegrationTimeGrayscale(10);

  TRACE("Get integration time...");
	//Find a good integration time
	int16_t integrationTime = findIntegrationTime();
	if (integrationTime < 0)
	{
	  TRACE("failed\r\n");
	  return TypeReturnValue::TOF_COS_STATUS_ERROR_GENERAL;
	}/*** escape here               ------------------------> ***/

	//Now set the integration time to the value found
	context->config->setIntegrationTime3d(integrationTime, 0);

	TRACE("integration time at %u\r\n", integrationTime);

	//Manual control of the DLL
	context->chipControl->setDllManual(true);

	DrnuCalibrationInfoData calibrationInfo;

	if (validateOnly == false)
	{
	  //Try at maximum for a certain amounts of attempts
	  for (uint8_t attempts = 0; attempts <= CALIBRATION_ATTEMPTS; attempts++)
	  {
		  //Calibrate the steps
	    TypeInternalReturnValue internalStatus = calibrateAllSteps(calibrationInfo, offsetOnly);
	    if (internalStatus == TypeInternalReturnValue::STATUS_OK)
	    {
	  	  break;
	    }/*** Successful, break here ----------------------------> ***/
	    //In case of temperature difference too high, the procedure can be repeated. In case of other errors not.
	    else if ((internalStatus != TypeInternalReturnValue::STATUS_ERROR_TEMPERATURE_DIFFERENCE_TOO_HIGH) ||
	  		     (attempts == CALIBRATION_ATTEMPTS))
	    {
        return TypeReturnValue::TOF_COS_STATUS_ERROR_GENERAL;
	    }/*** Cancel the procedure here ------------------------> ***/
	  }

	  //Store the calibration header
	  TypeInternalReturnValue calibrationStatus = calibration->storeHeader(calibrationInfo);
	  if (calibrationStatus != TypeInternalReturnValue::STATUS_OK)
	  {
	    return TypeReturnValue::TOF_COS_STATUS_ERROR_GENERAL;
	  }/*** Cancel the procedure here ------------------------> ***/
	}

	//Verify the steps
	TypeInternalReturnValue internalStatus = verifyAllSteps(calibrationInfo);
	if (internalStatus != TypeInternalReturnValue::STATUS_OK)
	{
	  return TypeReturnValue::TOF_COS_STATUS_ERROR_GENERAL;
	}/*** Cancel the procedure here ------------------------> ***/

	context->chipControl->setDllCoarseStepExt(TOF_COS_DLL_STEP_OPERATION);

	TRACE("Finished\r\n");

	return TypeReturnValue::TOF_COS_STATUS_OK;
}

/**
 * @brief Print info data
 *
 * This is just a helper function to print some information about the settings to the host
 */
void DrnuCalibrationJob::printInfoData()
{
	switch (context->config->getModulation().getModulationFrequency())
	{
	  case Modulation::MODULATION_10MHZ:
	  	TRACE("10MHz");
		  break;
	  case Modulation::MODULATION_12MHZ:
	  	TRACE("12MHz");
	  	break;
	  case Modulation::MODULATION_20MHZ:
	  	TRACE("20MHz");
		  break;
	  case Modulation::MODULATION_24MHZ:
	  	TRACE("24MHz");
	  	break;
	  case Modulation::MODULATION_5MHZ:
	  	TRACE("5MHz");
	  	break;
	  case Modulation::MODULATION_6MHZ:
	  	TRACE("6MHz");
	  	break;
	  case Modulation::MODULATION_2_5MHZ:
	  	TRACE("2.5MHz");
	  	break;
	  case Modulation::MODULATION_3MHZ:
	  	TRACE("3MHz");
	  	break;
	  case Modulation::MODULATION_1_25MHZ:
	  	TRACE("1.25MHz");
	  	break;
	  case Modulation::MODULATION_1_5MHZ:
	  	TRACE("1.5MHz");
	  	break;
	  case Modulation::MODULATION_0_625MHZ:
	  	TRACE("0.625MHz");
	  	break;
	  case Modulation::MODULATION_0_75MHZ:
	  	TRACE("0.75MHz");
	  	break;
	  case Modulation::MODULATION_0_375MHZ:
	  	TRACE("0.375MHz");
	  	break;
	  default:
	  	TRACE("unknown MHz");
		  break;
	}
}

/** @} */
