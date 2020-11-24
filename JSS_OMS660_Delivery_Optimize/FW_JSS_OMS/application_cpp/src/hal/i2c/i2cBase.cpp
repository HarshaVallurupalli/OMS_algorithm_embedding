/***
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @addtogroup i2c
 */
#include <GlobalSettings.h>
#include "i2cBase.h"
#include <sleep.h>
#include "IoExpander/IoExpanderConstants.h"


static const uint16_t TIMEOUT = 1000;            ///<Timeout for the HAL functions

/**
 * @brief Constructor
 *
 * Remark: No timeout implemented so far
 */
i2cBase::i2cBase()
{
  error = 0;
}

/**
 * @brief Do a read transfer
 *
 * Remark: No timeout implemented so far
 *
 * @param devAddr Device address
 * @param regAddr Register address to read
 * @param numBytes Number of bytes to read
 * @param pData Pointer to the buffer to copy the data
 * @retval 0 Ok
 * @retval -1 Error
 * @return Status
 */
int8_t i2cBase::transferRead(uint16_t devAddr, uint8_t regAddr, uint32_t numBytes, uint8_t* pData)
{
	int32_t status;
	uint8_t registerAddress = regAddr;

	status = XIicPs_MasterSendPolled(&Iic, &registerAddress, 1, devAddr);

	while (XIicPs_BusIsBusy(&Iic));

	status = XIicPs_MasterRecvPolled(&Iic, pData, numBytes, devAddr);

	while (XIicPs_BusIsBusy(&Iic));

	if (status != XST_SUCCESS)
	{
		return -1;
	}

	return 0;
}

/**
 * @brief Do a write transfer
 *
 * Remark: No timeout implemented so far
 *
 * @param devAddr Device address
 * @param regAddr Register address to write
 * @param numBytes Number of bytes to write
 * @param pData Pointer to the data to write
 * @retval 0 Ok
 * @retval -1 Error
 * @return Status
 */
int8_t i2cBase::transferWrite(uint16_t devAddr, uint8_t regAddr, uint32_t numBytes, uint8_t* pData)
{
	int32_t status;
	uint32_t bytesToSend = numBytes + 1; //For the register Address

	uint8_t writeBuffer[bytesToSend];

	//Set the first byte to the register address and copy the data to send
	writeBuffer[0] = regAddr;
	memcpy(&writeBuffer[1], pData, numBytes);

	status = XIicPs_MasterSendPolled(&Iic, writeBuffer, bytesToSend, devAddr);
	if (status != XST_SUCCESS)
	{
		return -1;
	}

	while (XIicPs_BusIsBusy(&Iic));

	return 0;
}

/**
 * @brief Write a register on the OMS
 *
 * These registers contain 32Bits of data
 *
 * Remark: No timeout implemented so far
 *
 * @param devAddr Device address
 * @param regAddr Register address to write
 * @param value Value to write
 * @retval 0 Ok
 * @retval -1 Error
 * @return Status
 */
int8_t i2cBase::ioExpanderWriteRegister(uint16_t devAddr, uint8_t regAddr, uint32_t value)
{
	int32_t status;
	uint8_t index = 0;
	uint8_t bytesToSend = sizeof(uint32_t) + sizeof(uint32_t);  //Register address, value

	uint8_t writeBuffer[bytesToSend];

	//Preamble
	writeBuffer[index++] = PREAMBLE_FIRST_BYTE;
	writeBuffer[index++] = PREAMBLE_SECOND_BYTE;

	//Register address
	writeBuffer[index++] = regAddr >> 8;
	writeBuffer[index++] = regAddr & 0xFF;

	//Payload
	writeBuffer[index++] = (value >> 24) & 0xFF;
	writeBuffer[index++] = (value >> 16) & 0xFF;
	writeBuffer[index++] = (value >> 8) & 0xFF;
	writeBuffer[index++] = value & 0xFF;

	status = XIicPs_MasterSendPolled(&Iic, writeBuffer, bytesToSend, devAddr);
	if (status != XST_SUCCESS)
	{
		return -1;
	}

	while (XIicPs_BusIsBusy(&Iic));


	return 0;
}

/**
 * @brief Read a register from the OMS
 *
 * These registers contain 32Bits of data
 *
 * Remark: No timeout implemented so far
 *
 * @param devAddr Device address
 * @param regAddr Register address to read
 * @param value Pointer to the variable to write the value
 * @retval 0 Ok
 * @retval -1 Error
 * @return Status
 */
