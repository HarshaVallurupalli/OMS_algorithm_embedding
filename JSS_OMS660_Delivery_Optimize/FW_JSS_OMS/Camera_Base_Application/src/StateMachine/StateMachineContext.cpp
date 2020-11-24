#include <hal/i2c/i2cInstance.h>
#include <StateMachine/StateMachineContext.h>
#include "ErrorCodes.h"

StateMachineContext::StateMachineContext(): calibrationMemory(tofCos, i2cInstance::getInstance())
{
  isStream = false;
  dataIp = 0;
  differentDataAndCommandIp = false;
}


void StateMachineContext::addInternalEvent(const uint8_t event)
{
	eventQueueInternalEvents.push(event);
}

void StateMachineContext::setErrorCodeFromTofCosStatus(const uint8_t tofCosStatus)
{
  switch(tofCosStatus)
  {
    case TOF_COS_STATUS_ERROR_DATA_ACQUISITION:
      error = ERROR_CODE_ACQUISITION;
      break;
    case TOF_COS_STATUS_ERROR_SENSOR_COMMUNICATION:
      error =  ERROR_CODE_SENSOR_COMMUNICATION;
      break;
    case TOF_COS_STATUS_OK:
      error =  ERROR_CODE_OK;
      break;
    default:
      error =  ERROR_CODE_OK;
      break;
  }
}
