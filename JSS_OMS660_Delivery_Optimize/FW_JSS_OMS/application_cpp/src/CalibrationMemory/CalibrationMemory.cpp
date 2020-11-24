/***
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @addtogroup calibration_memory
 */
#include <CalibrationMemory/CalibrationMemory.h>
#include <stdint.h>
#include "hal/qspi_flash/qspi_flash.h"
#include <string.h>
#include "tof_cos_hal/tof_cos_calibration_memory_config.h"
#include "CRC/CRC.h"
#include "CrcStm8.h"
#include <sleep.h>

#include "Camera_number/Camera_number.h"
#pragma pack(push,1)
///Memory header stored in the flash of the ECU
typedef struct
{
  uint32_t crcEcu;       ///<CRC over the data in the ECU
  uint32_t crcOms;       ///<CRC over the data in the OMS
  uint32_t chipWaferId;  ///<Chip and wafer ID of the calibrated chip on the OMS
  uint8_t reserved[52];  ///<Fill to 64 Bytes
}memoryHeaderEcu_t;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct
{
  uint32_t magicToken;  ///<Is at 0xFFFFFFFF when deleted and gets VALUE_MAGIC_TOKEN when written. Just to detect, if the flash contains data
  uint8_t reserved[60]; ///<Fill to 64 Bytes
}memoryHeaderOms_t;
#pragma pack(pop)

//The calibration data on the local flash is:
/*
-------------------------------------------------------
Memory Header ECU
-------------------------------------------------------
Memory Header OMS
-------------------------------------------------------
Calibration Data: the same as in the TOF>cam 660 FPGA


-------------------------------------------------------
*/


//The calibration data on the OMS is:
/*
-------------------------------------------------------
Memory Header OMS
-------------------------------------------------------
Calibration Data: the same as in the TOF>cam 660 FPGA


-------------------------------------------------------
*/

//Memory Header OMS and Calibration Data must be the same on ECU and OMS to operate the camera

static const uint32_t VALUE_MAGIC_TOKEN = 0xCAFEBABE;
static const uint32_t FLASH_SIZE = 2097152;
static const uint32_t ECU_MEMORY_SIZE = sizeof(memoryHeaderEcu_t) + FLASH_SIZE;
static const uint32_t OMS_MEMORY_SIZE = FLASH_SIZE;
static const uint32_t CALIBRATION_SIZE = FLASH_SIZE - sizeof(memoryHeaderOms_t);
static uint8_t calibrationMemory[ECU_MEMORY_SIZE];
static uint8_t *pCalibrationOms = nullptr;
static uint8_t *pCalibrationData = nullptr;

/**
 * @brief Constructor
 *
 * @param tofCos Reference to the TOF_COS to use
 * @param i2c Reference to the I2C to use
 */
CalibrationMemory::CalibrationMemory(TOF_COS_Instance &tofCos, i2c_IF &i2c): tofCos(tofCos), i2c(i2c), ioExpander(i2c)
{
}

/**
 * @brief Init
 *
 * This function initializes the calibration memory from the local flash memory. It checks if the local
 * calibration data corresponds to the calibration data in the OMS. If this is the case, the local calibration
 * data can be used to operate the camera. If there is no valid calibration data or the OMS has changed, this is
 * indicated with the return value.
 *
 * @retval CALIBRATION_MEMORY_FLASH_ERROR Error reading the flash
 * @retval CALIBRATION_MEMORY_ERROR_IO_EXPANDER Error when communicating with the IO Expander
 * @retval CALIBRATION_MEMORY_NO_CALIBRATION No calibration on the OMS
 * @retval CALIBRATION_MEMORY_LOCAL_DATA_NOT_OK Local data not ok
 * @retval CALIBRATION_MEMORY_DATA_NOT_SYNCHRONIZED Not the same calibration data local and on the OMS
 * @retval CALIBRATION_MEMORY_OK Calibration loaded and it is the same as on the OMS
 * @return Init result and information about the calibration data
 */
