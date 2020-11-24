/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @defgroup abstract_state Abstract state
 * @brief Abstract state to be inherited
 * @ingroup state_machine
 *
 * @{
 */
#ifndef STATE_H_
#define STATE_H_

#include <stdint.h>

class State
{
	public:
		State();
		virtual void enter();
		virtual void task();
		virtual void exit();
		virtual void timerTick();
		virtual void onEvent(const int32_t event);
};

#endif /* STATE_H_ */

/** @} */
