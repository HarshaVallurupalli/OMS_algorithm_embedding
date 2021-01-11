/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 *
 * @addtogroup pixel_tof_distance_amplitude
 *
 * @{
 */
#include <Pixel/PixelToFDistanceAmplitude.h>
#include "TOF_COS_Constants.h"

/**
 * @brief Constructor
 */
PixelToF_DistanceAmplitude::PixelToF_DistanceAmplitude()
{
  pixel = 0;
}

/**
 * @brief Set distance
 *
 * Take care: This just changes the distance. The amplitude will stay the same.
 * This is useful for compensation or filtering.
 *
 * @param distance Distance to set
 */
void PixelToF_DistanceAmplitude::setDistance(const uint32_t distance)
{
	uint32_t amplitude = pixel & AMPLITUDE_MASK;

	pixel = (distance << DISTANCE_SHIFT) | amplitude;
}

/**
 * @brief Get the distance value
 *
 * @return distance value
 */
uint16_t PixelToF_DistanceAmplitude::getDistance() const
{
  return ((pixel  & DISTANCE_MASK) >> DISTANCE_SHIFT);
}

/**
 * @brief Get the amplitude value
 *
 * @return amplitude value
 */
uint16_t PixelToF_DistanceAmplitude::getAmplitude() const
{
	return ((pixel & AMPLITUDE_MASK) >> AMPLITUDE_SHIFT);
}

/**
 * @brief Set distance, amplitude
 *
 * @param distance Distance to set or error code
 * @param amplitude Amplitude to set
 */
void PixelToF_DistanceAmplitude::setDistanceAmplitude(const uint32_t distance, const uint32_t amplitude)
{
  pixel = (distance << DISTANCE_SHIFT) | (amplitude << AMPLITUDE_SHIFT);
}

/**
 * @brief Mark pixel as low amplitude
 *
 * The amplitude is still stored in the pixel
 *
 * @param amplitude Amplitude
 */
void PixelToF_DistanceAmplitude::setLowAmplitude(const uint32_t amplitude)
{
	pixel = (TypePixelCode::PIXEL_CODE_LOW_AMPLITUDE << DISTANCE_SHIFT) | (amplitude << AMPLITUDE_SHIFT);
}

/**
 * @brief Mark pixel as filtered from edge detection
 *
 */
void PixelToF_DistanceAmplitude::setEdgeFiltered()
{
	pixel = (TypePixelCode::PIXEL_CODE_EDGE_FILTERED  << DISTANCE_SHIFT) | 0;
}

/**
 * @brief Mark pixel as saturated
 *
 */
void PixelToF_DistanceAmplitude::setSaturated()
{
	pixel = (TypePixelCode::PIXEL_CODE_SATURATION  << DISTANCE_SHIFT) | (TypePixelCode::PIXEL_CODE_SATURATION  << AMPLITUDE_SHIFT);
}

/**
 * @brief Mark pixel as adc overflow
 *
 */
void PixelToF_DistanceAmplitude::setAdcOverflow()
{
	pixel = (TypePixelCode::PIXEL_CODE_ADC_OVERFLOW  << DISTANCE_SHIFT) | (TypePixelCode::PIXEL_CODE_ADC_OVERFLOW  << AMPLITUDE_SHIFT);
}

/**
 * @brief Mark pixel as interfered
 *
 */
void PixelToF_DistanceAmplitude::setInterfered()
{
	pixel = (TypePixelCode::PIXEL_CODE_INTERFERENCE  << DISTANCE_SHIFT) | (TypePixelCode::PIXEL_CODE_INTERFERENCE  << AMPLITUDE_SHIFT);
}

/**
 * @brief Mark pixel as broken
 *
 */
void PixelToF_DistanceAmplitude::setBroken()
{
	pixel = (TypePixelCode::PIXEL_CODE_BAD << DISTANCE_SHIFT) | (TypePixelCode::PIXEL_CODE_BAD  << AMPLITUDE_SHIFT);
}

/**
 * @brief Check, if pixel is saturated
 *
 * @retval true Pixel is saturated
 * @retval false Pixel is not saturated
 * @return Pixel saturated or not
 */
bool PixelToF_DistanceAmplitude::getSaturated() const
{
  if (getDistance() == TypePixelCode::PIXEL_CODE_SATURATION)
	{
	  return true;
	}
	return false;
}

/**
 * @brief Check, if pixel has ADC overflow
 *
 * @retval true Pixel has ADC overflow
 * @retval false Pixel does not have ADC overflow
 * @return Pixel has ADC overflow or not
 */
bool PixelToF_DistanceAmplitude::getAdcOverflow() const
{
	if (getDistance() == TypePixelCode::PIXEL_CODE_ADC_OVERFLOW)
	{
	  return true;
	}
	return false;
}

/**
 * @brief Check, if pixel is bad
 *
 * @retval true Pixel is bad
 * @retval false Pixel is not bad
 * @return Pixel is bad or not
 */
bool PixelToF_DistanceAmplitude::getBadPixel() const
{
	if (getDistance() == TypePixelCode::PIXEL_CODE_BAD)
	{
	  return true;
	}
	return false;
}

/**
 * @brief Check, if pixel has low amplitude
 *
 * @retval true Pixel has low amplitude
 * @retval false Pixel does not have low amplitude
 * @return Pixel has low amplitude or not
 */
bool PixelToF_DistanceAmplitude::getLowAmplitude() const
{
	if (getDistance() == TypePixelCode::PIXEL_CODE_LOW_AMPLITUDE)
	{
	  return true;
	}
	return false;
}

/**
 * @brief Check, if pixel is invalid
 *
 * @retval true Pixel is invalid
 * @retval false Pixel is valid
 * @return Pixel is invalid or not
 */
bool PixelToF_DistanceAmplitude::isInvalid() const
{
	if (getDistance() > TypePixelCode::PIXEL_CODE_LIMIT_FOR_VALID_DATA)
	{
		return true;
	}
	return false;
}

/** @} */
