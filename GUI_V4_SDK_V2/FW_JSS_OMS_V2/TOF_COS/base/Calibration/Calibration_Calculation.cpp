#include "Calibration_Calculation.h"
#include <math.h>
#include <stdlib.h>
#include <TOF_COS_Constants.h>
#include "TypePixelCode.h"
#include "Calculation/calcFpga.h"
#include "fpga.h"
#include "TOF_COS_Config.h"

///<Special value for invalid pixels in 32Bit mode
const uint32_t VALUE_INVALID_PIXEL_UINT32 = 0xFFFFFFFF;

///Number of pixels in the center for
const uint32_t NUM_CENTER_PIXELS = 10;

CalibrationCalculation::CalibrationCalculation(): Calculation()
{
  pDistance = nullptr;
}

/**
 * @brief prepare for calibration
 *
 * This function is called at the beginning of the calibration to setup all
 * required sub modules.
 */
void CalibrationCalculation::prepareForCalibration()
{
	fpgaSetPreCorrectionOffsetEnabled(true);
	fpgaSetDistanceCorrectionEnabled(false);
	fpgaSetPostCorrectionOffsetEnabled(false);

//On the old soft logic the bit for grayscale compensation is used as bit to enable the calibration mode (new soft logic without calibration mode)
//Remove this code when the old soft logic is not used anymore
#if (OLD_SOFT_LOGIC==1)
	fpgaSetGrayscaleCompensationEnabled(true);
#endif

	//Use the multiplier 1 for calibration, so the calibration data matches the output data
	fpgaSetMultiplierToOne();

	//This offsets must be zero here
	fpgaSetPostCorrectionOffset(0);
	fpgaSetPreCorrectionOffset(0);
}

/**
 * @brief Scale a distance
 *
 * Scale a distance that is at full range to the current range
 *
 * @param setDistanceFullRange Set Distance in full range of the FPGA ALU
 * @return Distance in current range (e.g. mm)
 */
uint32_t CalibrationCalculation::scaleSetDistance(const uint32_t setDistanceFullRange)
{
  return fpgaScaleDistance(setDistanceFullRange);
}

/**
 * @brief Set offset
 *
 * Set offset of atan calculation to get distance 0 at step 0.
 *
 * @param offset Offset to set
 */
void CalibrationCalculation::setOffset(const int32_t offset)
{
	fpgaSetPreCorrectionOffset(offset);
}

/**
 * @brief Set calibration distance range
 *
 * Set distance range for calibration. This is not equal with the range later
 *
 * @param range Range
 */
void CalibrationCalculation::setCalibrationDistanceRange(const int32_t range)
{
	distanceRange = range;
}


/**
 * @brief Calculate the distance average of the pixels
 *
 * This function calculates the average of the valid pixels.
 *
 * @param pDcsData Pointer to the DCS Data (4 images at one piece)
 * @param numPixel Number of Pixels
 * @param compensate true if the distance should be compensated
 * @return average
 */
uint32_t CalibrationCalculation::calcDistAverage(const uint32_t *pDcsData, const uint32_t numPixel, const bool compensate)
{
  const uint32_t *pData32 = reinterpret_cast<const uint32_t *>(pDcsData);
  int32_t numValue = 0;
  int64_t sum = 0;
  int32_t offset = 0;

  for (uint32_t i = 0; i < numPixel; i++)
  {
    uint32_t value = pData32[i];

    //Only use the valid pixels
    if ((calcFpgaIsSaturated(value) == false) &&
        (calcFpgaIsAdcOverflow(value) == false))
    {
      int32_t distance = calcFpgaDistanceCalibration(value);

      if (compensate)
      {
        distance = calcFpgaDistanceNormal(value);
      }
      else
      {
        distance = calcFpgaDistanceCalibration(value);
      }

      //At the first value calculate an offset to have the values around the middle of the range --> middle range get's virtual "zero"
      if (numValue == 0)
      {
        offset = (distanceRange / 2) - distance;
      }

      //Add this offset
      processOffset(&distance, offset);

      //Sum up with the offset
      sum += distance;

      numValue++;
    }
  }

  //Calculate the average; still with the offset
  int32_t distanceAverage = sum /= numValue;

  //Now remove the offset again
  processOffset(&distanceAverage, -offset);

  return static_cast<uint32_t>(distanceAverage);
}

/**
 * @brief Amplitude spatial average
 *
 * This function returns the spatial average of the amplitude.
 *
 * - Invalid pixels are omitted.
 *
 * @param pDcsData Pointer to the data from the FPGA containing already distance and amplitude
 * @param numPixel Number of Pixels
 * @param pAmplitude Array to store the data
 * @retval 0 Failed
 * @return average
 */
uint32_t CalibrationCalculation::amplitudeSpatialAverage(const uint32_t *pDcsData, const uint32_t numPixel, uint16_t *pAmplitude)
{
	const uint32_t *pData32 = reinterpret_cast<const uint32_t *>(pDcsData);
	uint32_t numValue = 0;
	uint32_t sum = 0;

	for (uint32_t i = 0; i < numPixel; i++)
	{
		uint32_t value = pData32[i];
		if ((calcFpgaIsSaturated(value) == false) && (calcFpgaIsAdcOverflow(value) == false))
		{
      uint32_t amplitude = calcFpgaAmplitude(value);
			sum += amplitude;
      numValue++;
		}
	}

	if (numValue == 0)
	{
		return 0;
	}

	//Calculate the average pixel
	uint32_t averagePixel = sum / numValue;

	return averagePixel;
}

