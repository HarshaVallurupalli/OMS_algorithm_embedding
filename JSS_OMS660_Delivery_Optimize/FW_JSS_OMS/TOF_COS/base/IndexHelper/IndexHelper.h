/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @defgroup index_helper Index Helper
 * @brief Index Helper Class
 * @ingroup calculation
 *
 * This class helps to calculate indexes or coordinates.
 *
 * @{
 */
#ifndef INDEX_HELPER_H_
#define INDEX_HELPER_H_

#include <stdint.h>
#include "Binning/Binning.h"
#include "Roi/Roi.h"

//! Index Helper Class
/*!
 * This class helps to calculate indexes or coordinates.
 */
class IndexHelper
{
	public:
		IndexHelper();
		void setBaseSettings(const Roi roi, const Binning binning);
		void start(const Roi &roi, const Binning &binning);
		uint32_t getNextIndex();
		void indexToCoordinates(const uint32_t index, uint16_t &x, uint16_t &y);
		uint32_t subIndexToIndex(const Roi &roi, const Binning &binning, uint32_t subIndex);
		uint32_t indexToSubIndex(const Roi &roi, const Binning &binning, uint32_t index);

	private:
		uint16_t width;
		uint16_t heigth;
		uint32_t rowIndex;
		uint32_t indexResult;
		uint32_t rowInc;
		uint32_t rowBreak;
		Roi baseRoi;
		Binning baseBinning;
};

#endif /* INDEX_HELPER_H_ */

/** @} */
