/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup led Led
 *
 * @brief Small helper class to control the LED
 *
 * @{
 */
#ifndef LED_H_
#define LED_H_

#include <stdint.h>

//! Led
/*!
 * Small helper class to control the LED
 */
class Led
{
	public:
		void setPattern(const uint8_t pattern);
};

#endif /* LED_H_ */

/** @} */
