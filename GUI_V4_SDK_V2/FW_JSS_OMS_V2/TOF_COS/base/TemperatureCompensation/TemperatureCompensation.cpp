/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 *
 * @addtogroup temperature_compensation
 *
 * @{
 */
#include "TemperatureCompensation.h"
#include "TOF_COS_Constants.h"
#include <stdlib.h>
#include "Calibration/DrnuCalibrationDataHelper.h"



static const uint8_t FILTER_TOTAL = 10;                                 ///<Total parts for filter. For example if 0.1 * actual value and 0.9 * lastValue --> (1 * actualValue + 9 * lastValue) / 10
static const uint8_t FILTER_TEMP_ACTUAL = 1;                            ///<Gives 0.1 * actual value

TemperatureCompensation::TemperatureCompensation()
{

}

/**
 * @brief Set the calibration address
 *
 * Set the calibration address of the drnu calibration data. In the data there is also
 * included the calibration temperature.
 *
 * @param address Calibration address to set
 */
void TemperatureCompensation::setCalibrationAddress(const uint32_t address)
{
	this->calibrationAddress = address;

	update();
}

/**
 * @brief Update compensation data
 *
 * Updates the compensation data from the calibration data.
 */
void TemperatureCompensation::update()
{
	DrnuCalibrationDataHelper calibrationDataHelper(calibrationAddress);

	this->calibrationTemperature = calibrationDataHelper.getCalibrationTemperature();
}

/**
 * @brief Set the temperature coefficient
 *
 * Set this coefficient before using the temperature compensation.
 *
 * @param temperatureCoefficient Temperature coefficient to set
 */
void TemperatureCompensation::setTemperatureCoefficient(const int32_t temperatureCoefficient)
{
	this->temperatureCoefficient = temperatureCoefficient;
}

/**
 * @brief Filter the temperature
 *
 * This filter is used to filter the temperature. The reason is to prevent that a big temperature noise makes
 * a big noise in the distance because of the compensation. The distance changes about 13mm per °C. So a noise
 * of 1°C would make a distance noise of 13mm.
 *
 * Take 0.1 x actual value and 0.9 x last value
 *
 * @param actTemperature Actual temperature
 * @param lastTemperatur Last temperature
 * @return Filtered temperature
 */
int32_t TemperatureCompensation::filterTemperature(const int32_t actTemperature, const int32_t lastTemperature)
{
  int32_t filteredTemperature = ((actTemperature * FILTER_TEMP_ACTUAL) + (lastTemperature * (FILTER_TOTAL - FILTER_TEMP_ACTUAL))) / FILTER_TOTAL;
  return filteredTemperature;
}

/**
 * @brief Calculate the offset caused by the temperature
 *
 * This function calculates the offset that is caused by the temperature difference between calibration
 * temperature and actual temperature.
 *
 * @param currentTemperature Current chip temperature shifted high
 * @param dllStep Current used DLL step
 * @param enabled Compensation enabled or not
 * @param doFilter Filter temperature or not
 * @return Offset to add in millimeters
 */
int32_t TemperatureCompensation::getTemperatureOffset(const int32_t currentTemperature, const uint32_t dllStep, const bool enabled, const bool doFilter)
{
	if (enabled == false)
	{
	  return 0;
	}/* No temperature compensation, return zero ----------------------------------------> */

	//Get the difference to the calibration temperature
	int32_t tempDiffToCalibration = currentTemperature - calibrationTemperature;

	int32_t actTemperatureToUse = currentTemperature;

	if (doFilter)
	{
	  actTemperatureToUse = filterTemperature(actTemperatureToUse, lastTemperature);

	  tempDiffToCalibration = actTemperatureToUse - calibrationTemperature;
	}

	//Update the history
	lastTemperature = actTemperatureToUse;

	//Calculate the final temperature coefficient out of the coefficient for chip and illumination and the one for the DLL step (depending on the current DLL step)
	int32_t finalTemperatureCoefficient = temperatureCoefficient + (dllStep * DLL_STEP_TEMPERATURE_COEFFICIENT);

	//Calculate the offset using the formula in the AN 10
  int32_t temperatureOffset = -(tempDiffToCalibration * finalTemperatureCoefficient);

  //Shift back by 2 * 10 because of the multiplication
  temperatureOffset = temperatureOffset >> (2 * TEMPERATURE_CALC_SHIFT);

  return temperatureOffset;
}

/** @} */
