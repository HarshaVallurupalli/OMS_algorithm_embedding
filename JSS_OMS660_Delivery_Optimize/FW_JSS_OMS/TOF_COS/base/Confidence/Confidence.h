/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup confidence Confidence
 * @ingroup tof_cos
 * @brief Responsible to mark the distance information with confidence bits
 *
 * @{
 */
#ifndef CONFIDENCE_H_
#define CONFIDENCE_H_

#include <stdint.h>

//! Confidence
/*!
 * This class is responsible to mark the distance information with confidence bits. These confidence bits give
 * information about the distance quality.
 */
class Confidence
{
	public:
		static void addInformation(uint16_t &distance, const uint32_t amplitude);
		static void setLimit(const uint32_t index, const uint32_t amplitude);
		static uint32_t getLimit(const uint32_t index);
		static void init();
		static uint32_t amplitudeToSquaredAmplitude(const uint32_t amplitude);
		static uint32_t amplitudeSquaredToAmplitude(const uint32_t amplitude);

	private:
		static const uint32_t NUM_AMPLITUDE_LIMIT = 3;
		static uint32_t amplitudeLimit[NUM_AMPLITUDE_LIMIT];
};

#endif /* CONFIDENCE_H_ */

/** @} */
