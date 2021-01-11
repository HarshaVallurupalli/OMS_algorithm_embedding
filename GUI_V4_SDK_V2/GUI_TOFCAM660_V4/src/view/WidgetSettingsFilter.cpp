/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/


#include "WidgetSettingsFilter.h"
#include "ui_widget_settings_filter.h"
#include "ApplicationContext.h"
#include "InternalFilterFlags.h"

WidgetSettingsFilter::WidgetSettingsFilter(ApplicationContext &context_, QWidget *parent) :
QWidget(parent),
ui(new Ui::WidgetSettingsFilter),
context(context_)
{        
    ui->setupUi(this);

    connect( &context.getSettings(), &Settings::modulationChanged, this, &WidgetSettingsFilter::modulationChanged);

    restoreSettings();
}

WidgetSettingsFilter::~WidgetSettingsFilter()
{
    delete ui;
}

void WidgetSettingsFilter::restoreSettings()
{
    ui->cbMedianFilter->setChecked(context.getSettings().filter.isMedianFilter());
    ui->cbAverageFilter->setChecked(context.getSettings().filter.isAverageFilter());
    ui->cbTemporalFilter->setChecked(context.getSettings().filter.isTemporalFilter());
    ui->sbFactor->setValue(context.getSettings().filter.getFactor());
    ui->sbThreshold->setValue(context.getSettings().filter.getTemporalThreshold());

    ui->cbEdgeFilter->setChecked(context.getSettings().filter.isEdgeFilter());
    ui->sbEdgeThreshold->setValue(context.getSettings().filter.getEdgeThreshold());

    ui->cbTemporalEdgeFilter->setChecked(context.getSettings().filter.isTemporalEdgeFilter());
    ui->sbTemporalEdgeThresholdLow->setValue(context.getSettings().filter.getTemporalEdgeThresholdLow());
    ui->sbTemporalEdgeThresholdHigh->setValue(context.getSettings().filter.getTemporalEdgeThresholdHigh());

    ui->cbInterferenceDetection->setChecked(context.getSettings().filter.isInterferenceDetection());
    ui->sbInterferenceDetectionLimit->setValue(context.getSettings().filter.getInterferenceDetectionLimit());
    ui->cbUseLastValue->setChecked(context.getSettings().filter.isInterferenceDetectionUseLastValue());

    bool tempFilter = ui->cbTemporalFilter->isChecked();
    ui->lFactor->setVisible(tempFilter);
    ui->sbFactor->setVisible(tempFilter);
    ui->sbThreshold->setVisible(tempFilter);
    ui->lThreshold->setVisible(tempFilter);

    bool edgeFilter = ui->cbEdgeFilter->isChecked();
    ui->lEdgeThreshold->setVisible(edgeFilter);
    ui->sbEdgeThreshold->setVisible(edgeFilter);

    bool temporalEdgeFilter = ui->cbTemporalEdgeFilter->isChecked();
    ui->sbTemporalEdgeThresholdLow->setVisible(temporalEdgeFilter);
    ui->lTemporalEdgeThresholdLow->setVisible(temporalEdgeFilter);
    ui->sbTemporalEdgeThresholdHigh->setVisible(temporalEdgeFilter);
    ui->lTemporalEdgeThresholdHigh->setVisible(temporalEdgeFilter);

    bool interferenceDetection = ui->cbInterferenceDetection->isChecked();
    ui->lLimit->setVisible(interferenceDetection);
    ui->sbInterferenceDetectionLimit->setVisible(interferenceDetection);
    ui->cbUseLastValue->setVisible(interferenceDetection);

    context.getSettings().filter.updateFilter(); //send filter data to camera
    modulationChanged();
}

void WidgetSettingsFilter::on_cbMedianFilter_toggled(bool checked)
{
   context.getSettings().filter.setMedianFilter(checked) ;
}

void WidgetSettingsFilter::on_cbAverageFilter_toggled(bool checked)
{
    context.getSettings().filter.setAverageFilter(checked);
}

void WidgetSettingsFilter::on_cbTemporalFilter_toggled(bool checked)
{
    ui->lFactor->setVisible(checked);
    ui->sbFactor->setVisible(checked);
    ui->sbThreshold->setVisible(checked);
    ui->lThreshold->setVisible(checked);
    context.getSettings().filter.setTemporalFilter(checked);

}

void WidgetSettingsFilter::on_sbFactor_valueChanged(double arg1)
{
    context.getSettings().filter.setFactor(arg1);
}


void WidgetSettingsFilter::on_sbThreshold_valueChanged(int arg1)
{
    context.getSettings().filter.setTemporalThreshold(arg1);
}


void WidgetSettingsFilter::on_cbEdgeFilter_toggled(bool checked)
{
    ui->sbEdgeThreshold->setVisible(checked);
    ui->lEdgeThreshold->setVisible(checked);
    context.getSettings().filter.setEdgeFilter(checked);
}

void WidgetSettingsFilter::on_sbEdgeThreshold_valueChanged(int arg1)
{
    context.getSettings().filter.setEdgeThreshold(arg1);
}


void WidgetSettingsFilter::on_cbTemporalEdgeFilter_toggled(bool checked)
{
    ui->lTemporalEdgeThresholdLow->setVisible(checked);
    ui->sbTemporalEdgeThresholdLow->setVisible(checked);
    ui->lTemporalEdgeThresholdHigh->setVisible(checked);
    ui->sbTemporalEdgeThresholdHigh->setVisible(checked);
    context.getSettings().filter.setTemporalEdgeFilter(checked);
}

void WidgetSettingsFilter::on_cbInterferenceDetection_toggled(bool checked)
{
    ui->lLimit->setVisible(checked);
    ui->sbInterferenceDetectionLimit->setVisible(checked);
    ui->cbUseLastValue->setVisible(checked);
    context.getSettings().filter.setInterferenceDetection(checked);
}

void WidgetSettingsFilter::on_sbTemporalEdgeThresholdLow_valueChanged(int arg1)
{
    context.getSettings().filter.setTemporalEdgeThresholdLow(arg1);
}

void WidgetSettingsFilter::on_sbTemporalEdgeThresholdHigh_valueChanged(int arg1)
{
    context.getSettings().filter.setTemporalEdgeThresholdHigh(arg1);
}

void WidgetSettingsFilter::on_sbInterferenceDetectionLimit_valueChanged(int arg1)
{
    context.getSettings().filter.setInterferenceDetectionLimit(arg1);
}

void WidgetSettingsFilter::on_cbUseLastValue_toggled(bool checked)
{
    context.getSettings().filter.setInterferenceDetectionUseLastValue(checked);
}

void WidgetSettingsFilter::modulationChanged(){

    int index = context.getSettings().getModulation();

    if( index== Settings::ModulationType::MHZ_1_5 || index == Settings::ModulationType::MHZ_0_75){
        ui->sbThreshold->setSuffix("cm");
        ui->sbEdgeThreshold->setSuffix("cm");
        ui->sbTemporalEdgeThresholdLow->setSuffix("cm");
        ui->sbTemporalEdgeThresholdHigh->setSuffix("cm");
    } else {
        ui->sbThreshold->setSuffix("mm");
        ui->sbEdgeThreshold->setSuffix("mm");
        ui->sbTemporalEdgeThresholdLow->setSuffix("mm");
        ui->sbTemporalEdgeThresholdHigh->setSuffix("mm");
    }

}



