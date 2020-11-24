/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "WidgetPointCloudSettings.h"
#include "ui_widget_point_cloud_settings.h"

#include <QFontDialog>
#include <QColorDialog>
#include <math.h>
#include <QDebug>

WidgetPointCloudSettings::WidgetPointCloudSettings(Settings &set, PlotSurface *surfacePlot, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetPointCloudSettings),
    surfacePlot(surfacePlot),
    set(set)
{
    ui->setupUi(this);
    setWindowFlags ( Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowStaysOnTopHint | Qt::WindowCloseButtonHint);
    ui->tbLabelFont->setVisible(false);
    ui->sbLensAngle->setValue(set.cloud.getFOV());
    ui->sbAxisOffsetX->setVisible(false);
    ui->sbAxisOffsetY->setVisible(false);
    ui->sbAxisOffsetZ->setVisible(false);
    ui->lAxisOffsetX->setVisible(false);
    ui->lAxisOffsetY->setVisible(false);
    ui->lAxisOffsetZ->setVisible(false);
    ui->rbRectGrid->setChecked(true);
    ui->rbRectGrid->setVisible(false);
    ui->rbPolarGrid->setVisible(false);    
    ui->lAxis->setVisible(false);
    ui->lAxisLineWidth->setVisible(false);
    ui->sbAxisLineWidth->setVisible(false);
    ui->lLensAngle->setVisible(false);
    ui->sbLensAngle->setVisible(false);
    ui->cbGrayPointCloud->setVisible(false); //TODO...

    if(set.cloud.getWinWidth()!=0 && set.cloud.getWinHeight()!=0){
        this->setGeometry(set.cloud.getWinPosX(), set.cloud.getWinPosY(), set.cloud.getWinWidth(), set.cloud.getWinHeight());
    }

    //ui->tbSaveDefaultView->setVisible(false);
    //ui->tbResetDefaultView->setVisible(false);
}

WidgetPointCloudSettings::~WidgetPointCloudSettings()
{
    delete ui;
}

void WidgetPointCloudSettings::restoreSettings()
{
    showEvent(nullptr);
    bool isGray = set.cloud.isGrayPointCloud();
    bool isPoints = set.cloud.isPoints();
    bool isPCL = set.cloud.isPCLFilter();

    ui->cbPoints->setChecked(false);
    ui->cbGrayPointCloud->setChecked(!isGray);
    ui->cbGrayPointCloud->setChecked(isGray);

    if(!isGray){
        ui->cbPoints->setChecked(!isPoints);
        ui->cbPoints->setChecked(isPoints);
    }

    if(!isPoints){
        ui->cbSurfaceInterconnect->setChecked(!isPCL);
        ui->cbSurfaceInterconnect->setChecked(isPCL);
    }

    ui->sbSurfaceInterconnect->setValue(set.cloud.getPCLFilterThreshold());

    if(set.cloud.isPCLFilter() && !ui->cbSurfaceInterconnect->isChecked()){
        ui->cbSurfaceInterconnect->setChecked(set.cloud.isPCLFilter());
        if(ui->cbGrayPointCloud->isChecked()==false)
            ui->cbGrayPointCloud->setChecked(true);
    }else{
        ui->cbSurfaceInterconnect->setChecked(false);
    }


    ui->cbGrid->setChecked(set.cloud.isShowGrid());
    ui->cbAxis2D->setChecked(set.cloud.isShowAxis2D());
    ui->cbAxis3D->setChecked(set.cloud.isShowAxis3D());

    ui->cbCartesian->setChecked(set.cloud.isCartesian());
    ui->cbPerspectiveView->setChecked(true);

    ui->sbSensorOffsetX->setValue(set.cloud.getSensorCenterOffsetX());
    ui->sbSensorOffsetY->setValue(set.cloud.getSensorCenterOffsetY());

    set.cloud.setWideField(set.cloud.isWideField()); //update lens parameters
}


