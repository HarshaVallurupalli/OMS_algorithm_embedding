/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup grayscale_illumination_settings Grayscale Illumination Settings
 * @ingroup config
 * @brief Contains the settings for the illumination during grayscale acquisition
 *
 * @{
 */
#ifndef GRAYSCALE_ILLUMINATION_SETTINGS_H_
#define GRAYSCALE_ILLUMINATION_SETTINGS_H_

#include "Settings.h"

//! Grayscale Illumination Settings
/*!
 * This class contains the settings for the illumination during grayscale acquisition
 */
class GrayscaleIlluminationSettings: public Settings
{
  public:
    GrayscaleIlluminationSettings();
    void setEnabled(const bool enabled);
    bool getEnabled() const;

  private:
    bool enabled;
};

#endif /* GRAYSCALE_ILLUMINATION_SETTINGS_H_ */

/** @} */
