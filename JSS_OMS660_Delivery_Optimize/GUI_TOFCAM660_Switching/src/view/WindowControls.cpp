/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "WindowControls.h"
#include "ui_window_controls.h"
#include <QPicture>
#include <QDebug>

/// \addtogroup WindowControls
/// @{

WindowControls::WindowControls(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::WindowControls) {
    ui->setupUi(this);
    setAttribute( Qt::WA_QuitOnClose, false );
}

WindowControls::~WindowControls(){
    qDebug() << "---------------WindowControls destroying";
    delete ui;
    qDebug() << "---------------WindowControls destroyed";
}

/// @}
