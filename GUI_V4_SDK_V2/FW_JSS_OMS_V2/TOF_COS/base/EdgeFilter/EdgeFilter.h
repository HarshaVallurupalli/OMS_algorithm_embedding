/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup edge_filter Edge Filter
 * @brief Edge filter for the pixels.
 * @ingroup tof_cos
 *
 * @{
 */
#ifndef EDGE_FILTER_
#define EDGE_FILTER_

#include "Pixel/PixelToFDistance.h"
#include "Pixel/PixelToFDistanceAmplitude.h"
#include "Pixel/PixelToFDistanceGrayscale.h"

//! Edge filter
/*!
 * This filter detects edges in the distance and marks such pixel with a special code. This helps to remove flying pixels.
 * Flying pixels happen if a pixel does is covered partly by a near object and a far object. So the resulting distance is some
 * kind of a mix.
 */
class EdgeFilter
{
	public:
		EdgeFilter();
		void setThreshold(const uint32_t threshold);
		void startFilter(const uint16_t width, const uint16_t height);
		uint32_t calcFilteredValue(const uint32_t distance, PixelToF_Distance *pData, const int32_t *pIndexList, uint16_t x, uint16_t y);
		uint32_t calcFilteredValue(const uint32_t distance, PixelToF_DistanceAmplitude *pData, const int32_t *pIndexList, uint16_t x, uint16_t y);
		uint32_t calcFilteredValue(const uint32_t distance, PixelToF_DistanceGrayscale *pData, const int32_t *pIndexList, uint16_t x, uint16_t y);
		bool isEnabled() const;

	private:
		const int32_t DEFAULT_THRESHOLD = 300;

		template<typename T> uint32_t calcFilteredValue(const uint32_t distance, T *pData, const int32_t *pIndexList, uint16_t x, uint16_t y);
	  int32_t threshold;                  ///<Threshold for the edge filter in mm
	  uint16_t width;                     ///<Width of the image in pixels
	  uint16_t height;                    ///<Height of the image in pixels
	  int16_t edgeDetectX;                ///<Counter variable for the edge detection in x direction
	  int16_t edgeDetectY;                ///<Counter variable for the edge detection in y direction
};

#endif /* EDGE_FILTER_ */

/** @} */
