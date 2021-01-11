/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @addtogroup state_process_command
 */
#include <queue/queue_c.h>
#include "Communication/Answer.h"
#include "Communication/Command.h"
#include "events/events.h"
#include "Interface/InterfaceInstance.h"
#include "StateMachine/TofCamStateMachine.h"
#include "StateProcessCommand.h"
#include "releaseInfo.h"
#include <functional>
#include "hal/sd_card/sd_card.h"

#include "../../../application_cpp/src/Camera_number/Camera_number.h"
#include "Integration_times/Integration_times.h"

/**
 * @brief Enter function
 *
 * Nothing to be done here.
 */
void StateProcessCommand::enter()
{
}

/**
 * @brief Exit function
 *
 * Nothing to be done here.
 */
void StateProcessCommand::exit()
{
}

/**
 * @brief Get data ip as 32Bit value
 *
 * Convert the command received to a 32Bit ip value.
 *
 * @param ip Pointer to an ip buffer (4 bytes)
 * @return IP as 32Bit value
 */
uint32_t StateProcessCommand::convertIpToUint32(const uint8_t *ip)
{
  uint32_t ipUint32 = (ip[3] << 24) | (ip[2] << 16) | (ip[1] << 8) | ip[0];

  return ipUint32;
}

/**
 * @brief Set integration times
 *
 * Set the integration times.
 *
 * @param command Reference to the received command
 * @param answer Reference to the answer to send
 * @return Value from TypeReturnValue
 */
uint8_t StateProcessCommand::setIntegrationTimes(const Command &command, Answer &answer)
{
	Integration_times* integration_times = Integration_times::getInstance();
	integration_times->set_New_Integration_time_low(command.getIntegrationTime3d(0));
	integration_times->set_New_Integration_time_high(command.getIntegrationTime3d(1));
  uint16_t integrationTime=0;
uint16_t integrationTime_avg = 0;
  //IntegrationTime3d 0..2
  for (uint8_t i = 0; i < 3; i++)
  {
	  if(i<2)
	  {
		  integrationTime_avg=integrationTime_avg+integrationTime;
	  	  integrationTime = command.getIntegrationTime3d(i);
	  }
	  else
	  {
		  integrationTime_avg=integrationTime_avg/2;
		  integrationTime=integrationTime_avg;
	  }

  	context.tofCos.setIntegrationTime3d(integrationTime, i);
  }

  //IntegrationTimeGrayscale
  integrationTime = command.getIntegrationTimeGrayscale();

  context.tofCos.setIntegrationTimeGrayscale(integrationTime);

  return TOF_COS_STATUS_OK;
}

/**
 * @brief Process data command
 *
 * A command was received to get data. Process this command here. Change state depending on
 * external trigger settings.
 *
 * @param data Selected data type
 * @param isStream Bool to indicate if the data should be streamed
 * @return Pointer to the new state
 */
State *StateProcessCommand::processDataCommand(const TOF_COS_Data_e data, const bool isStream)
{
	State *newState = &stateMachine.sendDataState;

	context.tofCos.selectData(data);
	context.tofCos.startNextAcquisition();
	context.isStream = isStream;

	if (context.tofCos.getExternalShutter())
	{
		newState =  &stateMachine.externalTriggerState;
	}
	else if (isStream)
	{
		newState =  &stateMachine.streamState;
	}

	return newState;
}

/**
 * @brief Task function
 *
 * Called from the main loop
 */
