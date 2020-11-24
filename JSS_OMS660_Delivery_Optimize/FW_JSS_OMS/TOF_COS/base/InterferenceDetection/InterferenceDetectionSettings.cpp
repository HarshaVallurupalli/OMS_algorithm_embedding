/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 *
 * @addtogroup interference_detection_settings
 *
 * @{
 */
#include "InterferenceDetectionSettings.h"

/**
 * @brief Constructor without parameters
 */
InterferenceDetectionSettings::InterferenceDetectionSettings()
{
  this->enabled = DEFAULT_ENABLED;
  this->limit = DEFAULT_LIMIT;
  this->useLastValue = DEFAULT_USE_LAST_VALUE_ENABLED;
}

/**
 * @brief Constructor with parameters
 *
 * @param enabled Interference detection enabled/disabled
 * @param useLastValue Use last value in case of interference
 * @param limit Limit to mark pixels as interfered
 */
InterferenceDetectionSettings::InterferenceDetectionSettings(const bool enabled, const bool useLastValue, const int32_t limit)
{
	this->enabled = enabled;
	this->useLastValue = useLastValue;
	this->limit = limit;
}

/**
 * @brief Constructor with parameters
 *
 * If the limit is zero, the interference detection is switched off.
 *
 * @param useLastValue Use last value in case of interference
 * @param limit Limit to mark pixels as interfered
 */
InterferenceDetectionSettings::InterferenceDetectionSettings(const bool useLastValue, const int32_t limit)
{
	if (limit == 0)
	{
		this->enabled = false;
	}
	else
	{
		this->enabled = true;
	}
  this->useLastValue = useLastValue;
	this->limit = limit;
}
