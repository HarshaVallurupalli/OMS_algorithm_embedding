/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef WINDOW_CONTROLS_H_
#define WINDOW_CONTROLS_H_

#include <QMainWindow>

namespace Ui {
class WindowControls;
}

class WindowControls : public QMainWindow {
    Q_OBJECT
public:
    explicit WindowControls(QWidget *parent = nullptr);
    ~WindowControls();

private:
    Ui::WindowControls *ui;
};

#endif // WINDOW_CONTROLS_H_
