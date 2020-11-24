#ifndef MOVEMENT_DETECTION_ALGORITHM_
#define MOVEMENT_DETECTION_ALGORITHM_

#include "Pixel/PixelToFDistance.h"
#include "Pixel/PixelToFDistanceAmplitude.h"
#include "Pixel/PixelToFDistanceGrayscale.h"

class MovementDetectionAlgorithm
{
	public:
		MovementDetectionAlgorithm();
		void setWindowSize(const uint16_t WindowSize);
		bool isEnabled() const;
		uint16_t calcPixelValue(const uint16_t distance,uint32_t index);

	private:
		const int32_t DEFAULT_WINDOW_SIZE = 4;

	  int32_t OldMean[76800];
	  int32_t OldVariance[76800];
	  uint8_t WindowSize;
	  uint16_t width;                     ///<Width of the image in pixels
	  uint16_t height;                    ///<Height of the image in pixels

};

#endif /* EDGE_FILTER_ */

/** @} */
