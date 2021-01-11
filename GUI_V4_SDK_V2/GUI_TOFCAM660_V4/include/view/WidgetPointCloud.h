/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5:       Copyright (C) 2019 The Qt Company
* - QwtPlot3D: Copyright (C) 2003-2005 Michael Bieber
***************************************************************************************/

#ifndef WIDGET_POINT_CLOUD_H_
#define WIDGET_POINT_CLOUD_H_


#include "ApplicationContext.h"
#include "WidgetPointCloudSettings.h"
#include "EpcTransform.h"
#include "WindowControls.h"
#include "DataHeader.h"
#include "qwt3d_surfaceplot.h"
#include "qwt3d_function.h"
#include "PlotSurface.h"
#include <QSettings>
#include <QWidget>
#include <QTimer>


using namespace Qwt3D;



namespace Ui {
class WidgetPointCloud;
}

class WidgetPointCloud : public QWidget {
    Q_OBJECT
public:
    explicit WidgetPointCloud(ApplicationContext &context, QWidget *parent = nullptr);
    ~WidgetPointCloud();
    void setPlotMode(Qwt3D::PLOTSTYLE plotstyle);    
    void setPointSize(double value);
    void hideControls();
    void restoreSettings();

protected:
    void resizeEvent(QResizeEvent*);
    void keyPressEvent(QKeyEvent *e);
    void mouseReleaseEvent(QMouseEvent *event);
    void closeEvent (QCloseEvent *event  __attribute__((unused)));    

signals:    
    void updateShowDistance(const char *pData, DataHeader &dataHeader);
    void updateShowDistanceAmplitude(const char *pData, DataHeader &dataHeader);


public slots:
    void showData(const char *pData, DataHeader &dataHeader);    


private slots:

    void setLegendMax(int value);
    void setLegendMin(int value);
    void updateRotation();    
    void initControls();
    void updateControls(transform_e value);
    void updateView(bool fullScreen);
    void fullScreen(bool checked);
    void showDistance(const char *pData, DataHeader &dataHeader);
    void showDistanceAmplitude(const char *pData, DataHeader &dataHeader);
    void onKeyPressed(bool state);

    void on_tbShowControls_clicked();
    void on_tbReset_clicked();
    void on_cbPoints_toggled(bool checked);
    void on_cbGrayPointCloud_toggled(bool checked);
    void on_cbAutoRotating_toggled(bool checked);
    void on_cbSurfaceInterconnect_toggled(bool checked);
    void on_sbSurfaceInterconnect_valueChanged(int arg1);    
    void on_dbPointSize_valueChanged(double arg1);   
    void on_cbCartesian_toggled(bool checked);    
    void on_tbSettings_clicked();
    void on_tbFullScreenPC_clicked();
    void on_cbGrid_toggled(bool checked);
    void on_cbAxis2D_toggled(bool checked);
    void on_cbAxis3D_toggled(bool checked);   
    void on_cbUndistortion_toggled(bool checked);
    void on_tbFront_clicked();
    void on_tbSide_clicked();
    void on_tbTop_clicked();
    void on_cbVerticalFlip_toggled(bool checked);
    void on_cbHorizontalFlip_toggled(bool checked);
    void formatChanged();
    void mirrorChanged();
    void on_cbPerspectiveView_toggled(bool checked);

private:
    void initialisation(bool bLoadDefault = true);
    void flipVertical(int **data);
    void flipHorizontal(int **data);
    void flipping(int **data);
    void setVisibleControlls(bool state);    
    void loadCameraMove();
    void saveCameraMove();

    Ui::WidgetPointCloud *ui;
    Settings &set;
    PlotSurface *surfacePlot;    
    WindowControls *windowControls;
    WidgetPointCloudSettings *widgetPointCloudSettings;
    Qt::WindowStates lastWndowState;
    QSettings *cameraSettings;

    uint width;
    uint height;
    int screenWidth;
    int screenHeight;

    double zoom, angleX, angleY, angleZ;
    int viewPortX, viewPortY;
    int shiftX, shiftY, shiftZ;


    QTimer* timer;    
    double currentZoom;
    double rotationAngle;
    bool roiChanged;
    bool isKeyPressed;
    bool firstAutorotation;    
    bool fullScreenState;
    int **tempDataPixelfield;
    int **distanceData;
    int **amplitudeData;
    uint indx;
};

#endif // WIDGET_POINT_CLOUD_H_
