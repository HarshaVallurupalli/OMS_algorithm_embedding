/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "InterfaceThread.h"

InterfaceThread::InterfaceThread()
{  
}

void InterfaceThread::run()
{
  QThread::run();
}

void InterfaceThread::stopRunning()
{
  quit();
  wait();
}
