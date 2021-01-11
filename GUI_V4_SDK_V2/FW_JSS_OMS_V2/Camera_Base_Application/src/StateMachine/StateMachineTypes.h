/*
 * StateMachineTypes.h
 *
 *  Created on: 18.07.2018
 *      Author: mwi
 */

#ifndef STATE_MACHINE_TYPES_H_
#define STATE_MACHINE_TYPES_H_

typedef enum
{
  STATE_MACHINE_EVENT_COMMAND,
	STATE_MACHINE_EVENT_TEST_PIN_ACTIVE
}StateMachineExternalEvent_e;

typedef enum
{
	STATE_MACHINE_EVENT_DATA_SENT,
	STATE_MACHINE_EVENT_DATA_READY
}StateMachineInternalEvent_e;



#endif /* STATE_MACHINE_TYPES_H_ */
