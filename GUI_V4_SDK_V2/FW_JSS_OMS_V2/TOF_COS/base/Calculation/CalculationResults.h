/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @defgroup calculation_results Calculation Results
 * @brief Results class for the calculations
 * @ingroup calculation
 *
 * @{
 */
#ifndef CALCULATION_RESULTS_H_
#define CALCULATION_RESULTS_H_

//! Results class for the calculations
/*!
 * This class contains some additional result (besides the pixels) of the calculations, e.g the number
 * of valid pixels. These results are used e.g. to adjust the integration time in automatic mode.
 */
class CalculationResults
{
	public:
		CalculationResults()
	  {
		  clear();
	  }
		void clear()
		{
			numPixelWithValidDistance = 0;
			numPixelWithDisturbance = 0;
		  numPixelWithSaturationOverflow = 0;
			maxAmplitude = 0;
			minDistance = 1000000; //Just a high value
		}

		uint32_t numPixelWithValidDistance;
		uint32_t numPixelWithDisturbance;
		uint32_t numPixelWithSaturationOverflow;
		uint32_t maxAmplitude;
		int32_t minDistance;
};

#endif /* CALCULATION_RESULTS_H_ */

/** @} */
