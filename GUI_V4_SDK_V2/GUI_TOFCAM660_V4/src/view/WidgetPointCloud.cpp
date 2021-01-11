/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5:       Copyright (C) 2019 The Qt Company
* - QwtPlot3D: Copyright (C) 2003-2005 Michael Bieber
***************************************************************************************/

#include "WidgetPointCloud.h"
#include "ui_widget_point_cloud.h"
//#include "data/constants.h"
#include <math.h>
#include <QFileDialog>
#include <QDebug>
#include <QThread>
#include <QStandardPaths>
#include <QScreen>

/// \addtogroup WidgetPointCloud
/// @{

using namespace Qwt3D;


WidgetPointCloud::WidgetPointCloud(ApplicationContext &context, QWidget *parent) :
QWidget(parent),
ui(new Ui::WidgetPointCloud),
set(context.getSettings()),
width(320),
height(240)
{
    ui->setupUi(this);
    setWindowFlags (Qt::WindowTitleHint | Qt::WindowMaximizeButtonHint |  Qt::CustomizeWindowHint);
    windowControls   = nullptr;
    widgetPointCloudSettings = nullptr;
    surfacePlot = nullptr;
    lastWndowState = Qt::WindowActive;
    cameraSettings = nullptr;
    isKeyPressed = false;
    roiChanged = false;

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    screenWidth = screenGeometry.width();
    screenHeight = screenGeometry.height();

    tempDataPixelfield = new int*[width];
    distanceData  = new int*[width];
    amplitudeData = new int*[width];

    for (uint i = 0; i < width; i++){
        tempDataPixelfield[i] = new int[height];
        distanceData[i] = new int[height];
        amplitudeData[i] = new int[height];
    }

    surfacePlot = new PlotSurface(width, height, set, ui->widget3D);
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(updateRotation()));
    connect(this, SIGNAL(updateShowDistance(const char*, DataHeader&)), this, SLOT(showDistance(const char*, DataHeader&)));
    connect(this, SIGNAL(updateShowDistanceAmplitude(const char*, DataHeader&)), this, SLOT(showDistanceAmplitude(const char*, DataHeader&)));
    connect(surfacePlot, SIGNAL(fullScreen(bool)), this, SLOT(fullScreen(bool)));
    connect(&set.cloud, SIGNAL(showColorLegendChanged()), surfacePlot, SLOT(updateShowColorLegend()));

    initialisation();
    restoreSettings();

    ui->cbUndistortion->setChecked(false);
    ui->cbUndistortion->setVisible(false);
    ui->cbPerspectiveView->setChecked(true);

}


WidgetPointCloud::~WidgetPointCloud() {
    qDebug() << "----------WidgetPointCloud destroying";    
    delete widgetPointCloudSettings;
    delete windowControls;
    delete surfacePlot;
    delete ui;
    qDebug() << "----------WidgetPointCloud destroyed";
}


void WidgetPointCloud::restoreSettings()
{
    widgetPointCloudSettings->restoreSettings();

    ui->cbVerticalFlip->setChecked(set.isVerticalFlip());
    ui->cbHorizontalFlip->setChecked(set.isHorizontalFlip());

    setPointSize(set.cloud.getPointSize());

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

    currentZoom = 1.0;
    fullScreenState = false;
    firstAutorotation = true;

    CameraMoving camera;

    indx = 0;
    camera.angleX  = -265;
    camera.angleY  = 140;
    camera.angleZ  = 0;
    camera.viewPortOffsetX = 0;
    camera.viewPortOffsetY = 0;
    camera.shiftX = 0.0;
    camera.shiftY = 0.0;
    camera.shiftZ = 0.0;
    camera.zoom    = 0.5;
    camera.numSteps = 80;
    camera.timerSleep = 60;
    set.cloud.cameras.emplace_back(camera);

    camera.angleX  = -265;
    camera.angleY  = 220;
    camera.angleZ  = 0;
    camera.viewPortOffsetX = 0;
    camera.viewPortOffsetY = 0;
    camera.shiftX = 0.0;
    camera.shiftY = 0.0;
    camera.shiftZ = 0.0;
    camera.zoom    = 1.0;
    camera.numSteps = 320;
    camera.timerSleep = 30;
    set.cloud.cameras.emplace_back(camera);

    if(set.getWinDataWidth()!=0 && set.getWinDataHeight()!=0){
        this->setGeometry(set.getWinDataPosX(), set.getWinDataPosY(), set.getWinDataWidth(), set.getWinDataHeight());
    }

    initControls();
}

