/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup drnu_calibration DRNU Calibration
 * @ingroup calibration
 * @brief DRNU Calibration Class
 *
 * @{
 */
#ifndef DRNU_CALIBRATION_H_
#define DRNU_CALIBRATION_H_

#include "DrnuCalibrationTypes.h"
#include "DrnuCalibrationInfoData.h"
#include "TypeInternalReturnValue.h"

//! DRNU calibration class
/*!
 * Offers functions to store the DRNU calibration data.
 */
class DrnuCalibration
{
	public:
		DrnuCalibration();
		TypeInternalReturnValue setup(const uint32_t address);
		void setParameters(const int32_t distanceRange, const uint32_t multiplier, const uint32_t numPixel);
		TypeInternalReturnValue calibrateStep(const uint8_t *pDistance, const uint32_t setDistance, const uint32_t step);
		TypeInternalReturnValue storeHeader(const DrnuCalibrationInfoData &calibrationInfo);
		TypeInternalReturnValue checkErased();

	private:
		int8_t limitDiffToOneByte(const int32_t diff32);

		uint32_t numPixel;                            ///<[Pixel]Number of Pixels
		int32_t multiplier;                           ///<Multiplier used to multiply the distance error to be able to fit in one byte --> distanceErrorInFlash = distanceError / multiplier
		int32_t distanceRange;                        ///<Max. distance; wrap for the atan2
		uint32_t address;                             ///<Address of the calibration data
		uint32_t memorySize;                          ///<Size of the calibration data
};

#endif /* DRNU_CALIBRATION_H_ */

/** @} */
