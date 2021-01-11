/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup state_power_up Power Up
 * @ingroup tofcam_state
 * @brief
 *
 * This is the initial state at startup.
 *
 * @{
 */
#ifndef STATE_POWERUP_H_
#define STATE_POWERUP_H_

#include <StateMachine/TofCamState.h>

//! PowerUp State
/*!
 * This is the initial state at startup.
 */
class StatePowerUp: public TofCamState
{
	public:
		using TofCamState::TofCamState;
		void task() override;
		void enter() override;
		void exit() override;
};

#endif /* STATE_POWERUP_H_ */

/** @} */
