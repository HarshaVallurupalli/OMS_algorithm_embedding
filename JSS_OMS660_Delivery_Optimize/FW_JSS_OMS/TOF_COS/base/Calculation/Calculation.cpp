/***
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @addtogroup calc_fpga
 */
#include <Calibration/DrnuCalibrationDataHelper.h>
#include "Calculation.h"
#include <stdbool.h>
#include <math.h>
#include "drivers/fpga_ctrl.h"
#include "TypePixelCode.h"
#include <string.h>
#include <TOF_COS_Constants.h>
#include "fpga.h"
#include "Calculation/calcFpga.h"
#include "Pixel/PixelToFDcs.h"
#include "Iterator.h"

#include "events/events.h"
#include "Integration_times/Integration_times.h"

Calculation::Calculation()
{

}

/**
 * @brief Init
 *
 * Call this function before using this class
 */
void Calculation::init()
{

}

/**
 * @brief Calculate distance with dual integration time
 *
 * This function calculates the distance using two integration times.
 * When both values are valid, it uses the value with the higher amplitude, normally the one with
 * the higher integration time. When only one is valid (normally a near object, that is saturated with the high integration time), it uses the
 * other one.
 *
 * @param valueLowIntTime 32Bit value belonging to this pixel received from the FPGA (first/low integration time)
 * @param valueHighIntTime 32Bit value belonging to this pixel received from the FPGA (second/high integration time)
 * @param pAmplitude Pointer to the value where to write the amplitude
 * @param minAmplitude minimum amplitude in LSB
 * @retval SATURATION Pixel is saturated
 * @retval LOW_AMPLITUDE Amplitude is too low
 * @return distance or SATURATION/LOW_AMPLITUDE
 */
uint32_t Calculation::calcFpgaGetDistanceAndAmplitudeDualIntTime(const uint32_t valueLowIntTime, const uint32_t valueHighIntTime, uint32_t *pAmplitude, const uint32_t minAmplitude)
{

	Integration_times* integration_times = Integration_times::getInstance();
	if((integration_times->get_New_Integration_time_high() != integration_times->get_Old_Integration_time_high()) || (integration_times->get_New_Integration_time_low() != integration_times->get_Old_Integration_time_low()))
    {
	 integration_times -> Calculate_Scaling_factor();// scaling factor = sqrt(int_time_high/int_time_low)

	 integration_times->set_Old_Integration_time_high(integration_times->get_New_Integration_time_high());
	 integration_times->set_Old_Integration_time_low(integration_times->get_New_Integration_time_low());
    }

	uint32_t distance;
	uint32_t valueToUse;
	double Scaling_factor = integration_times -> get_Scaling_factor();
	//double Scaling_factor =1;

	//If the pixel with the high integration time is saturated or overflow, use the pixel with the low integration time
	if ((calcFpgaIsSaturated(valueHighIntTime)) || (calcFpgaIsAdcOverflow(valueHighIntTime)) || (calcFpgaIsInterfered(valueHighIntTime)))
	{
		//If the low integration time is not usable, directly return here
		if (calcFpgaIsSaturated(valueLowIntTime))
		{
			*pAmplitude = TypePixelCode::PIXEL_CODE_SATURATION;
			return TypePixelCode::PIXEL_CODE_SATURATION;   /* --------------------------------------> Exit here */
		}
		if (calcFpgaIsAdcOverflow(valueLowIntTime))
		{
			*pAmplitude = TypePixelCode::PIXEL_CODE_ADC_OVERFLOW;
			return TypePixelCode::PIXEL_CODE_ADC_OVERFLOW; /* --------------------------------------> Exit here */
		}
		if (calcFpgaIsInterfered(valueLowIntTime))
		{
		  *pAmplitude = TypePixelCode::PIXEL_CODE_INTERFERENCE;
			return TypePixelCode::PIXEL_CODE_INTERFERENCE; /* --------------------------------------> Exit here */
		}

		//Assign the usable value
		valueToUse = valueLowIntTime;
		*pAmplitude = (calcFpgaAmplitude(valueToUse))*(Scaling_factor);
	}
	//The high integration time is ok, so use this one
	else
	{
		//If the low integration time is not usable (this is not expected to be the case), use the high integration time
		if ((calcFpgaIsSaturated(valueLowIntTime)) || (calcFpgaIsAdcOverflow(valueLowIntTime)) || (calcFpgaIsInterfered(valueLowIntTime)))
		{
			valueToUse = valueHighIntTime;
			*pAmplitude = (calcFpgaAmplitude(valueToUse))/(Scaling_factor);
		}
		else
		{
			//Get both amplitudes
			uint32_t amplitudeLow = calcFpgaAmplitude(valueLowIntTime);
			uint32_t amplitudeHigh = calcFpgaAmplitude(valueHighIntTime);

			//Compare the two amplitudes. Normally the amplitude of the high integration time is higher anyway
			if (amplitudeHigh >= amplitudeLow)
			{
				valueToUse = valueHighIntTime;
				*pAmplitude = (amplitudeHigh)/(Scaling_factor);
			}
			else
			{
				valueToUse = valueLowIntTime;
				*pAmplitude = (amplitudeLow)*(Scaling_factor);
			}
		}
	}

	if (*pAmplitude < minAmplitude)
	{
	  distance = TypePixelCode::PIXEL_CODE_LOW_AMPLITUDE;
	}
	else
	{
	  distance = calcFpgaDistanceNormal(valueToUse);
  }
	return distance;
}

