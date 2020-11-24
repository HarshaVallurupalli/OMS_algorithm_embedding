/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>
#include <QObject>
#include <QByteArray>
#include "SettingsBinning.h"
#include "SettingsPointCloud.h"
#include "SettingsFilter.h"
#include "SettingsLog.h"
#include "RoiSettings.h"
#include "Selection.h"
#include <QRect>

class  Settings: public QObject
{

  Q_OBJECT

public:
    Settings();

    enum ViewType{ DISTANCE, DISTANCE_AMPLITUDE, GRAYSCALE, POINT_CLOUD_DISTANCE, POINT_CLOUD_DISTANCE_AMPLITUDE, POINT_CLOUD_DISTANCE_GRAYSCALE};
    enum ModulationType { MHZ_12, MHZ_24, MHZ_6, MHZ_3, MHZ_1_5, MHZ_0_75 };
    enum CameraNumber{ CAM1, CAM2, CAM3, CAM4};//edit
    enum ConnectionType{ TCP_IP, UDP_IP};//edit

    void setSetupSettingsPath(const QString filePath);
    QString getDefaultSettingsPath() const;

    int getMainWinPosX() const;
    int getMainWinPosY() const;
    int getMainWinWidth() const;
    int getMainWinHeight() const;
    int getWinDataPosX() const;
    int getWinDataPosY() const;
    int getWinDataWidth() const;
    int getWinDataHeight() const;

    QRect getPixelInfoRect() const;
    QRect getPixelScopeRect() const;
    QRect getTimeScopeRect() const;

    bool getShowInfo() const;
    bool getShowTimeScope() const;
    bool getShowPixelScope() const;

    bool isVerticalFlip();
    bool isHorizontalFlip();
    bool isRotated();
    unsigned int getRangeMax() const;
    unsigned int getRangeMin() const;
    unsigned int getIntegrationTime0() const;
    unsigned int getIntegrationTime1() const;
    unsigned int getIntegrationTime2() const;
    unsigned int getIntegrationTimeGrayscale() const;
    unsigned int getMaxIntegrationTime0() const;        
    unsigned int getMaxIntegrationTime1() const;

    Selection &getPixelInfoSelection();
    Selection &getTimeScopeSelection();
    Selection &getPixelScopeSelection();
    RoiSettings getRoiSettings() const;

    int getMeasurementType() const;
    int getCameraSelection() const;
    void setDataDestinationIP(const bool state);
    bool getDataDestinationIP();


    int getOffset() const;
    unsigned int getMinAmplitude() const;
    QByteArray getUserData() const;
    QString getDestIp() const;
    QString getComputerIp() const;
    SettingsPointCloud cloud;
    SettingsFilter filter;
    SettingsLog log;
    SettingsBinning binning;

    void restore();
    void save();
    void start();


public slots:

    void setMainWinPosX(const int value);
    void setMainWinPosY(const int value);
    void setMainWinWidth(const int value);
    void setMainWinHeight(const int value);
    void setMainWinRect(const QRect &rect);

    void setWinDataPosX(const int value);
    void setWinDataPosY(const int value);
    void setWinDataWidth(const int value);
    void setWinDataHeight(const int value);
    void setWinDataRect(const QRect &rect);

    void setPixelInfoRect(const QRect& rect);
    void setPixelScopeRect(const QRect& rect);
    void setTimeScopeRect(const QRect& rect);

    void setVerticalFlip(const bool state);
    void setHorizontalFlip(const bool state);
    void setRotate(const bool rotate);
    void setAmplitudeGrayscale(bool state);
    bool isAmplitudeGrayscale();

    void setShowInfo(const bool showInfo);
    void setShowTimeScope(const bool showTimeScope);
    void setShowPixelScope(const bool showPixelScope);


    void setRoi(const int x1, const int y1, const int x2, const int y2);
    void setRoiDefault();

