/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5:       Copyright (C) 2019 The Qt Company
* - QwtPlot3D: Copyright (C) 2003-2005 Michael Bieber
***************************************************************************************/

#ifndef FUNCTION_DISTANCE_H_
#define FUNCTION_DISTANCE_H_

#include "qwt3d_function.h"
#include "qwt3d_color.h"
#include "qwt3d_plot.h"


using namespace Qwt3D;

class FunctionDistance : public Function {
public:
    FunctionDistance(int **data_, SurfacePlot *surfacePlot);
    ~FunctionDistance();
    int **data;
    double operator ()(double x, double y);
};



class Plot3D;

class UserColor : public Color
{
public:
    //! Initializes with data and set up a ColorVector with a size of 100 z values (default);
  explicit UserColor(Qwt3D::Plot3D* data, unsigned size = 100);
    Qwt3D::RGBA operator()(double, double, double) const; //!< Receives z-dependend color from ColorVector
    Qwt3D::RGBA operator()(Qwt3D::Triple const& t) const;
    void setDataUserColor(Qwt3D::Triple** dataUsrColor);
    void setCellFieldUserColor(Qwt3D::CellField &dataUsrColor);
    uint incrementColorIdx(bool clear) const;
    void setColorVector(Qwt3D::ColorVector const& cv);
    void reset(unsigned size=100); //!< Resets the standard colors;
    void setAlpha(double a); //!< Sets unitary alpha value for all colors
    /**
        \brief Creates color vector
        Creates a color vector used by ColorLegend. This is essentially a copy from the internal used vector.
        \return The vector created
    */
    Qwt3D::ColorVector& createVector(Qwt3D::ColorVector& vec) {vec = colors_; return vec;}
    void setImageWidth(uint width);
    void setImageHeight(uint height);

protected:
    Qwt3D::Triple **tripDataUserColor;
    Qwt3D::CellField cellFieldUsrColor;
    Qwt3D::ColorVector colors_;
    Qwt3D::Plot3D* data_;
    uint _width;
    uint _height;
};










#endif // FUNCTION_DISTANCE_H_
