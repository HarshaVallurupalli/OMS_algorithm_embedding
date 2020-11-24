/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "SettingsPointCloud.h"


SettingsPointCloud::SettingsPointCloud(QObject *parent) : QObject(parent)
{    
    showAxis2D     = true;
    showAxis3D     = true;
    showGrid       = true;
    autoRotating   = false;
    undistortion   = false;
    cartesian      = false;
    grayPointCloud = false;
    rectGrid       = true;
    pclFilter      = false;
    pclFilterThreshold = 700;
    sensorCenterOffsetX = 0;
    sensorCenterOffsetY = 0;

    points = false;
    pointSize = 2.5;

    cellWidth   = 1000;
    numberCells = 20;

    gridOffsetX = 0;
    gridOffsetY = 0;
    gridOffsetZ = 0;

    zoom = 1.0;

    scaleX = 1.0;
    scaleY = 1.0;
    scaleZ = 1.0;

    angleObjectZ = 0;
    cameraAngleX = -67;
    cameraAngleY = 17;
    cameraAngleZ = 181;
    cameraOffsetX = 0;
    cameraOffsetY = 0;

    colorAxis.r = 1.0;
    colorAxis.g = 1.0;
    colorAxis.b = 1.0;
    colorAxis.a = 0.5;

    colorBackground.r = 0.0;
    colorBackground.g = 0.0;
    colorBackground.b = 0.0;
    colorBackground.a = 1.0;

    colorGrid.r = 1.0;
    colorGrid.g = 1.0;
    colorGrid.b = 1.0;
    colorGrid.a = 0.5;

    axisOffsetX = 0;
    axisOffsetY = 0;
    axisOffsetZ = 0;
    axisLineWidth = 3;

    objectOffsetX = 0;
    objectOffsetY = 0;
    objectOffsetZ = 0;

    showLabels = true;
    showLegend = true;

    labelFont.setFamily("Arial");
    labelFont.setPixelSize(12);
    labelFont.setWeight(QFont::Bold);
    labelFont.setItalic(false);

    setLabelColor(1.0, 1.0, 1.0);

    for(int i=0; i<9; i++)
        cameraMatrix[i] = 0.0;

    cameraMatrix[0] = 1.0;
    cameraMatrix[4] = 1.0;
    cameraMatrix[8] = 1.0;

    for(int i=0; i<8; i++)
        distCoeffs[i] = 0.0;

    fov = 108;

    winPosX   = 0;
    winPosY   = 0;
    winWidth  = 0;
    winHeight = 0;

    defaultViewAngleX = 0;
    defaultViewAngleY = 0;
    defaultViewAngleZ = 0;
    defaultOffsetX = 0;
    defaultOffsetY = 0;
    defaultZoom = 1.0;
}

void SettingsPointCloud::setWinRect(const QRect &rect)
{
    winPosX = rect.x();
    winPosY = rect.y();
    winHeight = rect.height();
    winWidth = rect.width();
}

void SettingsPointCloud::setWinPosX(const int value)
{
    winPosX = value;
}


void SettingsPointCloud::setWinPosY(const int value)
{
    winPosY = value;
}

void SettingsPointCloud::setWinWidth(const int value)
{
    winWidth = value;
}

void SettingsPointCloud::setWinHeight(const int value)
{
    winHeight = value;
}

int SettingsPointCloud::getWinPosX() const
{
    return winPosX;
}


int SettingsPointCloud::getWinPosY() const
{
    return winPosY;
}

int SettingsPointCloud::getWinWidth() const
{
    return winWidth;
}

int SettingsPointCloud::getWinHeight() const
{
    return winHeight;
}


void SettingsPointCloud::setShowAxis2D(bool state){
    showAxis2D = state;
}

bool SettingsPointCloud::isShowAxis2D(){
    return showAxis2D;
}

void SettingsPointCloud::setShowAxis3D(bool state){
    showAxis3D = state;
}

bool SettingsPointCloud::isShowAxis3D(){
    return showAxis3D;
}