/**
 * @brief Distance and amplitude with dual integration time
 *
 * The distance and amplitude calculations are done by the FPGA. In this function the better amplitude is chosen and the status flags from the FPGA are converted
 * to special code values.
 *
 * @param data0 Pointer to the image containing distance and amplitude (first integration time)
 * @param data1 Pointer to the image containing distance and amplitude (second integration time)
 * @param lastResult Pointer to the last image
 * @param result Pointer to the result data
 * @param parameters Parameters needed for the calculation
 * @param results Reference to the calculation results
 */
void Calculation::distAmpDualIntegrationTime(uint32_t *data0, uint32_t *data1, const uint8_t *lastResult, uint8_t *result, CalculationParameters &parameters, CalculationResults &results)
{
	const PixelToF_DistanceAmplitude *lastResultData = reinterpret_cast<const PixelToF_DistanceAmplitude *>(lastResult);
	PixelToF_DistanceAmplitude *resultData = reinterpret_cast<PixelToF_DistanceAmplitude *>(result);

	hysteresis.setMinAmplitude(parameters.minAmplitude, false, filter.getTemporalFilterEnabled());

	for (uint32_t i = 0; i < parameters.numPixel; i++)
  {
  	uint32_t value0 = data0[i];
  	uint32_t value1 = data1[i];
  	uint32_t amplitude;

  	uint32_t lastDistance = lastResultData[i].getDistance();
  	uint32_t minAmplitude = hysteresis.calcMinAmplitudeWithHysteresis(lastDistance);
  	uint32_t distance = calcFpgaGetDistanceAndAmplitudeDualIntTime(value0, value1, &amplitude, minAmplitude);
  	resultData[i].setDistanceAmplitude(distance, amplitude);
	}
}

/**
 * @brief Distance and amplitude with single integration time
 *
 * All the calculations are done by the FPGA. In this function only the status flags from the FPGA are converted
 * to special code values. This is for compatibility reasons.
 *
 * @param data Pointer to the image containing distance and amplitude
 * @param lastResult Pointer to the last image
 * @param result Pointer to the result data
 * @param parameters Parameters needed for the calculation
 * @param results Reference to the calculation results
 */
