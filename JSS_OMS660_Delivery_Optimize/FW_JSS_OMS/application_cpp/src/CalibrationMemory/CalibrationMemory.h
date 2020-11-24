/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup calibration_memory Calibration Memory
 *
 * @brief Calibration Memory
 *
 * This class contains the calibration memory and handles the operations to get the data into the calibration memory.
 * Normally the calibration data is taken from the flash on the controller board.
 * If there is no calibration on the board or a different OMS is connected, the calibration data is copied from the OMS to the controller
 * board and stored on the local flash. This is done for performance reasons: The copy procedure takes a lot of time, so this should not be
 * needed at every start of the system.
 *
 * @{
 */
#ifndef CALIBRATION_MEMORY_H_
#define CALIBRATION_MEMORY_H_

#include <stdint.h>
#include "hal/i2c_IF.h"
#include "TOF_COS_Instance/TOF_COS_Instance.h"
#include "IoExpander/IoExpander.h"

//! Calibration Memory
/*!
 * This class contains the calibration memory and handles the operations to get the data into the calibration memory.
 * Normally the calibration data is taken from the flash on the controller board.
 * If there is no calibration on the board or a different OMS is connected, the calibration data is copied from the OMS to the controller
 * board and stored on the local flash. This is done for performance reasons: The copy procedure takes a lot of time, so this should not be
 * needed at every start of the system.
 */
class CalibrationMemory
{
	public:
		enum CalibrationMemoryResult_e
		{
		  CALIBRATION_MEMORY_OK,
			CALIBRATION_MEMORY_NO_CALIBRATION,
			CALIBRATION_MEMORY_WRONG_CRC,
			CALIBRATION_MEMORY_LOCAL_DATA_NOT_OK,
			CALIBRATION_MEMORY_DATA_NOT_SYNCHRONIZED,
			CALIBRATION_MEMORY_FLASH_ERROR,
			CALIBRATION_MEMORY_ERROR_IO_EXPANDER
		};

		uint8_t cam_num=1;

		CalibrationMemory(TOF_COS_Instance &tofCos, i2c_IF &i2c);
		CalibrationMemoryResult_e init();
		CalibrationMemoryResult_e synchronizeCameraCalibration();
		CalibrationMemoryResult_e writeToDevice();
		CalibrationMemoryResult_e erase();

		//edit
		void Array8bit_to_Value32bit(uint32_t * reg, uint8_t c[4]);
		void Value32bit_to_Array8bit(uint32_t * reg, uint8_t c[4]);


		uint8_t *getMemory() const;
		uint32_t getSize() const;

	private:
    TOF_COS_Instance &tofCos;
    i2c_IF &i2c;
    IoExpander ioExpander;

};

#endif /* CALIBRATION_MEMORY_H_ */

/** @} */
