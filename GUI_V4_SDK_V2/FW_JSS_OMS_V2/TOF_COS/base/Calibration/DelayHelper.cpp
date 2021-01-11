/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 *
 * @addtogroup delay_helper
 *
 * @{
 */
#include "DelayHelper.h"
#include <math.h>

const uint16_t DELAY_TEMPERATURE_TOO_HIGH = 1000;                                             ///<ms delay, when temperature is too high at calibration
const uint16_t MAX_DELAY = 10000;                                                             ///<ms, max possible delay

DelayHelper::DelayHelper()
{
  delay = DELAY_TEMPERATURE_TOO_HIGH;
}

DelayHelper::~DelayHelper()
{
}

/**
 * @brief Increase the delay
 *
 * This function is called, when the sensor is too hot during calibration. The delay will
 * be increased by the step value.
 */
void DelayHelper::increase()
{
  delay += DELAY_TEMPERATURE_TOO_HIGH;
}

/**
 * @brief Decrease the delay
 *
 * This function is called, when the sensor is too cold during calibration.
 */
void DelayHelper::decrease()
{
  delay -= DELAY_TEMPERATURE_TOO_HIGH;
}

/**
 * @brief Check, if the maximum allowed delay is reached
 *
 * When this is reached, the calibration is canceled.
 *
 * @retval false Maximum delay not reached yet
 * @retval true Maximum delay reached
 * @return Maximum delay reached (stop calibration) or not
 */
bool DelayHelper::maxDelayReached()
{
	return (abs(delay) > MAX_DELAY);
}

/**
 * @brief Get the delay
 *
 * Read the actual delay.
 *
 * @return Actual delay in ms
 */
int32_t DelayHelper::getDelay() const
{
	//Negative delay is possible. This helps handling. But do not return a negative delay.
	if (delay < 0)
	{
		return 0;
	}

	return delay;
}

/** @} */
