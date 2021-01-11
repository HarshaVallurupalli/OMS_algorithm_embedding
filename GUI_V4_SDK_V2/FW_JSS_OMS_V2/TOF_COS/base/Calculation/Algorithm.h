
#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include <MovementDetectionAlgorithm/MovementDetectionAlgorithm.h>
#include <SkeletonDetectionAlgorithm/SkeletonDetectionAlgorithm.h>
#include "CalculationParameters.h"
#include "CalculationResults.h"
#include "IndexHelper/IndexHelper.h"
#include "Pixel/PixelToFDistance.h"
#include "Pixel/PixelToFDistanceAmplitude.h"


//! Algorithm Class
/*!
 * This class is responsible of all the Algorithm
 */
class Algorithm
{
	public:
		Algorithm();

		void setMovementDetectionAlgorithmSettings(const MovementDetectionAlgorithmSettings algorithmSettings);
		MovementDetectionAlgorithmSettings getMovementDetectionAlgorithmSettings() const;
		bool getMovementDetectionAlgorithmEnabled() const;

		void setSkeletonDetectionAlgorithmEnabled(const bool enabled) ;
		bool getSkeletonDetectionAlgorithmEnabled() const;

		void processAlgorithm(PixelToF_Distance *pDistance, const PixelToF_Distance *pLastDistance, const CalculationParameters &parameters, CalculationResults &results);
		void processAlgorithm(PixelToF_DistanceAmplitude *pDistanceAmplitude, const PixelToF_DistanceAmplitude *pLastDistanceAmplitude, const CalculationParameters &parameters, CalculationResults &results);
		void processAlgorithm(PixelToF_DistanceGrayscale *pDistanceGrayscale, const PixelToF_DistanceGrayscale *pLastDistanceGrayscale, const CalculationParameters &parameters, CalculationResults &results);

	private:
		template <typename T> void processAlgorithm(T *pData, const T *pLastData, const CalculationParameters &parameters, CalculationResults &results);
		template <typename T> void runGenericAlgorithm(T *pData, const T *pLastData, const CalculationParameters &parameters, CalculationResults &results);
		template <typename T> void runMovementDetectionAlgorithm(T *pData, const T *pLastData, const CalculationParameters &parameters, CalculationResults &results);
		template <typename T> void runSkeletonDetectionAlgorithm(T *pData, const T *pLastData, const CalculationParameters &parameters, CalculationResults &results);
		template <typename T> void runInterferenceDetection(T *pData, const T *pLastData, const CalculationParameters &parameters, CalculationResults &results);


		void initIndexes(int32_t *pIndexList, const uint32_t width);
		void incIndexes(int32_t *pIndexList);


		uint8_t algorithmSelector;
		MovementDetectionAlgorithm movementDetectionAlgorithm;
		SkeletonDetectionAlgorithm skeletonDetectionAlgorithm;
		bool interferenceUseLastValueEnabled;     ///<If true the last value is used if interference is detected

};

#endif /* FILTER_H_ */

/** @} */
