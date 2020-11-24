/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "UdpDataConnection.h"

#define PACKET_HEADER_SIZE          20

UdpDataConnection::UdpDataConnection(QObject *parent __attribute__((unused)))
{
  socket = nullptr;
  actualNumber = 0xFFFF;
  receivedBytes = 0;
}

UdpDataConnection::~UdpDataConnection()
{

}

void UdpDataConnection::setPort(const uint16_t port)
{
  this->port = port;
}

void UdpDataConnection::startRunning()
{
  socket = new QUdpSocket(this);

  socket->bind(QHostAddress::AnyIPv4, port);

  connect(socket, SIGNAL(readyRead()), this, SLOT(processPendingDatagrams()));
}

void UdpDataConnection::stopRunning()
{
  if (socket != nullptr)
  {
    socket->close();
  }
}

uint16_t UdpDataConnection::getHeaderUint16(QByteArray data, const int offset)
{
  uint16_t value0 = data.at(offset) & 0xFF;
  uint16_t value1 = data.at(offset + 1) & 0xFF;

  uint16_t value = (value0 << 8) | value1;

  return value;
}

uint32_t UdpDataConnection::getHeaderUint32(QByteArray data, const int offset)
{
  uint32_t value0 = data.at(offset) & 0xFF;
  uint32_t value1 = data.at(offset + 1) & 0xFF;
  uint32_t value2 = data.at(offset + 2) & 0xFF;
  uint32_t value3 = data.at(offset + 3) & 0xFF;

  uint32_t value = (value0 << 24) | (value1 << 16) | (value2 << 8) | value3;

  return value;
}

uint16_t UdpDataConnection::getHeaderUint16(char *pData, const int offset)
{
  uint16_t value0 = (unsigned char)(pData[offset]) & 0xFF;
  uint16_t value1 = (unsigned char)(pData[offset+1]) & 0xFF;

  uint16_t value = (value0 << 8) | value1;

  return value;
}

uint32_t UdpDataConnection::getHeaderUint32(char *pData, const int offset)
{
  uint32_t value0 = (unsigned char)(pData[offset]) & 0xFF;
  uint32_t value1 = (unsigned char)(pData[offset+1]) & 0xFF;
  uint32_t value2 = (unsigned char)(pData[offset+2]) & 0xFF;
  uint32_t value3 = (unsigned char)(pData[offset+3]) & 0xFF;

  uint32_t value = (value0 << 24) | (value1 << 16) | (value2 << 8) | value3;

  return value;
}

void UdpDataConnection::processPendingDatagrams()
{
  //Temporary buffer with enough size for one packet
  char tempBuffer[2000]; 
  while (socket->hasPendingDatagrams())
  {
    socket->readDatagram(tempBuffer, sizeof(tempBuffer));

    uint16_t number = getHeaderUint16(tempBuffer, 0);   
    uint32_t totalSize = getHeaderUint32(tempBuffer, 2);
    uint16_t payloadSize = getHeaderUint16(tempBuffer, 6);
    uint32_t offset = getHeaderUint32(tempBuffer, 8);
    uint32_t numPacket = getHeaderUint32(tempBuffer, 12);
    uint32_t packetNumber = getHeaderUint32(tempBuffer, 16);

    //A new data number is received, so clear anything
    if (number != actualNumber)
    {
      actualNumber = number;
      receivedBytes = 0;      
    }

    //Store the received frame at the required offset
    memcpy(&rxBuffer[offset], &tempBuffer[PACKET_HEADER_SIZE], payloadSize);
    receivedBytes += payloadSize;

    //If the last packet is received, the whole data
    if (packetNumber == (numPacket - 1))
    {
      bool complete = false;
      if (receivedBytes >= totalSize)
      {
        complete = true;
      }
      emit receivedData(rxBuffer, receivedBytes, complete);
    }
  }
}
