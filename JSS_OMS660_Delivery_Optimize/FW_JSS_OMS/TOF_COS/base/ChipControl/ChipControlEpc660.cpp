/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 *
 * @addtogroup chip_control_epc660
 *
 * @{
 */
#include <ChipControl/ChipControlEpc660.h>
#include <GlobalSettings.h>
#include <TOF_COS_Constants.h>
#include "ChipControl/registers.h"
#include "TOF_COS_Config.h"
#include "ChipSelection.h"
#include "tof_cos_io.h"
#include "tof_cos_i2c.h"

/**
 * @brief Init the chip
 *
 *
 * @return Value from TypeInternalReturnValue
 */
TypeInternalReturnValue ChipControlEpc660::initChip()
{
	tofCosI2cWriteByte(deviceAddress, SEQ_CONTROL, 0x03); // Enable pixel and TCMI sequencers.

	//Set DCS order to 0, 2, 1, 3
	tofCosI2cWriteByte(deviceAddress, MT_1_HI, 0x3A); // Swap DCS1 and DCS2
	tofCosI2cWriteByte(deviceAddress, MT_2_HI, 0x35); // Swap DCS1 and DCS2

	setExternalModulationClock(true);

	setLed2Pin(TOF_COS_USE_LED_2_PIN);
	setLedPin(TOF_COS_USE_LED_PIN);
	setLedPinInveted(TOF_COS_INVERT_LED);

	setBypassDll(false);
	setManualDll(true);
	setDllCoarseStepExt(TOF_COS_DLL_STEP_OPERATION);

	//TCMI speed
	tofCosI2cWriteByte(deviceAddress, TCMI_CLK_DIVIDER, TOF_COS_TCMI_CLK_DIVIDER);

	//In case of slow TCMI clock avoid readout rollover by a special register setting. This is needed below 20MHz.
	if (TOF_COS_TCMI_CLK_DIVIDER > 3)
	{
	  tofCosI2cWriteByte(deviceAddress, 0x91, 0x43);
	}

	//TCMI settings
	tofCosI2cWriteByte(deviceAddress, TCMI_POLARITY, TOF_COS_TCMI_SETTINGS);

	return TypeInternalReturnValue::STATUS_OK;
}

/**
 * @brief Read the temperature of the TOF imager
 *
 * This function returns the current temperature of the TOF imager. Therefore it reads the two needed
 * registers of the sensor and calculates the temperature using the formula provided in the datasheet.
 *
 * The resulting temperature is the average of the four temperature sensors.
 *
 * The temperature is in a fixed point format, shifted by 10Bits.
 *
 * @return Current chip temperature in fixed point format
 */
int32_t ChipControlEpc660::readTemperature()
{
	uint8_t array_TH[4];
	uint8_t array_TL[4];
	int32_t temperature[4];

	tofCosI2cReadByte(deviceAddress, TEMP_TOP_LEFT_REGISTER_HIGH, &array_TH[0]);
	tofCosI2cReadByte(deviceAddress, TEMP_TOP_LEFT_REGISTER_LOW, &array_TL[0]);
	tofCosI2cReadByte(deviceAddress, TEMP_TOP_RIGHT_REGISTER_HIGH, &array_TH[1]);
	tofCosI2cReadByte(deviceAddress, TEMP_TOP_RIGHT_REGISTER_LOW, &array_TL[1]);
	tofCosI2cReadByte(deviceAddress, TEMP_BOTTOM_LEFT_REGISTER_HIGH, &array_TH[2]);
	tofCosI2cReadByte(deviceAddress, TEMP_BOTTOM_LEFT_REGISTER_LOW, &array_TL[2]);
	tofCosI2cReadByte(deviceAddress, TEMP_BOTTOM_RIGHT_REGISTER_HIGH, &array_TH[3]);
	tofCosI2cReadByte(deviceAddress, TEMP_BOTTOM_RIGHT_REGISTER_LOW, &array_TL[3]);

  for (uint8_t i = 0; i < 4; i++)
  {
	  //This formula is from the data sheet. Here it is calculated without floating point, just shifted by 10Bits
    temperature[i] = ((array_TH[i] * 0x0100) + (array_TL[i] - 0x2000)) * TEMPERATURE_MULTIPLIER + temperatureCalibrationValue[i];
  }

  //Sum up all 4 temperatures
  int32_t temperatureSum = 0;
  for (uint8_t i = 0; i < 4; i++)
  {
  	temperatureSum += temperature[i];
  }

  //Calculate the average
  int32_t finalTemperature = temperatureSum / 4;

  return finalTemperature;
}

/**
 * @brief Init registers
 *
 * This function reads at system start all registers that are needed later during operation
 * Most of them are used for temperature readout.
 */
void ChipControlEpc660::initRegistersSpecific()
{
  //Read these registers to be able to readout the temperature
  register0xD3 = readRegister(0xD3);
  register0xD5 = readRegister(0xD5);
  register0xDA = readRegister(0xDA);
  register0xDC = readRegister(0xDC);

  //Read register for the DLL state temperature compensation
  register0xE9 = readRegister(0xE9);

  //Temporary array The same names as in the datasheet.
  uint8_t array_C[4];

  //Read the calibration value for the temperature
  array_C[0] = readRegister(0xE8);
  array_C[1] = readRegister(0xEA);
  array_C[2] = readRegister(0xEC);
  array_C[3] = readRegister(0xEE);

  //For each temperature sensor calculate the calibration value
  for (uint8_t i = 0; i < 4; i++)
  {
  	//Calculate the value according to the data sheet
    double temp = ((double)array_C[i] / 4.7) - 0x12B;

    //Make a fixed point value --> "shift" it up by 10Bits
    temperatureCalibrationValue[i] = (int32_t) (temp * (double)(1 << TEMPERATURE_CALC_SHIFT));
  }
}

/**
 * @brief Set registers to TOF
 *
 * Writes register values needed for TOF operation.
 */
void ChipControlEpc660::setRegistersToTof()
{
	//Restore the registers that were changed to read the temperature (read grayscale image). This is just following the data sheet.
	tofCosI2cWriteByte(deviceAddress, 0xD3, register0xD3);
	tofCosI2cWriteByte(deviceAddress, 0xD5, register0xD5);
	tofCosI2cWriteByte(deviceAddress, 0xDA, register0xDA);
	tofCosI2cWriteByte(deviceAddress, 0xDC, register0xDC);
}

/**
 * @brief Set registers to grayscale
 *
 * Writes register values needed for grayscale operation.
 */
void ChipControlEpc660::setRegistersToGrayscale()
{
  uint8_t data;

	//Set bit 5 and 6 to be able to read the temperature (look at datasheet)
	data = register0xD3 | 0x60;
	tofCosI2cWriteByte(deviceAddress, 0xD3, data);

	//Clear bit 4 and 5 to be able to read the temperature (look at datasheet)
	data = register0xD5 & 0x0F;
	tofCosI2cWriteByte(deviceAddress, 0xD5, data);

	//Set bit 5 and 6 to be able to read the temperature (look at datasheet)
	data = register0xDA | 0x60;
	tofCosI2cWriteByte(deviceAddress, 0xDA, data);

	//Clear bit 4 and 5 to be able to read the temperature (look at datasheet)
	data = register0xDC & 0x0F;
	tofCosI2cWriteByte(deviceAddress, 0xDC, data);
}

/**
 * @brief Set the ROI (region of interest of the chip)
 *
 * This sets the ROI of the chip. The new ROI is taken on the next acquisition.
 *
 * @param xMin X coordinate top left
 * @param yMin Y coordinate top left
 * @param xMax X coordinate bottom right
 * @param yMax y coordinate bottom right
 */
void ChipControlEpc660::setRoi(const uint16_t xMin, const uint16_t yMin, const uint16_t xMax, const uint16_t yMax)
{
	uint16_t xMinFinal = xMin + ROI_X_BORDER;
	uint16_t xMaxFinal = xMax + ROI_X_BORDER;

	tofCosI2cWriteByte(deviceAddress, ROI_TL_X_HI, static_cast<uint8_t>(xMinFinal >> 8));
	tofCosI2cWriteByte(deviceAddress, ROI_TL_X_LO, static_cast<uint8_t>(xMinFinal & 0xFF));

	tofCosI2cWriteByte(deviceAddress, ROI_TL_Y, static_cast<uint8_t>(yMin + ROI_Y_BORDER));

	tofCosI2cWriteByte(deviceAddress, ROI_BR_X_HI, static_cast<uint8_t>(xMaxFinal >> 8));
	tofCosI2cWriteByte(deviceAddress, ROI_BR_X_LO, static_cast<uint8_t>(xMaxFinal & 0xFF));

	//bottom right y must always be half of the sensor, because the ROI is symmetrical (look at the datasheet)
	tofCosI2cWriteByte(deviceAddress, ROI_BR_Y, static_cast<uint8_t>((HEIGTH / 2) - 1 + ROI_Y_BORDER));
}

/**
 * @brief Set minimal ROI
 *
 * Set the minimal ROI. This is used if an image is only taken to get the temperature (grayscale image). To improve
 * speed, the smallest ROI is used.
 */
void ChipControlEpc660::setMinimalRoi()
{
	uint16_t xMinFinal = 0 + ROI_X_BORDER;
	uint16_t xMaxFinal = 5 + ROI_X_BORDER;
	uint16_t yMin = 0;
	uint16_t yMax = 1;

	tofCosI2cWriteByte(deviceAddress, ROI_TL_X_HI, static_cast<uint8_t>(xMinFinal >> 8));
	tofCosI2cWriteByte(deviceAddress, ROI_TL_X_LO, static_cast<uint8_t>(xMinFinal & 0xFF));

	tofCosI2cWriteByte(deviceAddress, ROI_TL_Y, static_cast<uint8_t>(yMin + ROI_Y_BORDER));

	tofCosI2cWriteByte(deviceAddress, ROI_BR_X_HI, static_cast<uint8_t>(xMaxFinal >> 8));
	tofCosI2cWriteByte(deviceAddress, ROI_BR_X_LO, static_cast<uint8_t>(xMaxFinal & 0xFF));

	tofCosI2cWriteByte(deviceAddress, ROI_BR_Y, static_cast<uint8_t>(yMax + ROI_Y_BORDER));
}

/** @} */