void StateProcessCommand::task()
{
	events_t event;

	if (queueGetEvent(QUEUE_STATE_MACHINE, &event) != QUEUE_OK)
	{
		return; /* cancel here ----------------------------------------> */
	}

	State *newState = stateMachine.getLastState();

	Command command(event.data.command.data, event.data.command.size);
	Answer answer;

	//Use the IP of the TCP command for the UDP data if both use the same. This can be changed by command.
	if (context.differentDataAndCommandIp == false)
	{
	  context.dataIp = event.data.command.ipAddr;
	}

	uint8_t tofCosResult = TOF_COS_STATUS_OK;

	//Get the command
	uint8_t commandValue = command.prepareCommand();

	context.userData.setData(*command.getUserData());

	answer.sendAcknowledge();

	Camera_number* camera_number = Camera_number::getInstance();

	switch (commandValue)
  {
		case Command::GET_CAM1_DATA:
			camera_number->set_new_cam_num(1);
		break;
		case Command::GET_CAM2_DATA:
			camera_number->set_new_cam_num(2);
		break;
		case Command::GET_CAM3_DATA:
			camera_number->set_new_cam_num(3);
		break;
		case Command::GET_CAM4_DATA:
			camera_number->set_new_cam_num(4);
		break;
		case Command::SET_INT_TIMES:
			tofCosResult = setIntegrationTimes(command, answer);
			break;
		case Command::GET_DISTANCE_AMPLITUDE:
			newState = processDataCommand(TOF_COS_Data_e::DATA_DISTANCE_AMPLITUDE, command.isStream());
			break;
		case Command::GET_DISTANCE:
			newState = processDataCommand(TOF_COS_Data_e::DATA_DISTANCE, command.isStream());
			break;
		case Command::GET_GRAYSCALE:
			newState = processDataCommand(TOF_COS_Data_e::DATA_GRAYSCALE, command.isStream());
			break;
		case Command::GET_DCS:
		  newState = processDataCommand(TOF_COS_Data_e::DATA_DCS, command.isStream());
		  break;
		case Command::SET_OFFSET:
			context.tofCos.setOffset(command.getOffset());
			break;
		case Command::SET_MIN_AMPLITUDE:
			context.tofCos.setMinimalAmplitude(command.getMinAmplitude());
			break;
		case Command::SET_FILTER_SETTINGS:
			context.tofCos.setAverageFilterEnabled(command.getifAverageFilterEnabled());
			context.tofCos.setTemporalFilterSettings(command.getTemporalFilterSettings());
			context.tofCos.setMedianFilterEnabled(command.getifMedianFilterEnabled());
			context.tofCos.setEdgeFilterSettings(command.getEdgeFilterThreshold());
			context.tofCos.setInterferenceDetectionSettings(InterferenceDetectionSettings(command.getifInterferenceDetectionUseLastValue(), command.getInterferenceDetectionLimit()));
			context.tofCos.setTemporalEdgeFilterSettings(command.getTemporalEdgeFilterThresholdLow(), command.getTemporalEdgeFilterThresholdHigh());
			break;
			  //Algorithm Edit
		case Command::SET_ALGORITHM_SETTINGS:
			context.tofCos.setMovementDetectionAlgorithmSettings(command.getMovementDetectionAlgorithmSettings());
			context.tofCos.setSkeletonDetectionAlgorithmEnabled(command.getifSkeletonDetectionAlgorithmEnabled());
			break;
		case Command::SET_MODULATION:
			context.tofCos.setModulactionFrequency(command.getModulationFrequency());
			context.tofCos.setModulationChannel(command.getifAutoModulationChannelEnabled(), command.getModulationChannel());
			break;
		case Command::SET_BINNING:
			context.tofCos.setBinning(command.getBinning());
			break;
		case Command::SET_ROI:
			context.tofCos.setRoi(command.getRoi());
			break;
		case Command::SET_HDR:
			context.tofCos.setHdr(command.getHdr());
			break;
		case Command::SET_SHUTTER_MODE:
			context.tofCos.setExternalShutter(command.getifExternalShutterEnabled());
			break;
		case Command::SET_ABS:
			context.tofCos.setAbs(command.getifAbsEnabled());
			break;
		case Command::SET_COMPENSATION:
			context.tofCos.setCompensationEnabled(command.getifDrnuCompensationEnabed(), command.getifTemperatureCompensationEnabled(), command.getifAmbientLightCompensationEnabled(), command.getifGrayscaleCompensationEnabled());
			break;
		case Command::SET_DLL_STEP:
      context.tofCos.setDllStep(command.getDllStep());
			break;
		case Command::STOP_STREAM:
	    newState = &stateMachine.idleState;
			break;
		case Command::SHUTTER:
			context.tofCos.shutter();
			break;
		case Command::CALIBRATE_DRNU:
			//Do not execute the command now, just store it and indicate, that it is a long command
			context.longCommandJob = command;
			newState = &stateMachine.processLongCommandState;
			break;
		case Command::DELETE_CALIBRATION:
			//Do not execute the command now, just store it and indicate, that it is a long command
			context.longCommandJob = command;
			newState = &stateMachine.processLongCommandState;
			break;
		case Command::CALIBRATE_PRODUCTION:
			//Do not execute the command now, just store it and indicate, that it is a long command
			context.longCommandJob = command;
			newState = &stateMachine.processLongCommandState;
			break;
		case Command::CALIBRATE_GRAYSCALE:
			//Do not execute the command now, just store it and indicate, that it is a long command
			context.longCommandJob = command;
			newState = &stateMachine.processLongCommandState;
			break;
		case Command::CALIBRATE_AMBIENT_LIGHT:
			//Do not execute the command now, just store it and indicate, that it is a long command
			context.longCommandJob = command;
			newState = &stateMachine.processLongCommandState;
			break;
		case Command::GET_FIRMWARE_RELEASE:
      answer.sendFirmwareRelease(FIRMWARE_RELEASE);
		  break;
		case Command::GET_CHIP_INFORMATION:
      answer.sendChipInformation(context.tofCos.getChipId(), context.tofCos.getWaferId());
		  break;
		case Command::SET_GRAYSCALE_ILLUMINATION:
      context.tofCos.setGrayscaleIlluminated(command.getifGrayscaleIlluminated());
		  break;
		case Command::SET_DATA_IP_ADDRESS:
      context.dataIp = convertIpToUint32(command.getData());

      //If the data ip is set to zero, clear the flag for different IP, else set it
      if (context.dataIp == 0)
      {
        context.differentDataAndCommandIp = false;
      }
      else
      {
        context.differentDataAndCommandIp = true;
      }
		  break;
		case Command::SEND_FIRMWARE_UPDATE:
		  sdCardWriteDataWriteUpdateFile((const char *)command.getData(), command.getDataSize());
		  break;
		case Command::DEBUG:
		{
			uint8_t *pData = command.getData();
			switch(pData[0])
			{
			  case 0:
          context.tofCos.calibrateGrayscale();
				  break;
			  case 1:
			  	context.tofCos.calibrateAmbientLight();
			  	break;
			  default:
				  break;
			}
			break;
		}
		default:

			break;
  }

	(void) InterfaceInstance::getInstance().sendAnswer(answer, context.dataIp, true);

	stateMachine.changeState(*newState);
}

/** @} */
