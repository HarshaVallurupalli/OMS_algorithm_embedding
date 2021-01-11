/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @defgroup binning Binning
 * @brief Handle the binning settings
 * @ingroup tof_cos
 *
 * @{
 */
#ifndef BINNING_H_
#define BINNING_H_

#include <stdint.h>

//! Handle the binning settings
/*!
 * This class is responsible to handle the binning settings.
 */
class Binning
{
	public:
	  enum Binning_e
	  {
	    BINNING_NONE,
      BINNING_VERTICAL,
	    BINNING_HORIZONTAL,
      BINNING_VERTICAL_HORIZONTAL
	  };

	  Binning();
	  Binning(const Binning::Binning_e binning);
	  Binning &operator=(const Binning::Binning_e binning);
	  Binning::Binning_e getValue() const;
	  uint16_t getBinnedWidth(const uint16_t sensorWidth) const;
	  uint16_t getBinnedHeight(const uint16_t sensorHeight) const;
	  uint16_t getSensorRoiX(const uint16_t xRoiSetting) const;
	  uint16_t getSensorRoiY(const uint16_t yRoiSetting) const;

	private:
	  Binning::Binning_e binning;
};

#endif /* BINNING_H_ */

/** @} */
