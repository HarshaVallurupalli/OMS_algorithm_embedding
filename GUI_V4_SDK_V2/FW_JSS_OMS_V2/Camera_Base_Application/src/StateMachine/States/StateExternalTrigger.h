/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup state_external_trigger External Trigger
 * @ingroup tofcam_state
 * @brief
 *
 * In this state an external trigger is used to generate the shutter for the camera.
 *
 * @{
 */
#ifndef STATE_EXTERNAL_TRIGGER_H_
#define STATE_EXTERNAL_TRIGGER_H_

#include <StateMachine/TofCamState.h>

//! External Trigger State
/*!
 * In this state an external trigger is used to generate the shutter for the camera. this is not available on all cameras.
 */
class StateExternalTrigger: public TofCamState
{
	public:
		using TofCamState::TofCamState;
		void enter() override;
		void task() override;
		void onEvent(const int32_t event);
};

#endif /* STATE_EXTERNAL_TRIGGER_H_ */

/** @} */
