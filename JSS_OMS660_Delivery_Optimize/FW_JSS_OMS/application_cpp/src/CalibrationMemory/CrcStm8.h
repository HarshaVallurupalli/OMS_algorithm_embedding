/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup crc_stm8 CRC Calculation
 *
 * @brief Calculates the CRC like the HW CRC on the SPI of the STM8.
 *
 * @{
 */
#ifndef CRC_STM8_H_
#define CRC_STM8_H_

#include <stdint.h>

//! CRC Calculation
/*!
 * Calculates the CRC like the HW CRC on the SPI of the STM8.
 */
class CrcStm8
{
	public:
		static uint8_t calcCrc(const uint8_t *data, const uint32_t size);

	private:
		static uint8_t crcSoftwareFunction(uint8_t Initial_Crc, uint8_t Input_Data);
};

#endif /* CRC_STM8_H_ */

/** @} */
