/***
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @addtogroup temporal_filter_settings
 */
#include "TemporalFilterSettings.h"

/**
 * @brief Construction
 *
 * Default the filter is disabled
 */
TemporalFilterSettings::TemporalFilterSettings()
{
  threshold = TEMPORAL_FILTER_THRESHOLD_DEFAULT;
  factor = TEMPORAL_FILTER_FACTOR_DEFAULT;
}

/**
 * @brief Construction with initialization
 *
 * @param threshold Threshold for the temporal filter in mm
 * @param factor Factor of the temporal filter, 1..1000
 */
TemporalFilterSettings::TemporalFilterSettings(const uint16_t threshold, const uint16_t factor)
{
	this->threshold = threshold;
	this->factor = factor;
}

/** @} */
