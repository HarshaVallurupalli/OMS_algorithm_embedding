/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup filter Filter
 * @brief Filter Class
 * @ingroup calculation
 *
 * @{
 */
#ifndef FILTER_H_
#define FILTER_H_

#include "CalculationParameters.h"
#include "CalculationResults.h"
#include "IndexHelper/IndexHelper.h"
#include "TemporalFilter/TemporalFilter.h"
#include "TemporalEdgeFilter/TemporalEdgeFilter.h"
#include "EdgeFilter/EdgeFilter.h"
#include "Pixel/PixelToFDistance.h"
#include "Pixel/PixelToFDistanceAmplitude.h"


//! Filter Class
/*!
 * This class is responsible of all the filters. These are temporal and spatial filters.
 */
class Filter
{
	public:
		Filter();
		void setTemporalFilterSettings(const TemporalFilterSettings filterSettings);
		TemporalFilterSettings getTemporalFilterSettings() const;
		bool getTemporalFilterEnabled() const;
		void setAverageFilterEnabled(const bool enabled);
		bool getAverageFilterEnabled() const;
		void setMedianFilterEnabled(const bool enabled);
		bool getMedianFilterEnabled() const;
		void setEdgeFilterSettings(const uint32_t threshold);
		bool getEdgeFilterEnabled() const;
		void setInterferenceUseLastValueEnabled(const bool enabled);
		void setTemporalEdgeFilterThreshold(const uint32_t thresholdLow, const uint32_t thresholdHigh);
		void processFilter(PixelToF_Distance *pDistance, const PixelToF_Distance *pLastDistance, const CalculationParameters &parameters, CalculationResults &results);
		void processFilter(PixelToF_DistanceAmplitude *pDistanceAmplitude, const PixelToF_DistanceAmplitude *pLastDistanceAmplitude, const CalculationParameters &parameters, CalculationResults &results);
		void processFilter(PixelToF_DistanceGrayscale *pDistanceGrayscale, const PixelToF_DistanceGrayscale *pLastDistanceGrayscale, const CalculationParameters &parameters, CalculationResults &results);

	private:
		template <typename T> void processFilter(T *pData, const T *pLastData, const CalculationParameters &parameters, CalculationResults &results);
		template <typename T> void runTemporalFilter(T *pData, const T *pLastData, const CalculationParameters &parameters, CalculationResults &results);
		template <typename T> void runAverageFilter(T *pData, const T *pLastData, const CalculationParameters &parameters, CalculationResults &results);
		template <typename T> void runMedianFilter(T *pData, const T *pLastData, const CalculationParameters &parameters, CalculationResults &results);
		template <typename T> void runEdgeFilter(T *pData, const T *pLastData, const CalculationParameters &parameters, CalculationResults &results);
		template <typename T> void runAverageTemporalFilter(T *pData, const T *pLastData, const CalculationParameters &parameters, CalculationResults &results);
		template <typename T> void runMedianTemporalFilter(T *pData, const T *pLastData, const CalculationParameters &parameters, CalculationResults &results);
		template <typename T> void runTemporalEdgeFilter(T *pData, const T *pLastData, const CalculationParameters &parameters, CalculationResults &results);
		template <typename T> void runMedianTemporalEdgeFilter(T *pData, const T *pLastData, const CalculationParameters &parameters, CalculationResults &results);
		template <typename T> void runAverageTemporalEdgeFilter(T *pData, const T *pLastData, const CalculationParameters &parameters, CalculationResults &results);
		template <typename T> void runGenericFilter(T *pData, const T *pLastData, const CalculationParameters &parameters, CalculationResults &results);
		template <typename T> void runInterferenceDetection(T *pData, const T *pLastData, const CalculationParameters &parameters, CalculationResults &results);

		void initIndexes(int32_t *pIndexList, const uint32_t width);
		void incIndexes(int32_t *pIndexList);
		void setTemporalFilterEnabled(const bool eanbled);
		void setTemporalEdgeFilterEnabled(const bool enabled);

		TemporalFilter temporalFilter;            ///<Temporal filter instance
		TemporalEdgeFilter temporalEdgeFilter;    ///<Temporal Edge filter
		EdgeFilter edgeFilter;                    ///<Edge filter instance
		uint8_t filterSelector;                  ///<Variable containing filter flags
		bool interferenceUseLastValueEnabled;     ///<If true the last value is used if interference is detected
};

#endif /* FILTER_H_ */

/** @} */
