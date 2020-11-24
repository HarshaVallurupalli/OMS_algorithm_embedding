/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 *
 * @addtogroup binning
 *
 * @{
 */
#include "Binning.h"

/**
 * @brief Constructor without arguments
 *
 */
Binning::Binning(): binning(Binning::Binning_e::BINNING_NONE)
{
}

/**
 * @brief Constructor with arguments
 *
 * @param binning Binning enum to set
 */
Binning::Binning(const Binning::Binning_e binning): binning(binning)
{
}

/**
 * @brief Operator =
 *
 * @param binning Binning enum to set
 * @return Reference to this
 */
Binning &Binning::operator=(const Binning::Binning_e binning)
{
  this->binning = binning;

  return *this;
}

/**
 * @brief Get the binning value (enum)
 *
 * This function returns the binning enum defining the used binning.
 *
 * @return Value from Binning_e
 */
Binning::Binning_e Binning::getValue() const
{
	return binning;
}

/**
 * @brief Get the resulting image width
 *
 * This function returns the resulting width when the binning is taken into account.
 *
 * @param sensorWidth Width in pixels of the image without binning but with ROI taken into account
 * @return Resulting image width in pixels
 */
uint16_t Binning::getBinnedWidth(const uint16_t sensorWidth) const
{
	uint16_t binnedWidth = sensorWidth;

	switch (binning)
	{
	  case Binning::Binning_e::BINNING_NONE:
	  	binnedWidth = sensorWidth;
		  break;
	  case Binning::Binning_e::BINNING_VERTICAL:
	  	binnedWidth = sensorWidth;
		  break;
	  case Binning::Binning_e::BINNING_HORIZONTAL:
	  	binnedWidth = sensorWidth / 2;
		  break;
	  case Binning::Binning_e::BINNING_VERTICAL_HORIZONTAL:
	  	binnedWidth = sensorWidth / 2;
		  break;
	  default:
	  	break;
	}

	return binnedWidth;
}

/**
 * @brief Get the resulting image height
 *
 * This function returns the resulting height when the binning is taken into account.
 *
 * @param sensorHeight Height in pixels of the image without binning but with ROI taken into account
 * @return Resulting image height in pixels
 */
uint16_t Binning::getBinnedHeight(const uint16_t sensorHeight) const
{
	uint16_t binnedHeight = sensorHeight;

	switch(binning)
	{
	  case Binning::Binning_e::BINNING_NONE:
	  	binnedHeight = sensorHeight;
	  	break;
	  case Binning::Binning_e::BINNING_VERTICAL:
	    binnedHeight = sensorHeight / 2;
	  	break;
	  case Binning::Binning_e::BINNING_HORIZONTAL:
	    binnedHeight = sensorHeight;
	  	break;
	  case Binning::Binning_e::BINNING_VERTICAL_HORIZONTAL:
	    binnedHeight = sensorHeight / 2;
	  	break;
	  default:
	  	break;
	}

  return binnedHeight;
}

/**
 * @brief Get the ROI x needed for the sensor
 *
 * If binning is on the ROI internally for the sensor is different than for the user
 * outside. For example 20 gets 40 internally when binning is on.
 *
 * @return ROI setting needed to configure the sensor
 */
uint16_t Binning::getSensorRoiX(const uint16_t xRoiSetting) const
{
  uint16_t sensorX = xRoiSetting;

  switch(binning)
  {
    case Binning::Binning_e::BINNING_NONE:
      sensorX = xRoiSetting;
      break;
    case Binning::Binning_e::BINNING_VERTICAL:
      sensorX = xRoiSetting;
      break;
    case Binning::Binning_e::BINNING_HORIZONTAL:
      sensorX = xRoiSetting * 2;
      break;
    case Binning::Binning_e::BINNING_VERTICAL_HORIZONTAL:
      sensorX = xRoiSetting * 2;
      break;
    default:
      break;
  }

  return sensorX;
}

/**
 * @brief Get the ROI y needed for the sensor
 *
 * If binning is on the ROI internally for the sensor is different than for the user
 * outside. For example 20 gets 40 internally when binning is on.
 *
 * @return ROI setting needed to configure the sensor
 */
uint16_t Binning::getSensorRoiY(const uint16_t yRoiSetting) const
{
  uint16_t sensorY = yRoiSetting;

  switch(binning)
  {
    case Binning::Binning_e::BINNING_NONE:
      sensorY = yRoiSetting;
      break;
    case Binning::Binning_e::BINNING_VERTICAL:
      sensorY = yRoiSetting * 2;
      break;
    case Binning::Binning_e::BINNING_HORIZONTAL:
      sensorY = yRoiSetting;
      break;
    case Binning::Binning_e::BINNING_VERTICAL_HORIZONTAL:
      sensorY = yRoiSetting * 2;
      break;
    default:
      break;
  }

  return sensorY;
}

/** @} */
