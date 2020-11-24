/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef WIDGETSETTINGSBINNING_H
#define WIDGETSETTINGSBINNING_H

#include <QWidget>
#include "ApplicationContext.h"

namespace Ui {
class WidgetSettingsBinning;
}

class WidgetSettingsBinning : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetSettingsBinning(ApplicationContext &context_, QWidget *parent = nullptr);
    ~WidgetSettingsBinning();
    void restoreSettings();

private slots:
    void on_cbVerticalBinning_toggled(bool checked);
    void on_cbHorizontalBinning_toggled(bool checked);

private:
    Ui::WidgetSettingsBinning *ui;
    ApplicationContext &context;
};

#endif // WIDGETSETTINGSBINNING_H
