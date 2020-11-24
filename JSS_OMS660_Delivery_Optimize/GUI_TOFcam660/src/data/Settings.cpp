/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "Settings.h"
#include "QStandardPaths"
#include "MeasurementType.h"
#include <QDebug>

Settings::Settings():
mainWinPosX(0),
mainWinPosY(0),
mainWinWidth(0),
mainWinHeight(0),
winDataPosX(0),
winDataPosY(0),
winDataWidth(0),
winDataHeight(0),
verticalFlip(false),
horizontalFlip(true),
viewType(0)
{
    QString path = QStandardPaths::writableLocation(QStandardPaths::ConfigLocation);
    defaultSettingsPath = path + "/TOFCam660Settings.ini";
    setupSettings = new QSettings(defaultSettingsPath, QSettings::IniFormat);
    srcIp = "0.0.0.0";    
    restore();
}

void Settings::setSetupSettingsPath(const QString filePath)
{    
    delete setupSettings;
    setupSettings = new QSettings(filePath, QSettings::IniFormat);
}

QString Settings::getDefaultSettingsPath() const
{
    return defaultSettingsPath;
}

bool Settings::isVerticalFlip(){
    return verticalFlip;
}

bool Settings::isHorizontalFlip(){
    return horizontalFlip;
}

bool Settings::isRotated(){
    return rotate;
}

void Settings::setVerticalFlip(const bool state){
    verticalFlip = state;
    emit formatChanged();
    emit mirrorChanged();
    
}

void Settings::setHorizontalFlip(const bool state){
    horizontalFlip = state;
    emit formatChanged();
    emit mirrorChanged();    
}

void Settings::setRotate(const bool rotate){
    this->rotate = rotate;
    emit formatChanged();
}

void Settings::setAmplitudeGrayscale(bool state){
    amplitudeGrayscale = state;
}

bool Settings::isAmplitudeGrayscale(){
    return amplitudeGrayscale;
}

void Settings::setShowInfo(const bool showInfo)
{
  this->showInfo = showInfo;  
  emit showInfoChanged(this->showInfo);
}

bool Settings::getShowInfo() const
{
  return this->showInfo;
}

void Settings::setShowTimeScope(const bool showTimeScope)
{
  this->showTimeScope = showTimeScope;
  emit showTimeScopeChanged(this->showTimeScope);
}
bool Settings::getShowTimeScope() const
{
  return this->showTimeScope;
}

void Settings::setShowPixelScope(const bool showPixelScope)
{
  this->showPixelScope = showPixelScope;
    emit showPixelScopeChanged(this->showPixelScope);
}

void Settings::setRoiDefault()
{
  roiSettings.setDefault();
  emit roiChanged(roiSettings.getX1(), roiSettings.getY1(), roiSettings.getX2(), roiSettings.getY2());
}
void Settings::setRoi(const int x1, const int y1, const int x2, const int y2)
{
  roiSettings.setValues(x1, y1, x2, y2);
  emit roiChanged(roiSettings.getX1(), roiSettings.getY1(), roiSettings.getX2(), roiSettings.getY2());
}

RoiSettings Settings::getRoiSettings() const
{
  return roiSettings;
}

void Settings::setDataDestinationIP(const bool state)
{
    dataDestinationIP = state;
}

bool Settings::getDataDestinationIP(){
    return dataDestinationIP;
}


bool Settings::getShowPixelScope() const
{
  return this->showPixelScope;
}

void Settings::setRangeMin(const unsigned int range)
{
    this->rangeMin = range;
    //no signal to emit
}
unsigned int Settings::getRangeMin() const
{
    return rangeMin;
}

void Settings::setRangeMax(const unsigned int range)
{
    this->rangeMax = range;
    //no signal to emit
}
unsigned int Settings::getRangeMax() const
{
    return rangeMax;
}

void Settings::setIntegrationTime0(const unsigned int integrationTime)
{
    this->integrationTime0 = integrationTime;
    emit integrationTimeChanged();
}
unsigned int Settings::getIntegrationTime0() const
{
    return integrationTime0;
}

void Settings::setIntegrationTime1(const unsigned int integrationTime)
{
    this->integrationTime1 = integrationTime;
    emit integrationTimeChanged();
}

unsigned int Settings::getIntegrationTime1() const
{
     return integrationTime1;
}

