/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @addtogroup index_helper
 *
 * @{
 */
#include <IndexHelper/IndexCoordinatesHelper.h>
#include <IndexHelper/IndexHelper.h>

/**
 * @brief Constructor
 *
 */
IndexHelper::IndexHelper()
{
  width = 0;
  heigth = 0;
  rowIndex = 0;
  indexResult = 0;
  rowInc = 0;
  rowBreak = 0;
}

///**
// * @brief Set width
// *
// * Set the width of the whole image, e.g. calibration data
// *
// * param width Width of the image
// */
//void IndexHelper::setWidth(const uint32_t width)
//{
//	this->width = width;
//}
//
///**
// * @brief Set height
// *
// * Set the height of the whole image, e.g. calibration data
// *
// * param height Height of the image
// */
//void IndexHelper::setHeigth(const uint32_t heigth)
//{
//	this->heigth = heigth;
//}

void IndexHelper::setBaseSettings(const Roi roi, const Binning binning)
{
	this->baseRoi = roi;
	this->baseBinning = binning;
	this->width = binning.getBinnedWidth(roi.getWidth());
	this->heigth = binning.getBinnedHeight(roi.getHeight());
}

uint32_t IndexHelper::subIndexToIndex(const Roi &roi, const Binning &binning, uint32_t subIndex)
{
	uint16_t realImageWidth = binning.getBinnedWidth(roi.getWidth());
	uint16_t xMax = roi.xMin + realImageWidth - 1;
	uint16_t y = subIndex / realImageWidth;
	uint32_t x = subIndex - (y * realImageWidth);

	uint16_t cutOffLeft = roi.xMin;
	uint16_t cutOffRight = width - xMax - 1;

	uint32_t indexOffset = cutOffLeft + y * (cutOffLeft + cutOffRight);

	uint32_t finalIndex = subIndex + indexOffset;

	return finalIndex;
}

uint32_t IndexHelper::indexToSubIndex(const Roi &roi, const Binning &binning, uint32_t index)
{
	uint16_t realImageWidth = binning.getBinnedWidth(roi.getWidth());
	uint16_t xMax = roi.xMin + realImageWidth - 1;
	uint16_t y = index / width;
	uint16_t x = index - (y * width);

	uint16_t cutOffLeft = roi.xMin;
	uint16_t cutOffRight = width - xMax - 1;

	uint32_t indexOffset = cutOffLeft + y * (cutOffLeft + cutOffRight);

	uint32_t finalIndex = index - indexOffset;

	return finalIndex;
}

/**
 * @brief Start an image
 *
 * Call this function before reading the indexes with "getNextIndex".
 *
 * @param roi Roi settings
 * @param binning Binning settings
 */
void IndexHelper::start(const Roi &roi, const Binning &binning)
{
	Roi subRoi = this->baseRoi.getSubRoi(roi);

	rowIndex = 0;
	uint16_t yMax = subRoi.yMin + binning.getBinnedHeight(subRoi.getHeight()) - 1;
	indexResult = ((heigth - yMax - 1) * width) + subRoi.xMin;
	rowInc = width - binning.getBinnedWidth(subRoi.getWidth());
	rowBreak = binning.getBinnedWidth(subRoi.getWidth());
}

/**
 * @brief Get the next index
 *
 * Get the next index. This is used, if the whole sensor is calibrated but only a ROI is needed at runtime.
 * So the index of the calibration data does not match the index of the image data.
 *
 * At the beginning of the image call function "start".
 *
 * @return Next index
 */
uint32_t IndexHelper::getNextIndex()
{
  uint32_t indexToReturn = indexResult;

	rowIndex++;
  indexResult++;

  if (rowIndex >= rowBreak)
  {
    rowIndex = 0;
  	indexResult += rowInc;
  }

  return indexToReturn;
}

/** @} */
