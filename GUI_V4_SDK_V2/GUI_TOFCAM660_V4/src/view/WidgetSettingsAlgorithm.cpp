/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/


#include "WidgetSettingsAlgorithm.h"
#include "ui_widget_settings_algorithm.h"
#include "ApplicationContext.h"
#include <QWidget>


WidgetSettingsAlgorithm::WidgetSettingsAlgorithm(ApplicationContext &context_, QWidget *parent) :
QWidget(parent),
ui(new Ui::WidgetSettingsAlgorithm),
context(context_)
{        
    ui->setupUi(this);

    restoreSettings();
}

WidgetSettingsAlgorithm::~WidgetSettingsAlgorithm()
{
    delete ui;
}

void WidgetSettingsAlgorithm::restoreSettings()
{
    //restore Skeleton Detection Settings
    ui->cbSkeletonDetectionAlgorithm->setChecked(context.getSettings().algorithm.isSDAEnabled());

    ui->cbMovementDetectionAlgorithm->setChecked(context.getSettings().algorithm.isMDAEnabled());
    ui->sbMDAWindowSize->setValue(context.getSettings().algorithm.getMDAWindowSize());
    ui->comboboxMDAImageType->setCurrentIndex(context.getSettings().algorithm.getMDAImageType());
    
     bool movementDetection = ui->cbMovementDetectionAlgorithm->isChecked();
     ui->lMDAWindowSize->setVisible(movementDetection);
     ui->sbMDAWindowSize->setVisible(movementDetection);
     ui->lMDAImageType->setVisible(movementDetection);
     ui->comboboxMDAImageType->setVisible(movementDetection);

}
void WidgetSettingsAlgorithm::on_cbSkeletonDetectionAlgorithm_toggled(bool checked)
{
    context.getSettings().algorithm.setSDAEnabled(checked);
}
void WidgetSettingsAlgorithm::on_cbMovementDetectionAlgorithm_toggled(bool checked)
{
    ui->lMDAWindowSize->setVisible(checked);
    ui->sbMDAWindowSize->setVisible(checked);
    ui->lMDAImageType->setVisible(checked);
    ui->comboboxMDAImageType->setVisible(checked);
    context.getSettings().algorithm.setMDAEnabled(checked);
}
void WidgetSettingsAlgorithm::on_sbMDAWindowSize_valueChanged(int arg1)
{
    context.getSettings().algorithm.setMDAWindowSize(arg1);
}
void WidgetSettingsAlgorithm::on_comboboxMDAImageType_currentIndexChanged(int index)
{
    context.getSettings().algorithm.setMDAImageType(static_cast<uint8_t>(index));

}
