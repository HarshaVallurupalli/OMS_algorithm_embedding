/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 *
 * @addtogroup pixel_tof_distance
 *
 * @{
 */
#include "TOF_COS_Constants.h"
#include "PixelToFDistance.h"
#include "Confidence/Confidence.h"
#include "TOF_COS_Config.h"

/**
 * @brief Constructor
 */
PixelToF_Distance::PixelToF_Distance()
{
  pixel = 0;
}

/**
 * @brief Set distance, amplitude
 *
 * Take care: Uses the amplitude only to add the confidence information. There is no amplitude stored in the pixel.
 *
 * @param distance Distance to set or error code
 * @param amplitude Amplitude to use for the confidence information
 */
void PixelToF_Distance::setDistanceAmplitude(const uint32_t distance, const uint32_t amplitude)
{
  pixel = distance;

#if(TOF_COS_USE_CONFIDENCE_BITS==1)
  Confidence::addInformation(pixel, amplitude); //todo: add confidence information
#endif
}

/**
 * @brief Set distance
 *
 * Take care: This just changes the distance. The confidence bits will stay the same.
 * This is useful for compensation or filtering.
 *
 * @param distance Distance to set
 */
void PixelToF_Distance::setDistance(const uint32_t distance)
{
#if(TOF_COS_USE_CONFIDENCE_BITS==1)
	uint32_t confidence = pixel & DISTANCE_MASK_OUT_CONFIDENCE;

	pixel = confidence | distance;
#else
	pixel = distance;
#endif
}

/**
 * @brief Get the distance value
 *
 * Take care: The confidence information is masked out
 *
 * @return distance value
 */
uint16_t PixelToF_Distance::getDistance() const
{
	uint32_t distance = pixel;
#if(TOF_COS_USE_CONFIDENCE_BITS==1)
	distance &= DISTANCE_MASK_OUT_DISTANCE;
#endif
	return distance;
}

uint16_t PixelToF_Distance::getAmplitude() const
{
	return 0;
}
/**
 * @brief Check, if pixel is saturated
 *
 * @retval true Pixel is saturated
 * @retval false Pixel is not saturated
 * @return Pixel saturated or not
 */
bool PixelToF_Distance::getSaturated() const
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
bool PixelToF_Distance::getAdcOverflow() const
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
bool PixelToF_Distance::getBadPixel() const
{
	if (getDistance() == TypePixelCode::PIXEL_CODE_BAD)
	{
	  return true;
	}
	return false;
}

/**
 * @brief Mark pixel as low amplitude
 *
 * @param amplitude Amplitude, not used, for compatibility reasons
 */
void PixelToF_Distance::setLowAmplitude(const uint32_t amplitude __attribute__((unused)))
{
	pixel = TypePixelCode::PIXEL_CODE_LOW_AMPLITUDE;
}

/**
 * @brief Mark pixel as saturated
 *
 */
void PixelToF_Distance::setSaturated()
{
	pixel = TypePixelCode::PIXEL_CODE_SATURATION;
}

/**
 * @brief Mark pixel as ADC overflow
 *
 */
void PixelToF_Distance::setAdcOverflow()
{
	pixel = TypePixelCode::PIXEL_CODE_ADC_OVERFLOW;
}

/**
 * @brief Mark pixel as filtered from edge detection
 *
 */
void PixelToF_Distance::setEdgeFiltered()
{
	pixel = TypePixelCode::PIXEL_CODE_EDGE_FILTERED;
}

/**
 * @brief Mark pixel as interfered
 *
 */
void PixelToF_Distance::setInterfered()
{
	pixel = TypePixelCode::PIXEL_CODE_INTERFERENCE;
}

/**
 * @brief Mark pixel as broken
 *
 */
void PixelToF_Distance::setBroken()
{
	pixel = TypePixelCode::PIXEL_CODE_BAD;
}

/**
 * @brief Check, if pixel has low amplitude
 *
 * @retval true Pixel has low amplitude
 * @retval false Pixel does not have low amplitude
 * @return Pixel has low amplitude or not
 */
bool PixelToF_Distance::getLowAmplitude() const
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
bool PixelToF_Distance::isInvalid() const
{
	if (getDistance() > TypePixelCode::PIXEL_CODE_LIMIT_FOR_VALID_DATA)
	{
		return true;
	}
	return false;
}

/** @} */
