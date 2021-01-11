/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @addtogroup state_stream
 */
#include <Communication/Answer.h>
#include <queue/queue_c.h>
#include "events/events.h"
#include "Interface/InterfaceInstance.h"
#include "StateMachine/TofCamStateMachine.h"
#include <sleep.h>
#include "StateStream.h"
#include "ErrorCodes.h"

/**
 * @brief Enter function
 *
 * - Prepare for event triggered operation.
 * - Start timeout
 */
void StateStream::enter()
{
	context.isStream = true;
	stateMachine.armEvent(StateMachineInternalEvent_e::STATE_MACHINE_EVENT_DATA_READY);
	stateMachine.startTimer(TIMEOUT_SEND_DATA, false);
}

/**
 * @brief Exit function
 *
 * Nothing to do here
 */
void StateStream::exit()
{
  stateMachine.stopTimer();
}

/**
 * @brief Task function
 *
 * Nothing to do here
 */
void StateStream::task()
{
}

/**
 * @brief Timer tick event
 *
 */
void StateStream::timerTick()
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
void StateStream::onEvent(const int32_t event)
{
  switch(event)
  {
    case StateMachineInternalEvent_e::STATE_MACHINE_EVENT_DATA_SENT:
    	if (queueCheckEvent(QUEUE_STATE_MACHINE) == QUEUE_OK)
    	{
    	  stateMachine.changeState(stateMachine.processCommandState);
    	}
    	else
    	{
    	  stateMachine.startTimer(TIMEOUT_SEND_DATA, false);
    	  stateMachine.armEvent(StateMachineInternalEvent_e::STATE_MACHINE_EVENT_DATA_READY);
    	}
  		break;
    case StateMachineInternalEvent_e::STATE_MACHINE_EVENT_DATA_READY:
    {
      //Send the data. If this fails, send an error
      uint8_t status = sendData();

      //If there is an error and now the status is ok, the error is cleared.
      context.setErrorCodeFromTofCosStatus(status);

      if (status == TOF_COS_STATUS_OK)
      {
        stateMachine.startTimer(TIMEOUT_SEND_DATA, false);

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
