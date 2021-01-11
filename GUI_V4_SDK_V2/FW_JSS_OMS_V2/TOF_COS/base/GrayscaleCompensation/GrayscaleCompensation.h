/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @defgroup grayscale_compensation Grayscale compensation
 * @brief Compensates the Grayscale DSNU (Dark Signal Non Uniformity) and PRNU (Photo Response Non Uniformity)
 * @ingroup tof_cos
 *
 *
 * Here on the FPGA system no calculations are done in software, just the FPGA is loaded with the calibration data.
 *
 * @{
 */
#ifndef GRAYSCALE_COMPENSATION_H_
#define GRAYSCALE_COMPENSATION_H_

#include <stdint.h>
#include "ChipSelection.h"

//! Compensate Grayscale
/*!
 * This class is responsible to compensate the Grayscale DSNU (Dark Signal Non Uniformity) and PRNU (Photo Response Non Uniformity). Here on the FPGA
 * system it is only responsible to configure the soft logic.
 */
class GrayscaleCompensation
{
	public:
		GrayscaleCompensation();
		void setCalibrationAddress(const uint32_t address);
		uint32_t *getCalibrationAddress() const;
		uint32_t calcCorrectedGrayscale(const uint32_t grayscale, const uint32_t pixelIndex);

	private:
	  uint32_t *pCalibrationData;                                                 ///<Pointer to the calibration data
	  uint32_t grayscaleTable[WIDTH * HEIGTH] __attribute__ ((aligned (64)));     ///<LUT memory. Important is the alignment. It will not work without it
};

#endif /* GRAYSCALE_COMPENSATION_H_ */

/** @} */
