/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup queue Queue
 *
 * @brief Queue module; FIFO queue
 *
 * @{
 */
#ifndef QUEUE_C_H_
#define QUEUE_C_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "events/events.h"
#include "queue_config.h"


enum
{
	QUEUE_FULL,
	QUEUE_EMPTY,
	QUEUE_NOT_ENOUGH_MEMORY,
	QUEUE_OK
};

uint8_t queuePutEvent(const uint8_t queue, const events_t *pEvent);
uint8_t queuePutCommand(const uint8_t queue, const cmdData_t *pCommand);
uint8_t queueGetEvent(const uint8_t queue, events_t *pEvent);
uint8_t queueCheckEvent(const uint8_t queue);
uint8_t queueInit(void);

#ifdef __cplusplus
}
#endif

#endif /* QUEUE_C_H_ */

/** @} */
