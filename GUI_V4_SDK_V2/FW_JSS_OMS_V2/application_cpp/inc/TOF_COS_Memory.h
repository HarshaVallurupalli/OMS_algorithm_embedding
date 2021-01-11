/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup tof_cos_memory TOF COS Memory
 * @ingroup tof_cos
 *
 * @brief Contains memory settings for the current application.
 *
 * This file needs to be filled out for each application.
 *
 * @{
 */
#ifndef TOF_COS_MEMORY_H_
#define TOF_COS_MEMORY_H_

///Address offset of calibration 0: Full DRNU
const uint32_t TOF_COS_CALIBRATION_DRNU_DATA_0_OFFSET = 0;
const uint32_t TOF_COS_CALIBRATION_DRNU_DATA_0_SIZE = 320 * 240 * 24 + 2048;

///Address offset of the grayscale calibration data
const uint32_t TOF_COS_CALIBRATION_GRAYSCALE_OFFSET = TOF_COS_CALIBRATION_DRNU_DATA_0_OFFSET + TOF_COS_CALIBRATION_DRNU_DATA_0_SIZE;
const uint32_t TOF_COS_CALIBRATION_GRAYSCALE_SIZE = 320 * 240 * 1;

///Address offset of the ambient light calibration data
const uint32_t TOF_COS_CALIBRATION_AMBIENT_LIGHT_OFFSET = TOF_COS_CALIBRATION_GRAYSCALE_OFFSET + TOF_COS_CALIBRATION_GRAYSCALE_SIZE;
const uint32_t TOF_COS_CALIBRATION_AMBIENT_LIGHT_SIZE = 64;

const uint32_t TOF_COS_TOTAL_CALIBRATION_MEMORY = TOF_COS_CALIBRATION_AMBIENT_LIGHT_OFFSET + TOF_COS_CALIBRATION_AMBIENT_LIGHT_SIZE;


#endif /* TOF_COS_MEMORY_H_ */

/** @} */
