/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @defgroup temporal_edge_filter Temporal Edge Filter
 * @brief Temporal edge filter for the pixels.
 * @ingroup tof_cos
 *
 * @{
 */
#ifndef TEMPORAL_EDGE_FILTER_H_
#define TEMPORAL_EDGE_FILTER_H_

#include <stdint.h>
#include "ChipSelection.h"

//! Temporal Edge Filter
/*!
 * This filter removes pixels which have a too high change between the current image and the last image.
 */
class TemporalEdgeFilter
{
	public:
		TemporalEdgeFilter();
		void setThreshold(const uint32_t thresholdLow, const uint32_t thresholdHigh);
		uint32_t filter(const uint32_t distance, const uint32_t lastDistance, const uint32_t pixelIndex);
		bool isEnabled() const;

	private:
		uint16_t lastDistanceBuffer[NUM_PIXEL];
		int32_t thresholdLow;
		int32_t thresholdHigh;
};

#endif /* TEMPORAL_EDGE_FILTER_H_ */

/** @} */
