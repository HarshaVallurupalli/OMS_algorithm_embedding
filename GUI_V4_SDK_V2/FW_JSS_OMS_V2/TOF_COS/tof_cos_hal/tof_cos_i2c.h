/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup tof_cos_i2c I2C
 * @ingroup tof_cos_hal
 *
 * @brief HAL for the I2C
 *
 * @{
 */
#ifndef TOF_COS_I2C_H_
#define TOF_COS_I2C_H_

#include <stdint.h>

int8_t tofCosI2cInit(void);
int8_t tofCosI2cWriteByte(const uint16_t devAddr, const uint8_t regAddr, const uint8_t data);
int8_t tofCosI2cReadByte(const uint16_t devAddr, const uint8_t regAddr, uint8_t *data);
int8_t tofCosI2cReadBuffer(const uint16_t devAddr, const uint8_t regAddr, const uint32_t numBytes, uint8_t *pData);
int8_t tofCosI2cWriteBuffer(const uint16_t devAddr, const uint8_t regAddr, const uint32_t numBytes, const uint8_t* pData);
bool tofCosI2cDeviceIsPresent(const uint16_t devAddr);
int8_t tofCosI2cGetAndClearStatus();

#endif /* TOF_COS_I2C_H_ */

/** @} */
