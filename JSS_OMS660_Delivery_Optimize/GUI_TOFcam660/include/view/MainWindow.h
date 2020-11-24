/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "DataConnection.h"
#include "CmdConnection.h"
#include "ImageColorizer.h"
#include "DataHeader.h"
#include <QSettings>
#include <QStorageInfo>
#include <Settings.h>
#include "WidgetTools.h"
#include "WidgetImage.h"
#include "WidgetCalibration.h"
#include "WidgetData.h"
#include "WidgetPointCloud.h"
#include "WidgetSaveLoad.h"
#include "WidgetSettings.h"
#include "WidgetPlay.h"
#include "Controller.h"
#include "KeyHandler.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(ApplicationContext &context, QWidget *parent = nullptr);
  ~MainWindow();

signals:
  void showData(const char *pData, DataHeader &dataHeader);
  void getFirmwareVersion();

private slots:
  void restoreSettings();
  void receivedMeasurementData(const char *pData, uint length, DataHeader &dataHeader);
  void onError(const uint16_t errorNumber);
  void updateFps(const unsigned int fps);
  void onStateChange();
  void onDeveloperModeEnabled();
  void onPushButtonLogoClicked();
  void on_actionView_triggered();
  void on_actionCalibration_triggered();
  void on_actionTools_triggered();
  void on_actionPlay_triggered();
  void on_actionSettings_triggered();
  void on_actionSave_Load_triggered();
  void receivedFirmwareRelease(const int major, const int minor);
  void receivedChipInfo(const int waferID, const int ChipID);
  void showSystemInfo();

protected:
  void closeEvent (QCloseEvent *event  __attribute__((unused)));
  void moveEvent(QMoveEvent*);
  void resizeEvent(QResizeEvent*);

private:

  void keyPressEvent(QKeyEvent *event);
  void showDistanceAmplitude(const char *pData, DataHeader &dataHeader);
  void showDistance(const char *pData, DataHeader &dataHeader);
  void showGrayscale(const char *pData, DataHeader &dataHeader);

  Ui::MainWindow *ui;
  int debugCounter;
  QLabel *labelStatus;  
  ApplicationContext &context;
  WidgetTools *widgetMetaData;
  WidgetImage *widgetImage;
  WidgetPlay  *widgetPlay;
  WidgetCalibration *widgetCalibration;
  WidgetData* widgetData;
  WidgetPointCloud *widgetPointCloud;
  WidgetSettings* widgetSettings;
  WidgetSaveLoad* widgetSaveLoad;
  Controller controller; 
  QStorageInfo storage;  
};

#endif // MAINWINDOW_H
