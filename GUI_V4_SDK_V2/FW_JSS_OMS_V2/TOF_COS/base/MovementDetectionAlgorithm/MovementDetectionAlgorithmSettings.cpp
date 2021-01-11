/***
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @addtogroup temporal_filter_settings
 */
#include <MovementDetectionAlgorithm/MovementDetectionAlgorithmSettings.h>

/**
 * @brief Construction
 *
 * Default the filter is disabled
 */
MovementDetectionAlgorithmSettings::MovementDetectionAlgorithmSettings()
{
  windowSize = DEFAULT_WINDOW_SIZE;
  imageType = DEFAULT_IMAGE_TYPE;
}

/**
 * @brief Construction with initialization
 *
 * @param threshold Threshold for the temporal filter in mm
 * @param factor Factor of the temporal filter, 1..1000
 */
MovementDetectionAlgorithmSettings::MovementDetectionAlgorithmSettings(const uint16_t windowSize, const uint16_t imageType)
{
	this->windowSize = windowSize;
	this->imageType = imageType;
}

/** @} */
