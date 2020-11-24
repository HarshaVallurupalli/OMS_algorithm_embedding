/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "Controller.h"


Controller::Controller(ApplicationContext &context):context(context)
{
  //Signals from the settings
  connect(&context.getSettings(), static_cast<void (Settings::*)()>(&Settings::offsetChanged), this, &Controller::onOffsetChanged);
  connect(&context.getSettings(), static_cast<void (Settings::*)()>(&Settings::integrationTimeChanged), this, &Controller::onIntegrationTimesChanged);
  connect(&context.getSettings(), static_cast<void (Settings::*)()>(&Settings::minAmplitudeChanged), this, &Controller::onMinAmplitudeChanged);
  connect(&context.getSettings(), static_cast<void (Settings::*)()>(&Settings::modulationChanged), this, &Controller::onModulationChanged);
  connect(&context.getSettings().filter, static_cast<void (SettingsFilter::*)()>(&SettingsFilter::filterChanged), this, &Controller::onFilterChanged);
  connect(&context.getSettings().binning, static_cast<void (SettingsBinning::*)()>(&SettingsBinning::binningChanged), this, &Controller::onBinningChanged);

  //Signals from the interface
  connect(&context.getInterface(), &Interface::receivedMeasurementData, this, &Controller::receivedData);
  connect(&context.getInterface(), &Interface::updateFps, this, &Controller::onFpsUpdate);
  connect(&context.getInterface(), &Interface::connected, this, &Controller::cmdConnectionConnected);
  connect(&context.getInterface(), &Interface::disconnected, this, &Controller::cmdConnectionDisconnected);
  connect(&context.getInterface(), &Interface::receivedError, this, &Controller::onError);
}

//Integration time changed, update the camera
void Controller::onIntegrationTimesChanged()
{
  uint16_t integrationTimes3d[3];
  uint16_t integrationTimeGrayscale;

  integrationTimes3d[0] = context.getSettings().getIntegrationTime0();
  integrationTimes3d[1] = context.getSettings().getIntegrationTime1();
  integrationTimes3d[2] = context.getSettings().getIntegrationTime2();
  integrationTimeGrayscale = context.getSettings().getIntegrationTimeGrayscale();

  QByteArray userData = context.getSettings().getUserData();
  context.getInterface().setIntegrationTimes(integrationTimes3d, integrationTimeGrayscale, userData);
}

//Offset changed, update the camera
void Controller::onOffsetChanged()
{
  QByteArray userData = context.getSettings().getUserData();
  int16_t offset = context.getSettings().getOffset();
  context.getInterface().setOffset(offset, userData);
}

//Min. amplitude changed, update the camera
void Controller::onMinAmplitudeChanged()
{
  QByteArray userData = context.getSettings().getUserData();
  uint16_t minAmplitude = context.getSettings().getMinAmplitude();
  context.getInterface().setMinAmplitude(minAmplitude, userData);
}

//Send all settings to the camera, for example when the connection is established
void Controller::sendAllSettingsToCamera()
{
  uint16_t integrationTimes3d[3];
  uint16_t integrationTimeGrayscale;

  integrationTimes3d[0] = context.getSettings().getIntegrationTime0();
  integrationTimes3d[1] = context.getSettings().getIntegrationTime1();
  integrationTimes3d[2] = context.getSettings().getIntegrationTime2();
  integrationTimeGrayscale = context.getSettings().getIntegrationTimeGrayscale();
  context.getInterface().setIntegrationTimes(integrationTimes3d, integrationTimeGrayscale);

  int16_t offset = context.getSettings().getOffset();
  context.getInterface().setOffset(offset);

  uint16_t minAmplitude = context.getSettings().getMinAmplitude();
  context.getInterface().setMinAmplitude(minAmplitude);
  context.getInterface().getFirmwareRelease();
  context.getInterface().getChipInformation();
}


void  Controller::onFilterChanged(){

    bool median = context.getSettings().filter.isMedianFilter();
    bool average = context.getSettings().filter.isAverageFilter();
    bool interferenceDetectionUseLastValue = context.getSettings().filter.isInterferenceDetectionUseLastValue();
    uint16_t temporalFactor = static_cast<uint16_t>(context.getSettings().filter.getFactor() * 1000);
    uint16_t temporalThreshold = static_cast<uint16_t>(context.getSettings().filter.getTemporalThreshold());
    uint16_t edgeThreshold = static_cast<uint16_t>(context.getSettings().filter.getEdgeThreshold());
    uint16_t temporalEdgeThresholdLow = static_cast<uint16_t>(context.getSettings().filter.getTemporalEdgeThresholdLow());
    uint16_t temporalEdgeThresholdHigh = static_cast<uint16_t>(context.getSettings().filter.getTemporalEdgeThresholdHigh());
    uint16_t interferenceDetectionLimit = static_cast<uint16_t>(context.getSettings().filter.getInterferenceDetectionLimit());    

    if(!context.getSettings().filter.isTemporalFilter()){
        temporalFactor = 0;
    }

    if(!context.getSettings().filter.isEdgeFilter()){
        edgeThreshold = 0;
    }

    if(!context.getSettings().filter.isTemporalEdgeFilter()){
        temporalEdgeThresholdLow = 0;
        temporalEdgeThresholdHigh = 0;
    }

    if(!context.getSettings().filter.isInterferenceDetection()){
        interferenceDetectionLimit = 0;
    }

    context.getInterface().setFilter(median, average, temporalFactor, temporalThreshold, edgeThreshold, temporalEdgeThresholdLow, temporalEdgeThresholdHigh, interferenceDetectionLimit, interferenceDetectionUseLastValue);

}

void Controller::onModulationChanged(){

    context.getInterface().setModulation(context.getSettings().getModulation(), context.getSettings().getChannel());
}

