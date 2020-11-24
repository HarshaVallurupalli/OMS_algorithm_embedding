/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "WidgetRoi.h"
#include "ui_widget_roi.h"
#include <QLineEdit>
#include <QDebug>
#include <QPainter>
#include "MeasurementType.h"
#include "RoiSettings.h"

WidgetSettingsROI::WidgetSettingsROI(ApplicationContext &context, QWidget *parent) :
QWidget(parent),
ui(new Ui::WidgetSettingsROI),
context(context)
{
  ui->setupUi(this);
  ui->sbTopLeftX->setMaximum(context.getSettings().getRoiSettings().getXMax());
  ui->sbTopLeftY->setMaximum(context.getSettings().getRoiSettings().getYMax());
  ui->sbBottomRightX->setMaximum(context.getSettings().getRoiSettings().getXMax());
  ui->sbBottomRightY->setMaximum(context.getSettings().getRoiSettings().getYMax());

  updateYFlag = false;

  //ROI update
  connect(&context.getSettings(), &Settings::roiChanged, this, &WidgetSettingsROI::onRoiChanged);
  connect(&context.getSettings(), &Settings::roiChanged, &context.getInterface(), &Interface::setRoi);

  //Settings update
  connect(&context.getSettings(), &Settings::settingsChanged, this, &WidgetSettingsROI::onSettingsChanged);

  RoiSettings roi = context.getSettings().getRoiSettings();
  context.getSettings().setRoi(roi.getX1(), roi.getY1(), roi.getX2(), roi.getY2());
}

WidgetSettingsROI::~WidgetSettingsROI()
{
  qDebug() << "-----WidgetSettingsROI destroying";
  delete ui;
  qDebug() << "-----WidgetSettingsROI destroyed";
}

void WidgetSettingsROI::restoreSettings()
{
    Settings& set = context.getSettings();
    onRoiChanged(set.getRoiSettings().getX1(), set.getRoiSettings().getY1(), set.getRoiSettings().getX2(), set.getRoiSettings().getY2());
}

void WidgetSettingsROI::on_sbTopLeftX_valueChanged()
{
    int x = ui->sbTopLeftX->value();

    if(ui->sbBottomRightX->value() - x < 2)
        ui->sbTopLeftX->setValue(context.getSettings().getRoiSettings().getX1());
    else
        context.getSettings().setRoi(ui->sbTopLeftX->value(), ui->sbTopLeftY->value(), ui->sbBottomRightX->value(), ui->sbBottomRightY->value());
}

void WidgetSettingsROI::on_sbBottomRightX_valueChanged()
{
    int x = ui->sbBottomRightX->value();

    if(x - ui->sbTopLeftX->value() < 2)
        ui->sbBottomRightX->setValue(context.getSettings().getRoiSettings().getX2());
    else
        context.getSettings().setRoi(ui->sbTopLeftX->value(), ui->sbTopLeftY->value(), ui->sbBottomRightX->value(), ui->sbBottomRightY->value());
}

void WidgetSettingsROI::on_sbTopLeftY_valueChanged()
{
  int y = ui->sbBottomRightY->value();

  if(updateYFlag){
    updateYFlag =false;
  }else{
    y = 239 - ui->sbTopLeftY->value();
    updateYFlag =true;
  }

  context.getSettings().setRoi(ui->sbTopLeftX->value(), ui->sbTopLeftY->value(), ui->sbBottomRightX->value(), y );
}

void WidgetSettingsROI::on_sbBottomRightY_valueChanged()
{
  int y = ui->sbTopLeftY->value();

  if(updateYFlag){
    updateYFlag = false;
  }else{
    y = 239 - ui->sbBottomRightY->value();
    updateYFlag = true;
  }

  context.getSettings().setRoi(ui->sbTopLeftX->value(), y, ui->sbBottomRightX->value(), ui->sbBottomRightY->value());
}

void WidgetSettingsROI::on_tbDefaultROI_clicked()
{
  context.getSettings().setRoiDefault();
}

void WidgetSettingsROI::onRoiChanged(const int x1, const int y1, const int x2, const int y2)
{
  ui->sbTopLeftX->setValue(x1);
  ui->sbTopLeftY->setValue(y1);
  ui->sbBottomRightX->setValue(x2);
  ui->sbBottomRightY->setValue(y2);
}

void WidgetSettingsROI::setControlsEnabled(const bool enabled)
{
  ui->sbTopLeftX->setEnabled(enabled);
  ui->sbTopLeftY->setEnabled(enabled);
  ui->sbBottomRightX->setEnabled(enabled);
  ui->sbBottomRightY->setEnabled(enabled);
  ui->tbDefaultROI->setEnabled(enabled);
}

void WidgetSettingsROI::onSettingsChanged()
{
  switch(context.getSettings().getMeasurementType())
  {
    case MeasurementType_e::MEASUREMENT_TYPE_DISTANCE:      
      setControlsEnabled(true);
      break;
    case MeasurementType_e::MEASUREMENT_TYPE_DISTANCE_AMPLITUDE:
      setControlsEnabled(true);
      break;
    case MeasurementType_e::MEASUREMENT_TYPE_GRAYSCALE:
      setControlsEnabled(true);
      break;
    case MeasurementType_e::MEASUREMENT_TYPE_DISTANCE_GRAYSCALE:
      break;
  }


}

