void SettingsPointCloud::setShowGrid(bool state){
    showGrid = state;
}

bool SettingsPointCloud::isShowGrid(){
    return showGrid;
}

void SettingsPointCloud::setAutoRotating(bool state){
    autoRotating = state;
}

bool SettingsPointCloud::isAutoRotating(){
    return autoRotating;
}

void SettingsPointCloud::setUndistortion(bool state){
    undistortion = state;
}
bool SettingsPointCloud::isUndistortion(){
    return undistortion;
}

void SettingsPointCloud::setCartesian(bool state){
    cartesian = state;
}
bool SettingsPointCloud::isCartesian(){
    return cartesian;
}

void SettingsPointCloud::setGrayPointCloud(bool state){
    grayPointCloud = state;
}

bool SettingsPointCloud::isGrayPointCloud(){
    return grayPointCloud;
}

void SettingsPointCloud::setPoints(bool state){
    points = state;
}

bool SettingsPointCloud::isPoints(){
    return points;
}

void SettingsPointCloud::setRotate90(bool state)
{
    rotate90 = state;
}

bool SettingsPointCloud::isRotate90()
{
    return  rotate90;
}

void SettingsPointCloud::setPointSize(double value){
    pointSize = value;
}

double SettingsPointCloud::getPointSize(){
    return pointSize;
}

void SettingsPointCloud::setCellWidth(uint width){
    cellWidth = width;
}

uint SettingsPointCloud::getCellWidth(){
    return cellWidth;
}

void SettingsPointCloud::setNumberCells(uint value){
    numberCells = value;
}
uint SettingsPointCloud::getNumberCells(){
    return numberCells;
}

void SettingsPointCloud::setGridOffsetX(int value){
    gridOffsetX = value;
}

int SettingsPointCloud::getGridOffsetX(){
    return gridOffsetX;
}

void SettingsPointCloud::setGridOffsetY(int value){
    gridOffsetY = value;
}

int SettingsPointCloud::getGridOffsetY(){
    return gridOffsetY;
}

void SettingsPointCloud::setGridOffsetZ(int value){
    gridOffsetZ = value;
}

int SettingsPointCloud::getGridOffsetZ(){
    return gridOffsetZ;
}


void SettingsPointCloud::setCameraZoom(double value){
    zoom = value;
}

double SettingsPointCloud::getCameraZoom(){
    return zoom;
}

void SettingsPointCloud::setScaleX(double value){
    scaleX = value;
}

double SettingsPointCloud::getScaleX(){
    return scaleX;
}

void SettingsPointCloud::setScaleY(double value){
    scaleY = value;
}

double SettingsPointCloud::getScaleY(){
    return scaleY;
}
void SettingsPointCloud::setScaleZ(double value){
    scaleZ = value;
}

double SettingsPointCloud::getScaleZ(){
    return scaleZ;
}


void SettingsPointCloud::setAngleObjectZ(int value){
    angleObjectZ = value;
}

int SettingsPointCloud::getAngleObjectZ(){
    return angleObjectZ;
}


void SettingsPointCloud::setCameraAngleX(int value){
    cameraAngleX = value;
}

int  SettingsPointCloud::getCameraAngleX(){
    return cameraAngleX;
}

void SettingsPointCloud::setCameraAngleY(int value){
    cameraAngleY = value;
}

int  SettingsPointCloud::getCameraAngleY(){
    return cameraAngleY;
}

void SettingsPointCloud::setCameraAngleZ(int value){
    cameraAngleZ = value;
}

int  SettingsPointCloud::getCameraAngleZ(){
    return cameraAngleZ;
}

void SettingsPointCloud::setAxisColor(double r, double g, double b, double a){
    colorAxis.r = r;
    colorAxis.g = g;
    colorAxis.b = b;
    colorAxis.a = a;
}

void SettingsPointCloud::setAxisColor(EpcColor &axis){
    colorAxis = axis;
}

void SettingsPointCloud::setAxisColorR(double r){
     colorAxis.r = r;
}
void SettingsPointCloud::setAxisColorG(double g){
     colorAxis.g = g;
}
void SettingsPointCloud::setAxisColorB(double b){
     colorAxis.b = b;
}

