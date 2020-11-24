/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "WidgetSettingsModulation.h"
#include "ui_widget_settings_modulation.h"
#include <QDebug>


/// \addtogroup WidgetSettingsModulation
/// @{


WidgetSettingsModulation::WidgetSettingsModulation(ApplicationContext &context, QWidget *parent) :
QWidget(parent),
ui(new Ui::WidgetSettingsModulation),
set(context.getSettings())
{
    ui->setupUi(this);
    restoreSettings();
}

WidgetSettingsModulation::~WidgetSettingsModulation(){
    qDebug() << "-----WidgetSettingsModulation destroying";
    delete ui;
    qDebug() << "-----WidgetSettingsModulation destroyed";
}

void WidgetSettingsModulation::restoreSettings()
{
    ui->cmbChannel->setCurrentIndex(set.getChannel());

    if(set.getModulation() == 0) ui->cbModeFrequency->setCurrentIndex(1);
    else if(set.getModulation() == 1) ui->cbModeFrequency->setCurrentIndex(0);
    else ui->cbModeFrequency->setCurrentIndex(set.getModulation());

    ui->cmbChannel->setCurrentIndex(set.getChannel());

    set.setModulation(set.getModulation()); //send modulation to camera
}

void WidgetSettingsModulation::on_cbModeFrequency_currentIndexChanged(int index){

    if(index == 0) set.setModulation(1);
    else if(index == 1) set.setModulation(0);
    else set.setModulation(static_cast<uint8_t>(index));
}


void WidgetSettingsModulation::on_cmbChannel_currentIndexChanged(int index)
{
    set.setChannel(static_cast<uint8_t>(index));
}

/// @}



