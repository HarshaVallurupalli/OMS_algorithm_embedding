/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "IoControl.h"
#include <QProcess>
#include <QDebug>
#include <QApplication>


/**
 * @brief Enable or disable the ambient light for the calibration
 *
 * This is used only if the camera sends a special character pattern in the trace to control
 * the illumination via the GUI.
 *
 * Here just two batch files are started if they are present. They must be placed in the GUI folder.
 * All the commands needed to turn on/off the illumination must be placed in these batch files.
 *
 * Remark: Works only on Windows
 *
 * @param enabled Enable or disable the ambient light
 * @retval true Ambient light enabled or disabled
 * @retval false Nothing done
 * @return Ambient light enabled/disabled or not
 */
bool IoControl::setAmbientLightCalibrationLight(const bool enabled)
{
  QProcess process;
  QString fileString;

  if (enabled)
  {
    fileString = "AmbientLightIlluminationOn.bat";
  }
  else
  {
    fileString = "AmbientLightIlluminationOff.bat";
  }

  int status = process.execute("cmd.exe", {"/C" + qApp->applicationDirPath() + "/" + fileString});

  if (status == 0)
  {
    return true;
  }

  return false;
}