CalibrationMemory::CalibrationMemoryResult_e CalibrationMemory::init()
{

	Camera_number* camera_number = Camera_number::getInstance();
	cam_num=camera_number->get_new_cam_num();

	memset(calibrationMemory, 0x00, sizeof(calibrationMemory));

	pCalibrationOms = &calibrationMemory[sizeof(memoryHeaderEcu_t)];
	pCalibrationData = &calibrationMemory[sizeof(memoryHeaderEcu_t) + sizeof(memoryHeaderOms_t)];

	tofCosCalibrationMemorySetMemory(this);

	int8_t status = qspiFlashInit();
	if (status < 0)
	{
	  return CALIBRATION_MEMORY_FLASH_ERROR;
	}/*  Error, cancel ----------------------------------------------------------> */


	uint32_t ioExpanderFirmwareRelease = ioExpander.getFirmwareRelease();
	if (ioExpanderFirmwareRelease == 0)
	{
		return CALIBRATION_MEMORY_ERROR_IO_EXPANDER;
	}/*  Error, cancel ----------------------------------------------------------> */


  memoryHeaderOms_t memoryHeaderOms;
	//Read the header in the OMS. Just to see, if there really is calibration data there
	status = ioExpander.readFlash(0, reinterpret_cast<uint8_t*>(&memoryHeaderOms), sizeof(memoryHeaderOms_t));
	if (status < 0)
	{
	  return CalibrationMemoryResult_e::CALIBRATION_MEMORY_ERROR_IO_EXPANDER;
	}

	if (memoryHeaderOms.magicToken != VALUE_MAGIC_TOKEN)
	{
	  return CalibrationMemoryResult_e::CALIBRATION_MEMORY_NO_CALIBRATION;
	}


	//Let the OMS start to calculate the CRC of the flash. This may take up to a few seconds time
	status = ioExpander.startCalcCrc(OMS_MEMORY_SIZE);

	//Read the calibration data from the local flash to RAM
	status = qspiFlashRead(0x0000000+(0x300000)*(cam_num-1), calibrationMemory, sizeof(calibrationMemory));
	if (status < 0)
	{
	  return CALIBRATION_MEMORY_FLASH_ERROR;
	}/*  Error, cancel ----------------------------------------------------------> */


  //Wait for the OMS to be finished with the CRC calculation. Probably this is already the case.
	ioExpander.waitBlockingFlashBusy();


	//Check the local calibration data
	uint8_t crcData = CrcStm8::calcCrc(pCalibrationOms, OMS_MEMORY_SIZE);
	memoryHeaderEcu_t *memoryHeaderEcu = reinterpret_cast<memoryHeaderEcu_t *>(calibrationMemory);
	if (memoryHeaderEcu->crcEcu != crcData)
	{
		return CalibrationMemoryResult_e::CALIBRATION_MEMORY_LOCAL_DATA_NOT_OK;
	}


	//Check if the OMS data corresponds to the ECU data
	uint32_t currentChipWaferId = (tofCos.getWaferId() << 16) | (tofCos.getChipId());
	uint32_t crcOms = ioExpander.getCalibrationCrc();

	if ((memoryHeaderEcu->chipWaferId != currentChipWaferId) ||
			(crcOms != crcData) ||
			(memoryHeaderEcu->crcOms != crcOms))
	{
		return CalibrationMemoryResult_e::CALIBRATION_MEMORY_DATA_NOT_SYNCHRONIZED;
	}


	return CALIBRATION_MEMORY_OK;
}

/**
 * @brief Synchronize calibration data
 *
 * This function synchronizes the calibration data from the OMS to the local flash. This is needed if there is no valid
 * calibration data on the local flash or if the OMS has changed.
 * This synchronization is blocking and will take more than a minute of time.
 *
 *
 * @retval CALIBRATION_MEMORY_FLASH_ERROR Error reading the flash
 * @retval CALIBRATION_MEMORY_ERROR_IO_EXPANDER Error when communicating with the IO Expander
 * @retval CALIBRATION_MEMORY_NO_CALIBRATION No calibration on the OMS
 * @retval CALIBRATION_MEMORY_LOCAL_DATA_NOT_OK Local data not ok
 * @retval CALIBRATION_MEMORY_WRONG_CRC Data on the OMS not valid
 * @retval CALIBRATION_MEMORY_OK Calbiration synchronized
 * @return Synchronization result
 */
