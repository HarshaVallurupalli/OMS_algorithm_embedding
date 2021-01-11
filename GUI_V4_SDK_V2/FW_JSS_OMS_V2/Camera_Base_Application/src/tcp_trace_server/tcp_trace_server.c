/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 *
 * @addtogroup tcp_trace_server
 *
 * @{
 */
#include <queue/queue_c.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "tcp_trace_server.h"
#include "hal/timestamp/timestamp.h"

#include "lwip/err.h"
#include "lwip/tcp.h"
#if defined (__arm__) || defined (__aarch64__)
#include "xil_printf.h"
#endif

///Stores, if the connection is opened or not
static bool isConnected = false;
static struct tcp_pcb *tcpPcb;
static bool dataIsSent = false;

extern void platformProcessEthernet(void);

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
	dataIsSent = true;

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
	/* do not read the packet if we are not in ESTABLISHED state */
	if (!p)
	{
		tcp_close(tpcb);
		tcp_recv(tpcb, NULL);
		tcp_sent(tpcb, NULL);
		tcp_err(tpcb, NULL);
		isConnected = false;
		return ERR_OK;
	}

	/* indicate that the packet has been received */
	tcp_recved(tpcb, p->tot_len);

	return ERR_OK;
}

/**
 * @brief Error callback
 *
 * Gets called from the lwip stack when an error has happened
 *
 * @param arg Pointer to the arg, here not used
 * @param err Error
 */
static void  errorCallback(void *arg, err_t err)
{
	isConnected = false;
	switch(err)
  {
    case ERR_RST:

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
	/* set the receive callback for this connection */
	tcp_recv(newpcb, recvCallback);

	/* set the error callback for this connection */
	tcp_err(newpcb, errorCallback);

	/* set the sent callback for this connection */
	tcp_sent(newpcb, sentCallback);

	isConnected = true;

	tcpPcb = newpcb;

	return ERR_OK;
}

/**
 * @brief Send a Trace message
 *
 * Call this function using a formated string to send trace
 *
 * @param format Pointer to a formated string
 */
void tcpTraceServerSend(const char *format, ...)
{
	if (isConnected == false)
	{
		return;
	}/** Cancel here, not connected ----------------> */

	va_list args;
	char buffer[256];
	int length = 0;

	//Print the text to the buffer
	va_start(args, format);
	length += vsnprintf(buffer, sizeof(buffer), format, args);
	va_end(args);

	tcp_write(tcpPcb, buffer, length, TCP_WRITE_FLAG_COPY);

	//Do here a blocking write, so keep the lwip stack running. A timeout prevents the system from blocking
	timestampInit();
	dataIsSent = false;
	while((isConnected) &&
			  (dataIsSent == false) &&
				(timestampGetDiffMs() < 1000))
	{
	  platformProcessEthernet();
	}
}

/**
 * @brief Start the TCP trace server
 *
 * @param port Port to listen on
 * @return 0 if ok else a negative value
 */
int tcpTraceServerStart(const uint16_t port)
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

	/* specify callback to use for incoming connections */
	tcp_accept(pcb, acceptCallback);

	xil_printf("TCP echo server started @ port %d\n\r", port);

	return 0;
}

/** @} */
