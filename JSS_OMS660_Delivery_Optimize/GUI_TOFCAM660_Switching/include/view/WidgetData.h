/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef WIDGETDATA_H
#define WIDGETDATA_H

#include <QWidget>
#include <DataHeader.h>
#include <Settings.h>
#include <ImageColorizer.h>
#include <QLabel>

#include "WidgetPixelScope.h"
#include "WidgetTimeScope.h"
#include "WidgetInfo.h"



//Data TOFCAM-->GUI
typedef enum
{
    TOFCAM_DATA_DISTANCE_AMPLITUDE = 0,
    TOFCAM_DATA_DISTANCE = 1,
    TOFCAM_DATA_AMPLITUDE = 2,
    TOFCAM_DATA_GRAYSCALE = 3
}tofCamData_e;


namespace Ui {
class WidgetData;
}

class WidgetData : public QWidget
{
    Q_OBJECT

  public:
    explicit WidgetData(ApplicationContext &context, QWidget *parent = nullptr);
    ~WidgetData()override;
    void restoreSettings();
    void showDistance(const char *pData, DataHeader &dataHeader);
    void showDistanceAmplitude(const char *pData, DataHeader &dataHeader);
    void showGrayscale(const char *pData, DataHeader &dataHeader);
    void showData(const char *pData, DataHeader &dataHeader);
    void logData(const char *pData, uint length);
    void updateFps(const unsigned int fps);

  private slots:

    void onRoiChanged();
    void onRoiSelected(const int x1, const int x2, const int y1, const int y2);    
    void onMouseHover(const int x, const int y);
    void onMouseOutOfRange();
    void onSelectionPixelInfoChanged();
    void onSelectionPixelScopeChanged();
    void onSelectionTimeScopeChanged();
   // void onCameraSelectionChanged();//edit


    void selectionPixelInfoCleared(bool state);
    void selectionPixelScopeCleared(bool state);
    void selectionTimeScopeCleared(bool state);
    void onDistanceMousePositionChange(const double x, const double y);
    void on_tbFullScreen_clicked();    
    void on_checkBoxMirrorHorizontal_toggled(bool checked);
    void on_checkBoxMirrorVertical_toggled(bool checked);
    void formatChanged();
    void mirrorChanged();
    void on_checkBoxAmplitudeGrayscale_toggled(bool checked);
    void onMouseDoubleClick();
    void on_checkBoxRotate_clicked(bool checked);
    void resetFirstLogFlag();    
    void clearPixelInfo();
    void clearTimeScopeROI();
    void clearPixelScopeLine();
    void deselectAllSelections();
    void on_tbDefaultRoi_clicked();
    void on_tbPixelInfo_toggled(bool checked);
    void on_tbPixelScope_toggled(bool checked);
    void on_tbTimeScope_toggled(bool checked);
    void on_tbRoi_toggled(bool checked);

signals:
    void updateTimeScopeDistance(const char *pData, DataHeader &dataHeader);
    void updateTimeScopeDistanceAmplitude(const char *pData, DataHeader &dataHeader);
    void updateTimeScopeGrayscale(const char *pData, DataHeader &dataHeader);
    void selectedPixelInfo(bool);
    void selectedPixelScope(bool);
    void selectedTimeScope(bool);
    void setRoiDefault();

protected:
    void keyPressEvent(QKeyEvent *e) override;
    void mouseDoubleClickEvent(QMouseEvent* e)override;
    void moveEvent(QMoveEvent *) override;
    void resizeEvent(QResizeEvent *) override;
    void closeEvent(QCloseEvent *) override;

private:
    void updateSelectedPixels(const unsigned int distance, const unsigned int amplitude, const int selectionX, const int selectionY);
    unsigned int calcLog(const unsigned int value);
    void updateImage(QLabel &label, const QImage &image); 
    void updateView(bool fullScreen);        
    void saveDataBin(const char *pData, uint length, QString filePath);
    void saveIndex(QString filePath, QString str);

    Ui::WidgetData *ui;
    Settings &settings;
    Qt::WindowStates lastWndowState;
    ImageColorizer imageColorizerDistance;
    ImageColorizer imageColorizerAmplitude;
    ImageColorizer imageColorizerGrayscale;

    WidgetInfo *widgetInfo;
    WidgetTimeScope *widgetTimeScope;
    WidgetPixelScope *widgetPixelScope;

    bool screen16_9;
    double leftImageSelectionX;
    double leftImageSelectionY;

    QString pathToLoggingDir;
    QString filename;
    QString filenameIdx;
    QString indexFilePath;
    QString indexFilePathCurrent;
    QString indexFilePathLast;
    bool pixelInfoSelected;
    bool pixelScopeSelected;
    bool timeScopeSelected;
    bool firstLogFlag;
    int second;
    int count;

};

#endif // WIDGETDATA_H
