#ifndef TOFCAM_STATE_H_
#define TOFCAM_STATE_H_

#include "../../base/StateMachine/State.h"
#include <stdint.h>
#include "LedPattern.h"

class TofCamState: public State
{
	public:
		TofCamState(class TofCamStateMachine &stateMachine, class StateMachineContext &context): stateMachine(stateMachine), context(context){};

	protected:
		class TofCamStateMachine &stateMachine;
	  class StateMachineContext &context;

	  uint8_t getType();
	  uint8_t sendData();
	  void sendError(const uint16_t error);
};

#endif /* TOFCAM_STATE_H_ */
