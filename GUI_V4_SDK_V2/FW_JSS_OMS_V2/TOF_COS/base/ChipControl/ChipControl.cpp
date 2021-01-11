/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 *
 * @addtogroup chip_control
 *
 * @{
 */
#include "ChipControl.h"
#include "registers.h"
#include <stdlib.h>
#include <string.h>
#include "tof_cos_io.h"
#include "tof_cos_i2c.h"


ChipControl::ChipControl()
{
	register0xD3 = 0;
	register0xD5 = 0;
	register0xE9 = 0;
	deviceAddress = 0;
}

/**
 * @brief Set the device address of the chip
 *
 * This function sets the device address of the chip.
 * In addition, the registers needed to be read at startup are read and the temperature calibration value is also read.
 *
 * If no chip is found, an error is thrown.
 *
 * @param deviceAddress I2C address of the chip
 * @retval TypeInternalReturnValue::STATUS_ERROR_DEVICE_NOT_PRESENT Device not found
 * @retval TypeInternalReturnValue::STATUS_OK Everything done successfully
 * @return Result
 */
TypeInternalReturnValue ChipControl::setDeviceAddress(const uint16_t deviceAddress)
{
  //Check, if the device was found during init. Else the operation is not possible anyway
	if (tofCosI2cDeviceIsPresent(deviceAddress) == false)
  {
  	return TypeInternalReturnValue::STATUS_ERROR_DEVICE_NOT_PRESENT;
  }

	this->deviceAddress = deviceAddress;

  initRegisters();
	initRegistersSpecific();

  return TypeInternalReturnValue::STATUS_OK;
}

/**
 * @brief Init registers
 *
 * This is a basic function for all types of imagers. Some registers need to be read at startup, some
 * need to be written to the values to operate. Specific registers for a tof imager need to be implemented in
 * the sub classes, for example "ChipControlEpc660".
 */
void ChipControl::initRegisters()
{
	chipId = readChipId();
	waferId = readWaferId();

	//Grayscale differential readout
	writeRegister(GRAYSCALE_READOUT_MODE, 0x00);
}

/**
 * @brief Send shutter to the chip
 *
 * This function sends the shutter to the chip using I2C
 *
 * Possible improvements: Use a GPIO instead
 */
void ChipControl::sendShutter()
{
	tofCosI2cWriteByte(deviceAddress, SHUTTER_CONTROL, MASK_SHUTTER);
}

/**
 * @brief Set the TOF chip to 3D mode shadowed
 *
 * This function can be called when an acquisition is running, because the chip has shadow registers and
 * loads the values on the next acquisition. The reason to have two functions is speed improvement.
 */
void ChipControl::setTo3dShadowed()
{
  //Set to 3D
	tofCosI2cWriteByte(deviceAddress, MOD_CONTROL, VALUE_MODE_3D);
	
  //Reset DCS composition
	//i2c.writeByte(deviceAddress, MT_0_HI, 0x30);
	//i2c.writeByte(deviceAddress, MT_1_HI, 0x3A);
}

/**
 * @brief Set the TOF chip to 3D mode not shadowed
 *
 * This function must only be called when not acquisition is running! It will write registers that have
 * an influence immediately. The reason to have two functions is speed improvement.
 */
void ChipControl::setTo3dUnShadowed()
{
  //This is specific in derived class
	setRegistersToTof();
}

/**
 * @brief Set the TOF chip to Grayscale mode shadowed
 *
 * This function can be called when an acquisition is running, because the chip has shadow registers and
 * loads the values on the next acquisition. The reason to have two functions is speed improvement.
 */
void ChipControl::setToGrayscaleShadowed()
{
	//Put to grayscale
	tofCosI2cWriteByte(deviceAddress, MOD_CONTROL, VALUE_MODE_GRAYSCALE);
	
  //Reset DCS composition
	//i2c.writeByte(deviceAddress, MT_0_HI, 0x30);
	//i2c.writeByte(deviceAddress, MT_1_HI, 0x3A);
}

/**
 * @brief Set the TOF chip to grayscale mode not shadowed
 *
 * This function must only be called when not acquisition is running! It will write registers that have
 * an influence immediately. The reason to have two functions is speed improvement.
 */
void ChipControl::setToGrayscaleUnShadowed()
{
	//This is specific to the chip in derived class
	setRegistersToGrayscale();
}

/**
 * @brief Set the TOF chip to DualMGX mode
 *
 */
void ChipControl::setToDualMGX()
{
  //This is specific in derived class
	setRegistersToTof();

  //Set to 3D
	tofCosI2cWriteByte(deviceAddress, MOD_CONTROL, VALUE_MODE_DUALMGX);
	
  //Correct DCS composition
	//i2c.writeByte(deviceAddress, MT_0_HI, 0x31);
	//i2c.writeByte(deviceAddress, MT_1_HI, 0x3B);
}

/**
 * @brief Set the integration time
 *
 * The integration time registers and the multiplier are calculated. As long as the multiplier can be 1 it stays there.
 * Only for big integration times it is higher than 1. The calculation of the integration time depends on the modulation
 * clock input. Therefore that one is given as parameter.
 *
 * @param us Integration time in microseconds
 * @param modulationClockInput Modulation clock (Hz) that is at the chip input --> higher than the modulation clock of the illumination
 */
void ChipControl::setIntegrationTime(const uint16_t us, const uint32_t modulationClockInput)
{
	//Try to use multiplier 1
	integrationTimeMultiplier = 1;
	int16_t integrationTimeRegisters = (us * (modulationClockInput / 1000)) / (1000 * (modulationClockDivider + 1));

	//If this does not fit, set the multiplier to the needed value
	if (integrationTimeRegisters > 0xFFFF)
	{
		integrationTimeMultiplier = (integrationTimeRegisters / 0xFFFF) + 1;
		integrationTimeRegisters /= integrationTimeMultiplier;
	}

	if (integrationTimeRegisters > 0)
	{
	  integrationTimeRegisters -= 1;
	}

	uint8_t dataToWrite[4];

	//Combine to a single buffer
	dataToWrite[0] = (integrationTimeMultiplier >> 8);
	dataToWrite[1] = (integrationTimeMultiplier & 0xFF);
	dataToWrite[2] = (integrationTimeRegisters >> 8);
	dataToWrite[3] = (integrationTimeRegisters & 0xFF);

	//All bytes can be written at once because they have a sequence of addresses
	tofCosI2cWriteBuffer(deviceAddress, INTM_HI, 4, dataToWrite);
}

/**
* @brief Set dual integration time
*
* The integration time registers and the multiplier are calculated. As long as the multiplier can be 1 it stays there.
* Only for big integration times it is higher than 1. The calculation of the integration time depends on the modulation
* clock input. Therefore that one is given as parameter.
*
* @param us0 Integration time 0 in microseconds
* @param us1 Integration time 1 in microseconds
* @param modulationClockInput Modulation clock (Hz) that is at the chip input --> higher than the modulation clock of the illumination
*/
void ChipControl::setIntegrationTime1(const uint16_t us0, const uint16_t us1, const uint32_t modulationClockInput)
{
	uint16_t timeHigh = us0;
	uint16_t timeLow = us1;

	if (timeHigh < us1)
	{
		timeHigh = us1;
		timeLow = us0;
	}

	//Try to use multiplier 1
	integrationTimeMultiplier = 1;
	int16_t integrationTimeRegisters = (timeHigh * (modulationClockInput / 1000)) / (1000 * (modulationClockDivider + 1));

	//If this does not fit, set the multiplier to the needed value
	if (integrationTimeRegisters > 0xFFFF)
	{
		integrationTimeMultiplier = (integrationTimeRegisters / 0xFFFF) + 1;
		integrationTimeRegisters /= integrationTimeMultiplier;
	}

	integrationTimeRegisters -= 1;

	uint8_t dataToWrite[4];

	//Combine to a single buffer
	dataToWrite[0] = (integrationTimeMultiplier >> 8);
	dataToWrite[1] = (integrationTimeMultiplier & 0xFF);
	dataToWrite[2] = (integrationTimeRegisters >> 8);
	dataToWrite[3] = (integrationTimeRegisters & 0xFF);

	//Write first integration time with multiplier
	tofCosI2cWriteBuffer(deviceAddress, INTM_HI, 4, dataToWrite);


	integrationTimeRegisters = (timeLow * (modulationClockInput / 1000)) / (1000 * (modulationClockDivider + 1));
	integrationTimeRegisters /= integrationTimeMultiplier;

	dataToWrite[0] = (integrationTimeRegisters >> 8);
	dataToWrite[1] = (integrationTimeRegisters & 0xFF);

	//Write second integration time (without multiplier)
	tofCosI2cWriteBuffer(deviceAddress, INT_LEN_MGX_HI, 2, dataToWrite);
}

/**
 * @brief Set the modulation clock divider
 *
 * This function sets the modulation clock divider.
 * resulting clock = MOD_CLOCK / (divider + 1)
 *
 * @param divider Divider to set
 */
void ChipControl::setModClockDivider(const uint8_t divider)
{
	modulationClockDivider = divider;
	tofCosI2cWriteByte(deviceAddress, MOD_CLK_DIVIDER, divider);
}

/**
 * @brief Sets the number of DCSs
 *
 * @param nDCS number of DCSs
 */
void ChipControl::setDCS(uint8_t nDCS)
{
	uint8_t i2cData;

	//Prepare the value according to the data sheet (calculation + shift)
	uint8_t tempNumDcs = nDCS;
	tempNumDcs = (tempNumDcs - 1) << 4;

	//Read the actual register value
	tofCosI2cReadByte(deviceAddress, MOD_CONTROL, &i2cData);

	//Clear the bits
	i2cData &= 0xCF;

	//Set to the wanted value
	i2cData |= tempNumDcs;

	//Now write it back to the chip
	tofCosI2cWriteByte(deviceAddress, MOD_CONTROL, i2cData);
}

/**
 * @brief Bypass DLL or not
 *
 * This function helps to bypass the DLL.
 *
 * @param bypass Bypass DLL or not (true/false)
 */
void ChipControl::setBypassDll(const bool bypass)
{
	uint8_t dllControl;
	tofCosI2cReadByte(deviceAddress, DLL_CONTROL, &dllControl);

	if (bypass)
	{
		dllControl = dllControl | MASK_DLL_BYPASS;
	}
	else
	{
		dllControl = dllControl & ~MASK_DLL_BYPASS;
	}

	tofCosI2cWriteByte(deviceAddress, DLL_CONTROL, dllControl);
}


/**
 * @brief Set HDR mode
 *
 * Enable or disable the HDR mode on the chip
 *
 *
 * @param enabled Hdr mode enabled or disabled
 */
void ChipControl::setHdrMode(const bool enabled)
{
	uint8_t modulationSelect;
	uint8_t resolutionReductionRegister;

	tofCosI2cReadByte(deviceAddress, RESOLUTION_REDUCTION, &resolutionReductionRegister);
	tofCosI2cReadByte(deviceAddress, MOD_CONTROL, &modulationSelect);

	if (enabled)
  {
		modulationSelect |= MASK_HDR;
		resolutionReductionRegister |= MASK_DUAL_MGX;
  }
	else
	{
    modulationSelect &= ~MASK_HDR;
    resolutionReductionRegister &= ~MASK_DUAL_MGX;
	}

	tofCosI2cWriteByte(deviceAddress, MOD_CONTROL, modulationSelect);
	tofCosI2cWriteByte(deviceAddress, RESOLUTION_REDUCTION, resolutionReductionRegister);
}

/**
 * @brief Set ABS
 *
 * Enable or disable the ABS (ambient-light suppression) on the chip
 *
 *
 * @param enabled Hdr mode enabled or disabled
 */
void ChipControl::setAbs(const bool enabled)
{
	uint8_t addresses[4];


	addresses[0] = MT_0_HI;
	addresses[1] = MT_1_HI;
	addresses[2] = MT_2_HI;
	addresses[3] = MT_3_HI;

	for (uint8_t i = 0; i < 4; i++)
	{
		uint8_t registerValue;
		tofCosI2cReadByte(deviceAddress, addresses[i], &registerValue);

		if (enabled)
		{
		  registerValue |= MASK_ABS_ENABLED;
		}
		else
		{
      registerValue &= ~(MASK_ABS_ENABLED);
		}

		tofCosI2cWriteByte(deviceAddress, addresses[i], registerValue);
	}
}

/**
 * @brief Set LED behavior during grayscale acquisition
 *
 * @param enabled Set to true to enable the LED during grayscale acquisition
 * @param modulated Set to true to modulate the LED during grayscale acquisition (only if enabled is true, too).
 */
void ChipControl::setLedGrayscale(const bool enabled, const bool modulated)
{
	uint8_t registerValue;
	tofCosI2cReadByte(deviceAddress, MODULATION_CONTROL_GRAYSCALE, &registerValue);

	//Set default values
	registerValue |= MASK_LED_OFF_GRAYSCALE;
	registerValue &= ~MASK_LED_ON_GRAYSCALE;

	//Change bits if needed
	if (enabled)
  {
		registerValue &= ~MASK_LED_OFF_GRAYSCALE;

		if (modulated == false)
    {
    	registerValue |= MASK_LED_ON_GRAYSCALE;
    }
  }

	tofCosI2cWriteByte(deviceAddress, MODULATION_CONTROL_GRAYSCALE, registerValue);
}


/**
 * @brief Enable or disable manual DLL
 *
 * This function helps to enable or disable the manual DLL (delay locked loop) of the chip.
 *
 * @param manual Enable or disable manual control (true/false)
 */
void ChipControl::setManualDll(const bool manual)
{
	uint8_t dllControl;
	tofCosI2cReadByte(deviceAddress, DLL_CONTROL, &dllControl);

	if (manual)
	{
		dllControl = dllControl | MASK_DLL_CTRL_EXT;
	}
	else
	{
		dllControl = dllControl & ~MASK_DLL_CTRL_EXT;
	}

	tofCosI2cWriteByte(deviceAddress, DLL_CONTROL, dllControl);
}

/**
 * @brief Set the coarse step of the dll
 *
 * @param step DLL step
 */
void ChipControl::setDllCoarseStepExt(const uint8_t step)
{
	uint8_t dllStep = step;

	tofCosI2cWriteByte(deviceAddress, DLL_COARSE_CTRL_EXT, dllStep);
}

/**
 * @brief Enable or disable manual DLL control
 *
 * This is the public function to set the DLL to manual or not. It manages everything.
 *
 * @param manual Manual control or not
 */
void ChipControl::setDllManual(const bool manual)
{
  if (manual)
  {
  	setBypassDll(false);
  	setManualDll(true);
  }
  else
  {
  	setManualDll(false);
  	setBypassDll(true);
  }
}

/**
 * @brief Set the vertical binning
 *
 * @param binning vertical binning enabled or not
 */
void ChipControl::setVerticalBinning(const bool binning)
{
	uint8_t resolutionReductionRegister;

	tofCosI2cReadByte(deviceAddress, RESOLUTION_REDUCTION, &resolutionReductionRegister);

	if (binning)
  {
    resolutionReductionRegister |= MASK_VERTICAL_BINNING;
    resolutionReductionRegister |= MASK_ROW_REDUCTION;
  }
  else
  {
  	resolutionReductionRegister &= ~MASK_VERTICAL_BINNING;
  	resolutionReductionRegister &= ~MASK_ROW_REDUCTION;
  }

	tofCosI2cWriteByte(deviceAddress, RESOLUTION_REDUCTION, resolutionReductionRegister);
}

/**
 * @brief Set the horizontal binning
 *
 * @param binning horizontal binning enabled or not
 */
void ChipControl::setHorizontalBinning(const bool binning)
{
	uint8_t resolutionReductionRegister;

	tofCosI2cReadByte(deviceAddress, RESOLUTION_REDUCTION, &resolutionReductionRegister);

	if (binning)
	{
		resolutionReductionRegister |= MASK_HORIZONTAL_BINNING;
		resolutionReductionRegister |= MASK_COLUMN_REDUCTION;
	}
	else
	{
		resolutionReductionRegister &= ~MASK_HORIZONTAL_BINNING;
		resolutionReductionRegister &= ~MASK_COLUMN_REDUCTION;
	}

	tofCosI2cWriteByte(deviceAddress, RESOLUTION_REDUCTION, resolutionReductionRegister);
}

/**
 * @brief Enable or disable the Led2 pin
 *
 * @param enabled Led2 pin enabled or not
 */
void ChipControl::setLed2Pin(const bool enabled)
{
	uint8_t ledDriverRegister;
	tofCosI2cReadByte(deviceAddress, LED_DRIVER, &ledDriverRegister);

	if (enabled)
	{
		ledDriverRegister = ledDriverRegister | MASK_LED_2;
	}
	else
	{
		ledDriverRegister = ledDriverRegister & ~MASK_LED_2;
	}

	tofCosI2cWriteByte(deviceAddress, LED_DRIVER, ledDriverRegister);
}

/**
 * @brief Enable or disable the Led pin
 *
 * @param enabled Led pin enabled or not
 */
void ChipControl::setLedPin(const bool enabled)
{
	uint8_t ledDriverRegister;
	tofCosI2cReadByte(deviceAddress, LED_DRIVER, &ledDriverRegister);

	if (enabled)
	{
		ledDriverRegister = ledDriverRegister | MASK_LED;
	}
	else
	{
		ledDriverRegister = ledDriverRegister & ~MASK_LED;
	}

	tofCosI2cWriteByte(deviceAddress, LED_DRIVER, ledDriverRegister);
}

/**
 * @brief Invert the LED pins
 *
 * @param inverted LED pin inverted or not
 */
void ChipControl::setLedPinInveted(const bool inverted)
{
	uint8_t ledDriverRegister;
	tofCosI2cReadByte(deviceAddress, LED_DRIVER, &ledDriverRegister);

	if (inverted)
	{
	  ledDriverRegister = ledDriverRegister | MASK_LED_INVERTED;
	}
	else
	{
	  ledDriverRegister = ledDriverRegister & ~MASK_LED_INVERTED;
	}

	tofCosI2cWriteByte(deviceAddress, LED_DRIVER, ledDriverRegister);
}

/**
 * @brief Enable or disable the external modulation clock
 *
 * @param enabled External modulation clock enabled or not
 */
void ChipControl::setExternalModulationClock(const bool enabled)
{
	uint8_t clockControl;
	tofCosI2cReadByte(deviceAddress, CLK_ENABLES, &clockControl);

	if (enabled)
	{
		clockControl = clockControl | MASK_EXTERNAL_MODULATION_CLOCK;
	}
	else
	{
		clockControl = clockControl & ~MASK_EXTERNAL_MODULATION_CLOCK;
	}

	tofCosI2cWriteByte(deviceAddress, CLK_ENABLES, clockControl);
}

/**
 * @brief Read a register of the TOF chip
 *
 * This function helps to read a register of the chip.
 *
 * @param registerAddress Register to read from
 * @return Value read from the chip
 */
uint8_t ChipControl::readRegister(const uint8_t registerAddress)
{
	uint8_t value;
	tofCosI2cReadByte(deviceAddress, registerAddress, &value);
	return value;
}

/**
 * @brief Write a register of the TOF chip
 *
 * This function helps to write a register of the chip.
 *
 * @param registerAddress Register to write to
 * @param value Value to write into the register
 */
void ChipControl::writeRegister(const uint8_t registerAddress, const uint8_t value)
{
	uint8_t tempValue = value;
	tofCosI2cWriteByte(deviceAddress, registerAddress, tempValue);
}

/**
 * @brief Get the chip ID
 *
 * This chip ID was read at startup.
 *
 * @return chip ID
 */
uint16_t ChipControl::getChipId() const
{
	return chipId;
}

/**
 * @brief Get the wafer ID
 *
 * This wafer ID was read at startup.
 *
 * @return wafer ID
 */
uint16_t ChipControl::getWaferId() const
{
	return waferId;
}

/**
 * @brief Get the integration time length
 *
 * Function to get the integration time length. Used for ambient light calibration
 *
 * @return Integration time length
 */
uint16_t ChipControl::getIntegrationTimeLength()
{
  uint8_t dataToRead[2];

  tofCosI2cReadBuffer(deviceAddress, INT_LEN_HI, 2, dataToRead);

  uint16_t length = (dataToRead[0] << 8) | dataToRead[1];

  return length;
}

/**
 * @brief Get the integration time multiplier
 *
 * Function to get the integration time multiplier. Used for ambient light calibration
 *
 * @return Integration time multiplier
 */
uint16_t ChipControl::getIntegrationTimeMultiplier()
{
  return integrationTimeMultiplier;
}

/**
 * @brief Set the integration time registers
 *
 * Function to set all the integration time registers. Used for ambient light calibration
 *
 * @param length Length so set
 * @param multiplier Multiplier to set
 */
void ChipControl::setIntegrationTimeRegisters(const uint16_t length, const uint16_t multiplier)
{
	uint8_t dataToWrite[4];

	this->integrationTimeMultiplier = multiplier;

	dataToWrite[0] = (multiplier >> 8);
  dataToWrite[1] = (multiplier & 0xFF);
  dataToWrite[2] = (length >> 8);
  dataToWrite[3] = (length & 0xFF);

  //Write first integration time with multiplier
  tofCosI2cWriteBuffer(deviceAddress, INTM_HI, 4, dataToWrite);
}

/**
 * @brief Read data from the eeprom
 *
 *
 * @param registerAddress Register address to read
 * @param numBytes Number of bytes to read
 * @param pData Pointer to the buffer to put the bytes
 * @return wafer ID
 */
void ChipControl::readFromEeprom(const uint8_t registerAddress, const uint32_t numBytes, uint8_t *pData)
{
	tofCosI2cWriteByte(deviceAddress, EE_ADDR, registerAddress);

	for (uint32_t i = 0; i < numBytes; i++)
	{
		tofCosI2cReadByte(deviceAddress, EE_DATA, &pData[i]);
	}
}

/**
 * @brief Read the wafer ID
 *
 *
 * @return wafer ID
 */
uint16_t ChipControl::readWaferId()
{
	uint8_t data[2];

	readFromEeprom(WAFER_ID_MSB, 2, data);

	uint16_t WaferId = (data[0] << 8) | data[1];

	return WaferId;
}

/**
 * @brief Read the chip ID
 *
 *
 * @return chip ID
 */
uint16_t ChipControl::readChipId()
{
	uint8_t data[2];

	readFromEeprom(CHIP_ID_MSB, 2, data);

	uint16_t chipId = (data[0] << 8) | data[1];

	return chipId;
}

/**
 * @brief Get status and clear it
 *
 * This function is used to get the status of this class and in case of an error, clear it.
 * The intention is, that the error has not to be read on every function call, so it can for
 * example be read once per image.
 *
 *
 * @retval TypeInternalReturnValue::STATUS_ERROR_COMMUNICATION There was a communication error since the last call
 * @retval TypeInternalReturnValue::STATUS_OK No error happened
 * @return Status of this class
 */
TypeInternalReturnValue ChipControl::getAndClearStatus()
{
	int8_t i2cStatus = tofCosI2cGetAndClearStatus();
  if (i2cStatus != 0)
  {
  	return TypeInternalReturnValue::STATUS_ERROR_COMMUNICATION;
  }
  return TypeInternalReturnValue::STATUS_OK;
}

/**
 * @brief Initialize this class
 *
 * This function initializes this class. It has to be called before using anything
 * else.
 *
 * The EPC chip is reset first, and then, the I2C is initialized. On initialization of
 * the I2C, the devices are scanned, so the EPC chip has to be ready.
 *
 * @retval TypeInternalReturnValue::STATUS_ERROR_GENERAL Initialization failed
 * @retval TypeInternalReturnValue::STATUS_OK Initialization done successfully
 * @return Result of the initialization
 */
TypeInternalReturnValue ChipControl::init()
{
	tofCosIoResetEpcChip();

	int8_t status = tofCosI2cInit();
	if (status < 0)
	{
		return TypeInternalReturnValue::STATUS_ERROR_GENERAL;
	}

	return TypeInternalReturnValue::STATUS_OK;
}

/** @} */