void WidgetPointCloud::initialisation(bool bLoadDefault){

    if(windowControls!=nullptr)    delete windowControls;
    if(surfacePlot->functionDistance != nullptr)  delete surfacePlot->functionDistance;
    if(widgetPointCloudSettings != nullptr) delete widgetPointCloudSettings;

    RGBA bkgColor(0,0,0,1);

    surfacePlot->setBackgroundColor(bkgColor);

    if(set.cloud.isPoints()) surfacePlot->setPlotStyle(Qwt3D::POINTS);
    else        surfacePlot->setPlotStyle(Qwt3D::FILLED);

    surfacePlot->initialisation(screenWidth, screenHeight);

    if(bLoadDefault)
        surfacePlot->loadDefault(-67,17,181, 0.5);

    surfacePlot->functionDistance = new FunctionDistance(distanceData, surfacePlot);
    windowControls = new WindowControls();
    widgetPointCloudSettings = new WidgetPointCloudSettings(set);

    surfacePlot->coordinates()->setAutoScale(false);    
    //connect(&set.view, SIGNAL(distanceMinChanged(int)), this, SLOT(setLegendMin(int))); //TODO...
    //connect(&set.view, SIGNAL(distanceMaxChanged(int)), this, SLOT(setLegendMax(int)));        
    //connect(widgetPointCloudSettings, SIGNAL(updateGraphicAtributes()), this, SLOT(updateGraphicAtributes()));
    connect(widgetPointCloudSettings, SIGNAL(updateControlls(transform_e)), this, SLOT(updateControls(transform_e)));
    connect(surfacePlot, SIGNAL(vieportShiftChanged(double, double)), widgetPointCloudSettings, SLOT(vieportShiftChanged(double, double)));                    
    connect(surfacePlot, SIGNAL(zoomChanged(double)), widgetPointCloudSettings, SLOT(zoomChanged(double)));
    connect(surfacePlot, SIGNAL(scaleChanged(double, double, double)), widgetPointCloudSettings, SLOT(scaleChanged(double, double, double)));
    connect(surfacePlot, SIGNAL(rotationChanged(double, double, double)), widgetPointCloudSettings, SLOT(rotationChanged(double, double, double)));
    connect(surfacePlot, SIGNAL(shiftChanged(double, double, double)), widgetPointCloudSettings, SLOT(shiftChanged(double, double, double)));
    connect(surfacePlot, SIGNAL(keyPressed(bool)), this, SLOT(onKeyPressed(bool)));    
}


void WidgetPointCloud::updateView(bool fullScreen){

    static QString style = this->styleSheet();

    if(fullScreen){
        lastWndowState = this->windowState();
        this->setWindowState(Qt::WindowMaximized);
        this->setWindowState(Qt::WindowFullScreen);
        this->setStyleSheet("background-color: rgb(0, 0, 0, 255)");

    }else{
        this->setWindowState(lastWndowState);
        this->setStyleSheet(style);
    }
}


void WidgetPointCloud::resizeEvent(QResizeEvent*){
    surfacePlot->setGeometry(ui->widget3D->x(),ui->widget3D->y(), ui->widget3D->width(), ui->widget3D->height());
    surfacePlot->updateResizeGL();
}

void WidgetPointCloud::showData(const char *pData, DataHeader &dataHeader){

    switch (set.getViewType()) {
        case Settings::ViewType::POINT_CLOUD_DISTANCE:
            emit updateShowDistance(pData, dataHeader);
            break;
        case Settings::ViewType::POINT_CLOUD_DISTANCE_AMPLITUDE:
            emit updateShowDistanceAmplitude(pData, dataHeader);
            break;
        case Settings::ViewType::POINT_CLOUD_DISTANCE_GRAYSCALE:
            //showDistanceGrayscale(pData, dataHeader);
            break;
        default: break;
    }

}

