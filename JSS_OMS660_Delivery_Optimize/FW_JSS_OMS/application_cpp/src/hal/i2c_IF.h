/**
 * Copyright (C) 2016 Espros Photonics Corporation
 *
 * @defgroup i2c_if Interface
 * @ingroup i2c
 *
 * @brief Interface for the I2c class
 *
 * @{
 */
#ifndef I2C_IF_H_
#define I2C_IF_H_

#include <stdint.h>

//! I2C Interface
/*!
 * Interface for the I2C class
 */
class i2c_IF
{
	public:
  	virtual int8_t init(void) = 0;
	  virtual int8_t writeByte(const uint16_t devAddr, const uint8_t regAddr, const uint8_t data) = 0;
	  virtual int8_t readByte(const uint16_t devAddr, const uint8_t regAddr, uint8_t *data) = 0;
	  virtual int8_t writeBuffer(const uint16_t devAddr, const uint8_t regAddr, const uint32_t numBytes, const uint8_t* data) = 0;
	  virtual int8_t readBuffer(const uint16_t devAddr, const uint8_t regAddr, const uint32_t numBytes, uint8_t* pData) = 0;
	  virtual bool deviceIsPresent(const uint16_t devAddr) = 0;
	  virtual int8_t getAndClearStatus() = 0;
	  virtual int8_t ioExpanderWriteRegister(uint16_t devAddr, uint8_t regAddr, uint32_t value) = 0;
	  virtual int8_t ioExpanderReadRegister(uint16_t devAddr, uint8_t regAddr, uint32_t *value) = 0;
	  virtual int8_t ioExpanderReadFlash(uint16_t devAddr, uint8_t regAddr, const uint32_t flashAddress, uint32_t numBytes, uint8_t *pData) = 0;
	  virtual int8_t ioExpanderWriteFlash(const uint16_t devAddr, const uint8_t regAddr, const uint32_t flashAddr, const uint32_t numBytes, const uint8_t *pData) = 0;
};

#endif /* I2C_IF_H_ */

/** @} */
