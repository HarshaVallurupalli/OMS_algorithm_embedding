/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef DEBUGMODE_H
#define DEBUGMODE_H

#include <QObject>
#include <QTimer>
#include <QKeyEvent>

class KeyHandler: public QObject
{
  Q_OBJECT

  public:
    KeyHandler();
    ~KeyHandler();
    void keyPressEvent(QKeyEvent *event);

  signals:
    void developerModeEnabled();

  private slots:
    void onTimeout();

  private:
    QTimer *timer;
    int counter;
    int index;

};

#endif // DEBUGMODE_H
