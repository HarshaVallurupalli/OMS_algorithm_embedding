/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef WIDGETCALIBRATION_H
#define WIDGETCALIBRATION_H

#include <QWidget>
#include "ApplicationContext.h"
#include "DataHeader.h"
#include "Controller.h"

namespace Ui {
class WidgetCalibration;
}

class WidgetCalibration: public QWidget
{
  Q_OBJECT

  public:
    explicit WidgetCalibration(ApplicationContext &context, Controller &controller, QWidget *parent = nullptr);
    ~WidgetCalibration();

  private slots:
    void onStateChange();
    void onPushButtonCalibrationClicked();
    void onPushButtonProductionCalibrationClicked();    
    void onTraceReceived(const QString text);
    void sendDebugCommand(QString text, const unsigned int command);

private:
    ApplicationContext &context;
    Controller &controller;
    Ui::WidgetCalibration *ui;
};

#endif // WIDGETCALIBRATION_H