void Controller::onBinningChanged()
{
    context.getInterface().setBinning(context.getSettings().binning.isVerticalBinning(), context.getSettings().binning.isHorizontalBinning());
}


//Wrapper function to request the distance from the interface
void Controller::requestDistance(const bool isStream)
{
  if (isStream)
  {
    context.setApplicationState(TypeApplicationState::STATE_STREAM);
  }

  QByteArray userData = context.getSettings().getUserData();
  context.getInterface().requestDistance(isStream, userData);
}
void Controller::requestCam1_Data(const bool isStream)//edit
{
  if (isStream)
  {
    context.setApplicationState(TypeApplicationState::STATE_STREAM);
  }

  QByteArray userData = context.getSettings().getUserData();
  context.getInterface().requestCam1_Data(isStream, userData);
}
void Controller::requestCam2_Data(const bool isStream)
{
  if (isStream)
  {
    context.setApplicationState(TypeApplicationState::STATE_STREAM);
  }

  QByteArray userData = context.getSettings().getUserData();
  context.getInterface().requestCam2_Data(isStream, userData);
}
void Controller::requestCam3_Data(const bool isStream)
{
  if (isStream)
  {
    context.setApplicationState(TypeApplicationState::STATE_STREAM);
  }

  QByteArray userData = context.getSettings().getUserData();
  context.getInterface().requestCam3_Data(isStream, userData);
}
void Controller::requestCam4_Data(const bool isStream)
{
  if (isStream)
  {
    context.setApplicationState(TypeApplicationState::STATE_STREAM);
  }

  QByteArray userData = context.getSettings().getUserData();
  context.getInterface().requestCam4_Data(isStream, userData);
}
void Controller::request_Data_TCP_IP(const bool isStream)
{
  if (isStream)
  {
    context.setApplicationState(TypeApplicationState::STATE_STREAM);
  }

  QByteArray userData = context.getSettings().getUserData();
  context.getInterface().request_Data_TCP_IP(isStream, userData);
}
void Controller::request_Data_UDP_IP(const bool isStream)
{
  if (isStream)
  {
    context.setApplicationState(TypeApplicationState::STATE_STREAM);
  }

  QByteArray userData = context.getSettings().getUserData();
  context.getInterface().request_Data_UDP_IP(isStream, userData);
}
//Wrapper function to request grayscale from the interface
void Controller::requestGrayscale(const bool isStream)
{
  if (isStream)
  {
    context.setApplicationState(TypeApplicationState::STATE_STREAM);
  }

  QByteArray userData = context.getSettings().getUserData();
  context.getInterface().requestGrayscale(isStream, userData);
}

void Controller::requestPointCloudDistance(const bool isStream){
    if (isStream)
    {
        context.setApplicationState(TypeApplicationState::STATE_STREAM);
    }

    QByteArray userData = context.getSettings().getUserData();
    context.getInterface().requestDistance(isStream, userData);
}

void Controller::requestPointCloudDistanceAmplitude(const bool isStream){
    if (isStream)
    {
        context.setApplicationState(TypeApplicationState::STATE_STREAM);
    }

    QByteArray userData = context.getSettings().getUserData();
    context.getInterface().requestDistanceAmplitude(isStream, userData);
}


//Wrapper function to request distance and amplitude from the interface
void Controller::requestDistanceAmplitude(const bool isStream)
{
  if (isStream)
  {
    context.setApplicationState(TypeApplicationState::STATE_STREAM);
  }

  QByteArray userData = context.getSettings().getUserData();
  context.getInterface().requestDistanceAmplitude(isStream, userData);
}

//Wrapper function to stop a stream
void Controller::stopStream()
{
  context.setApplicationState(TypeApplicationState::STATE_CONNECTED);

  QByteArray userData = context.getSettings().getUserData();
  context.getInterface().stopStream(userData);
}

void Controller::calibrate(const bool verifyOnly, const bool offsetOnly, const uint8_t calibrationIndex)
{
  QByteArray userData = context.getSettings().getUserData();
  context.getInterface().calibrate(verifyOnly, offsetOnly, calibrationIndex, userData);
}

void Controller::calibrateProduction()
{
  QByteArray userData = context.getSettings().getUserData();
  context.getInterface().calibrateProduction(userData);
}

//Called on application close
void Controller::close()
{
  context.setApplicationState(TypeApplicationState::STATE_UNCONNECTED);
  context.getInterface().close();
  context.getSettings().save();
}

//Forward the data
void Controller::receivedData(const char *pData, const int length, const bool complete)
{
  //Only use the complete data, no broken images
  if (complete == false)
  {       
    return;
  }

  //This is for the case when the application is connecting to a streaming camera
  if (context.getApplicationState() == TypeApplicationState::STATE_UNCONNECTED)
  {
    context.setApplicationState(TypeApplicationState::STATE_CONNECTED);
    stopStream();
  }

  DataHeader dataHeader(pData, length);

  emit receivedMeasurementData(pData, static_cast<uint>(length), dataHeader);
}

//Forward connected event
void Controller::cmdConnectionConnected()
{
  context.setApplicationState(TypeApplicationState::STATE_CONNECTED);
  sendAllSettingsToCamera();
  emit connected();
}

//Forward disconnected event
void Controller::cmdConnectionDisconnected()
{
  context.setApplicationState(TypeApplicationState::STATE_UNCONNECTED);
  emit disconnected();
}

//Forward error event
void Controller::onError(const uint16_t errorNumber)
{
  context.setApplicationState(TypeApplicationState::STATE_CONNECTED);

  emit error(errorNumber);
}

//Forward updateFps event
void Controller::onFpsUpdate(const unsigned int fps)
{
  emit updateFps(fps);
}

