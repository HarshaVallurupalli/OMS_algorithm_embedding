/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef INTERFACE_THREAD_H
#define INTERFACE_THREAD_H

#include <QThread>

class InterfaceThread: public QThread
{
  Q_OBJECT

public:
    InterfaceThread();
    void stopRunning();

private:
  void run();
};

#endif // INTERFACE_THREAD_H
