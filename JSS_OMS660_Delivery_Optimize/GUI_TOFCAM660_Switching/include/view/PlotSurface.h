/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5:       Copyright (C) 2019 The Qt Company
* - QwtPlot3D: Copyright (C) 2003-2005 Michael Bieber
***************************************************************************************/

#ifndef PLOT_SURFACE_H
#define PLOT_SURFACE_H

#include "SettingsPointCloud.h"
#include "FunctionDistance.h"
#include "EpcTransform.h"
#include "Settings.h"
#include "qwt3d_surfaceplot.h"
#include "qwt3d_function.h"
#include <QWidget>


using namespace Qwt3D;

class PlotSurface : public SurfacePlot
{
    Q_OBJECT
public:
    explicit PlotSurface(uint width_, uint height_, Settings &set_, QWidget *parent = nullptr);
    ~PlotSurface();
    void initialisation(int scrWidth, int scrHeight);
    void loadDefault(double x, double y, double z, double zoom);
    void setLabelsProperties();
    void displayLabels(bool state);
    void setFullScreenState(bool state);
    void updateResizeGL();

    FunctionDistance *functionDistance;
    EpcTransform epcTransform;    
    StandardColor *stdColor;
    UserColor *usrColor;

signals:
    void fullScreen(bool);
    void keyPressed(bool state);

public slots:
    void updateGUI(int **distance, int **amplitude);
    void updateGraphicAtributes();
    void updateShowColorLegend();

private slots:

    void fovChanged();


protected:
    void keyPressEvent(QKeyEvent *e) override;
    void keyReleaseEvent(QKeyEvent *e) override;
    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
    void mouseDoubleClickEvent(QMouseEvent* e)override;


private:

    Settings &set;
    uint width;
    uint height;
    int screenWidth;
    int screenHeight;

    virtual void createData();
    void setColor();
    void updateColor(int **data);
    void gridRect(uint numCells, double widthCell, double offsetX, double offsetY, double offsetZ, EpcColor &color);
    void gridPolar(double alfaX, uint distMin, uint numCells, double widthCell, double offsetX, double offsetY, double offsetZ, EpcColor &color);
    void axisPiramide3D(double alfaX, double alfaY, double distMin, double distMax, double offsetX, double offsetY, double offsetZ, EpcColor &color);
    void axisPiramide2D(double alfaX, double distMin, double distMax, double offsetX, double offsetY, double offsetZ, EpcColor &color);
    void axisCube2D(double distMin, double distMax, double offsetX, double offsetY, double offsetZ, EpcColor &color);
    void axisCube3D(double distMin, double distMax, double offsetX, double offsetY, double offsetZ, EpcColor &color);
    void drawArc(float cx, float cy, float cz, float r, float start_angle, float arc_angle, int num_segments);
    void drawText(double x, double y, double z, QString &str);
    void createColorMapPixel(int numSteps, int indx, unsigned char &red, unsigned char &green, unsigned char &blue);
    double interpolate( double x, double x0, double y0, double x1, double y1);    
    bool pcFilter(uint d1, uint d2, uint d3, int threshold);
    void loadData(int **distance, int **amplitude, bool cartesian);
    void transformation(double angleGrad, int **data, uint width_, uint height_);
    void displayText(int x, int y, uint z, QString &text);

    bool fullScreenState;
    Qwt3D::Triple** tripData;
    Qwt3D::TripleField tripleField;
    Qwt3D::CellField cellField;
    Qwt3D::ColorVector cvColor;
    Qwt3D::ColorVector cvGray;
    std::vector<Qwt3D::Label> labels;
    Qwt3D::Label label;

};




#endif // PLOT_SURFACE_H
