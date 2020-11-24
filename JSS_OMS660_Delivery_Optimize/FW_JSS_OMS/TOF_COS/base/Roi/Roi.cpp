/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 *
 * @addtogroup roi
 *
 * @{
 */
#include "Roi.h"

/**
 * @brief Constructor without arguments
 *
 */
Roi::Roi()
{
  xMin = 0;
  yMin = 0;
  xMax = 0;
  yMax = 0;
}

/**
 * @brief Constructor with ROI parameters
 *
 * @param xMin X start point
 * @param yMin Y start point
 * @param width Width of the ROI in pixels
 * @param height Height of the ROI in pixels
 */
Roi::Roi(const uint16_t xMin, const uint16_t yMin, const uint16_t width, const uint16_t height)
{
  this->xMin = xMin;
	this->yMin = yMin;
	this->xMax = this->xMin + width - 1;
	this->yMax = this->yMin + height - 1;
}

/**
 * @brief Get the number of pixels
 *
 * This function returns the number of pixels of the current ROI.
 * This class only handles the ROI, binning is not taken into account.
 *
 * @return Number of pixels
 */
uint32_t Roi::getNumPixel() const
{
  return (getWidth() * getHeight());
}

/**
 * @brief Get the width
 *
 * This function returns the width of the current ROI.
 * This class only handles the ROI, binning is not taken into account.
 *
 * @return Width in pixels
 */
uint16_t Roi::getWidth() const
{
  return (xMax - xMin + 1);
}

/**
 * @brief Get the height
 *
 * This function returns the height of the current ROI.
 * This class only handles the ROI, binning is not taken into account.
 *
 * @return Height in pixels
 */
uint16_t Roi::getHeight() const
{
  return (yMax - yMin + 1);
}

/**
 * @brief Operator ==
 *
 * Useful to compare the ROI settings with another ROI settings.
 *
 * @param lhs Other ROI
 * @retval true ROI settings equal
 * @retval false ROI settings not equal
 * @return ROI settings equal or not
 */
bool Roi::operator ==(const Roi& lhs)
{
  bool equal = ((lhs.xMin == this->xMin) &&
	  		  		  (lhs.yMin == this->yMin) &&
	  						(lhs.xMax == this->xMax) &&
	              (lhs.yMax == this->yMax));

  return equal;
}

/**
 * @brief sub ROI
 *
 * Needed in this case:
 * - The whole image is defined by a ROI, e.g. xMin = 10, yMin = 5 at calibration time
 * - At runtime the ROI relative to the whole image is needed, so xMin --> 0, yMin --> 0
 *
 * @param roi Current ROI settings of the sensor
 * @return ROI
 */
Roi Roi::getSubRoi(const Roi &roi)
{
  Roi newRoi = roi;
	int16_t xMinDiff = roi.xMin - xMin;
  int16_t yMinDiff = roi.yMin - yMin;

  if ((xMinDiff >= 0) &&
			(yMinDiff >= 0))
  {
  	newRoi.xMin = xMinDiff;
  	newRoi.yMin = yMinDiff;
  	newRoi.xMax = newRoi.xMin + roi.getWidth() - 1;
  	newRoi.yMax = newRoi.yMin + roi.getHeight() - 1;
  }

  return newRoi;
}

/** @} */
