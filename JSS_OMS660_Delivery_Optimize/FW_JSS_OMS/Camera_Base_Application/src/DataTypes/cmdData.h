#ifndef SRC_TYPES_H_
#define SRC_TYPES_H_

#include <stdint.h>
#include "GlobalConstants.h"

///Structure to fill the queue. Data is copied into a structure eventCmdData_t
typedef struct
{
  int8_t *data;                   ///<Pointer to the data
  uint32_t size;                  ///<Size of the data in bytes
  uint32_t ipAddr;                ///<Destination IP address
}cmdData_t;

///Structure for data in the queue
typedef struct
{
  uint8_t data[MAX_COMMUNICATION_PAYLOAD_SIZE]; ///<Contains the data (copied from *data in cmdData_t)
  uint32_t size;                  ///<Size of the data
  uint32_t ipAddr;                ///<Destination IP address
}eventCmdData_t;

#endif /* SRC_TYPES_H_ */
