/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "Interface.h"
#include "TcpCmdConnection.h"
#include "UdpDataConnection.h"
#include "CommunicationConstants.h"
#include "DataHeader.h"
#include <QByteArray>
#include <QDebug>
#include <QtCore>

//Destination IP address
static const QString DEFAULT_DEST_IP = "10.10.31.180";

//Port for the commands
static const unsigned int COMMAND_PORT = 50660;

//Port for the trace
static const unsigned int TRACE_PORT = 50661;


Interface::Interface(QObject *parent  __attribute__((unused)))
{
  numMeasurements = 0;
  waitAck = false;
  destIp = DEFAULT_DEST_IP;

  udpThread = new InterfaceThread();
  tcpThread = new InterfaceThread();
  timerThread = new InterfaceThread();

  dataConnection = new UdpDataConnection(this);
  connect(dataConnection, &DataConnection::receivedData, this, &Interface::receivedData);
  dataConnection->setPort(45454);

  cmdConnection = new TcpCmdConnection();
  cmdConnection->setConnectionParameters(destIp, COMMAND_PORT);
  connect(cmdConnection, &TcpCmdConnection::receivedAnswer, this, &Interface::receivedAnswer);
  connect(cmdConnection, &TcpCmdConnection::connected, this, &Interface::cmdConnectionConnected);
  connect(cmdConnection, &TcpCmdConnection::disconnected, this, &Interface::cmdConnectionDisconnected);

  cmdConnection->moveToThread(tcpThread);
  cmdConnection->connect(tcpThread, &QThread::started, cmdConnection, &CmdConnection::startRunning);
  cmdConnection->connect(tcpThread, &QThread::finished, cmdConnection, &CmdConnection::stopRunning);
  //tcpThread->start();

  dataConnection->moveToThread(udpThread);  
  dataConnection->connect(udpThread, &QThread::started, dataConnection, &DataConnection::startRunning);
  dataConnection->connect(udpThread, &QThread::finished, dataConnection, &DataConnection::stopRunning);
  //udpThread->start();

  traceConntection = new TcpTraceClient();
  connect(traceConntection, &TcpTraceClient::traceReceived, this, &Interface::onTraceReceived);

  fpsTimer = new QTimer(nullptr); //Parent must be null
  fpsTimer->setInterval(1000);
  fpsTimer->start();
  fpsTimer->moveToThread(timerThread);
  connect(fpsTimer, SIGNAL(timeout()), this, SLOT(onUpdateFps()));
  timerThread->start();
}

Interface::~Interface()
{
  close();
  delete cmdConnection;
  delete dataConnection;
  delete traceConntection;
  delete udpThread;
}

void Interface::connectToDevice(const QString destIp)
{
  this->destIp = destIp;
  cmdConnection->setConnectionParameters(destIp, COMMAND_PORT);
  tcpThread->start();
  udpThread->start();
}

void Interface::close()
{
  stopStream();
  udpThread->stopRunning();
  tcpThread->stopRunning();
  timerThread->stopRunning();

  waitAck = true;
  QTimer timer;
  timer.setSingleShot(true);
  timer.start(1000);

  while(waitAck && (timer.isActive()))
  {
    QCoreApplication::processEvents();
  }
  cmdConnection->close();
}

void Interface::insertValue(QByteArray &output, const int8_t value){
    output.append(value);
}

void Interface::insertValue(QByteArray &output, const uint16_t value)
{
  output.append(static_cast<int8_t>(value >> 8));
  output.append(static_cast<int8_t>(value & 0xFF));
}

void Interface::insertValue(QByteArray &output, const int16_t value)
{
  output.append(value >> 8);
  output.append(static_cast<int8_t>(value & 0xFF));
}

unsigned int Interface::getUint16Value(const QByteArray &array, const unsigned int index)
{
  int indexToUse = static_cast<int>(index);

  unsigned int value = ((static_cast<unsigned int>(array.at(indexToUse + 0)) << 8) |
                        (static_cast<unsigned int>(array.at(indexToUse + 1)) & 0xFF));

  return value;
}

unsigned int Interface::getUint32Value(const QByteArray &array, const unsigned int index)
{
  int indexToUse = static_cast<int>(index);

  unsigned int value = ((static_cast<unsigned int>(array.at(indexToUse)) << 24) |
                        (static_cast<unsigned int>(array.at(indexToUse + 1)) << 16) |
                        (static_cast<unsigned int>(array.at(indexToUse + 2)) << 8) |
                        (static_cast<unsigned int>(array.at(indexToUse + 3)) & 0xFF));

  return value;
}

