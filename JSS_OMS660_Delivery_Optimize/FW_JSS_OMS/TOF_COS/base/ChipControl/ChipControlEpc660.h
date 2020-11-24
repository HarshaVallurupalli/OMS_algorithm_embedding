/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup chip_control_epc660 EPC660
 * @ingroup chip_control
 *
 * @brief Chip Control Implementation for EPC660
 *
 *
 * @{
 */
#ifndef CHIP_CONTROL_EPC660_H_
#define CHIP_CONTROL_EPC660_H_

#include "ChipControl/ChipControl.h"

//! ChipControl implementation for EPC660
/*!
 * This class is used to control the EPC660 chip.
 */
class ChipControlEpc660: public ChipControl
{
	public:
		using ChipControl::ChipControl;

		TypeInternalReturnValue initChip();
		int32_t readTemperature();
		void setRoi(const uint16_t xMin, const uint16_t yMin, const uint16_t xMax, const uint16_t yMax);
		void setMinimalRoi();

	private:
		void initRegistersSpecific();
		void setRegistersToTof();
		void setRegistersToGrayscale();

		int32_t temperatureCalibrationValue[4];            ///<Calibration value for the temperature, read from the chip
		uint8_t register0xDA;                              ///<Stores the register value at startup
		uint8_t register0xDC;                              ///<Stores the register value at startup
};

#endif /* CHIP_CONTROL_EPC660_H_ */

/** @} */
