/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup drnu_compensation DRNU compensation
 * @brief Compensation the DRNU (Distance Response Non Uniformity)
 * @ingroup tof_cos
 *
 * @{
 */
#ifndef DRNU_COMPENSATION_H_
#define DRNU_COMPENSATION_H_

#include <stdint.h>
#include "ChipSelection.h"

//! Compensate DRNU
/*!
 * This class is responsible to compensate the DRNU. Here on the FPGA system it only configures the FPGA. The
 * compensation itself is done in the soft logic.
 */
class DrnuCompensation
{
	public:
		DrnuCompensation();
		void setCalibrationAddress(const uint32_t address);
		void update();
		void loadFpga();
		int32_t getOffset() const;
		void setVerificationModeEnabled(const bool verificationMode);

	protected:
		uint32_t calibrationAddress;                                              ///<Stores the address of the calibration data (whole data inclusive the header)
		int32_t atanOffset;                                                       ///<Offset for the atan calculation
		uint32_t dllStepDistance;                                                 ///<Distance from step to step
		uint32_t numDllStepsFpga;                                                 ///<Number of DLL steps used in the FPGA. This must be a multiplier of 4 and therefore might be different than the really calibrated number of steps
		int32_t distanceRange;                                                    ///<Distance range for the selected modulation frequency
    bool offsetOnly;                                                          ///<true if only the offset is calibrated
    int32_t offset;

	private:
		void fillTable(class DrnuCalibrationDataHelper &drnuCalibrationDataHelper);
		void addValue(const uint32_t pixelIndex, const uint8_t dllStep, const uint8_t numDllSteps, const uint32_t distance);

		uint16_t drnuTable[WIDTH * HEIGTH * 50] __attribute__ ((aligned (64)));        ///<LUT memory. Important is the alignment. It will not work without it.
		static bool verificationMode;                                             ///<In verification mode not offset is added to the result. This variable is static because it is the same for all instances.
};

#endif /* DRNU_COMPENSATION_H_ */