void Settings::setIntegrationTime2(const unsigned int integrationTime)
{
    this->integrationTime2 = integrationTime;
    emit integrationTimeChanged();
}
unsigned int Settings::getIntegrationTime2() const
{
    return integrationTime2;
}

void Settings::setIntegrationTimeGrayscale(const unsigned int integrationTime)
{
    this->integrationTimeGrayscale = integrationTime;
    emit integrationTimeChanged();
}

void Settings::setMaxIntegrationTime0(const unsigned int integrationTime)
{
    this->maxIntegrationTime0 = integrationTime;
}

void Settings::setMaxIntegrationTime1(const unsigned int integrationTime)
{
    this->maxIntegrationTime1 = integrationTime;
}

unsigned int Settings::getIntegrationTimeGrayscale() const
{
    return integrationTimeGrayscale;
}

unsigned int Settings::getMaxIntegrationTime0() const
{
    return maxIntegrationTime0;
}

unsigned int Settings::getMaxIntegrationTime1() const
{
    return maxIntegrationTime1;
}

Selection &Settings::getPixelInfoSelection()
{
  return pixelInfoSelection;
}

Selection &Settings::getTimeScopeSelection()
{
  return timeScopeSelection;
}

Selection &Settings::getPixelScopeSelection()
{
    return pixelScopeSelection;
}

void Settings::setMeasurementType(const int measurementType)
{
  this->measurementType = measurementType;
  emit measurementTypeChanged(measurementType);
  emit settingsChanged();
}
int Settings::getMeasurementType() const
{
  return measurementType;
}


void Settings::start()
{
    emit startClicked();
}

void Settings::setOffset(const int offset)
{
    this->offset = offset;
    emit offsetChanged();
}
int Settings::getOffset() const
{
    return offset;
}

void Settings::setMinAmplitude(const unsigned int amplitude)
{
    this->minAmplitude = amplitude;
    emit minAmplitudeChanged();
}
unsigned int Settings::getMinAmplitude() const
{
    return minAmplitude;
}

void Settings::setUserData(const QByteArray userData)
{
  this->userData = userData;
  //no signal to emit
}

QByteArray Settings::getUserData() const
{
    return userData;
}

void Settings::setDestIp(const QString destIp)
{
    this->destIp = destIp;
}

void Settings::setComputerIp(const QString srcIP)
{
    srcIp = srcIP;
}

QString Settings::getDestIp() const
{
    return destIp;
}

QString Settings::getComputerIp() const
{
    return srcIp;
}

void Settings::setViewType(uint val)
{
    viewType = val;
}

uint Settings::getViewType()
{
    return viewType;
}

void Settings::setModulation(uint8_t mod){
    modulation = mod;
    emit modulationChanged();
}

uint8_t Settings::getModulation(){
    return modulation;
}

void Settings::setChannel(uint8_t value){
    channel = value;
    emit modulationChanged();
}

uint8_t Settings::getChannel(){
    return channel;
}

void Settings::setFirmwareRelease(const uint16_t major, const uint16_t minor)
{
    this->major = major;
    this->minor = minor;
    emit systemInfoChanged();
}

void Settings::setChipInfo(const uint16_t waferID, const uint16_t chipID){
    this->chipID = chipID;
    this->waferID = waferID;
    emit systemInfoChanged();
}

uint16_t Settings::getMajor() const
{
    return major;
}

uint16_t Settings::getMinor() const
{
    return minor;
}

uint16_t Settings::getWaferID() const
{
    return waferID;
}

uint16_t Settings::getChipID() const
{
    return  chipID;
}

void Settings::setMainWinPosX(const int value)
{
    mainWinPosX = value;
}

void Settings::setMainWinPosY(const int value)
{
    mainWinPosY = value;
}

void Settings::setMainWinWidth(const int value)
{
    mainWinWidth = value;
}

void Settings::setMainWinHeight(const int value)
{
    mainWinHeight = value;
}

void Settings::setMainWinRect(const QRect &rect)
{
    mainWinPosX = rect.x();
    mainWinPosY = rect.y();
    mainWinWidth = rect.width();
    mainWinHeight = rect.height();
}

int Settings::getMainWinPosX() const
{
    return mainWinPosX;
}

int Settings::getMainWinPosY() const
{
    return mainWinPosY;
}

