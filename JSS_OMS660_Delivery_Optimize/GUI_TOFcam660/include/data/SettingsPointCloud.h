/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef SETTINGS_POINT_CLOUD_H
#define SETTINGS_POINT_CLOUD_H

#include <QObject>
#include <QFont>
#include <QRect>


struct EpcColor{

    double r;
    double g;
    double b;
    double a;
};


struct CameraMoving{

    int angleX;
    int angleY;
    int angleZ;
    double zoom;
    int shiftX;
    int shiftY;
    int shiftZ;
    int viewPortOffsetX;
    int viewPortOffsetY;
    int timerSleep;
    int numSteps;

};



class SettingsPointCloud : public QObject
{
    Q_OBJECT
public:
    explicit SettingsPointCloud(QObject *parent = nullptr);

    std::vector<CameraMoving> cameras;

    void setWinRect(const QRect &rect);
    void setWinPosX(const int value);
    void setWinPosY(const int value);
    void setWinWidth(const int value);
    void setWinHeight(const int value);

    int getWinPosX() const;
    int getWinPosY() const;
    int getWinWidth() const;
    int getWinHeight() const;

    void setShowAxis2D(bool state);
    bool isShowAxis2D();

    void setShowAxis3D(bool state);
    bool isShowAxis3D();

    void setShowGrid(bool state);
    bool isShowGrid();

    void setAutoRotating(bool state);
    bool isAutoRotating();

    void setUndistortion(bool state);
    bool isUndistortion();

    void setCartesian(bool state);
    bool isCartesian();

    void setGrayPointCloud(bool state);
    bool isGrayPointCloud();

    void setPoints(bool state);
    bool isPoints();

    void setRotate90(bool state);
    bool isRotate90();


    void setPCLFilter(bool state);
    bool isPCLFilter();
    void setPCLFilterThreshold(int val, bool phase = false);
    int  getPCLFilterThreshold(bool phase = false);

    void setPointSize(double value);
    double getPointSize();


    void setCellWidth(uint width);
    uint getCellWidth();
    void setNumberCells(uint value);
    uint getNumberCells();


    void setAxisOffsetX(int value);
    int  getAxisOffsetX();
    void setAxisOffsetY(int value);
    int  getAxisOffsetY();
    void setAxisOffsetZ(int value);
    int  getAxisOffsetZ();
    void setAxisLineWidth(int value);
    int  getAxisLineWidth();

    void setRectGrid(bool state);
    bool isRectGrid();
    void setGridOffsetX(int value);
    int  getGridOffsetX();
    void setGridOffsetY(int value);
    int  getGridOffsetY();
    void setGridOffsetZ(int value);
    int  getGridOffsetZ();

    void setCameraZoom(double value);
    double getCameraZoom();    
    void setScaleX(double value);
    double getScaleX();
    void setScaleY(double value);
    double getScaleY();
    void setScaleZ(double value);
    double getScaleZ();

    void setAngleObjectZ(int value);
    int  getAngleObjectZ();
    void setCameraAngleX(int value);
    int  getCameraAngleX();
    void setCameraAngleY(int value);
    int  getCameraAngleY();
    void setCameraAngleZ(int value);
    int  getCameraAngleZ();
    void setCameraOffsetX(int value);
    int getCameraOffsetX();
    void setCameraOffsetY(int value);
    int getCameraOffsetY();

    void setObjectOffsetX(int value);
    int getObjectOffsetX();
    void setObjectOffsetY(int value);
    int getObjectOffsetY();
    void setObjectOffsetZ(int value);
    int getObjectOffsetZ();

    void setAxisColor(double r, double g, double b, double a);
    void setAxisColor(EpcColor &axis);    
    void setAxisColorR(double r);
    void setAxisColorG(double g);
    void setAxisColorB(double b);
    void setAxisColorA(double a);

    EpcColor &getAxisColor();
    void setBackgroundColor(double r, double g, double b, double a);
    void setBackgroundColor(EpcColor &background);
    void setBackgroundColorR(double r);
    void setBackgroundColorG(double g);
    void setBackgroundColorB(double b);

    EpcColor &getBackgroundColor();
    void setGridColor(double r, double g, double b, double a);
    void setGridColor(EpcColor &value);
    void setGridColorR(double r);
    void setGridColorG(double gr);
    void setGridColorB(double b);
    void setGridColorA(double a);
    EpcColor &getGridColor();

    void setLabelColorR(double val);
    void setLabelColorG(double val);
    void setLabelColorB(double val);
    void setLabelColor(double r, double g, double b, double a = 1.0);
    EpcColor &getLabelColor();
    void setShowLabels(bool state);
    bool isShowLabels();
    void setShowLegend(bool state);
    bool isShowLegend();
    void setLabelFont(QFont &font);
    QFont &getLabelFont();

    double *getDistortionCoeffs();
    double *getCameraMatrix();
    void setCameraMatrixElement(int index, double value);
    void setDistortionCoeffElement(int index, double value);
    double getCameraMatrixElement(int index);
    double getDistortionCoeffElement(int index);

    void setSensorCenterOffsetX(int val);
    int getSensorCenterOffsetX();

    void setSensorCenterOffsetY(int val);
    int getSensorCenterOffsetY();

    void setFOV(int value);
    int getFOV();

    void setWideField(bool state);
    bool isWideField();

    void setDefaultViewAngleX(int val);
    int  getDefaultViewAngleX();
    void setDefaultViewAngleY(int val);
    int  getDefaultViewAngleY();
    void setDefaultViewAngleZ(int val);
    int  getDefaultViewAngleZ();

    void setDefaultViewOffsetX(int val);
    int  getDefaultViewOffsetX();
    void setDefaultViewOffsetY(int val);
    int  getDefaultViewOffsetY();

    void setDefaultViewZoom(double val);
    double getDefaultViewZoom();


signals:    
    void fovChanged();
    void showColorLegendChanged();
    void sensorParameterChanged();



public slots:


private:

    int winPosX;
    int winPosY;
    int winWidth;
    int winHeight;

    bool wideField;
    bool isGrayscale;
    bool showPoints;

    bool showAxis2D;
    bool showAxis3D;
    bool showGrid;
    bool rotate90;

    bool autoRotating;
    bool undistortion;
    bool cartesian;
    bool grayPointCloud;
    bool rectGrid;

    bool showLabels;
    bool showLegend;

    bool   pclFilter;
    int    pclFilterThreshold;
    int    pclFilterThresholdPhase;

    bool points;
    double pointSize;

    uint cellWidth;
    uint numberCells;
    int axisOffsetX;
    int axisOffsetY;
    int axisOffsetZ;
    int axisLineWidth;

    int gridOffsetX;
    int gridOffsetY;
    int gridOffsetZ;

    int objectOffsetX;
    int objectOffsetY;
    int objectOffsetZ;

    int angleObjectZ;
    int cameraAngleX;
    int cameraAngleY;
    int cameraAngleZ;
    int cameraOffsetX;
    int cameraOffsetY;
    double scaleX;
    double scaleY;
    double scaleZ;
    double zoom;

    int defaultViewAngleX;
    int defaultViewAngleY;
    int defaultViewAngleZ;
    int defaultOffsetX;
    int defaultOffsetY;
    double defaultZoom;

    int sensorCenterOffsetX;
    int sensorCenterOffsetY;

    QFont labelFont;
    EpcColor colorAxis;
    EpcColor colorBackground;
    EpcColor colorGrid;
    EpcColor colorLabel;

    int fov;
    double cameraMatrix[9];
    double distCoeffs[8];


};

#endif // SETTINGS_POINT_CLOUD_H
