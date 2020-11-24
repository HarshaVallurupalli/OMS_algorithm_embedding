/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef TYPEAPPLICATIONSTATE_H
#define TYPEAPPLICATIONSTATE_H

enum TypeApplicationState
{
  STATE_UNCONNECTED,
  STATE_CONNECTED,
  STATE_STREAM,  
  STATE_CALIBRATION,
  STATE_CALIBRATION_SYSTEM_OFFSET
};

#endif // TYPEAPPLICATIONSTATE_H
