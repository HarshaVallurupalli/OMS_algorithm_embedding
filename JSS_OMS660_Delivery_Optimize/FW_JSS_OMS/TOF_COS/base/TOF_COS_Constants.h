/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup tof_cos_constants Constants
 * @ingroup tof_cos
 * @brief Constants for the TOF_COS
 *
 * @{
 */
#ifndef TOF_COS_CONSTANTS_H_
#define TOF_COS_CONSTANTS_H_

#include <stdint.h>

///TOF_COS version
const uint32_t TOF_COS_VERSION = 1;

/*****************************************************************************
 * Masks and Shifts
 *****************************************************************************/
///Defines the total number of pixels
const uint32_t MAX_IMAGE_SIZE = 76800;

///Shift for distance in 32Bit value combined amplitude/distance
const uint32_t DISTANCE_SHIFT = 0;

///Mask for distance in 32Bit value combined amplitude/distance
const uint32_t DISTANCE_MASK = 0x0000FFFF;

///Shift for amplitude in 32Bit value combined amplitude/distance
const uint32_t AMPLITUDE_SHIFT = 16;

///Mask for amplitude in 32Bit value combined amplitude/distance
const uint32_t AMPLITUDE_MASK = 0xFFFF0000;

///Masks out the distance value of the combined value distance/confidence
const uint32_t DISTANCE_MASK_OUT_DISTANCE = 0x3FFF;

///Masks out the confidence value of the combined value distance/confidence
const uint32_t DISTANCE_MASK_OUT_CONFIDENCE = 0xC000;

///Shift for the confidence bits in distance 16Bit mode
const uint32_t CONFIDENCE_SHIFT = 14;

///Number of shifts for the temperature to do fix point calculations
const uint32_t TEMPERATURE_CALC_SHIFT = 10;



/*****************************************************************************
 * Other constants
 *****************************************************************************/
const int32_t DLL_STEP_TEMPERATURE_COEFFICIENT = static_cast<int32_t>((0.6) * (double)(1 << TEMPERATURE_CALC_SHIFT));


#endif /* TOF_COS_CONSTANTS_H_ */

/** @} */
