/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef EPCTRANSFORM_H
#define EPCTRANSFORM_H

#include <stdint.h>
#include <vector>

struct Point2d{
    double x;
    double y;
};


#define ROWS 252
#define COLS 328


class EpcTransform
{
public:
    EpcTransform();

    bool isInitialised();
    void resetInitialisation();
    void initialisation(double angleX, unsigned int cols, unsigned int rows, double *cameraMatrix9, double *distCoeffs8);
    void getRect(double &xMin, double &yMin, double &xMax, double &yMax, bool undistorted);
    double getUndistortMapX(unsigned int row, unsigned int col);
    double getUndistortMapY(unsigned int row, unsigned int col);
    void undistortion2D(double xSrc, double ySrc, double &xDest, double &yDest);    
    void cartesianTransform3D(double sin_angle, double cos_angle, unsigned int srcX, unsigned int srcY, double srcZ, double &destX, double &destY, double &destZ, double width_offset,  double height_offset, bool undistortion);
    void rotationX(double angleGrad, unsigned int srcX, unsigned int srcY, double srcZ, double &destX, double &destY, double &destZ);

private:

    unsigned int cols_, rows_;
    double xMin_, yMin_, xMax_, yMax_;
    double mapX[ROWS][COLS];
    double mapY[ROWS][COLS];
    double cameraMatrix[3][3];
    double distCoeffs[8];

    bool initialized;
    int colsHalf;
    int rowsHalf;
    double koefX[ROWS][COLS];
    double koefY[ROWS][COLS];
    double koefZ[ROWS][COLS];

    double koefX_undist[ROWS][COLS];
    double koefY_undist[ROWS][COLS];
    double koefZ_undist[ROWS][COLS];

    void createUndistortionMap(unsigned int cols, unsigned int rows);
    void initCartesianCoeff(double angleGradX, int cols, int rows, double widthHalf, double heightHalf, double x0, double y0);
};

#endif // EPCTRANSFORM_H
