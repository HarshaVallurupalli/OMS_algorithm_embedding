/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup median_filter Median Filter
 * @brief Median filter for the pixels.
 * @ingroup tof_cos
 *
 * @{
 */
#ifndef MEDIANFILTER_H_
#define MEDIANFILTER_H_

#include <stdint.h>

//! Median filter
/*!
 * The median filter smoothes the image data quite good but it takes a lot of computing time.
 */
class MedianFilter
{
	public:
		template <typename T> static uint32_t calcFilteredValue(uint32_t distance, T *pData, const int32_t *pIndexList, const uint32_t x, const uint32_t y, const uint32_t width, const uint32_t height);

	private:
		template <typename T> static void addValueIfValid(T *pData, uint32_t *array, const uint32_t index, uint32_t &num);
};

//Must be included here at the end of the file
#include "MedianFilter.tpp"

#endif /* MEDIANFILTER_H_ */

/** @} */
