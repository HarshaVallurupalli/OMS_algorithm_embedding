/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @addtogroup state_send_data
 */
#include <Communication/Answer.h>
#include "Interface/InterfaceInstance.h"
#include "StateMachine/TofCamStateMachine.h"
#include <StateMachine/States/StateSendData.h>
#include "ErrorCodes.h"

/**
 * @brief Enter function
 *
 * - Start the timer for the timeout detection
 * - Arm for data ready event
 */
void StateSendData::enter()
{
	stateMachine.armEvent(StateMachineInternalEvent_e::STATE_MACHINE_EVENT_DATA_READY);
	stateMachine.startTimer(TIMEOUT_SEND_DATA, false);
}

/**
 * @brief Exit function
 *
 * Nothing to do here
 */
void StateSendData::exit()
{
  stateMachine.stopTimer();
}

/**
 * @brief Task function
 *
 * Nothing to do here
 */
void StateSendData::task()
{
}

/**
 * @brief Timer tick event
 *
 */
void StateSendData::timerTick()
{
  context.error = ERROR_CODE_TIMEOUT;
  stateMachine.changeState(stateMachine.idleState);
}

/**
 * @brief Handle events
 *
 * There are two events to wait:
 * - Data from TOFCOS ready
 * - Data sent to host
 *
 * When the two events have happened, the state changes.
 *
 * @param event Event that occured
 */
void StateSendData::onEvent(const int32_t event)
{
  switch(event)
  {
    case StateMachineInternalEvent_e::STATE_MACHINE_EVENT_DATA_SENT:
    	stateMachine.changeState(stateMachine.idleState);
  		break;
  	case StateMachineInternalEvent_e::STATE_MACHINE_EVENT_DATA_READY:
  	{
  		//Send the data. If this fails, send an error
  		uint8_t status = sendData();

  		//If there is an error and now the status is ok, the error is cleared.
  		context.setErrorCodeFromTofCosStatus(status);

  		if (status == TOF_COS_STATUS_OK)
  		{
  			//Data is being sent. Arm for event that the data is sent
  			stateMachine.armEvent(StateMachineInternalEvent_e::STATE_MACHINE_EVENT_DATA_SENT);
  		}
  		else
  		{
  		  sendError(context.error);
  		  stateMachine.changeState(stateMachine.idleState);
  		}
  		break;
  	}
  	default:
  	 break;
  }
}

/** @} */
