#include <queue/queue_c.h>
#include "events/events.h"
#include <string.h>

///Content of the queue
typedef struct
{
  int32_t indexOut;                ///<Index to take data out of the queue
  int32_t indexIn;                 ///<Index to put data into the queue
  events_t data[QUEUE_SIZE];   ///<Data in the queue; list of events
}queueContent_t;

static queueContent_t queueList[NUM_QUEUE];

#define INC_INDEX(x)                 \
  x++;                               \
  if(x >= QUEUE_SIZE)  { x = 0; }


uint8_t queuePutCommand(const uint8_t queue, const cmdData_t *pCommand)
{
	queueContent_t *p = &queueList[queue];

	int32_t nextIndex = p->indexIn;
	INC_INDEX(nextIndex);

	if (nextIndex == p->indexOut)
	{
		return QUEUE_FULL;
	}

	if (pCommand->size > MAX_COMMUNICATION_PAYLOAD_SIZE)
	{
		return QUEUE_NOT_ENOUGH_MEMORY;
	}

	events_t *pNewEvent = &p->data[p->indexIn];
	memcpy(pNewEvent->data.command.data, pCommand->data, pCommand->size);
	pNewEvent->data.command.size = pCommand->size;
	pNewEvent->data.command.ipAddr = pCommand->ipAddr;
	p->indexIn = nextIndex;

	return QUEUE_OK;
}

uint8_t queuePutEvent(const uint8_t queue, const events_t *pEvent)
{
	queueContent_t *p = &queueList[queue];

	int nextIndex = p->indexIn;
	INC_INDEX(nextIndex);

	if (nextIndex == p->indexOut)
	{
		return QUEUE_FULL;
	}

	p->data[p->indexIn] = *pEvent;
	p->indexIn = nextIndex;

	return QUEUE_OK;
}

uint8_t queueCheckEvent(const uint8_t queue)
{
	queueContent_t *p = &queueList[queue];

	if (p->indexIn == p->indexOut)
	{
		return QUEUE_EMPTY;
  }

	return QUEUE_OK;
}

uint8_t queueGetEvent(const uint8_t queue, events_t *pEvent)
{
	queueContent_t *p = &queueList[queue];

	if (p->indexIn == p->indexOut)
	{
		return QUEUE_EMPTY;
	}

	*pEvent = p->data[p->indexOut];
	INC_INDEX(p->indexOut);

	return QUEUE_OK;
}

uint8_t queueInit(void)
{
	return QUEUE_OK;
}



