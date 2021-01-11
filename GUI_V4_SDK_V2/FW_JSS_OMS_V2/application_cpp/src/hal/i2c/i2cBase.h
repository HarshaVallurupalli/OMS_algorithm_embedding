/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup i2c I2C
 *
 * @brief HAL for the I2C
 */
#ifndef I2C_BASE_H_
#define I2C_BASE_H_

#include <stdint.h>
#include "xiicps.h"
#include "hal/i2c_IF.h"

//! I2C class
/*!
 * HAL function so control the I2C
 */
class i2cBase: public i2c_IF
{
	public:
		i2cBase();

		int8_t init(void);
		int8_t writeByte(const uint16_t devAddr, const uint8_t regAddr, const uint8_t data);
		int8_t readByte(const uint16_t devAddr, const uint8_t regAddr, uint8_t *data);
		int8_t writeBuffer(const uint16_t devAddr, const uint8_t regAddr, const uint32_t numBytes, const uint8_t* pData);
		int8_t readBuffer(const uint16_t devAddr, const uint8_t regAddr, const uint32_t numBytes, uint8_t* pData);
		bool deviceIsPresent(const uint16_t devAddr);
		int8_t getAndClearStatus();
		int8_t ioExpanderWriteRegister(uint16_t devAddr, uint8_t regAddr, uint32_t value);
		int8_t ioExpanderReadRegister(uint16_t devAddr, uint8_t regAddr, uint32_t *value);
		int8_t ioExpanderReadFlash(uint16_t devAddr, uint8_t regAddr, const uint32_t flashAddress, uint32_t numBytes, uint8_t *pData);
		int8_t ioExpanderWriteFlash(const uint16_t devAddr, const uint8_t regAddr, const uint32_t flashAddr, const uint32_t numBytes, const uint8_t *pData);

	protected:
		XIicPs Iic;                                       ///< Instance of the xilinx IIC Device

	private:
		int8_t error;

		virtual int8_t initHardware() = 0;
		int8_t transferRead(const uint16_t devAddr, const uint8_t regAddr, const uint32_t numBytes, uint8_t* pData);
		int8_t transferWrite(const uint16_t devAddr, const uint8_t regAddr, const uint32_t numBytes, uint8_t* pData);
};

#endif /* I2C_BASE_H_ */

/** @} */
