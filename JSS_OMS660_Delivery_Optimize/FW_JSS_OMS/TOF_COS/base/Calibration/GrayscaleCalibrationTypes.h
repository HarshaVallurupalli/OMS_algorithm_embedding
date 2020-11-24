/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup grayscale_calibration_types Types
 * @brief Types and constants for the grayscale calibration
 * @ingroup grayscale_calibration
 *
 * @{
 */
#ifndef GRAYSCALE_CALIBRATION_TYPES_H_
#define GRAYSCALE_CALIBRATION_TYPES_H_

///If the whole byte equals to this value, the grayscale is not calibrated. This is the default value of the not written flash.
const uint8_t VALUE_GRAYSCALE_NOT_CALIBRATED = 0xFF;

///If the DSNU value in the LUT equals to this value, the pixel is broken. This value may not be used for calibration
const uint8_t VALUE_GRAYSCALE_BROKEN_PIXEL = 0xEE;

///Shift of the DSNU. It uses fixed 4 bits.
//const uint32_t SHIFT_GRAYSCALE_DSNU = 4;

///Shift of the PRNU. It uses fixed 4 bits.
//const uint32_t SHIFT_GRAYSCALE_PRNU = 0;

///The values are stored unsigned, so they are stored with an offset: -7 --> 0, 0 --> 7, 7 --> 14
//const int32_t VALUE_DSNU_PRNU_OFFSET = 7;

///Value of the pixel without light (theoretically)
const uint16_t VALUE_PIXEL_NO_LIGHT = 2048;

///Value of the pixel with 50% light (theoretically)
const uint16_t VALUE_PIXEL_HALF_LIGHT = 3072;

///Divider for the calibration data
const int8_t CALIBRATION_DATA_DIVIDER = 16;

///Helper unit for grayscale calibration where two nibbles are used
typedef union
{
  uint8_t value;
  struct
  {
    int8_t low_dsnu: 4;
    int8_t high_prnu : 4;
  }nibbles;
}grayscaleCalibration_u;

#endif /* GRAYSCALE_CALIBRATION_TYPES_H_ */

/** @} */
