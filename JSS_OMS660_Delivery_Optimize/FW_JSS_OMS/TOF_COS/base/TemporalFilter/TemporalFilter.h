/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @defgroup temporal_filter Temporal filter
 * @brief Temporal filter for the pixels.
 * @ingroup tof_cos
 *
 * @{
 */
#ifndef TEMPORALFILTER_H_
#define TEMPORALFILTER_H_

#include <stdint.h>
#include <TemporalFilter/TemporalFilterSettings.h>

//! Temporal filter
/*!
 * This filter filters the distance of each pixel dependent of the last distance of the pixel.
 * This reduces the noise. The filter is exponential smoothing and works like this:
 *
 * if (abs(actValue - lastValue) < threshold)
 * {
 *   filteredValue = (actValue * factor) + (lastValue * (1 - factor))
 * }
 *
 * Remark: In the code it is implemented with integers so this is not exactly the code.
 */
class TemporalFilter
{
	public:
		TemporalFilter();
		void setSettings(const TemporalFilterSettings settings);
		TemporalFilterSettings getSettings() const;
		bool isEnabled() const;
		uint32_t filter(const uint32_t actValue, const uint32_t lastValue);

	private:
		uint32_t factorActual;                     ///<Factor for the current value
		uint32_t factorLast;                       ///<Factor for the last value = (1 - factorActual)
		int32_t threshold;                         ///<Threshold: If the difference to the last distance is higher than this, do not filter
};

#endif /* TEMPORALFILTER_H_ */

/** @} */
