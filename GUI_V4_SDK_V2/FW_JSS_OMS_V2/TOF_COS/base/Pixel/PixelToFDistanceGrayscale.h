/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @defgroup pixel_tof_distance_grayscale Distance/Grayscale Pixel
 * @ingroup pixel
 *
 * @brief Represents one Distance/Grayscale Pixel
 *
 * @{
 */
#ifndef PIXEL_TOF_DISTANCE_GRAYSCALE_H_
#define PIXEL_TOF_DISTANCE_GRAYSCALE_H_

#include "Pixel.h"
#include <stdint.h>

#pragma pack(push,1)
typedef struct
{
  uint8_t grayscale;
	uint16_t distance;
}distanceGrayscale_t;
#pragma pack(pop)

//! Pixel with distance and amplitude information
/*!
 * This Pixel contains distance and grayscale information.
 */
class PixelToF_DistanceGrayscale: public Pixel<distanceGrayscale_t>
{
	public:
		PixelToF_DistanceGrayscale();
		void setDistance(const uint32_t distance);
		uint16_t getDistance() const;
		uint16_t getAmplitude() const;
		void setDistanceAmplitude(const uint32_t distance, const uint32_t amplitude);
		void setDistanceAmplitudeGrayscale(const uint32_t distance, const uint32_t amplitude, const uint32_t grayscale);
		void setLowAmplitude(const uint32_t amplitude, const uint32_t grayscale);
		bool getSaturated() const;
		bool getAdcOverflow() const;
		bool getBadPixel() const;
		bool getLowAmplitude() const;
		bool isInvalid() const;
};

#endif /* PIXEL_TOF_DISTANCE_GRAYSCALE_H_ */

/** @} */
