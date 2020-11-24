/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @addtogroup io_expander
 */
#include <hal/i2c/i2cInstance.h>
#include <IoExpander/IoExpander.h>
#include "sleep.h"
#include "CalibrationMemory/CrcStm8.h"
#include "IoExpanderConstants.h"

IoExpander::IoExpander(i2c_IF &i2c): i2c(i2c)
{
	deviceAddress = 20;
}

/**
 * @brief Test the flash
 *
 * This function writes data to the OMS flash and reads it back. The purpose is to test
 * the OMS firmware. This function is not used during normal operation.
 *
 * @retval 0 OK
 * @return 0 OK else negative value
 */
int8_t IoExpander::testFlash()
{
	//Delete flash
  startDeleteFlash();
	waitBlockingFlashBusy();

	//uint8_t dataTx[1000];
	uint8_t dataTx[2097152];
	for (uint32_t i = 0; i < sizeof(dataTx); i++)
	{
		dataTx[i] = i;
	}

	writeFlash(0, dataTx, sizeof(dataTx));

	uint8_t dataRx[sizeof(dataTx)];

	memset(dataRx, 0, sizeof(dataRx));

	readFlash(0, dataRx, sizeof(dataRx));

	for (uint32_t i = 0; i < sizeof(dataRx); i++)
	{
		if (dataTx[i] != dataRx[i])
		{
			return -2;
		}
	}

  return 0;
}


/**
 * @brief Test function (just for debugging)
 *
 * This function writes some data to the OMS and reads them back. The purpose is to test
 * the OMS firmware. This function is not used during normal operation.
 *
 * @param testPowerSupply Set to true to also enable/disable the illumination power supply during the test
 * @retval 0 OK
 * @return 0 OK else negative value
 */
int8_t IoExpander::test(const bool testPowerSupply)
{
	uint8_t data[16];
	i2c_IF &i2c = i2cInstance::getInstance();

	i2c.ioExpanderReadFlash(deviceAddress, REGISTER_ADDRESS_READ, 0, sizeof(data), data);


  //Turn OMS STM LuED on
	i2c.ioExpanderWriteRegister(deviceAddress, REGISTER_GENERAL_STATUS_LED, 1);
	uint32_t temp = 0;

	//Read LED status
	i2c.ioExpanderReadRegister(deviceAddress, REGISTER_GENERAL_STATUS_LED, &temp);
	if (temp != 0x1)
	{
    return -1;
	}

	//Turn OMS STM LED off
	i2c.ioExpanderWriteRegister(deviceAddress, REGISTER_GENERAL_STATUS_LED, 0);

	//Read LED status
  i2c.ioExpanderReadRegister(deviceAddress, REGISTER_GENERAL_STATUS_LED, &temp);
  if (temp != 0x0)
  {
    return -2;
  }

  //Read EPC reset, must be 1
  i2c.ioExpanderReadRegister(deviceAddress, REGISTER_EPC_CONTROL, &temp);
  if (temp != 0x1)
  {
    return -3;
  }

  //Clear reset
  i2c.ioExpanderWriteRegister(deviceAddress, REGISTER_EPC_CONTROL, 0);

  //Read EPC reset, must be 0
  i2c.ioExpanderReadRegister(deviceAddress, REGISTER_EPC_CONTROL, &temp);
  if (temp != 0x0)
  {
    return -4;
  }


  //Set reset
  i2c.ioExpanderWriteRegister(deviceAddress, REGISTER_EPC_CONTROL, 1);

  //Read EPC reset, must be 1
  i2c.ioExpanderReadRegister(deviceAddress, REGISTER_EPC_CONTROL, &temp);
  if (temp != 0x1)
  {
    return -5;
  }


  if (testPowerSupply == false)
  {
  	return 0;
  }

  //Enable LED power
  i2c.ioExpanderWriteRegister(deviceAddress, REGISTER_ILLUMINATION_CONTROL, 1);
  i2c.ioExpanderReadRegister(deviceAddress, REGISTER_ILLUMINATION_CONTROL, &temp);
  if (temp != 0x1)
  {
    return -6;
  }

  //Some time for power supply
  usleep(100000);

  //Disable LED power
  i2c.ioExpanderWriteRegister(deviceAddress, REGISTER_ILLUMINATION_CONTROL, 0);
  i2c.ioExpanderReadRegister(deviceAddress, REGISTER_ILLUMINATION_CONTROL, &temp);
  if (temp != 0x0)
  {
    return -7;
  }

  //Some time for power supply
  usleep(100000);


	return 0;
}

/**
 * @brief Read from the flash (blocking)
 *
 * @param flashAddress Start address of the flash for reading
 * @param data Pointer where to put the data
 * @param size Number of bytes to read
 * @retval 0 OK
 * @retval -1 Error
 * @return status
 */
int8_t IoExpander::readFlash(const uint32_t flashAddress, uint8_t *data, const uint32_t size)
{
	int8_t status = i2c.ioExpanderReadFlash(deviceAddress, REGISTER_ADDRESS_READ, flashAddress, size, data);

	return status;
}

