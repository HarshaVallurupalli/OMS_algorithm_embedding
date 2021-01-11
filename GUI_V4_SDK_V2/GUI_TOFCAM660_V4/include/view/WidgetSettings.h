/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef WIDGETSETTINGS_H
#define WIDGETSETTINGS_H

#include <QWidget>
#include "ApplicationContext.h"


namespace Ui {
class WidgetSettings;
}

class WidgetSettings : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetSettings(ApplicationContext &context_, QWidget *parent = nullptr);
    ~WidgetSettings();

private slots:
    void on_lineEditIP_textChanged(const QString &arg1);
    void on_tbApply_clicked();
    void on_lineEditIP_returnPressed();

private:
    Ui::WidgetSettings *ui;
    ApplicationContext &context;
};

#endif // WIDGETSETTINGS_H
