/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 *
 * @addtogroup udp_transfer
 *
 * @{
 */
#include "udp_transfer.h"
#include "hal/timestamp/timestamp.h"
#include "lwip/udp.h"
#include <stdbool.h>
#include <stdint.h>
#include <sleep.h>

#define NUM_BYTES_PER_PACKET          1400   ///<Number of payload bytes per UDP packet
#define PACKET_HEADER_SIZE              20   ///<Number of header bytes per UDP packet
#define MINIMUM_DELAY_BETWEEN_PACKETS   80   ///<[us]Minimum delay between UDP packets to not overrun the receiving PC

///Context structure
typedef struct
{
	uint16_t number;                       ///<Number of the data that is being sent
	uint16_t dataType;                     ///<Type of the data that is being sent
	uint32_t totalSizeBytes;               ///<Total size of the data that is being sent
	uint16_t packetSizeBytes;              ///<Size of the actual packet
	uint32_t bytesSent;                    ///<Bytes already sent
	uint32_t numPacket;                    ///<Number of packets needed to send the data
	int8_t *data;                          ///<Pointer to the data to send
	ip4_addr_t destAddr;                   ///<Destination IP address
	uint16_t destPort;                     ///<Destination port
	bool busy;                             ///<true, if a transmission is in progress
	struct udp_pcb *udp_pcb;               ///<Pointer to the udp instance of the lwip stack
	uint32_t timestampLastPacket;          ///<Stores the timestamp of the last packet sent
}udpTransferCtx_t;

///Context; could be changed to an array to have multiple instances.
static udpTransferCtx_t ctx;

static bool packetJustSent(udpTransferCtx_t *pTransferCtx)
{
	uint32_t actTimestamp = timestampGetUsCounter();
	uint32_t diff = 0;

	//Handle wrap
	if (actTimestamp > pTransferCtx->timestampLastPacket)
	{
		diff = actTimestamp - pTransferCtx->timestampLastPacket;
	}
	else
	{
		diff = (0xFFFFFFFF - pTransferCtx->timestampLastPacket) + actTimestamp;
	}

	//Not yet enough delay
	if (diff < MINIMUM_DELAY_BETWEEN_PACKETS)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
 * @brief Fill in a u16 value into a buffer
 *
 * @param pBuffer Pointer to the buffer
 * @param value Value to put
 * @return Number of bytes changed in the buffer
 */
static uint32_t fillUint16ToBuffer(uint8_t *pBuffer, const uint16_t value)
{
	pBuffer[0] = value >> 8;
	pBuffer[1] = value & 0xFF;

	return 2;
}

/**
 * @brief Fill in a u32 value into a buffer
 *
 * @param pBuffer Pointer to the buffer
 * @param value Value to put
 * @return Number of bytes changed in the buffer
 */
static uint32_t fillUint32ToBuffer(uint8_t *pBuffer, const uint32_t value)
{
	pBuffer[0] = value >> 24;
	pBuffer[1] = (value >> 16) & 0xFF;
	pBuffer[2] = (value >> 8) & 0xFF;
	pBuffer[3] = value & 0xFF;

	return 4;
}

/**
 * @brief Helper function to fill in the header data
 *
 * @param pTransferCtx Pointer to the context
 * @param pbHead Pointer to the lwip pbuf containing the header data
 */
static void fillHeader(const udpTransferCtx_t *pTransferCtx, struct pbuf *pbHead)
{
	uint8_t *pOut = (uint8_t *)pbHead->payload;
	uint32_t offset = 0;

	offset += fillUint16ToBuffer(&pOut[offset], pTransferCtx->number);
	//offset += fillUint16ToBuffer(&pOut[offset], pTransferCtx->dataType);
	offset += fillUint32ToBuffer(&pOut[offset], pTransferCtx->totalSizeBytes);
	offset += fillUint16ToBuffer(&pOut[offset], pTransferCtx->packetSizeBytes);
	offset += fillUint32ToBuffer(&pOut[offset], pTransferCtx->bytesSent);
	offset += fillUint32ToBuffer(&pOut[offset], pTransferCtx->numPacket);

	//Packet number = bytesSent / NUM_BYTES_PER_PACKET
	offset += fillUint32ToBuffer(&pOut[offset], (pTransferCtx->bytesSent / NUM_BYTES_PER_PACKET));
}

/**
 * @brief Processing function
 *
 * Call this function repeatedly from the main loop. It handles the transmission of all
 * the packets.
 */
void udpTransferProcess(void)
{
	udpTransferCtx_t *p = &ctx;

	if (p->busy == false)
	{
		return;
	}/* Return directly if nothing has to be done --------------------------->*/

	//Do nothing, if a packet has just been sent. --> Do not overrun the receiving PC
	if (packetJustSent(p))
	{
		return;
	}

	uint32_t payloadSize = p->totalSizeBytes - p->bytesSent;
	if (payloadSize > NUM_BYTES_PER_PACKET)
	{
		payloadSize = NUM_BYTES_PER_PACKET;
	}

	p->packetSizeBytes = payloadSize;

	struct pbuf *pb = pbuf_alloc(PBUF_TRANSPORT, p->packetSizeBytes, PBUF_REF);
	if (pb == NULL)
	{
		return;
	}/* Failed, try it the next time              --------------------------->*/

	struct pbuf *pbHead = pbuf_alloc(PBUF_TRANSPORT, PACKET_HEADER_SIZE, PBUF_RAM);
	if (pbHead == NULL)
	{
	  pbuf_free(pb);
	  return;
	}/* Failed, try it the next time              --------------------------->*/

	//Combinte the two pbufs: one of the header, one for the data
	pbuf_cat(pbHead, pb);

	//Fill in the data for the header (this data is copied)
	fillHeader(p, pbHead);

	//Set the pointer to the payload
	pb->payload = &p->data[p->bytesSent];

	err_t err = udp_sendto(p->udp_pcb, pbHead, &p->destAddr, p->destPort);

  //Only increment the counters, if the sending is successful, otherwise try it the next time
  if (err == ERR_OK)
  {
  	//Store the timestamp to know the time of the packet
  	p->timestampLastPacket = timestampGetUsCounter();

  	p->bytesSent += p->packetSizeBytes;

  	if (p->bytesSent >= p->totalSizeBytes)
  	{
  		p->busy = false;
  	}
  }
  else
  {
  	udp_remove(p->udp_pcb);
  	p->udp_pcb = udp_new();
  }
	pbuf_free(pbHead);
}

/**
 * @brief Send data to the receiver
 *
 * Call this function to send data to the receiver. If the data needs more than one udp packet to
 * get sent, it will not be completely sent after calling the function. Only the first packet is sent.
 *
 * @retval UDP_TRANSPORT_RESULT_BUSY Transmission is still in progress, try it later
 * @retval UDP_TRANSPORT_RESULT_ERROR_NO_IP No ip is set, data cannot be sent
 * @retval UDP_TRANSPORT_RESULT_OK Transmission started
 * @return result of the transmission
 */
udpTransportResult_t udpTransferSendData(const int8_t *pData, const uint32_t size, const uint32_t destIp)
{
	udpTransferCtx_t *p = &ctx;

	if (p->busy)
	{
		return UDP_TRANSPORT_RESULT_BUSY;
	}/* Return, busy -------------------------------->*/

	if (destIp == 0)
	{
		return UDP_TRANSPORT_RESULT_ERROR_NO_IP;
	}/* Return, no IP set --------------------------->*/

	if (p->destPort == 0)
	{
		return UDP_TRANSPORT_RESULT_ERROR_NO_PORT;
	}/* Return, no port set ------------------------->*/

	if ((pData == NULL) || (size == 0))
	{
		return UDP_TRANSPORT_RESULT_OK;
	}/* Return, nothing to send --------------------->*/


	p->destAddr.addr = destIp;

	p->number++;
	p->data = (int8_t *)pData;
	p->totalSizeBytes = size;
	p->bytesSent = 0;
	p->dataType = 0; //test, not yet implemented

	//Calculate the number of packets needed. Add one, if the size does not fit
	p->numPacket = p->totalSizeBytes / NUM_BYTES_PER_PACKET;
	if ((p->totalSizeBytes % NUM_BYTES_PER_PACKET) != 0)
	{
		p->numPacket++;
	}

	p->busy = true;

	return UDP_TRANSPORT_RESULT_OK;
}

/**
 * @brief Read back, if the transport is busy
 *
 * If the transport is busy, it cannot send further data
 *
 * @retval true Transport is busy
 * @retval false Transport is not busy
 * @return Transport busy or not
 */
bool udpTransferIsBusy(void)
{
	udpTransferCtx_t *p = &ctx;

	return p->busy;
}

/**
 * @brief Set the destination port
 *
 * @param port Port
 */
void udpTransferSetDestPort(const uint16_t destPort)
{
	udpTransferCtx_t *p = &ctx;

	p->destPort = destPort;
}

/**
 * @brief Set the destination ip
 *
 * @param ip1 IP byte 1
 * @param ip2 IP byte 2
 * @param ip3 IP byte 3
 * @param ip4 IP byte 4
 */
void udpTransferSetDestIp(const uint8_t ip1, const uint8_t ip2, const uint8_t ip3, const uint8_t ip4)
{
	udpTransferCtx_t *p = &ctx;

	IP4_ADDR(&p->destAddr, ip1, ip2, ip3, ip4);
}

/**
 * @brief Init this module
 *
 * Call this function before using the module
 *
 * @retval UDP_TRANSPORT_RESULT_ERROR_INIT_FAILED Init failed, udp socket initialization failed
 * @retval UDP_TRANSPORT_RESULT_OK Init successfully done
 * @return result of the initialization
 */
udpTransportResult_t udpTransferInit(void)
{
	udpTransferCtx_t *p = &ctx;

	p->udp_pcb = udp_new();

	if (p->udp_pcb == NULL)
	{
		return UDP_TRANSPORT_RESULT_ERROR_INIT_FAILED;
	}/* Failed to get the udp pcb, exit --------------------------->*/

	p->busy = false;
	p->destAddr.addr = 0;
	p->destPort = 0;

	return UDP_TRANSPORT_RESULT_OK;
}

/** @} */

