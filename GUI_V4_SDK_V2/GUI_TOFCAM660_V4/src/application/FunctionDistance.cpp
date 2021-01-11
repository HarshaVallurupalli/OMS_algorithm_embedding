/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5:       Copyright (C) 2019 The Qt Company
* - QwtPlot3D: Copyright (C) 2003-2005 Michael Bieber
***************************************************************************************/

#include "FunctionDistance.h"
#include <cmath>
#include <QDebug>

#include <qstring.h>
#include "qwt3d_global.h"
#include "qwt3d_types.h"

#include "qwt3d_color.h"
#include "qwt3d_plot.h"


/// \addtogroup FunctionDistance
/// @{

FunctionDistance::FunctionDistance(int** data_, SurfacePlot *surfacePlot):
Function(surfacePlot),
data(data_){
}

FunctionDistance::~FunctionDistance() {
    qDebug() << "***FunctionDistance destroyed";
}

double FunctionDistance::operator ()(double x, double y){
    uint posX = static_cast<uint>(x);
    uint posY = static_cast<uint>(y);
    return data[posX][posY];
}

/// @}



/// \addtogroup UserColor
/// @{

UserColor::UserColor(Qwt3D::Plot3D* data, unsigned size) : data_(data)
{
    Q_ASSERT(data_);
    reset(size);
}

void UserColor::reset(unsigned size) //
{
    colors_ = ColorVector(size);
    RGBA elem;

    double dsize = size;

    for (unsigned int i=0; i!=size; ++i)
    {
        elem.r = i / dsize;
        elem.g = i / dsize / 4;
        elem.b = 1 - i/dsize;
        elem.a = 1.0;
        colors_[i] = elem;
    }
}

/**
    Assigns a new ColorVector (Also overwrites the constructors size argument)
*/
void UserColor::setColorVector(ColorVector const& cv)
{
    colors_ = cv;
}

void UserColor::setAlpha(double a)
{
    if (a<0 || a>1)
        return;

    RGBA elem;

    for (unsigned int i=0; i!=colors_.size(); ++i)
    {
        elem = colors_[i];
        elem.a = a;
        colors_[i] = elem;
    }
}

void UserColor::setImageWidth(uint width)
{
    _width  = width;
}

void UserColor::setImageHeight(uint height)
{
    _height  = height;
}

Qwt3D::RGBA UserColor::operator()(double, double, double) const
{
    Q_ASSERT(data_);

    uint index = incrementColorIdx(false);
    return colors_[index];
}

Qwt3D::RGBA UserColor::operator()(Qwt3D::Triple const& t) const {
    return this->operator()(t.x,t.y,t.z);
}

void UserColor::setDataUserColor(Qwt3D::Triple **dataUsrColor){
    tripDataUserColor=dataUsrColor;
}

void UserColor::setCellFieldUserColor(Qwt3D::CellField &dataUsrColor){
    cellFieldUsrColor=dataUsrColor;    
}

uint UserColor::incrementColorIdx(bool clear) const{
    static uint cellFieldIdx = 0;
    static int cellPixels = -1;
    Cell cell(3);

    if(clear){
        cellPixels=-1;
        cellFieldIdx=0;
        return 0;
    }else{
        cellPixels++;

        if(cellPixels==3){
            cellPixels=0;
            cellFieldIdx++;
        }
        cell = cellFieldUsrColor[cellFieldIdx];
        return cell[ static_cast<uint>(cellPixels) ];
    }
}
/// @}
