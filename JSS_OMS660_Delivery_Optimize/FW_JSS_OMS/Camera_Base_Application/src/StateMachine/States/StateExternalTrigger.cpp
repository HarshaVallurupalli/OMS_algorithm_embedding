/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @addtogroup state_external_trigger
 */
#include <queue/queue_c.h>
#include "StateExternalTrigger.h"
#include "Communication/Answer.h"
#include "events/events.h"
#include "Interface/InterfaceInstance.h"
#include "StateMachine/TofCamStateMachine.h"


/**
 * @brief Enter function
 *
 * - Start the timer for the timeout detection
 * - Arm for data ready event
 */
void StateExternalTrigger::enter()
{
	stateMachine.armEvent(StateMachineInternalEvent_e::STATE_MACHINE_EVENT_DATA_READY);
}

/**
 * @brief Task function
 *
 * Check the event queue for commands.
 */
void StateExternalTrigger::task()
{
	if (queueCheckEvent(QUEUE_STATE_MACHINE) == QUEUE_OK)
	{
	  stateMachine.changeState(stateMachine.processCommandState);
	}
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
void StateExternalTrigger::onEvent(const int32_t event)
{
  switch(event)
  {
    case StateMachineInternalEvent_e::STATE_MACHINE_EVENT_DATA_SENT:
    	if (context.isStream)
    	{
    		stateMachine.armEvent(StateMachineInternalEvent_e::STATE_MACHINE_EVENT_DATA_READY);
    	}
    	else
    	{
    	  stateMachine.changeState(stateMachine.idleState);
    	}
    	break;
  	case StateMachineInternalEvent_e::STATE_MACHINE_EVENT_DATA_READY:
  	{
  		//Send the data. If this fails, go to error state
  		bool dataBeingSent = sendData();
  		if (dataBeingSent)
  		{
  			//Data is being sent. Arm for event that the data is sent
  			stateMachine.armEvent(StateMachineInternalEvent_e::STATE_MACHINE_EVENT_DATA_SENT);
  		}
  		else
  		{
  		  stateMachine.changeState(stateMachine.errorState);
  		}
  		break;
  	}
  	default:
  	 break;
  }
}

/** @} */

