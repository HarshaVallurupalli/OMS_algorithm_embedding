/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef WIDGET_SETTINGS_MODULATION_H
#define WIDGET_SETTINGS_MODULATION_H

#include "ApplicationContext.h"
#include <Settings.h>
#include <QWidget>

namespace Ui {
class WidgetSettingsModulation;
}

/// \addtogroup WidgetSettingsModulation
/// @{

class WidgetSettingsModulation : public QWidget {
    Q_OBJECT
public:
    explicit WidgetSettingsModulation(ApplicationContext &context, QWidget *parent = nullptr);
    ~WidgetSettingsModulation();
    void restoreSettings();

private slots:
    void on_cbModeFrequency_currentIndexChanged(int index);    
    void on_cmbChannel_currentIndexChanged(int index);

private:
    Ui::WidgetSettingsModulation *ui;
    Settings &set;   
};

/// @}

#endif // WIDGET_SETTINGS_MODULATION_H_
