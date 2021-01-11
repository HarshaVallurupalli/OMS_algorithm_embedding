#ifndef IMPLEMENTATION_CALCULATION_CALIBRATION_CALCULATION_H_
#define IMPLEMENTATION_CALCULATION_CALIBRATION_CALCULATION_H_

#include "Calibration/Calibration_Calculation.h"
#include "Calculation/Calculation.h"

class CalibrationCalculation: public Calculation
{
	public:
		CalibrationCalculation();

		void prepareForCalibration();
		uint32_t calcDistAverage(const uint32_t *pDcsData, const uint32_t numPixel, const bool compensate);
		uint32_t amplitudeSpatialAverage(const uint32_t *pDcsData, const uint32_t numPixel, uint16_t *pAmplitude);
		void prepareForDistAverage(const uint32_t numPixel, const uint32_t averageDistanceAtStep0, const uint32_t wantedTemperature, uint32_t *pDistance);
		void calcDistAndSumUp(const uint32_t *pInputData, const uint32_t actTemperature, const bool compensate);
		void calcAveragePerValidPixel();
		uint32_t dcsAverage(const uint32_t *dcsData, const uint32_t numPixel, const uint32_t dcsIndex);

		void setCalibrationDistanceRange(const int32_t range);
		void setOffset(const int32_t offset);
		uint32_t scaleSetDistance(const uint32_t setDistanceFullRange);

		uint32_t getMinDistance() const;
		uint32_t getMaxDistance() const;

		int32_t getTemperatureDiff() const;
		uint32_t getAverageTemperature() const;
		uint32_t getAverageDistance() const;

	private:
		void processOffset(int32_t *pDistance, const int32_t offset);

		int32_t offset;
		uint32_t numPixel;
		uint32_t *pDistance;
		uint32_t numValue;
		uint32_t minDistance;
		uint32_t maxDistance;
		uint32_t wantedTemperature;
		uint32_t sumTemperature;
		uint32_t averageTemperature;
		uint32_t averageDistance;
		int32_t distanceRange;            ///<Stores the distance range of the atan = unambiguity distance
};

#endif /* IMPLEMENTATION_CALCULATION_CALIBRATION_CALCULATION_H_ */
