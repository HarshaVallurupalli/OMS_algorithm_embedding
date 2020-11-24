/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef WIDGET_SETTINGS_ROI_H_
#define WIDGET_SETTINGS_ROI_H_

#include <QDebug>
#include <QWidget>
#include "ApplicationContext.h"

namespace Ui {
class WidgetSettingsROI;
}

class WidgetSettingsROI : public QWidget {
    Q_OBJECT
public:
    explicit WidgetSettingsROI(ApplicationContext &context, QWidget *parent = nullptr);
    ~WidgetSettingsROI();
    void restoreSettings();

private slots:
    void on_sbTopLeftX_valueChanged();
    void on_sbBottomRightX_valueChanged();
    void on_sbTopLeftY_valueChanged();
    void on_sbBottomRightY_valueChanged();

    void on_tbDefaultROI_clicked();
    void onRoiChanged(const int x1, const int y1, const int x2, const int y2);
    void onSettingsChanged();


private:
    void setControlsEnabled(const bool enabled);    
    Ui::WidgetSettingsROI *ui;
    ApplicationContext &context;
    bool updateYFlag;

};

#endif // WIDGET_SETTINGS_ROI_H_