void Calculation::distAmpSingleIntegrationTime(uint32_t *data, const uint8_t *lastResult, uint8_t *result, CalculationParameters &parameters, CalculationResults &results)
{
	const PixelToF_DistanceAmplitude *lastResultData = reinterpret_cast<const PixelToF_DistanceAmplitude *>(lastResult);
	PixelToF_DistanceAmplitude *resultData = reinterpret_cast<PixelToF_DistanceAmplitude *>(result);

	processSingleIntegrationTime<PixelToF_DistanceAmplitude>(data, lastResultData, resultData, parameters, results);
}

/**
 * @brief Distance and amplitude with dual integration time
 *
 * The distance and amplitude calculations are done by the FPGA. In this function the better amplitude is chosen and the status flags from the FPGA are converted
 * to special code values.
 *
 * @param data0 Pointer to the image containing distance and amplitude (first integration time)
 * @param data1 Pointer to the image containing distance and amplitude (second integration time)
 * @param pLastResult Pointer to the last image
 * @param pResult Pointer to the result data
 * @param parameters Parameters needed for the calculation
 * @param results Reference to the calculation results
 */
template <typename T> void Calculation::processDualIntegrationTime(uint32_t *data0, uint32_t *data1, const T *pLastResult, T *pResult, CalculationParameters &parameters, CalculationResults &results)
{

	uint32_t numPixel = parameters.numPixel;
	hysteresis.setMinAmplitude(parameters.minAmplitude, false, filter.getTemporalFilterEnabled());

	for (uint32_t i = 0; i < numPixel; i++)
  {
  	uint32_t value0 = data0[i];
  	uint32_t value1 = data1[i];
  	uint32_t amplitude;

  	uint32_t lastDistance = pLastResult[i].getDistance();
  	uint32_t minAmplitude = hysteresis.calcMinAmplitudeWithHysteresis(lastDistance);
  	uint32_t distance = calcFpgaGetDistanceAndAmplitudeDualIntTime(value0, value1, &amplitude, minAmplitude);
  	pResult[i].setDistanceAmplitude(distance, amplitude);
	}
}

/**
 * @brief Process single integration time
 *
 * - Works for distance or distance/amplitude
 * - Sets special codes for invalid pixels
 * - Processes hysteresis for the minimal amplitude
 *
 * @param pData Pointer to the data
 * @param pLastResult Pointer to the last data
 * @param pResult Pointer to the result data
 * @param parameters Parameters needed for the calculation
 * @param results Reference to the calculation results
 */
template <typename T> void Calculation::processSingleIntegrationTime(const uint32_t *pData, const T *pLastResult, T *pResult, const CalculationParameters &parameters,CalculationResults &results)
{
	uint32_t numPixel = parameters.numPixel;

	hysteresis.setMinAmplitude(parameters.minAmplitude, false, filter.getTemporalFilterEnabled());

	for (uint32_t i = 0; i < numPixel; i++)
  {
  	uint32_t value = pData[i];
  	uint32_t amplitude = calcFpgaAmplitude(value);
  	uint32_t distance = calcFpgaDistanceNormal(value);
  	if (calcFpgaIsSaturated(value))
  	{
  		pResult[i].setSaturated();
  	}
  	else if (calcFpgaIsAdcOverflow(value))
  	{
  		pResult[i].setAdcOverflow();
  	}
  	else if (calcFpgaIsInterfered(value))
  	{
  		pResult[i].setInterfered();
  	}
  	else
  	{
  		uint32_t lastDistance = pLastResult[i].getDistance();
  		uint32_t minAmplitude = hysteresis.calcMinAmplitudeWithHysteresis(lastDistance);

  		if (amplitude < minAmplitude)
  	  {
  			pResult[i].setLowAmplitude(amplitude);
  	  }
  	  else
  	  {
  	  	pResult[i].setDistanceAmplitude(distance, amplitude);
  	  }
  	}
  }
}

/**
 * @brief Distance with single integration time
 *
 * The distance calculations are done by the FPGA.
 *
 * @param data Pointer to the image containing distance and amplitude
 * @param lastResult Pointer to the last image
 * @param result Pointer to the result data
 * @param parameters Parameters needed for the calculation
 * @param results Reference to the calculation results
 */
