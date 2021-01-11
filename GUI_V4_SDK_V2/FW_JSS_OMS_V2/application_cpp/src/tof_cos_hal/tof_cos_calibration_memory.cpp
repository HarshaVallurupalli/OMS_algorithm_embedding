/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 *
 * @addtogroup tof_cos_calibration_memory
 *
 * @{
 */
#include "tof_cos_calibration_memory.h"
#include "tof_cos_calibration_memory_config.h"
#include "Calibration/DrnuCalibrationTypes.h"
#include <string.h>
#include "CalibrationMemory/CalibrationMemory.h"


///Current index when writing into the memory
static uint32_t currentIndex;


static CalibrationMemory *calibrationMemoryInstance;

/**
 * @brief Set the calibration memory
 *
 * Used to inject the dependency to the calibration memory class.
 *
 * @param memory Pointer to the calibration memory
 */
void tofCosCalibrationMemorySetMemory(CalibrationMemory *memory)
{
	calibrationMemoryInstance = memory;
}

/**
 * @brief Get the start address of the calibration memory
 *
 * @return Start address of the calibration memory
 */
int8_t tofCosCalibrationMemoryInit()
{
	return 0;
}

/**
 * @brief Get the start address of the calibration memory
 *
 * @return Start address of the calibration memory
 */
uint32_t tofCosCalibrationMemoryGetStartAddress()
{
	return (uint32_t)calibrationMemoryInstance->getMemory();
}

/**
 * @brief Get the total size of the calibration memory
 *
 * @return Total size of the calibration memory
 */
uint32_t tofCosCalibrationMemoryGetTotalSize()
{
	return calibrationMemoryInstance->getSize();
}

/**
 * @brief Set current address
 *
 * Call this function before using "tofCosCalibrationMemoryAddByte" to set the start address to work on.
 *
 * @param address Address to set
 * @retval 0 Success
 * @retval -1 Error
 * @return Result
 */
int8_t tofCosCalibrationMemorySetCurrentAddress(const uint32_t address)
{
	uint8_t *calibrationMemory = calibrationMemoryInstance->getMemory();
	int32_t indexTemp = address - (uint32_t)calibrationMemory;

	if (indexTemp < 0)
	{
		indexTemp = 0;
	}

	currentIndex = indexTemp;

  return 0;
}

/**
 * @brief Add one byte
 *
 * Use this function to add one byte. It automatically handles the write of the flash words.
 *
 * @param data Byte to add
 * @retval 0 Success
 * @retval -1 Error
 * @return Result
 */
int8_t tofCosCalibrationMemoryAddByte(const uint8_t data)
{
	uint8_t *calibrationMemory = calibrationMemoryInstance->getMemory();
	calibrationMemory[currentIndex] = data;
  currentIndex++;

	return 0;
}

/**
 * @brief Add 32 bytes
 *
 * Use this function to add 32 bytes.
 *
 * @param address Address to write
 * @param data Byte to add
 * @retval 0 Success
 * @retval -1 Error
 * @return Result
 */
int8_t tofCosCalibrationMemoryAdd32Bytes(const uint32_t address, const uint8_t *data)
{
	tofCosCalibrationMemorySetCurrentAddress(address);

	for (uint32_t i = 0; i < 32; i++)
	{
		tofCosCalibrationMemoryAddByte(data[i]);
	}

  return 0;
}

/**
 * @brief Write data to device
 *
 * This function is useful, if the calibration data is in the RAM and by calling this function all
 * the data is stored into the flash. This would be the case on a system with slow flash and big RAM.
 *
 *
 * @retval 0 Success
 * @retval -1 Error
 * @return Result of the procedure
 */
int8_t tofCosCalibrationMemoryWriteToDevice()
{
  return calibrationMemoryInstance->writeToDevice();
}

/**
 * @brief Check, if the given memory space is erased
 *
 * @param address Flash address (start of the space)
 * @param size Number of bytes to check
 * @retval -1 Error, not all erased
 * @retval 0 Ok, all bytes erased
 * @return Result
 */
int8_t tofCosCalibrationMemoryCheckErased(const uint32_t address, const uint32_t size)
{
	//Always return zero (erased) here
	return 0;
}

/** @} */
