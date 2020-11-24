/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @addtogroup drnu_calibration
 *
 * @{
 */
#include "DrnuCalibration.h"
#include <math.h>
#include "tof_cos_calibration_memory.h"
#include "CRC/CRC.h"
#include "DrnuCalibrationDataHelper.h"

///Value for bad pixels that cannot be calibrated
const uint32_t BAD_PIXEL_VALUE = 0xFFFFFFFF;

DrnuCalibration::DrnuCalibration()
{
	//First init everything
	this->multiplier = 0;
	this->distanceRange = 0;
	this->numPixel = 0;
  this->address = 0;
  this->memorySize = 0;
}

/**
 * @brief Setup this class
 *
 * Call this function to setup (dependency injection) this module for operation. Basically the data for the calibration
 * data is set.
 *
 * @param address Address of the calibration/correction data
 * @param memorySize Size of the calibration/correction data
 */
TypeInternalReturnValue DrnuCalibration::setup(const uint32_t address)
{
	//Check, if it is possible to continue
	if (address == 0)
	{
		return TypeInternalReturnValue::STATUS_ERROR_NOT_INITIALIZED;
	}/** Cancel here, if data not valid ------------------------------------*/

	this->address = address;

	return TypeInternalReturnValue::STATUS_OK;
}

/**
 * @brief Check if calibration memory is erased
 *
 * This function checks if the calibration memory is erased and can be programmed with new
 * calibration data.
 *
 * @retval TypeInternalReturnValue::STATUS_OK Calibration memory erased
 * @return Value from TypeInternalReturnValue
 */
TypeInternalReturnValue DrnuCalibration::checkErased()
{
	if ((address == 0) || (memorySize == 0))
	{
		return TypeInternalReturnValue::STATUS_ERROR_NOT_INITIALIZED;
	}/** Cancel here, if data not valid ------------------------------------*/

	if (tofCosCalibrationMemoryCheckErased(address, memorySize) < 0)
	{
		return TypeInternalReturnValue::STATUS_ERROR_FLASH_NOT_ERASED;
		/* Flash not erased ------------------------------------------------> */
	}

	return TypeInternalReturnValue::STATUS_OK;
}

/**
 * @brief Helper function to limit value
 *
 * This helper function limits the difference value to the range of one byte. This is needed,
 * because the lookup table in the flash is made with Bytes.
 *
 * @param diff32 Difference set distance to actual distance as 32Bit value
 * @retval Difference limited to one Byte
 */
int8_t DrnuCalibration::limitDiffToOneByte(const int32_t diff32)
{
	int8_t diff = diff32;
	if (diff32 > 125)
	{
		diff = 125;
	}
	else if (diff32 < -125)
	{
		diff = -125;
	}

	return diff;
}

/**
 * @brief Set parameters for calibration
 *
 * Do this before using the function "calibrateStep"
 *
 * @param distanceRange Distance range for the modulation frequency
 * @param multiplier Multiplier used for the calibration data
 * @param numPixel Number of pixels
 */
void DrnuCalibration::setParameters(const int32_t distanceRange, const uint32_t multiplier, const uint32_t numPixel)
{
  this->distanceRange = distanceRange;
  this->multiplier = multiplier;
  this->numPixel = numPixel;
}

/**
 * @brief Calibrate one DLL step
 *
 * This function has to be called during calibration to store the selected data into the flash. It has to be
 * called once for each DLL step. I stores the calibration values of all pixels.
 *
 * @param pDistance Pointer to the distance array containing the already calculated average
 * @param setDistance Wanted distance = theoretical correct distance
 * @param step DLL step of calibration
 * @retval TypeInternalReturnValue::STATUS_OK Ok
 * @retval TypeInternalReturnValue::STATUS_ERROR_NOT_INITIALIZED Parameters not initialized
 * @retval TypeInternalReturnValue::STATUS_ERROR_FLASH_WRITE Failed Writing to flash failed
 * @return Result of calibrating this step
 */
TypeInternalReturnValue DrnuCalibration::calibrateStep(const uint8_t *pDistance, const uint32_t setDistance, const uint32_t step)
{
	//Check, if calibration is possible
	if ((address == 0) ||
			(numPixel == 0) ||
			(multiplier == 0) ||
			(distanceRange == 0)
			)
	{
		return TypeInternalReturnValue::STATUS_ERROR_NOT_INITIALIZED;
	}/* Cancel, error --------------------------------------------------------> */

	DrnuCalibrationDataHelper calibrationDataHelper(address);

	int8_t *pCalibration = calibrationDataHelper.getCalibrationDataAddress();
	if (pCalibration == nullptr)
	{
		return TypeInternalReturnValue::STATUS_ERROR_NOT_INITIALIZED;
	}/* Cancel, error --------------------------------------------------------> */

	const uint32_t *pDistance32 = reinterpret_cast<const uint32_t *>(pDistance);

	uint32_t flashAddress = reinterpret_cast<uint32_t>(pCalibration) + (step * numPixel * sizeof(int8_t));
	//Calculate the address in the calibration memory. This is given by the step, number of pixels and the calibration size per pixel
	(void)tofCosCalibrationMemorySetCurrentAddress(flashAddress);

	//Do this for all the pixels
	for (uint32_t i = 0; i < numPixel; i++)
	{
		//Calculate the distance using the offset
		int32_t actDistance = pDistance32[i];

		//If the distance is negative, there was an overflow. Add the max distance. Else do nothing.
		if (actDistance < 0)
		{
			actDistance = actDistance + distanceRange;
		}

		//Calculate the difference to the wanted distance = set distance
		int32_t diff32 = actDistance - setDistance;

		//Handle the overflow
		if (diff32 < -(distanceRange / 2))
		{
		  diff32 += distanceRange;
		}
		else if (diff32 > (distanceRange / 2))
		{
			diff32 -= distanceRange;
		}

		int8_t lutValue = 0;

		//Omit the bad pixels, store special value
		if (pDistance32[i] == BAD_PIXEL_VALUE)
		{
		  lutValue = DRNU_LUT_VALUE_BROKEN_PIXEL;
		}
		else
		{
		  //Divide to use less space but lose precision
		  diff32 = diff32 / multiplier;

		  //Limit to not be bigger than one byte
		  lutValue = limitDiffToOneByte(diff32);
		}

		//Store to memory, e.g. flash
		int8_t status = tofCosCalibrationMemoryAddByte(static_cast<const uint8_t>(lutValue));
		if (status < 0)
		{
			return TypeInternalReturnValue::STATUS_ERROR_FLASH_WRITE;
		}/* Cancel, error ------------------------------------------------------------> */
	}

	return TypeInternalReturnValue::STATUS_OK;
}

/**
 * @brief Store the header for the calibration data
 *
 * This function has to be called when the calibration has been run without errors.
 * It stores the header data (version, crc) of the calibration data, so the data
 * can be read as valid.
 *
 * @param calibrationInfoData Reference to the calibration info struct that contains all informations for the calibration
 * @return TypeInternalReturnValue::STATUS_ERROR_FLASH_WRITE Failed
 * @return TypeInternalReturnValue::STATUS_OK Success
 * @return Result of the procedure
 */
TypeInternalReturnValue DrnuCalibration::storeHeader(const DrnuCalibrationInfoData &calibrationInfo)
{
	int8_t status = 0;
	DrnuCalibrationDataHelper calibrationDataHelper(address);

	calibrationHeaderV1_t header = calibrationDataHelper.createHeader(calibrationInfo);

	uint8_t *pSource = reinterpret_cast<uint8_t *>(&header);

	//Write is done in chunks of flashWordSize, so calculate how many words here
  uint32_t numFlashWords = sizeof(calibrationHeaderV1_t) / FLASH_WORD_SIZE;

	//Store it in the flash
  for (uint32_t i = 0; i < numFlashWords; i++)
  {
	  uint32_t addressOffset = i * FLASH_WORD_SIZE;
  	status = tofCosCalibrationMemoryAdd32Bytes((calibrationDataHelper.getHeaderAddress() + addressOffset), &pSource[addressOffset]);
	  if (status != 0)
	  {
	    return TypeInternalReturnValue::STATUS_ERROR_FLASH_WRITE;
	  }
  }

  return TypeInternalReturnValue::STATUS_OK;
}

/** @} */
