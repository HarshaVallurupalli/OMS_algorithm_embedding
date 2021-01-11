/***
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @addtogroup grayscale_compensation
 */
#include <GrayscaleCompensation/GrayscaleCompensation.h>
#include "Calibration/GrayscaleCalibrationTypes.h"
#include "fpga.h"

GrayscaleCompensation::GrayscaleCompensation()
{

}

/**
 * @brief Do the grayscale compensation
 *
 * This function takes the raw grayscale value from the sensor and compensates it.
 *
 * Function here only to test the software. This is later done in the soft logic
 *
 *
 * @param grayscale Raw grayscale data from the sensor
 * @param pixelIndex Index of the pixel, e.g. 0..75799
 * @return compensated grayscale data in range 0..2047
 */
uint32_t GrayscaleCompensation::calcCorrectedGrayscale(const uint32_t grayscale, const uint32_t pixelIndex)
{
  grayscaleCalibration_u *p8Bit = reinterpret_cast<grayscaleCalibration_u *>(pCalibrationData);

  //Restore the two values from the calibration data byte
  int32_t dsnu = p8Bit[pixelIndex].nibbles.low_dsnu;
  int32_t prnu = p8Bit[pixelIndex].nibbles.high_prnu;

  dsnu *= CALIBRATION_DATA_DIVIDER;
  prnu *= CALIBRATION_DATA_DIVIDER;

  int32_t valueAtZero = VALUE_PIXEL_NO_LIGHT + dsnu;
  int32_t valueAtHalf = VALUE_PIXEL_HALF_LIGHT + prnu + dsnu;

  int32_t grayscaleDifference = grayscale - valueAtZero;

  if (grayscaleDifference < 0)
  {
    grayscaleDifference = 0;
  }

  int32_t correctedValue = (grayscaleDifference * (VALUE_PIXEL_HALF_LIGHT - VALUE_PIXEL_NO_LIGHT)) / (valueAtHalf - valueAtZero);

  //Limit
  if (correctedValue > 2047)
  {
    correctedValue = 2047;
  }

  return static_cast<uint32_t>(correctedValue);
}

/**
 * @brief Set the calibration data address
 *
 * Call this before running any grayscale compensation
 *
 * @param address Address of the grayscale calibration (in the flash)
 */
void GrayscaleCompensation::setCalibrationAddress(const uint32_t address)
{
	pCalibrationData = reinterpret_cast<uint32_t *>(address);

	uint16_t *pFill = (uint16_t *)grayscaleTable;

	grayscaleCalibration_u *pTest = reinterpret_cast<grayscaleCalibration_u *>(address);
//

	//Just some tests so far. Not yet usable

	uint32_t index = 0;
	for (uint32_t i = 0; i < 76800; i += 2)
	{
	  //pTest[i] = (1 << 4) | 5;
	  //pTest[i] = (0 << 4) | 0;

	  //grayscaleTable[i] = (pTest[i+0].value << 8) | pTest[i+1].value;

	  grayscaleCalibration_u value0;
	  grayscaleCalibration_u value1;

	  //value0.nibbles.high_prnu = 0;
	  //value1.nibbles.high_prnu = 0;
	  //value0.nibbles.low_dsnu = 6;
	  //value1.nibbles.low_dsnu = 6;

	  value1 = pTest[i+0];
	  value0 = pTest[i+1];

	  //value0.nibbles.high_prnu = -6;
	  //value1.nibbles.high_prnu = -6;


	  grayscaleTable[index] = (value0.value << 8) | value1.value;
	  index++;

	  //pFill[i] = (pTest[i+0].value << 8) | pTest[i+1].value;
	}


//	//This is just a test to check the values. Later just the memory address needs to be handed over to the soft logic and that one does all the calculations
	for (uint32_t i = 0; i < 76800; i++)
	{
		int32_t dsnu = pTest[i].nibbles.low_dsnu;
		int32_t prnu = pTest[i].nibbles.high_prnu;
		asm("nop");
	}
}

/**
 * @brief Get the calibration address
 *
 * @return Pointer to the calibration data
 */
uint32_t *GrayscaleCompensation::getCalibrationAddress() const
{
  return const_cast<uint32_t *>(grayscaleTable);
}

/** @} */
