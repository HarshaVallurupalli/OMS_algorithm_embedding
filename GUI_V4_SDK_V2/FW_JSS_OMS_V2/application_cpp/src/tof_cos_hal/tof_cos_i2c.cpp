/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 *
 * @addtogroup tof_cos_i2c
 *
 * @{
 */
#include <hal/i2c/i2cInstance.h>
#include "tof_cos_i2c.h"
#include "hal/i2c_IF.h"


static i2c_IF &i2c = i2cInstance::getInstance();

int8_t tofCosI2cInit(void)
{
	return i2c.init();
}

int8_t tofCosI2cWriteByte(const uint16_t devAddr, const uint8_t regAddr, const uint8_t data)
{
	return i2c.writeByte(devAddr, regAddr, data);
}

int8_t tofCosI2cReadByte(const uint16_t devAddr, const uint8_t regAddr, uint8_t *data)
{
	return i2c.readByte(devAddr, regAddr, data);
}

int8_t tofCosI2cReadBuffer(const uint16_t devAddr, const uint8_t regAddr, const uint32_t numBytes, uint8_t *pData)
{
	return i2c.readBuffer(devAddr,  regAddr, numBytes, pData);
}

int8_t tofCosI2cWriteBuffer(const uint16_t devAddr, const uint8_t regAddr, const uint32_t numBytes, const uint8_t* pData)
{
	return i2c.writeBuffer(devAddr, regAddr, numBytes, pData);
}

bool tofCosI2cDeviceIsPresent(const uint16_t devAddr)
{
	return i2c.deviceIsPresent(devAddr);
}

int8_t tofCosI2cGetAndClearStatus()
{
	return i2c.getAndClearStatus();
}

/** @} */
