/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @defgroup state_machine State Machine
 * @brief State Machine for the device
 * @ingroup application
 *
 * @{
 */
#ifndef STATE_MACHINE_H_
#define STATE_MACHINE_H_

#include "StateMachine/State.h"
#include "StateMachineTimer.h"

class StateMachine
{
	public:
		StateMachine();
		void task();
		void timerTick(const int32_t numTicks);
		void changeState(class State &newState);
		void startTimer(const uint32_t value, const bool continuous);
		void restartTimer();
		void stopTimer();
		State *getLastState() const;

	protected:
		State *actState;
		State *lastState;

	private:
		State dummyState;
		SimpleTimer timer;
};

#endif /* STATE_MACHINE_H_ */

/** @} */
