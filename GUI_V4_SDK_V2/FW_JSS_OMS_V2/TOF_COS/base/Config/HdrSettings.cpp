/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 *
 * @addtogroup hdr_settings
 *
 * @{
 */
#include <Config/HdrSettings.h>

/**
 * @brief Set the HDR settings
 *
 * @param hdr Hdr settings to set
 */
void HdrSettings::setHdr(const Hdr hdr)
{
  changed = true;
  this->hdr = hdr;
}

/**
 * @brief Get the HDR settings
 *
 * @return Current HDR settings
 */
Hdr HdrSettings::getHdr() const
{
	return hdr;
}

/** @} */
