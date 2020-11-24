/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "WidgetSettingsBinning.h"
#include "ui_widget_settings_binning.h"

WidgetSettingsBinning::WidgetSettingsBinning(ApplicationContext &context_, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetSettingsBinning),
    context(context_)
{
    ui->setupUi(this);
    restoreSettings();
}

WidgetSettingsBinning::~WidgetSettingsBinning()
{
    delete ui;
}

void WidgetSettingsBinning::restoreSettings()
{
    ui->cbVerticalBinning->setChecked(context.getSettings().binning.isVerticalBinning());
    ui->cbHorizontalBinning->setChecked(context.getSettings().binning.isHorizontalBinning());
}

void WidgetSettingsBinning::on_cbVerticalBinning_toggled(bool checked)
{
    context.getSettings().binning.setVerticalBinning(checked);
}

void WidgetSettingsBinning::on_cbHorizontalBinning_toggled(bool checked)
{
    context.getSettings().binning.setHorizontalBinning(checked);
}
