/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @defgroup temporal_filter_settings Temporal filter settings
 * @brief Settings class for the temporal filter
 * @ingroup temporal_filter
 *
 * @{
 */
#ifndef MOVEMENT_DETECTION_SETTINGS_H_
#define MOVEMENT_DETECTION_SETTINGS_H_

#include <stdint.h>
#include "MovementDetectionAlgorithmContstants.h"

//! Temporal filter settings
/*!
 * This class contains the temporal filter settings and is used as parameter for the
 * temporal filter
 */
class MovementDetectionAlgorithmSettings
{
	public:
		MovementDetectionAlgorithmSettings();
		MovementDetectionAlgorithmSettings(const uint16_t WindowSize, const uint16_t ImageType);

	  uint32_t windowSize;
	  uint32_t imageType;
};

#endif
