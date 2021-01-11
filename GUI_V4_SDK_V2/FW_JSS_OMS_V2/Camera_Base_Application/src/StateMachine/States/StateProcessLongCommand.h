/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @defgroup state_process_long_command Process Long Command
 * @ingroup tofcam_state
 * @brief
 *
 * In this state the camera is processing a command that takes a long time, e.g. calibration.
 *
 * @{
 */
#ifndef STATE_PROCESS_LONG_COMMAND_H_
#define STATE_PROCESS_LONG_COMMAND_H_

#include <StateMachine/TofCamState.h>

//! Process Command State
/*!
 * In this state the camera is processing a command received from the host.
 */
class StateProcessLongCommand: public TofCamState
{
	public:
		using TofCamState::TofCamState;
		void task() override;
		void enter() override;
		void exit() override;

	private:
		void processLongCommand(class Answer &answer);
};

#endif /* STATE_PROCESS_LONG_COMMAND_H_ */

/** @} */
