/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup crc CRC
 * @brief CRC calculation
 * @ingroup tof_cos
 *
 *
 * @{
 */
#ifndef BASE_CRC_CRC_H_
#define BASE_CRC_CRC_H_

#include <stdint.h>

//! CRC calculation
/*!
 * Class for the CRC calculation in software (no hardware assistance)
 *
 * The calculation of CRC can be found on wikipedia. It is here implemented straight forward.
 */
class CRC
{
	public:
		static uint32_t calcCrc32(const uint8_t *data, const uint32_t size);
		static uint32_t startCrc32();
		static uint32_t accumulateCrc32(const uint8_t *data, const uint32_t size, const uint32_t currentCrc);
		static uint32_t finishCrc32(const uint32_t currentCrc);

	private:
		static uint32_t calcCrc32Byte(uint32_t crc, uint8_t byte);
};

#endif /* BASE_CRC_CRC_H_ */

/** @} */
