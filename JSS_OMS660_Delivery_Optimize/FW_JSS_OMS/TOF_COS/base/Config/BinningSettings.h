/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup binning_settings Binning Settings
 * @ingroup config
 * @brief Contains the settings for the binning
 *
 * @{
 */
#ifndef BINNING_SETTINGS_H_
#define BINNING_SETTINGS_H_

#include <stdint.h>
#include "Settings.h"
#include "Roi/Roi.h"
#include "Binning/Binning.h"
#include "TOF_COS_Config.h"

//! Binning Settings
/*!
 * This class handles the binning settings. It can contain multiple settings for example for different illuminations or calibrations.
 */
class BinningSettings: public Settings
{
	public:
		BinningSettings();
		void setBinning(const Binning binning, const uint8_t index);
		void selectBinning(const uint8_t index);
		Binning getBinning() const;
		uint16_t getBinnedWidth(const uint16_t sensorWidth) const;
		uint16_t getBinnedHeight(const uint16_t sensorHeight) const;

	private:
		Binning binning[TOF_COS_NUM_SETTINGS];
		uint8_t index;
};

#endif /* BINNING_SETTINGS_H_ */

/** @} */