void WidgetPointCloud::showDistance(const char *pData, DataHeader &dataHeader){

    disconnect(this, SIGNAL(updateShowDistance(const char*, DataHeader&)), this, SLOT(showDistance(const char*, DataHeader&)));

    width = dataHeader.width;
    height = dataHeader.height;

    surfacePlot->updateGraphicAtributes();

    uint x0 = 0;
    uint y0 = 0;

    if(width < 320 || height < 240){

        for(int y=0; y< 240; y++){
            for(int x=0; x< 320; x++){
                distanceData[x][y] = 0;
                amplitudeData[x][y] = 0;
                tempDataPixelfield[x][y] = 0;
            }
        }

        RoiSettings roi = set.getRoiSettings();
        x0 = static_cast<uint>(roi.getX1());
        y0 = static_cast<uint>(roi.getY1());

        if(width + x0 > 320)  x0 = 0;
        if(height + x0 > 240) y0 = 0;
    }

    int index = 0;
    for(uint y = 0; y < height; y++){
        for(uint x = 0; x < width; x++){
            uint8_t distanceMsb = static_cast<uint8_t>(pData[2*index+1+dataHeader.offset]);
            uint8_t distanceLsb = static_cast<uint8_t>(pData[2*index+0+dataHeader.offset]);
            distanceData[x + x0][y + y0] = ((distanceMsb << 8) + distanceLsb);
            amplitudeData[x + x0][y + y0] = 500;
            index++;
        }
    }

    flipping(distanceData);

    surfacePlot->updateGUI(distanceData, amplitudeData);   

    QCoreApplication::processEvents();

    connect(this, SIGNAL(updateShowDistance(const char*, DataHeader&)), this, SLOT(showDistance(const char*, DataHeader&)));

}


void WidgetPointCloud::showDistanceAmplitude(const char *pData, DataHeader &dataHeader){

    disconnect(this, SIGNAL(updateShowDistanceAmplitude(const char*, DataHeader&)), this, SLOT(showDistanceAmplitude(const char*, DataHeader&)));

    width  = dataHeader.width;
    height = dataHeader.height;

    surfacePlot->updateGraphicAtributes();

    uint x0 = 0;
    uint y0 = 0;

    if(width < 320 || height < 240){

        for(int y=0; y< 240; y++){
            for(int x=0; x< 320; x++){
                distanceData[x][y] = 0;
                amplitudeData[x][y] = 0;
                tempDataPixelfield[x][y] = 0;
            }
        }

        RoiSettings roi = set.getRoiSettings();
        x0 = static_cast<uint>(roi.getX1());
        y0 = static_cast<uint>(roi.getY1());

        if(width + x0 > 320)  x0 = 0;
        if(height + x0 > 240) y0 = 0;
    }

    int index = 0;
    for(uint y = 0; y < height; y++){
        for(uint x = 0; x < width; x++, index++){

            //First get the values of the distance
            uint8_t distanceMsb = static_cast<uint8_t>(pData[4*index+1+dataHeader.offset]);
            uint8_t distanceLsb = static_cast<uint8_t>(pData[4*index+0+dataHeader.offset]);

            //Then get the values of the amplitude
            uint8_t amplitudeMsb = static_cast<uint8_t>(pData[4*index+3+dataHeader.offset]);
            uint8_t amplitudeLsb = static_cast<uint8_t>(pData[4*index+2+dataHeader.offset]);

            //pixelAmplitude = calcLog(pixelAmplitude);
            distanceData[x+x0][y+y0] = (distanceMsb << 8) + distanceLsb;
            amplitudeData[x+x0][y+y0] = (amplitudeMsb << 8) + amplitudeLsb;

        } //end for x

    } //end for y

    flipping(distanceData);
    flipping(amplitudeData);

    surfacePlot->updateGUI(distanceData, amplitudeData);

    QCoreApplication::processEvents();

    connect(this, SIGNAL(updateShowDistanceAmplitude(const char*, DataHeader&)), this, SLOT(showDistanceAmplitude(const char*, DataHeader&)));

}


void WidgetPointCloud::on_tbShowControls_clicked() {
    windowControls->hide();
    windowControls->show();
}

void WidgetPointCloud::hideControls(){
    windowControls->hide();
}

void WidgetPointCloud::on_tbReset_clicked() {
    surfacePlot->loadDefault(-67,17,181, set.cloud.getCameraZoom());
     ui->cbPerspectiveView->setChecked(true);
}

void WidgetPointCloud::on_tbFront_clicked(){
    surfacePlot->setRotation(-270, 180, 0);
    ui->cbPerspectiveView->setChecked(false);
}

void WidgetPointCloud::on_tbSide_clicked(){
    surfacePlot->setRotation(90, 90, 0);
    ui->cbPerspectiveView->setChecked(false);
}

void WidgetPointCloud::on_tbTop_clicked(){
    surfacePlot->setRotation(0, 0, 180);
    ui->cbPerspectiveView->setChecked(false);
}

void WidgetPointCloud::setPointSize(double value){
    surfacePlot->setPointSize(value);
}

