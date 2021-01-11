/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef SETTINGSBINNING_H
#define SETTINGSBINNING_H

#include <QObject>

class SettingsBinning : public QObject
{
    Q_OBJECT
public:
    explicit SettingsBinning(QObject *parent = nullptr);
    void setVerticalBinning(const bool state);
    void setHorizontalBinning(const bool state);
    bool isVerticalBinning() const;
    bool isHorizontalBinning() const;

signals:
    void binningChanged();

public slots:


private:
    bool vertical;
    bool horizontal;

};

#endif // SETTINGSBINNING_H
