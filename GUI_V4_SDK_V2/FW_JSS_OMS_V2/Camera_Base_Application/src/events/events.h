/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup events Events
 *
 * @brief Event definitions
 */
#ifndef EVENTS_EVENTS_H_
#define EVENTS_EVENTS_H_

#include <stdint.h>
#include "DataTypes/cmdData.h"

///Event structure to put into the queue
typedef struct
{
  union
  {
    eventCmdData_t command; ///<Events for the state machine
  }data;
}events_t;

#endif /* EVENTS_EVENTS_H_ */

/** @} */
