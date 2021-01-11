/***
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 */
#include "CRC.h"

///generator polynom
static const uint32_t polynom = 0xEDB88320;

/**
 * @brief Calculate CRC32 of a buffer
 *
 * This function calculates the CRC32 checksum for the given buffer.
 *
 * @param data Pointer to the data buffer
 * @param size Size of the data buffer in Bytes
 * @return CRC32 checksum
 */
uint32_t CRC::calcCrc32(const uint8_t *data, const uint32_t size)
{
	uint32_t crc = 0xffffffff;

	for(uint32_t i = 0; i < size; i++)
	{
		crc = calcCrc32Byte(crc, data[i]);
	}
	return crc ^ 0xffffffff;
}

/**
 * @brief Get the start value of the CRC
 *
 * Useful to accumulate CRC later
 *
 * @return CRC32 start value
 */
uint32_t CRC::startCrc32()
{
	uint32_t crc = 0xffffffff;

	return crc;
}

/**
 * @brief Accumulate CRC32 of a buffer
 *
 * This function accumulates the CRC32 checksum for the given buffer.
 *
 * @param data Pointer to the data buffer
 * @param size Size of the data buffer in Bytes
 * @param currentCrc Current CRC value
 * @return CRC32 checksum so far
 */
uint32_t CRC::accumulateCrc32(const uint8_t *data, const uint32_t size, const uint32_t currentCrc)
{
	uint32_t crc = currentCrc;

	for(uint32_t i = 0; i < size; i++)
	{
		crc = calcCrc32Byte(crc, data[i]);
	}
	return crc;
}


/**
 * @brief Finish the CRC calculation
 *
 * @param currentCrc Current CRC value
 * @return CRC32 final value
 */
uint32_t CRC::finishCrc32(const uint32_t currentCrc)
{
	uint32_t crc = currentCrc ^ 0xffffffff;

	return crc;
}

/**
 * @brief Calculate CRC32 of one Byte
 *
 * This function calculates the CRC32 checksum of one Byte. It is only
 * used internally as private function
 *
 * @param crc current CRC value
 * @param byte Byte to use
 * @return CRC32 checksum
 */
uint32_t CRC::calcCrc32Byte(uint32_t crc, uint8_t byte)
{
  int8_t i;
  crc = crc ^ byte;

  for (i = 7; i >= 0; i--)
  {
    uint8_t bit0 = crc & 1;
    crc >>= 1;
    if (bit0)
    {
      crc ^= polynom;
    }
  }

  return crc;
}
