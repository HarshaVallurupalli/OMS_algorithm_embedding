/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup io_expander_constants Constants
 * @ingroup io_expander
 *
 * @brief Contains constants for the communication with the IO Expander
 *
 * @{
 */
#ifndef IO_EXPANDER_CONSTANTS_H_
#define IO_EXPANDER_CONSTANTS_H_

//Register addresses
static const uint8_t REGISTER_GENERAL_FIRMWARE_RELEASE = 0x00;
static const uint8_t REGISTER_GENERAL_STATUS_LED = 0x04;
static const uint8_t REGISTER_EPC_CONTROL = 0x40;
static const uint8_t REGISTER_ILLUMINATION_CONTROL = 0x80;
static const uint8_t REGISTER_CALIBRATION_CONTROL = 0xC0;
static const uint8_t REGISTER_CALIBRATION_STATUS = 0xC4;
static const uint8_t REGISTER_ADDRESS_READ = 0xC8;
static const uint8_t REGISTER_ADDRESS_WRITE = 0xCC;
static const uint8_t REGISTER_CALIBRATION_SIZE = 0xD0;
static const uint8_t REGISTER_CALIBRATION_CHECKSUM = 0xD4;

//Bit masks for some registers
static const uint8_t MASK_CALIBRATION_CONTROL_FLAG_ERASE = 0x01;
static const uint8_t MASK_CALIBRATION_CONTROL_FLAG_WRITE = 0x02;
static const uint8_t MASK_CALIBRATION_CONTROL_FLAG_START_CRC_CALCULATION = 0x04;

static const uint8_t MASK_CALIBRATION_STATUS_FLAG_BUSY = 0x01;

//Preamble for address
static const uint8_t PREAMBLE_FIRST_BYTE = 0xBA;
static const uint8_t PREAMBLE_SECOND_BYTE = 0xBE;

#endif /* IO_EXPANDER_CONSTANTS_H_ */

/** @} */