int8_t i2cBase::ioExpanderReadRegister(uint16_t devAddr, uint8_t regAddr, uint32_t *value)
{
	int32_t status;
	uint8_t index = 0;
	uint8_t bytesToSend = sizeof(uint32_t);  //Register address
	uint8_t bytesToRead = sizeof(uint32_t);

	uint8_t transmitBuffer[bytesToSend];
	uint8_t receiverBuffer[bytesToRead];

	//Preamble
	transmitBuffer[index++] = PREAMBLE_FIRST_BYTE;
	transmitBuffer[index++] = PREAMBLE_SECOND_BYTE;

	//Register address
	transmitBuffer[index++] = regAddr >> 8;
	transmitBuffer[index++] = regAddr & 0xFF;

	XIicPs_SetOptions(&Iic, XIICPS_REP_START_OPTION);

	status = XIicPs_MasterSendPolled(&Iic, transmitBuffer, bytesToSend, devAddr);
	if (status != XST_SUCCESS)
	{
	  return -1;
	}

	XIicPs_ClearOptions(&Iic, XIICPS_REP_START_OPTION);

	status = XIicPs_MasterRecvPolled(&Iic, receiverBuffer, bytesToRead, devAddr);
	if (status != XST_SUCCESS)
	{
	  return -1;
	}

	while (XIicPs_BusIsBusy(&Iic));

  //combine the bytes to the 32bit register value
  *value = (receiverBuffer[0] << 24) | (receiverBuffer[1] << 16) | (receiverBuffer[2] << 8) | receiverBuffer[3];

	return 0;
}

/**
 * @brief Read from the flash on the OMS
 *
 * This function reads from the flash memory on the OMS device. Because of the low I2C speed this may take a long time.
 * This read is done blocking.
 *
 * Remark: No timeout implemented so far
 *
 * @param devAddr Device address
 * @param regAddr Register address to read on the IO expander
 * @param flashAddr Flash address where the first byte is read
 * @param numBytes Number of bytes to read
 * @param pData Pointer to the data to read.
 * @retval 0 Ok
 * @retval -1 Error
 * @return Status
 */
int8_t i2cBase::ioExpanderReadFlash(uint16_t devAddr, uint8_t regAddr, const uint32_t flashAddress, uint32_t numBytes, uint8_t *pData)
{
	int32_t status;
	uint8_t index = 0;
	uint8_t bytesToSend = sizeof(uint32_t) + sizeof(uint32_t);  //Register address + flash address

	uint8_t writeBuffer[bytesToSend];

	//Preamble
	writeBuffer[index++] = PREAMBLE_FIRST_BYTE;
	writeBuffer[index++] = PREAMBLE_SECOND_BYTE;

	//Register address
	writeBuffer[index++] = regAddr >> 8;
	writeBuffer[index++] = regAddr & 0xFF;

	//Flash address
	writeBuffer[index++] = (flashAddress >> 24);
	writeBuffer[index++] = (flashAddress >> 16);
	writeBuffer[index++] = (flashAddress >> 8);
	writeBuffer[index++] = (flashAddress & 0xFF);

	XIicPs_SetOptions(&Iic, XIICPS_REP_START_OPTION);

	//Send preamble and addresses
	status = XIicPs_MasterSendPolled(&Iic, writeBuffer, bytesToSend, devAddr);
	if (status != XST_SUCCESS)
	{
	  return -1;
	}

	//Read as many bytes as needed
	status = XIicPs_MasterRecvPolled(&Iic, pData, numBytes, devAddr);
	if (status != XST_SUCCESS)
	{
	  return -1;
	}

	while (XIicPs_BusIsBusy(&Iic));

	XIicPs_ClearOptions(&Iic, XIICPS_REP_START_OPTION);

	return 0;
}

/**
 * @brief Write to the flash on the OMS
 *
 * This function writes to the flash memory on the OMS device. Because of the low I2C speed this may take a long time.
 * This write is done blocking.
 *
 * Remark: No timeout implemented so far
 *
 * @param devAddr Device address
 * @param regAddr Register address to write on the IO expander
 * @param flashAddr Flash address where the first byte is written
 * @param numBytes Number of bytes to write
 * @param pData Pointer to the data to write.
 * @retval 0 Ok
 * @retval -1 Error
 * @return Status
 */
