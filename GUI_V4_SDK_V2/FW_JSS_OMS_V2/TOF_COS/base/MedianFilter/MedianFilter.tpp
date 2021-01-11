/***
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @addtogroup median_filter
 */
#include "QuickSort/QuickSort.h"

/**
 * @brief Helper function
 *
 * If the pixel is valid, it is added, else it is discarded.
 *
 * @param pData Pointer to the data
 * @param index Index of the pixel
 * @param num Reference to the number of pixels to inecreas
 */
template <typename T> void MedianFilter::addValueIfValid(T *pData, uint32_t *array, const uint32_t index, uint32_t &num)
{
  if (pData[index].isInvalid() == false)
  {
    array[num] = pData[index].getDistance();	
	num++;
  }
}

/**
 * @brief Median filter on distance
 *
 * For each pixels all surrounding pixels are taken into account. These nine pixels
 * are sorted and the middle one (median) is taken as value.
 *
 * @param distance Current distance
 * @param pData Pointer to the data
 * @param pIndexList Pointer to the index list for filtering, always 9 elements
 * @param x Current x coordinate
 * @param y Current y coordinate
 * @return filtered value
 */
template <typename T> uint32_t MedianFilter::calcFilteredValue(uint32_t distance, T *pData, const int32_t *pIndexList, const uint32_t x, const uint32_t y, const uint32_t width, const uint32_t height)
{
  uint32_t array[64];
  
  if ((x > 0) &&
  	  (x < (width - 1)) &&
	  (y > 0) &&
	  (y < (height - 1)) )
  {
    uint32_t num = 0;
    
    addValueIfValid(pData, array, pIndexList[0], num);
    addValueIfValid(pData, array, pIndexList[1], num);
    addValueIfValid(pData, array, pIndexList[2], num);
  	
    addValueIfValid(pData, array, pIndexList[3], num);
    addValueIfValid(pData, array, pIndexList[4], num);
    addValueIfValid(pData, array, pIndexList[5], num);
  	
    addValueIfValid(pData, array, pIndexList[6], num);
    addValueIfValid(pData, array, pIndexList[7], num);
    addValueIfValid(pData, array, pIndexList[8], num);  
    
    if (num < 2)
    {
      return pData[pIndexList[4]].getDistance();
    }   
    
    QuickSort::quickSort(array, num);
    
    return array[num / 2];     
  }
  else
  {
    return pData[pIndexList[4]].getDistance();    
  }
}

/** @} */
