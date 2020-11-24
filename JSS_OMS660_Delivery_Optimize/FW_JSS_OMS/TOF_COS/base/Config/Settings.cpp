/***
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @addtogroup settings
 */
#include "Settings.h"

/**
 * @brief Constructor
 *
 */
Settings::Settings()
{
  changed = true;
}

/**
 * @brief Read if the settings have changed
 *
 * @retval true Settings have changed
 * @retval false Settings not changed
 * @return Settings changed or not
 */
bool Settings::hasChanged()
{
	bool returnValue = changed;
	changed = false;
	return returnValue;
}

/**
 * @brief Set changed
 *
 * Mark the settings as changed so they need to be reloaded to the tof imager.
 */
void Settings::setChanged()
{
	changed = true;
}

/** @} */