void WidgetPointCloudSettings::showEvent(QShowEvent *){

    ui->sbAxisOffsetX->setValue(set.cloud.getAxisOffsetX());
    ui->sbAxisOffsetY->setValue(set.cloud.getAxisOffsetY());
    ui->sbAxisOffsetZ->setValue(set.cloud.getAxisOffsetZ());
    ui->sbAxisLineWidth->setValue(set.cloud.getAxisLineWidth());
    ui->dbAxisTransparent->setValue(set.cloud.getAxisColor().a);

    ui->sbCellWidth->setValue(static_cast<int>(set.cloud.getCellWidth()));
    ui->sbNumCells->setValue(static_cast<int>(set.cloud.getNumberCells()));
    ui->sbdTransparent->setValue(set.cloud.getGridColor().a);

    ui->sbOffsetX->setValue(set.cloud.getGridOffsetX());
    ui->sbOffsetY->setValue(set.cloud.getGridOffsetY());
    ui->sbOffsetZ->setValue(set.cloud.getGridOffsetZ());

    ui->sbObjectOffsetX->setValue(set.cloud.getObjectOffsetX());
    ui->sbObjectOffsetY->setValue(set.cloud.getObjectOffsetY());
    ui->sbObjectOffsetZ->setValue(set.cloud.getObjectOffsetZ());

    ui->dbScaleX->setValue(set.cloud.getScaleX());
    ui->dbScaleY->setValue(set.cloud.getScaleY());
    ui->dbScaleZ->setValue(set.cloud.getScaleZ());


    ui->sbAngleObjectZ->setValue(set.cloud.getAngleObjectZ());
    ui->sbAngleX->setValue(set.cloud.getCameraAngleX());
    ui->sbAngleY->setValue(set.cloud.getCameraAngleY());
    ui->sbAngleZ->setValue(set.cloud.getCameraAngleZ());

    ui->sbCameraOffesetX->setValue(set.cloud.getCameraOffsetX());
    ui->sbCameraOffesetY->setValue(set.cloud.getCameraOffsetY());
    ui->dbZoom->setValue(set.cloud.getCameraZoom());

    if(set.cloud.isRectGrid()) ui->rbRectGrid->toggle();
    else ui->rbPolarGrid->toggle();

    ui->cbShowLabels->setChecked(set.cloud.isShowLabels());
    ui->cbShowLegend->setChecked(set.cloud.isShowLegend());
    ui->sbLensAngle->setValue(set.cloud.getFOV());

    ui->lAxisTransparent->setVisible(false);
    ui->lGridTransparent->setVisible(false);
    ui->sbdTransparent->setVisible(false);
    ui->dbAxisTransparent->setVisible(false);
    ui->cbShowLegend->setChecked(false);
    ui->cbShowLegend->setVisible(false);


    if(set.cloud.isWideField()){
        ui->rbWideField->setChecked(true);
    }else{
        ui->rbNarrowField->setChecked(true);
    }

    if(set.cloud.isWideField()){
        set.cloud.setFOV(108);
    }else{
        set.cloud.setFOV(32);
    }

    set.cloud.setShowLegend(false);


}

void WidgetPointCloudSettings::closeEvent(QCloseEvent *)
{
    QRect  rect = this->geometry();
    set.cloud.setWinRect(rect);
}

void WidgetPointCloudSettings::on_tbAxisColor_clicked()
{
    QColorDialog dlg;
    QColor color = dlg.getColor();
    double r,g,b,a;
    color.getRgbF(&r,&g,&b,&a);
    set.cloud.setAxisColor(r,g,b, set.cloud.getAxisColor().a);
    emit updateControlls(transform_e::IDLE);

}

void WidgetPointCloudSettings::on_tbBackgroundColor_clicked()
{
    QColorDialog dlg;
    QColor color = dlg.getColor();
    double r,g,b,a;
    color.getRgbF(&r,&g,&b,&a);
    set.cloud.setBackgroundColor(r,g,b, 1.0);
    emit updateControlls(transform_e::IDLE);

}

void WidgetPointCloudSettings::on_tbGridColor_clicked()
{
    QColorDialog dlg;
    QColor color = dlg.getColor();
    double r,g,b,a;
    color.getRgbF(&r,&g,&b,&a);

    set.cloud.setGridColor(r, g, b, set.cloud.getGridColor().a);
    emit updateControlls(transform_e::IDLE);
}

void WidgetPointCloudSettings::on_sbCellWidth_valueChanged(int arg1)
{
    set.cloud.setCellWidth(static_cast<uint>(arg1));
    emit updateControlls(transform_e::IDLE);
}

void WidgetPointCloudSettings::on_sbNumCells_valueChanged(int arg1)
{
    set.cloud.setNumberCells(static_cast<uint>(arg1));
    emit updateControlls(transform_e::IDLE);
}

void WidgetPointCloudSettings::on_sbdTransparent_valueChanged(double arg1)
{    
    set.cloud.setGridColorA(arg1);
    emit updateControlls(transform_e::IDLE);
}

void WidgetPointCloudSettings::on_sbOffsetX_valueChanged(int arg1)
{
    set.cloud.setGridOffsetX(arg1);
    emit updateControlls(transform_e::IDLE);
}

void WidgetPointCloudSettings::on_sbOffsetY_valueChanged(int arg1)
{
    set.cloud.setGridOffsetY(arg1);
    emit updateControlls(transform_e::IDLE);
}

