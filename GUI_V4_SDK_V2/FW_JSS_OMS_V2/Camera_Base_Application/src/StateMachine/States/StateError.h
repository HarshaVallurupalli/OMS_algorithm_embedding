/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup state_error Error
 * @ingroup tofcam_state
 * @brief
 *
 * This state is entered when the camera is not able to run. It answers only
 * basic commands like firmware release, ...
 *
 * @{
 */
#ifndef STATE_ERROR_H_
#define STATE_ERROR_H_

#include <StateMachine/TofCamState.h>

//! Error State
/*!
 * This state is entered when the camera is not able to run.
 */
class StateError: public TofCamState
{
	public:
		using TofCamState::TofCamState;
	  void task() override;
		void enter() override;
		void exit() override;
};

#endif /* STATE_ERROR_H_ */

/** @} */
