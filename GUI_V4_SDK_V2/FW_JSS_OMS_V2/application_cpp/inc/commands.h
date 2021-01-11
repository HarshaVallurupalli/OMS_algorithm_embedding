/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup commands Commands
 * @ingroup command_processor
 * @brief List of the commands
 *
 * @{
 */
#ifndef COMMAND_PROCESSOR_COMMANDS_H_
#define COMMAND_PROCESSOR_COMMANDS_H_

#ifdef __cplusplus
extern "C" {
#endif

//commands GUI-->TOFCAM (TCP)
typedef enum
{
	TOFCAM_COMMAND_SET_INT_TIMES = 1,
	TOFCAM_COMMAND_GET_DISTANCE_AMPLITUDE = 2,
	TOFCAM_COMMAND_GET_DISTANCE = 3,
	TOFCAM_COMMAND_GET_GRAYSCALE = 5,
	TOFCAM_COMMAND_STOP_STREAM = 6,
	TOFCAM_COMMAND_SET_OFFSET = 20,
	TOFCAM_COMMAND_SET_MIN_AMPLITUDE = 21,
	TOFCAM_COMMAND_CALIBRATE = 30,
	TOFCAM_COMMAND_CALIBRATE_SYSTEM_OFFSET = 31
}tofcamCommand_e;

//data TOFCAM-->GUI (UDP)
typedef enum
{
	TOFCAM_DATA_DISTANCE_AMPLITUDE = 0,
	TOFCAM_DATA_DISTANCE = 1,
	TOFCAM_DATA_AMPLITUDE = 2,
	TOFCAM_DATA_GRAYSCALE = 3
}tofcamData_e;

//answers TOFCAM-->GUI (TCP)
typedef enum
{
	TOFCAM_ANSWER_ACK = 0,
	TOFCAM_ANSWER_ERROR = 1
}tofcamAnswer_e;

#ifdef __cplusplus
}
#endif

#endif /* COMMAND_PROCESSOR_COMMANDS_H_ */

/** @} */
