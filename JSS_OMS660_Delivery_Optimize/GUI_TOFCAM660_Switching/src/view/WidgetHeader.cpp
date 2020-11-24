/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "WidgetHeader.h"
#include "ui_widget_header.h"

WidgetHeader::WidgetHeader(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetHeader)
{
    ui->setupUi(this);
}

WidgetHeader::~WidgetHeader()
{
  delete ui;
}

void WidgetHeader::showHeaderData(DataHeader &dataHeader)
{
  ui->textInfo->clear();
  ui->textInfo->append("version: " + QString::number(dataHeader.version));
  ui->textInfo->append("dataType: " + QString::number(dataHeader.dataType));
  ui->textInfo->append("width: " + QString::number(dataHeader.width));
  ui->textInfo->append("height: " + QString::number(dataHeader.height));
  ui->textInfo->append("roiX0: " + QString::number(dataHeader.roiX0));
  ui->textInfo->append("roiY0: " + QString::number(dataHeader.roiY0));
  ui->textInfo->append("roiX1: " + QString::number(dataHeader.roiX1));
  ui->textInfo->append("roiY1: " + QString::number(dataHeader.roiY1));
  ui->textInfo->append("Int Time 0: " + QString::number(dataHeader.intTime0) + "us");
  ui->textInfo->append("Int Time 1: " + QString::number(dataHeader.intTime1) + "us");
  ui->textInfo->append("Int Time 2: " + QString::number(dataHeader.intTime2) + "us");

  if (dataHeader.userData.length() > 0)
  {
    QString userData = QString(dataHeader.userData);
    ui->textInfo->append("User Data: " + userData);
  }
}
