/***
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @addtogroup crc_stm8
 */
#include "CrcStm8.h"

static const uint8_t INITIAL_CRC = 0x00;
static const uint8_t POLYNOM = 0x07;


/**
 * @brief Calculate the CRC for the given buffer
 *
 * This function calculates the CRC for the given buffer. It uses the same algorithm like the hardware
 * crc calculation of the SPI in the STM8.
 *
 * @param data Pointer to the data
 * @param size Number of bytes to take for the CRC calculation
 * @return CRC
 */
uint8_t CrcStm8::calcCrc(const uint8_t *data, const uint32_t size)
{
	uint8_t crc = INITIAL_CRC;

	for (uint32_t i = 0; i < size; i++)
	{
		crc = crcSoftwareFunction(crc, data[i]);
	}

	return crc;
}

/**
 * @brief Calculated CRC for one input byte
 *
 * Do the CRC calculation for one bye. To calculate the CRC of a buffer, run this function
 * in a loop.
 *
 * @param initialCrc Current CRC
 * @param inputData Data byte to take into account for the CRC calculation
 * @return CRC
 */
uint8_t CrcStm8::crcSoftwareFunction(uint8_t initialCrc, uint8_t inputData)
{
	uint8_t bindex = 0;
  uint8_t crc = 0;

  /* Initial XOR operation with the previous Crc value */
  crc = initialCrc ^ inputData;

  /* The CRC algorithm routine */
  for (bindex = 0; bindex < 8; bindex++)
  {
    if (crc & 0x80)
    {
      crc = (crc << 1) ^ POLYNOM;
    }
    else
    {
      crc = (crc << 1);
    }
  }
  return crc;
}

/** @} */
