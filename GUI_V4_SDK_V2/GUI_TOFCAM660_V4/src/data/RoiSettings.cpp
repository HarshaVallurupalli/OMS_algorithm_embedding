/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "RoiSettings.h"
#include "global/ChipSelection.h"

RoiSettings::RoiSettings()
{
  setDefault();
}

void RoiSettings::setDefault()
{
  x1 = 0;
  x2 = ROI_X_MAX;
  y1 = 0;
  y2 = ROI_Y_MAX;
}

void RoiSettings::setValues(const int x1, const int y1, const int x2, const int y2)
{
  this->x1 = x1;
  this->y1 = y1;
  this->x2 = x2;
  this->y2 = y2;
}

int RoiSettings::getX1() const
{
  return x1;
}

int RoiSettings::getY1() const
{
  return y1;
}

int RoiSettings::getX2() const
{
  return x2;
}

int RoiSettings::getY2() const
{
  return y2;
}

int RoiSettings::getXMax() const
{
  return ROI_X_MAX;
}

int RoiSettings::getYMax() const
{
  return ROI_Y_MAX;
}
