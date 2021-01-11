/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef WIDGETIMAGE_H
#define WIDGETIMAGE_H

#include <QWidget>
#include "ApplicationContext.h"
#include "Controller.h"
#include "WidgetSettingsFilter.h"
#include "WidgetSettingsAlgorithm.h"
#include "WidgetSettingsModulation.h"
#include "WidgetSettingsBase.h"
#include "WidgetSettingsBinning.h"
#include "WidgetRoi.h"

namespace Ui {
class WidgetImage;
}

class WidgetImage: public QWidget
{
  Q_OBJECT

  public:
    explicit WidgetImage(ApplicationContext &context, Controller &controller, QWidget *parent = nullptr);
    ~WidgetImage();
    void restoreSettings();

  private slots:
    void on_pushButtonSingle_clicked();
    void on_pushButtonStream_clicked();
    void on_comboBoxImageType_currentIndexChanged(int index);
    void on_comboBoxCameraNumber_currentIndexChanged(int index);//edit
    void on_comboBoxStreamConnectionType_currentIndexChanged(int index);
    void onStateChange();
    void on_cbRecord_toggled(bool checked);
    void on_cbDisplay_toggled(bool checked);
    void recordClicked(bool state);
    void streamModeChanged(int state);
    void indexViewChanged(int index);
    void indexCameraChanged(int index);//edit
    void indexStreamConnectionTypeChanged(int index);//edit
    void on_cbPixelInfo_toggled(bool checked);
    void on_cbPixelScope_toggled(bool checked);
    void on_cbTimeScope_toggled(bool checked);
    void on_cbDataToDifferentIP_toggled(bool checked);
    void onSelectionPixelInfoChanged(bool state);
    void onSelectionPixelScopeChanged(bool state);
    void onSelectionTimeScopeChanged(bool state);

signals:
    void updatePlayList();
    void currentIndexChanged(int index);
    void cameraIPAddressChanged();

private:
    void requestData(const bool isStream);
    void changeImageType();
    void CameraSelect(const bool isStream); //edit
    void changeCameraNumber();
    void StreamConnectionSelect(const bool isStream); //edit
    void changeStreamConnectionType();
    ApplicationContext &context;
    Controller &controller;
    Ui::WidgetImage *ui;
    WidgetSettingsBase   *widgetSettingsBase;
    WidgetSettingsFilter *widgetSettingsFilter;
    WidgetSettingsAlgorithm *widgetSettingsAlgorithm;
    WidgetSettingsModulation *widgetSettingsModulation;
    WidgetSettingsROI* widgetSettingsROI;
    WidgetSettingsBinning* widgetSettingsBinning;
};

#endif // WIDGETIMAGE_H
