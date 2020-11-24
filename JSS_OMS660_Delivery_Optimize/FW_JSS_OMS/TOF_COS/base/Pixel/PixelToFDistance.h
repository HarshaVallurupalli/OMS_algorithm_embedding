/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup pixel_tof_distance Distance Pixel
 * @ingroup pixel
 *
 * @brief Represents one Distance Pixel
 *
 * @{
 */
#ifndef PIXEL_TOF_DISTANCE_H_
#define PIXEL_TOF_DISTANCE_H_

#include "Pixel.h"

//! Pixel with distance information
/*!
 * This Pixel contains only distance information.
 */
class PixelToF_Distance: public Pixel<uint16_t>
{
	public:
		PixelToF_Distance();
		void setDistance(const uint32_t distance);
		void setDistanceAmplitude(const uint32_t distance, const uint32_t amplitude);
		uint32_t getDistance() const;
		bool getSaturated() const;
		bool getAdcOverflow() const;
		bool getBadPixel() const;
		void setLowAmplitude(const uint32_t amplitude);
		void setSaturated();
		void setAdcOverflow();
		void setEdgeFiltered();
		void setInterfered();
		void setBroken();
		bool getLowAmplitude() const;
		bool isInvalid() const;
};

#endif /* PIXEL_TOF_DISTANCE_H_ */

/** @} */
