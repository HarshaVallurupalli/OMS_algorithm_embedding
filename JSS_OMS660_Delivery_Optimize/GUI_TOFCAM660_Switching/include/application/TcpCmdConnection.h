/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef TCP_CMD_CONNECTION_H
#define TCP_CMD_CONNECTION_H

#include "CmdConnection.h"
#include <QTcpSocket>
#include <QTimer>
#include <QSemaphore>
#include <QQueue>
#include <QThread>
#include <QMutex>
#include <QWaitCondition>

class TcpCmdConnection: public CmdConnection
{
  Q_OBJECT
    
  enum State
  {
    STATE_CONNECTING,
    STATE_UNCONNECTED,
    STATE_CONNECTED,
    STATE_CLOSING,
    STATE_WAIT_ACK
  };

  public:
    TcpCmdConnection(QObject *parent = nullptr);
    ~TcpCmdConnection();
    bool setConnectionParameters(QString ip, uint16_t port);
    void sendCommand(QByteArray dataToSend);
    bool sendCommandBlocking(QByteArray dataToSend, QByteArray &receivedData, const uint8_t answerType);
    void close();

  public slots:
    void startRunning();
    void stopRunning();

  private slots:
    void readTcpData();
    void TcpConnected();
    void TcpDisconnected();
    void timeout();
    void checkToSendData();
    void error(QAbstractSocket::SocketError error);

  signals:
    void checkData();

  private:
    const int TIMER_INTERVAL = 3000;

    bool isValidData(QByteArray data);
    bool hasValidStartMarking(QByteArray data);
    bool hasValidEndMarking(QByteArray data);
    bool lengthIsCorrect(QByteArray data);
    int output(QTcpSocket &socket, QByteArray dataToSend);

    QByteArray receiverData;
    QByteArray blockingCommandReceiverData;
    QQueue<QByteArray> queue;
    QTcpSocket *tcpSocket;
    QString destIp;
    uint16_t destPort;  
    State state;
    QTimer *timeoutTimer;
    QWaitCondition blockingCommandCondition;
    QMutex mutex;
    bool blockingCommandBusy;
};


#endif // TCP_CMD_CONNECTION_H
