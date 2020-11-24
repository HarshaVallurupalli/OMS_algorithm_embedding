/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 *
 * @addtogroup pixel_tof_dcs
 *
 * @{
 */
#include <Pixel/PixelToFDcs.h>

/**
 * @brief Check, if pixel is invalid
 *
 * @retval true Pixel is invalid
 * @retval false Pixel is valid
 * @return Pixel is invalid or not
 */
bool PixelToF_Dcs::isInvalid() const
{
	if (pixel > TypePixelCode::PIXEL_CODE_LIMIT_FOR_VALID_DATA)
	{
		return true;
	}
	return false;
}

/**
 * @brief Get the DCS value
 *
 * @return DCS value
 */
uint16_t PixelToF_Dcs::getValue() const
{
	return pixel;
}

/**
 * @brief Set the DCS value
 *
 * @param DCS value
 */
void PixelToF_Dcs::setValue(const uint16_t value)
{
  pixel = value;
}

/**
 * @brief Set to saturated
 *
 * Set special code for saturation.
 */
void PixelToF_Dcs::setSaturated()
{
  pixel = TypePixelCode::PIXEL_CODE_SATURATION;
}

/**
 * @brief Set to adc overflow
 *
 * Set special code for adc overflow.
 */
void PixelToF_Dcs::setAdcOverflow()
{
  pixel = TypePixelCode::PIXEL_CODE_ADC_OVERFLOW;
}

/** @} */
