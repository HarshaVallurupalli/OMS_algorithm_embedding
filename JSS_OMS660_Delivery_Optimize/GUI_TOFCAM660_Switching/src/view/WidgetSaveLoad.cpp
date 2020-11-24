/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "WidgetSaveLoad.h"
#include "ui_widget_save_load.h"
#include <QFileDialog>

WidgetSaveLoad::WidgetSaveLoad(ApplicationContext &context, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetSaveLoad),
    set(context.getSettings())
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
