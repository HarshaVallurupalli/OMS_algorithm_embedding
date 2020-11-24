/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "stdint.h"
#include "DataHeader.h"
#include "ApplicationContext.h"

class Controller: public QObject
{
Q_OBJECT

public:
    Controller(ApplicationContext &context);
    void sendAllSettingsToCamera();
    void requestDistance(const bool isStream);
    void requestGrayscale(const bool isStream);
    void requestDistanceAmplitude(const bool isStream);
    void requestPointCloudDistance(const bool isStream);
    void requestPointCloudDistanceAmplitude(const bool isStream);
    void requestDCS(const bool isStream);
    void stopStream();
    void calibrate(const bool verifyOnly, const bool offsetOnly, const uint8_t calibrationIndex);
    void calibrateProduction();
    void close();

signals:
    void receivedMeasurementData(const char *pData, uint length, DataHeader &dataHeader);
    void updateFps(const unsigned int fps);
    void connected();
    void disconnected();
    void error(const uint16_t errorNumber);

private slots:
    void receivedData(const char *pData, const int length, const bool complete);
    void onFpsUpdate(const unsigned int fps);
    void cmdConnectionConnected();
    void cmdConnectionDisconnected();
    void onError(const uint16_t errorNumber);

private:
    void onOffsetChanged();
    void onIntegrationTimesChanged();
    void onMinAmplitudeChanged();
    void onFilterChanged();
    void onModulationChanged();
    void onBinningChanged();



    ApplicationContext &context;
};

#endif // CONTROLLER_H
