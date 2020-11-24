/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup hdr_settings HDR Settings
 * @ingroup config
 * @brief Contains the settings for the HDR
 *
 * @{
 */
#ifndef HDR_SETTINGS_H_
#define HDR_SETTINGS_H_

#include "Hdr/Hdr.h"
#include "Settings.h"

//! HDR Settings
/*!
 * This class handles the HDR settings.
 */
class HdrSettings: public Settings
{
	public:
		void setHdr(const Hdr hdr);
		Hdr getHdr() const;

	private:
		Hdr hdr;                                ///<HDR settings
};

#endif /* HDR_SETTINGS_H_ */

/** @} */
