/***
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @addtogroup drnu_compensation
 */
#include <DrnuCompensation/DrnuCompensation.h>
#include "Calibration/DrnuCalibrationDataHelper.h"
#include "fpga.h"
#include "TOF_COS_Config.h"

bool DrnuCompensation::verificationMode = false;

DrnuCompensation::DrnuCompensation()
{
	calibrationAddress = 0;
	atanOffset = 0;
	dllStepDistance = 0;
	numDllStepsFpga = 0;
	distanceRange = 0;
	offsetOnly = false;
	offset = 0;
}

/**
 * @brief Enabled or disable verification mode
 *
 * If the verification mode is enabled:
 * - The calibration offset is not added
 *
 * @param verificationMode Enable or disable verification mode
 */
void DrnuCompensation::setVerificationModeEnabled(const bool verificationMode)
{
	this->verificationMode = verificationMode;
}

/**
 * @brief Get the offset
 *
 * In verification mode the offset is zero.
 *
 * @return offset
 */
int32_t DrnuCompensation::getOffset() const
{
	if (verificationMode)
	{
		return 0;
	}

	return offset;
}

/**
 * @brief Set calibration address
 *
 * The calibration address needs to be set before using this class.
 *
 * @param address Address of the calibration
 */
void DrnuCompensation::setCalibrationAddress(const uint32_t address)
{
	this->calibrationAddress = address;

	update();
}

/**
 * @brief Update calibration data
 *
 */
void DrnuCompensation::update()
{
  DrnuCalibrationDataHelper calibrationDataHelper(calibrationAddress);

  if (calibrationDataHelper.checkHeaderValid())
  {
    fillTable(calibrationDataHelper);
  }
}

/**
 * @brief Load the FPGA
 *
 * Load the FPGA with data needed for the compensation. The FPGA does the compensation on the fly so this
 * needs to be done before the data acquisition.
 */
void DrnuCompensation::loadFpga()
{
	//Get the calibration offset. This is directly set into the atan calculation but with negative sign.
	fpgaSetPreCorrectionOffset(-atanOffset);

	fpgaSetDistanceRange(distanceRange);

	fpgaSetPreCorrectionOffsetEnabled(true);

	fpgaSetPostCorrectionOffsetEnabled(true);

	if (offsetOnly)
	{
		fpgaSetDistanceCorrectionEnabled(false);
	}
	else
	{
	  //Write the pointer to the calibration data
	  fpgaSetCorrectionAddress((uint32_t)drnuTable);

	  fpgaSetDllStep(dllStepDistance, numDllStepsFpga);

	  fpgaSetDistanceCorrectionEnabled(true);
	}
}

/**
 * @brief Fill the table
 *
 * In the flash memory for the calibration there is one byte used for each pixel. Here these values are used to fill
 * the LUT containing the distance values at calibration time.
 * These values are calculated back using the set distance and the error values from the flash.
 * The LUT contains 16Bit values.
 */
void DrnuCompensation::fillTable(DrnuCalibrationDataHelper &drnuCalibrationDataHelper)
{
	int32_t setDistance[50]; //enough for any case

  uint8_t numStepsCalibrated =  drnuCalibrationDataHelper.getNumStepsCalibrated();

  //The number of steps needs to be a multiplier of 4
  uint8_t additionalSteps = (4 - (numStepsCalibrated % 4)) % 4;

  uint16_t dllRange = drnuCalibrationDataHelper.getRange();


  //Store the following numbers to be able to use them during runtime
  numDllStepsFpga = numStepsCalibrated + additionalSteps;

  dllStepDistance = dllRange / (numStepsCalibrated - 1);

  distanceRange = drnuCalibrationDataHelper.getModulation().getBaseDistanceRange();

  atanOffset = drnuCalibrationDataHelper.getAtanOffset();


  /*******************
   * If no steps are calibrated, only the offset is calibrated, set flag and cancel here
   *******************/
  if (numStepsCalibrated == 0)
  {
  	offsetOnly = true;
  	offset = TOF_COS_CALIBRATION_BOX_LENGTH - (300 * TOF_COS_DLL_STEP_OPERATION) - TOF_COS_DISTANCE_CHIP_TO_FRONT;

  	//Convert to cm if distance range is not in millimeter (low modulation frequencies)
  	if (drnuCalibrationDataHelper.getModulation().isInMillimeter() == false)
  	{
  		offset /= 10;
  	}
  	return;
  }


  //Fill a temporary table with the set distances
	for (uint8_t i = 0; i < numStepsCalibrated; i++)
	{
	  //Fill the values for the DLL step = set distance
		volatile int32_t multipliedRange = static_cast<int32_t>(dllRange) * (static_cast<int32_t>(i));
		int32_t distance = multipliedRange / (numStepsCalibrated - 1);

	  setDistance[i] = distance;
	}


	//Now recalculate the measured distances at calibration time and fill these values into the LUT. This also expands the 8Bit values from the flash to 16Bit values in the LUT
	uint32_t numPixel = 76800; //test, todo: use calibration data
	int8_t *calibrationData = drnuCalibrationDataHelper.getCalibrationDataAddress();
	for (uint8_t step = 0; step < numStepsCalibrated; step++)
	{
		for (uint32_t i = 0; i < numPixel; i++)
		{
		  int32_t measuredDistanceAtCalibration = setDistance[step] + (calibrationData[(step * numPixel) + i] * CALIBRATION_MULTIPLIER);
		  if (measuredDistanceAtCalibration < 0)
		  {
		  	measuredDistanceAtCalibration += DISTANCE_RANGE;
		  }
		  else if (measuredDistanceAtCalibration > DISTANCE_RANGE)
		  {
		  	measuredDistanceAtCalibration -= DISTANCE_RANGE;
		  }
			addValue(i, step, numDllStepsFpga, measuredDistanceAtCalibration);
		}
	}


  //Copy the values for the additional steps to reach a number of steps that is a multiplier of 4
	uint8_t lastRealDllStep = numStepsCalibrated - 1;
	for (uint32_t i = 0; i < numPixel; i++)
	{
	  uint16_t distanceToCopy = drnuTable[(i * numDllStepsFpga) + (numStepsCalibrated - 1)];
	  for (uint8_t step = 0; step < additionalSteps; step++)
	  {
	  	uint32_t currentStep = lastRealDllStep + step + 1;
	  	addValue(i, currentStep, numDllStepsFpga, distanceToCopy);
	  }
	}

	int32_t offsetAtDllStep = (setDistance[TOF_COS_DLL_STEP_OPERATION]  * distanceRange) / DISTANCE_RANGE;

	offset = TOF_COS_CALIBRATION_BOX_LENGTH - offsetAtDllStep - TOF_COS_DISTANCE_CHIP_TO_FRONT;

	//Convert to cm if distance range is not in millimeter (low modulation frequencies)
	if (drnuCalibrationDataHelper.getModulation().isInMillimeter() == false)
	{
	  offset /= 10;
	}
}

/**
 * @brief Add one value
 *
 * Helper function to add one distance value to the LUT.
 *
 * @param pixelIndex Index of the pixel (e.g. 0 = first pixel)
 * @param dllStep Current dll step
 * @param numDllSteps Total number of dll steps
 * @param distance Distance value to add
 */
void DrnuCompensation::addValue(const uint32_t pixelIndex, const uint8_t dllStep, const uint8_t numDllSteps, const uint32_t distance)
{
  drnuTable[(pixelIndex * numDllSteps) + dllStep] = distance;
}

/** @} */