CalibrationMemory::CalibrationMemoryResult_e CalibrationMemory::synchronizeCameraCalibration()
{
	//qspiFlashBulkErase();
	Camera_number* camera_number = Camera_number::getInstance();
	cam_num=camera_number->get_new_cam_num();

	uint8_t flash_ChipWaferId[4];
	uint32_t flash_ChipWaferId_val;
	uint32_t currentChipWaferId = (tofCos.getWaferId() << 16) | (tofCos.getChipId());
	memoryHeaderOms_t *memoryHeader = reinterpret_cast<memoryHeaderOms_t *>(pCalibrationOms);
	memoryHeaderEcu_t *memoryHeaderEcu = reinterpret_cast<memoryHeaderEcu_t *>(calibrationMemory);

	//Read the header in the OMS. Just to see, if there really is calibration data there
	int8_t status = ioExpander.readFlash(0, pCalibrationOms, sizeof(memoryHeaderOms_t));
	if (status < 0)
	{
    return CalibrationMemoryResult_e::CALIBRATION_MEMORY_ERROR_IO_EXPANDER;
	}

  //Check for magic token
	if (memoryHeader->magicToken != VALUE_MAGIC_TOKEN)
	{
    return CalibrationMemoryResult_e::CALIBRATION_MEMORY_NO_CALIBRATION;
	}


	//Let the OMS start to calculate the CRC of the flash. This may take up to a few seconds time
	status = ioExpander.startCalcCrc(OMS_MEMORY_SIZE);

	//Wait for the OMS to be finished with the CRC calculation
	ioExpander.waitBlockingFlashBusy();

	uint32_t crcOms = ioExpander.getCalibrationCrc();


	//Read the whole memory of the OMS
	status = ioExpander.readFlash(0, pCalibrationOms, OMS_MEMORY_SIZE);
	if (status < 0)
	{
	  return CalibrationMemoryResult_e::CALIBRATION_MEMORY_ERROR_IO_EXPANDER;
	}


	//Check, if the calibration is valid
	uint8_t crcData = CrcStm8::calcCrc(pCalibrationOms, OMS_MEMORY_SIZE);
	if (crcData != crcOms)
	{
    return CalibrationMemoryResult_e::CALIBRATION_MEMORY_WRONG_CRC;
	}


	//Get the meta data
	memoryHeaderEcu->chipWaferId = currentChipWaferId;
	memoryHeaderEcu->crcOms = crcOms;
	memoryHeaderEcu->crcEcu = crcData;

	// begin bulk erase ---------------------------------------------------------->
	//read chipwafer ID stored in flosh for all 4 cameras
	//value at address 900000 in flash -> ChipWaferId for cam1
	//value at address 900004 in flash -> ChipWaferId for cam2
	//value at address 900008 in flash -> ChipWaferId for cam3
	//value at address 9000012 in flash -> ChipWaferId for cam4

	status = qspiFlashRead((0x0900000+(cam_num-1)*4), flash_ChipWaferId, 4);
	if (status < 0)
	{
	  return CALIBRATION_MEMORY_FLASH_ERROR;
	}
	//get the value present in flash_ChipWaferId[4] 8 bit array into a 32 bit flash_ChipWaferId_val value for compare
	Array8bit_to_Value32bit(&flash_ChipWaferId_val, flash_ChipWaferId);

	//check if a new camera is connected to any of the already working ports on the daughter board
	//only bulk erase if a new camera is connected to a working port
	if ((flash_ChipWaferId_val!=currentChipWaferId)  &&  (flash_ChipWaferId_val)!=0xffffffff)
	{
		status = qspiFlashBulkErase();
		if (status < 0)
		{
		    return CalibrationMemoryResult_e::CALIBRATION_MEMORY_FLASH_ERROR;
		}

		flash_ChipWaferId_val=currentChipWaferId;

		//get the value present in 32 bit flash_ChipWaferId_val value  into flash_ChipWaferId[4] 8 bit array for flash_write
		Value32bit_to_Array8bit(&flash_ChipWaferId_val, flash_ChipWaferId);
		status = qspiFlashWrite(0x0900000+(cam_num-1)*4, flash_ChipWaferId, 4);
		if (status < 0)
		{
			return CalibrationMemoryResult_e::CALIBRATION_MEMORY_FLASH_ERROR;
		}
	}

	//check if a new camera is connected to any of the brand new ports on the daughter board
	if((flash_ChipWaferId_val)==(0xffffffff))
	{
		flash_ChipWaferId_val=currentChipWaferId;

		//get the value present in 32 bit flash_ChipWaferId_val value  into flash_ChipWaferId[4] 8 bit array for flash_write
		Value32bit_to_Array8bit(&flash_ChipWaferId_val, flash_ChipWaferId);
		status = qspiFlashWrite(0x0900000+(cam_num-1)*4, flash_ChipWaferId, 4);
		if (status < 0)
		{
			return CalibrationMemoryResult_e::CALIBRATION_MEMORY_FLASH_ERROR;
		}
	}
	//end of bulk erase ---------------------------------------------------------->

	//Store the data into the local flash (blocking)
	status = qspiFlashWrite(0x0000000+(0x300000)*(cam_num-1), calibrationMemory, sizeof(calibrationMemory));
	if (status < 0)
	{
    return CalibrationMemoryResult_e::CALIBRATION_MEMORY_FLASH_ERROR;
	}


	return CalibrationMemoryResult_e::CALIBRATION_MEMORY_OK;
}

