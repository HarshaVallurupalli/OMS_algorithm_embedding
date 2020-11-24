/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "TcpTraceClient.h"

TcpTraceClient::TcpTraceClient()
{
  tcpSocket = new QTcpSocket();
  tcpSocket->setSocketOption(QAbstractSocket::LowDelayOption, 1);
  tcpSocket->setSocketOption(QAbstractSocket:: KeepAliveOption, 1);
  connect(tcpSocket, SIGNAL(readyRead()), SLOT(readTcpData()) );
}

TcpTraceClient::~TcpTraceClient()
{
  tcpSocket->close();
  delete tcpSocket;
}

void TcpTraceClient::connectToServer(const QString destIp, const unsigned int destPort)
{
  if (tcpSocket->isOpen() == false)
  {
    tcpSocket->connectToHost(destIp, destPort);
  }
}

void TcpTraceClient::close()
{

}

void TcpTraceClient::readTcpData()
{
  QString text = QString(tcpSocket->readAll());
  emit traceReceived(text);
}
