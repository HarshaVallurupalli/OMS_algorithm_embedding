/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @addtogroup filter
 *
 * @{
 */
#include <Calculation/Filter.h>
#include "MedianFilter/MedianFilter.h"
#include "AverageFilter/AverageFilter.h"


//Masks for the filter enable
const uint8_t MASK_TEMPORAL_FILTER = 0x01;
const uint8_t MASK_AVERAGE_FILTER = 0x02;
const uint8_t MASK_MEDIAN_FILTER = 0x04;
const uint8_t MASK_EDGE_FILTER = 0x08;
const uint8_t MASK_TEMPORAL_EDGE_FILTER = 0x10;

///Helper enum to call the filter functions
enum
{
	NO_FILTER,
	TEMPORAL_FILTER = MASK_TEMPORAL_FILTER,
	AVERAGE_FILTER = MASK_AVERAGE_FILTER,
	MEDIAN_FILTER = MASK_MEDIAN_FILTER,
	EDGE_FILTER = MASK_EDGE_FILTER,
	AVERAGE_TEMPORAL_FILTER = (MASK_TEMPORAL_FILTER | MASK_AVERAGE_FILTER),
	MEDIAN_TEMPORAL_FILTER = (MASK_TEMPORAL_FILTER | MASK_MEDIAN_FILTER),
	TEMPORAL_EDGE_FILTER = (MASK_TEMPORAL_FILTER | MASK_EDGE_FILTER),
	MEDIAN_TEMPORAL_EDGE_FILTER = (MASK_MEDIAN_FILTER | MASK_TEMPORAL_FILTER | MASK_EDGE_FILTER),
	AVERAGE_TEMPORAL_EDGE_FILTER = (MASK_AVERAGE_FILTER | MASK_TEMPORAL_FILTER | MASK_EDGE_FILTER)
};

Filter::Filter()
{
	filterSelector = MASK_EDGE_FILTER;
	interferenceUseLastValueEnabled = false;
}

/**
 * @brief Set the temporal filter settings for the distance
 *
 * @param filterSettings Temporal filter settings class
 */
void Filter::setTemporalFilterSettings(const TemporalFilterSettings filterSettings)
{
	temporalFilter.setSettings(filterSettings);
}

/**
 * @brief Get the temporal filter settings for the distance
 *
 * @return filterSettings Temporal filter settings class
 */
TemporalFilterSettings Filter::getTemporalFilterSettings() const
{
  return temporalFilter.getSettings();
}

/**
 * @brief Get temporal filter enabled
 *
 * @retval true Temporal filter enabled
 * @retval false Temporal filter disabled
 * @return Temporal filter enabled/disabled
 */
bool Filter::getTemporalFilterEnabled() const
{
  return temporalFilter.isEnabled();
}

/**
 * @brief Enable/disable the average filter
 *
 * @param enabled Average filter enabled or disabled
 */
void Filter::setAverageFilterEnabled(const bool enabled)
{
	if (enabled)
	{
	  filterSelector |= MASK_AVERAGE_FILTER;
	}
	else
	{
		filterSelector &= ~MASK_AVERAGE_FILTER;
	}
}

/**
 * @brief Get average filter enabled
 *
 * @retval true Average filter enabled
 * @retval false Average filter disabled
 * @return Average filter enabled/disabled
 */
bool Filter::getAverageFilterEnabled() const
{
	return (filterSelector & MASK_AVERAGE_FILTER);
}

/**
 * @brief Enable/disable the median filter
 *
 * @param enabled Median filter enabled or disabled
 */
void Filter::setMedianFilterEnabled(const bool enabled)
{
	if (enabled)
	{
	  filterSelector |= MASK_MEDIAN_FILTER;
	}
  else
	{
	  filterSelector &= ~MASK_MEDIAN_FILTER;
	}
}

/**
 * @brief Get median filter enabled
 *
 * @retval true Median filter enabled
 * @retval false Median filter disabled
 * @return Median filter enabled/disabled
 */
bool Filter::getMedianFilterEnabled() const
{
	return (filterSelector & MASK_MEDIAN_FILTER);
}

/**
 * @brief Get edge filter enabled
 *
 * @retval true Edge filter enabled
 * @retval false Edge filter disabled
 * @return Edge filter enabled/disabled
 */
bool Filter::getEdgeFilterEnabled() const
{
  return (filterSelector & MASK_EDGE_FILTER);
}

/**
 * @brief Set edge filter settings
 *
 * If the threshold is zero, the edge filter is disabled. If the threshold is higher
 * than zero, the edge filter is enabled and the threshold is used as threshold for edge detection.
 *
 * @param threshold Threshold for the edge filter in mm, zero for edge filter disabled
 */
void Filter::setEdgeFilterSettings(const uint32_t threshold)
{
	edgeFilter.setThreshold(threshold);

	bool edgeFilterEnabled = edgeFilter.isEnabled();
	if (edgeFilterEnabled)
	{
	  filterSelector |= MASK_EDGE_FILTER;
	}
	else
	{
	  filterSelector &= ~MASK_EDGE_FILTER;
	}
}

/**
 * @brief Set interference use last value flag
 *
 * If this flag is set, the last valid distance value is used in case of a detected interference
 *
 * @param enabled Use last value true/false
 */
void Filter::setInterferenceUseLastValueEnabled(const bool enabled)
{
	interferenceUseLastValueEnabled = enabled;
}

/**
 * @brief Set threshold for temporal edge filter
 *
 * @param enabled Use last value true/false
 */
void Filter::setTemporalEdgeFilterThreshold(const uint32_t thresholdLow, const uint32_t thresholdHigh)
{
  temporalEdgeFilter.setThreshold(thresholdLow, thresholdHigh);
}

/**
 * @brief Public filter function for distance
 *
 * @param pData Pointer to the current data
 * @param pLastData Pointer to the last data
 * @param parameters Reference to the parameters class containing all needed parameters for the calculation
 * @param results Reference to the results class containing all needed values for the results
 */
void Filter::processFilter(PixelToF_Distance *pDistance, const PixelToF_Distance *pLastDistance, const CalculationParameters &parameters, CalculationResults &results)
{
	processFilter<PixelToF_Distance>(pDistance, pLastDistance, parameters, results);
}

/**
 * @brief Public filter function for distance and amplitude
 *
 * @param pData Pointer to the current data
 * @param pLastData Pointer to the last data
 * @param parameters Reference to the parameters class containing all needed parameters for the calculation
 * @param results Reference to the results class containing all needed values for the results
 */
void Filter::processFilter(PixelToF_DistanceAmplitude *pDistanceAmplitude, const PixelToF_DistanceAmplitude *pLastDistanceAmplitude, const CalculationParameters &parameters, CalculationResults &results)
{
	processFilter<PixelToF_DistanceAmplitude>(pDistanceAmplitude, pLastDistanceAmplitude, parameters, results);
}

/**
 * @brief Public filter function for distance and grayscale
 *
 * @param pData Pointer to the current data
 * @param pLastData Pointer to the last data
 * @param parameters Reference to the parameters class containing all needed parameters for the calculation
 * @param results Reference to the results class containing all needed values for the results
 */
void Filter::processFilter(PixelToF_DistanceGrayscale *pDistanceGrayscale, const PixelToF_DistanceGrayscale *pLastDistanceGrayscale, const CalculationParameters &parameters, CalculationResults &results)
{
	processFilter<PixelToF_DistanceGrayscale>(pDistanceGrayscale, pLastDistanceGrayscale, parameters, results);
}

void Filter::setTemporalFilterEnabled(const bool eanbled)
{
	if (eanbled)
	{
		filterSelector |= MASK_TEMPORAL_FILTER;
	}
	else
	{
	  filterSelector &= ~MASK_TEMPORAL_FILTER;
	}
}

void Filter::setTemporalEdgeFilterEnabled(const bool enabled)
{
	if (enabled)
	{
	  filterSelector |= MASK_TEMPORAL_EDGE_FILTER;
	}
	else
	{
	  filterSelector &= ~MASK_TEMPORAL_EDGE_FILTER;
	}
}

/**
 * @brief Process filter internal
 *
 * This function checks, which kind of filter is enabled and calls the corresponding function. For all important filter combination
 * there exists an own function.
 *
 * Important: These many functions help to increase the performance because the if statements during the loop through the pixels
 * can be reduced. This makes a significant performance boost but leads to some functions that are very similar to each other.
 * Here it is implemented like this because the performance is more important than the reduction of code repetition.
 *
 * @param pData Pointer to the current data
 * @param pLastData Pointer to the last data
 * @param parameters Reference to the parameters class containing all needed parameters for the calculation
 * @param results Reference to the results class containing all needed values for the results
 */
template <typename T> void Filter::processFilter
(
  T *pData,
	const T *pLastData,
	const CalculationParameters &parameters,
	CalculationResults &results
)
{
	//The temporal filter setting is stored in the temporal filter itself. In addition the temporal filter is sometimes not possible, e.g. if last data is not available
	bool temporalFilterEnabled = temporalFilter.isEnabled() && (!parameters.overrideFilter);
	setTemporalFilterEnabled(temporalFilterEnabled);

	bool temporalEdgeFilterEnabled = temporalEdgeFilter.isEnabled() && (!parameters.overrideFilter);
	setTemporalEdgeFilterEnabled(temporalEdgeFilterEnabled);

	//Now depending on the filter flags call the needed function
	switch(filterSelector)
	{
	  case NO_FILTER:
      if (interferenceUseLastValueEnabled)
      {
      	runInterferenceDetection(pData, pLastData, parameters, results);
      }
		  break;
	  case TEMPORAL_FILTER:
	  	runTemporalFilter(pData, pLastData, parameters, results);
		  break;
	  case AVERAGE_FILTER:
      runAverageFilter(pData, pLastData, parameters, results);
	  	break;
	  case MEDIAN_FILTER:
	  	runMedianFilter(pData, pLastData, parameters, results);
	  	break;
	  case EDGE_FILTER:
      runEdgeFilter(pData, pLastData, parameters, results);
	  	break;
	  case AVERAGE_TEMPORAL_FILTER:
      runAverageTemporalFilter(pData, pLastData, parameters, results);
	  	break;
	  case MEDIAN_TEMPORAL_FILTER:
	  	runMedianTemporalFilter(pData, pLastData, parameters, results);
	  	break;
	  case TEMPORAL_EDGE_FILTER:
	  	runTemporalEdgeFilter(pData, pLastData, parameters, results);
	  	break;
	  case MEDIAN_TEMPORAL_EDGE_FILTER:
      runMedianTemporalEdgeFilter(pData, pLastData, parameters, results);
	  	break;
	  case AVERAGE_TEMPORAL_EDGE_FILTER:
      runAverageTemporalEdgeFilter(pData, pLastData, parameters, results);
	  	break;
	  default:
	  	runGenericFilter(pData, pLastData, parameters, results);
	  	break;
	}
}

/**
 * @brief Temporal filter
 *
 * This function is called, if the temporal filter only is enabled.
 *
 * @param pData Pointer to the current data
 * @param pLastData Pointer to the last data
 * @param parameters Reference to the parameters class containing all needed parameters for the calculation
 * @param results Reference to the results class containing all needed values for the results
 */
template <typename T> void Filter::runTemporalFilter(T *pData, const T *pLastData, const CalculationParameters &parameters, CalculationResults &results)
{
	uint32_t numPixel = parameters.acquisitionInfo.getNumPixel();
  int32_t minDistance = 100000;

  for (uint32_t i = 0; i < numPixel; i++)
	{
	  uint32_t distance = pData[i].getDistance();
	  uint32_t lastDistance = pLastData[i].getDistance();

	  if (distance < TypePixelCode::PIXEL_CODE_LIMIT_FOR_VALID_DATA)
		{
	    distance = temporalFilter.filter(distance, lastDistance);
			pData[i].setDistance(distance);
		}
		else if (distance == TypePixelCode::PIXEL_CODE_INTERFERENCE)
		{
			if ((interferenceUseLastValueEnabled) && (pLastData[i].isInvalid() == false))
			{
			  pData[i] = pLastData[i];
			}
	  }

	  if (distance < minDistance)
	  {
	    minDistance = distance;
	  }
	}
  results.minDistance = minDistance;
}

/**
 * @brief Average filter
 *
 * This function is called, if the average filter only is enabled.
 *
 * @param pData Pointer to the current data
 * @param pLastData Pointer to the last data
 * @param parameters Reference to the parameters class containing all needed parameters for the calculation
 * @param results Reference to the results class containing all needed values for the results
 */
template <typename T> void Filter::runAverageFilter(T *pData, const T *pLastData, const CalculationParameters &parameters, CalculationResults &results)
{
	uint16_t width = parameters.acquisitionInfo.getWidth();
	uint16_t height = parameters.acquisitionInfo.getFinalHeight();
	int32_t minDistance = 100000;
	int32_t indexList[9];

	initIndexes(indexList, width);
	uint32_t index = 0;
  for (uint16_t y = 0; y < height; y++)
  {
	  for (uint16_t x = 0; x < width; x++)
		{
		  int32_t distance = pData[index].getDistance();

		  if (distance < TypePixelCode::PIXEL_CODE_LIMIT_FOR_VALID_DATA)
		  {
			  distance = AverageFilter::calcFilteredValue<T>(distance, pData, indexList, x, y, width, height);

			  pData[index].setDistance(distance);
		  }
			else if (distance == TypePixelCode::PIXEL_CODE_INTERFERENCE)
			{
				if ((interferenceUseLastValueEnabled) && (pLastData[index].isInvalid() == false))
				{
					pData[index] = pLastData[index];
				}
			}

		  if (distance < minDistance)
			{
				minDistance = distance;
			}

		  incIndexes(indexList);
		  index++;
	  }
  }

	results.minDistance = minDistance;
}

/**
 * @brief Median filter
 *
 * This function is called, if the median filter only is enabled.
 *
 * @param pData Pointer to the current data
 * @param pLastData Pointer to the last data
 * @param parameters Reference to the parameters class containing all needed parameters for the calculation
 * @param results Reference to the results class containing all needed values for the results
 */
template <typename T> void Filter::runMedianFilter(T *pData, const T *pLastData, const CalculationParameters &parameters, CalculationResults &results)
{
	uint16_t width = parameters.acquisitionInfo.getWidth();
	uint16_t height = parameters.acquisitionInfo.getFinalHeight();
	int32_t minDistance = 100000;
	int32_t indexList[9];

	initIndexes(indexList, width);
	uint32_t index = 0;
  for (uint16_t y = 0; y < height; y++)
  {
	  for (uint16_t x = 0; x < width; x++)
		{
		  uint32_t distance = pData[index].getDistance();

		  if (distance < TypePixelCode::PIXEL_CODE_LIMIT_FOR_VALID_DATA)
		  {
			  distance = MedianFilter::calcFilteredValue<T>(distance, pData, indexList, x, y, width, height);

			  pData[index].setDistance(distance);
		  }
			else if (distance == TypePixelCode::PIXEL_CODE_INTERFERENCE)
			{
				if ((interferenceUseLastValueEnabled) && (pLastData[index].isInvalid() == false))
				{
					pData[index] = pLastData[index];
				}
			}

		  if (distance < minDistance)
			{
				minDistance = distance;
			}

		  incIndexes(indexList);
		  index++;
	  }
  }

	results.minDistance = minDistance;
}

/**
 * @brief Edge filter
 *
 * This function is called if the edge filter only is enabled
 *
 * @param pData Pointer to the current data
 * @param pLastData Pointer to the last data
 * @param parameters Reference to the parameters class containing all needed parameters for the calculation
 * @param results Reference to the results class containing all needed values for the results
 */
template <typename T> void Filter::runEdgeFilter(T *pData, const T *pLastData, const CalculationParameters &parameters, CalculationResults &results)
{
	uint16_t width = parameters.acquisitionInfo.getWidth();
	uint16_t height = parameters.acquisitionInfo.getFinalHeight();
	int32_t minDistance = 100000;
	int32_t indexList[9];

	edgeFilter.startFilter(parameters.acquisitionInfo.getWidth(), parameters.acquisitionInfo.getHeight());
	uint32_t index = 0;
	initIndexes(indexList, width);

	for (uint16_t y = 0; y < height; y++)
  {
	  for (uint16_t x = 0; x < width; x++)
		{
		  uint32_t distance = pData[index].getDistance();

		  if (distance < TypePixelCode::PIXEL_CODE_LIMIT_FOR_VALID_DATA)
		  {
		  	distance = edgeFilter.calcFilteredValue(distance, pData, indexList, x, y);

			  pData[index].setDistance(distance);
		  }
		  else if (distance == TypePixelCode::PIXEL_CODE_INTERFERENCE)
			{
				if ((interferenceUseLastValueEnabled) && (pLastData[index].isInvalid() == false))
				{
					pData[index] = pLastData[index];
				}
			}

		  if (distance < minDistance)
			{
				minDistance = distance;
			}

		  incIndexes(indexList);
		  index++;
	  }
  }

	results.minDistance = minDistance;
}

/**
 * @brief Temporal and average filter
 *
 * This function is called, if the temporal and average filter are enabled.
 *
 * @param pData Pointer to the current data
 * @param pLastData Pointer to the last data
 * @param parameters Reference to the parameters class containing all needed parameters for the calculation
 * @param results Reference to the results class containing all needed values for the results
 */
template <typename T> void Filter::runAverageTemporalFilter(T *pData, const T *pLastData, const CalculationParameters &parameters, CalculationResults &results)
{
	uint16_t width = parameters.acquisitionInfo.getWidth();
	uint16_t height = parameters.acquisitionInfo.getFinalHeight();
	int32_t minDistance = 100000;
	int32_t indexList[9];

	edgeFilter.startFilter(parameters.acquisitionInfo.getWidth(), parameters.acquisitionInfo.getHeight());
	uint32_t index = 0;
	initIndexes(indexList, width);

	for (uint16_t y = 0; y < height; y++)
  {
	  for (uint16_t x = 0; x < width; x++)
		{
		  uint32_t distance = pData[index].getDistance();

		  if (distance < TypePixelCode::PIXEL_CODE_LIMIT_FOR_VALID_DATA)
		  {
		  	distance = AverageFilter::calcFilteredValue<T>(distance, pData, indexList, x, y, width, height);

		  	uint32_t lastDistance = pLastData[index].getDistance();
		  	distance = temporalFilter.filter(distance, lastDistance);

			  pData[index].setDistance(distance);
		  }
		  else if (distance == TypePixelCode::PIXEL_CODE_INTERFERENCE)
			{
				if ((interferenceUseLastValueEnabled) && (pLastData[index].isInvalid() == false))
				{
					pData[index] = pLastData[index];
				}
			}

		  if (distance < minDistance)
			{
				minDistance = distance;
			}

		  incIndexes(indexList);
		  index++;
	  }
  }

	results.minDistance = minDistance;
}

/**
 * @brief Temporal and median filter
 *
 * This function is called, if the temporal and median filter are enabled.
 *
 * @param pData Pointer to the current data
 * @param pLastData Pointer to the last data
 * @param parameters Reference to the parameters class containing all needed parameters for the calculation
 * @param results Reference to the results class containing all needed values for the results
 */
template <typename T> void Filter::runMedianTemporalFilter(T *pData, const T *pLastData, const CalculationParameters &parameters, CalculationResults &results)
{
	uint16_t width = parameters.acquisitionInfo.getWidth();
	uint16_t height = parameters.acquisitionInfo.getFinalHeight();
	int32_t minDistance = 100000;
	int32_t indexList[9];

	edgeFilter.startFilter(parameters.acquisitionInfo.getWidth(), parameters.acquisitionInfo.getHeight());
	uint32_t index = 0;
	initIndexes(indexList, width);

	for (uint16_t y = 0; y < height; y++)
  {
	  for (uint16_t x = 0; x < width; x++)
		{
		  int32_t distance = pData[index].getDistance();

		  if (distance < TypePixelCode::PIXEL_CODE_LIMIT_FOR_VALID_DATA)
		  {
		  	distance = MedianFilter::calcFilteredValue<T>(distance, pData, indexList, x, y, width, height);

		  	uint32_t lastDistance = pLastData[index].getDistance();
		  	distance = temporalFilter.filter(distance, lastDistance);

			  pData[index].setDistance(distance);
		  }
		  else if (distance == TypePixelCode::PIXEL_CODE_INTERFERENCE)
			{
				if ((interferenceUseLastValueEnabled) && (pLastData[index].isInvalid() == false))
				{
					pData[index] = pLastData[index];
				}
			}

		  if (distance < minDistance)
			{
				minDistance = distance;
			}

		  incIndexes(indexList);
		  index++;
	  }
  }

	results.minDistance = minDistance;
}

/**
 * @brief Temporal and edge filter
 *
 * This function is called if the temporal and edge filter only are enabled.
 *
 * @param pData Pointer to the current data
 * @param pLastData Pointer to the last data
 * @param parameters Reference to the parameters class containing all needed parameters for the calculation
 * @param results Reference to the results class containing all needed values for the results
 */
template <typename T> void Filter::runTemporalEdgeFilter(T *pData, const T *pLastData, const CalculationParameters &parameters, CalculationResults &results)
{
	uint16_t width = parameters.acquisitionInfo.getWidth();
	uint16_t height = parameters.acquisitionInfo.getFinalHeight();
	int32_t minDistance = 100000;
	int32_t indexList[9];

	edgeFilter.startFilter(parameters.acquisitionInfo.getWidth(), parameters.acquisitionInfo.getHeight());
	uint32_t index = 0;
	initIndexes(indexList, width);

	for (uint16_t y = 0; y < height; y++)
  {
	  for (uint16_t x = 0; x < width; x++)
		{
		  uint32_t distance = pData[index].getDistance();

		  if (distance < TypePixelCode::PIXEL_CODE_LIMIT_FOR_VALID_DATA)
		  {
		  	uint32_t lastDistance = pLastData[index].getDistance();
		  	distance = temporalFilter.filter(distance, lastDistance);

		  	distance = edgeFilter.calcFilteredValue(distance, pData, indexList, x, y);

			  pData[index].setDistance(distance);
		  }
		  else if (distance == TypePixelCode::PIXEL_CODE_INTERFERENCE)
			{
				if ((interferenceUseLastValueEnabled) && (pLastData[index].isInvalid() == false))
				{
					pData[index] = pLastData[index];
				}
			}

		  if (distance < minDistance)
			{
				minDistance = distance;
			}

		  incIndexes(indexList);
		  index++;
	  }
  }

	results.minDistance = minDistance;
}

/**
 * @brief Median, temporal, edge filter
 *
 * This function is called if the following filters are enabled:
 * - median filter
 * - temporal filter
 * - edge filter
 *
 * @param pData Pointer to the current data
 * @param pLastData Pointer to the last data
 * @param parameters Reference to the parameters class containing all needed parameters for the calculation
 * @param results Reference to the results class containing all needed values for the results
 */
template <typename T> void Filter::runMedianTemporalEdgeFilter(T *pData, const T *pLastData, const CalculationParameters &parameters, CalculationResults &results)
{
	uint16_t width = parameters.acquisitionInfo.getWidth();
	uint16_t height = parameters.acquisitionInfo.getFinalHeight();
	int32_t minDistance = 100000;
	int32_t indexList[9];

	edgeFilter.startFilter(parameters.acquisitionInfo.getWidth(), parameters.acquisitionInfo.getHeight());
	uint32_t index = 0;
	initIndexes(indexList, width);

	for (uint16_t y = 0; y < height; y++)
  {
	  for (uint16_t x = 0; x < width; x++)
		{
		  uint32_t distance = pData[index].getDistance();

		  if (distance < TypePixelCode::PIXEL_CODE_LIMIT_FOR_VALID_DATA)
		  {
		  	distance = MedianFilter::calcFilteredValue<T>(distance, pData, indexList, x, y, width, height);

		  	uint32_t lastDistance = pLastData[index].getDistance();
		    distance = temporalFilter.filter(distance, lastDistance);

			  distance = edgeFilter.calcFilteredValue(distance, pData, indexList, x, y);

			  pData[index].setDistance(distance);
		  }
			else if (distance == TypePixelCode::PIXEL_CODE_INTERFERENCE)
			{
				if ((interferenceUseLastValueEnabled) && (pLastData[index].isInvalid() == false))
				{
					pData[index] = pLastData[index];
				}
			}

		  if (distance < minDistance)
			{
				minDistance = distance;
			}

		  incIndexes(indexList);
		  index++;
	  }
  }

	results.minDistance = minDistance;
}

/**
 * @brief Average, temporal, edge filter
 *
 * This function is called if the following filters are enabled:
 * - average filter
 * - temporal filter
 * - edge filter
 *
 * @param pData Pointer to the current data
 * @param pLastData Pointer to the last data
 * @param parameters Reference to the parameters class containing all needed parameters for the calculation
 * @param results Reference to the results class containing all needed values for the results
 */
template <typename T> void Filter::runAverageTemporalEdgeFilter(T *pData, const T *pLastData, const CalculationParameters &parameters, CalculationResults &results)
{
	uint16_t width = parameters.acquisitionInfo.getWidth();
	uint16_t height = parameters.acquisitionInfo.getFinalHeight();
	int32_t minDistance = 100000;
	int32_t indexList[9];

	edgeFilter.startFilter(parameters.acquisitionInfo.getWidth(), parameters.acquisitionInfo.getHeight());
	uint32_t index = 0;
	initIndexes(indexList, width);

  for (uint16_t y = 0; y < height; y++)
  {
	  for (uint16_t x = 0; x < width; x++)
		{
		  uint32_t distance = pData[index].getDistance();

		  if (distance < TypePixelCode::PIXEL_CODE_LIMIT_FOR_VALID_DATA)
		  {
		  	distance = AverageFilter::calcFilteredValue<T>(distance, pData, indexList, x, y, width, height);

		  	uint32_t lastDistance = pLastData[index].getDistance();
		    distance = temporalFilter.filter(distance, lastDistance);

			  distance = edgeFilter.calcFilteredValue(distance, pData, indexList, x, y);

			  pData[index].setDistance(distance);
		  }
		  else if (distance == TypePixelCode::PIXEL_CODE_INTERFERENCE)
			{
				if ((interferenceUseLastValueEnabled) && (pLastData[index].isInvalid() == false))
				{
					pData[index] = pLastData[index];
				}
			}

		  if (distance < minDistance)
		  {
		    minDistance = distance;
		  }

		  incIndexes(indexList);
		  index++;
	  }
  }

	results.minDistance = minDistance;
}

/**
 * @brief Generic filter
 *
 * This function is the fallback function. It checks for every filter, if it should be applied. This is slow, but works for all filters.
 *
 * @param pData Pointer to the current data
 * @param pLastData Pointer to the last data
 * @param parameters Reference to the parameters class containing all needed parameters for the calculation
 * @param results Reference to the results class containing all needed values for the results
 */
template <typename T> void Filter::runGenericFilter(T *pData, const T *pLastData, const CalculationParameters &parameters, CalculationResults &results)
{
	uint16_t width = parameters.acquisitionInfo.getWidth();
	uint16_t height = parameters.acquisitionInfo.getFinalHeight();
	int32_t minDistance = 100000;
	int32_t indexList[9];


  edgeFilter.startFilter(parameters.acquisitionInfo.getWidth(), parameters.acquisitionInfo.getHeight());
	uint32_t index = 0;
	initIndexes(indexList, width);

  for (uint16_t y = 0; y < height; y++)
  {
  	for (uint16_t x = 0; x < width; x++)
		{
  		uint32_t distance = pData[index].getDistance();
  		uint32_t lastDistance = pLastData[index].getDistance();

/*  		if (distance < TypePixelCode::PIXEL_CODE_LIMIT_FOR_VALID_DATA)
  		{
  		  distance = temporalEdgeFilter.filter(distance, lastDistance, index);
  			pData[index].setDistance(distance);
  		}*/

  		//Check again because the temporal edge filter may remove the pixel
  		if (distance < TypePixelCode::PIXEL_CODE_LIMIT_FOR_VALID_DATA)
  		{
  			if (filterSelector & MASK_MEDIAN_FILTER)
  		  {
  			  distance = MedianFilter::calcFilteredValue<T>(distance, pData, indexList, x, y, width, height);
  			}

  		  if (filterSelector & MASK_AVERAGE_FILTER)
			  {
          distance = AverageFilter::calcFilteredValue<T>(distance, pData, indexList, x, y, width, height);
			  }

  		  if (filterSelector & MASK_TEMPORAL_FILTER)
  		  {
  		    distance = temporalFilter.filter(distance, lastDistance);
  		  }

  		  if (filterSelector & MASK_EDGE_FILTER)
  		  {
  		    distance = edgeFilter.calcFilteredValue(distance, pData, indexList, x, y);
  		  }

			  pData[index].setDistance(distance);
		  }
  		else if (distance == TypePixelCode::PIXEL_CODE_INTERFERENCE)
  		{
  		  if ((interferenceUseLastValueEnabled) && (pLastData[index].isInvalid() == false))
  		  {
  			  pData[index] = pLastData[index];
  			}
  		}

  		if (distance < minDistance)
  		{
  		  minDistance = distance;
  		}

		  incIndexes(indexList);

		  index++;
	  }
  }

	results.minDistance = minDistance;
}

/**
 * @brief Generic filter
 *
 * This function is the fallback function. It checks for every filter, if it should be applied. This is slow, but works for all filters.
 *
 * @param pData Pointer to the current data
 * @param pLastData Pointer to the last data
 * @param parameters Reference to the parameters class containing all needed parameters for the calculation
 * @param results Reference to the results class containing all needed values for the results
 */
template <typename T> void Filter::runInterferenceDetection(T *pData, const T *pLastData, const CalculationParameters &parameters, CalculationResults &results)
{
	uint16_t width = parameters.acquisitionInfo.getWidth();
	uint16_t height = parameters.acquisitionInfo.getFinalHeight();
	int32_t minDistance = 100000;


  uint32_t index = 0;

  for (uint16_t y = 0; y < height; y++)
  {
  	for (uint16_t x = 0; x < width; x++)
		{
  		uint32_t distance = pData[index].getDistance();

  		if (distance == TypePixelCode::PIXEL_CODE_INTERFERENCE)
  		{
  		  if (pLastData[index].isInvalid() == false)
  		  {
  			  pData[index] = pLastData[index];
  			}
  		}

  		if (distance < minDistance)
  		{
  		  minDistance = distance;
  		}

		  index++;
	  }
  }

	results.minDistance = minDistance;
}

/**
 * @brief Create an index list for all filters.
 *
 *
 * The index list is like this:
 *     |0|1|2|
 *     |3|4|5|
 *     |6|7|8|
 *
 * It contains the indexes for 9 Pixels. The current pixel is the middle one (number 4)
 * - Median filter uses all of them
 * - Average filter uses 4, 5, 7, 8
 * - Edge filter uses 4, 5, 7
 *
 * On the rows/columns at the border of the image not all filters are possible, e.g. at pixel 0 values 0, 1, 2, 3, 6 are not available.
 * It's the responsibility of the filter function to handle these situations. Here just the indexes are filled and in such situations they
 * can get negative.
 *
 * The purpose of this is to reuse the indexes for all filters.
 *
 * @param pIndexList Pointer to the index list array, always 9 elements
 * @param width Width of the image
 */
void Filter::initIndexes(int32_t *pIndexList, const uint32_t width)
{
	pIndexList[0] = -(width) - 1;
	pIndexList[1] = -(width);
	pIndexList[2] = -(width) + 1;
	pIndexList[3] = -1;
	pIndexList[4] = 0;
	pIndexList[5] = 1;
	pIndexList[6] = width - 1;
	pIndexList[7] = width;
	pIndexList[8] = width + 1;
}

/**
 * @brief Increment all indexes
 *
 * To be called after every filter loop. Increments each of the indexes in the index list.
 *
 * @param pIndexList Pointer to the index list array, always 9 elements
 */
void Filter::incIndexes(int32_t *pIndexList)
{
  for (uint8_t i = 0; i < 9; i++)
	{
  	pIndexList[i]++;
	}
}



/** @} */
