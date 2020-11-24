/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup grayscale_calibration_calculation Grayscale Calibration Calculation
 * @brief Calculation functions for the grayscale calibration
 * @ingroup calibration_calculation
 *
 * @{
 */
#ifndef GRAYSCALE_CALIBRATION_CALCULATION_H_
#define GRAYSCALE_CALIBRATION_CALCULATION_H_

#include <stdint.h>

//! Calculation functions for grayscale calibration
/*!
 * This class offers calculation functions used only for grayscale calibration
 */
class GrayscaleCalibrationCalculation
{
	public:
		void grayscaleTemporalAveragePrepare(const uint32_t numPixel, uint32_t *pResult);
		void grayscaleTemporalAverageSumUp(const uint32_t *pGrayscale, const uint32_t numPixel);
		void grayscaleTemporalAverageCalculate(const uint32_t numPixel);
		uint32_t grayscaleSpatialAverage(const uint32_t *pGrayscale, const uint32_t numPixel);

	private:
		uint32_t *pSumTemporalAverage;                   ///<Pointer to the image buffer where the sum for each pixel is stored to later calculate the temporal average
		uint32_t numValueTemporalAverage;                ///<Number of values for each pixel
};

#endif /* GRAYSCALE_CALIBRATION_CALCULATION_H_ */

/** @} */
