/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @defgroup average_filter Average Filter
 * @brief Average Filter on distance level
 * @ingroup tof_cos
 *
 * @{
 */
#ifndef AVERAGE_FILTER_H_
#define AVERAGE_FILTER_H_

#include <stdint.h>

//! Average filter
/*!
 * The average filter smoothes the image and is a lot faster than the median filter.
 */
class AverageFilter
{
	public:
		template <typename T> static uint32_t calcFilteredValue(uint32_t distance, T *pData, const int32_t *pIndexList, const uint32_t x, const uint32_t y, const uint32_t width, const uint32_t height);

	private:
		template <typename T> static uint32_t addValueIfValid(const T ownValue, const T otherValue);
		template <typename T> static uint32_t addValueIfValid(const uint32_t ownValue, const T otherValue);
};

//Must be included here at the end of the file
#include <AverageFilter/AverageFilter.tpp>

#endif /* AVERAGE_FILTER_H_ */

/** @} */
