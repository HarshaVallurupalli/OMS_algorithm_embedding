/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @addtogroup state_synchronize_calibration_data
 */
#include <StateMachine/States/StateSynchronizeCalibrationData.h>
#include "StateMachine/TofCamStateMachine.h"

/**
 * @brief Enter function
 *
 * Just start the LED pattern
 */
void StateSynchronizeCalibrationData::enter()
{
  context.led.setPattern(LED_PATTERN_SYNCHRONIZE);
}

/**
 * @brief Exit function
 *
 * Nothing to do here
 */
void StateSynchronizeCalibrationData::exit()
{
}

/**
 * @brief Task function
 *
 * Because the synchronization is blocking, this is called only once. If needed the synchronization could
 * be done unblocking. This would require some non blocking functions to access i2c and qspi flash.
 */
void StateSynchronizeCalibrationData::task()
{
	//To make it simple this is a blocking procedure which takes up to about 1.5minutes
	CalibrationMemory::CalibrationMemoryResult_e status = context.calibrationMemory.synchronizeCameraCalibration();
	if (status == CalibrationMemory::CalibrationMemoryResult_e::CALIBRATION_MEMORY_OK)
	{
		context.led.setPattern(LED_PATTERN_OPERATION);
	}
	else
	{
		context.led.setPattern(LED_PATTERN_NO_CALIBRATION);
	}

	context.tofCos.updateCalibrationData();

	stateMachine.changeState(stateMachine.idleState);
}

/** @} */
