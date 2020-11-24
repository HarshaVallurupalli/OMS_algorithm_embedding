/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 *
 * @addtogroup binning_settings
 *
 * @{
 */
#include <Config/BinningSettings.h>

/**
 * @brief Constructor
 *
 */
BinningSettings::BinningSettings()
{
  index = 0;

	for (uint8_t i = 0; i < TOF_COS_NUM_SETTINGS; i++)
  {
	  this->binning[i] = Binning::BINNING_NONE;
  }
}

/**
 * @brief Set bining settings of index
 *
 * @param binning Binning settings
 * @param index Index of the settings
 */
void BinningSettings::setBinning(const Binning binning, const uint8_t index)
{
	if (index >= TOF_COS_NUM_SETTINGS)
	{
	  return;
	}

	changed = true;
	this->binning[index] = binning;
}

/**
 * @brief Get binning settings
 *
 * Returns the binning settings of the current selection.
 *
 * @return Binning settings
 */
Binning BinningSettings::getBinning() const
{
	return binning[index];
}

/**
 * @brief Get binned width
 *
 * Returns the width when taking the binning into account.
 *
 * @param sensorWidth Current sensor width (without binning)
 */
uint16_t BinningSettings::getBinnedWidth(const uint16_t sensorWidth) const
{
	uint16_t binnedWidth = binning[index].getBinnedWidth(sensorWidth);

	return binnedWidth;
}

/**
 * @brief Get binned height
 *
 * Returns the height when taking the binning into account.
 *
 * @param sensorHeight Current sensor height (without binning)
 */
uint16_t BinningSettings::getBinnedHeight(const uint16_t sensorHeight) const
{
  uint16_t binnedHeight = binning[index].getBinnedHeight(sensorHeight);

  return binnedHeight;
}

/**
 * @brief Select binning
 *
 * Select the settings for the binning. This just switches the index.
 *
 * @param index Index of the settings to select
 */
void BinningSettings::selectBinning(const uint8_t index)
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