/**
 * @brief Write the calibration data
 *
 * This function writes the calibration data from the RAM into both flash memories:
 * - Local flash
 * - Flash on the OMS
 *
 * This function needs to be called after the calibration (the calibration stores the data into the RAM).
 * This function is blocking and will take up to about three minutes. At the end the calibration data
 * is synchronized between the local flash and the flash on the OMS, so at the next start, no copy
 * procedure is needed.
 *
 * @retval CALIBRATION_MEMORY_FLASH_ERROR Error flash access
 * @retval CALIBRATION_MEMORY_ERROR_IO_EXPANDER Error when communicating with the IO Expander
 * @retval CALIBRATION_MEMORY_WRONG_CRC Data on the OMS not valid
 * @return Write result
 */
CalibrationMemory::CalibrationMemoryResult_e CalibrationMemory::writeToDevice()
{
	Camera_number* camera_number = Camera_number::getInstance();
	cam_num=camera_number->get_new_cam_num();
	uint32_t currentChipWaferId = (tofCos.getWaferId() << 16) | (tofCos.getChipId());

	pCalibrationOms = &calibrationMemory[sizeof(memoryHeaderEcu_t)];

	memoryHeaderEcu_t *memoryHeaderEcu = reinterpret_cast<memoryHeaderEcu_t *>(calibrationMemory);
	memoryHeaderOms_t *memoryHeaderOms = reinterpret_cast<memoryHeaderOms_t *>(pCalibrationOms);


	//Start delete the flash in the OMS
	int8_t status = ioExpander.startDeleteFlash();
	if (status < 0)
	{
		return CalibrationMemoryResult_e::CALIBRATION_MEMORY_FLASH_ERROR;
	}


	//Delete local flash (blocking)
	status = qspiFlashBulkErase();
	if (status < 0)
	{
	  return CalibrationMemoryResult_e::CALIBRATION_MEMORY_FLASH_ERROR;
	}


	//Wait until the OMS has finished (blocking)
	status = ioExpander.waitBlockingFlashBusy();
	if (status < 0)
	{
		return CalibrationMemoryResult_e::CALIBRATION_MEMORY_ERROR_IO_EXPANDER;
	}

	memoryHeaderOms->magicToken = VALUE_MAGIC_TOKEN;

	//Write the calibration into the OMS (blocking)
	status = ioExpander.writeFlash(0, pCalibrationOms, OMS_MEMORY_SIZE);
	if (status < 0)
	{
		return CalibrationMemoryResult_e::CALIBRATION_MEMORY_ERROR_IO_EXPANDER;
	}

	//Let the OMS start to calculate the CRC of the flash. This may take up to a few seconds time
	status = ioExpander.startCalcCrc(OMS_MEMORY_SIZE);
	if (status < 0)
	{
		return CalibrationMemoryResult_e::CALIBRATION_MEMORY_ERROR_IO_EXPANDER;
	}


	//Wait for the OMS to be finished with the CRC calculation. Probably this is already the case.
	ioExpander.waitBlockingFlashBusy();

	//Get the meta data
	memoryHeaderEcu->chipWaferId = currentChipWaferId;
	memoryHeaderEcu->crcOms = ioExpander.getCalibrationCrc();
	memoryHeaderEcu->crcEcu = CrcStm8::calcCrc(pCalibrationOms, OMS_MEMORY_SIZE);

	if (memoryHeaderEcu->crcOms != memoryHeaderEcu->crcEcu)
	{
		return CalibrationMemoryResult_e::CALIBRATION_MEMORY_WRONG_CRC;
	}

	//Store the data into the local flash (blocking)
	status = qspiFlashWrite(0+(0x300000)*(cam_num-1), calibrationMemory, sizeof(calibrationMemory));
	if (status < 0)
	{
		return CalibrationMemoryResult_e::CALIBRATION_MEMORY_FLASH_ERROR;
	}


	return CalibrationMemoryResult_e::CALIBRATION_MEMORY_OK;
}

