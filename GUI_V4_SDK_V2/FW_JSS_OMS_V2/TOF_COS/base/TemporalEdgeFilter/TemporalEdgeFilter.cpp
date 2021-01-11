/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 *
 * @addtogroup temporal_edge_filter
 *
 * @{
 */
#include "TemporalEdgeFilter.h"
#include "TypePixelCode.h"
#include <stdlib.h>

/**
 * @brief Constructor
 */
TemporalEdgeFilter::TemporalEdgeFilter()
{
	thresholdHigh = 300;
	thresholdLow = 100;
}

/**
 * @brief Set the thresholds
 *
 * @param thresholdLow Lower threshold
 * @param thresholdHigh Higher threshold
 */
void TemporalEdgeFilter::setThreshold(const uint32_t thresholdLow, const uint32_t thresholdHigh)
{
  this->thresholdLow = thresholdLow;
  this->thresholdHigh = thresholdHigh;
}

/**
 * @brief Run the filter
 *
 * @param distance Current distance value
 * @param lastDistance Last distance value
 * @param pixelIndex Index of the current pixel
 */
uint32_t TemporalEdgeFilter::filter(const uint32_t distance, const uint32_t lastDistance, const uint32_t pixelIndex)
{
  uint32_t result = distance;

  int32_t thresholdToUse = thresholdHigh;

  if (lastDistance == TypePixelCode::PIXEL_CODE_INTERFERENCE)
  {
  	thresholdToUse = thresholdLow;
  }

	int32_t diff = distance - lastDistanceBuffer[pixelIndex];

	if (abs(diff) > thresholdToUse)
	{
	  result = TypePixelCode::PIXEL_CODE_INTERFERENCE;
	}

	lastDistanceBuffer[pixelIndex] = distance;

	return result;
}

/**
 * @brief Read if the filter is enabled
 *
 * @retval true Filter is enabled
 * @retval false Filter is disabled
 * @return Filter enabled or disabled
 */
bool TemporalEdgeFilter::isEnabled() const
{
	if ((thresholdLow == 0) || (thresholdHigh == 0))
	{
		return false;
	}

	return true;
}

/** @} */
