/***
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @addtogroup edge_filter
 */
#include "MovementDetectionAlgorithm.h"
#include <stdlib.h>

/**
 * @brief Constructor
 *
 */
MovementDetectionAlgorithm::MovementDetectionAlgorithm()
{
	width = 320;
	height = 240;
	WindowSize = DEFAULT_WINDOW_SIZE;
    for(int i = 0; i < 76800; i++)
    {
        OldMean[i] = 0;
    	OldVariance[i]=0;
    }
}


void MovementDetectionAlgorithm::setWindowSize(const uint16_t WindowSize)
{
	this->WindowSize = WindowSize;
}


bool MovementDetectionAlgorithm::isEnabled() const
{
	if (WindowSize == 0)
	{
		return false;
	}

	return true;
}


uint16_t MovementDetectionAlgorithm::calcPixelValue(const uint16_t distance,uint32_t index)
{
	uint16_t NewMean;
	uint16_t NewVariance;
if(index < 	width*height)
{ NewMean= (((WindowSize-1)*OldMean[index])+ distance)/WindowSize;
  NewVariance=(((WindowSize-1)*OldVariance[index]) + (distance-NewMean)^2)/WindowSize;
  OldMean[index]=NewMean;
  OldVariance[index]=NewVariance;
}
if(NewVariance>=300)
  return NewVariance;
else
	return 640010;
//return distance;
}
