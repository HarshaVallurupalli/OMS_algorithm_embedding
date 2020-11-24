/***
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @addtogroup roi_settings
 */
#include "RoiSettings.h"
#include "ChipSelection.h"

/**
 * @brief Constructor
 *
 */
RoiSettings::RoiSettings()
{
	index = 0;

	for (uint8_t i = 0; i < TOF_COS_NUM_SETTINGS; i++)
	{
	  setRoiInternal(0, 0, ROI_X_MAX, ROI_Y_MAX, i);
	}
}

/**
 * @brief Get width
 *
 * @return Width in pixels
 */
uint16_t RoiSettings::getWidth() const
{
  return (roi[index].xMax - roi[index].xMin + 1);
}

/**
 * @brief Get height
 *
 * @return Height in pixels
 */
uint16_t RoiSettings::getHeight() const
{
  return (roi[index].yMax - roi[index].yMin + 1);
}

/**
 * @brief Get width in case of full resolution
 *
 * @return Width in pixels
 */
uint16_t RoiSettings::getFullResolutionWidth() const
{
	return (ROI_X_MAX + 1);
}

/**
 * @brief Get height in case of full resolution
 *
 * @return Height in pixels
 */
uint16_t RoiSettings::getFullResolutionHeight() const
{
  return (ROI_Y_MAX + 1);
}

/**
 * @brief Limit to maximum value
 *
 * Helper function to limit ROI values to a maximum value.
 *
 * @param value Wanted value
 * @param limit Maximum value
 * @return valid value
 */
uint16_t RoiSettings::limitValue(const uint16_t value, const uint16_t limit)
{
	uint16_t returnValue = value;

	if (returnValue > limit)
  {
		returnValue = limit;
  }

  return returnValue;
}

/**
 * @brief Make a even number if needed
 *
 *
 * @param value Current value
 * @return valid (even) value
 */
uint16_t RoiSettings::makeEven(const uint16_t value)
{
  uint16_t finalValue = value;

  if ((finalValue % 2) != 0)
  {
    //Normally decrease by one. Only in case of zero increase it
    if (finalValue > 0)
    {
      finalValue--;
    }
    else
    {
      finalValue++;
    }
  }

  return finalValue;
}

/**
 * @brief Fit the values of the ROI
 *
 * This function is needed to fit the values of the ROI to valid values. There are some requirements
 * - width or height must be a multiplication of 4
 * - A minimum width or height is required
 * - minimum value must be even and maximum odd
 *
 * This function can be used for width or height depending on the parameters.
 *
 * @param min Reference to min
 * @param max Reference to max
 * @param maxValue Maximal possible value
 * @param minRange Maximal range; max - min + 1
 * @return Range; = Width or height
 */
uint16_t RoiSettings::fitValues(uint16_t &min, uint16_t &max, const uint16_t maxValue, const uint16_t minRange)
{
	uint16_t range = max - min + 1;

  //First limit to the minimum range
  if (range < minRange)
  {
  	uint16_t valueToAdd = minRange - range;

    //Either increase the maximum or decrease the minimum. Depending on the position.
  	if ((maxValue - max) > min)
  	{
  		max += valueToAdd;
  	}
  	else
  	{
  		min -= valueToAdd;
  	}

  	range = max - min + 1;
  }

  //The number must be a multiplication of 4
  uint16_t remaining = range % 4;
  uint16_t half = maxValue / 2;

  //Try to make the range smaller. But it must have a minimal size.
  while(remaining > 0)
  {
  	if (range > minRange)
  	{
  	  //Depending of the position increase the minimum or decrease the maximum
  		if (min < half)
  	  {
  	  	min++;
  	  }
  	  else
  	  {
  	  	max--;
  	  }
  	}
  	else
  	{
  		//Minimum range reached. Stop
  		break;
  	}

  	range = max - min + 1;
  	remaining = range % 4;
  }

  //If it is still not a multiplication of 4, make the range bigger
  while(remaining > 0)
  {
    //Depending of the position decrease the minimum or increase the maximum
  	if (min > half)
    {
      min--;
    }
    else
    {
      max++;
    }

    range = max - min + 1;
    remaining = range % 4;
  }

  //Make sure that min is even and max is odd. Because the range is already a multiplier of four, just check the max. If max is even, min is odd and vice versa
  if ((max & 1) == 0)
  {
  	//Max can be increased, so increase both
  	if (max < maxValue)
  	{
  	  max++;
  	  min++;
  	}
  	else
  	{
  		//Max must be decreased. Check if min can be decreased too, or if it must bi increased
  		max--;
  		if (min > 0)
  		{
  		  min--;
  		}
  		else
  		{
  			min++;
  		}
    }
  }

  return range;
}

