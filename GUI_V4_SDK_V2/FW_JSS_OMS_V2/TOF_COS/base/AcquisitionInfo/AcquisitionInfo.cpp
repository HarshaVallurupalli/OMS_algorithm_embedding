/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 *
 * @addtogroup acquisition_info
 *
 * @{
 */
#include <AcquisitionInfo/AcquisitionInfo.h>

/**
 * @brief Get number of pixels that get read from the sensor
 *
 * This takes into account ROI and binning settings.
 *
 * @return Number of pixels read from the sensor
 */
uint32_t AcquisitionInfo::getNumPixel() const
{
	return (getWidth() * getHeight());
}

/**
 * @brief Get number of pixels in the final data
 *
 * The number of pixels may change during the calculation if HDR is used because
 * two rows get combined to one. This function returns the final number of pixels
 * after processing the HDR.
 *
 * @return Number of pixels in the resulting data
 */
uint32_t AcquisitionInfo::getFinalNumPixel() const
{
	return (getWidth() * getFinalHeight());
}

/**
 * @brief Get x min coordinate
 *
 * @return X min coordinate
 */
uint16_t AcquisitionInfo::getXMin() const
{
  return roi.xMin;
}

/**
 * @brief Get x max coordinate
 *
 * @return X max coordinate
 */
uint16_t AcquisitionInfo::getXMax() const
{
	return roi.xMin + getWidth() - 1;
}

/**
 * @brief Get y min coordinate
 *
 * @return Y min coordinate
 */
uint16_t AcquisitionInfo::getYMin() const
{
  return roi.yMin;
}

/**
 * @brief Get y max coordinate
 *
 * @return Y max coordinate
 */
uint16_t AcquisitionInfo::getYMax() const
{
	return roi.yMin + getHeight() - 1;
}

/**
 * @brief Get image width read from sensor
 *
 * This takes into account ROI and binning settings.
 *
 * @return Width of the image read from the sensor
 */
uint16_t AcquisitionInfo::getWidth() const
{
  return binning.getBinnedWidth(roi.getWidth());
}

/**
 * @brief Get image height read from sensor
 *
 * This takes into account ROI and binning settings.
 *
 * @return Height of the image read from the sensor
 */
uint16_t AcquisitionInfo::getHeight() const
{
  return binning.getBinnedHeight(roi.getHeight());
}

/**
 * @brief Get image height in the final data
 *
 * The height of the image may change during the calculation if HDR is used because
 * two rows get combined to one. This function returns the final height after processing the HDR.
 *
 * @return Height of the image in the resulting data
 */
uint16_t AcquisitionInfo::getFinalHeight() const
{
	if (hdr.isSpatialHdr())
	{
		return getHeight() / 2;
	}
	else
	{
		return getHeight();
	}
}

/** @} */