int Settings::getMainWinWidth() const
{
    return mainWinWidth;
}

int Settings::getMainWinHeight() const
{
    return mainWinHeight;
}

void Settings::setWinDataPosX(const int value)
{
    winDataPosX = value;
}

void Settings::setWinDataPosY(const int value)
{
    winDataPosY = value;
}

void Settings::setWinDataWidth(const int value)
{
    winDataWidth = value;
}

void Settings::setWinDataHeight(const int value)
{
    winDataHeight = value;
}

void Settings::setWinDataRect(const QRect &rect)
{
    winDataPosX = rect.x();
    winDataPosY = rect.y();
    winDataWidth = rect.width();
    winDataHeight = rect.height();
}

void Settings::setPixelInfoRect(const QRect &rect)
{
    winPixelInfoPosX = rect.x();
    winPixelInfoPosY = rect.y();
    winPixelInfoWidth = rect.width();
    winPixelInfoHeight = rect.height();
}

void Settings::setPixelScopeRect(const QRect &rect)
{
    winPixelScopePosX = rect.x();
    winPixelScopePosY = rect.y();
    winPixelScopeWidth = rect.width();
    winPixelScopeHeight = rect.height();
}

void Settings::setTimeScopeRect(const QRect &rect)
{
    winTimeScopePosX = rect.x();
    winTimeScopePosY = rect.y();
    winTimeScopeWidth = rect.width();
    winTimeScopeHeight = rect.height();
}

int Settings::getWinDataPosX() const
{
    return winDataPosX;
}

int Settings::getWinDataPosY() const
{
    return winDataPosY;
}

int Settings::getWinDataWidth() const
{
    return winDataWidth;
}

int Settings::getWinDataHeight() const
{
    return winDataHeight;
}

QRect Settings::getPixelInfoRect() const
{
    QRect rect(winPixelInfoPosX, winPixelInfoPosY, winPixelInfoWidth, winPixelInfoHeight);
    return rect;
}

QRect Settings::getPixelScopeRect() const
{
    QRect rect(winPixelScopePosX, winPixelScopePosY, winPixelScopeWidth, winPixelScopeHeight);
    return rect;
}

QRect Settings::getTimeScopeRect() const
{
    QRect rect(winTimeScopePosX, winTimeScopePosY, winTimeScopeWidth, winTimeScopeHeight);
    return rect;
}

