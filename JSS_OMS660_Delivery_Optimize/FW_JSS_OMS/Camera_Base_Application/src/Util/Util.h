/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @defgroup util Util
 * @brief Utilities
 * @ingroup application
 *
 * @{
 */
#ifndef UTIL_UTIL_H_
#define UTIL_UTIL_H_

#include <stdint.h>

//! Utilities
/*!
 * This class provides some common used functions. They are implemented static, so no instance
 * of the class is needed.
 */
class Util
{
	public:
		static uint32_t getValueUint32BigEndian(const uint8_t *buffer, const uint16_t index);
		static uint16_t getValueUint16BigEndian(const uint8_t *buffer, const uint16_t index);
		static int16_t getValueInt16BigEndian(const uint8_t *buffer, const uint16_t index);
		static void setValueUint16BigEndian(uint8_t *buffer, const uint16_t index, const uint16_t value);
		static void setValueInt16BigEndian(uint8_t *buffer, const uint16_t index, const int16_t value);
		static void setValueUint32BigEndian(uint8_t *buffer, const uint16_t index, const uint32_t value);
		static bool getifEnabled(const uint8_t *buffer, const uint16_t index);
};

#endif /* UTIL_UTIL_H_ */

/** @} */
