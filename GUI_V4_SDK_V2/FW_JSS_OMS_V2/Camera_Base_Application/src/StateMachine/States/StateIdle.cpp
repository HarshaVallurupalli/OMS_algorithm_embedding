/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @addtogroup state_idle
 */
#include "StateMachine/TofCamStateMachine.h"
#include "StateIdle.h"
#include <events/events.h>
#include <queue/queue_c.h>

/**
 * @brief Enter function
 *
 * Nothing to be done here. Eventually the LED pattern could be set here.
 */
void StateIdle::enter()
{
}

/**
 * @brief Exit function
 *
 * Nothing to be done here.
 */
void StateIdle::exit()
{
}

/**
 * @brief Task function
 *
 * If there is a command in the queue, change the state.
 */
void StateIdle::task()
{
	if (queueCheckEvent(QUEUE_STATE_MACHINE) == QUEUE_OK)
	{
	  stateMachine.changeState(stateMachine.processCommandState);
	}
}

/** @} */
