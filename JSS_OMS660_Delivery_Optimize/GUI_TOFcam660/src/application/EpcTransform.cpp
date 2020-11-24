/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "EpcTransform.h"
#include <math.h>
#include <QDebug>


EpcTransform::EpcTransform()
{
    initialized = false;
}

const double PI = 3.14159265358979323846264338328;

void EpcTransform::getRect(double &xMin, double &yMin, double &xMax, double &yMax, bool undistorted){

    if(undistorted){
        xMin = xMin_;
        yMin = yMin_;
        xMax = xMax_;
        yMax = yMax_;
    }else{
        xMin = 0;
        yMin = 0;
        xMax = cols_;
        yMax = rows_;
    }
}


void EpcTransform::resetInitialisation(){
    initialized = false;
}

double EpcTransform::getUndistortMapX(unsigned int row,  unsigned int col){
    return mapX[row][col];
}

double EpcTransform::getUndistortMapY(unsigned int row, unsigned int col){
    return mapY[row][col];
}


bool EpcTransform::isInitialised(){
    return initialized;
}

void EpcTransform::initialisation(double angleX, unsigned int cols, unsigned int rows, double *cameraMatrix9, double *distCoeffs8){

    cols_ = cols;
    rows_ = rows;
    colsHalf = cols / 2;
    rowsHalf = rows / 2;

    int l=0;
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++, l++){
            cameraMatrix[i][j] = cameraMatrix9[l];            
        }

    for(int i=0; i<8; i++){
        distCoeffs[i] = distCoeffs8[i];
    }



    double x0, y0, x1, y1;
    undistortion2D(0, 0, x0, y0);
    undistortion2D(cols-1, rows-1, x1, y1);

    double widthHalf  = (x1 - x0) / 2.0;
    double heightHalf = (y1 - y0) / 2.0;

    createUndistortionMap(cols, rows);
    initCartesianCoeff(angleX, cols, rows, widthHalf, heightHalf, x0, y0);

    initialized = true;
}

void EpcTransform::createUndistortionMap(unsigned int cols, unsigned int rows)
{
    double xDest, yDest;

    for(unsigned int y=0; y< rows; y++)
        for(unsigned int x=0; x < cols; x++){
            undistortion2D(x, y, xDest, yDest);
            mapX[y][x] = xDest;
            mapY[y][x] = yDest;
        }
}

void EpcTransform::undistortion2D(double xSrc, double ySrc, double &xDest, double &yDest)
{
    // define temporary variables
    double k[8]={ distCoeffs[0], distCoeffs[1], distCoeffs[2], distCoeffs[3], distCoeffs[4]  };
    double fx = cameraMatrix[0][0];
    double fy = cameraMatrix[1][1];
    double ifx = 1.0 / fx;
    double ify = 1.0 / fy;
    double cx = cameraMatrix[0][2];
    double cy = cameraMatrix[1][2];

    // cancel distortion iteratively
    const int iters = 5;
    double x, y, x0, y0;
    x0 = x = (xSrc - cx) * ifx;
    y0 = y = (ySrc - cy) * ify;

    for(int j=0; j<iters; ++j)
    {
        double r2 = x*x + y*y;
        double icdist = 1/(1 + ((k[4]*r2 + k[1])*r2 + k[0])*r2);
        double deltax = 2*k[2]*x*y + k[3]*(r2 + 2*x*x);
        double deltay = k[2]*(r2 + 2*y*y) + 2*k[3]*x*y;
        x = (x0 - deltax) * icdist;
        y = (y0 - deltay) * icdist;
    }

    xDest = fx * x + cx;
    yDest = fy * y + cy;
}


//sin_angle, cos_angle - camera vertical position angle
void EpcTransform::cartesianTransform3D(double sin_angle, double cos_angle, unsigned int srcX, unsigned int srcY, double srcZ, double &destX, double &destY, double &destZ, double width_offset,  double height_offset, bool undistortion)
{
    if(undistortion){        
        destX = srcZ * koefX_undist[srcY][srcX] + width_offset;
        destY = srcZ * koefY_undist[srcY][srcX] + height_offset;
        destZ = srcZ * koefZ_undist[srcY][srcX];
    }else{
        destX = srcZ * koefX[srcY][srcX] + colsHalf;
        destY = srcZ * koefY[srcY][srcX] + rowsHalf;
        destZ = srcZ * koefZ[srcY][srcX];
    }

    destY = destY - destZ * sin_angle;
    destZ = destZ * cos_angle;

}


void EpcTransform::initCartesianCoeff(double angleGradX, int cols, int rows, double widthHalf, double heightHalf, double x0, double y0)
{   
    double alfa0 = angleGradX * 3.14159265359 / (2 * 180.0);  // grad -> rad
    double step_undist  = alfa0 / widthHalf;
    double step = alfa0 / colsHalf;

    for(int y=0; y < rows; y++){
        for(int x=0; x < cols; x++){

            double x1 = mapX[y][x];
            double y1 = mapY[y][x];
            double alfa = (x1 - widthHalf  - x0) * step_undist;
            double beta = (y1 - heightHalf - y0) * step_undist;
            koefX_undist[y][x] = cos(beta) * sin(alfa);
            koefY_undist[y][x] = sin(beta);
            koefZ_undist[y][x] = cos(alfa) * cos(beta);

            alfa = (x - colsHalf) * step;
            beta = (y - rowsHalf) * step;
            koefX[y][x] = cos(beta) * sin(alfa);
            koefY[y][x] = sin(beta);
            koefZ[y][x] = cos(alfa) * cos(beta);
        }
    }

}

void EpcTransform::rotationX(double angleGrad, unsigned int srcX, unsigned int srcY, double srcZ, double &destX, double &destY, double &destZ){

    double angle = angleGrad * PI / 180.0;
    destX = srcX;
    destZ = srcZ * cos(angle);
    destY = srcY + srcZ * sin(angle);

}
