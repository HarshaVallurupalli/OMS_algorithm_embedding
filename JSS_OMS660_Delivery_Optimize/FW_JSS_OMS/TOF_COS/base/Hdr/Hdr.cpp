/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 *
 * @addtogroup hdr
 *
 * @{
 */
#include "Hdr.h"

/**
 * @brief Constructor default
 *
 */
Hdr::Hdr()
{
  this->mode = Hdr::HdrMode_e::HDR_MODE_NONE;
}

/**
 * @brief Constructor with parameter
 *
 * @param hdr HDR mode to set
 */
Hdr::Hdr(const Hdr::HdrMode_e hdr)
{
  this->mode = hdr;
}

/**
 * @brief Operator =
 *
 * @param hdr HDR mode to set
 * @return Reference to this
 */
Hdr &Hdr::operator=(const Hdr::HdrMode_e hdr)
{
	this->mode = hdr;

	return *this;
}

/**
 * @brief Read, if temporal HDR is enabled
 *
 * @retval true Temporal HDR is enabled
 * @retval false Temporal HDR is disabled
 * @return Temporal HDR enabled or not
 */
bool Hdr::isTemporalHdr() const
{
	if (mode == HdrMode_e::HDR_MODE_TEMPORAL)
	{
	  return true;
	}

	return false;
}

/**
 * @brief Read, if spatial HDR is enabled
 *
 * @retval true Spatial HDR is enabled
 * @retval false Spatial HDR is disabled
 * @return Spatial HDR enabled or not
 */
bool Hdr::isSpatialHdr() const
{
	if (mode == HdrMode_e::HDR_MODE_SPATIAL)
	{
	  return true;
	}

	return false;
}

/**
 * @brief Read the HDR mode
 *
 * @return Current HDR mode
 */
Hdr::HdrMode_e Hdr::getValue() const
{
	return mode;
}

/** @} */