void SettingsPointCloud::setAxisColorA(double a){
    colorAxis.a = a;
}

EpcColor& SettingsPointCloud::getAxisColor(){
    return colorAxis;
}

void SettingsPointCloud::setBackgroundColor(double r, double g, double b, double a){
    colorBackground.r = r;
    colorBackground.g = g;
    colorBackground.b = b;
    colorBackground.a = a;
}

void SettingsPointCloud::setBackgroundColor(EpcColor &background){
    colorBackground = background;
}

void SettingsPointCloud::setBackgroundColorR(double r){
    colorBackground.r = r;
}

void SettingsPointCloud::setBackgroundColorG(double g){
    colorBackground.g = g;
}

void SettingsPointCloud::setBackgroundColorB(double b){
    colorBackground.b = b;
}

EpcColor& SettingsPointCloud::getBackgroundColor(){
    return colorBackground;
}

void SettingsPointCloud::setGridColor(EpcColor &value){
   colorGrid = value;
}

void SettingsPointCloud::setGridColor(double r, double g, double b, double a){
    colorGrid.r = r;
    colorGrid.g = g;
    colorGrid.b = b;
    colorGrid.a = a;
}

void SettingsPointCloud::setGridColorR(double r){
    colorGrid.r = r;
}

void SettingsPointCloud::setGridColorG(double g){
    colorGrid.g = g;
}

void SettingsPointCloud::setGridColorB(double b){
    colorGrid.b = b;
}

void SettingsPointCloud::setGridColorA(double a){
    colorGrid.a = a;
}

EpcColor& SettingsPointCloud::getGridColor(){
    return colorGrid;
}

void SettingsPointCloud::setAxisOffsetX(int value){
    axisOffsetX = value;
}

int SettingsPointCloud::getAxisOffsetX(){
    return axisOffsetX;
}

void SettingsPointCloud::setAxisOffsetY(int value){
    axisOffsetY = value;
}

int SettingsPointCloud::getAxisOffsetY(){
    return axisOffsetY;
}

void SettingsPointCloud::setAxisOffsetZ(int value){
    axisOffsetZ = value;
}

int SettingsPointCloud::getAxisOffsetZ(){
    return axisOffsetZ;
}

void SettingsPointCloud::setAxisLineWidth(int value){
    axisLineWidth = value;
}

int SettingsPointCloud::getAxisLineWidth(){
    return axisLineWidth;
}

void SettingsPointCloud::setCameraOffsetX(int value){
    cameraOffsetX = value;
}

int SettingsPointCloud::getCameraOffsetX(){
    return cameraOffsetX;
}

void SettingsPointCloud::setCameraOffsetY(int value){
    cameraOffsetY = value;
}

int SettingsPointCloud::getCameraOffsetY(){
    return cameraOffsetY;
}

void SettingsPointCloud::setObjectOffsetX(int value){
    objectOffsetX = value;
}

int SettingsPointCloud::getObjectOffsetX(){
    return objectOffsetX;
}

void SettingsPointCloud::setObjectOffsetY(int value){
    objectOffsetY = value;
}

int SettingsPointCloud::getObjectOffsetY(){
    return objectOffsetY;
}

void SettingsPointCloud::setObjectOffsetZ(int value){
    objectOffsetZ = value;
}

int SettingsPointCloud::getObjectOffsetZ(){
    return objectOffsetZ;
}

void SettingsPointCloud::setPCLFilter(bool state){
    pclFilter = state;
}

bool SettingsPointCloud::isPCLFilter(){
    return pclFilter;
}

void SettingsPointCloud::setPCLFilterThreshold(int val, bool phase){
    if(phase) pclFilterThresholdPhase = val;
    else      pclFilterThreshold      = val;
}

int SettingsPointCloud::getPCLFilterThreshold(bool phase){
    if(phase)   return pclFilterThresholdPhase;
    else        return pclFilterThreshold;
}

