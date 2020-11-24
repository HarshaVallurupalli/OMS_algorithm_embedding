/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef INTERFACE_H
#define INTERFACE_H

#include <QObject>
#include <QByteArray>
#include <QTimer>
#include "InterfaceThread.h"
#include "CmdConnection.h"
#include "DataConnection.h"
#include "TcpTraceClient.h"


class Interface: public QObject
{
  Q_OBJECT

  public:
    //These error numbers are given in the signal "error"
    enum Status_e
    {
      STATUS_OK = 0,
      STATUS_NO_ANSWER = 32768,
      STATUS_NOT_ACKNOWLEDGE = 32769
    };

    explicit Interface(QObject *parent = nullptr);
    ~Interface();
    void requestDistanceAmplitude(const bool doStream, const QByteArray &userData = nullptr);
    void requestDistance(const bool doStream, const QByteArray &userData = nullptr);
    void requestGrayscale(const bool doStream, const QByteArray &userData = nullptr);
    void requestDCS(const bool doStream, const QByteArray &userData = nullptr);
    void setIntegrationTimes(const uint16_t integrationTime3d[3], const uint16_t integrationTimeGrayscale, const QByteArray &userData = nullptr);
    void setOffset(const int16_t offset, const QByteArray &userData = nullptr);
    void setMinAmplitude(const uint16_t minAmplitude, const QByteArray &userData = nullptr);
    void setFilter(const bool medianFilter, const bool averageFilter, const uint16_t temporalFactor, const uint16_t temporalThreshold, const uint16_t edgeThreshold, const uint16_t temporalEdgeThresholdLow, const uint16_t temporalEdgeThresholdHigh, const uint16_t interferenceDetectionLimit, const bool interferenceDetectionUseLastValue, const QByteArray &userData=nullptr);
    void setBinning(const bool vertical, const bool horizontal);
    void setRoi(const uint16_t x0, const uint16_t y0, const uint16_t x1, const uint16_t y1);
    void setModulation(const uint8_t index, const uint8_t channel, const QByteArray &userData = nullptr);
    void stopStream(const QByteArray &userData = nullptr);
    void calibrate(const bool verifyOnly, const bool offsetOnly, const uint8_t calibrationIndex, const QByteArray &userData = nullptr);
    void calibrateProduction(const QByteArray &userData = nullptr);
    void getFirmwareRelease();
    void getChipInformation();
    void sendDebugCommand(const uint16_t command, const QByteArray payload);
    void setDataIPaddress(const QString& ipAddress, const QByteArray &userData= nullptr);
    void sendFirmwareUpdate(const QByteArray data);
    void connectToDevice(const QString destIp);
    void close();

    //Blocking commands
    Status_e getFirmwareRelease(unsigned int &major, unsigned int &minor);
    Status_e getChipInformation(uint16_t &chipId, uint16_t &waferId);



  signals:
    void receivedAck();
    void receivedError(const int errorCode);
    void receivedMeasurementData(const char *pData, const int length, bool complete);
    void receivedFirmwareRelease(const int major, const int minor);
    void receivedChipInfo(const int waferID, const int chipID);
    void connected();
    void disconnected();
    void stopRunning();
    void updateFps(const unsigned int fps);
    void traceReceived(const QString text);

  private slots:
    void receivedAnswer(QByteArray data);
    void receivedData(const char *pData, const int length, bool complete);   
    void cmdConnectionConnected();
    void cmdConnectionDisconnected();
    void onUpdateFps();
    void onTraceReceived(const QString text);

  private:
    void insertValue(QByteArray &output, const int8_t value);
    void insertValue(QByteArray &output, const uint16_t value);
    void insertValue(QByteArray &output, const int16_t value);
    unsigned int getUint16Value(const QByteArray &array, const unsigned int index);
    unsigned int getUint32Value(const QByteArray &array, const unsigned int index);
    int getInt16Value(const QByteArray &array, const unsigned int index);
    uint8_t boolToUint8(const bool value);
    int8_t boolToInt8(const bool value);
    void sendCommand(QByteArray &dataToSend, const QByteArray &userData);
    bool sendCommandBlocking(QByteArray &dataToSend, QByteArray &receivedData, const uint8_t answerType);

    InterfaceThread *timerThread;
    InterfaceThread *udpThread;
    InterfaceThread *tcpThread;
    CmdConnection *cmdConnection;
    DataConnection *dataConnection;
    TcpTraceClient *traceConntection;
    bool waitAck;
    QTimer *fpsTimer;
    unsigned int numMeasurements;
    QString destIp;

};

#endif // INTERFACE_H
