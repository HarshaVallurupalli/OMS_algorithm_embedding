/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "WidgetSettingsBase.h"
#include "ui_widget_settings_base.h"

WidgetSettingsBase::WidgetSettingsBase(ApplicationContext &context_, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetSettingsBase),
    context(context_)
{
    ui->setupUi(this);

    unsigned int maxIntTime0 = context.getSettings().getMaxIntegrationTime0();
    unsigned int maxIntTime1 = context.getSettings().getMaxIntegrationTime1();

    ui->spinBoxIntTime0->setMaximum(maxIntTime0);
    ui->spinBoxIntTime1->setMaximum(maxIntTime1);

    //Signals from the GUI elements to the settings
    connect(ui->spinBoxIntTime0, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), &context.getSettings(), &Settings::setIntegrationTime0);
    connect(ui->spinBoxIntTime1, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), &context.getSettings(), &Settings::setIntegrationTime1);
    connect(ui->spinBoxIntTimeGrayscale, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), &context.getSettings(), &Settings::setIntegrationTimeGrayscale);
    connect(ui->spinBoxOffset, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), &context.getSettings(), &Settings::setOffset);
    connect(ui->spinBoxMinAmplitude, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), &context.getSettings(), &Settings::setMinAmplitude);
    connect(ui->spinBoxRangeMax, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), &context.getSettings(), &Settings::setRangeMax);
    connect(ui->spinBoxRangeMin, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), &context.getSettings(), &Settings::setRangeMin);
    connect( &context.getSettings(), &Settings::modulationChanged, this, &WidgetSettingsBase::modulationChanged);

    restoreSettings();
}

WidgetSettingsBase::~WidgetSettingsBase()
{
    delete ui;
}


void WidgetSettingsBase::restoreSettings()
{
  if(context.getSettings().getIntegrationTime0() > context.getSettings().getMaxIntegrationTime0())
      context.getSettings().setIntegrationTime0(context.getSettings().getMaxIntegrationTime0());

  if(context.getSettings().getIntegrationTime1() > context.getSettings().getMaxIntegrationTime1())
      context.getSettings().setIntegrationTime1(context.getSettings().getMaxIntegrationTime1());

  ui->spinBoxIntTime0->setValue(context.getSettings().getIntegrationTime0());
  ui->spinBoxIntTime1->setValue(context.getSettings().getIntegrationTime1());
  ui->spinBoxIntTimeGrayscale->setValue(context.getSettings().getIntegrationTimeGrayscale());
  ui->spinBoxOffset->setValue(context.getSettings().getOffset());
  ui->spinBoxMinAmplitude->setValue(context.getSettings().getMinAmplitude());
  ui->spinBoxRangeMax->setValue(context.getSettings().getRangeMax());
  ui->spinBoxRangeMin->setValue(context.getSettings().getRangeMin());

  modulationChanged();

}

void WidgetSettingsBase::modulationChanged(){

    int index = context.getSettings().getModulation();

    if(index == Settings::ModulationType::MHZ_1_5 || index == Settings::ModulationType::MHZ_0_75){
        ui->spinBoxOffset->setSuffix("cm");
        ui->spinBoxRangeMin->setSuffix("cm");
        ui->spinBoxRangeMax->setSuffix("cm");
    } else {
        ui->spinBoxOffset->setSuffix("mm");
        ui->spinBoxRangeMin->setSuffix("mm");
        ui->spinBoxRangeMax->setSuffix("mm");
    }

}

