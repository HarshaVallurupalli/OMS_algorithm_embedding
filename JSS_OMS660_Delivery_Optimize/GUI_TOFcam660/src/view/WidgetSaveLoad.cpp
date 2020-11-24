/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "WidgetSaveLoad.h"
#include "ui_widget_save_load.h"
#include <QFileDialog>
#include <QMessageBox>

WidgetSaveLoad::WidgetSaveLoad(ApplicationContext &context_, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetSaveLoad),
    set(context_.getSettings()),
    context(context_)
{
    ui->setupUi(this);
}

WidgetSaveLoad::~WidgetSaveLoad()
{
    delete ui;
}

void WidgetSaveLoad::on_tbSave_clicked()
{

    //#ifdef Q_OS_MAC
    //    QString filename = QFileDialog::getSaveFileName(this, tr("Open Configuration"), "Applications/ESPROS_TOF-Imager_Evaluation_Kit_Software_v2.12.14/install/client/mac/preConfig", tr("XML Files (*.xml)"));
    //#else

    QString filename = QFileDialog::getSaveFileName(this, tr("Open Configuration"), "", tr("INI Files (*.ini)"));

    //#endif

    if (!filename.isEmpty()){
        set.setSetupSettingsPath(filename);
        set.save();
        set.setSetupSettingsPath(set.getDefaultSettingsPath());
    }

}

void WidgetSaveLoad::on_tbLoad_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Configuration"), "", tr("INI Files (*.ini)"));

    if (!filename.isEmpty()){
        set.setSetupSettingsPath(filename);
        set.restore();
        set.setSetupSettingsPath(set.getDefaultSettingsPath());
    }


}

void WidgetSaveLoad::on_tbUpdateFirmware_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Configuration"), "./", tr("Binary Files (*.bin)"));
    if (!filename.isEmpty()){
        this->hide();
        QFile file(filename);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox msg;
            msg.setWindowTitle("Error");
            msg.setText("Failed to open the file");            
            msg.exec();
            return;
        }

        QByteArray data = file.readAll();
        file.close();

        context.getInterface().sendFirmwareUpdate(data);

        QTimer timer;
        timer.setSingleShot(true);
        timer.start(2000);

        while(timer.isActive()){
            QCoreApplication::processEvents();
        }

        QMessageBox msg;
        msg.setWindowTitle("Confirmation");
        msg.setText("Firmware updated.\nPlease restart camera and GUI.");
        msg.exec();


    }
}

void WidgetSaveLoad::getFirmwareVersion()
{
    uint16_t major = context.getSettings().getMajor();
    uint16_t minor = context.getSettings().getMinor();

    if(major < 2 && minor < 6){
        ui->tbUpdateFirmware->setEnabled(false);
    }

}
