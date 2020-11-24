/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup roi_settings Settings ROI settings
 * @ingroup config
 * @brief Helper class for ROI settings
 *
 * @{
 */
#ifndef ROI_SETTINGS_H_
#define ROI_SETTINGS_H_

#include <stdint.h>
#include "Settings.h"
#include "Roi/Roi.h"
#include "TOF_COS_Config.h"

//! ROI settings
/*!
 * Handles different ROI settings and indicates, if the TOF imager needs to be reconfigured with ROI settings.
 */
class RoiSettings: public Settings
{
	public:
		RoiSettings();
		void setRoi(const Roi roi, const uint8_t index);
		void selectRoi(const uint8_t index);
		Roi getRoi() const;
		Roi getRoi(const uint32_t indexSettings) const;
		uint16_t getWidth() const;
		uint16_t getHeight() const;
		uint16_t getFullResolutionWidth() const;
		uint16_t getFullResolutionHeight() const;

	private:
		uint16_t limitValue(const uint16_t value, const uint16_t limit);
		uint16_t fitValues(uint16_t &min, uint16_t &max, const uint16_t maxValue, const uint16_t minRange);
		void setRoiInternal(const uint16_t roiXmin, const uint16_t roiYmin, const uint16_t roiXmax, const uint16_t roiYmax, const uint8_t index);
		uint16_t makeEven(const uint16_t value);

		Roi roi[TOF_COS_NUM_SETTINGS];
		uint8_t index;
};

#endif /* ROI_SETTINGS_H_ */
