/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "WidgetSettings.h"
#include "ui_widget_settings.h"

WidgetSettings::WidgetSettings(ApplicationContext &context_, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetSettings),
    context(context_)
{
    ui->setupUi(this);
    QString str = "Data IP address: This computer";
    ui->lCurrentIPAddress->setText(str);
    ui->lineEditIP->setText(context.getSettings().getComputerIp());
}

WidgetSettings::~WidgetSettings()
{
    delete ui;
}

void WidgetSettings::on_lineEditIP_textChanged(const QString &arg1)
{
    context.getSettings().setComputerIp(arg1);
}

void WidgetSettings::on_tbApply_clicked()
{
    QString str;

    if(context.getSettings().getDataDestinationIP()){
        context.getInterface().setDataIPaddress(context.getSettings().getComputerIp());
        str = "Data IP address: " + context.getSettings().getComputerIp();
    }else{
        context.getInterface().setDataIPaddress("0.0.0.0");
        str = "Data IP address: This computer";
    }

    ui->lCurrentIPAddress->setText(str);
}

void WidgetSettings::on_lineEditIP_returnPressed()
{
    ui->tbApply->click();
}
