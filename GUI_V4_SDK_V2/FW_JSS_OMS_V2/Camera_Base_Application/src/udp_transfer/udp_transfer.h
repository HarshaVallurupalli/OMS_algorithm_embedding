/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup udp_transfer UDP Transfer
 * @brief Data transmission over UDP
 *
 * This module requires the lwip stack.
 *
 * @{
 */

#ifndef UDP_TRANSFER_UDP_TRANSFER_H_
#define UDP_TRANSFER_UDP_TRANSFER_H_

#include <stdbool.h>
#include <stdint.h>

typedef enum
{
	UDP_TRANSPORT_RESULT_OK,
	UDP_TRANSPORT_RESULT_BUSY,
	UDP_TRANSPORT_RESULT_ERROR_NO_IP,
	UDP_TRANSPORT_RESULT_ERROR_INIT_FAILED,
	UDP_TRANSPORT_RESULT_ERROR_NO_PORT
}udpTransportResult_t;

udpTransportResult_t udpTransferInit(void);
udpTransportResult_t udpTransferSendData(const int8_t *pData, const uint32_t size, const uint32_t destIp);
void udpTransferProcess(void);
bool udpTransferIsBusy(void);
void udpTransferSetDestIp(const uint8_t ip1, const uint8_t ip2, const uint8_t ip3, const uint8_t ip4);
void udpTransferSetDestPort(const uint16_t destPort);

#endif /* UDP_TRANSFER_UDP_TRANSFER_H_ */

/** @} */
