/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @addtogroup interface
 */
#include <GlobalSettings.h>
#include <Interface/Interface.h>
#include <stddef.h>
#include "xparameters.h"
#include "netif/xadapter.h"
#include "hal/cpu/platform.h"
#include "hal/cpu/platform_config.h"
#if defined (__arm__) || defined(__aarch64__)
#include "xil_printf.h"
#endif
#include "lwip/tcp.h"
#include "xil_cache.h"
#include "lwip/init.h"
#include "udp_transfer/udp_transfer.h"
#include "tcp_cmd_handler/tcp_cmd_handler.h"
#include "tcp_trace_server/tcp_trace_server.h"
#include <queue/queue_c.h>


#if LWIP_DHCP==1
#include "lwip/dhcp.h"
#endif


/* missing declaration in lwIP */
void lwip_init();

volatile int interfaceTimer;
extern volatile int TcpFastTmrFlag;
extern volatile int TcpSlowTmrFlag;
static struct netif server_netif;
struct netif *echo_netif;

Interface::Interface()
{
	initialized = false;
}

/**
 * @brief Send answer to the connected PC
 *
 * This function sends data to the connected PC. It sends two kind of data types:
 * - An answer to the TCP socket if needed
 * - The data to the UDP socket if present
 *
 * These combinations are possible:
 * - only answer (after a command for settings)
 * - data and answer (after a command for an image)
 * - only data (during a stream, an answer is there sent only with the first image after the command)
 *
 *
 * @param answer Reference to the answer to send
 * @param destIP Destination IP for the UDP socket
 * @param sendTcpAnswer true, if the TCP answer has to be sent
 * @retval INTERFACE_RESULT_ERROR Data could not be sent
 * @retval INTERFACE_RESULT_OK Data sent
 * @return Result of sending the data
 */
TypeInterfaceResult Interface::sendAnswer(Answer &answer, uint32_t destIp, bool sendTcpAnswer)
{
	if (tcpCmdHandlerConnectionIsOpen() == false)
	{
		return INTERFACE_RESULT_ERROR;
	}

	//The flag indicates to send an answer to the TCP socket
	if (sendTcpAnswer)
	{
	  cmdData_t cmdData;
	  cmdData.data = (int8_t *)answer.getAnswer();
	  cmdData.size = answer.getAnswerSize();
	  queuePutCommand(QUEUE_TCP_ANSWER, &cmdData);
	}

	//No data to send, so OK
	if ((answer.getDataSize() == 0) || (answer.getData() == nullptr))
	{
	  return INTERFACE_RESULT_OK;
	}

	udpTransferSendData((const int8_t *)answer.getData(), answer.getDataSize(), (const uint32_t)destIp);

	return INTERFACE_RESULT_OK;
}

bool Interface::isBusy(void)
{
	return udpTransferIsBusy();
}

bool Interface::cmdInterfaceIsBusy()
{
	return tcpCmdHandlerProcess();
}

void Interface::process(void)
{
	//Dont do anything if init has not been called
	if (initialized == false)
	{
		return;
	}

	platformProcessEthernet();

	//The tcp command handler returns true, if it is busy
	bool tcpBusy = tcpCmdHandlerProcess();

	//Only process the UDP output, if the tcp is not busy any more.
	if (tcpBusy == false)
	{
	  udpTransferProcess();
	}
}

TypeInterfaceResult Interface::initDefault()
{
	ipAddress_t ip;
	ipAddress_t subnet;

	ip.val0 = 10;
	ip.val1 = 10;
	ip.val2 = 31;
	ip.val3 = 180;

	subnet.val0 = 255;
	subnet.val1 = 255;
	subnet.val2 = 255;
	subnet.val3 = 0;

	return init(ip, subnet, 2);
}

/**
 * @brief Init
 *
 * Call this before using the interface
 *
 * @param ip IP address to use
 * @param subnet Subnet to set
 * @param macLastNumber Last byte of the MAC number (no HW to read the number yet)
 * @retval INTERFACE_RESULT_ERROR Data could not be sent
 * @retval INTERFACE_RESULT_OK Data sent
 * @return Result of the initialization
 */
TypeInterfaceResult Interface::init(const ipAddress_t ip, const ipAddress_t subnet, uint8_t macLastNumber)
{
	ip4_addr_t ipaddr, netmask, gw;

	/* the mac address of the board. this should be unique per board */
	unsigned char mac_ethernet_address[] =
	{ 0x00, 0x0a, 0x35, 0x00, 0x01, macLastNumber };

	echo_netif = &server_netif;

	init_platform();

#if LWIP_DHCP==1
	ipaddr.addr = 0;
	gw.addr = 0;
	netmask.addr = 0;
#else
	/* initliaze IP addresses to be used */
	IP4_ADDR(&ipaddr, ip.val0, ip.val1, ip.val2, ip.val3);
	IP4_ADDR(&netmask, subnet.val0, subnet.val1, subnet.val2, subnet.val3);
	IP4_ADDR(&gw, 192, 168, 1, 1);
#endif

	lwip_init();

	/* Add network interface to the netif_list, and set it as default */
	if (!xemac_add(echo_netif, &ipaddr, &netmask, &gw, mac_ethernet_address, PLATFORM_EMAC_BASEADDR))
	{
		xil_printf("Error adding N/W interface\n\r");
		return INTERFACE_RESULT_ERROR;
	}
	netif_set_default(echo_netif);

	/* now enable interrupts */
	platform_enable_interrupts();

	/* specify that the network if is up */
	netif_set_up(echo_netif);

#if (LWIP_DHCP==1)
	/* Create a new DHCP client for this interface.
	 * Note: you must call dhcp_fine_tmr() and dhcp_coarse_tmr() at
	 * the predefined regular intervals after starting the client.
	 */
	dhcp_start(echo_netif);
	dhcp_timoutcntr = 24;

	while(((echo_netif->ip_addr.addr) == 0) && (dhcp_timoutcntr > 0))
	xemacif_input(echo_netif);

	if (dhcp_timoutcntr <= 0)
	{
		if ((echo_netif->ip_addr.addr) == 0)
		{
			xil_printf("DHCP Timeout\r\n");
			xil_printf("Configuring default IP of 192.168.1.10\r\n");
			IP4_ADDR(&(echo_netif->ip_addr), 192, 168, 1, 10);
			IP4_ADDR(&(echo_netif->netmask), 255, 255, 255, 0);
			IP4_ADDR(&(echo_netif->gw), 192, 168, 1, 1);
		}
	}

	ipaddr.addr = echo_netif->ip_addr.addr;
	gw.addr = echo_netif->gw.addr;
	netmask.addr = echo_netif->netmask.addr;
#endif

	tcpCmdHandlerStart(50660);

	tcpTraceServerStart(50661);

	udpTransferInit();
	udpTransferSetDestIp(192, 168, 1, 100);
	udpTransferSetDestPort(45454);

	initialized = true;

	return INTERFACE_RESULT_OK;
}

/** @} */
