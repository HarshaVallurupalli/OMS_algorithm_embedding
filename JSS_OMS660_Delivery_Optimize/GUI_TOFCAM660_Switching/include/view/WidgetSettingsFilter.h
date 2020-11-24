/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef WIDGETSETTINGSFILTER_H
#define WIDGETSETTINGSFILTER_H

#include "ApplicationContext.h"
#include <QWidget>

namespace Ui {
class WidgetSettingsFilter;
}

class WidgetSettingsFilter : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetSettingsFilter(ApplicationContext &context_, QWidget *parent = nullptr);
    ~WidgetSettingsFilter();
    void restoreSettings();

private slots:
    void on_cbMedianFilter_toggled(bool checked);
    void on_cbAverageFilter_toggled(bool checked);
    void on_cbTemporalFilter_toggled(bool checked);

    void on_sbFactor_valueChanged(double arg1);
    void on_sbThreshold_valueChanged(int arg1);
    void on_cbEdgeFilter_toggled(bool checked);
    void on_sbEdgeThreshold_valueChanged(int arg1);

    void on_cbTemporalEdgeFilter_toggled(bool checked);
    void on_cbInterferenceDetection_toggled(bool checked);
    void on_sbTemporalEdgeThresholdLow_valueChanged(int arg1);
    void on_sbTemporalEdgeThresholdHigh_valueChanged(int arg1);
    void on_sbInterferenceDetectionLimit_valueChanged(int arg1);    
    void on_cbUseLastValue_toggled(bool checked);
    void modulationChanged();


private:
    Ui::WidgetSettingsFilter *ui;
    ApplicationContext &context;

};

#endif // WIDGETSETTINGSFILTER_H
