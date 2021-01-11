/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 *
 * @addtogroup pixel_tof_distance_grayscale
 *
 * @{
 */
#include <Pixel/PixelToFDistanceGrayscale.h>
#include "TOF_COS_Constants.h"
#include "Confidence/Confidence.h"

/**
 * @brief Constructor
 */
PixelToF_DistanceGrayscale::PixelToF_DistanceGrayscale()
{
  pixel.distance = 0;
  pixel.grayscale = 0;
}

/**
 * @brief Set distance
 *
 * Take care: This just changes the distance. The confidence bits will stay the same.
 * This is useful for compensation or filtering.
 *
 * @param distance Distance to set
 */
void PixelToF_DistanceGrayscale::setDistance(const uint32_t distance)
{
	//Store the confidence and restore it afterwards
	uint32_t confidence = pixel.distance & DISTANCE_MASK_OUT_CONFIDENCE;

	pixel.distance = confidence | distance;
}

/**
 * @brief Get distance
 *
 * Take care: Returns the distance only. Without confidence bits.
 *
 * @return Distance
 */
uint16_t PixelToF_DistanceGrayscale::getDistance() const
{
	return pixel.distance & DISTANCE_MASK_OUT_DISTANCE;
}

uint16_t PixelToF_DistanceGrayscale::getAmplitude() const
{
	return 0;
}

/**
 * @brief Set distance, amplitude and grayscale
 *
 * Take care: Uses the amplitude only to add the confidence information. There is no amplitude stored in the pixel
 *
 * @param distance Distance to set or error code
 * @param amplitude Amplitude to use for the confidence information
 * @param grayscale Grayscale to set (0..255)
 */
void PixelToF_DistanceGrayscale::setDistanceAmplitudeGrayscale(const uint32_t distance, const uint32_t amplitude, const uint32_t grayscale)
{
	pixel.distance = distance;

	Confidence::addInformation(pixel.distance, amplitude);

	pixel.grayscale = grayscale;
}

void PixelToF_DistanceGrayscale::setDistanceAmplitude(const uint32_t distance, const uint32_t amplitude)
{
	pixel.distance = distance;

	Confidence::addInformation(pixel.distance, amplitude);
}

/**
 * @brief Mark pixel as low amplitude
 *
 * The distance value is marked with an error code. The grayscale value is still stored in the pixel.
 *
 * @param amplitude Amplitude to use for the confidence information
 * @param grayscale Grayscale to set (0..255)
 */
void PixelToF_DistanceGrayscale::setLowAmplitude(const uint32_t amplitude, const uint32_t grayscale)
{
	pixel.distance = TypePixelCode::PIXEL_CODE_LOW_AMPLITUDE;
	pixel.grayscale = grayscale;
}

/**
 * @brief Check, if pixel is saturated
 *
 * @retval true Pixel is saturated
 * @retval false Pixel is not saturated
 * @return Pixel saturated or not
 */
bool PixelToF_DistanceGrayscale::getSaturated() const
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
bool PixelToF_DistanceGrayscale::getAdcOverflow() const
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
bool PixelToF_DistanceGrayscale::getBadPixel() const
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
bool PixelToF_DistanceGrayscale::getLowAmplitude() const
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
bool PixelToF_DistanceGrayscale::isInvalid() const
{
	if (getDistance() > TypePixelCode::PIXEL_CODE_LIMIT_FOR_VALID_DATA)
	{
		return true;
	}
	return false;
}

/** @} */
