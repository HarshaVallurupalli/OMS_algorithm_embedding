/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 *
 * @addtogroup integration_time_finder
 *
 * @{
 */
#include "IntegrationTimeFinder.h"
#include "DataAcquisition/DataAcquisition.h"

static const uint8_t INTEGRATION_TIME_INC_MIN = 10;                                                    ///<[us] Minimal inc. of integration time

/**
 * @brief Get the median amplitude
 *
 * This function gets the median amplitude of all pixels.
 *
 * @param context Pointer to the context
 * @param calibrationCalculation Pointer to the calibrationCalculation class to use
 * @retval 0 Failed
 * @return Median amplitude in lsb
 */
uint32_t IntegrationTimeFinder::getSpatialAverageAmplitude(TOF_COS_Context *context, CalibrationCalculation *calibrationCalculation)
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

	uint32_t *data3d = nullptr;
	context->dataAcquisition->get3dData(&data3d);

	uint32_t numPixel = context->config->getNumPixel();

	uint16_t *resultBuffer = reinterpret_cast<uint16_t*>(context->ramManager->getOutputBuffer_32Bit());

	uint32_t averagePixel = calibrationCalculation->amplitudeSpatialAverage(data3d, numPixel, resultBuffer);

  return averagePixel;
}

/**
 * @brief Find the required integration time for the calibration
 *
 * The target is to find an integration time with a big enough amplitude.
 * The minimum integration time is set and then the integration time is increased until the amplitude
 * reaches the required value.
 *
 * @param context Pointer to the TOFCOS context
 * @param calibrationCalculation Pointer to the calibration calculation class to use
 * @param amplitudeTarget Target amplitude to reach
 * @param integrationTimeMin Minimal integration time = starting integration time
 * @param integrationTimeMax Maximal integration time = maximal integration time set during search
 * @retval -1 Failed
 * @return Integration time in us
 */
int16_t IntegrationTimeFinder::findIntegrationTime(TOF_COS_Context *context, CalibrationCalculation *calibrationCalculation, const uint32_t amplitudeTarget, const uint16_t integrationTimeMin, const uint16_t integrationTimeMax)
{
	//Start with a low integration time
	uint16_t integrationTime = integrationTimeMin;
	bool goodAmplitude = false;

	while (goodAmplitude == false)
	{
		context->config->setIntegrationTime3d(integrationTime, 0);

		//Take the median pixel
		uint32_t amplitudeAverage = getSpatialAverageAmplitude(context, calibrationCalculation);

		//Cancel, if no median found --> all Pixels invalid
		if (amplitudeAverage == 0)
		{
			return -1;
		}/*** Exit here ---------------------------------------------> ***/

		//At the moment just look at the median pixel
		if (amplitudeAverage < amplitudeTarget)
		{
			//Amplitude too low, increase it up to a certain value and then cancel
			if (integrationTime < integrationTimeMax)
			{
				//Calculate the new integration time from the amplitude
				uint16_t integrationTimeNew = (amplitudeTarget * integrationTime) / amplitudeAverage;

				//Now make the increment only 2/3 to prevent overshoot
				uint16_t integrationTimeInc = ((integrationTimeNew - integrationTime) * 2) / 3;
        uint16_t integrationTimeMaxInc = (integrationTime * 2) / 3;

				//Be sure there is an increment
				if (integrationTimeInc < INTEGRATION_TIME_INC_MIN)
				{
					integrationTimeInc = INTEGRATION_TIME_INC_MIN;
				}
				else if (integrationTimeInc > integrationTimeMaxInc)
				{
				  integrationTimeInc = integrationTimeMaxInc;
				}

				integrationTime += integrationTimeInc;
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

/** @} */
