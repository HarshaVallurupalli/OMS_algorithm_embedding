/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 *
 * @addtogroup average_filter
 *
 * @{
 */
#include "AverageFilter.h"

/**
 * @brief Helper function
 *
 * If the pixel is valid, it is added, else the own value is taken.
 *
 * @param ownValue Current own distance
 * @param otherValue Other pixel to take into account
 * @return Other value if it is valid, else the own value
 */
template <typename T> uint32_t AverageFilter::addValueIfValid(const uint32_t ownValue, const T otherValue)
{
  uint32_t result = ownValue;

  if (otherValue.isInvalid() == false)
  {
    result = otherValue.getDistance();
  }

  return result;
}

/**
 * @brief Average filter on distance
 *
 * Each pixel is as result the average of the surrounding ones and itself:
 * 
 * |x|a|
 * |b|c|
 *
 * x = average(x, a, b, c)
 *
 * @param distance Current distance
 * @param pData Pointer to the data
 * @param pIndexList Pointer to the index list for filtering, always 9 elements
 * @param x Current x coordinate
 * @param y Current y coordinate
 * @return filtered value
 */
template <typename T> uint32_t AverageFilter::calcFilteredValue(uint32_t distance, T *pData, const int32_t *pIndexList, const uint32_t x, const uint32_t y, const uint32_t width, const uint32_t height)
{
  uint32_t sum = 0;

  if ( (x < (width - 1)) &&
	   (y < (height - 1)) )
  {
    uint32_t ownValue = distance;
    sum = ownValue;
	sum += addValueIfValid(ownValue, pData[pIndexList[5]]);
	sum += addValueIfValid(ownValue, pData[pIndexList[7]]);
	sum += addValueIfValid(ownValue, pData[pIndexList[8]]);

	sum >>= 2;

    return sum;
  }
  else
  {
    return distance;
  }
}

/** @} */
