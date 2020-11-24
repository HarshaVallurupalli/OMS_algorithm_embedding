#ifndef TOFCAM_STATE_MACHINE_H_
#define TOFCAM_STATE_MACHINE_H_

#include <StateMachine/States/StateError.h>
#include <StateMachine/States/StateIdle.h>
#include <StateMachine/States/StatePowerUp.h>
#include <StateMachine/States/StateProcessCommand.h>
#include <StateMachine/States/StateStream.h>
#include <StateMachine/StateMachineContext.h>
#include <StateMachine/States/StateProcessLongCommand.h>
#include <StateMachine/States/StateExternalTrigger.h>
#include <StateMachine/States/StateSendData.h>
#include <StateMachine/States/StateSynchronizeCalibrationData.h>
#include "../../base/StateMachine/StateMachine.h"
#include "StateMachineTypes.h"

static const uint32_t TIMEOUT_SEND_DATA = 1000;

class TofCamStateMachine: public StateMachine
{
	public:
		TofCamStateMachine();

		StatePowerUp powerUpState;
		StateIdle idleState;
		StateProcessCommand processCommandState;
		StateStream streamState;
		StateError errorState;
		StateProcessLongCommand processLongCommandState;
		StateExternalTrigger externalTriggerState;
		StateSendData sendDataState;
		StateSynchronizeCalibrationData synchronizeCalibrationDataState;

		void task();
		void armEvent(const StateMachineInternalEvent_e event);

		//setter functions
		void setGenerateEventDataAvailable(bool Value);
		void setGenerateEventDataSent(bool Value);
	private:
		StateMachineContext context;
		bool generateEventDataAvailable;
		bool generateEventDataSent;

};

#endif /* TOFCAM_STATE_MACHINE_H_ */
