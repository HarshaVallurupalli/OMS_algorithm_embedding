/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup settings Settings helper class
 * @ingroup config
 * @brief Helper class for settings with build-in detection of settings changed
 *
 * @{
 */
#ifndef SETTINGS_H_
#define SETTINGS_H_

//! Settings
/*!
 * Helper class for settings with build-in detection of settings changed
 */
class Settings
{
	public:
		Settings();
		bool hasChanged();
		void setChanged();

	protected:
		bool changed;
};

#endif /* SETTINGS_H_ */

/** @} */
