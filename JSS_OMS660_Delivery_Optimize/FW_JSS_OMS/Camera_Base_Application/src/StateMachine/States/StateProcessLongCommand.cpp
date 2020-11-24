/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @addtogroup state_process_long_command
 */
#include <StateMachine/States/StateProcessLongCommand.h>
#include "../../../base/StateMachine/StateMachine.h"
#include "StateMachine/TofCamStateMachine.h"
#include "Communication/Answer.h"
#include "Interface/InterfaceInstance.h"
#include "TraceSettings.h"

/**
 * @brief Task function
 *
 * This is implemented blocking, so this is called only once.
 */
void StateProcessLongCommand::task()
{
	//Wait, as long as the command interface is still busy sending the answer
	if (InterfaceInstance::getInstance().cmdInterfaceIsBusy())
	{
		return;
	}

	Answer answer;
	processLongCommand(answer);

	stateMachine.changeState(stateMachine.idleState);
}

/**
 * @brief Enter function
 *
 * Nothing to do here
 */
void StateProcessLongCommand::enter()
{
}

/**
 * @brief Exit function
 *
 * Nothing to do here
 */
void StateProcessLongCommand::exit()
{
}

/**
 * @brief Process the command
 *
 * @param answer Reference to the answer to send
 */
void StateProcessLongCommand::processLongCommand(class Answer &answer)
{
  //Get the command
	uint8_t command = context.longCommandJob.prepareCommand();

	switch(command)
	{
	  case Command::CALIBRATE_DRNU:
	  	TRACE(">>>>>>>> Calibrate\r\n");
	  	context.tofCos.calibrateDrnu(context.longCommandJob.getDrnuCalibrationValidateOnly(), context.longCommandJob.getDrnuCalibrationOffsetOnly(), context.longCommandJob.getDrnuCalibrationIndex());
	  	context.tofCos.writeCalibrationToMemory();
	  	TRACE(">>>>>>>> Done\r\n");
	  	break;
	  case Command::CALIBRATE_PRODUCTION:
	  	TRACE(">>>>>>>> Calibrate Production\r\n");
	  	context.tofCos.calibrateProduction();
	  	TRACE(">>>>>>>> Done\r\n");
	  	break;
	  case Command::DELETE_CALIBRATION:
	  	TRACE(">>>>>>>> Delete Calibration\r\n");
	  	context.calibrationMemory.erase();
	  	TRACE(">>>>>>>> Done\r\n");
	  	break;
	  case Command::CALIBRATE_GRAYSCALE:
	  	TRACE(">>>>>>>> Calibrate Grayscale\r\n");
	  	context.tofCos.calibrateGrayscale();
	  	context.tofCos.writeCalibrationToMemory();
	    TRACE(">>>>>>>> Done\r\n");
	  	break;
	  case Command::CALIBRATE_AMBIENT_LIGHT:
	  	TRACE(">>>>>>>> Calibrate Ambient Light\r\n");
	  	context.tofCos.calibrateAmbientLight();
	  	context.tofCos.writeCalibrationToMemory();
	  	TRACE(">>>>>>>> Done\r\n");
	  	break;
		default:
			break;
	}
}

/** @} */