void Calculation::distSingleIntegrationTime(uint32_t *data, const uint8_t *lastResult, uint8_t *result, CalculationParameters &parameters, CalculationResults &results)
{
	const PixelToF_Distance *lastResultData = reinterpret_cast<const PixelToF_Distance *>(lastResult);
	PixelToF_Distance *resultData = reinterpret_cast<PixelToF_Distance *>(result);

	processSingleIntegrationTime<PixelToF_Distance>(data, lastResultData, resultData, parameters, results);
}

/**
 * @brief Distance with dual integration time
 *
 * The distance calculations are done by the FPGA. In this function the better amplitude is chosen and the status flags from the FPGA are converted
 * to special code values. The amplitude is not put into the output.
 *
 * @param data0 Pointer to the first image containing distance and amplitude (first integration time)
 * @param data1 Pointer to the second image containing distance and amplitude (second integration time)
 * @param lastResult Pointer to the last image
 * @param result Pointer to the result data
 * @param parameters Parameters needed for the calculation
 * @param results Reference to the calculation results
 */
void Calculation::distDualIntegrationTime(uint32_t *data0, uint32_t *data1, const uint8_t *lastResult, uint8_t *result, CalculationParameters &parameters, CalculationResults &results)
{
	const PixelToF_Distance *lastResultData = reinterpret_cast<const PixelToF_Distance *>(lastResult);
	PixelToF_Distance *resultData = reinterpret_cast<PixelToF_Distance *>(result);

	processDualIntegrationTime<PixelToF_Distance>(data0, data1, lastResultData, resultData, parameters, results);
}

/**
 * @brief Set grayscale compensation
 *
 * Later not needed any more. Just for some tests before the soft logic is running the grayscale compensation.
 *
 * @param grayscaleCompensation Pointer to the grayscale compensation to use
 */
void Calculation::setGrayscaleCompensation(GrayscaleCompensation *grayscaleCompensation)
{
  this->grayscaleCompensation = grayscaleCompensation;
}

/**
 * @brief Grayscale image
 *
 * This function only converts to a 16Bit value
 *
 * @param inputData Pointer to the 32Bit grayscale data from the FPGA
 * @param grayscaleData Pointer to the 16Bit grayscale result data
 * @param numPixel Number of pixels
 */
void Calculation::grayscale(uint32_t *inputData, uint16_t *grayscaleData, const uint32_t numPixel)
{
  //If the subtract and the compensation are disabled, the values of the sensor are 2048..4095. So subtract 2048.
  bool subtract = (fpgaGetGrayscaleCompensationEnabled() == false) && (fpgaGetGrayscaleSubtractEnabled() == false);

  for (uint32_t i = 0; i < numPixel; i++)
  {
    int32_t value = inputData[i];

    if (subtract)
    {
      value -= 2048;

      if (value < 0)
      {
        value = 0;
      }
    }

  	grayscaleData[i] = value;
  }
}

/**
 * @brief DCS image
 *
 * This function does:
 * - Sorting and shrinking to 16bit values
 * - Add special codes in case of adc overflow or saturation
 *
 * @param pDcs Pointer to the 32bit DCS data
 * @param pDcsSorted Pointer to the 16bit sorted DCS data
 * @param parameters Parameters needed for the calculation
 * @param results Reference to the calculation results
 */
