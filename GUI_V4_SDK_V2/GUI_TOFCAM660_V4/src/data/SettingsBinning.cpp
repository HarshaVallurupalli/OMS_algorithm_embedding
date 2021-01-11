/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "SettingsBinning.h"

SettingsBinning::SettingsBinning(QObject *parent) : QObject(parent)
{
    vertical = false;
    horizontal = false;

}

void SettingsBinning::setVerticalBinning(const bool state)
{
    vertical = state;
    emit binningChanged();
}

void SettingsBinning::setHorizontalBinning(const bool state)
{
    horizontal = state;
    emit binningChanged();
}

bool SettingsBinning::isVerticalBinning() const
{
    return vertical;
}

bool SettingsBinning::isHorizontalBinning() const
{
    return horizontal;
}
