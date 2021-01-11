/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup temperature_compensation Temperature Compensation
 * @ingroup tof_cos
 * @brief Class responsible to do the temperature compensation
 *
 * @{
 */
#ifndef TEMPERATURE_COMPENSATION_H_
#define TEMPERATURE_COMPENSATION_H_

#include <stdint.h>
#include "Calculation/CalculationParameters.h"

class TemperatureCompensation
{
	public:
		TemperatureCompensation();
		UNIT_TEST_VIRTUAL void setCalibrationAddress(const uint32_t address);
		UNIT_TEST_VIRTUAL void update();
		UNIT_TEST_VIRTUAL void setTemperatureCoefficient(const int32_t temperatureCoefficient);
		UNIT_TEST_VIRTUAL int32_t getTemperatureOffset(const int32_t currentTemperature, const uint32_t dllStep, const bool enabled, const bool doFilter);

	private:
		int32_t filterTemperature(const int32_t actTemperature, const int32_t lastTemperature);

		uint32_t calibrationAddress;                                              ///<Stores the address of the calibration data (whole data including the header)
		int32_t calibrationTemperature;                                           ///<Chip temperature at calibration time
		int32_t lastTemperature;                                                  ///<Last temperature used for temporal filtering of the temperature
		int32_t temperatureCoefficient;                                           ///<Temperature coefficient of chip and illumination
};

#endif /* TEMPERATURE_COMPENSATION_H_ */

/** @} */
