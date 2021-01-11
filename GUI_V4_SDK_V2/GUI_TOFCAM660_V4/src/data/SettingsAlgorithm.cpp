/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "SettingsAlgorithm.h"

SettingsAlgorithm::SettingsAlgorithm(QObject *parent) : QObject(parent),
    sdaEnabled(false),
    mdaEnabled(false),
    mdaWindowSize(0),
    mdaImageType(0)
{

}

void SettingsAlgorithm::setSDAEnabled(bool state)
    {
        sdaEnabled = state;
        emit algorithmChanged();
    }

bool SettingsAlgorithm::isSDAEnabled()
    {
        return sdaEnabled;
    }

void SettingsAlgorithm::setMDAEnabled(bool state)
    {
        mdaEnabled = state;
        if(mdaEnabled==false)
            mdaWindowSize=0;
        emit algorithmChanged();
    }
bool SettingsAlgorithm::isMDAEnabled()
    {
        return mdaEnabled;
    }
void SettingsAlgorithm::setMDAWindowSize(int value)
    {
        mdaWindowSize = value;
        emit algorithmChanged();
    }
int SettingsAlgorithm::getMDAWindowSize()
    {
        return mdaWindowSize;
    }
void SettingsAlgorithm::setMDAImageType(int value)
{
    mdaImageType = value;
    emit algorithmChanged();
}
int SettingsAlgorithm::getMDAImageType()
{
    return mdaImageType;
}

void SettingsAlgorithm::updateAlgorithm()
{
    emit algorithmChanged();
}