void Settings::restore()
{
    viewType = setupSettings->value("viewType", 0).toUInt();

    if(viewType == 3) setMeasurementType(0);
    else if(viewType == 4) setMeasurementType(1);
    else setMeasurementType(static_cast<int>(viewType));

    integrationTime0 = setupSettings->value("IntTime0", 500).toUInt();
    integrationTime1 = setupSettings->value("IntTime1", 40).toUInt();
    integrationTime2 = setupSettings->value("IntTime2", 0).toUInt();    
    maxIntegrationTime0= setupSettings->value("maxIntTime0", 2000).toUInt();
    maxIntegrationTime1= setupSettings->value("maxIntTime1", 2000).toUInt();
    integrationTimeGrayscale = setupSettings->value("IntTimeGrayscale", 100).toUInt();
    offset =  setupSettings->value("Offset", 0).toInt();
    minAmplitude = setupSettings->value("MinAmplitude", 50).toUInt();
    rangeMin = setupSettings->value("RangeMin", 0).toUInt();
    rangeMax = setupSettings->value("RangeMax", 6000).toUInt();
    userData = setupSettings->value("UserData").toByteArray();
    destIp = setupSettings->value("destIp", "10.10.31.180").toString();

    mainWinPosX = setupSettings->value("mainWinPosX", 0).toInt();
    mainWinPosY = setupSettings->value("mainWinPosY", 0).toInt();
    mainWinWidth = setupSettings->value("mainWinWidth", 0).toInt();
    mainWinHeight = setupSettings->value("mainWinHeight", 0).toInt();

    winDataPosX = setupSettings->value("winDataPosX", 0).toInt();
    winDataPosY = setupSettings->value("winDataPosY", 0).toInt();
    winDataWidth = setupSettings->value("winDataWidth", 0).toInt();
    winDataHeight = setupSettings->value("winDataHeight", 0).toInt();

    winPixelInfoPosX = setupSettings->value("winPixelInfoPosX", 0).toInt();
    winPixelInfoPosY = setupSettings->value("winPixelInfoPosY", 0).toInt();
    winPixelInfoWidth = setupSettings->value("winPixelInfoWidth", 0).toInt();
    winPixelInfoHeight = setupSettings->value("winPixelInfoHeight", 0).toInt();

    winPixelScopePosX = setupSettings->value("winPixelScopePosX", 0).toInt();
    winPixelScopePosY = setupSettings->value("winPixelScopePosY", 0).toInt();
    winPixelScopeWidth = setupSettings->value("winPixelScopeWidth", 0).toInt();
    winPixelScopeHeight = setupSettings->value("winPixelScopeHeight", 0).toInt();

    winTimeScopePosX = setupSettings->value("winTimeScopePosX", 0).toInt();
    winTimeScopePosY = setupSettings->value("winTimeScopePosY", 0).toInt();
    winTimeScopeWidth = setupSettings->value("winTimeScopeWidth", 0).toInt();
    winTimeScopeHeight = setupSettings->value("winTimeScopeHeight", 0).toInt();

    cloud.setPoints(setupSettings->value("isPoints", true).toBool());
    cloud.setGrayPointCloud(setupSettings->value("isGrayPointCloud", false).toBool());
    cloud.setShowAxis2D(setupSettings->value("isShowAxis2D", false).toBool());
    cloud.setShowAxis3D(setupSettings->value("isShowAxis3D", false).toBool());
    cloud.setShowGrid(setupSettings->value("isShowGrid", true).toBool());
    cloud.setShowLabels(setupSettings->value("isShowLabels", false).toBool());
    cloud.setShowLegend(setupSettings->value("isShowLegend", false).toBool());
    cloud.setCartesian(setupSettings->value("isCartesian", true).toBool());
    cloud.setPCLFilter(setupSettings->value("isPCLFilter", false).toBool());
    cloud.setPCLFilterThreshold(setupSettings->value("PCLFilterThreshold", 700).toInt());
    cloud.setPointSize(setupSettings->value("pointSize", 2.5).toDouble());
    setVerticalFlip(setupSettings->value("verticalFlip", false).toBool());
    setHorizontalFlip(setupSettings->value("horizontalFlip", false).toBool());
    setRotate(setupSettings->value("Rotate", false).toBool());

    cloud.setAxisLineWidth(setupSettings->value("axisLineWidth", 3).toInt());    
    cloud.setAxisOffsetX(setupSettings->value("axisOffsetX", 0).toInt());
    cloud.setAxisOffsetY(setupSettings->value("axisOffsetY", 0).toInt());
    cloud.setAxisOffsetZ(setupSettings->value("axisOffsetZ", 0).toInt());
    cloud.setAxisColorR(setupSettings->value("axisColorR", 0.4).toDouble());
    cloud.setAxisColorG(setupSettings->value("axisColorG", 0.4).toDouble());
    cloud.setAxisColorB(setupSettings->value("axisColorB", 0.4).toDouble());
    cloud.setAxisColorA(setupSettings->value("axisColorA", 1.0).toDouble());

    cloud.setLabelColorR(setupSettings->value("labelColorR", 1.0).toDouble());
    cloud.setLabelColorG(setupSettings->value("labelColorG", 1.0).toDouble());
    cloud.setLabelColorB(setupSettings->value("labelColorB", 1.0).toDouble());

    cloud.setCellWidth(setupSettings->value("gridCellWidth", 1000).toUInt());
    cloud.setNumberCells(setupSettings->value("gridNumberCells", 14).toUInt());
    cloud.setGridOffsetX(setupSettings->value("gridOffsetX", 0).toInt());
    cloud.setGridOffsetY(setupSettings->value("gridOffsetY", 0).toInt());
    cloud.setGridOffsetZ(setupSettings->value("gridOffsetZ", 0).toInt());

    cloud.setGridColorR(setupSettings->value("gridColorR", 0.4).toDouble());
    cloud.setGridColorG(setupSettings->value("gridColorG", 0.4).toDouble());
    cloud.setGridColorB(setupSettings->value("gridColorB", 0.4).toDouble());
    cloud.setGridColorA(setupSettings->value("gridColorA", 1.0).toDouble());


    cloud.setObjectOffsetX(setupSettings->value("objectOffsetX", 0).toInt());
    cloud.setObjectOffsetY(setupSettings->value("objectOffsetY", 0).toInt());
    cloud.setObjectOffsetZ(setupSettings->value("objectOffsetZ", 0).toInt());
    cloud.setScaleX(setupSettings->value("scaleX", 1.0).toDouble());
    cloud.setScaleY(setupSettings->value("scaleY", 1.0).toDouble());
    cloud.setScaleZ(setupSettings->value("scaleZ", 1.0).toDouble());
    cloud.setAngleObjectZ(setupSettings->value("angleObjectZ", 0).toInt());
    cloud.setFOV(setupSettings->value("fov", 50).toInt());

    cloud.setCameraOffsetX(setupSettings->value("cameraOffsetX", -450).toInt());
    cloud.setCameraOffsetY(setupSettings->value("cameraOffsetY", -520).toInt());
    cloud.setCameraZoom(setupSettings->value("cameraZoom", 0.25).toDouble());
    cloud.setCameraAngleX(setupSettings->value("cameraAngleX", -70).toInt());
    cloud.setCameraAngleY(setupSettings->value("cameraAngleY", 20).toInt());
    cloud.setCameraAngleZ(setupSettings->value("cameraAngleZ", 180).toInt());

    filter.setMedianFilter(setupSettings->value("isMedianFilter", false).toBool());
    filter.setAverageFilter(setupSettings->value("isAverageFilter", false).toBool());

    filter.setTemporalFilter(setupSettings->value("isTemporalFilter", false).toBool());
    filter.setFactor(setupSettings->value("factor", 0.3).toDouble());
    filter.setTemporalThreshold(setupSettings->value("temporalThreshold", 300).toInt());

    filter.setEdgeFilter(setupSettings->value("isEdgeFilter", false).toBool());
    filter.setEdgeThreshold(setupSettings->value("edgeThreshold", 300).toInt());

    filter.setTemporalEdgeFilter(setupSettings->value("isTemporalEdgeFilter", false).toBool());
    filter.setTemporalEdgeThresholdLow(setupSettings->value("temporalEdgeThresholdLow", 100).toInt());
    filter.setTemporalEdgeThresholdHigh(setupSettings->value("temporalEdgeThresholdHigh", 300).toInt());

    filter.setInterferenceDetection(setupSettings->value("isInterferenceDetection", false).toBool());
    filter.setInterferenceDetectionLimit(setupSettings->value("interferenceDetectionLimit", 300).toInt());
    filter.setInterferenceDetectionUseLastValue(setupSettings->value("interferenceDetectionUseLastValue", false).toBool());        
    setModulation( static_cast<uint8_t>(setupSettings->value("modulationFrequency", 0).toUInt()));
    setChannel( static_cast<uint8_t>(setupSettings->value("channelFrequency", 0).toUInt()));
    setAmplitudeGrayscale(setupSettings->value("amplitudeGrayscale", false).toBool());

    log.setLogPath(setupSettings->value("logPath", "../").toString());
    log.setLogName(setupSettings->value("logName", "image").toString());    
    log.setFps(setupSettings->value("logFps", 20.0).toDouble());

    int x1 = setupSettings->value("roi_x1", 0).toInt();
    int y1 = setupSettings->value("roi_y1", 0).toInt();
    int x2 = setupSettings->value("roi_x2", 319).toInt();
    int y2 = setupSettings->value("roi_y2", 239).toInt();
    roiSettings.setValues(x1, y1, x2, y2);

    cloud.setWinPosX(setupSettings->value("cloud_win_x", 0).toInt());
    cloud.setWinPosY(setupSettings->value("cloud_win_y", 0).toInt());
    cloud.setWinWidth(setupSettings->value("cloud_win_width", 1000).toInt());
    cloud.setWinHeight(setupSettings->value("cloud_win_height", 750).toInt());

    binning.setVerticalBinning(setupSettings->value("isVerticalBinning", false).toBool());
    binning.setHorizontalBinning(setupSettings->value("isHorizontalBinning", false).toBool());

    cloud.setWideField(setupSettings->value("isWideField", false).toBool());
    cloud.setSensorCenterOffsetX(setupSettings->value("lensCenterOffsetX", 0).toInt());
    cloud.setSensorCenterOffsetY(setupSettings->value("lensCenterOffsetY", 0).toInt());

    cloud.setDefaultViewAngleX(setupSettings->value("defaultViewAngleX", 0).toInt());
    cloud.setDefaultViewAngleY(setupSettings->value("defaultViewAngleY", 0).toInt());
    cloud.setDefaultViewAngleZ(setupSettings->value("defaultViewAngleZ", 0).toInt());
    cloud.setDefaultViewOffsetX(setupSettings->value("defaultViewOffsetX", 0).toInt());
    cloud.setDefaultViewOffsetY(setupSettings->value("defaultViewOffsetY", 0).toInt());
    cloud.setDefaultViewZoom(setupSettings->value("defaultViewZoom", 1.0).toDouble());

    emit settingsLoaded();
}

