/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef APPLICATIONCONTEXT_H
#define APPLICATIONCONTEXT_H

#include <QObject>
#include "Settings.h"
#include "Interface.h"
#include "TypeApplicationState.h"
#include "MultiPixelStatistics.h"
#include "KeyHandler.h"
#include "IoControl.h"


class ApplicationContext: public QObject
{
  Q_OBJECT

  public:
    ApplicationContext();
    Settings &getSettings();
    Interface &getInterface();
    void setApplicationState(const TypeApplicationState state);
    TypeApplicationState getApplicationState() const;
    MultiPixelStatistics &getMultiPixelStatistics(){return multiPixelStatistics;}
    KeyHandler &getKeyHandler();
    IoControl &getIoControl();
    bool isStreaming() const;

  signals:
    void stateChanged(const TypeApplicationState newState);

  private:
    Settings settings;
    Interface interface;
    TypeApplicationState applicationState;
    MultiPixelStatistics multiPixelStatistics;
    KeyHandler keyHandler;
    IoControl ioControl;
};

#endif // APPLICATIONCONTEXT_H
