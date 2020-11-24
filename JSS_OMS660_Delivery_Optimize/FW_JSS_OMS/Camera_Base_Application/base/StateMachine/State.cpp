/***
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @addtogroup abstract_state
 */

#include "State.h"

/**
 * @brief Constructor
 */
State::State()
{
}

/**
 * @brief Task function
 *
 * Called from the main loop.
 */
void State::task()
{
}

/**
 * @brief Enter function
 *
 */
void State::enter()
{
}

/**
 * @brief Exit function
 *
 */
void State::exit()
{
}

/**
 * @brief Timer tick
 *
 * Called when the time has passed
 */
void State::timerTick()
{
}

/**
 * @brief Event
 *
 * Called when an event happens
 *
 * @param event Type of the event
 */
void State::onEvent(const int32_t event)
{
}

/** @} */
