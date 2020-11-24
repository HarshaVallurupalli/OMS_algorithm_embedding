/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "KeyHandler.h"

//Word to enable debugger mode
static const QString MAGIC_WORD = "ESPROS";

KeyHandler::KeyHandler()
{
  timer = new QTimer();
  counter = 0;
  index = 0;

  connect(timer, &QTimer::timeout, this, &KeyHandler::onTimeout);
}

KeyHandler::~KeyHandler()
{
  delete timer;
}

void KeyHandler::onTimeout()
{
  index = 0;
  timer->stop();
}

void KeyHandler::keyPressEvent(QKeyEvent *event)
{
  if ((index < MAGIC_WORD.length()) && (event->key() == MAGIC_WORD.toLocal8Bit().at(index)))
  {
    if (index == 0)
    {
      timer->start(5000);
    }

    index++;
    if (index >= MAGIC_WORD.length())
    {
      timer->stop();
      emit developerModeEnabled();
    }
  }
  else
  {
    index = 0;
    timer->stop();
  }
}
