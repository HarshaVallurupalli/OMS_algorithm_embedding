/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup hysteresis Hysteresis
 * @brief Hysteresis for minimal amplitude
 * @ingroup tof_cos
 *
 * @{
 */
#ifndef HYSTERESIS_H_
#define HYSTERESIS_H_

#include <stdint.h>

//! Hysteresis
/*!
 * This class adds a hysteresis to the minimal amplitude to prevent flickering.
 */
class Hysteresis
{
	public:
		Hysteresis();
		uint32_t calcMinAmplitudeWithHysteresis(const uint32_t lastDistance);
		uint32_t setMinAmplitude(const uint32_t amplitude, const bool squared, const bool enabled);

	private:
    uint32_t minAmplitude;
    uint32_t minAmplitudeHysteresis;
    uint8_t hysteresis;
};

#endif /* HYSTERESIS_H_ */

/** @} */
