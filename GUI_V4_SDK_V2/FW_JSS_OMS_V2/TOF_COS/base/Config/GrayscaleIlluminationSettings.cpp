/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 *
 * @addtogroup grayscale_illumination_settings
 *
 * @{
 */
#include <Config/GrayscaleIlluminationSettings.h>

/**
 * @brief Constructor
 *
 */
GrayscaleIlluminationSettings::GrayscaleIlluminationSettings()
{
  enabled = false;
}

/**
 * @brief Set enabled
 *
 * @param enabled Illumination on during grayscale acquisition if true
 */
void GrayscaleIlluminationSettings::setEnabled(const bool enabled)
{
  changed = true;
  this->enabled = enabled;
}

/**
 * @brief Get enabled
 *
 * @return Illumination on during grayscale acquisition if true
 */
bool GrayscaleIlluminationSettings::getEnabled() const
{
  return enabled;
}

/** @} */