    void setMinAmplitude(const unsigned int amplitude);
    void setIntegrationTime0(const unsigned int integrationTime);
    void setIntegrationTime1(const unsigned int integrationTime);
    void setIntegrationTime2(const unsigned int integrationTime);    
    void setMaxIntegrationTime0(const unsigned int integrationTime);
    void setMaxIntegrationTime1(const unsigned int integrationTime);
    void setIntegrationTimeGrayscale(const unsigned int integrationTime);
    void setMeasurementType(const int measurementType);
   // void setCameraSelection(const int cameraSelection);//edit
    void setRangeMin(const unsigned int rangeMin);
    void setRangeMax(const unsigned int rangeMax);
    void setOffset(const int offset);
    void setUserData(const QByteArray userData);
    void setDestIp(const QString destIp);
    void setComputerIp(const QString srcIP);
    void setViewType(uint val);
    uint getViewType();
    void setCameraNumber(uint cameranumber);//edit
    uint getCameraNumber();
    void setStreamConnectionType(uint ConnectionType);//edit
    uint getStreamConnectionType();
    void setModulation(uint8_t mod);
    uint8_t getModulation();
    void setChannel(uint8_t value);
    uint8_t getChannel();    
    void setFirmwareRelease(const uint16_t major, const uint16_t minor);
    void setChipInfo(const uint16_t waferID, const uint16_t chipID);
    uint16_t getMajor() const;
    uint16_t getMinor() const;
    uint16_t getWaferID()const;
    uint16_t getChipID() const;



signals:
    void settingsLoaded();
    void settingsChanged();
    void minAmplitudeChanged();
    void offsetChanged();
    void integrationTimeChanged();
    void modulationChanged();
    void mirrorChanged();
    void formatChanged();
    void startClicked();
    void showInfoChanged(const bool checked);
    void showTimeScopeChanged(const bool checked);
    void showPixelScopeChanged(const bool checked);
    void measurementTypeChanged(int);
    //void cameraSelectionChanged(int); //edit
    void roiChanged(const int x1, const int y1, const int x2, const int y2);
    void systemInfoChanged();


private:

    int mainWinPosX;
    int mainWinPosY;
    int mainWinWidth;
    int mainWinHeight;

    int winDataPosX;
    int winDataPosY;
    int winDataWidth;
    int winDataHeight;

    int winPixelInfoPosX;
    int winPixelInfoPosY;
    int winPixelInfoWidth;
    int winPixelInfoHeight;

    int winPixelScopePosX;
    int winPixelScopePosY;
    int winPixelScopeWidth;
    int winPixelScopeHeight;

    int winTimeScopePosX;
    int winTimeScopePosY;
    int winTimeScopeWidth;
    int winTimeScopeHeight;


    bool verticalFlip;
    bool horizontalFlip;
    bool rotate;
    bool amplitudeGrayscale;
    bool showInfo;
    bool showTimeScope;
    bool showPixelScope;
    bool dataDestinationIP;

    unsigned int viewType;
    unsigned int cameranumber;//edit
    unsigned int connectiontype;//edit
    unsigned int rangeMin;
    unsigned int rangeMax;
    unsigned int integrationTime0;
    unsigned int integrationTime1;
    unsigned int integrationTime2;
    unsigned int integrationTimeGrayscale;
    unsigned int maxIntegrationTime0;
    unsigned int maxIntegrationTime1;
    Selection pixelInfoSelection;
    Selection timeScopeSelection;
    Selection pixelScopeSelection;
    RoiSettings roiSettings;

    int offset;
    int measurementType;
    int cameraSelection;//edit
    unsigned int minAmplitude;
    uint16_t major;
    uint16_t minor;
    uint16_t waferID;
    uint16_t chipID;
    uint8_t modulation;
    uint8_t channel;
    QByteArray userData;
    QString destIp;
    QString srcIp;
    QSettings *setupSettings;
    QString defaultSettingsPath;

};

#endif // SETTINGS_H
