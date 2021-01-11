#ifndef SKELETON_DETECTION_ALGORITHM_
#define SKELETON_DETECTION_ALGORITHM_

#include "Pixel/PixelToFDistance.h"
#include "Pixel/PixelToFDistanceAmplitude.h"
#include "Pixel/PixelToFDistanceGrayscale.h"

class SkeletonDetectionAlgorithm
{
	public:
		SkeletonDetectionAlgorithm();
		bool isEnabled() const;
		uint16_t calcPixelValue(const uint32_t pixel_value,uint32_t index);

	private:
		bool enable;
};

#endif /* EDGE_FILTER_ */

/** @} */
