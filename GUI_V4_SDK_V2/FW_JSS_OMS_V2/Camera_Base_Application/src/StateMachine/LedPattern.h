/*
 * LedPattern.h
 *
 *  Created on: 24.09.2019
 *      Author: mwi
 */

#ifndef LED_PATTERN_H_
#define LED_PATTERN_H_

static const uint8_t LED_PATTERN_STARTUP = 0x01;
static const uint8_t LED_PATTERN_OPERATION = 0xF0;
static const uint8_t LED_PATTERN_SYNCHRONIZE = 0xAA;
static const uint8_t LED_PATTERN_NO_CALIBRATION = 0x05;
static const uint8_t LED_PATTERN_OFF = 0x00;
static const uint8_t LED_PATTERN_ERROR = 0x2A;

#endif /* LED_PATTERN_H_ */
