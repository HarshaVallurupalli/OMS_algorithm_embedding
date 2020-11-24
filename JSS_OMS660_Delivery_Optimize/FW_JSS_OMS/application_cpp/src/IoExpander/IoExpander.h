/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup io_expander IO Expander
 *
 * @brief Handles the communication with the IO expander on the OMS.
 *
 * @{
 */
#ifndef IO_EXPANDER_H_
#define IO_EXPANDER_H_

#include <stdint.h>
#include "hal/i2c_IF.h"

//! IO Expander
/*!
 * Handles the communication with the IO expander on the OMS.
 */
class IoExpander
{
	public:
		IoExpander(i2c_IF &i2c);
		int8_t test(const bool testPowerSupply);
		int8_t testFlash();
		int8_t readFlash(const uint32_t flashAddress, uint8_t *data, const uint32_t size);
		int8_t writeFlash(const uint32_t flashAddress, const uint8_t *data, const uint32_t size);
		int8_t startCalcCrc(const uint32_t size);
		int8_t startDeleteFlash();
		int8_t waitBlockingFlashBusy();
		bool getFlashBusy();
		uint32_t getCalibrationCrc() const;
		int8_t setLedPattern(const uint8_t pattern);
		uint32_t getFirmwareRelease() const;

	private:
		 i2c_IF &i2c;
		 uint16_t deviceAddress;
};

#endif /* IO_EXPANDER_H_ */

/** @} */
