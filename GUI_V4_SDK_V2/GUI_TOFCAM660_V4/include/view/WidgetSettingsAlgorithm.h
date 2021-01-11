/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef WIDGETSETTINGSALGORITHM_H
#define WIDGETSETTINGSALGORITHM_H

#include "ApplicationContext.h"
#include <QWidget>

namespace Ui {
class WidgetSettingsAlgorithm;
}

class WidgetSettingsAlgorithm : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetSettingsAlgorithm(ApplicationContext &context_, QWidget *parent = nullptr);
    ~WidgetSettingsAlgorithm();
    void restoreSettings();

private slots:
    void on_cbSkeletonDetectionAlgorithm_toggled(bool checked);
    void on_cbMovementDetectionAlgorithm_toggled(bool checked);

    void on_sbMDAWindowSize_valueChanged(int arg1);
    void on_comboboxMDAImageType_currentIndexChanged(int index);


private:
    Ui::WidgetSettingsAlgorithm *ui;
    ApplicationContext &context;

};

#endif // WIDGETSETTINGSFILTER_H
