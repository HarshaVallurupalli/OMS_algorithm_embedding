#include <StateMachine/TofCamStateMachine.h>
#include "../../base/StateMachine/StateMachine.h"
#include "Interface/InterfaceInstance.h"

#include "Camera_number/Camera_number.h"
#include <hal/i2c/i2cInstance.h>
#include "hal/io/IO.h"
#include "trace/TraceLoggerInstance.h"
#include "SerDes/SerDes.h"




TofCamStateMachine::TofCamStateMachine():
powerUpState(*this, context),
idleState(*this, context),
processCommandState(*this, context),
streamState(*this, context),
errorState(*this, context),
processLongCommandState(*this, context),
externalTriggerState(*this, context),
sendDataState(*this, context),
synchronizeCalibrationDataState(*this, context)
{
	generateEventDataAvailable = false;
	generateEventDataSent = false;
	changeState(powerUpState);
}

/**
 * @brief Task function
 *
 * This function is called from the main loop of the application and triggers the state machine.
 * - First events are filled into the queue for the state machine
 * - Then the task function of the state machine is called. That calls the task function of the current state
 */
void TofCamStateMachine::task()
{
	//Check for changes in Camera Selection
	onCameraSelectionChanged();

	//Check for data ready of the TOFCOS
	bool tofDataReady = !context.tofCos.acquisitionBusy();
	if (generateEventDataAvailable && tofDataReady)
	{
		generateEventDataAvailable = false;
		context.addInternalEvent(StateMachineInternalEvent_e::STATE_MACHINE_EVENT_DATA_READY);
	}

	//Check for data transmission finished
	bool transmitBusy = InterfaceInstance::getInstance().isBusy();
	if (generateEventDataSent && (transmitBusy == false))
	{
		generateEventDataSent = false;
		context.addInternalEvent(StateMachineInternalEvent_e::STATE_MACHINE_EVENT_DATA_SENT);
	}

	//Trigger the event function if needed
	if (context.eventQueueInternalEvents.empty() == false)
	{
		int32_t event = context.eventQueueInternalEvents.pop();
		actState->onEvent(event);
	}

	//The task function of the state machine that calls the task function of the current state
	StateMachine::task();
}

/**
 * @brief Arm the state machine for a certain event
 *
 * This function is used to arm the state machine for a certain event. This is useful e.g. for the event
 * "data sent" when all the data is sent to the interface.
 *
 * @param event Event to arm
 */
void TofCamStateMachine::armEvent(const StateMachineInternalEvent_e event)
{
	switch(event)
	{
	  case StateMachineInternalEvent_e::STATE_MACHINE_EVENT_DATA_READY:
	  	generateEventDataAvailable = true;
	  	break;
	  case StateMachineInternalEvent_e::STATE_MACHINE_EVENT_DATA_SENT:
	  	generateEventDataSent = true;
	  	break;
	  default:
	  	break;
	}
}

//setter function definition
void TofCamStateMachine::setGenerateEventDataAvailable(bool Value)
{
	generateEventDataAvailable = Value;
}


void TofCamStateMachine::setGenerateEventDataSent(bool Value)
{
	generateEventDataSent = Value;
}

void TofCamStateMachine::onCameraSelectionChanged()
{
	Camera_number* camera_number = Camera_number::getInstance();

	uint8_t cam_old   =   camera_number->get_old_cam_num();
	uint8_t cam_new   =   camera_number->get_new_cam_num();

	//check if a different camera was selected at the GUI and initialize the selected camera
	if((cam_new) != (cam_old))
	{
		//int8_t status = CameraInit(camera_number->get_new_cam_num());
		IO_IF &io = IO::getInstance();
		io.PoweronDaughterBoardPort(camera_number->get_new_cam_num());

		//Config the serDes here based on camera selected. Later no new configuration is done
		i2c_IF &i2c = i2cInstance::getInstance();
		SerDes serdes(i2c);
		serdes.connect(camera_number->get_new_cam_num());


		// restart the StateMachine in powerup state
		generateEventDataAvailable = false;
		generateEventDataSent = false;
		changeState(powerUpState);

		camera_number->set_old_cam_num(camera_number->get_new_cam_num());
	}
	}


