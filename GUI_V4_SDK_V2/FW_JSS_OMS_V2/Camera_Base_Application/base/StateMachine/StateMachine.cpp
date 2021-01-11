/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @addtogroup state_machine
 */
#include "StateMachine.h"


StateMachine::StateMachine()
{
	actState = &dummyState;
	lastState = actState;
}

void StateMachine::changeState(State &newState)
{
  lastState = actState;
	actState->exit();
  actState = &newState;
  actState->enter();
}

void StateMachine::startTimer(const uint32_t value, const bool continuous)
{
  timer.start(value, continuous);
}

void StateMachine::restartTimer()
{
  timer.restart();
}

void StateMachine::stopTimer()
{
  timer.stop();
}

void StateMachine::task()
{
  actState->task();
}

void StateMachine::timerTick(const int32_t numTicks)
{
  bool timeOver = timer.tick(numTicks);
  if (timeOver)
  {
    actState->timerTick();
  }
}

State *StateMachine::getLastState() const
{
	return lastState;
}

/** @} */
