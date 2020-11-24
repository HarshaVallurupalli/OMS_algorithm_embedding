/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup pixel_tof_distance_amplitude Distance/Amplitude Pixel
 * @ingroup pixel
 *
 * @brief Represents one Distance/Amplitude Pixel
 *
 * @{
 */
#ifndef PIXEL_TOF_DISTANCE_AMPLITUDE_H_
#define PIXEL_TOF_DISTANCE_AMPLITUDE_H_

#include "Pixel.h"

//! Pixel with distance and amplitude information
/*!
 * This Pixel contains distance and amplitude information.
 */
class PixelToF_DistanceAmplitude: public Pixel<uint32_t>
{
	public:
		PixelToF_DistanceAmplitude();
		void setDistance(const uint32_t distance);
		uint16_t getDistance() const;
		uint16_t getAmplitude() const;
		void setDistanceAmplitude(const uint32_t distance, const uint32_t amplitude);
		void setLowAmplitude(const uint32_t amplitude);
		void setEdgeFiltered();
		void setSaturated();
		void setAdcOverflow();
		void setInterfered();
		void setBroken();
		bool getSaturated() const;
		bool getAdcOverflow() const;
		bool getBadPixel() const;
		bool getLowAmplitude() const;
		bool isInvalid() const;
};

#endif /* PIXEL_TOF_DISTANCE_AMPLITUDE_H_ */

/** @} */
