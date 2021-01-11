#include <StateMachine/TofCamState.h>
#include "CommunicationConstants.h"
#include "StateMachineContext.h"
#include "Interface/InterfaceInstance.h"

uint8_t TofCamState::getType()
{
  uint8_t type = CommunicationConstants::DataType::DATA_DISTANCE;

	switch(context.tofCos.getSelectedDataType())
  {
    case TOF_COS_Data_e::DATA_DISTANCE:
      type = CommunicationConstants::DataType::DATA_DISTANCE;
  	  break;
    case TOF_COS_Data_e::DATA_DISTANCE_AMPLITUDE:
    	type = CommunicationConstants::DataType::DATA_DISTANCE_AMPLITUDE;
    	break;
    case TOF_COS_Data_e::DATA_GRAYSCALE:
      type = CommunicationConstants::DataType::DATA_GRAYSCALE;
    	break;
    case TOF_COS_Data_e::DATA_DCS:
      type = CommunicationConstants::DataType::DATA_DCS;
      break;
    default:
    	break;
  }

	return type;
}

void TofCamState::sendError(const uint16_t error)
{
  Answer answer;
  answer.sendError(error);
}

uint8_t TofCamState::sendData()
{
	uint8_t *data = nullptr;
	Answer answer;

	AcquisitionMetaData acquisitionMetaData;

	//Get the data
	uint8_t tofCosStatus = context.tofCos.getData(&data, acquisitionMetaData);

	//If this is ok, send the data with header
	if (tofCosStatus == TOF_COS_STATUS_OK)
	{
	  uint32_t size = acquisitionMetaData.sizeResult;

		//Get the type to send. This also indicates, if it should be sent as large data
	  uint8_t type = getType();

	  answer.sendData(type, data, size);

	  answer.addHeader(context.tofCos, acquisitionMetaData, &context.userData);

	  (void)InterfaceInstance::getInstance().sendAnswer(answer, context.dataIp, false);
	}

	return tofCosStatus;
}

