/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef TCPTRACECLIENT_H
#define TCPTRACECLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QString>

class TcpTraceClient: public QObject
{
  Q_OBJECT

  public:
    TcpTraceClient();
    ~TcpTraceClient();
    void connectToServer(const QString destIp, const unsigned int destPort);
    void close();

  signals:
    void traceReceived(const QString text);

  private slots:
    void readTcpData();

  private:
     QTcpSocket *tcpSocket;
};

#endif // TCPTRACECLIENT_H
