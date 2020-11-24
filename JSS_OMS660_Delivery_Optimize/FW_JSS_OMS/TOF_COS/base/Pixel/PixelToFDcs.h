/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup pixel_tof_dcs DCS Pixel
 * @ingroup pixel
 *
 * @brief Represents one DCS Pixel
 *
 * @{
 */
#ifndef PIXEL_TOF_DCS_H_
#define PIXEL_TOF_DCS_H_

#include "Pixel.h"

//! Pixel with DCS information
/*!
 * This Pixel contains DCS information.
 */
class PixelToF_Dcs: public Pixel<uint16_t>
{
	public:
		bool isInvalid() const;
		uint16_t getValue() const;
		void setValue(const uint16_t value);
		void setSaturated();
		void setAdcOverflow();
};

#endif /* PIXEL_TOF_DCS_H_ */

/** @} */
