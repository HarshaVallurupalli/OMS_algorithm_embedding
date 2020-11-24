/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup tof_cos_calibration_memory Calibration Memory
 * @ingroup tof_cos_hal
 * @brief This is an abstraction layer for the calibration memory used in the TOFCOS
 *
 * This calibration memory could be located in the flash or in the RAM.
 *
 * @{
 */
#ifndef TOF_COS_CALIBRATION_MEMORY_H_
#define TOF_COS_CALIBRATION_MEMORY_H_

#include <stdint.h>

int8_t tofCosCalibrationMemoryInit();
uint32_t tofCosCalibrationMemoryGetStartAddress();
uint32_t tofCosCalibrationMemoryGetTotalSize();
int8_t tofCosCalibrationMemorySetCurrentAddress(const uint32_t address);
int8_t tofCosCalibrationMemoryAddByte(const uint8_t data);
int8_t tofCosCalibrationMemoryAdd32Bytes(const uint32_t address, const uint8_t *data);
int8_t tofCosCalibrationMemoryWriteToDevice();
int8_t tofCosCalibrationMemoryCheckErased(const uint32_t address, const uint32_t size);

#endif /* TOF_COS_CALIBRATION_MEMORY_H_ */

/** @} */
