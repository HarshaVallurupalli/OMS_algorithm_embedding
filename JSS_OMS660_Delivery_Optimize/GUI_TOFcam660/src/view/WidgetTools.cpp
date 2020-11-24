/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "WidgetTools.h"
#include "ui_widget_tools.h"

WidgetTools::WidgetTools(ApplicationContext &context, QWidget *parent):
    QWidget(parent),
    context(context),
    ui(new Ui::WidgetTools)
{
  ui->setupUi(this);

  connect(ui->textEditUserDataToSend, static_cast<void (QTextEdit::*)()>(&QTextEdit::textChanged), this, &WidgetTools::onUserDataChanged);

  onRestoreSettings();
}

WidgetTools::~WidgetTools()
{
  delete ui;
}

void WidgetTools::onUserDataChanged()
{
  QByteArray userData = ui->textEditUserDataToSend->toPlainText().toLocal8Bit();
  context.getSettings().setUserData(userData);
}

void WidgetTools::onRestoreSettings()
{
  QString string(context.getSettings().getUserData());
  ui->textEditUserDataToSend->setText(string);
}

void WidgetTools::updateHeaderData(DataHeader &dataHeader)
{
  ui->widgetHeaderData->showHeaderData(dataHeader);
}
