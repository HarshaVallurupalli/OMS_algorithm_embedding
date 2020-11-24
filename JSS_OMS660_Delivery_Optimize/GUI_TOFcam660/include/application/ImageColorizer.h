/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef IMAGE_COLORIZER_H_
#define IMAGE_COLORIZER_H_

#include <QColor>
#include <QImage>
#include <QObject>
#include <QVector>


///This value is added to the pixel codes. Normally the codes start at 16000, e.g. 16001 for low amplitude. In case of high distance ranges this would be a valid value, so
///this offset changes the value for the codes to 64000.
///For compatibility to current systems we do this only if needed because of the range.
static const int PIXEL_CODE_OFFSET = 48000;

//Special codes for pixels without valid data
static const int LOW_AMPLITUDE = (16001 + PIXEL_CODE_OFFSET);
static const int ADC_OVERFLOW = (16002 + PIXEL_CODE_OFFSET);
static const int SATURATION = (16003 + PIXEL_CODE_OFFSET);
static const int INTERFERENCE = (16007 + PIXEL_CODE_OFFSET);

class ImageColorizer : public QObject {
    Q_OBJECT
public:
    explicit ImageColorizer (QObject *parent = nullptr);
    void setRange(int start, int stop);
    enum ColorSpace {GRAYSCALE, BLUETORED, REDTOBLUE};
    QImage& getLegend(ColorSpace colorspace);
    QColor getColor(int value, ColorSpace colorspace);
    ~ImageColorizer();

private:
    QVector<QColor> colorVector;
    QVector<QColor> bwVector;
    QImage legendRedToBlue;
    QImage legendBlueToRed;
    QImage legendGrayscale;
    int begin;
    int end;
    double indexFactorColor;
    double indexFactorBw;
    QColor getCol(int value);
    QColor getColInverted(int value);
    QColor getBw(int value);
    QImage& getColorLegend();
    QImage& getBwLegend();
    double interpolate( double x, double x0, double y0, double x1, double y1);
    void createColorMapPixel(int numSteps, int indx, unsigned char &red, unsigned char &green, unsigned char &blue);
};

#endif // IMAGE_COLORIZER_H_