/**
 * @brief Set ROI
 *
 * Set the ROI of the given index.
 * If all values of the ROI are zero, the default ROI (full image) is selected.
 *
 * @param roi ROI to set
 * @param index Index of the ROI
 */
void RoiSettings::setRoi(const Roi roi, const uint8_t index)
{
  if ((roi.xMin == 0) &&
  		(roi.yMin == 0) &&
			(roi.xMax == 0) &&
			(roi.yMax == 0))
  {
    setRoiInternal(0, 0, ROI_X_MAX, ROI_Y_MAX, index);
  }
  else
  {
  	setRoiInternal(roi.xMin, roi.yMin, roi.xMax, roi.yMax, index);
  }
}

/**
 * @brief Select a ROI
 *
 * Selects the ROI of the given index.
 * In case of a change a flag is set to indicate that the TOF imager
 * needs to be reconfigured.
 *
 * @param index Index of the ROI
 */
void RoiSettings::selectRoi(const uint8_t index)
{
	if (this->index != index)
	{
		changed = true;
		this->index = index;
	}
}

/**
 * @brief Set ROI internal
 *
 * Helper function to set the ROI internal. The ROI is automatically limited to valid
 * values --> the final ROI may be slightly different.
 *
 * @param roiXmin X min coordinate
 * @param roiYmin Y min coordinate
 * @param roiXmax X max coordinate
 * @param roiYmax Y max coordinate
 * @param index Index of the settings
 */
void RoiSettings::setRoiInternal(const uint16_t roiXmin, const uint16_t roiYmin, const uint16_t roiXmax, const uint16_t roiYmax, const uint8_t index)
{
  changed = true;

  //Limit the maximum values first
	uint16_t xMaxToUse = limitValue(roiXmax, ROI_X_MAX);
	uint16_t yMaxToUse = limitValue(roiYmax, ROI_Y_MAX);

	//Limit the minimum values --> limit them to the maximum values. They are never allowed to be bigger then the maximum values.
	uint16_t xMinToUse = limitValue(roiXmin, xMaxToUse);
	uint16_t yMinToUse = limitValue(roiYmin, yMaxToUse);

	//Now fit the values to be valid. This returns also width and height
	uint16_t width = fitValues(xMinToUse, xMaxToUse, ROI_X_MAX, ROI_WIDTH_MIN);
	uint16_t height = fitValues(yMinToUse, yMaxToUse, ROI_Y_MAX, ROI_HEIGHT_MIN);

  //In case of symmetrical ROI (like on EPC660) mirror the y ROI around the y axis
  if (SYMMETRICAL_ROI)
  {
    //Limit to maximum value
    yMinToUse = limitValue(yMinToUse, ROI_Y_SETTING_MAX);

    //Make even
    yMinToUse = makeEven(yMinToUse);

    yMaxToUse = HEIGTH - yMinToUse - 1;

    height = yMaxToUse - yMinToUse + 1;
  }

	//Finally the values can be stored to use
	this->roi[index].xMin = xMinToUse;
	this->roi[index].yMin = yMinToUse;
  this->roi[index].xMax = this->roi[index].xMin + width - 1;
  this->roi[index].yMax = this->roi[index].yMin + height - 1;
}

/**
 * @brief Get current ROI
 *
 * @return Current ROI
 */
Roi RoiSettings::getRoi() const
{
	return roi[index];
}

/**
 * @brief Get ROI of index
 *
 * @paran indexSettings index of the ROI
 * @return ROI of index
 */
Roi RoiSettings::getRoi(const uint32_t indexSettings) const
{
	return roi[indexSettings];
}

/** @} */
