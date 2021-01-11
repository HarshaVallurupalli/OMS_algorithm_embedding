/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup calculation Calculation
 * @ingroup tof_cos
 * @brief Offers calculation functions to calculate distance, amplitude, ...
 */
#ifndef CALCULATION_H_
#define CALCULATION_H_

#include <Calibration/DrnuCalibrationTypes.h>
#include "Calculation/Calculation.h"
#include "Config/Config.h"
#include "Calculation/CalculationParameters.h"
#include "Calculation/CalculationResults.h"
#include "Filter.h"
#include "Algorithm.h"
#include "Hysteresis/Hysteresis.h"
#include "TemporalFilter/TemporalFilterSettings.h"
#include "MovementDetectionAlgorithm/MovementDetectionAlgorithmSettings.h"
#include "InterferenceDetection/InterferenceDetectionSettings.h"
#include "GrayscaleCompensation/GrayscaleCompensation.h"


class Calculation
{
	public:
		Calculation();

		void init();

		void distAmpSingleIntegrationTime(uint32_t *data, const uint8_t *lastResult, uint8_t *result,  CalculationParameters &parameters, CalculationResults &results);
		void distAmpDualIntegrationTime(uint32_t *data0, uint32_t *data1, const uint8_t *lastResult, uint8_t *result, CalculationParameters &parameters, CalculationResults &results);

		void distSingleIntegrationTime(uint32_t *data, const uint8_t *lastResult, uint8_t *result, CalculationParameters &parameters, CalculationResults &results);
		void distDualIntegrationTime(uint32_t *data0, uint32_t *data1, const uint8_t *lastResult, uint8_t *result, CalculationParameters &parameters, CalculationResults &results);

		void grayscale(uint32_t *inputData, uint16_t *grayscaleData, const uint32_t numPixel);

		void rawDcsSorted(const uint32_t *pDcs, uint8_t *pDcsSorted, const CalculationParameters &parameters, CalculationResults &results);

		void processFilterOnDistanceAmplitude      (uint8_t *pDistanceAmplitude, const uint8_t *pLastDistanceAmplitude, const CalculationParameters &parameters, CalculationResults &results);
		void processFilterOnDistance               (uint8_t *pDistance, const uint8_t *pLastDistance, const CalculationParameters &parameters, CalculationResults &results);

		//Algorithm Edit
		void processAlgorithmOnDistanceAmplitude      (uint8_t *pDistanceAmplitude, const uint8_t *pLastDistanceAmplitude, const CalculationParameters &parameters, CalculationResults &results);
		void processAlgorithmOnDistance               (uint8_t *pDistance, const uint8_t *pLastDistance, const CalculationParameters &parameters, CalculationResults &results);

	 /********************************************
		*Filter / interference detection functions
		*********************************************/
		void setTemporalFilterSettings(const TemporalFilterSettings filterSettings);
		TemporalFilterSettings getTemporalFilterSettings() const;

		void setAverageFilterEnabled(const bool enabled);
		bool getAverageFilterEnabled() const;

		void setMedianFilterEnabled(const bool enabled);
		bool getMedianFilterEnabled() const;

		void setEdgeFilterSettings(const uint32_t threshold);

		void setInterferenceDetectionSettings(const InterferenceDetectionSettings interferenceDetectionSettings);

		void setTemporalEdgeFilterSettings(const uint32_t thresholdLow, const uint32_t thresholdHigh);
		 /********************************************
			*Algorithm functions
		 *********************************************/
		void setMovementDetectionAlgorithmSettings(const MovementDetectionAlgorithmSettings algorithmSettings);
		MovementDetectionAlgorithmSettings getMovementDetectionAlgorithmSettings() const;
		bool getifMovementDetectionAlgorithmEnabled();

		void setSkeletonDetectionAlgorithmEnabled(const bool enabled);
		bool getifSkeletonDetectionAlgorithmEnabled() const;


			//add other Algorithms here

		/********************************************
		 *Compensation setter
		 ********************************************/
		void setGrayscaleCompensation(GrayscaleCompensation *grayscaleCompensation);

	protected:
    uint32_t calcFpgaGetDistanceAndAmplitudeDualIntTime(const uint32_t valueLowIntTime, const uint32_t valueHighIntTime, uint32_t *pAmplitude, const uint32_t minAmplitude);

	private:
    template <typename T> void processSingleIntegrationTime(const uint32_t *pData, const T *pLastResult, T *pResult, const CalculationParameters &parameters,CalculationResults &results);
    template <typename T> void processDualIntegrationTime(uint32_t *data0, uint32_t *data1, const T *pLastResult, T *pResult, CalculationParameters &parameters, CalculationResults &results);

    Algorithm algorithm;
    Filter filter;                                                       ///<Filter class containing all filters
    Hysteresis hysteresis;                                               ///<Hysteresis for minimal amplitude
    GrayscaleCompensation *grayscaleCompensation;                        ///<Grayscale compensation, later not needed anymore
};

#endif /* CALCULATION_H_ */
