#ifndef STATE_MACHINE_CONTEXT_H_
#define STATE_MACHINE_CONTEXT_H_

extern "C"
{
#include <events/events.h>
}

#include "TOF_COS_Instance/TOF_COS_Instance.h"
#include "queue/Queue.h"
#include "Communication/UserData.h"
#include "Communication/Command.h"
#include "CalibrationMemory/CalibrationMemory.h"
#include "Led/Led.h"

class StateMachineContext
{
	public:
		StateMachineContext();
		void addInternalEvent(const uint8_t event);
		void setErrorCodeFromTofCosStatus(const uint8_t tofCosStatus);


		bool isStream;                           ///<true if a stream is running
		uint32_t dataIp;                         ///<Destination IP address for the data
		bool differentDataAndCommandIp;          ///<true if the command and data ip are different
		TOF_COS_Instance tofCos;                 ///<Instance of the TOF_COS
		Queue<int32_t>eventQueueInternalEvents;  ///<Event queue for internal events of the state machine
		UserData userData;                       ///<User data; received by command and added to the data
		Command longCommandJob;                  ///<Job for the long command, for example calibration
		CalibrationMemory calibrationMemory;     ///<Calibration memory instance
		Led led;                                 ///<LED instance
		uint16_t error;
};

#endif /* STATE_MACHINE_CONTEXT_H_ */
