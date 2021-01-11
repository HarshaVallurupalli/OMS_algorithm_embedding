/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @addtogroup state_power_up
 */
#include <events/events.h>
#include <Interface/Interface.h>
#include <queue/queue_c.h>
#include "StateMachine/TofCamStateMachine.h"
#include "StatePowerUp.h"
#include "hal/timer/timer.h"

/**
 * @brief Enter function
 *
 * Nothing to be done here.
 */
void StatePowerUp::enter()
{
}

/**
 * @brief Exit function
 *
 * Nothing to be done here.
 */
void StatePowerUp::exit()
{
}

/**
 * @brief Task function
 *
 * - Init TOF_COS
 * - Synchronize calibration data if needed
 * - Change state to idle if everything is ok, else change to error
 */
void StatePowerUp::task()
{
	context.led.setPattern(LED_PATTERN_STARTUP);

	uint8_t status = context.tofCos.init(Header::MAX_HEADER_SIZE, 0);

	if (status != TOF_COS_STATUS_OK)
	{
		stateMachine.changeState(stateMachine.errorState);
	}
	else
	{
		context.led.setPattern(LED_PATTERN_OFF);

		CalibrationMemory::CalibrationMemoryResult_e result = context.calibrationMemory.init();

		//If the data is not synchronized, do this now.
		if ((result == CalibrationMemory::CalibrationMemoryResult_e::CALIBRATION_MEMORY_DATA_NOT_SYNCHRONIZED) ||
				(result == CalibrationMemory::CalibrationMemoryResult_e::CALIBRATION_MEMORY_LOCAL_DATA_NOT_OK))
		{
			stateMachine.changeState(stateMachine.synchronizeCalibrationDataState);
		}
		else
		{
			context.tofCos.updateCalibrationData();

			context.led.setPattern(LED_PATTERN_OPERATION);

			stateMachine.changeState(stateMachine.idleState);
		}
	}
}

/** @} */