void WidgetPointCloud::setLegendMin(int value){
    surfacePlot->setMinZ(value);
    surfacePlot->legend()->setLimits(value, set.getRangeMax());
}

void WidgetPointCloud::setLegendMax(int value){
    surfacePlot->setMaxZ(value);
    surfacePlot->legend()->setLimits(set.getRangeMin(), value);
}

void WidgetPointCloud::mouseReleaseEvent(QMouseEvent *event){
    if (event->button() == Qt::RightButton){
        QString filename = QFileDialog::getSaveFileName(this,"save image as", "", ".png");
        if (!filename.isNull()){
            surfacePlot->savePixmap(filename, "png");
        }
    }
}

void WidgetPointCloud::closeEvent (QCloseEvent *event  __attribute__((unused))){    
    surfacePlot->close();
    widgetPointCloudSettings->close();
}

void WidgetPointCloud::flipping(int **data){

    if (!set.isHorizontalFlip()){
        flipHorizontal(data);
    }

    if (!set.isVerticalFlip()){
        flipVertical(data);
    }


}

void WidgetPointCloud::flipHorizontal(int **data){
    uint i, x, y;

    for(x = 0; x < 320; x++){
        i = 320 - 1 - x;
        for(y = 0; y < 240; y++ ){
             tempDataPixelfield[i][y] = data[x][y];
        }
    }

    for(x=0; x < 320; x++ )
        for(y = 0; y < 240; y++){
            data[x][y] = tempDataPixelfield[x][y];
    }
}

void WidgetPointCloud::flipVertical(int** data){
    uint i, x, y;    

    for(y = 0; y < 240; y++){
        i = 240 - 1 - y;
        for(x = 0; x < 320; x++ ){
             tempDataPixelfield[x][i] = data[x][y];
        }
    }

    for(y=0; y < 240; y++)
        for(x=0; x < 320; x++ )
            data[x][y] = tempDataPixelfield[x][y];

}