void WidgetPointCloudSettings::on_sbOffsetZ_valueChanged(int arg1)
{
    set.cloud.setGridOffsetZ(arg1);
    emit updateControlls(transform_e::IDLE);
}

void WidgetPointCloudSettings::on_sbAngleX_valueChanged(int arg1)
{
    set.cloud.setCameraAngleX(arg1);
    emit updateControlls(transform_e::ROTATION);
}

void WidgetPointCloudSettings::on_sbAngleY_valueChanged(int arg1)
{
    set.cloud.setCameraAngleY(arg1);
    emit updateControlls(transform_e::ROTATION);
}

void WidgetPointCloudSettings::on_sbAngleZ_valueChanged(int arg1)
{
    set.cloud.setCameraAngleZ(arg1);
    emit updateControlls(transform_e::ROTATION);
}


void WidgetPointCloudSettings::on_tbClose_clicked()
{
    close();
}

void WidgetPointCloudSettings::on_sbAxisLineWidth_valueChanged(int arg1)
{
    set.cloud.setAxisLineWidth(arg1);
    emit updateControlls(transform_e::IDLE);
}

void WidgetPointCloudSettings::on_dbAxisTransparent_valueChanged(double arg1)
{
    set.cloud.setAxisColorA(arg1);
    emit updateControlls(transform_e::IDLE);
}

void WidgetPointCloudSettings::on_sbAxisOffsetX_valueChanged(int arg1)
{
    set.cloud.setAxisOffsetX(arg1);
    emit updateControlls(transform_e::IDLE);
}

void WidgetPointCloudSettings::on_sbAxisOffsetY_valueChanged(int arg1)
{
    set.cloud.setAxisOffsetY(arg1);
    emit updateControlls(transform_e::IDLE);

}

void WidgetPointCloudSettings::on_sbAxisOffsetZ_valueChanged(int arg1)
{
    set.cloud.setAxisOffsetZ(arg1);
    emit updateControlls(transform_e::IDLE);

}

void WidgetPointCloudSettings::on_sbCameraOffesetX_valueChanged(int arg1)
{  
    if(set.cloud.getCameraOffsetX() != arg1){
        set.cloud.setCameraOffsetX(arg1);
        emit updateControlls(transform_e::VIEWPORT_SHIFT);
    }
}

void WidgetPointCloudSettings::on_sbCameraOffesetY_valueChanged(int arg1)
{        
    if(set.cloud.getCameraOffsetY() != arg1){
        set.cloud.setCameraOffsetY(arg1);
        emit updateControlls(transform_e::VIEWPORT_SHIFT);
    }
}

void WidgetPointCloudSettings::on_dbZoom_valueChanged(double arg1){
    set.cloud.setCameraZoom(arg1);
    emit updateControlls(transform_e::ZOOM);
}

void WidgetPointCloudSettings::on_dbScaleX_valueChanged(double arg1)
{
    set.cloud.setScaleX(arg1);
    emit updateControlls(transform_e::SCALE);
}

void WidgetPointCloudSettings::on_dbScaleY_valueChanged(double arg1)
{
    set.cloud.setScaleY(arg1);
    emit updateControlls(transform_e::SCALE);

}

void WidgetPointCloudSettings::on_dbScaleZ_valueChanged(double arg1)
{
    set.cloud.setScaleZ(arg1);
    emit updateControlls(transform_e::SCALE);
}

void WidgetPointCloudSettings::on_sbObjectOffsetX_valueChanged(int arg1)
{
    set.cloud.setObjectOffsetX(arg1);
    emit updateControlls(transform_e::SHIFT);
}

void WidgetPointCloudSettings::on_sbObjectOffsetY_valueChanged(int arg1)
{
    set.cloud.setObjectOffsetY(arg1);
    emit updateControlls(transform_e::SHIFT);
}

void WidgetPointCloudSettings::on_sbObjectOffsetZ_valueChanged(int arg1)
{
    set.cloud.setObjectOffsetZ(arg1);
    emit updateControlls(transform_e::SHIFT);
}

void WidgetPointCloudSettings::on_rbRectGrid_toggled(bool checked)
{
    set.cloud.setRectGrid(checked);
    emit updateControlls(transform_e::IDLE);
}

void WidgetPointCloudSettings::on_sbAngleObjectZ_valueChanged(int arg1)
{
    set.cloud.setAngleObjectZ(arg1);
    emit updateControlls(transform_e::IDLE);
}

