#include "WidgetPointCloudView.h"
#include "ui_widget_point_cloud_view.h"

WidgetPointCloudView::WidgetPointCloudView(Settings &set, PlotSurface *surfacePlot, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetPointCloudView),    
    surfacePlot(surfacePlot),
    set(set)
{
    ui->setupUi(this);
    setWindowFlags ( Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowStaysOnTopHint | Qt::WindowCloseButtonHint);

    ui->cbUndistortion->setChecked(false);
    ui->cbUndistortion->setVisible(false);
    ui->cbPerspectiveView->setChecked(true);    

    this->move(25, 500);
}

WidgetPointCloudView::~WidgetPointCloudView()
{
    delete ui;
}

void WidgetPointCloudView::restoreSettings()
{
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

}

void WidgetPointCloudView::initControls()
{
    ui->sbSurfaceInterconnect->setValue(set.cloud.getPCLFilterThreshold());
    ui->cbPoints->setChecked(set.cloud.isPoints());

    ui->cbAutoRotating->setChecked(set.cloud.isAutoRotating());
    ui->cbGrayPointCloud->setChecked(set.cloud.isGrayPointCloud());
    ui->dbPointSize->setValue(set.cloud.getPointSize());

}

void WidgetPointCloudView::updateControls()
{
    ui->sbSurfaceInterconnect->setValue(set.cloud.getPCLFilterThreshold());
}

void WidgetPointCloudView::setPerspective(bool state)
{
    ui->cbPerspectiveView->setChecked(state);
}

void WidgetPointCloudView::on_tbClose_clicked()
{
    hide();
}

void WidgetPointCloudView::on_cbAxis2D_toggled(bool checked)
{
    set.cloud.setShowAxis2D(checked);
}

void WidgetPointCloudView::on_cbAxis3D_toggled(bool checked)
{
    set.cloud.setShowAxis3D(checked);
}

void WidgetPointCloudView::on_cbGrid_toggled(bool checked)
{
    set.cloud.setShowGrid(checked);
}

void WidgetPointCloudView::on_cbUndistortion_toggled(bool checked)
{
    set.cloud.setUndistortion(checked);
}

void WidgetPointCloudView::on_cbCartesian_toggled(bool checked)
{
    set.cloud.setCartesian(checked);
}


void WidgetPointCloudView::on_sbSurfaceInterconnect_valueChanged(int arg1)
{
    double distPCLfilterLSB = arg1;
    distPCLfilterLSB+=0.5;
    set.cloud.setPCLFilterThreshold(static_cast<int>(distPCLfilterLSB), true);
    set.cloud.setPCLFilterThreshold(arg1);
}

void WidgetPointCloudView::on_cbPerspectiveView_toggled(bool checked)
{
    surfacePlot->setOrtho(!checked);
}

void WidgetPointCloudView::on_cbGrayPointCloud_toggled(bool checked)
{

   // emit grayPointCloudChanged(checked);

    /*if(set.cloud.isGrayPointCloud()){

        //surfacePlot->showColorLegend(false);
        ui->cbPoints->setDisabled(true);
        ui->dbPointSize->setDisabled(true);
        ui->dbPointSize->setVisible(false);

    }else{

        //surfacePlot->showColorLegend(set.cloud.isShowLegend());
        ui->cbPoints->setDisabled(false);
        ui->cbCartesian->setDisabled(false);
    }*/


}

void WidgetPointCloudView::on_dbPointSize_valueChanged(double arg1)
{
    set.cloud.setPointSize(arg1);
    surfacePlot->setPointSize(arg1);
}

void WidgetPointCloudView::on_cbPoints_toggled(bool checked)
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

void WidgetPointCloudView::on_cbSurfaceInterconnect_toggled(bool checked)
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

void WidgetPointCloudView::on_cbAutoRotating_toggled(bool checked)
{
    emit autoRotatingToggled(checked);
}
