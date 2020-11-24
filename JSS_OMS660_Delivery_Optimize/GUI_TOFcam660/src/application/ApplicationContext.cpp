/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "ApplicationContext.h"

ApplicationContext::ApplicationContext():
multiPixelStatistics(settings.getTimeScopeSelection())
{
  applicationState = TypeApplicationState::STATE_UNCONNECTED;
}

Settings &ApplicationContext::getSettings()
{
  return settings;
}

Interface &ApplicationContext::getInterface()
{
  return interface;
}

KeyHandler &ApplicationContext::getKeyHandler()
{
  return keyHandler;
}

 IoControl &ApplicationContext::getIoControl()
 {
   return ioControl;
 }

TypeApplicationState ApplicationContext::getApplicationState() const
{
  return applicationState;
}

void ApplicationContext::setApplicationState(const TypeApplicationState state)
{
  applicationState = state;
  emit stateChanged(applicationState);
}

bool ApplicationContext::isStreaming() const
{
  if (applicationState == TypeApplicationState::STATE_STREAM)
  {
    return true;
  }

  return false;
}