int8_t i2cBase::ioExpanderWriteFlash(const uint16_t devAddr, const uint8_t regAddr, const uint32_t flashAddr, const uint32_t numBytes, const uint8_t *pData)
{
	int32_t status;
	uint8_t index = 0;
	uint8_t bytesToSend = sizeof(uint32_t) + sizeof(uint32_t) + numBytes;  //Register address + flash address + payload

	uint8_t writeBuffer[bytesToSend];

	//Preamble
	writeBuffer[index++] = PREAMBLE_FIRST_BYTE;
	writeBuffer[index++] = PREAMBLE_SECOND_BYTE;

	//Register address
	writeBuffer[index++] = regAddr >> 8;
	writeBuffer[index++] = regAddr & 0xFF;

	//Flash address
	writeBuffer[index++] = (flashAddr >> 24);
	writeBuffer[index++] = (flashAddr >> 16);
	writeBuffer[index++] = (flashAddr >> 8);
	writeBuffer[index++] = (flashAddr & 0xFF);

	//Copy the payload to have everything in one temporary buffer
	for (uint32_t i = 0; i < numBytes; i++)
	{
		writeBuffer[index++] = pData[i];
	}

	status = XIicPs_MasterSendPolled(&Iic, writeBuffer, bytesToSend, devAddr);
	if (status != XST_SUCCESS)
	{
		return -1;
	}

	while (XIicPs_BusIsBusy(&Iic));

	return 0;
}

/**
 * @brief Write one byte
 *
 * This function writes one byte to the device.
 *
 * @param devAddr Device address
 * @param regAddr Register address to write
 * @param data Data byte to write
 * @retval 0 Ok
 * @retval -1 Error
 * @return Status
 */
int8_t i2cBase::writeByte(const uint16_t devAddr, const uint8_t regAddr, const uint8_t data)
{
	return transferWrite(devAddr, regAddr, 1, (uint8_t *)&data);
}

/**
 * @brief Read one byte
 *
 * This function reads one byte from the device.
 *
 * @param devAddr Device address
 * @param regAddr Register address to read
 * @param pData Pointer where to copy the data byte
 * @retval 0 Ok
 * @retval -1 Error
 * @return Status
 */
int8_t i2cBase::readByte(const uint16_t devAddr, const uint8_t regAddr, uint8_t *data)
{
  return transferRead(devAddr, regAddr, 1, data);
}

/**
 * @brief Write a buffer to the device
 *
 * This function writes as many bytes as requested to the device.
 *
 * @param devAddr Device address
 * @param regAddr Register address to start writing
 * @param numBytes Number of bytes to write
 * @param pData Pointer to the buffer to read the data from
 * @retval 0 Ok
 * @retval -1 Error
 * @return Status
 */
int8_t i2cBase::writeBuffer(const uint16_t devAddr, const uint8_t regAddr, const uint32_t numBytes, const uint8_t* pData)
{
	return transferWrite(devAddr, regAddr, numBytes, (unsigned char *)pData);
}

/**
 * @brief Read a buffer from the device
 *
 * This function reads as many bytes as requested from the device.
 *
 * @param devAddr Device address
 * @param regAddr Register address to start reading
 * @param numBytes Number of bytes to read
 * @param pData Pointer to the buffer to write the data
 * @retval 0 Ok
 * @retval -1 Error
 * @return Status
 */
int8_t i2cBase::readBuffer(const uint16_t devAddr, const uint8_t regAddr, const uint32_t numBytes, uint8_t* pData)
{
	return transferRead(devAddr, regAddr, numBytes, pData);
}

/**
 * @brief Check if a device with the given address is present
 *
 * This function just makes a read to address 0. If this is successful, a device is assumed to
 * be there.
 *
 * @param devAddr Device address to check
 * @retval true Device was found
 * @retval false No device found
 * @return Device found or not
 */
bool i2cBase::deviceIsPresent(const uint16_t devAddr)
{
	uint8_t data[1];
	int32_t status = readByte(devAddr, 0, data);

	if (status < 0)
	{
		return false;
	}

	return true;
}

/**
 * @brief Read the status
 *
 * Read back, if since the last call of this functions an error has happened. The error is cleared
 * after reading.
 *
 * @retval 0 OK
 * @return 0 if there was no error, else a negative number
 */
int8_t i2cBase::getAndClearStatus()
{
  int8_t errorToReturn = error;
  error = 0;
  return errorToReturn;
}

/**
 * @brief Init
 *
 * Call this before using the I2C.
 *
 * @retval 0 OK
 * @return Result, 0 if ok, else negative value
 */
int8_t i2cBase::init(void)
{
	int8_t status = initHardware();

	return status;
}

/** @} */
