/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef LABELIMAGE_H
#define LABELIMAGE_H

#include <QLabel>
#include <QRubberBand>

class LabelImage: public QLabel
{
  Q_OBJECT

  public:
    LabelImage(QWidget *parent = nullptr);
    void setImage(const QImage &image);
    void setFormat(const bool horizontal, const bool vertical, const bool rotate);
    void setMirror(const bool horizontal, const bool vertical);
    void onSelectionChanged();
    void selectionPixelInfoCleared();
    void selectionPixelScopeCleared();
    void selectionTimeScopeCleared();
    void selectPixelInfo(bool state);
    void selectPixelScope(bool state);
    void selectTimeScope(bool state);
    void selectRoi(bool state);
    void removeAllElements();

  signals:
    void mouseChanged(const double x, const double y);
    void mouseDoubleClick();    
    void infoSelected(int x, int y);
    void timescopeSelected(int x1, int x2, int y1, int y2);
    void pixelscopeSelected(int x1, int x2, int y1, int y2);
    void regionSelected(int x1, int x2, int y1, int y2);
    void mouseHover(int x, int y);
    void pixelInfoSelectionCleared(bool state);
    void pixelScopeSelectionCleared(bool state);
    void timeScopeSelectionCleared(bool state);
    void mouseOutOfRange();
    void clearPixelInfo();
    void clearRubberBandRect();
    void clearRubberBandLine();
    void setRoiDefault();

  protected:
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent * event);
    virtual void mouseDoubleClickEvent(QMouseEvent*);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);

  private:
    void showImage();    
    void updateRubber(const int x, const int y);
    void updateRubberX(const int x);
    bool isOnPixmap(const int x, const int y);
    int getCoordinates(int labelSize, int pixmapSize, int mousePosition);
    int convertToFinalXCoordinate(const int x);
    int convertToFinalYCoordinate(const int y);    
    int labelToImageX(const int x);
    int labelToImageY(const int y);
    int imageToPixmapX(const int x);
    int imageToPixmapY(const int y);

    int calcPenSize();
    int scale(int value, int labelValue, int pixmapValue, int imageValue);
    int transform(int value, int imageValue, bool mirror);
    void swapIfNeeded(int &value1, int &value2);

    QRubberBand rubberBandLine;
    QRubberBand rubberBandRect;    
    QRect labelRectBand;
    QRect labelLineBand;
    QRect pixmapRectBand;
    QRect pixmapLineBand;

    int infoX;
    int infoY;
    int x1, x2, y1, y2;
    int rubberStartX, rubberStartY, rubberStopX, rubberStopY;    
    bool selectPixelInfoEnable;
    bool selectPixelScopeEnable;
    bool selectTimeScopeEnable;
    bool selectRoiEnable;
    bool pixelInfoSelected;
    bool pixelScopeSelected;
    bool timeScopeSelected;
    bool ctrlKeyFlag;
    bool altKeyFlag;
    bool shiftKeyFlag;
    bool ctrlAltKeyFlag;
    QCursor cursorCrosshair;

    int imageWidth;
    int imageHeight;
    int pixmapWidth;
    int pixmapHeight;

    bool mirrorHorizontal;
    bool mirrorVertical;
    bool rotate;
    QImage currentImage;    
};

#endif // LABELIMAGE_H
