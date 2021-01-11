/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef WIDGET_POINT_CLOUD_SETTINGS_H
#define WIDGET_POINT_CLOUD_SETTINGS_H

#include "Settings.h"
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
    explicit WidgetPointCloudSettings(Settings& set_, QWidget *parent = nullptr);
    ~WidgetPointCloudSettings();
    void restoreSettings();

signals:
    void updateControlls(transform_e type);


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
    void on_sbLensAngle_valueChanged(int arg1);

private:
    Ui::WidgetPointCloudSettings *ui;
    Settings &set;
};

#endif // WIDGET_POINT_CLOUD_SETTINGS_H