/**
 * @brief Erase the calibration data
 *
 * This function erases the whole calibration data on the OMS and local.
 *
 * @retval CALIBRATION_MEMORY_FLASH_ERROR Error flash access
 * @retval CALIBRATION_MEMORY_ERROR_IO_EXPANDER Error when communicating with the IO Expander
 * @retval CALIBRATION_MEMORY_OK OK
 * @return Write result
 */
CalibrationMemory::CalibrationMemoryResult_e CalibrationMemory::erase()
{
  //Start delete the flash in the OMS
	int8_t status = ioExpander.startDeleteFlash();
	if (status < 0)
	{
	  return CalibrationMemoryResult_e::CALIBRATION_MEMORY_FLASH_ERROR;
	}


	//Delete local flash (blocking)
	status = qspiFlashBulkErase();
	if (status < 0)
	{
	  return CalibrationMemoryResult_e::CALIBRATION_MEMORY_FLASH_ERROR;
	}


	//Wait until the OMS has finished (blocking)
	status = ioExpander.waitBlockingFlashBusy();
	if (status < 0)
	{
	  return CalibrationMemoryResult_e::CALIBRATION_MEMORY_ERROR_IO_EXPANDER;
	}

	return CalibrationMemoryResult_e::CALIBRATION_MEMORY_OK;
}

/**
 * @brief Get the memory
 *
 * Get the pointer to the calibration data
 *
 * @return Pointer to the calibration memory
 */
uint8_t *CalibrationMemory::getMemory() const
{
  return pCalibrationData;
}

/**
 * @brief Get the size
 *
 * Get the size of the calibration memory
 *
 * @return Size of the calibration memory
 */
uint32_t CalibrationMemory::getSize() const
{
	return CALIBRATION_SIZE;
}

/** @} */
//edit
void CalibrationMemory::Array8bit_to_Value32bit(uint32_t * reg, uint8_t c[4])
{
/*    int start=0;
    int end=3;
   	while (start < end)
       {
           int temp = c[start];
           c[start] = c[end];
           c[end] = temp;
           start++;
           end--;
       }*/
    *reg = 0;
        for(uint8_t i=0 ;i<4; i++)
        {
            *reg = (*reg<<8) | c[i];
        }
}

void CalibrationMemory::Value32bit_to_Array8bit(uint32_t * reg, uint8_t c[4])
{
    for(uint8_t i=0; i<4; i++)
        {
            c[i] = *reg;
            *reg = *reg>>8;
        }
    int start=0;
    int end=3;
   	while (start < end)
       {
           int temp = c[start];
           c[start] = c[end];
           c[end] = temp;
           start++;
           end--;
       }
}


