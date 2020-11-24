/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup pixel_tof_grayscale Grayscale Pixel
 * @ingroup pixel
 *
 * @brief Represents one Grayscale Pixel
 *
 * @{
 */

#ifndef API_CPP_PIXELTOFGRAYSCALE_H_
#define API_CPP_PIXELTOFGRAYSCALE_H_

#include "Pixel.h"
#include <stdint.h>

//! Pixel with grayscale information
/*!
 * This Pixel contains grayscale information.
 */
class PixelToF_Grayscale: public Pixel<uint16_t>
{
	public:
		PixelToF_Grayscale();
		~PixelToF_Grayscale();
		uint16_t getValue() const;
		bool getSaturated() const;
		bool getBadPixel() const;
};

#endif /* API_CPP_PIXELTOFGRAYSCALE_H_ */

/** @} */
