/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @defgroup state_send_data Send Data
 * @ingroup tofcam_state
 * @brief
 *
 * In this state the camera is sending data to the host in DMA mode. This state waits until the data
 * is sent.
 *
 * @{
 */
#ifndef STATE_SEND_DATA_H_
#define STATE_SEND_DATA_H_

#include <StateMachine/TofCamState.h>

//! Send Data State
/*!
 * In this state the camera is sending data to the host in DMA mode. This state waits until the data
 * is sent.
 */
class StateSendData: public TofCamState
{
	public:
		using TofCamState::TofCamState;
		void enter() override;
		void exit() override;
		void task() override;
		void timerTick() override;
		void onEvent(const int32_t event) override;
};

#endif /* STATE_SEND_DATA_H_ */

/** @} */
