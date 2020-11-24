/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef WIDGETSAVELOAD_H
#define WIDGETSAVELOAD_H

#include <QWidget>
#include "ApplicationContext.h"
#include "Settings.h"

namespace Ui {
class WidgetSaveLoad;
}

class WidgetSaveLoad : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetSaveLoad(ApplicationContext& context_, QWidget *parent = nullptr);
    ~WidgetSaveLoad();

private slots:
    void on_tbSave_clicked();
    void on_tbLoad_clicked();
    void on_tbUpdateFirmware_clicked();
    void getFirmwareVersion();

private:
    Ui::WidgetSaveLoad *ui;
    Settings &set;
    ApplicationContext& context;
};

#endif // WIDGETSAVELOAD_H