void CalibrationCalculation::prepareForDistAverage(const uint32_t numPixel, const uint32_t averageDistanceAtStep0, const uint32_t wantedTemperature, uint32_t *pDistance)
{
	this->pDistance = pDistance;
	this->numPixel = numPixel;
	this->numValue = 0;
	this->wantedTemperature = wantedTemperature;
	this->sumTemperature = 0;
	this->averageTemperature = 0;

	for (uint32_t i = 0; i < numPixel; i++)
  {
    pDistance[i] = 0;
  }

	//This is just a value to not be near zero. At the end there is a back shift
	offset = 3700 - averageDistanceAtStep0;
}

/**
 * @brief Calculate distance for average.
 *
 * This function only sums up the distances, so later the average can be calculated by a
 * division. There is no memory to store all the images for the average.
 *
 * @param pInputData Pointer to the input data
 * @param numPixel Number of Pixels
 * @param pDistance Pointer to the memory for the distance
 */
void CalibrationCalculation::calcDistAndSumUp(const uint32_t *pInputData, const uint32_t actTemperature, const bool compensate)
{
	const uint32_t *pData32 = reinterpret_cast<const uint32_t *>(pInputData);

	sumTemperature += actTemperature;
	numValue++;

	for (uint32_t i = 0; i < numPixel; i++)
	{
		uint32_t value = pData32[i];

		if (calcFpgaIsSaturated(value))
		{
			pDistance[i] = VALUE_INVALID_PIXEL_UINT32;
		}
		else if (calcFpgaIsAdcOverflow(value))
		{
			pDistance[i] = VALUE_INVALID_PIXEL_UINT32;
		}
		//calculate the distance --> here add it, but only, if it is valid
		else if (pDistance[i] != VALUE_INVALID_PIXEL_UINT32)
		{
			int32_t distance;

			if (compensate)
			{
				distance = calcFpgaDistanceNormal(value);
			}
			else
			{
				distance = calcFpgaDistanceCalibration(value);
			}

			processOffset(&distance, offset);

			//Sum up the distance
			pDistance[i] += distance;
		}
	}
}

/**
 * @brief Calculate the average
 *
 * This function calculates the average per pixel. The value per pixel must be a
 * sum of measurements, so this function can just divide the value.
 * Invalid pixels are marked with a special value and are omitted.
 *
 * @param pDistance Pointer to the distance array
 * @param numPixel Number of pixels
 * @param numValue Number of values summed up
 */
void CalibrationCalculation::calcAveragePerValidPixel()
{
	int32_t sumDistance = 0;
	uint32_t numInSum = 0;
	minDistance = 100000; //Just a high value
	maxDistance = 0;
	int32_t averageDistanceTemp = 0;

	for (uint32_t i = 0; i < numPixel; i++)
	{
		//Omit the invalid pixels
		if (pDistance[i] != VALUE_INVALID_PIXEL_UINT32)
		{
			int32_t distance = pDistance[i] / numValue;

		  sumDistance += distance;
		  numInSum++;

		  //Negative offset, to "turn" back
		  processOffset(&distance, -offset);

		  pDistance[i] = distance;

		  if (pDistance[i] > maxDistance)
		  {
		  	maxDistance = pDistance[i];
		  }
		  else if (pDistance[i] < minDistance)
		  {
		  	minDistance = pDistance[i];
		  }
		}
  }

	averageDistanceTemp = sumDistance / numInSum;

	//Negative offset, to "turn" back
	processOffset(&averageDistanceTemp, -offset);

	averageDistance = averageDistanceTemp;

  averageTemperature = sumTemperature / numValue;
}

void CalibrationCalculation::processOffset(int32_t *pDistance, const int32_t offset)
{
	int32_t distance = *pDistance;

	distance += offset;

	if (distance < 0)
	{
		distance += distanceRange + 1;
	}
	else if (distance > distanceRange)
	{
		distance -= distanceRange + 1;
	}

	*pDistance = distance;
}


uint32_t CalibrationCalculation::getMinDistance() const
{
  return minDistance;
}

uint32_t CalibrationCalculation::getMaxDistance() const
{
	return maxDistance;
}

int32_t CalibrationCalculation::getTemperatureDiff() const
{
	int32_t tempDiff = (int32_t)averageTemperature - (int32_t)wantedTemperature;

	return tempDiff;
}

uint32_t CalibrationCalculation::getAverageTemperature() const
{
	return averageTemperature;
}

uint32_t CalibrationCalculation::getAverageDistance() const
{
	return averageDistance;
}

/**
 * @brief DCS average
 *
 * Calculate the average of the DCS.
 *
 * @param dcsData Pointer to the DCS data buffer
 * @param numPixel Number of pixels
 * @param dcsIndex Index of the selected DCS
 */
uint32_t CalibrationCalculation::dcsAverage(const uint32_t *dcsData, const uint32_t numPixel, const uint32_t dcsIndex)
{
  uint32_t sum = 0;
  uint32_t numPixelWithValidData = 0;


	//The data comes like this: |DCS0 all pixels|DCS2 all pixels|DCS1 all pixels|DCS3 all pixels|. So each DCS has an offset of number of pixels
	const uint32_t dcsOffset = dcsIndex * numPixel;

	if (dcsIndex > 3)
	{
	  return 0;
	}/* No DCS available ---------------------------------> */

	for (uint32_t i = 0; i <= numPixel; i++)
	{
    uint32_t currentIndex = i + dcsOffset;
		sum += dcsData[currentIndex];
    numPixelWithValidData++;
	}

	if (numPixelWithValidData == 0)
	{
	  return 0;
	}/* No average possible ---------------------------------> */

	uint32_t average = sum / numPixelWithValidData;

	return average;
}