void WidgetPointCloud::on_cbPoints_toggled(bool checked){    

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

void WidgetPointCloud::on_cbGrayPointCloud_toggled(bool checked){

    set.cloud.setGrayPointCloud(checked);

    initialisation(false);

    if(set.cloud.isGrayPointCloud()){
        surfacePlot->showColorLegend(false);
        ui->cbPoints->setDisabled(true);
        ui->dbPointSize->setDisabled(true);
        ui->dbPointSize->setVisible(false);
    }else{
        surfacePlot->showColorLegend(set.cloud.isShowLegend());
        ui->cbPoints->setDisabled(false);
        ui->cbCartesian->setDisabled(false);
    }

}


void WidgetPointCloud::on_cbAutoRotating_toggled(bool checked)
{
    set.cloud.setAutoRotating(checked);

    if(checked){        
        indx = 0;        
        firstAutorotation = true;        
        loadCameraMove();
        timer->start(30);        

    }else{                
        timer->stop();
        saveCameraMove();
    }
}


void WidgetPointCloud::on_cbSurfaceInterconnect_toggled(bool checked){
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

void WidgetPointCloud::on_sbSurfaceInterconnect_valueChanged(int arg1){
    double distPCLfilterLSB = arg1;    
    distPCLfilterLSB+=0.5;    
    set.cloud.setPCLFilterThreshold(static_cast<int>(distPCLfilterLSB), true);
    set.cloud.setPCLFilterThreshold(arg1);
}


void WidgetPointCloud::on_dbPointSize_valueChanged(double arg1){
    set.cloud.setPointSize(arg1);
    surfacePlot->setPointSize(arg1);    
}

void WidgetPointCloud::on_cbAxis2D_toggled(bool checked){
    set.cloud.setShowAxis2D(checked);
}

void WidgetPointCloud::on_cbAxis3D_toggled(bool checked){
    set.cloud.setShowAxis3D(checked);
}

void WidgetPointCloud::on_cbCartesian_toggled(bool checked)
{
    set.cloud.setCartesian(checked);
}

void WidgetPointCloud::on_cbUndistortion_toggled(bool checked)
{
    set.cloud.setUndistortion(checked);
}

void WidgetPointCloud::on_cbGrid_toggled(bool checked){
    set.cloud.setShowGrid(checked);
}

void WidgetPointCloud::on_tbSettings_clicked(){
    widgetPointCloudSettings->hide();
    widgetPointCloudSettings->show();
}

void WidgetPointCloud::on_tbFullScreenPC_clicked(){
    fullScreenState = !fullScreenState;
    fullScreen(fullScreenState);
    surfacePlot->setFullScreenState(fullScreenState);
}


void WidgetPointCloud::keyPressEvent(QKeyEvent *e){

    if(e->key() == Qt::Key_Escape){
        fullScreenState  = false;        
        updateView(false);
        setVisibleControlls(true);
    }
}

void WidgetPointCloud::fullScreen(bool checked){
    fullScreenState = checked;
    setVisibleControlls(!checked);
    updateView(fullScreenState);
}

void WidgetPointCloud::setVisibleControlls(bool state)
{
    ui->tbReset->setVisible(state);
    ui->tbSettings->setVisible(state);
    ui->tbFullScreenPC->setVisible(state);
    ui->tbTop->setVisible(state);
    ui->tbSide->setVisible(state);
    ui->tbFront->setVisible(state);
    ui->tbShowControls->setVisible(state);
    ui->cbCartesian->setVisible(state);
    ui->cbAutoRotating->setVisible(state);
    ui->cbAxis2D->setVisible(state);
    ui->cbAxis3D->setVisible(state);
    ui->cbAxis3D->setVisible(state);
    ui->cbGrid->setVisible(state);
    ui->cbPoints->setVisible(state);
    ui->cbSurfaceInterconnect->setVisible(state);
    ui->cbGrayPointCloud->setVisible(state);
    ui->sbSurfaceInterconnect->setVisible(state);
    ui->dbPointSize->setVisible(state);
    ui->cbUndistortion->setVisible(state);
    ui->cbVerticalFlip->setVisible(state);
    ui->cbHorizontalFlip->setVisible(state);
}


void WidgetPointCloud::initControls()
{    
    ui->sbSurfaceInterconnect->setValue(set.cloud.getPCLFilterThreshold());

    RGBA bkgColor(0,0,0,1);
    EpcColor color = set.cloud.getBackgroundColor();
    bkgColor.r = color.r;
    bkgColor.g = color.g;
    bkgColor.b = color.b;
    bkgColor.a = color.a;

    surfacePlot->setBackgroundColor(bkgColor);
    double dx = set.cloud.getCameraOffsetX() / 1000.0;
    double dy = set.cloud.getCameraOffsetY() / 1000.0;
    surfacePlot->setViewportShift(dx, dy);
    surfacePlot->setShift(set.cloud.getObjectOffsetX(), set.cloud.getObjectOffsetY(), set.cloud.getObjectOffsetZ());
    surfacePlot->setZoom(set.cloud.getCameraZoom());
    surfacePlot->setScale(set.cloud.getScaleX(), set.cloud.getScaleY(), set.cloud.getScaleZ());
    surfacePlot->setRotation(set.cloud.getCameraAngleX(), set.cloud.getCameraAngleY(), set.cloud.getCameraAngleZ());
    surfacePlot->showColorLegend(set.cloud.isShowLegend());
    surfacePlot->setLabelsProperties();

    ui->cbAxis2D->setChecked(set.cloud.isShowAxis2D());
    ui->cbAxis3D->setChecked(set.cloud.isShowAxis3D());
    ui->cbGrid->setChecked(set.cloud.isShowGrid());
    ui->cbAutoRotating->setChecked(set.cloud.isAutoRotating());    
    ui->cbCartesian->setChecked(set.cloud.isCartesian());
    ui->cbGrayPointCloud->setChecked(set.cloud.isGrayPointCloud());    
    ui->cbPoints->setChecked(set.cloud.isPoints());
    ui->dbPointSize->setValue(set.cloud.getPointSize());

    surfacePlot->updateGraphicAtributes();

}

void WidgetPointCloud::updateControls(transform_e value)
{


    if(!set.cloud.isAutoRotating()){
        ui->sbSurfaceInterconnect->setValue(set.cloud.getPCLFilterThreshold());
        RGBA bkgColor(0,0,0,1);
        EpcColor color = set.cloud.getBackgroundColor();
        bkgColor.r = color.r;
        bkgColor.g = color.g;
        bkgColor.b = color.b;
        bkgColor.a = color.a;
        surfacePlot->setBackgroundColor(bkgColor);
    }

    if(!isKeyPressed && !set.cloud.isAutoRotating()){

        if(value == transform_e::VIEWPORT_SHIFT){
            double dx = set.cloud.getCameraOffsetX()/1000.0;
            double dy = set.cloud.getCameraOffsetY()/1000.0;
            surfacePlot->setViewportShift(dx, dy, false);
        }else if(value == transform_e::SHIFT){
            surfacePlot->setShift(set.cloud.getObjectOffsetX(), set.cloud.getObjectOffsetY(), set.cloud.getObjectOffsetZ(), true);
        }else if(value == transform_e::ZOOM){
            surfacePlot->setZoom(set.cloud.getCameraZoom(), true);
        }else if(value == transform_e::SCALE){
            surfacePlot->setScale(set.cloud.getScaleX(), set.cloud.getScaleY(), set.cloud.getScaleZ(), true);
        }else if(value == transform_e::ROTATION){
            surfacePlot->setRotation(set.cloud.getCameraAngleX(), set.cloud.getCameraAngleY(), set.cloud.getCameraAngleZ(), true);
        }

        /*double dx = set.cloud.getCameraOffsetX()/1000.0;
        double dy = set.cloud.getCameraOffsetY()/1000.0;
        surfacePlot->setViewportShift(dx, dy, false);
        surfacePlot->setShift(set.cloud.getObjectOffsetX(), set.cloud.getObjectOffsetY(), set.cloud.getObjectOffsetZ(), false);
        surfacePlot->setZoom(set.cloud.getCameraZoom(), false);
        surfacePlot->setScale(set.cloud.getScaleX(), set.cloud.getScaleY(), set.cloud.getScaleZ(), false);
        surfacePlot->setRotation(set.cloud.getCameraAngleX(), set.cloud.getCameraAngleY(), set.cloud.getCameraAngleZ(), true);*/

        surfacePlot->showColorLegend(set.cloud.isShowLegend());
        surfacePlot->setLabelsProperties();
    }

    static int count = 0;

    count++;
    surfacePlot->updateGraphicAtributes();
}



void WidgetPointCloud::updateRotation(){

    static int cnt = 0;
    static double dAngleX = 0.0;
    static double dAngleY = 0.0;
    static double dAngleZ = 0.0;
    static double dZoom = 0.0;
    static double dViewX = 0.0;
    static double dViewY = 0.0;
    static double dShiftX = 0.0;
    static double dShiftY = 0.0;
    static double dShiftZ = 0.0;

    if(firstAutorotation || cnt >= set.cloud.cameras[indx].numSteps){

        if(firstAutorotation || indx >= set.cloud.cameras.size()){
            firstAutorotation = false;
            indx = 0;
        }else{
            indx++;
        }

        cnt = 0;

        if (indx == set.cloud.cameras.size()-1){
            dAngleX = (set.cloud.cameras[0].angleX - set.cloud.cameras[indx].angleX) / static_cast<double>(set.cloud.cameras[indx].numSteps);
            dAngleY = (set.cloud.cameras[0].angleY - set.cloud.cameras[indx].angleY) / static_cast<double>(set.cloud.cameras[indx].numSteps);
            dAngleZ = (set.cloud.cameras[0].angleZ - set.cloud.cameras[indx].angleZ) / static_cast<double>(set.cloud.cameras[indx].numSteps);
            dZoom = (set.cloud.cameras[0].zoom - set.cloud.cameras[indx].zoom) / static_cast<double>(set.cloud.cameras[indx].numSteps);
            dViewX = (set.cloud.cameras[0].viewPortOffsetX - set.cloud.cameras[indx].viewPortOffsetX) / static_cast<double>(set.cloud.cameras[indx].numSteps);
            dViewY = (set.cloud.cameras[0].viewPortOffsetX - set.cloud.cameras[indx].viewPortOffsetX) / static_cast<double>(set.cloud.cameras[indx].numSteps);
            dShiftX = (set.cloud.cameras[0].shiftX - set.cloud.cameras[indx].shiftX) / static_cast<double>(set.cloud.cameras[indx].numSteps);
            dShiftY = (set.cloud.cameras[0].shiftY - set.cloud.cameras[indx].shiftY) / static_cast<double>(set.cloud.cameras[indx].numSteps);
            dShiftZ = (set.cloud.cameras[0].shiftZ - set.cloud.cameras[indx].shiftZ) / static_cast<double>(set.cloud.cameras[indx].numSteps);

        }else{

            if(indx > set.cloud.cameras.size()-1){
                indx = 0;
            }

            dAngleX = (set.cloud.cameras[indx+1].angleX - set.cloud.cameras[indx].angleX) / static_cast<double>(set.cloud.cameras[indx].numSteps);
            dAngleY = (set.cloud.cameras[indx+1].angleY - set.cloud.cameras[indx].angleY) / static_cast<double>(set.cloud.cameras[indx].numSteps);
            dAngleZ = (set.cloud.cameras[indx+1].angleZ - set.cloud.cameras[indx].angleZ) / static_cast<double>(set.cloud.cameras[indx].numSteps);
            dZoom = (set.cloud.cameras[indx+1].zoom - set.cloud.cameras[indx].zoom) / static_cast<double>(set.cloud.cameras[indx].numSteps);
            dViewX = (set.cloud.cameras[indx+1].viewPortOffsetX - set.cloud.cameras[indx].viewPortOffsetX) / static_cast<double>(set.cloud.cameras[indx].numSteps);
            dViewY = (set.cloud.cameras[indx+1].viewPortOffsetX - set.cloud.cameras[indx].viewPortOffsetX) / static_cast<double>(set.cloud.cameras[indx].numSteps);
            dShiftX = (set.cloud.cameras[indx+1].shiftX - set.cloud.cameras[indx].shiftX) / static_cast<double>(set.cloud.cameras[indx].numSteps);
            dShiftY = (set.cloud.cameras[indx+1].shiftY - set.cloud.cameras[indx].shiftY) / static_cast<double>(set.cloud.cameras[indx].numSteps);
            dShiftZ = (set.cloud.cameras[indx+1].shiftZ - set.cloud.cameras[indx].shiftZ) / static_cast<double>(set.cloud.cameras[indx].numSteps);

        }

        timer->setInterval(set.cloud.cameras[indx].timerSleep);

    }else{

        cnt++;
    }


    int viewPort_X = static_cast<int>(set.cloud.cameras[indx].viewPortOffsetX + cnt * dViewX);
    int viewPort_Y = static_cast<int>(set.cloud.cameras[indx].viewPortOffsetY + cnt * dViewY);

    if(viewPortX != viewPort_X || viewPortY != viewPort_Y){
        viewPortX = viewPort_X;
        viewPortY = viewPort_Y;
        surfacePlot->setViewportShift(viewPortX, viewPortY, false);
    }


    int shift_X = static_cast<int>(set.cloud.cameras[indx].shiftX + cnt * dShiftX);
    int shift_Y = static_cast<int>(set.cloud.cameras[indx].shiftY + cnt * dShiftY);
    int shift_Z = static_cast<int>(set.cloud.cameras[indx].shiftZ + cnt * dShiftZ);

    if(shiftX != shift_X || shiftY != shift_Y || shiftZ != shift_Z){
        shiftX = shift_X;
        shiftY = shift_Y;
        shiftZ = shift_Z;
        surfacePlot->setShift(shiftX, shiftY, shiftZ, false);
    }

    double zoom_ = set.cloud.cameras[indx].zoom + cnt * dZoom;
    if(fabs(zoom_ - zoom) >= std::numeric_limits<double>::epsilon()){
        zoom = zoom_;
        surfacePlot->setZoom(zoom, false);
    }

    double angleX_ = set.cloud.cameras[indx].angleX + cnt * dAngleX;
    double angleY_ = set.cloud.cameras[indx].angleY + cnt * dAngleY;
    double angleZ_ = set.cloud.cameras[indx].angleZ + cnt * dAngleZ;

    if(fabs(angleX_ - angleX) >= std::numeric_limits<double>::epsilon() || fabs(angleY_ - angleY) >= std::numeric_limits<double>::epsilon() || fabs(angleZ_ - angleZ) >= std::numeric_limits<double>::epsilon())
    {
        angleX = angleX_;
        angleY = angleY_;
        angleZ = angleZ_;
        surfacePlot->setRotation(angleX, angleY, angleZ);
    }

}

void WidgetPointCloud::on_cbVerticalFlip_toggled(bool checked)
{
    set.setVerticalFlip(checked);
}


void WidgetPointCloud::on_cbHorizontalFlip_toggled(bool checked)
{
    set.setHorizontalFlip(checked);
}


void  WidgetPointCloud::formatChanged(){

    if(ui->cbVerticalFlip->isChecked() != set.isVerticalFlip())
    {
        ui->cbVerticalFlip->setChecked(set.isVerticalFlip());
    }

    if(ui->cbHorizontalFlip->isChecked() != set.isHorizontalFlip())
    {
        ui->cbHorizontalFlip->setChecked(set.isHorizontalFlip());
    }
}

void  WidgetPointCloud::mirrorChanged(){

    if(ui->cbVerticalFlip->isChecked() != set.isVerticalFlip())
    {
        ui->cbVerticalFlip->setChecked(set.isVerticalFlip());
    }

    if(ui->cbHorizontalFlip->isChecked() != set.isHorizontalFlip())
    {
        ui->cbHorizontalFlip->setChecked(set.isHorizontalFlip());
    }
}


void WidgetPointCloud::loadCameraMove(){

    QString str;
    if(cameraSettings!= nullptr) delete cameraSettings;
    QString path = QStandardPaths::writableLocation(QStandardPaths::ConfigLocation);
    cameraSettings = new QSettings(path + "/AutoRotationSettings660.ini", QSettings::IniFormat);

    uint numberSteps = cameraSettings->value("numberSteps", 0).toUInt();

    if(numberSteps > 0){

        set.cloud.cameras.clear();

        for(uint i=0; i< numberSteps; i++){

            CameraMoving camera;
            str.sprintf("angleX%d", i);
            camera.angleX  = cameraSettings->value(str, 0).toInt();
            str.sprintf("angleY%d", i);
            camera.angleY  = cameraSettings->value(str, 0).toInt();
            str.sprintf("angleZ%d", i);
            camera.angleZ  = cameraSettings->value(str, 0).toInt();

            str.sprintf("viewPortOffsetX%d", i);
            camera.viewPortOffsetX = cameraSettings->value(str, 0).toInt();
            str.sprintf("viewPortOffsetY%d", i);
            camera.viewPortOffsetY = cameraSettings->value(str, 0).toInt();

            str.sprintf("shiftX%d", i);
            camera.shiftX = cameraSettings->value(str, 0).toInt();
            str.sprintf("shiftY%d", i);
            camera.shiftY = cameraSettings->value(str, 0).toInt();
            str.sprintf("shiftZ%d", i);
            camera.shiftZ = cameraSettings->value(str, 0).toInt();

            str.sprintf("zoom%d", i);
            camera.zoom   = cameraSettings->value(str, 1.0).toDouble();

            str.sprintf("numSteps%d", i);
            camera.numSteps = cameraSettings->value(str, 100).toInt();

            str.sprintf("timerSleep%d", i);
            camera.timerSleep = cameraSettings->value(str, 50).toInt();



            set.cloud.cameras.emplace_back(camera);
        }

    }


}

void WidgetPointCloud::saveCameraMove(){

    if(cameraSettings == nullptr)
        return;

    QString str;
    cameraSettings->setValue("numberSteps", QVariant::fromValue(set.cloud.cameras.size()));

    for(uint i=0; i< set.cloud.cameras.size(); i++){

        str.sprintf("angleX%d", i);
        cameraSettings->setValue(str, QVariant::fromValue(set.cloud.cameras[i].angleX));
        str.sprintf("angleY%d", i);
        cameraSettings->setValue(str, QVariant::fromValue(set.cloud.cameras[i].angleY));
        str.sprintf("angleZ%d", i);
        cameraSettings->setValue(str, QVariant::fromValue(set.cloud.cameras[i].angleZ));

        str.sprintf("viewPortOffsetX%d", i);
        cameraSettings->setValue(str, QVariant::fromValue(set.cloud.cameras[i].viewPortOffsetX));
        str.sprintf("viewPortOffsetY%d", i);
        cameraSettings->setValue(str, QVariant::fromValue(set.cloud.cameras[i].viewPortOffsetY));

        str.sprintf("shiftX%d", i);
        cameraSettings->setValue(str, QVariant::fromValue(set.cloud.cameras[i].shiftX));
        str.sprintf("shiftY%d", i);
        cameraSettings->setValue(str, QVariant::fromValue(set.cloud.cameras[i].shiftY));
        str.sprintf("shiftZ%d", i);
        cameraSettings->setValue(str, QVariant::fromValue(set.cloud.cameras[i].shiftZ));

        str.sprintf("zoom%d", i);
        cameraSettings->setValue(str, QVariant::fromValue(set.cloud.cameras[i].zoom));

        str.sprintf("numSteps%d", i);
        cameraSettings->setValue(str, QVariant::fromValue(set.cloud.cameras[i].numSteps));        

        str.sprintf("timerSleep%d", i);
        cameraSettings->setValue(str, QVariant::fromValue(set.cloud.cameras[i].timerSleep));
    }

}

void WidgetPointCloud::onKeyPressed(bool state){
    isKeyPressed = state;
}

void WidgetPointCloud::on_cbPerspectiveView_toggled(bool checked)
{
    surfacePlot->setOrtho(!checked);
}


/// @}













