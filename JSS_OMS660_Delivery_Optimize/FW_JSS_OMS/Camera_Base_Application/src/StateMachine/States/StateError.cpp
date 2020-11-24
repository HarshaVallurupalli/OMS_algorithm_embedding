/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @addtogroup state_error
 */
#include "StateError.h"
#include "../../../base/StateMachine/StateMachine.h"
#include "LedPattern.h"
#include "StateMachine/TofCamStateMachine.h"


/**
 * @brief Enter function
 *
 * Just start the LED pattern
 */
void StateError::enter()
{
	context.led.setPattern(LED_PATTERN_ERROR);
}

/**
 * @brief Task function
 *
 * No action until now. Later some basic commands could be executed here.
 */
void StateError::task()
{
}

/**
 * @brief Exit function
 *
 * This state is never left because the system is not able to operate.
 */
void StateError::exit()
{
}

/** @} */