void Settings::save()
{            
    setupSettings->setValue("viewType", QVariant::fromValue(viewType));
    setupSettings->setValue("IntTime0", QVariant::fromValue(integrationTime0));
    setupSettings->setValue("IntTime1", QVariant::fromValue(integrationTime1));
    setupSettings->setValue("IntTimeGrayscale", QVariant::fromValue(integrationTimeGrayscale));
    setupSettings->setValue("Offset", QVariant::fromValue(offset));
    setupSettings->setValue("MinAmplitude", QVariant::fromValue(minAmplitude));
    setupSettings->setValue("RangeMin", QVariant::fromValue(rangeMin));
    setupSettings->setValue("RangeMax", QVariant::fromValue(rangeMax));
    setupSettings->setValue("UserData", QVariant::fromValue(userData));
    setupSettings->setValue("destIp", QVariant::fromValue(destIp));

    setupSettings->setValue("mainWinPosX", QVariant::fromValue(mainWinPosX));
    setupSettings->setValue("mainWinPosY", QVariant::fromValue(mainWinPosY));
    setupSettings->setValue("mainWinWidth", QVariant::fromValue(mainWinWidth));
    setupSettings->setValue("mainWinHeight", QVariant::fromValue(mainWinHeight));

    setupSettings->setValue("winDataPosX", QVariant::fromValue(winDataPosX));
    setupSettings->setValue("winDataPosY", QVariant::fromValue(winDataPosY));
    setupSettings->setValue("winDataWidth", QVariant::fromValue(winDataWidth));
    setupSettings->setValue("winDataHeight", QVariant::fromValue(winDataHeight));

    setupSettings->setValue("winPixelInfoPosX", QVariant::fromValue(winPixelInfoPosX));
    setupSettings->setValue("winPixelInfoPosY", QVariant::fromValue(winPixelInfoPosY));
    setupSettings->setValue("winPixelInfoWidth", QVariant::fromValue(winPixelInfoWidth));
    setupSettings->setValue("winPixelInfoHeight", QVariant::fromValue(winPixelInfoHeight));

    setupSettings->setValue("winPixelScopePosX", QVariant::fromValue(winPixelScopePosX));
    setupSettings->setValue("winPixelScopePosY", QVariant::fromValue(winPixelScopePosY));
    setupSettings->setValue("winPixelScopeWidth", QVariant::fromValue(winPixelScopeWidth));
    setupSettings->setValue("winPixelScopeHeight", QVariant::fromValue(winPixelScopeHeight));

    setupSettings->setValue("winTimeScopePosX", QVariant::fromValue(winTimeScopePosX));
    setupSettings->setValue("winTimeScopePosY", QVariant::fromValue(winTimeScopePosY));
    setupSettings->setValue("winTimeScopeWidth", QVariant::fromValue(winTimeScopeWidth));
    setupSettings->setValue("winTimeScopeHeight", QVariant::fromValue(winTimeScopeHeight));

    setupSettings->setValue("isPoints", QVariant::fromValue(cloud.isPoints()));
    setupSettings->setValue("isGrayPointCloud", QVariant::fromValue(cloud.isGrayPointCloud()));
    setupSettings->setValue("isShowAxis2D", QVariant::fromValue(cloud.isShowAxis2D()));
    setupSettings->setValue("isShowAxis3D", QVariant::fromValue(cloud.isShowAxis3D()));
    setupSettings->setValue("isShowGrid", QVariant::fromValue(cloud.isShowGrid()));
    setupSettings->setValue("isShowLabels", QVariant::fromValue(cloud.isShowLabels()));
    setupSettings->setValue("isShowLegend", QVariant::fromValue(cloud.isShowLegend()));
    setupSettings->setValue("isCartesian", QVariant::fromValue(cloud.isCartesian()));
    setupSettings->setValue("isPCLFilter", QVariant::fromValue(cloud.isPCLFilter()));
    setupSettings->setValue("PCLFilterThreshold", QVariant::fromValue(cloud.getPCLFilterThreshold()));
    setupSettings->setValue("pointSize", QVariant::fromValue(cloud.getPointSize()));
    setupSettings->setValue("verticalFlip", QVariant::fromValue(isVerticalFlip()));
    setupSettings->setValue("horizontalFlip", QVariant::fromValue(isHorizontalFlip()));
    setupSettings->setValue("Rotate", QVariant::fromValue(isRotated()));

    setupSettings->setValue("axisLineWidth", QVariant::fromValue(cloud.getAxisLineWidth()));    
    setupSettings->setValue("axisOffsetX", QVariant::fromValue(cloud.getAxisOffsetX()));
    setupSettings->setValue("axisOffsetY", QVariant::fromValue(cloud.getAxisOffsetY()));
    setupSettings->setValue("axisOffsetZ", QVariant::fromValue(cloud.getAxisOffsetZ()));
    setupSettings->setValue("axisColorR", QVariant::fromValue(cloud.getAxisColor().r));
    setupSettings->setValue("axisColorG", QVariant::fromValue(cloud.getAxisColor().g));
    setupSettings->setValue("axisColorB", QVariant::fromValue(cloud.getAxisColor().b));
    setupSettings->setValue("axisColorA", QVariant::fromValue(cloud.getAxisColor().a));
    setupSettings->setValue("labelColorR", QVariant::fromValue(cloud.getLabelColor().r));
    setupSettings->setValue("labelColorG", QVariant::fromValue(cloud.getLabelColor().g));
    setupSettings->setValue("labelColorB", QVariant::fromValue(cloud.getLabelColor().b));

    setupSettings->setValue("gridCellWidth", QVariant::fromValue(cloud.getCellWidth()));
    setupSettings->setValue("gridNumberCells", QVariant::fromValue(cloud.getNumberCells()));
    setupSettings->setValue("gridOffsetX", QVariant::fromValue(cloud.getGridOffsetX()));
    setupSettings->setValue("gridOffsetY", QVariant::fromValue(cloud.getGridOffsetY()));
    setupSettings->setValue("gridOffsetZ", QVariant::fromValue(cloud.getGridOffsetZ()));
    setupSettings->setValue("gridColorR", QVariant::fromValue(cloud.getGridColor().r));
    setupSettings->setValue("gridColorG", QVariant::fromValue(cloud.getGridColor().g));
    setupSettings->setValue("gridColorB", QVariant::fromValue(cloud.getGridColor().b));
    setupSettings->setValue("gridColorA", QVariant::fromValue(cloud.getGridColor().a));

    setupSettings->setValue("objectOffsetX", QVariant::fromValue(cloud.getObjectOffsetX()));
    setupSettings->setValue("objectOffsetY", QVariant::fromValue(cloud.getObjectOffsetY()));
    setupSettings->setValue("objectOffsetZ", QVariant::fromValue(cloud.getObjectOffsetZ()));
    setupSettings->setValue("scaleX", QVariant::fromValue(cloud.getScaleX()));
    setupSettings->setValue("scaleY", QVariant::fromValue(cloud.getScaleY()));
    setupSettings->setValue("scaleZ", QVariant::fromValue(cloud.getScaleZ()));
    setupSettings->setValue("angleObjectZ", QVariant::fromValue(cloud.getAngleObjectZ()));    
    setupSettings->setValue("fov", QVariant::fromValue(cloud.getFOV()));

    setupSettings->setValue("cameraOffsetX", QVariant::fromValue(cloud.getCameraOffsetX()));
    setupSettings->setValue("cameraOffsetY", QVariant::fromValue(cloud.getCameraOffsetY()));
    setupSettings->setValue("cameraZoom", QVariant::fromValue(cloud.getCameraZoom()));
    setupSettings->setValue("cameraAngleX", QVariant::fromValue(cloud.getCameraAngleX()));
    setupSettings->setValue("cameraAngleY", QVariant::fromValue(cloud.getCameraAngleY()));
    setupSettings->setValue("cameraAngleZ", QVariant::fromValue(cloud.getCameraAngleZ()));

    setupSettings->setValue("isMedianFilter", QVariant::fromValue(filter.isMedianFilter()));
    setupSettings->setValue("isAverageFilter", QVariant::fromValue(filter.isAverageFilter()));

    setupSettings->setValue("isTemporalFilter", QVariant::fromValue(filter.isTemporalFilter()));    
    setupSettings->setValue("factor", QVariant::fromValue(filter.getFactor()));
    setupSettings->setValue("temporalThreshold", QVariant::fromValue(filter.getTemporalThreshold()));

    setupSettings->setValue("isEdgeFilter", QVariant::fromValue(filter.isEdgeFilter()));
    setupSettings->setValue("edgeThreshold", QVariant::fromValue(filter.getEdgeThreshold()));

    setupSettings->setValue("isTemporalEdgeFilter", QVariant::fromValue(filter.isTemporalEdgeFilter()));
    setupSettings->setValue("temporalEdgeThresholdLow", QVariant::fromValue(filter.getTemporalEdgeThresholdLow()));
    setupSettings->setValue("temporalEdgeThresholdHigh", QVariant::fromValue(filter.getTemporalEdgeThresholdHigh()));

    setupSettings->setValue("isInterferenceDetection", QVariant::fromValue(filter.isInterferenceDetection()));
    setupSettings->setValue("interferenceDetectionLimit", QVariant::fromValue(filter.getInterferenceDetectionLimit()));
    setupSettings->setValue("interferenceDetectionUseLastValue", QVariant::fromValue(filter.isInterferenceDetectionUseLastValue()));
    setupSettings->setValue("modulationFrequency", QVariant::fromValue(getModulation()));
    setupSettings->setValue("channelFrequency", QVariant::fromValue(getChannel()));
    setupSettings->setValue("amplitudeGrayscale", QVariant::fromValue(isAmplitudeGrayscale()));

    setupSettings->setValue("logPath", QVariant::fromValue(log.getLogPath()));
    setupSettings->setValue("logName", QVariant::fromValue(log.getLogName()));
    setupSettings->setValue("logFps",  QVariant::fromValue(log.getFps()));

    setupSettings->setValue("roi_x1",  QVariant::fromValue(roiSettings.getX1()));
    setupSettings->setValue("roi_y1",  QVariant::fromValue(roiSettings.getY1()));
    setupSettings->setValue("roi_x2",  QVariant::fromValue(roiSettings.getX2()));
    setupSettings->setValue("roi_y2",  QVariant::fromValue(roiSettings.getY2()));

    setupSettings->setValue("cloud_win_x",  QVariant::fromValue(cloud.getWinPosX()));
    setupSettings->setValue("cloud_win_y",  QVariant::fromValue(cloud.getWinPosY()));
    setupSettings->setValue("cloud_win_width",  QVariant::fromValue(cloud.getWinWidth()));
    setupSettings->setValue("cloud_win_height",  QVariant::fromValue(cloud.getWinHeight()));

    setupSettings->setValue("isVerticalBinning",  QVariant::fromValue(binning.isVerticalBinning()));
    setupSettings->setValue("isHorizontalBinning",  QVariant::fromValue(binning.isHorizontalBinning()));

    setupSettings->setValue("isWideField", QVariant::fromValue(cloud.isWideField()));
    setupSettings->setValue("lensCenterOffsetX", QVariant::fromValue(cloud.getSensorCenterOffsetX()));
    setupSettings->setValue("lensCenterOffsetY", QVariant::fromValue(cloud.getSensorCenterOffsetY()));

    setupSettings->setValue("defaultViewAngleX", QVariant::fromValue(cloud.getDefaultViewAngleX()));
    setupSettings->setValue("defaultViewAngleY", QVariant::fromValue(cloud.getDefaultViewAngleY()));
    setupSettings->setValue("defaultViewAngleZ", QVariant::fromValue(cloud.getDefaultViewAngleZ()));
    setupSettings->setValue("defaultViewOffsetX", QVariant::fromValue(cloud.getDefaultViewOffsetX()));
    setupSettings->setValue("defaultViewOffsetY", QVariant::fromValue(cloud.getDefaultViewOffsetY()));
    setupSettings->setValue("defaultViewZoom", QVariant::fromValue(cloud.getDefaultViewZoom()));

}

