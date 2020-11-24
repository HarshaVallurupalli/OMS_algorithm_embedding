/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 *
 * @addtogroup tcp_cmd_handler
 *
 * @{
 */
#include <queue/queue_c.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "DataTypes/cmdData.h"
#include "lwip/err.h"
#include "lwip/tcp.h"
#include "hal/cpu/cpu.h"
#if defined (__arm__) || defined (__aarch64__)
#include "xil_printf.h"
#endif

#define MARKING_START 0xFFFFAA55                                   ///<Start marking, at the start of the data
#define MARKING_END   0xFFFF55AA                                   ///<End marking, at the end of the data
#define HEADER_SIZE            8                                   ///<[Bytes] size of the header
#define END_MARKING_SIZE       4                                   ///<[Bytes] Size of the end marking
#define PROTOCOL_OVERHEAD_SIZE (HEADER_SIZE + END_MARKING_SIZE)    ///<[Bytes] Total overhead of the header
#define PAYLOAD_SIZE_INDEX     4                                   ///<Index of the payload size in the header
#define MAX_CONNECTIONS        5                                   ///<Max. Number of parallel TCP connections
#define MAX_DATA_SIZE    (6000000 + PROTOCOL_OVERHEAD_SIZE)        ///<[Bytes] Max. Data size to receive


///Connection state enum
typedef enum
{
  TCP_STATE_IDLE,
	TCP_STATE_SEND_DATA,
	TCP_STATE_WAIT_DATA_ACKNOWLEDGED
}tcpState_e;

///Context structure for the connections
typedef struct
{
	int8_t data[MAX_DATA_SIZE]; ///<data input buffer
	uint32_t index;             ///<Index for access
  uint32_t numBytes;          ///<[Bytes] Data size in the buffer
  uint32_t maxBytes;          ///<[Bytes] Buffer size (could be used if data is generated by malloc and not static)
}tcpData_t;

///Context structure for the connections
typedef struct
{
	struct tcp_pcb *pcb;        ///<Pointer to the tcp_pcb for this connection
	tcpData_t inputData;        ///<Received Data
	tcpData_t outputData;       ///<Data to send
	tcpState_e state;           ///<Stores the actual state of the connection
}tcpCmdHandlerCtx_t;

//Static variables
static tcpCmdHandlerCtx_t context;

/**
 * @brief Clear received data
 *
 * Call this function to clear the received data. At the moment just
 * reset the size. Could also free data if malloc would be used.
 *
 * @parm pCtx Pointer to the context
 */
static void clearReceivedData(tcpCmdHandlerCtx_t *pCtx)
{
	pCtx->inputData.numBytes = 0;
}

/**
 * @brief Check for valid start marking
 *
 * @retval false No valid start marking (yet)
 * @retval true Valid start marking
 * @return Valid start marking or not (true/false)
 */
static bool hasValidStartMarking(const tcpCmdHandlerCtx_t *pCtx)
{
  uint8_t *pData = (uint8_t *)pCtx->inputData.data;

	bool isValidMarking = ( (pData[0] == (MARKING_START >> 24)) ||
			                    (pData[1] == (MARKING_START >> 16)) ||
													(pData[2] == (MARKING_START >> 8)) ||
													(pData[3] == (MARKING_START >> 0)) );

	return isValidMarking;
}

/**
 * @brief Check for valid end marking
 *
 * @retval false No valid end marking (yet)
 * @retval true Valid end marking
 * @return Valid end marking or not (true/false)
 */
static bool hasValidEndMarking(const tcpCmdHandlerCtx_t *pCtx)
{
	uint8_t *pData = (uint8_t *)pCtx->inputData.data;
	uint32_t size = pCtx->inputData.numBytes;

	uint8_t byte3 = pData[size - 4];
	uint8_t byte2 = pData[size - 3];
	uint8_t byte1 = pData[size - 2];
	uint8_t byte0 = pData[size - 1];

  bool isValidMarking = ( (byte3 == (MARKING_END >> 24)) ||
				                  (byte2 == (MARKING_END >> 16)) ||
													(byte1 == (MARKING_END >> 8)) ||
													(byte0 == (MARKING_END >> 0)) );

  return isValidMarking;
}

/**
 * @brief Check if the length is correct
 *
 * @retval false No correct length (yet)
 * @retval true Correct length received
 * @return Valid command data or not (true/false)
 */
static bool lengthIsCorrect(const tcpCmdHandlerCtx_t *pCtx)
{
	uint8_t *pData = (uint8_t *)pCtx->inputData.data;
	uint32_t size = pCtx->inputData.numBytes;

	uint32_t expectedPayloadBytes = (pData[PAYLOAD_SIZE_INDEX] << 24) + (pData[PAYLOAD_SIZE_INDEX+1] << 16) + (pData[PAYLOAD_SIZE_INDEX+2] << 8) + (pData[PAYLOAD_SIZE_INDEX+3] << 0);

	if ((size -  PROTOCOL_OVERHEAD_SIZE) == expectedPayloadBytes)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
 * @brief Check for valid command data
 *
 * @retval false No valid command data (yet)
 * @retval true Valid command data received
 * @return Valid command data or not (true/false)
 */
static bool isValidData(tcpCmdHandlerCtx_t *pCtx)
{
	if (pCtx->inputData.numBytes < HEADER_SIZE)
	{
    return false;
	}

	if (hasValidStartMarking(pCtx) == false)
	{
		return false;
	}

	if (hasValidEndMarking(pCtx) == false)
	{
    return false;
	}

	if (lengthIsCorrect(pCtx) == false)
	{
		return false;
	}

	return true;
}

/**
 * @brief Handle the received data
 *
 * Get the received data and put it together.
 *
 * @param pCtx Pointer to the connection context
 * @param p Pointer to the received data
 */
static void handleReceivedData(tcpCmdHandlerCtx_t *pCtx, struct pbuf *p)
{
  uint32_t maxAllowedLength = pCtx->inputData.maxBytes - pCtx->inputData.numBytes;
	if (p->tot_len > maxAllowedLength)
	{
    //Cannot receive the data, it is too big for the receiver buffer
		clearReceivedData(pCtx);
	}
	else
	{
	  //Very important: Cache flush. If not, sometimes the received data is corrupted
	  cpuInvalidateDCachebyAddrU8(reinterpret_cast<uint8_t *>(p->payload), p->len);

	  uint32_t copied = pbuf_copy_partial(p, &pCtx->inputData.data[pCtx->inputData.numBytes], p->tot_len, 0);
	  pCtx->inputData.numBytes += copied;
	}

	//Got the desired data
  if (isValidData(pCtx))
  {
  	cmdData_t cmdData;
  	cmdData.data = &pCtx->inputData.data[HEADER_SIZE];
  	cmdData.size = pCtx->inputData.numBytes - PROTOCOL_OVERHEAD_SIZE;
  	cmdData.ipAddr = pCtx->pcb->remote_ip.addr;

  	//Only use data with payload.
  	if (cmdData.size > 0)
  	{
  	  queuePutCommand(QUEUE_STATE_MACHINE, &cmdData);
  	}
  	clearReceivedData(pCtx);
  }

	pbuf_free(p);
}

/**
 * @brief Sent callback
 *
 * Gets called from the lwip stack when data was sent
 *
 * @param arg Pointer to the arg, here not used
 * @param tpcb Pointer to the connection
 * @param len Number of bytes confirmed
 */
static err_t sentCallback(void *arg, struct tcp_pcb *tpcb, u16_t len)
{
	tcpCmdHandlerCtx_t *pCtx = (tcpCmdHandlerCtx_t *)arg;

	//Cancel, if not in wanted state
	if (pCtx->state != TCP_STATE_WAIT_DATA_ACKNOWLEDGED)
	{
		return ERR_OK;
	}/** Cancel here ---------------------------------------> **/

	pCtx->outputData.index += len;
	if (pCtx->outputData.index >= pCtx->outputData.numBytes)
	{
	  pCtx->state = TCP_STATE_IDLE;
		pCtx->outputData.index = 0;
		pCtx->outputData.numBytes = 0;
	}
	else
	{
		pCtx->state = TCP_STATE_SEND_DATA;
	}

	return ERR_OK;
}

/**
 * @brief Receive callback
 *
 * Gets called from the lwip stack when data is received.
 *
 * @param arg Pointer to the arg, here not used
 * @param tpcb Pointer to the connection
 * @param p Pointer to the received data
 * @param err Error
 * @return ERR_OK
 */
static err_t recvCallback(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err)
{
	tcpCmdHandlerCtx_t *pCtx = (tcpCmdHandlerCtx_t *)arg;

	/* do not read the packet if we are not in ESTABLISHED state */
	if (!p)
	{
		pCtx->pcb = NULL;
		clearReceivedData(pCtx);
		tcp_close(tpcb);
		tcp_recv(tpcb, NULL);
		tcp_sent(pCtx->pcb, NULL);
		tcp_err(tpcb, NULL);
		return ERR_OK;
	}

	/* process the data here */
	handleReceivedData(pCtx, p);

	/* indicate that the packet has been received */
	tcp_recved(tpcb, p->tot_len);

	return ERR_OK;
}

/**
 * @brief Error callback
 *
 * Gets called from the lwip stack when an error occurs
 *
 * @param arg Pointer to the arg, here not used
 * @param err Error
 */
void  errorCallback(void *arg, err_t err)
{
	tcpCmdHandlerCtx_t *pCtx = (tcpCmdHandlerCtx_t *)arg;

	switch(err)
  {
  case ERR_RST:
  	tcp_close(pCtx->pcb);
    tcp_recv(pCtx->pcb, NULL);
    tcp_sent(pCtx->pcb, NULL);
    tcp_err(pCtx->pcb, NULL);
    pCtx->pcb = NULL;
    clearReceivedData(pCtx);
  	break;
  }
}

/**
 * @brief Accept callback
 *
 * Gets called from the lwip stack when a TCP connection is opened.
 *
 * @param arg Pointer to the arg, here not used
 * @param newpcb Pointer to the new connection
 * @param err Error
 * @return ERR_OK
 */
static err_t acceptCallback(void *arg, struct tcp_pcb *newpcb, err_t err)
{
	tcpCmdHandlerCtx_t *pCtx = &context;

	//If Connected, clear the connection. Only one connection at the moment is supported
	if (context.pcb != NULL)
	{
		tcp_close(newpcb);
		tcp_recv(newpcb, NULL);
		tcp_sent(pCtx->pcb, NULL);
		tcp_err(newpcb, NULL);
		return ERR_OK;
	}

	/* Give the pointer to the context as argument */
  tcp_arg(newpcb, pCtx);

	pCtx->inputData.numBytes = 0;
	pCtx->pcb = newpcb;
	pCtx->state = TCP_STATE_IDLE;

	/* set the receive callback for this connection */
	tcp_recv(newpcb, recvCallback);

	/* set the sent callback for this connection */
	tcp_sent(newpcb, sentCallback);

	/* set the error callback for this connection */
	tcp_err(newpcb, errorCallback);

	return ERR_OK;
}

/**
 * @brief Put the protocol markers to the buffer
 *
 * @param pBuffer Pointer to the buffer to put the markers
 * @param size Size of the output data to send
 * @return Total size; payload + protocol overhead
 */
static uint32_t putProtocolMarkers(int8_t *pBuffer, uint32_t size)
{
  //Start marker
	pBuffer[0] = (MARKING_START >> 24) & 0xFF;
  pBuffer[1] = (MARKING_START >> 16) & 0xFF;
  pBuffer[2] = (MARKING_START >> 8) & 0xFF;
  pBuffer[3] = (MARKING_START >> 0) & 0xFF;

  //Size
  pBuffer[PAYLOAD_SIZE_INDEX] = (size >> 24) & 0xFF;
  pBuffer[PAYLOAD_SIZE_INDEX+1] = (size >> 16) & 0xFF;
  pBuffer[PAYLOAD_SIZE_INDEX+2] = (size >> 8) & 0xFF;
  pBuffer[PAYLOAD_SIZE_INDEX+3] = (size >> 0) & 0xFF;

  //End marker
  pBuffer[PROTOCOL_OVERHEAD_SIZE + size - 4] = (MARKING_END >> 24) & 0xFF;
  pBuffer[PROTOCOL_OVERHEAD_SIZE + size - 3] = (MARKING_END >> 16) & 0xFF;
  pBuffer[PROTOCOL_OVERHEAD_SIZE + size - 2] = (MARKING_END >> 8) & 0xFF;
  pBuffer[PROTOCOL_OVERHEAD_SIZE + size - 1] = (MARKING_END >> 0) & 0xFF;

	return size + PROTOCOL_OVERHEAD_SIZE;
}

/**
 * @brief Helper function to get the output data from the event
 *
 * @param pCtx Pointer to the connection context
 * @parem pEvent Pointer to the event
 */
static void putEventToOutputData(tcpCmdHandlerCtx_t *pCtx, const events_t *pEvent)
{
  pCtx->outputData.index = 0;
  memcpy(&pCtx->outputData.data[HEADER_SIZE], pEvent->data.command.data, pEvent->data.command.size);
  uint32_t finalSize = putProtocolMarkers(pCtx->outputData.data, pEvent->data.command.size);
  pCtx->outputData.numBytes = finalSize;
}

/**
 * @brief Process the TCP output
 *
 * This function processes the TCP output and returns, if TCP data is being sent or not. This
 * helps to give the TCP a priority over others (for example UDP output)
 *
 * @retval true TCP is busy
 * @retval false TCP is not busy
 * @return TCP output status
 */
bool tcpCmdHandlerProcess(void)
{
	tcpCmdHandlerCtx_t *pCtx = &context;

	if (pCtx->pcb == NULL)
	{
		return false;
	}/* Return, not connected --------------------->*/

	//Noting to send yet, check queue
	switch(pCtx->state)
	{
	  case TCP_STATE_IDLE:
	  {
	    events_t event;
		  if (queueGetEvent(QUEUE_TCP_ANSWER, &event) == QUEUE_OK)
		  {
        putEventToOutputData(pCtx, &event);
        pCtx->state = TCP_STATE_SEND_DATA;
	    }
	  }
	  break;

	  case TCP_STATE_WAIT_DATA_ACKNOWLEDGED:
      //Do nothing here
	    break;

	  case TCP_STATE_SEND_DATA:
	  {
	  	int8_t *pOut = pCtx->outputData.data;
	    int32_t outSize = pCtx->outputData.numBytes - pCtx->outputData.index;

	    //Limit to available space
	    if (tcp_sndbuf(pCtx->pcb) < outSize)
	    {
	      outSize = tcp_sndbuf(pCtx->pcb);
	    }

	    //Send data with the size of the available space
	    if (outSize > 0)
	    {
	      err_t err = tcp_write(pCtx->pcb, pOut, outSize, TCP_WRITE_FLAG_COPY);

	      //Only change the state, if the write was OK. Important: The data is not yet sent here. The sending is later confirmed by a callback
	      if (err == ERR_OK)
		    {
			    pCtx->state = TCP_STATE_WAIT_DATA_ACKNOWLEDGED;
		    }
	    }
	  }
	  break;
	  default:
	  	break;
	}

	//Only the state idle is allowed to return false
	if (pCtx->state == TCP_STATE_IDLE)
	{
		return false;
	}

	return true;
}

/**
 * @brief Start the TCP command handler (TCP server)
 *
 * @param port Port to listen on
 * @return 0 if ok else a negative value
 */
int32_t tcpCmdHandlerStart(const uint16_t port)
{
	struct tcp_pcb *pcb;
	err_t err;

	/* create new TCP PCB structure */
	pcb = tcp_new();
	if (!pcb)
	{
		xil_printf("Error creating PCB. Out of Memory\n\r");
		return -1;
	}

	/* bind to specified @port */
	err = tcp_bind(pcb, IP_ADDR_ANY, port);
	if (err != ERR_OK)
	{
		xil_printf("Unable to bind to port %d: err = %d\n\r", port, err);
		return -2;
	}

	/* Here no arg needed */
	tcp_arg(pcb, NULL);

	/* listen for connections */
	pcb = tcp_listen(pcb);
	if (!pcb)
	{
		xil_printf("Out of memory while tcp_listen\n\r");
		return -3;
	}

	context.inputData.numBytes = 0;
	context.inputData.maxBytes = MAX_DATA_SIZE;

	context.outputData.numBytes = 0;
	context.outputData.maxBytes = MAX_DATA_SIZE;
	context.pcb = NULL;
	context.state = TCP_STATE_IDLE;

	/* specify callback to use for incoming connections */
	tcp_accept(pcb, acceptCallback);

	xil_printf("TCP echo server started @ port %d\n\r", port);

	return 0;
}

/**
 * @brief Read, if tcp is connected
 *
 * @retval true TCP is connected
 * @retval false TCP is not connected
 * @return TCP connection status
 */
bool tcpCmdHandlerConnectionIsOpen(void)
{
  if(context.pcb != NULL)
  {
    return true;
  }

	return false;
}

/** @} */