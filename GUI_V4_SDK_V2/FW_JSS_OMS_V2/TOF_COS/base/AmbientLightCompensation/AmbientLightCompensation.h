/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @defgroup ambient_light_compensation Ambient Light compensation
 * @brief Compensates the distance error caused by ambient light
 * @ingroup tof_cos
 *
 *
 * Here on the FPGA system no calculations are done in software, just the FPGA is loaded with the calibration data.
 *
 * @{
 */
#ifndef AMBIENT_LIGHT_COMPENSATION_H_
#define AMBIENT_LIGHT_COMPENSATION_H_

#include <stdint.h>

//! Compensate Ambient Light
/*!
 * This class is responsible to compensate the error caused by ambient light. Here on the FPGA
 * system it is only responsible to configure the soft logic.
 */
class AmbientLightCompensation
{
	public:
		AmbientLightCompensation();
		void setCalibrationAddress(const uint32_t address);
		void loadFpga(const uint16_t integrationTimeMultiplier);
		uint32_t getCorrectedValue(const uint32_t dcs, const uint32_t grayscale, const uint16_t integrationTimeMultiplier);

	private:
	  int32_t kalFactor;
	  uint32_t intMultiplier;
};

#endif /* AMBIENT_LIGHT_COMPENSATION_H_ */

/** @} */
