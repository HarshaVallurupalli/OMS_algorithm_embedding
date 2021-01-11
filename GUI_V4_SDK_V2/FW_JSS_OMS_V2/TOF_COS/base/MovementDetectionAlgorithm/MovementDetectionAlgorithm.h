#ifndef MOVEMENT_DETECTION_ALGORITHM_
#define MOVEMENT_DETECTION_ALGORITHM_

#include "Pixel/PixelToFDistance.h"
#include "Pixel/PixelToFDistanceAmplitude.h"
#include "Pixel/PixelToFDistanceGrayscale.h"
#include <MovementDetectionAlgorithm/MovementDetectionAlgorithmSettings.h>


class MovementDetectionAlgorithm
{
	public:
		MovementDetectionAlgorithm();
		void setSettings(const MovementDetectionAlgorithmSettings settings);
		MovementDetectionAlgorithmSettings getSettings() const;
		bool isEnabled() const;
		uint16_t calcPixelValue(const uint16_t amplitude, const uint16_t distance, uint32_t index);

	private:
	  int32_t OldMeanA[76800];
	  int32_t OldVarianceA[76800];
	  int32_t OldMeanD[76800];
	  int32_t OldVarianceD[76800];
	  uint8_t WindowSize;
	  uint8_t ImageType;
	  uint16_t width;                     ///<Width of the image in pixels
	  uint16_t height;                    ///<Height of the image in pixels

};

#endif


