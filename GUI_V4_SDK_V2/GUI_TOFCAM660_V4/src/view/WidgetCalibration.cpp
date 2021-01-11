/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "WidgetCalibration.h"
#include "ui_widget_calibration.h"
#include "QMessageBox"

WidgetCalibration::WidgetCalibration(ApplicationContext &context, Controller &controller, QWidget *parent):
    QWidget(parent),
    context(context),
    controller(controller),
    ui(new Ui::WidgetCalibration)
{
  ui->setupUi(this);

  connect(ui->pushButtonCalibration, static_cast<void (QPushButton::*)(bool)>(&QPushButton::clicked), this, &WidgetCalibration::onPushButtonCalibrationClicked);
  connect(ui->pushButtonProductionCalibration, static_cast<void (QPushButton::*)(bool)>(&QPushButton::clicked), this, &WidgetCalibration::onPushButtonProductionCalibrationClicked);
  connect(ui->pushButtonDebugCommand0, static_cast<void (QPushButton::*)(bool)>(&QPushButton::clicked), this, [this](){sendDebugCommand(ui->lineEditData0->text(), ui->spinBoxCommand0->value()); });
  connect(ui->pushButtonDebugCommand1, static_cast<void (QPushButton::*)(bool)>(&QPushButton::clicked), this, [this](){sendDebugCommand(ui->lineEditData1->text(), ui->spinBoxCommand1->value()); });
  connect(ui->pushButtonDebugCommand2, static_cast<void (QPushButton::*)(bool)>(&QPushButton::clicked), this, [this](){sendDebugCommand(ui->lineEditData2->text(), ui->spinBoxCommand2->value()); });
  connect(ui->pushButtonDebugCommand3, static_cast<void (QPushButton::*)(bool)>(&QPushButton::clicked), this, [this](){sendDebugCommand(ui->lineEditData3->text(), ui->spinBoxCommand3->value()); });

  //Signals from context to this
  connect(&context, &ApplicationContext::stateChanged, this, &WidgetCalibration::onStateChange);

  //Signals from the interface to this
  connect(&context.getInterface(), &Interface::traceReceived, this, &WidgetCalibration::onTraceReceived);

  //For initial state
  onStateChange(); 
}

WidgetCalibration::~WidgetCalibration()
{
  delete ui;
}

void WidgetCalibration::onPushButtonCalibrationClicked()
{
  bool doIt = false;

  //If calibration is selected (and not only verification), show a warning
  if (ui->checkBoxVerifyOnly->isChecked() == false)
  {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Start Calibration", "Put the camera in the calibration box without lens mounted. Current calibration data will be lost.",QMessageBox::Yes|QMessageBox::No);

    if(reply == QMessageBox::Yes)
    {
      doIt = true;
    }
  }
  else
  {
    doIt = true;
  }

  if (doIt)
  {
    controller.calibrate(ui->checkBoxVerifyOnly->isChecked(), ui->checkBoxOffsetOnly->isChecked(), ui->spinBoxIndex->value());
  }
}

void WidgetCalibration::onPushButtonProductionCalibrationClicked()
{
  QMessageBox::StandardButton reply;
  reply = QMessageBox::question(this, "Run Production Calibration", "Put the camera in the calibration box without lens mounted. Current calibration data will be lost.",QMessageBox::Ok|QMessageBox::Cancel);
  if (reply == QMessageBox::Ok)
  {
    controller.calibrateProduction();
  }
}

void WidgetCalibration::onStateChange()
{
  switch(context.getApplicationState())
  {
    case TypeApplicationState::STATE_UNCONNECTED:
      ui->pushButtonCalibration->setEnabled(false);
      ui->pushButtonProductionCalibration->setEnabled(false);
      break;
    case TypeApplicationState::STATE_CONNECTED:
      ui->pushButtonCalibration->setEnabled(true);
      ui->pushButtonProductionCalibration->setEnabled(true);
      break;
    case TypeApplicationState::STATE_STREAM:
      ui->pushButtonCalibration->setEnabled(false);
      ui->pushButtonProductionCalibration->setEnabled(false);
      break;
    case TypeApplicationState::STATE_CALIBRATION:
      ui->pushButtonCalibration->setEnabled(false);
      ui->pushButtonProductionCalibration->setEnabled(false);
      break;
    case TypeApplicationState::STATE_CALIBRATION_SYSTEM_OFFSET:
      ui->pushButtonCalibration->setEnabled(false);
      ui->pushButtonProductionCalibration->setEnabled(false);
      break;
    default:
      ui->pushButtonCalibration->setEnabled(false);
      ui->pushButtonProductionCalibration->setEnabled(false);
      break;
  }
}

void WidgetCalibration::onTraceReceived(const QString text)
{
  QString textToAdd = text;

  //Handle special character patterns. If these characters are in the text, do IO commands.
  if (text.contains("{"))
  {
    bool ok = false;

    //Switch on the ambient light illumination with pattern "{1"
    if (text.contains("{1"))
    {
      ok = context.getIoControl().setAmbientLightCalibrationLight(true);
    }

    //Switch off the ambient light illumination with pattern "{0"
    else if (text.contains("{0"))
    {
      ok = context.getIoControl().setAmbientLightCalibrationLight(false);
    }

    //Add a message if the IO access fails
    if (ok == false)
    {
      textToAdd = "IO Call failed";
    }
    else
    {
      textToAdd = "";
    }
  }

  ui->textEditCalibration->moveCursor (QTextCursor::End);
  ui->textEditCalibration->insertPlainText (textToAdd);
  ui->textEditCalibration->moveCursor (QTextCursor::End);
}

void WidgetCalibration::sendDebugCommand(QString text, const unsigned int command)
{
  text = text.replace("0x", "");
  QByteArray payload = QByteArray::fromHex(text.toUtf8());
  context.getInterface().sendDebugCommand(command, payload);
}
