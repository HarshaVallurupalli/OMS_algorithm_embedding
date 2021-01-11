/***
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @addtogroup edge_filter
 */
#include "EdgeFilter.h"
#include <stdlib.h>

/**
 * @brief Constructor
 *
 */
EdgeFilter::EdgeFilter()
{
	threshold = DEFAULT_THRESHOLD;
}

/**
 * @brief Set threshold
 *
 * @param threshold Threshold to set
 */
void EdgeFilter::setThreshold(const uint32_t threshold)
{
	this->threshold = threshold;
}

/**
 * @brief Read back if the edge filter is enabled
 *
 * @retval true Edge filter is enabled
 * @retval false Edge filter is disabled
 * @return Edge filter enabled or disabled
 */
bool EdgeFilter::isEnabled() const
{
	if (threshold == 0)
	{
		return false;
	}

	return true;
}

/**
 * @brief Start the filter
 *
 * This function must be called before using the filter. It initializes the variables needed during filtering.
 *
 * @param width Width of the image
 * @param height Height of the image
 * @param pData Pointer to the data
 */
void EdgeFilter::startFilter(const uint16_t width, const uint16_t height)
{
	this->edgeDetectX = 0;
	this->edgeDetectY = 0;
	this->width = width;
	this->height = height;
}

/**
 * @brief Filter distance
 *
 * This is the main filter function and implemented as template function to be able to work with
 * different types of pixels.
 * It scans the pixels in horizontal and vertical direction. One big edge is allowed, because ideally a near object
 * in front of a far object would cause a big edge.
 *
 * @param distance Current distance
 * @param pData Pointer to the data
 * @param pIndexList Pointer to the index list for filtering
 * @param x Current x coordinate
 * @param y Current y coordinate
 * @return filtered value
 */
template <typename T> uint32_t EdgeFilter::calcFilteredValue(const uint32_t distance, T *pData, const int32_t *pIndexList, uint16_t x, uint16_t y)
{
  uint32_t filteredDistance = distance;
uint32_t PixelRightIndex=pIndexList[5];
uint32_t PixelBottomIndex=pIndexList[7];


	if ((x < (width - 1)) &&
  		(pData[PixelRightIndex].isInvalid() == false))
  {
  	int32_t distance1 = pData[PixelRightIndex].getDistance();
  	int32_t diff = abs(static_cast<int32_t>(distance) - distance1);
  	if (threshold < diff)
  	{
  		edgeDetectX++;

  		if (edgeDetectX != 1)
  		{
  			filteredDistance = TypePixelCode::PIXEL_CODE_EDGE_FILTERED;
  		}
  	}
  	else
  	{
  		edgeDetectX = 0;
  	}
  }


  if ((y < (height - 1)) &&
    	(pData[PixelBottomIndex].isInvalid() == false))
	{
  	int32_t distance1 = pData[PixelBottomIndex].getDistance();
  	int32_t diff = abs(static_cast<int32_t>(distance) - distance1);
		if (threshold < diff)
		{
		  edgeDetectY++;

		  if (edgeDetectY != 1)
		  {
		  	filteredDistance = TypePixelCode::PIXEL_CODE_EDGE_FILTERED;
		  }
		 }
		 else
		 {
		   edgeDetectY = 0;
		 }
	}

  return filteredDistance;
}

/**
 * @brief Filter distance on distance pixel
 *
 * All pixels with detected edge are marked with a pixel code.
 *
 * @param distance Current distance
 * @param pData Pointer to the data
 * @param pIndexList Pointer to the index list for filtering
 * @param x Current x coordinate
 * @param y Current y coordinate
 * @return filtered value
 */
uint32_t EdgeFilter::calcFilteredValue(const uint32_t distance, PixelToF_Distance *pData, const int32_t *pIndexList, uint16_t x, uint16_t y)
{
	return calcFilteredValue<PixelToF_Distance>(distance, pData, pIndexList, x, y);
}

/**
 * @brief Filter distance on distance amplitude pixel
 *
 * All pixels with detected edge are marked with a pixel code.
 *
 * @param distance Current distance
 * @param pData Pointer to the data
 * @param pIndexList Pointer to the index list for filtering
 * @param x Current x coordinate
 * @param y Current y coordinate
 * @return filtered value
 */
uint32_t EdgeFilter::calcFilteredValue(const uint32_t distance, PixelToF_DistanceAmplitude *pData, const int32_t *pIndexList, uint16_t x, uint16_t y)
{
	return calcFilteredValue<PixelToF_DistanceAmplitude>(distance, pData, pIndexList, x, y);
}

/**
 * @brief Filter distance on distance grayscale pixel
 *
 * All pixels with detected edge are marked with a pixel code.
 *
 * @param distance Current distance
 * @param pData Pointer to the data
 * @param pIndexList Pointer to the index list for filtering
 * @param x Current x coordinate
 * @param y Current y coordinate
 * @return filtered value
 */
uint32_t EdgeFilter::calcFilteredValue(const uint32_t distance, PixelToF_DistanceGrayscale *pData, const int32_t *pIndexList, uint16_t x, uint16_t y)
{
	return calcFilteredValue<PixelToF_DistanceGrayscale>(distance, pData, pIndexList, x, y);
}



/** @} */