void Calculation::rawDcsSorted(const uint32_t *pDcs, uint8_t *pDcsSorted, const CalculationParameters &parameters, CalculationResults &results)
{
  Iterator iterator;
  uint32_t numPixel = parameters.numPixel;
  const uint32_t *dcsIn[4];
  PixelToF_Dcs *resultData[4];

  //Create some helper pointers
  for (uint8_t i = 0; i < 4; i++)
  {
    dcsIn[i] = reinterpret_cast<const uint32_t *>(&pDcs[i * numPixel]);

    resultData[i] = reinterpret_cast<PixelToF_Dcs *>(&pDcsSorted[i * numPixel * sizeof(PixelToF_Dcs)]);
  }

  //To sort the image we use an iterator in software
  iterator.init(numPixel, parameters.acquisitionInfo.getWidth(), parameters.acquisitionInfo.getHeight());

  for (uint8_t i = 0; i < numPixel; i++)
  {
    uint32_t currentIndex = iterator.getNext();

    for (uint8_t j = 0; j < 4; j++)
    {
      uint32_t dcsInput = dcsIn[j][i];

      if (calcFpgaIsAdcOverflow(dcsInput))
      {
        resultData[j][currentIndex].setAdcOverflow();
      }
      else if (calcFpgaIsSaturated(dcsInput))
      {
        resultData[j][currentIndex].setSaturated();
      }
      else
      {
        resultData[j][currentIndex].setValue(dcsInput);
      }
    }

    //As long as the soft logic is not ready, fill in some artificial data
//    resultData[0][currentIndex].setValue(1000);
//    resultData[1][currentIndex].setValue(2000);
//    resultData[2][currentIndex].setValue(3000);
//    resultData[3][currentIndex].setValue(4000);

  }
}

/**
 * @brief Process filter on distance/amplitude
 *
 * This function is used to process filtering on distance/amplitude data
 *
 * @param pDistanceAmplitude Pointer to the array with the compensated distance/amplitude
 * @param pLastDistanceAmplitude Pointer to the last distance/amplitude. Used for filtering
 * @param parameters Reference to the parameters class containing all needed parameters for the calculation
 * @param results Reference to the results class containing all needed values for the results
 */
void Calculation::processFilterOnDistanceAmplitude
(
  uint8_t *pDistanceAmplitude,
	const uint8_t *pLastDistanceAmplitude,
	const CalculationParameters &parameters,
	CalculationResults &results
)
{
  PixelToF_DistanceAmplitude *pixelDistanceAmplitude = reinterpret_cast<PixelToF_DistanceAmplitude *>(pDistanceAmplitude);
	const PixelToF_DistanceAmplitude *pixelLastDistanceAmplitude = reinterpret_cast<const PixelToF_DistanceAmplitude *>(pLastDistanceAmplitude);

	filter.processFilter(pixelDistanceAmplitude, pixelLastDistanceAmplitude, parameters, results);

}

/**
 * @brief Process filter on distance
 *
 * This function is used to process filtering on distance data
 *
 * @param pDistance Pointer to the array with the compensated distance
 * @param pLastDistance Pointer to the last distance. Used for filtering
 * @param parameters Reference to the parameters class containing all needed parameters for the calculation
 * @param results Reference to the results class containing all needed values for the results
 */
void Calculation::processFilterOnDistance
(
  uint8_t *pDistance,
	const uint8_t *pLastDistance,
	const CalculationParameters &parameters,
	CalculationResults &results
)
{
  PixelToF_Distance *pixelDistance = reinterpret_cast<PixelToF_Distance *>(pDistance);
	const PixelToF_Distance *pixelLastDistance = reinterpret_cast<const PixelToF_Distance *>(pLastDistance);

	filter.processFilter(pixelDistance, pixelLastDistance, parameters, results);
}

//ALgorithm Edit
void Calculation::processAlgorithmOnDistanceAmplitude
(
  uint8_t *pDistanceAmplitude,
	const uint8_t *pLastDistanceAmplitude,
	const CalculationParameters &parameters,
	CalculationResults &results
)
{
	if(algorithm.enable==false)
		return;
  PixelToF_DistanceAmplitude *pixelDistanceAmplitude = reinterpret_cast<PixelToF_DistanceAmplitude *>(pDistanceAmplitude);
	const PixelToF_DistanceAmplitude *pixelLastDistanceAmplitude = reinterpret_cast<const PixelToF_DistanceAmplitude *>(pLastDistanceAmplitude);

	algorithm.processAlgorithm(pixelDistanceAmplitude, pixelLastDistanceAmplitude, parameters, results);

}