void SettingsPointCloud::setRectGrid(bool state){
    rectGrid = state;
}

bool SettingsPointCloud::isRectGrid(){
    return rectGrid;
}


void SettingsPointCloud::setLabelColorR(double val){
    colorLabel.r = val;
}

void SettingsPointCloud::setLabelColorG(double val){
    colorLabel.g = val;
}

void SettingsPointCloud::setLabelColorB(double val){
    colorLabel.b = val;
}

void SettingsPointCloud::setLabelColor(double r, double g, double b, double a){
    colorLabel.r = r;
    colorLabel.g = g;
    colorLabel.b = b;
    colorLabel.a = a;
}

EpcColor& SettingsPointCloud::getLabelColor(){
    return colorLabel;
}

void SettingsPointCloud::setShowLabels(bool state){
    showLabels = state;
}

bool SettingsPointCloud::isShowLabels(){
    return showLabels;
}

void SettingsPointCloud::setShowLegend(bool state){
    showLegend = state;
    emit showColorLegendChanged();
}
bool SettingsPointCloud::isShowLegend(){
    return showLegend;
}

void SettingsPointCloud::setLabelFont(QFont &font){
    labelFont = font;
}

QFont& SettingsPointCloud::getLabelFont(){
    return labelFont;
}

double* SettingsPointCloud::getDistortionCoeffs(){
    return distCoeffs;
}

double* SettingsPointCloud::getCameraMatrix(){
    return cameraMatrix;
}

void SettingsPointCloud::setCameraMatrixElement(int index, double value){
    cameraMatrix[index] = value;
}

void SettingsPointCloud::setDistortionCoeffElement(int index, double value){
    distCoeffs[index] = value;
}


double SettingsPointCloud::getCameraMatrixElement(int index){
    return cameraMatrix[index];
}

double SettingsPointCloud::getDistortionCoeffElement(int index){
    return distCoeffs[index];
}

void SettingsPointCloud::setSensorCenterOffsetX(int val)
{
    sensorCenterOffsetX = val;
    emit sensorParameterChanged();
}

int SettingsPointCloud::getSensorCenterOffsetX()
{
    return sensorCenterOffsetX;
}

void SettingsPointCloud::setSensorCenterOffsetY(int val)
{
    sensorCenterOffsetY = val;
    emit sensorParameterChanged();
}

int SettingsPointCloud::getSensorCenterOffsetY()
{
    return sensorCenterOffsetY;
}

void SettingsPointCloud::setFOV(int value){
    fov = value;
    emit fovChanged();
}
int SettingsPointCloud::getFOV(){
    return fov;
}

void SettingsPointCloud::setWideField(bool state)
{
    wideField = state;
    emit sensorParameterChanged();
}

bool SettingsPointCloud::isWideField()
{
    return wideField;
}

void SettingsPointCloud::setDefaultViewAngleX(int val)
{
    defaultViewAngleX = val;
}

int SettingsPointCloud::getDefaultViewAngleX()
{
    return defaultViewAngleX;
}

void SettingsPointCloud::setDefaultViewAngleY(int val)
{
    defaultViewAngleY = val;
}

int SettingsPointCloud::getDefaultViewAngleY()
{
    return defaultViewAngleY;
}

void SettingsPointCloud::setDefaultViewAngleZ(int val)
{
    defaultViewAngleZ = val;
}

int SettingsPointCloud::getDefaultViewAngleZ()
{
    return defaultViewAngleZ;
}

void SettingsPointCloud::setDefaultViewOffsetX(int val)
{
    defaultOffsetX = val;
}

int SettingsPointCloud::getDefaultViewOffsetX()
{
    return defaultOffsetX;
}

void SettingsPointCloud::setDefaultViewOffsetY(int val)
{
    defaultOffsetY = val;
}

int SettingsPointCloud::getDefaultViewOffsetY()
{
    return defaultOffsetY;
}

void SettingsPointCloud::setDefaultViewZoom(double val)
{
    defaultZoom = val;
}

double SettingsPointCloud::getDefaultViewZoom()
{
    return defaultZoom;
}


















