/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef WIDGET_POINT_CLOUD_SETTINGS_H
#define WIDGET_POINT_CLOUD_SETTINGS_H

#include "Settings.h"
#include "PlotSurface.h"
#include <QWidget>


typedef enum{
    IDLE = 0,
    VIEWPORT_SHIFT = 1,
    SHIFT = 2,
    ZOOM = 3,
    SCALE = 4,
    ROTATION = 5,
} transform_e;



namespace Ui {
class WidgetPointCloudSettings;
}

class WidgetPointCloudSettings : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetPointCloudSettings(Settings& set, PlotSurface *surfacePlot, QWidget *parent = nullptr);
    ~WidgetPointCloudSettings();
    void initControls();
    void restoreSettings();
    void updateControls();
    void setPerspective(bool state);


signals:
    void updateControlls(transform_e type);
    void grayPointCloudChanged(bool);
    void resetDefaultView();


protected:
    void showEvent(QShowEvent *);
    void closeEvent(QCloseEvent *);

private slots:

    void on_tbAxisColor_clicked();
    void on_tbBackgroundColor_clicked();
    void on_tbGridColor_clicked();
    void on_sbCellWidth_valueChanged(int arg1);
    void on_sbNumCells_valueChanged(int arg1);
    void on_sbdTransparent_valueChanged(double arg1);
    void on_sbOffsetX_valueChanged(int arg1);
    void on_sbOffsetY_valueChanged(int arg1);
    void on_sbOffsetZ_valueChanged(int arg1);
    void on_sbAngleX_valueChanged(int arg1);
    void on_sbAngleY_valueChanged(int arg1);
    void on_sbAngleZ_valueChanged(int arg1);
    void on_tbClose_clicked();

    void on_sbAxisLineWidth_valueChanged(int arg1);
    void on_dbAxisTransparent_valueChanged(double arg1);
    void on_sbAxisOffsetX_valueChanged(int arg1);
    void on_sbAxisOffsetY_valueChanged(int arg1);
    void on_sbAxisOffsetZ_valueChanged(int arg1);
    void on_sbCameraOffesetX_valueChanged(int arg1);
    void on_sbCameraOffesetY_valueChanged(int arg1);
    void vieportShiftChanged(double offsetX, double offsetY);
    void zoomChanged(double zoom);
    void scaleChanged(double, double, double);
    void rotationChanged(double xAngle, double yAngle, double zAngle);
    void shiftChanged(double xShift, double yShift, double zShift);
    void on_dbZoom_valueChanged(double arg1);
    void on_dbScaleX_valueChanged(double arg1);
    void on_dbScaleY_valueChanged(double arg1);
    void on_dbScaleZ_valueChanged(double arg1);
    void on_sbObjectOffsetX_valueChanged(int arg1);
    void on_sbObjectOffsetY_valueChanged(int arg1);
    void on_sbObjectOffsetZ_valueChanged(int arg1);

    void on_rbRectGrid_toggled(bool checked);
    void on_sbAngleObjectZ_valueChanged(int arg1);
    void on_tbLabelColor_clicked();
    void on_cbShowLabels_toggled(bool checked);
    void on_cbShowLegend_toggled(bool checked);
    void on_tbLabelFont_clicked();
    //void on_sbLensAngle_valueChanged(int arg1);

    //void on_cbGrayPointCloud_toggled(bool checked);
    void on_cbSurfaceInterconnect_toggled(bool checked);
    void on_cbPoints_toggled(bool checked);
    void on_sbSurfaceInterconnect_valueChanged(int arg1);
    void on_dbPointSize_valueChanged(double arg1);
    void on_cbAxis2D_toggled(bool checked);
    void on_cbAxis3D_toggled(bool checked);
    void on_cbGrid_toggled(bool checked);
    void on_cbPerspectiveView_toggled(bool checked);
    void on_cbCartesian_toggled(bool checked);
    void on_cbUndistortion_toggled(bool checked);

    void on_sbSensorOffsetX_valueChanged(int arg1);
    void on_sbSensorOffsetY_valueChanged(int arg1);    
    void on_rbWideField_toggled(bool checked);
    void on_rbNarrowField_toggled(bool checked);

    void on_tbSaveDefaultView_clicked();
    void on_tbResetDefaultView_clicked();

private:
    Ui::WidgetPointCloudSettings *ui;
    PlotSurface *surfacePlot;
    Settings &set;
};

#endif // WIDGET_POINT_CLOUD_SETTINGS_H