//Algorithm Edit
void Calculation::processAlgorithmOnDistance
(
  uint8_t *pDistance,
	const uint8_t *pLastDistance,
	const CalculationParameters &parameters,
	CalculationResults &results
)
{
	if(algorithm.enable==false)
		return;
  PixelToF_Distance *pixelDistance = reinterpret_cast<PixelToF_Distance *>(pDistance);
	const PixelToF_Distance *pixelLastDistance = reinterpret_cast<const PixelToF_Distance *>(pLastDistance);

	algorithm.processAlgorithm(pixelDistance, pixelLastDistance, parameters, results);
}

/**
 * @brief Set the temporal filter settings for the distance (all pixels)
 *
 * @param filterSettings Temporal filter settings class
 */
void Calculation::setTemporalFilterSettings(const TemporalFilterSettings filterSettings)
{
	filter.setTemporalFilterSettings(filterSettings);
}

/**
 * @brief Get the temporal filter settings for the distance (all pixels)
 *
 * @return filterSettings Temporal filter settings class
 */
TemporalFilterSettings Calculation::getTemporalFilterSettings() const
{
  return filter.getTemporalFilterSettings();
}

/**
 * @brief Enable/disable the average filter
 *
 * @param enabled Average filter enabled or disabled
 */
void Calculation::setAverageFilterEnabled(const bool enabled)
{
	filter.setAverageFilterEnabled(enabled);
}

/**
 * @brief Get average filter enabled
 *
 * @retval true Average filter enabled
 * @retval false Average filter disabled
 * @return Average filter enabled/disabled
 */
bool Calculation::getAverageFilterEnabled() const
{
	return filter.getAverageFilterEnabled();
}

/**
 * @brief Enable/disable the median filter
 *
 * @param enabled Median filter enabled or disabled
 */
void Calculation::setMedianFilterEnabled(const bool enabled)
{
	filter.setMedianFilterEnabled(enabled);
}

/**
 * @brief Get median filter enabled
 *
 * @retval true Median filter enabled
 * @retval false Median filter disabled
 * @return Median filter enabled/disabled
 */
bool Calculation::getMedianFilterEnabled() const
{
	return filter.getMedianFilterEnabled();
}

/**
 * @brief Set edge filter settings
 *
 * If the threshold is zero, the edge filter is disabled. If the threshold is higher
 * than zero, the edge filter is enabled and the threshold is used as threshold for edge detection.
 *
 * @param threshold Threshold for the edge filter in mm, zero for edge filter disabled
 */
void Calculation::setEdgeFilterSettings(const uint32_t threshold)
{
  filter.setEdgeFilterSettings(threshold);
}

//Algorithm Edit
void Calculation::setMovementDetectionSettings(bool enable, const uint16_t WindowSize)
{
	algorithm.enable= enable;
	algorithm.setMovementDetectionSettings(WindowSize);
}

/**
 * @brief Set the interference detection settings
 *
 * @param interferenceDetectionSettings Class containing the interference detection settings
 */
void Calculation::setInterferenceDetectionSettings(const InterferenceDetectionSettings interferenceDetectionSettings)
{
  //This parameter is needed in the filter class
	filter.setInterferenceUseLastValueEnabled(interferenceDetectionSettings.useLastValue);

	//The limit is directly written to the soft logic
  if (interferenceDetectionSettings.enabled)
  {
  	fpgaSetInterferenceThreshold(interferenceDetectionSettings.limit);
  }
  else
  {
  	//Set to a high value to disable the interference detection
  	fpgaSetInterferenceThreshold(10000);
  }
}

/**
 * @brief Set temporal edge filter threshold
 *
 * @param thresholdLow Lower threshold to set
 * @param thresholdHigh Higher threshold to set
 */
void Calculation::setTemporalEdgeFilterSettings(const uint32_t thresholdLow, const uint32_t thresholdHigh)
{
  filter.setTemporalEdgeFilterThreshold(thresholdLow, thresholdHigh);
}
