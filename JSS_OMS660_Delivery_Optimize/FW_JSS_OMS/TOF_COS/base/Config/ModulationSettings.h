/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup modulation Modulation Settings
 * @ingroup config
 * @brief Contains the current modulation settings
 *
 * @{
 */
#ifndef MODULATION_SETTINGS_H_
#define MODULATION_SETTINGS_H_

#include <stdint.h>
#include "Modulation/Modulation.h"
#include "Settings.h"
#include "TOF_COS_Config.h"

//! Modulation Settings
/*!
 * This class contains the current modulation settings
 */
class ModulationSettings: public Settings
{
	public:
		ModulationSettings();
		void setModulation(const Modulation modulation, const uint8_t index);
		void selectModulation(const uint8_t index);
		Modulation getModulation() const;
		Modulation getModulation(const uint8_t index) const;

	private:
		Modulation modulation[TOF_COS_NUM_SETTINGS];     ///<Stores the modulation type
		uint8_t index;                                  ///<Current selected settings index
};

#endif /* MODULATION_SETTINGS_H_ */

/** @} */
