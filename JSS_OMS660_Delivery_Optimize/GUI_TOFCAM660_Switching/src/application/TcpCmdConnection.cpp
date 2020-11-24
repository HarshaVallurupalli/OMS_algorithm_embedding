/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "TcpCmdConnection.h"
#include <QtCore>
#include <QTimer>
#include "CommunicationConstants.h"

#define MARKING_START 0xFFFFAA55                                   ///<Start marking, at the start of the data
#define MARKING_END   0xFFFF55AA                                   ///<End marking, at the end of the data
#define HEADER_SIZE            8                                   ///<[Bytes] size of the header
#define END_MARKING_SIZE       4                                   ///<[Bytes] Size of the end marking
#define PROTOCOL_OVERHEAD_SIZE (HEADER_SIZE + END_MARKING_SIZE)    ///<[Bytes] Total overhead of the header
#define PAYLOAD_SIZE_INDEX     4                                   ///<Index of the payload size in the header

TcpCmdConnection::TcpCmdConnection(QObject *parent __attribute__((unused)))
{

}

void TcpCmdConnection::startRunning()
{
  state = STATE_UNCONNECTED;
  blockingCommandBusy = false;

  tcpSocket = new QTcpSocket();
  tcpSocket->setSocketOption(QAbstractSocket::LowDelayOption, 1);
  tcpSocket->setSocketOption(QAbstractSocket:: KeepAliveOption, 1);
  connect(tcpSocket, SIGNAL(readyRead()), SLOT(readTcpData()) );
  connect(tcpSocket, SIGNAL(connected()), SLOT(TcpConnected()) );
  connect(tcpSocket, SIGNAL(disconnected()), SLOT(TcpDisconnected()));
  connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), SLOT(error(QAbstractSocket::SocketError)));
  connect(this, SIGNAL(checkData()), SLOT(checkToSendData()));

  timeoutTimer = new QTimer(nullptr);
  connect(timeoutTimer, SIGNAL(timeout()), this, SLOT(timeout()));
  timeoutTimer->start(TIMER_INTERVAL);

  emit checkToSendData();
}

void TcpCmdConnection::stopRunning()
{
  tcpSocket->close();
}

TcpCmdConnection::~TcpCmdConnection()
{

}

void TcpCmdConnection::close()
{
  tcpSocket->close();
}

bool TcpCmdConnection::setConnectionParameters(QString ip, uint16_t port)
{
  destPort = port;
  destIp = ip;

  return true;
}

void TcpCmdConnection::sendCommand(QByteArray dataToSend)
{
  queue.enqueue(dataToSend);
  emit checkData();
}

bool TcpCmdConnection::sendCommandBlocking(QByteArray dataToSend, QByteArray &receivedData, const uint8_t answerType)
{
  queue.enqueue(dataToSend);

  //Block here until an answer is received
  mutex.lock();
  blockingCommandBusy = true;
  emit checkData();
  blockingCommandCondition.wait(&mutex);
  receivedData = blockingCommandReceiverData;
  mutex.unlock();

  //Check on answer type.
  if ((receivedData.length() > 0) && (static_cast<uint8_t>(receivedData.at(CommunicationConstants::AnswerType::INDEX)) == answerType))
  {
    return true;
  }

  return false;
}

int TcpCmdConnection::output(QTcpSocket &socket, QByteArray dataToSend)
{
  QByteArray output = dataToSend;
  output.insert(0, static_cast<char>((MARKING_START >> 24) & 0xFF));
  output.insert(1, static_cast<char>((MARKING_START >> 16) & 0xFF));
  output.insert(2, static_cast<char>((MARKING_START >> 8) & 0xFF));
  output.insert(3, static_cast<char>((MARKING_START >> 0) & 0xFF));

  uint32_t payloadSize = dataToSend.length();
  output.insert(4, static_cast<char>((payloadSize >> 24) & 0xFF));
  output.insert(5, static_cast<char>((payloadSize >> 16) & 0xFF));
  output.insert(6, static_cast<char>((payloadSize >> 8) & 0xFF));
  output.insert(7, static_cast<char>((payloadSize >> 0) & 0xFF));

  output.append(static_cast<char>((MARKING_END >> 24) & 0xFF));
  output.append(static_cast<char>((MARKING_END >> 16) & 0xFF));
  output.append(static_cast<char>((MARKING_END >> 8) & 0xFF));
  output.append(static_cast<char>((MARKING_END >> 0) & 0xFF));

  return socket.write(output);
}


bool TcpCmdConnection::hasValidStartMarking(QByteArray data)
{
  bool isValidMarking = ( (data.at(0) == static_cast<int8_t>(MARKING_START >> 24)) ||
                          (data.at(1) == static_cast<int8_t>(MARKING_START >> 16)) ||
                          (data.at(2) == static_cast<int8_t>(MARKING_START >> 8)) ||
                          (data.at(3) == static_cast<int8_t>(MARKING_START >> 0)) );

  return isValidMarking;
}