int Interface::getInt16Value(const QByteArray &array, const unsigned int index)
{
  int indexToUse = static_cast<int>(index);

  unsigned int value = ((static_cast<unsigned int>(array.at(indexToUse + 0)) << 8) |
                        (static_cast<unsigned int>(array.at(indexToUse + 1)) & 0xFF));


  int16_t signedValue = static_cast<int16_t>(value);

  return signedValue;
}

uint8_t Interface::boolToUint8(const bool value)
{
  if (value)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int8_t Interface::boolToInt8(const bool value)
{
  if (value)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}


void Interface::sendCommand(QByteArray &dataToSend, const QByteArray &userData)
{
  //If present, add user data
  if (userData != nullptr)
  {
    dataToSend.append(userData);
  }  

  cmdConnection->sendCommand(dataToSend);
}

bool Interface::sendCommandBlocking(QByteArray &dataToSend, QByteArray &receivedData, const uint8_t answerType)
{
  return cmdConnection->sendCommandBlocking(dataToSend, receivedData, answerType);
}

void Interface::requestDistanceAmplitude(const bool doStream, const QByteArray &userData)
{
  QByteArray outputData;

  uint16_t command = CommunicationConstants::CommandList::COMMAND_GET_DISTANCE_AMPLITUDE;
  uint8_t stream = boolToUint8(doStream);

  //Insert the 16Bit command
  insertValue(outputData, command);

  //Insert the stream flag
  outputData.insert(2, stream);  

  sendCommand(outputData, userData);
}

void Interface::requestDistance(const bool doStream, const QByteArray &userData)
{
  QByteArray outputData;

  uint16_t command = CommunicationConstants::CommandList::COMMAND_GET_DISTANCE;
  uint8_t stream = boolToUint8(doStream);

  //Insert the 16Bit command
  insertValue(outputData, command);

  //Insert the stream flag
  outputData.insert(2, stream);

  sendCommand(outputData, userData);
}

void Interface::requestGrayscale(const bool doStream, const QByteArray &userData)
{
  QByteArray outputData;

  uint16_t command = CommunicationConstants::CommandList::COMMAND_GET_GRAYSCALE;
  uint8_t stream = boolToUint8(doStream);

  //Insert the 16Bit command
  insertValue(outputData, command);

  //Insert the stream flag
  outputData.insert(2, stream);

  sendCommand(outputData, userData);
}

void Interface::requestMovementDetection(const bool doStream, const QByteArray &userData)
{
  QByteArray outputData;

  uint16_t command = CommunicationConstants::CommandList::COMMAND_SET_ALGORITHM;
  uint8_t stream = boolToUint8(doStream);
  uint16_t WindowSize=4;
  //Insert the 16Bit command
  insertValue(outputData, command);
  insertValue(outputData,WindowSize);

  //Insert the stream flag
  outputData.insert(2, stream);

  sendCommand(outputData, userData);
}
void Interface::requestCam1_Data(const bool doStream, const QByteArray &userData)//EDIT
{
  QByteArray outputData;

  uint16_t command = CommunicationConstants::CommandList::COMMAND_GET_CAM1_DATA;
  uint8_t stream = boolToUint8(doStream);

  //Insert the 16Bit command
  insertValue(outputData, command);

  //Insert the stream flag
  outputData.insert(2, stream);

  sendCommand(outputData, userData);
}
void Interface::requestCam2_Data(const bool doStream, const QByteArray &userData)
{
  QByteArray outputData;

  uint16_t command = CommunicationConstants::CommandList::COMMAND_GET_CAM2_DATA;
  uint8_t stream = boolToUint8(doStream);

  //Insert the 16Bit command
  insertValue(outputData, command);

  //Insert the stream flag
  outputData.insert(2, stream);

  sendCommand(outputData, userData);
}
void Interface::requestCam3_Data(const bool doStream, const QByteArray &userData)
{
  QByteArray outputData;

  uint16_t command = CommunicationConstants::CommandList::COMMAND_GET_CAM3_DATA;
  uint8_t stream = boolToUint8(doStream);

  //Insert the 16Bit command
  insertValue(outputData, command);

  //Insert the stream flag
  outputData.insert(2, stream);

  sendCommand(outputData, userData);
}
void Interface::requestCam4_Data(const bool doStream, const QByteArray &userData)
{
  QByteArray outputData;

  uint16_t command = CommunicationConstants::CommandList::COMMAND_GET_CAM4_DATA;
  uint8_t stream = boolToUint8(doStream);

  //Insert the 16Bit command
  insertValue(outputData, command);

  //Insert the stream flag
  outputData.insert(2, stream);

  sendCommand(outputData, userData);
}
void Interface::request_Data_TCP_IP(const bool doStream, const QByteArray &userData)
{
  QByteArray outputData;

  uint16_t command = CommunicationConstants::CommandList::COMMAND_STREAM_USING_TCP_IP;
  uint8_t stream = boolToUint8(doStream);

  //Insert the 16Bit command
  insertValue(outputData, command);

  //Insert the stream flag
  outputData.insert(2, stream);

  sendCommand(outputData, userData);
}
void Interface::request_Data_UDP_IP(const bool doStream, const QByteArray &userData)
{
  QByteArray outputData;

  uint16_t command = CommunicationConstants::CommandList::COMMAND_STREAM_USING_UDP_IP;
  uint8_t stream = boolToUint8(doStream);

  //Insert the 16Bit command
  insertValue(outputData, command);

  //Insert the stream flag
  outputData.insert(2, stream);

  sendCommand(outputData, userData);
}
void Interface::setIntegrationTimes(const uint16_t integrationTime3d[3], const uint16_t integrationTimeGrayscale, const QByteArray &userData)
{
  QByteArray outputData;

  uint16_t command = CommunicationConstants::CommandList::COMMAND_SET_INT_TIMES;

  //Insert the 16Bit command
  insertValue(outputData, command);

  //Insert the 3 integration times for 3D
  for (int i = 0; i < 3; i++)
  {
    insertValue(outputData, integrationTime3d[i]);   
  }

  //Insert the integration time for grayscale
  insertValue(outputData, integrationTimeGrayscale);

  sendCommand(outputData, userData);
}

void Interface::setOffset(const int16_t offset, const QByteArray &userData)
{
  QByteArray outputData;

  uint16_t command = CommunicationConstants::CommandList::COMMAND_SET_OFFSET;

  //Insert the 16Bit command
  insertValue(outputData, command);

  //Insert the offset
  insertValue(outputData, offset);

  sendCommand(outputData, userData);
}

void Interface::setMinAmplitude(const uint16_t minAmplitude, const QByteArray &userData)
{
  QByteArray outputData;

  uint16_t command = CommunicationConstants::CommandList::COMMAND_SET_MIN_AMPLITUDE;

  //Insert the 16Bit command
  insertValue(outputData, command);

  //Insert the min Amplitude
  insertValue(outputData, minAmplitude);

  sendCommand(outputData, userData);
}

void Interface::setFilter(const bool medianFilter, const bool averageFilter, const uint16_t temporalFactor, const uint16_t temporalThreshold, const uint16_t edgeThreshold, const uint16_t temporalEdgeThresholdLow, const uint16_t temporalEdgeThresholdHigh, const uint16_t interferenceDetectionLimit, const bool interferenceDetectionUseLastValue, const QByteArray &userData)
{

    QByteArray outputData;

    uint16_t command = CommunicationConstants::CommandList::COMMAND_SET_FILTER;

    //Insert the 16Bit command
    insertValue(outputData, command);

    //Insert temporal filter factor
    insertValue(outputData, temporalFactor);

    //Insert temporal filter threshold
    insertValue(outputData, temporalThreshold);

    //Insert median filter
    insertValue(outputData, boolToInt8(medianFilter));

    //Insert average filter
    insertValue(outputData, boolToInt8(averageFilter));

    //Insert edge filter threshold
    insertValue(outputData, edgeThreshold);

    //Insert interference detection use last value flag
    insertValue(outputData, boolToInt8(interferenceDetectionUseLastValue));

    //Insert edge filter interference detection limit
    insertValue(outputData, interferenceDetectionLimit);

    //Insert edge filter threshold low
    insertValue(outputData, temporalEdgeThresholdLow);

    //Insert edge filter threshold high
    insertValue(outputData, temporalEdgeThresholdHigh);

    sendCommand(outputData, userData);
}

void Interface::setAlgorithm(const bool SkeletonDetectionAlgorithm, const uint16_t MDAWindowSize, const uint16_t MDAImageType, const QByteArray &userData)

{

    QByteArray outputData;

    uint16_t command = CommunicationConstants::CommandList::COMMAND_SET_ALGORITHM;

    //Insert the 16Bit command
    insertValue(outputData, command);

    //Insert Skeleton Detection Algorithm
    insertValue(outputData, boolToInt8(SkeletonDetectionAlgorithm));

    //Insert Movement Detection Algorithm Window Size
    insertValue(outputData, MDAWindowSize);

    //Insert Movement Detection Algorithm Image Type
    insertValue(outputData, MDAImageType);

    sendCommand(outputData, userData);
}
void Interface::setBinning(const bool vertical, const bool horizontal)
{
    QByteArray outputData;
    uint16_t command = CommunicationConstants::CommandList::COMMAND_SET_BINNING;

    //Insert the 16Bit command
    insertValue(outputData, command);

    int8_t  byte = 0;
    if(vertical && horizontal){
        byte = 3;
    }else if(vertical){
        byte = 1;
    }else if(horizontal){
        byte = 2;
    }

    outputData.append(byte);
    sendCommand(outputData, nullptr);
}

void Interface::setRoi(const uint16_t x0, const uint16_t y0, const uint16_t x1, const uint16_t y1)
{
    QByteArray outputData;
    uint16_t command = CommunicationConstants::CommandList::COMMAND_SET_ROI;

    insertValue(outputData, command);
    insertValue(outputData, x0);
    insertValue(outputData, y0);
    insertValue(outputData, x1);
    insertValue(outputData, y1); 
    sendCommand(outputData, nullptr);
}

void Interface::setModulation(const uint8_t index, const uint8_t channel, const QByteArray &userData){

    QByteArray outputData;

    uint16_t command = CommunicationConstants::CommandList::COMMAND_SET_MODULATION;

    //Insert the 16Bit command
    insertValue(outputData, command);

    char data = static_cast<char>(index);
    outputData.append(data);

    data = static_cast<char>(channel);
    outputData.append(data);

    data = 0; //AutoChannel reserved
    outputData.append(data);

    sendCommand(outputData, userData);
}


void Interface::stopStream(const QByteArray &userData)
{
  QByteArray outputData;

  uint16_t command = CommunicationConstants::CommandList::COMMAND_STOP_STREAM;

  //Insert the 16Bit command
  insertValue(outputData, command);

  sendCommand(outputData, userData);
}

void Interface::calibrate(const bool verifyOnly, const bool offsetOnly, const uint8_t calibrationIndex, const QByteArray &userData)
{
  QByteArray outputData;

  uint16_t command = CommunicationConstants::CommandList::COMMAND_CALIBRATE;

  //Insert the 16Bit command
  insertValue(outputData, command);

  uint8_t verifyOnlyByte = boolToUint8(verifyOnly);

  //Insert the stream flag
  outputData.insert(2, verifyOnlyByte);

  uint8_t offsetOnlyByte = boolToUint8(offsetOnly);

  //Insert offset only byte
  outputData.insert(3, offsetOnlyByte);

  //Insert calibration index byte
  outputData.insert(4, calibrationIndex);

  sendCommand(outputData, userData);
}

void Interface::calibrateProduction(const QByteArray &userData)
{
  QByteArray outputData;

  uint16_t command = CommunicationConstants::CommandList::COMMAND_CALIBRATE_PRODUCTION;

  //Insert the 16Bit command
  insertValue(outputData, command);

  sendCommand(outputData, userData);
}

void Interface::sendDebugCommand(const uint16_t command, const QByteArray payload)
{
  QByteArray outputData;

  //Insert the 16Bit command
  insertValue(outputData, command);

  outputData.append(payload);

  qDebug() << "SendDebugCommand, command = " << command << "data = " << payload;

  sendCommand(outputData, nullptr);
}

void Interface::setDataIPaddress(const QString &ipAddress, const QByteArray &userData)
{
    QByteArray outputData;

    uint16_t command = CommunicationConstants::CommandList::COMMAND_SET_DATA_IP_ADDRESS;
    insertValue(outputData, command);

    quint32 addr = QHostAddress(ipAddress).toIPv4Address();        
    outputData.append(static_cast<int8_t>((addr>>24) & 0xFF));
    outputData.append(static_cast<int8_t>((addr>>16) & 0xFF));
    outputData.append(static_cast<int8_t>((addr>>8) & 0xFF));
    outputData.append(static_cast<int8_t>( addr & 0xFF));

    sendCommand(outputData, userData);
}


void Interface::getFirmwareRelease()
{
    QByteArray outputData;
    uint16_t command = CommunicationConstants::CommandList::COMMAND_GET_FIRMWARE_RELEASE;

    //Insert the 16Bit command
    insertValue(outputData, command);
    sendCommand(outputData, nullptr);
}

void Interface::getChipInformation(){
    QByteArray outputData;
    uint16_t command = CommunicationConstants::CommandList::COMMAND_GET_CHIP_INFORMATION;

    //Insert the 16Bit command
    insertValue(outputData, command);
    sendCommand(outputData, nullptr);
}


Interface::Status_e Interface::getFirmwareRelease(unsigned int &major, unsigned int &minor)
{
  QByteArray outputData;
  QByteArray inputData; 

  uint16_t command = CommunicationConstants::CommandList::COMMAND_GET_FIRMWARE_RELEASE;

  //Insert the 16Bit command
  insertValue(outputData, command);

  bool success = sendCommandBlocking(outputData, inputData, CommunicationConstants::AnswerType::ANSWER_FIRMWARE_RELEASE);

  //Extract the data here
  if (success)
  {
    uint32_t firmwareRelease = getUint32Value(inputData, CommunicationConstants::AnswerData::FirmwareRelease::INDEX);

    major = firmwareRelease >> 16;
    minor = firmwareRelease & 0xFF;
    qDebug() << "Received Firmware major = " << major << "minor = " << minor;
    return Interface::Status_e::STATUS_OK;
  }

  return Interface::Status_e::STATUS_NO_ANSWER;
}

Interface::Status_e Interface::getChipInformation(uint16_t &chipId, uint16_t &waferId)
{
  QByteArray outputData;
  QByteArray inputData;

  uint16_t command = CommunicationConstants::CommandList::COMMAND_GET_CHIP_INFORMATION;

  //Insert the 16Bit command
  insertValue(outputData, command);

  bool success = sendCommandBlocking(outputData, inputData, CommunicationConstants::AnswerType::ANSWER_CHIP_INFORMATION);

  //Extract the data here
  if (success)
  {
    chipId = static_cast<uint16_t>(getUint16Value(inputData, CommunicationConstants::AnswerData::ChipInformation::INDEX_CHIP_ID));
    waferId = static_cast<uint16_t>(getUint16Value(inputData, CommunicationConstants::AnswerData::ChipInformation::INDEX_WAFER_ID));
    qDebug() << "Received Chip Information chipId = " << chipId << "waferId = " << waferId;
    return Interface::Status_e::STATUS_OK;
  }

  return Interface::Status_e::STATUS_NO_ANSWER;
}

void Interface::receivedAnswer(QByteArray data)
{
  uint8_t answer = data.at(CommunicationConstants::AnswerType::INDEX);
  switch(answer)
  {
    case CommunicationConstants::AnswerType::ANSWER_ACK:
      emit receivedAck();
      waitAck = false;
      break;
    case CommunicationConstants::AnswerType::ANSWER_ERROR:
      {
        uint8_t errorNumber = (data.at(1) << 8) | data.at(2);
        emit receivedError(errorNumber);
        waitAck = false;        
        qDebug() << "Received Error: " << errorNumber;
      }
      break;
    case CommunicationConstants::AnswerType::ANSWER_FIRMWARE_RELEASE:
      {
        int major = (data.at(1) << 8) | data.at(2);
        int minor = (data.at(3) << 8) | data.at(4);
        emit receivedFirmwareRelease(major, minor);
        waitAck = false;
        qDebug() << "Received Firmware release: " << major << minor;
      }
      break;
    case CommunicationConstants::AnswerType::ANSWER_CHIP_INFORMATION:
      {      
        int chipID = static_cast<int>(getUint16Value(data, CommunicationConstants::AnswerData::ChipInformation::INDEX_CHIP_ID));
        int waferID = static_cast<int>(getUint16Value(data, CommunicationConstants::AnswerData::ChipInformation::INDEX_WAFER_ID));
        emit receivedChipInfo(waferID, chipID);
        waitAck = false;
        qDebug() << "Received Chip information: " << chipID << waferID;
      }
      break;
    default:
      qDebug() << "Unknown answer";
      break;
  }
}

void Interface::onUpdateFps()
{
  emit updateFps(numMeasurements);
  numMeasurements = 0;
}

void Interface::onTraceReceived(const QString text)
{
  emit traceReceived(text);
}

void Interface::receivedData(const char *pData, const int length, bool complete)
{
  if (complete)
  {
    numMeasurements++;
  }
  emit receivedMeasurementData(pData, length, complete);
}

void Interface::cmdConnectionConnected()
{
  traceConntection->connectToServer(destIp, TRACE_PORT);
  emit connected();
}

void Interface::cmdConnectionDisconnected()
{
  traceConntection->close();
  emit disconnected();
}

