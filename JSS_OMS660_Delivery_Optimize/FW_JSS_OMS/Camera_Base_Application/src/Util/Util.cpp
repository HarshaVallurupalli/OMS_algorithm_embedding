/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @addtogroup util
 */
#include "Util.h"

/**
 * @brief Get a uint32 value from a buffer at a defined Index
 *
 * @param buffer Buffer to get the value
 * @param index Index where to get the value
 * @return Required value
 */
uint32_t Util::getValueUint32BigEndian(const uint8_t *buffer, const uint16_t index)
{
	uint32_t value = (buffer[index+0] << 24) | (buffer[index+1] << 16) | (buffer[index+2] << 8) | buffer[index+3];

	return value;
}

/**
 * @brief Get a uint16 value from a buffer at a defined Index
 *
 * @param buffer Buffer to get the value
 * @param index Index where to get the value
 * @return Required value
 */
uint16_t Util::getValueUint16BigEndian(const uint8_t *buffer, const uint16_t index)
{
	uint16_t value = (buffer[index+0] << 8) | buffer[index+1];

	return value;
}

/**
 * @brief Get a int16 value from a buffer at a defined Index
 *
 * @param buffer Buffer to get the value
 * @param index Index where to get the value
 * @return Required value
 */
int16_t Util::getValueInt16BigEndian(const uint8_t *buffer, const uint16_t index)
{
	int16_t value = (buffer[index+0] << 8) | buffer[index+1];

	return value;
}

/**
 * @brief Get a boolian value from a buffer at a defined Index
 *
 * If the value is zero, false is returned. Else (any other value) true.
 *
 * @param buffer Buffer to get the value
 * @param index Index where to get the value
 * @return Boolian
 */
bool Util::getifEnabled(const uint8_t *buffer, const uint16_t index)
{
  if(buffer[index])
  {
  	return true;
  }

  return false;
}

/**
 * @brief Put a uint16 value into the buffer at a defined index
 *
 * @param buffer Buffer to put the value
 * @param index Index where to put the value
 * @param value Value to put
 */
void Util::setValueUint16BigEndian(uint8_t *buffer, const uint16_t index, const uint16_t value)
{
	buffer[index+1] = value & 0xff;
	buffer[index+0] = value >> 8;
}

/**
 * @brief Put a int16 value into the buffer at a defined index
 *
 * @param buffer Buffer to put the value
 * @param index Index where to put the value
 * @param value Value to put
 */
void Util::setValueInt16BigEndian(uint8_t *buffer, const uint16_t index, const int16_t value)
{
	buffer[index+1] = value & 0xff;
	buffer[index+0] = value >> 8;
}

/**
 * @brief Put a uint32 value into the buffer at a defined index
 *
 * @param buffer Buffer to put the value
 * @param index Index where to put the value
 * @param value Value to put
 */
void Util::setValueUint32BigEndian(uint8_t *buffer, const uint16_t index, const uint32_t value)
{
	volatile uint8_t *p = buffer;

	p[index+3] = value & 0xFF;
	p[index+2] = (value >> 8) & 0xFF;
	p[index+1] = (value >> 16) & 0xFF;
	p[index+0] = (value >> 24) & 0xFF;
}

/** @} */