bool TcpCmdConnection::hasValidEndMarking(QByteArray data)
{
  bool isValidMarking = ( (data.at(data.length()-4) == static_cast<int8_t>(MARKING_END >> 24)) ||
                          (data.at(data.length()-3) == static_cast<int8_t>(MARKING_END >> 16)) ||
                          (data.at(data.length()-2) == static_cast<int8_t>(MARKING_END >> 8)) ||
                          (data.at(data.length()-1) == static_cast<int8_t>(MARKING_END >> 0)) );

  return isValidMarking;
}

bool TcpCmdConnection::lengthIsCorrect(QByteArray data)
{
  int32_t expectedPayloadBytes = (data.at(PAYLOAD_SIZE_INDEX) << 24) + (data.at(PAYLOAD_SIZE_INDEX+1) << 16) + (data.at(PAYLOAD_SIZE_INDEX+2) << 8) + (data.at(PAYLOAD_SIZE_INDEX+3) << 0);

  if ((data.length() -  PROTOCOL_OVERHEAD_SIZE) == expectedPayloadBytes)
  {
    return true;
  }
  else
  {
    return false;
  }
}


bool TcpCmdConnection::isValidData(QByteArray data)
{
  if (data.length() < HEADER_SIZE)
  {
    return false;
  }

  if (hasValidStartMarking(data) == false)
  {
    return false;
  }

  if (hasValidEndMarking(data) == false)
  {
    return false;
  }

  if (lengthIsCorrect(data) == false)
  {
    return false;
  }

  return true;
}

void TcpCmdConnection::readTcpData()
{
  switch(state)
  {
    case STATE_WAIT_ACK:
      receiverData.append(tcpSocket->readAll());

      if (isValidData(receiverData))
      {
        receiverData.remove(0, HEADER_SIZE);
        mutex.lock();
        if (blockingCommandBusy)
        {
          blockingCommandReceiverData = receiverData;
          blockingCommandBusy = false;
          blockingCommandCondition.wakeAll();
          qDebug() << "got blocking data";
        }
        else
        {
          emit receivedAnswer(receiverData);          
        }
        mutex.unlock();
        state = STATE_CONNECTED;
        receiverData.clear();
        emit checkData();        
      }      
      break;
    default:
      state = STATE_CLOSING;
      tcpSocket->close();
      break;
  }
}

void TcpCmdConnection::TcpConnected()
{
  if (state == STATE_CONNECTING)
  {
    qDebug() << "connected";
    emit connected();    
    state = STATE_CONNECTED;
  }
  else
  {
    tcpSocket->close();
    state = STATE_CLOSING;
  }
}

void TcpCmdConnection::TcpDisconnected()
{
  qDebug() << "disconnected";
  emit disconnected();
  state = STATE_UNCONNECTED;
  emit checkData();
}

void TcpCmdConnection::error(QAbstractSocket::SocketError error __attribute__((unused)))
{
  if (tcpSocket->isOpen())
  {
    tcpSocket->close();
  }
  tcpSocket->abort();
  state = STATE_UNCONNECTED;

  emit checkData();
}

void TcpCmdConnection::timeout()
{
  switch(state)
  {
    case STATE_UNCONNECTED:
      emit checkToSendData();
      break;
    case STATE_WAIT_ACK:
      //No ACK received, close the connection
      state = STATE_CLOSING;
      tcpSocket->close();
      break;
    case STATE_CONNECTED:
      if (tcpSocket->isOpen() == false)
      {
        tcpSocket->abort();
        state = STATE_UNCONNECTED;
      }
      else
      {
        emit checkToSendData();
      }
      break;
    case STATE_CLOSING:
      state = STATE_UNCONNECTED;
      break;
    case STATE_CONNECTING:
      if (tcpSocket->isOpen())
      {
        tcpSocket->close();
      }
      tcpSocket->abort();
      state = STATE_UNCONNECTED;
      break;
   }
}

void TcpCmdConnection::checkToSendData()
{
  switch(state)
  {
    case STATE_UNCONNECTED:
      state = STATE_CONNECTING;      
      tcpSocket->connectToHost(destIp, destPort);
      break;
    case STATE_WAIT_ACK:      
      break;
    case STATE_CONNECTED:
      if(queue.isEmpty() == false)
      {
       timeoutTimer->start(TIMER_INTERVAL);
       QByteArray data = queue.dequeue();
       output(*tcpSocket, data);
       state = STATE_WAIT_ACK;
      }
      break;
    case STATE_CLOSING:

      break;
    case STATE_CONNECTING:

      break;
  }
}
