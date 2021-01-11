/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @defgroup tof_cos_config TOF COS config
 * @ingroup tof_cos
 *
 * @brief Contains defines for the current application.
 *
 * This file needs to be filled out for each application.
 *
 * @{
 */
#ifndef TOF_COS_CONFIG_H_
#define TOF_COS_CONFIG_H_

#include <stdint.h>


/******************************************************************************************************
 * Buffer settings
 ******************************************************************************************************/
///This is the amount of bytes in front of the measurement data. That is useful e.g for communication, where some prebytes are needed
//const uint32_t TOF_COS_DATA_SIZE_PRE_BYTES = Header::HEADER_SIZE + CommunicationConstants::Data::SIZE_HEADER;

///This is the amount of bytes in front of the dcs data. That is useful e.g for communication, where some prebytes are needed
//const uint32_t TOF_COS_DATA_PRE_BYTES_DCS = Header::HEADER_SIZE;

///This is the total overhead of memory on the measurement data
//const uint32_t TOF_COS_DATA_SIZE_OVERHEAD = TOF_COS_DATA_SIZE_PRE_BYTES + CommunicationConstants::Data::SIZE_CHECKSUM;


/******************************************************************************************************
 * Configuration
 ******************************************************************************************************/
///[lsb] Target amplitude for calibration
const uint16_t DRNU_CALIBRATION_AMPLITUDE_TARGET = 600;

///I2C address of the TOF imager
const uint8_t TOF_COS_DEVICE_ADDRESS_TOF_IMAGER = 32;

///Number of calibrations
const uint8_t TOF_COS_NUM_CALIBRATION = 1;

///Number of illuminations
const uint8_t TOF_COS_NUM_ILLUMINATION = 1;

///Number of settings to use
const uint8_t TOF_COS_NUM_SETTINGS = 2;

///DLL step on which the TOF imager operates
const uint8_t TOF_COS_DLL_STEP_OPERATION = 3;

///Length of the calibration box in mm
const uint16_t TOF_COS_CALIBRATION_BOX_LENGTH = 330;

///Distance in mm from chip to front of camera
const uint8_t TOF_COS_DISTANCE_CHIP_TO_FRONT = 22;

///Integration time for grayscale for ambient light compensation
const uint8_t TOF_COS_GRAYSCALE_INTEGRATION_TIME_AMBIENT_LIGHT_COMPENSATION = 50;

///Temperature coefficient
const float TOF_COS_TEMPERATURE_COEFFICIENT = 12.9 + 4.6;

///This value is added to the pixel codes. Normally the codes start at 16000, e.g. 16001 for low amplitude. In case of high distance ranges this would be a valid value, so
///this offset changes the value for the codes to 64000.
///For compatibility to current systems we do this only if needed because of the range.
static const uint16_t PIXEL_CODE_OFFSET = 48000;

///Set to 1 to used confidence bits. Only possible if distances < 16'000 are used
#define TOF_COS_USE_CONFIDENCE_BITS 0


#define TOF_COS_USE_LOW_MODULATION_FREQUENCIES 0


/******************************************************************************************************
 * LED output
 ******************************************************************************************************/
///Configure LED pin (open drain)
const bool TOF_COS_USE_LED_PIN = false;

///Configure LED 2 pin (push/pull)
const bool TOF_COS_USE_LED_2_PIN = true;

///Configure invert
const bool TOF_COS_INVERT_LED = false;


/******************************************************************************************************
 * Chip Settings
 ******************************************************************************************************/
//Set TCMI clock to 96MHz / (TOF_COS_TCMI_CLK_DIVICER + 1), here 32.0MHz
const uint8_t TOF_COS_TCMI_CLK_DIVIDER = 2;

//TCMI settings: invert HSYNC, VSYNC, force 0xFFF if saturated,  default is 0x41
const uint8_t TOF_COS_TCMI_SETTINGS = 0xC7;


/******************************************************************************************************
 * soft logic specific Settings
 ******************************************************************************************************/
#define OLD_SOFT_LOGIC 0

/******************************************************************************************************
 * Trace Settings
 ******************************************************************************************************/
///If trace is desired, set to 1
#define TRACE_ENABLED 1

#if (TRACE_ENABLED==1)
  #include "trace/TraceLoggerInstance.h"
  #define TRACE_STR(x) TraceLoggerInstance::getInstance()->printDataStr(x)
  #define TRACE_UINT(t, x) TraceLoggerInstance::getInstance()->printDataUint(t, x)
  #define TRACE_INT(t, x) TraceLoggerInstance::getInstance()->printDataInt(t, x)
  #define TRACE_STEP(x) TraceLoggerInstance::getInstance()->printStep(x)
  #define TRACE_NEWLINE TraceLoggerInstance::getInstance()->printDataStr("\r\n")
#else
  #define TRACE_STR(x)
  #define TRACE_UINT(t, x)
  #define TRACE_INT(t, x)
  #define TRACE_STEP(x)
  #define TRACE_NEWLINE
#endif

#endif /* TOF_COS_CONFIG_H_ */

/** @} */
