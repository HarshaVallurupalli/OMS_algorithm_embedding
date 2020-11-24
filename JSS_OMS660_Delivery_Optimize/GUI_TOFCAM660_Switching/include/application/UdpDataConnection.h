/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef UDP_DATA_CONNECTION_H
#define UDP_DATA_CONNECTION_H

#include <QObject>
#include <QUdpSocket>
#include <QThread>
#include "DataConnection.h"

class UdpDataConnection: public DataConnection
{
  Q_OBJECT

  public:
    UdpDataConnection(QObject *parent = nullptr);
    ~UdpDataConnection();
    void setPort(const uint16_t port);

  public slots:
    void startRunning();
    void stopRunning();

  private slots:
    void processPendingDatagrams();

  private:
    uint16_t getHeaderUint16(QByteArray data, const int offset);
    uint32_t getHeaderUint32(QByteArray data, const int offset);
    uint16_t getHeaderUint16(char *pData, const int offset);
    uint32_t getHeaderUint32(char *pData, const int offset);

    uint16_t port;
    QUdpSocket *socket = nullptr;   
    uint16_t actualNumber;
    unsigned int receivedBytes;
    char rxBuffer[10000000];
};

#endif // UDP_DATA_CONNECTION_H
