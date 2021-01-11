/***
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @addtogroup edge_filter
 */
#include "MovementDetectionAlgorithm.h"
#include <stdlib.h>
#include <math.h>
/**
 * @brief Constructor
 *
 */
enum
{
	AMPLITUDE = 0,
	DISTANCE = 1,
	DISTANCE_AMPLITUDE = 2

};

MovementDetectionAlgorithm::MovementDetectionAlgorithm()
{
	this->width = 320;
	this->height = 240;
	this->WindowSize = DEFAULT_WINDOW_SIZE;
	this->ImageType = DEFAULT_IMAGE_TYPE;
    for(int i = 0; i < 76800; i++)
    {
        OldMeanA[i] = 0;
    	OldVarianceA[i]=0;
        OldMeanD[i] = 0;
    	OldVarianceD[i]=0;
    }
}


/**
 * @brief Set the settings
 *
 * @param TemporalFilterSettings class containing the wanted settings
 */
void MovementDetectionAlgorithm::setSettings(const MovementDetectionAlgorithmSettings settings)
{
	this->WindowSize = settings.windowSize;

	if (this->WindowSize > MDA_MAXIMUM_WINDOW_SIZE)
	{
		this->WindowSize = MDA_MAXIMUM_WINDOW_SIZE;
	}
	this->ImageType = settings.imageType;
}

/**
 * @brief Get the settings
 *
 * @return TemporalFilterSettings class containing the current settings
 */
MovementDetectionAlgorithmSettings MovementDetectionAlgorithm::getSettings() const
{
	MovementDetectionAlgorithmSettings settings(this->WindowSize, this->ImageType);

	return settings;
}

/**
 * @brief Read back, if the filter is enabled
 *
 * @retval true Filter is enabled
 * @retval false Filter is disabled
 * @return Filter enabled or disabled
 */

bool MovementDetectionAlgorithm::isEnabled() const
{
	if (WindowSize == 0)
	{
		return false;
	}

	return true;
}


uint16_t MovementDetectionAlgorithm::calcPixelValue(const uint16_t amplitude, const uint16_t distance, uint32_t index)
{

	uint16_t Variance;
if(index < 	width*height)
{
switch(ImageType)

	{
	case AMPLITUDE:
		{
			//calculate Mean and Variance of Amplitude
			int32_t NewMeanA= (((WindowSize-1)*OldMeanA[index])+ amplitude)/WindowSize;
			int32_t NewVarianceA=(((WindowSize-1)*OldVarianceA[index]) + (((amplitude-NewMeanA)*(amplitude-NewMeanA))))/WindowSize;
			OldMeanA[index]=NewMeanA;
			OldVarianceA[index]=NewVarianceA;
			Variance = NewVarianceA;
		}
		break;
	case DISTANCE:
		{
			//calculate Mean and Variance of Distance
			int32_t NewMeanD= (((WindowSize-1)*OldMeanD[index])+ distance)/WindowSize;
			int32_t NewVarianceD=(((WindowSize-1)*OldVarianceD[index]) + (((distance-NewMeanD)*(distance-NewMeanD))))/WindowSize;
			OldMeanD[index]=NewMeanD;
			OldVarianceD[index]=NewVarianceD;
			Variance = NewVarianceD;
		}
		break;
	case DISTANCE_AMPLITUDE:
		{
			//calculate Mean and Variance of Amplitude
			int32_t NewMeanA= (((WindowSize-1)*OldMeanA[index])+ amplitude)/WindowSize;
			int32_t NewVarianceA=(((WindowSize-1)*OldVarianceA[index]) + (((amplitude-NewMeanA)*(amplitude-NewMeanA))))/WindowSize;
			OldMeanA[index]=NewMeanA;
			OldVarianceA[index]=NewVarianceA;

			//calculate Mean and Variance of Distance
			int32_t NewMeanD= (((WindowSize-1)*OldMeanD[index])+ distance)/WindowSize;
			int32_t NewVarianceD=(((WindowSize-1)*OldVarianceD[index]) + (((distance-NewMeanD)*(distance-NewMeanD))))/WindowSize;
			OldMeanD[index]=NewMeanD;
			OldVarianceD[index]=NewVarianceD;

			//add the variance of Amplitude and Distance
			Variance = NewVarianceD + NewVarianceA;
		}
		break;
	 default:
		{
			//calculate Mean and Variance of Amplitude
			int32_t NewMeanA= (((WindowSize-1)*OldMeanA[index])+ amplitude)/WindowSize;
			int32_t NewVarianceA=(((WindowSize-1)*OldVarianceA[index]) + (((amplitude-NewMeanA)*(amplitude-NewMeanA))))/WindowSize;
			OldMeanA[index]=NewMeanA;
			OldVarianceA[index]=NewVarianceA;
			Variance = NewVarianceA;
		}
		break;
	}
  //Variance=sqrt(NewVariance);
}
if(Variance>=100)
  return Variance;
else
	return 64010;
//return distance;
}
