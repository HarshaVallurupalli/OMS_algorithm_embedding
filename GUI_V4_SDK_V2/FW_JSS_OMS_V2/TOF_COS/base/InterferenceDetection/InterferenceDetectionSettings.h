/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup interference_detection Interference Detection
 * @defgroup interference_detection_settings Settings
 * @ingroup interference_detection
 * @brief Contains the settings for the interference detection
 *
 * @{
 */
#ifndef INTERFERENCE_DETECTION_SETTINGS_H_
#define INTERFERENCE_DETECTION_SETTINGS_H_

#include <stdint.h>

//! Interference Detection Settings
/*!
 * Contains the settings for the interference detection
 */
class InterferenceDetectionSettings
{
	public:
		InterferenceDetectionSettings();
		InterferenceDetectionSettings(const bool enabled, const bool useLastValue, const int32_t limit);
		InterferenceDetectionSettings(const bool useLastValue, const int32_t limit);
		bool enabled;
		bool useLastValue;
		int32_t limit;

	private:
		static const int32_t DEFAULT_LIMIT = 500;     ///<Default limit at startup
		static const bool DEFAULT_ENABLED = true;    ///<Default enabled at startup
		static const bool DEFAULT_USE_LAST_VALUE_ENABLED = true;
};

#endif /* INTERFERENCE_DETECTION_SETTINGS_H_ */

/** @} */