void WidgetPointCloudSettings::on_tbLabelColor_clicked()
{
    QColorDialog dlg;
    QColor color = dlg.getColor();
    double r,g,b,a;
    color.getRgbF(&r,&g,&b,&a);
    set.cloud.setLabelColor(r,g,b);
    emit updateControlls(transform_e::IDLE);
}

void WidgetPointCloudSettings::on_cbShowLabels_toggled(bool checked)
{
    set.cloud.setShowLabels(checked);
    emit updateControlls(transform_e::IDLE);
}

void WidgetPointCloudSettings::on_cbShowLegend_toggled(bool checked)
{
    set.cloud.setShowLegend(checked);
    emit updateControlls(transform_e::IDLE);
}

void WidgetPointCloudSettings::on_tbLabelFont_clicked()
{
    bool ok;
    QFontDialog dlg;
    QFont font = dlg.getFont(&ok);
    if(ok){
        set.cloud.setLabelFont(font);
        emit updateControlls(transform_e::IDLE);
    }
}

//void WidgetPointCloudSettings::on_sbLensAngle_valueChanged(int arg1)
//{
    //if(set.cloud.getFOV() != arg1){
    //    set.cloud.setFOV(arg1);
    //    emit updateControlls(transform_e::IDLE);
    //}
//}

void WidgetPointCloudSettings::zoomChanged(double zoom){

    if(fabs(ui->dbZoom->value() - zoom) > 0.000001)
        ui->dbZoom->setValue(zoom);
}


void WidgetPointCloudSettings::rotationChanged( double xAngle, double yAngle, double zAngle ){

    if(ui->sbAngleX->value() != static_cast<int>(xAngle))
        ui->sbAngleX->setValue(static_cast<int>(xAngle));

    if(ui->sbAngleY->value() != static_cast<int>(yAngle))
        ui->sbAngleY->setValue(static_cast<int>(yAngle));

    if(ui->sbAngleZ->value() != static_cast<int>(zAngle))
        ui->sbAngleZ->setValue(static_cast<int>(zAngle));
}



void WidgetPointCloudSettings::vieportShiftChanged(double offsetX, double offsetY){

    int valX = static_cast<int>(offsetX * 1000.0);
    int valY = static_cast<int>(offsetY * 1000.0);

    if(ui->sbCameraOffesetX->value()!= valX)
        ui->sbCameraOffesetX->setValue(valX);

    if(ui->sbCameraOffesetY->value()!= valY)
        ui->sbCameraOffesetY->setValue(valY);
}


void WidgetPointCloudSettings::scaleChanged(double scaleX, double scaleY, double scaleZ){

    if(fabs(ui->dbScaleX->value() - scaleX) > 0.00001  )
        ui->dbScaleX->setValue(scaleX);

    if(fabs(ui->dbScaleY->value() - scaleY) > 0.00001  )
        ui->dbScaleY->setValue(scaleY);

    if(fabs(ui->dbScaleZ->value() - scaleZ) > 0.00001  )
        ui->dbScaleZ->setValue(scaleZ);
}


void WidgetPointCloudSettings::shiftChanged(double xShift, double yShift, double zShift){

    if(ui->sbObjectOffsetX->value() != static_cast<int>(xShift))
        ui->sbObjectOffsetX->setValue(static_cast<int>(xShift));

    if(ui->sbObjectOffsetX->value() != static_cast<int>(yShift))
        ui->sbObjectOffsetY->setValue(static_cast<int>(yShift));

    if(ui->sbObjectOffsetX->value() != static_cast<int>(zShift))
        ui->sbObjectOffsetZ->setValue(static_cast<int>(zShift));
}

//void WidgetPointCloudSettings::on_cbGrayPointCloud_toggled(bool checked)
//{
    //emit grayPointCloudChanged(checked);
//}

void WidgetPointCloudSettings::on_cbSurfaceInterconnect_toggled(bool checked)
{
    if(checked){
        set.cloud.setPCLFilter(true);
        ui->sbSurfaceInterconnect->setVisible(true);

        if(ui->cbPoints->isChecked()==true)
            ui->cbPoints->setChecked(false);

    }else{
        set.cloud.setPCLFilter(false);
        ui->sbSurfaceInterconnect->setVisible(true);

        if(ui->cbPoints->isChecked()==false){
            if(ui->cbGrayPointCloud->isChecked()==true)
                ui->cbGrayPointCloud->setChecked(false);

            ui->cbPoints->setChecked(true);
        }
    }
}

