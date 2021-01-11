/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup state_process_command Process Command
 * @ingroup tofcam_state
 * @brief
 *
 * In this state the camera is processing a command from the host.
 *
 * @{
 */
#ifndef STATE_PROCESS_COMMAND_H_
#define STATE_PROCESS_COMMAND_H_

#include <StateMachine/TofCamState.h>
#include <stdint.h>
#include "TOF_COS_Data.h"
#include "Communication/Command.h"
#include "Communication/Answer.h"

//! Process Command State
/*!
 * In this state the camera is processing a command received from the host.
 */
class StateProcessCommand: public TofCamState
{
	public:
		using TofCamState::TofCamState;
		void task() override;
		void enter() override;
		void exit() override;

	private:
		uint8_t setIntegrationTimes(const Command &job, Answer &answer);
		State *processDataCommand(const TOF_COS_Data_e data, const bool isStream);
		uint32_t convertIpToUint32(const uint8_t *ip);
};

#endif /* STATE_PROCESS_COMMAND_H_ */

/** @} */
