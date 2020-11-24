/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 *
 * @addtogroup grayscale_calibration_calculation
 *
 * @{
 */
#include "GrayscaleCalibrationCalculation.h"

/**
 * @brief Calculate spatial average
 *
 * This function calculates the spatial average of the grayscale image.
 *
 * @param pGrayscale Pointer to the current grayscale data
 * @param numPixel Number of pixels
 * @return spatial average
 */
uint32_t GrayscaleCalibrationCalculation::grayscaleSpatialAverage(const uint32_t *pGrayscale, const uint32_t numPixel)
{
	uint32_t sum = 0;

	//Sum up the distances
	for (uint32_t i = 0; i < numPixel; i++)
	{
	  uint32_t currentValue = pGrayscale[i];
		sum += currentValue;
	}

	uint32_t average = sum / numPixel;

	return average;
}

/**
 * @brief Prepare to calculate the temporal average
 *
 * Call this function before using grayscaleTemporalAverageCalculate
 *
 * @param numPixel Number of pixels
 * @param pResult Pointer to store the sums of each pixel
 */
void GrayscaleCalibrationCalculation::grayscaleTemporalAveragePrepare(const uint32_t numPixel, uint32_t *pResult)
{
	this->pSumTemporalAverage = pResult;
	this->numValueTemporalAverage = 0;

	//Important: init to zero for average
	for (uint32_t i = 0; i < numPixel; i++)
  {
		pSumTemporalAverage[i] = 0;
  }
}

/**
 * @brief Sum up for grayscale average
 *
 * This function only sums up the grayscale, so later the average can be calculated by a
 * division. There is no memory to store all the images for the average.
 *
 * @param pGrayscale Pointer to the current grayscale data
 * @param numPixel Number of pixels
 */
void GrayscaleCalibrationCalculation::grayscaleTemporalAverageSumUp(const uint32_t *pGrayscale, const uint32_t numPixel)
{
	numValueTemporalAverage++;

	//Sum up the distances
	for (uint32_t i = 0; i < numPixel; i++)
	{
	  uint32_t currentValue = pGrayscale[i];
		pSumTemporalAverage[i] += currentValue;
	}
}

/**
 * @brief Calculate the average of grayscale
 *
 * This function calculates the average per pixel. It therefore just divides the sum of each pixel.
 *
 * @param numPixel Number of pixels
 */
void GrayscaleCalibrationCalculation::grayscaleTemporalAverageCalculate(const uint32_t numPixel)
{
	for (uint32_t i = 0; i < numPixel; i++)
	{
		pSumTemporalAverage[i] /= numValueTemporalAverage;
  }
}

/** @} */