void WidgetPointCloudSettings::on_cbPoints_toggled(bool checked)
{
    set.cloud.setPoints(checked);

    if(checked){
        set.cloud.setPCLFilter(false);
        surfacePlot->setPlotStyle(Qwt3D::POINTS);

        ui->cbGrayPointCloud->setDisabled(true);
        ui->cbPoints->setDisabled(false);
        ui->dbPointSize->setDisabled(false);
        ui->dbPointSize->setVisible(true);

        if(ui->cbSurfaceInterconnect->isChecked())
            ui->cbSurfaceInterconnect->setChecked(false);

        ui->sbSurfaceInterconnect->setVisible(false);
    } else{
        set.cloud.setPCLFilter(true);
        surfacePlot->setPlotStyle(Qwt3D::FILLED);

        ui->cbGrayPointCloud->setDisabled(false);
        ui->dbPointSize->setDisabled(true);
        ui->dbPointSize->setVisible(false);

        if(!ui->cbSurfaceInterconnect->isChecked())
            ui->cbSurfaceInterconnect->setChecked(true);

        ui->sbSurfaceInterconnect->setVisible(true);
    }

    set.cloud.setPoints(checked);
}

void WidgetPointCloudSettings::on_sbSurfaceInterconnect_valueChanged(int arg1)
{
    double distPCLfilterLSB = arg1;
    distPCLfilterLSB+=0.5;
    set.cloud.setPCLFilterThreshold(static_cast<int>(distPCLfilterLSB), true);
    set.cloud.setPCLFilterThreshold(arg1);
}

void WidgetPointCloudSettings::on_dbPointSize_valueChanged(double arg1)
{
    set.cloud.setPointSize(arg1);
    surfacePlot->setPointSize(arg1);
}


void WidgetPointCloudSettings::on_cbAxis2D_toggled(bool checked)
{
    set.cloud.setShowAxis2D(checked);
}

void WidgetPointCloudSettings::on_cbAxis3D_toggled(bool checked)
{
    set.cloud.setShowAxis3D(checked);
}

void WidgetPointCloudSettings::on_cbGrid_toggled(bool checked)
{
    set.cloud.setShowGrid(checked);
}

void WidgetPointCloudSettings::on_cbPerspectiveView_toggled(bool checked)
{
    surfacePlot->setOrtho(!checked);
}

void WidgetPointCloudSettings::on_cbCartesian_toggled(bool checked)
{
    set.cloud.setCartesian(checked);
}

void WidgetPointCloudSettings::on_cbUndistortion_toggled(bool checked)
{
    set.cloud.setUndistortion(checked);
}

void WidgetPointCloudSettings::updateControls()
{
    ui->sbSurfaceInterconnect->setValue(set.cloud.getPCLFilterThreshold());
}

void WidgetPointCloudSettings::setPerspective(bool state)
{
    ui->cbPerspectiveView->setChecked(state);
}

void WidgetPointCloudSettings::initControls()
{
    ui->sbSurfaceInterconnect->setValue(set.cloud.getPCLFilterThreshold());
    ui->cbPoints->setChecked(set.cloud.isPoints());

    ui->cbGrayPointCloud->setChecked(set.cloud.isGrayPointCloud());
    ui->dbPointSize->setValue(set.cloud.getPointSize());

}

void WidgetPointCloudSettings::on_sbSensorOffsetX_valueChanged(int arg1)
{
    set.cloud.setSensorCenterOffsetX(arg1);
}

void WidgetPointCloudSettings::on_sbSensorOffsetY_valueChanged(int arg1)
{
    set.cloud.setSensorCenterOffsetY(arg1);
}

void WidgetPointCloudSettings::on_rbWideField_toggled(bool checked)
{
    if(checked){
        set.cloud.setWideField(checked);

        if(checked) set.cloud.setFOV(108);
        else set.cloud.setFOV(32);
    }

}

void WidgetPointCloudSettings::on_rbNarrowField_toggled(bool checked)
{
    if(checked){
        set.cloud.setWideField(!checked);

        if(!checked) set.cloud.setFOV(108);
        else set.cloud.setFOV(32);
    }
}

void WidgetPointCloudSettings::on_tbSaveDefaultView_clicked()
{
    set.cloud.setDefaultViewAngleX(set.cloud.getCameraAngleX());
    set.cloud.setDefaultViewAngleY(set.cloud.getCameraAngleY());
    set.cloud.setDefaultViewAngleZ(set.cloud.getCameraAngleZ());
    set.cloud.setDefaultViewOffsetX(set.cloud.getCameraOffsetX());
    set.cloud.setDefaultViewOffsetY(set.cloud.getCameraOffsetY());
    set.cloud.setDefaultViewZoom(set.cloud.getCameraZoom());
}

void WidgetPointCloudSettings::on_tbResetDefaultView_clicked()
{
    emit resetDefaultView();
}
