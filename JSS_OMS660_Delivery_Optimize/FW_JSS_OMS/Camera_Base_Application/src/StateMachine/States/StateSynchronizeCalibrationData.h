/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup state_synchronize_calibration_data Synchronize Calibration Data
 * @ingroup tofcam_state
 * @brief
 *
 * Synchronize the calibration data from the camera to the controller.
 * @{
 */
#ifndef STATE_SYNCHRONIZE_CALIBRATION_DATA_H_
#define STATE_SYNCHRONIZE_CALIBRATION_DATA_H_

#include <StateMachine/TofCamState.h>

//! State Synchronize Calibration Data
/*!
 *  Synchronize the calibration data from the camera to the controller.
 */
class StateSynchronizeCalibrationData: public TofCamState
{
	public:
	  using TofCamState::TofCamState;
		void task() override;
		void enter() override;
		void exit() override;
};

#endif /* STATE_SYNCHRONIZE_CALIBRATION_DATA_H_ */

/** @} */
