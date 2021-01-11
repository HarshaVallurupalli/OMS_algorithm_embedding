/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @defgroup temporal_filter_settings Temporal filter settings
 * @brief Settings class for the temporal filter
 * @ingroup temporal_filter
 *
 * @{
 */
#ifndef TEMPORAL_FILTER_SETTINGS_H_
#define TEMPORAL_FILTER_SETTINGS_H_

#include <stdint.h>
#include "TemporalFilterContstants.h"

//! Temporal filter settings
/*!
 * This class contains the temporal filter settings and is used as parameter for the
 * temporal filter
 */
class TemporalFilterSettings
{
	public:
		TemporalFilterSettings();
		TemporalFilterSettings(const uint16_t threshold, const uint16_t factor);

	  uint32_t threshold;                       ///<Temporal filter threshold
	  uint32_t factor;                          ///<Temporal filter factor
};

#endif /* TEMPORAL_FILTER_SETTINGS_H_ */

/** @} */
