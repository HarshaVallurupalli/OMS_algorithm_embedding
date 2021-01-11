/***
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @addtogroup confidence
 */
#include "Confidence.h"
#include "TOF_COS_Constants.h"
#include <math.h>

static const uint32_t DEFAULT_AMPLITUDE_LIMIT_0 = 100;                           ///<[lsb] Amplitude limit for confidence value 0/1
static const uint32_t DEFAULT_AMPLITUDE_LIMIT_1 = 200;                           ///<[lsb] Amplitude limit for confidence value 1/2
static const uint32_t DEFAULT_AMPLITUDE_LIMIT_2 = 500;                           ///<[lsb] Amplitude limit for confidence value 2/3

///Amplitude limits to set the bits
uint32_t Confidence::amplitudeLimit[NUM_AMPLITUDE_LIMIT];

/**
 * @brief Init
 *
 * This function initializes the amplitude limits to the default values.
 */
void Confidence::init()
{
	setLimit(0, DEFAULT_AMPLITUDE_LIMIT_0);
	setLimit(1, DEFAULT_AMPLITUDE_LIMIT_1);
	setLimit(2, DEFAULT_AMPLITUDE_LIMIT_2);
}

/**
 * @brief Amplitude to squared amplitude
 *
 * This function converts the amplitude to a squared amplitude. This is to not need
 * the calculation of the square root during distance only mode.
 *
 * @param amplitude
 * @return squared amplitude
 */
uint32_t Confidence::amplitudeToSquaredAmplitude(const uint32_t amplitude)
{
	uint32_t amplitudeSquared = amplitude * amplitude * 4;

	return amplitudeSquared;
}

/**
 * @brief Amplitude squared to amplitude
 *
 * This function converts a squared amplitude to a normal amplitude. This is to not need
 * the calculation of the square root during distance only mode.
 *
 * @param amplitude squared amplitude
 * @return amplitude
 */
uint32_t Confidence::amplitudeSquaredToAmplitude(const uint32_t amplitude)
{
	uint32_t normalAmplitude = sqrtf((float) (amplitude)) / 2.0f;

	return normalAmplitude;
}

/**
 * @brief Set the amplitude limit
 *
 * This function sets the amplitude limit
 *
 * @param index Index of the amplitude limit to set
 * @param amplitude Amplitude to set
 */
void Confidence::setLimit(const uint32_t index, const uint32_t amplitude)
{
	if (index >= NUM_AMPLITUDE_LIMIT)
	{
	  return;
	}

	amplitudeLimit[index] = amplitudeToSquaredAmplitude(amplitude);
}

/**
 * @brief Get the amplitude limit
 *
 * This function gets the amplitude limit
 *
 * @param index Index of the amplitude limit to set
 * @return amplitude Amplitude
 */
uint32_t Confidence::getLimit(const uint32_t index)
{
	if (index >= NUM_AMPLITUDE_LIMIT)
	{
	  return 0;
	}

  return amplitudeLimit[index];
}

/**
 * @brief Add the confidence information
 *
 * This function adds the confidence bits to the distance
 *
 * @param distance Reference to the distance to add the confidence
 * @param amplitude Amplitude of the pixel
 */
void Confidence::addInformation(uint16_t &distance, const uint32_t amplitude)
{
	uint32_t confidence = 0;

	for (int32_t i = NUM_AMPLITUDE_LIMIT; i > 0; i--)
	{
		if (amplitude > amplitudeLimit[i-1])
		{
			confidence = i << CONFIDENCE_SHIFT;
			break;
		}
	}

	distance |= confidence;
}

/** @} */