/**
 * @brief Write to the flash (blocking)
 *
 * @param flashAddress Start address of the flash for writing
 * @param data Pointer to the data to write
 * @param size Number of bytes to write
 * @retval 0 OK
 * @retval -1 Error
 * @return status
 */
int8_t IoExpander::writeFlash(const uint32_t flashAddress, const uint8_t *data, const uint32_t size)
{
	i2c_IF &i2c = i2cInstance::getInstance();

  //Write data to flash
  int8_t status = i2c.ioExpanderWriteFlash(deviceAddress, REGISTER_ADDRESS_WRITE, flashAddress, size, data);
  if (status < 0)
  {
  	return status;
  }/* Cancel, error ----------------------------------------------------> */

  //Small delay for the remote controller
  usleep(1000);

  //Give program command
  status = i2c.ioExpanderWriteRegister(deviceAddress, REGISTER_CALIBRATION_CONTROL, MASK_CALIBRATION_CONTROL_FLAG_WRITE);
  if (status < 0)
  {
    return status;
  }/* Cancel, error ----------------------------------------------------> */

  status = waitBlockingFlashBusy();

  return status;
}

/**
 * @brief Read if the flash is busy
 *
 * @retval false Flash not busy
 * @retval true Flash busy
 * @return Flash busy or not
 */
bool IoExpander::getFlashBusy()
{
	uint32_t temp = 0;
	i2c.ioExpanderReadRegister(deviceAddress, REGISTER_CALIBRATION_STATUS, &temp);

	if (temp & MASK_CALIBRATION_STATUS_FLAG_BUSY)
	{
		return true;
	}

	return false;
}

/**
 * @brief Wait blocking for the flash
 *
 * This function is helpful when the remote controller is doing:
 * - write
 * - erase
 * - calc crc
 *
 * @retval 0 OK
 * @retval -1 Error
 * @return status
 */
int8_t IoExpander::waitBlockingFlashBusy()
{
	while(getFlashBusy())
	{

	}

	return 0;
}

/**
 * @brief Start the delete procedure
 *
 * The delete of the flash takes several seconds. This function just gives the command for the remote controller
 * to delete. The status must be polled to detect when the delete procedure is finished.
 *
 * The whole flash is deleted.
 *
 * @retval 0 OK
 * @retval -1 Error
 * @return status
 */
int8_t IoExpander::startDeleteFlash()
{
	int8_t status = i2c.ioExpanderWriteRegister(deviceAddress, REGISTER_CALIBRATION_CONTROL, MASK_CALIBRATION_CONTROL_FLAG_ERASE);

	return status;
}

/**
 * @brief Start the calculation of the CRC
 *
 * The calculation of the CRC takes a few seconds. This function just gives the command for the remote controller to
 * start the calculation. The status must be polled to detect when the calculation is finished.
 * The size is needed to tell the remote controller how many bytes it needs to take into account for the CRC calculation.
 *
 * @param size Size of the calibration
 * @retval 0 OK
 * @retval -1 Error
 * @return status
 */
int8_t IoExpander::startCalcCrc(const uint32_t size)
{
	//First set the size of the calibration so the remote CPU knows this
	int8_t status = i2c.ioExpanderWriteRegister(deviceAddress, REGISTER_CALIBRATION_SIZE, size);
	if (status < 0)
	{
		return status;
	}/* Error, cancel ------------------------------------------> */

	//Then let the remote CPU start the calculation. Here we do not wait until this is finished.
	status = i2c.ioExpanderWriteRegister(deviceAddress, REGISTER_CALIBRATION_CONTROL, MASK_CALIBRATION_CONTROL_FLAG_START_CRC_CALCULATION);

	return status;
}

/**
 * @brief Get the calibration CRC
 *
 * For the CRC details look at the documentation of the OMS firmware.
 *
 * To have a valid CRC previously do:
 * - call function "startCalcCrc"
 * - Wait until the CRC calculation is finished, e.g. "waitBlockingFlashBusy"
 *
 * @return CRC
 */
uint32_t IoExpander::getCalibrationCrc() const
{
	uint32_t crc;

	(void)i2c.ioExpanderReadRegister(deviceAddress, REGISTER_CALIBRATION_CHECKSUM, &crc);

	return crc;
}

/**
 * @brief Set the LED pattern
 *
 * Look at the documentation of the OMS for details about the LED pattern.
 *
 * @param pattern LED pattern
 * @retval 0 OK
 * @retval -1 Communication error
 * @return Status
 */
int8_t IoExpander::setLedPattern(const uint8_t pattern)
{
	int8_t status = i2c.ioExpanderWriteRegister(deviceAddress, REGISTER_GENERAL_STATUS_LED, pattern);

	return status;
}

/**
 * @brief Read the firmware release of the IO expander on the OMS
 *
 *
 * @retval 0 Read failed
 * @return Firmware release
 */
uint32_t IoExpander::getFirmwareRelease() const
{
	uint32_t firmwareRelease;

	int8_t status = i2c.ioExpanderReadRegister(deviceAddress, REGISTER_GENERAL_FIRMWARE_RELEASE, &firmwareRelease);
  if (status < 0)
	{
    return 0;
	}/* Error, cancel ------------------------------------------> */

  return firmwareRelease;
}

/** @} */
