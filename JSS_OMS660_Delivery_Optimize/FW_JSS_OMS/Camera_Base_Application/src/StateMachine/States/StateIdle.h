/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup state_idle Idle
 * @ingroup tofcam_state
 * @brief
 *
 * Idle state, wait for commands.
 *
 * @{
 */
#ifndef STATE_IDLE_H_
#define STATE_IDLE_H_

#include <StateMachine/TofCamState.h>

//! Idle State
/*!
 * Wait for commands.
 */
class StateIdle: public TofCamState
{
	public:
		using TofCamState::TofCamState;
		void task() override;
		void enter() override;
		void exit() override;
};

#endif /* STATE_IDLE_H_ */

/** @} */
