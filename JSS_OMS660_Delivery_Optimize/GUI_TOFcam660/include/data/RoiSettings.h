/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef ROI_SETTINGS_H
#define ROI_SETTINGS_H

#include <QSettings>


class RoiSettings
{
  public:
    RoiSettings();
    void setValues(const int x1, const int y1, const int x2, const int y2);
    void setDefault();
    int getX1() const;
    int getY1() const;
    int getX2() const;
    int getY2() const;
    int getXMax() const;
    int getYMax() const;

  private:
    int x1;
    int x2;
    int y1;
    int y2;
};

#endif // ROI_SETTINGS_H
