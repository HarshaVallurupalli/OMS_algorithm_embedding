/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup state_stream Stream
 * @ingroup tofcam_state
 * @brief
 *
 * In this state the camera is streaming data to the host until it is stopped by a command.
 *
 * @{
 */
#ifndef STATE_STREAM_H_
#define STATE_STREAM_H_

#include <StateMachine/TofCamState.h>

//! Stream State
/*!
 *  In this state the camera is streaming data to the host until it is stopped by a command.
 */
class StateStream: public TofCamState
{
	public:
		using TofCamState::TofCamState;
		void enter() override;
		void exit() override;
		void task() override;
		void timerTick() override;
		void onEvent(const int32_t event) override;
};

#endif /* STATE_STREAM_H_ */

/** @} */
