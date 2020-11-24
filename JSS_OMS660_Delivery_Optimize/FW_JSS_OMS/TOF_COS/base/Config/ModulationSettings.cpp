/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 *
 * @addtogroup modulation_settings
 *
 * @{
 */
#include <Config/ModulationSettings.h>

/**
 * @brief Constructor
 *
 */
ModulationSettings::ModulationSettings()
{
  index = 0;

	for (uint8_t i = 0; i < TOF_COS_NUM_SETTINGS; i++)
  {
	  modulation[i] = Modulation::MODULATION_10MHZ;
  }
}

/**
 * @brief Set modulation
 *
 * Sets the modulation of the given settings index
 *
 * @param modulation Modulation to set
 * @param index Index of the settings to set
 */
void ModulationSettings::setModulation(const Modulation modulation, const uint8_t index)
{
	if (index >= TOF_COS_NUM_SETTINGS)
	{
    return;
	}

	changed = true;
	this->modulation[index] = modulation;
}

/**
 * @brief Get modulation of index
 *
 * @param index Index of the settings to get
 * @return modulation
 */
Modulation ModulationSettings::getModulation(const uint8_t index) const
{
	return modulation[index];
}

/**
 * @brief Get modulation
 *
 * @return modulation
 */
Modulation ModulationSettings::getModulation() const
{
	return modulation[index];
}

/**
 * @brief Select modulation of given settings index
 *
 * @param index Index of settings to select
 */
void ModulationSettings::selectModulation(const uint8_t index)
{
  if (index >= TOF_COS_NUM_SETTINGS)
	{
	  return;
	}

	if (this->index != index)
	{
	  this->index = index;
	  changed = true;
	}
}

/** @} */
