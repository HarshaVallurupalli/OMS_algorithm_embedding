/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "LabelImage.h"
#include <QDebug>
#include <QMouseEvent>
#include <QFileDialog>
#include <QPainter>

//QObject *LabelImage::currentObject = nullptr;

LabelImage::LabelImage(QWidget *parent):
    QLabel(parent),
    rubberBandLine(QRubberBand::Line, this),
    rubberBandRect(QRubberBand::Rectangle, this)
{
    this->setAttribute(Qt::WA_Hover, true);

    mirrorHorizontal = false;
    mirrorVertical = false;
    rotate = true;
    selectPixelInfoEnable = false;
    selectTimeScopeEnable = false;
    selectPixelScopeEnable = false;
    selectRoiEnable = false;
    pixelInfoSelected = false;
    pixelScopeSelected = false;
    timeScopeSelected  = false;
    imageWidth = 0;
    imageHeight = 0;
    pixmapWidth = 0;
    pixmapHeight = 0;
    ctrlKeyFlag = false;
    altKeyFlag = false;
    shiftKeyFlag = false;
    ctrlAltKeyFlag = false;
    infoX = 0;
    infoY = 0;
    cursorCrosshair = QCursor(QPixmap(":/cursors/cursors/cursor_crosshair.png"));

    setMouseTracking(true);

}

void LabelImage::onSelectionChanged()
{
    showImage();
}

void LabelImage::enterEvent(QEvent *)
{ 
    setCursor(LabelImage::cursorCrosshair);
}

void LabelImage::leaveEvent(QEvent *)
{    
    emit mouseOutOfRange();
}

void LabelImage::selectionPixelInfoCleared()
{        
    infoY = 0;
    infoX = 0;
    pixelInfoSelected = false;    
    showImage();
}


void LabelImage::selectionPixelScopeCleared(){

    pixelScopeSelected = false;
    rubberBandLine.hide();
    showImage();
}

void LabelImage::selectionTimeScopeCleared(){

    timeScopeSelected = false;
    rubberBandRect.hide();
    showImage();
}

void LabelImage::selectPixelInfo(bool state)
{
    selectPixelInfoEnable = state;
}

void LabelImage::selectPixelScope(bool state)
{
    selectPixelScopeEnable = state;
}

void LabelImage::selectTimeScope(bool state)
{
    selectTimeScopeEnable = state;
}

void LabelImage::selectRoi(bool state)
{
    selectRoiEnable = state;
}

void LabelImage::removeAllElements()
{
    pixelInfoSelected = false;
    pixelScopeSelected = false;
    timeScopeSelected = false;    

    emit pixelInfoSelectionCleared(false);
    emit pixelScopeSelectionCleared(false);
    emit timeScopeSelectionCleared(false);

    showImage();
}

int LabelImage::calcPenSize(){

    double sz = pixmapWidth / currentImage.width();
    if(sz < 1.5) return 1;
    else if(sz < 2.5) return 2;
    else return 3;
}


void LabelImage::setFormat(const bool horizontal, const bool vertical, const bool rotate)
{
    this->mirrorHorizontal = horizontal;
    this->mirrorVertical = vertical;
    this->rotate = rotate;
}

void LabelImage::setMirror(const bool horizontal, const bool vertical)
{
    this->mirrorHorizontal = horizontal;
    this->mirrorVertical = vertical;
}


int LabelImage::getCoordinates(int labelSize, int pixmapSize, int mousePosition)
{
    int overLength = labelSize - pixmapSize;
    int result = static_cast<int>(mousePosition - (overLength / 2));

    if(result < 0)  result = -1;
    else if(result > static_cast<int>(pixmapSize))    result = -2;


    return result;
}

bool LabelImage::isOnPixmap(const int x, const int y)
{
    int xPixmapMin = (width() / 2) - (pixmapWidth / 2);
    int xPixmapMax = (width() / 2) + (pixmapWidth / 2);
    int yPixmapMin = (height() / 2) - (pixmapHeight / 2);
    int yPixmapMax = (height() / 2) + (pixmapHeight / 2);

    if (x < xPixmapMin) return false;

    if (x > xPixmapMax) return false;

    if (y < yPixmapMin) return false;

    if (y > yPixmapMax) return false;

    return true;
}

void LabelImage::updateRubber(const int x, const int y)
{
    rubberStopX = x;
    if (rubberStartX > rubberStopX){
        x1 = rubberStopX;
        x2 = rubberStartX;
    }else{
        x1 = rubberStartX;
        x2 = rubberStopX;
    }

    rubberStopY = y;
    if (rubberStartY > rubberStopY){
        y1 = rubberStopY;
        y2 = rubberStartY;
    }else{
        y1 = rubberStartY;
        y2 = rubberStopY;
    }

    if(x1 < 0)        x1 = 0;
    if(x1 > width())  x1 = width();
    if(x2 < 0)        x2 = 0;
    if(x2 > width())  x2 = width();
    if(y1 < 0)        y1 = 0;
    if(y1 > height()) y1 = height();
    if(y2 < 0)        y2 = 0;
    if(y2 > height()) y2 = height();

    rubberBandRect.setGeometry(x1, y1, x2 - x1, y2 - y1);
    rubberBandRect.show();

}

void LabelImage::updateRubberX(const int x)
{
    rubberStopX = x;
    if (rubberStartX > rubberStopX){
        x1 = rubberStopX;
        x2 = rubberStartX;
    }else{
        x1 = rubberStartX;
        x2 = rubberStopX;
    }

    y1 = rubberStartY;

    if(x1 < 0)        x1 = 0;
    if(x1 > width())  x1 = width();
    if(x2 < 0)        x2 = 0;
    if(x2 > width())  x2 = width();
    if(y1 < 0)        y1 = 0;
    if(y1 > height()) y1 = height();

    rubberBandLine.setGeometry(x1, y1, x2 - x1, 3);
    rubberBandLine.show();
}

int LabelImage::convertToFinalXCoordinate(const int x)
{
    //First scale the coordinates to the real image: the pixmap has not the same size as the label and the label not as the real image
    int finalX = scale(x, width(), pixmapWidth, imageWidth);
    finalX = transform(finalX, imageWidth, mirrorHorizontal);
    return finalX;
}

int LabelImage::convertToFinalYCoordinate(const int y)
{
    //First scale the coordinates to the real image: the pixmap has not the same size as the label and the label not as the real image
    int finalY = scale(y, height(), pixmapHeight, imageHeight);
    //Default mirror vertical, because the chip and the QUI imag do not start at the same corner);
    finalY = transform(finalY, imageHeight, mirrorVertical);
    return finalY;
}

int LabelImage::labelToImageX(const int x){

    int finalX = scale(x, width(), pixmapWidth, imageWidth);
    finalX = transform(finalX, imageWidth, mirrorHorizontal);
    return finalX;
}

int LabelImage::labelToImageY(const int y){

    int finalY = scale(y, height(), pixmapHeight, imageHeight);    
    finalY = transform(finalY, imageHeight, mirrorVertical);
    return finalY;
}


int LabelImage::imageToPixmapX(const int x){

    int xPerX = pixmapWidth / imageWidth; //calculate how many pixels per pixel
    if (xPerX == 0)
        xPerX = 1;

    int finalX = x;

    if (mirrorHorizontal) //Handle mirroring
        finalX = imageWidth - finalX - 1;

    int x_out = ((pixmapWidth * finalX) / imageWidth);
    x_out += (xPerX / 2);

    return x_out;
}

int LabelImage::imageToPixmapY(const int y){

    int yPerY = pixmapHeight / imageHeight; //calculate how many pixels per pixel
    if (yPerY == 0)
        yPerY = 1;

    int finalY = y;

    if (mirrorVertical) //handle mirroring
        finalY = imageHeight - finalY - 1;

    int y_out = ((pixmapHeight * finalY) / imageHeight);
    y_out += (yPerY / 2);

    return y_out;
}

int LabelImage::scale(int value, int labelValue, int pixmapValue, int imageValue)
{
    //The pixmap is in the middle of the label, so calculate the difference of the label to the pixmap
    int diff = labelValue - pixmapValue;
    if(diff < 0) diff = 0;

    //Remove the half of the difference to get the real starting point
    value -= (diff / 2);

    double factor = value / static_cast<double>(pixmapValue);
    if(factor > 1.0) factor = 1.0;

    int result = static_cast<int>(factor * imageValue);

    return result;
}

int LabelImage::transform(int value, int imageValue, bool mirror)
{
    int result = value;

    if(mirror)
        result = imageValue - value - 1;

    return result;
}

void LabelImage::swapIfNeeded(int &value1, int &value2)
{
    if (value1 > value2){
        int temp = value1;
        value1 = value2;
        value2 = temp;
    }
}

void LabelImage::setImage(const QImage &image)
{
    this->imageHeight = image.height();
    this->imageWidth = image.width();

    QImage newImage = image.mirrored(mirrorHorizontal, mirrorVertical);
    currentImage = image.mirrored(mirrorHorizontal, mirrorVertical);

    showImage();
}

void LabelImage::showImage()
{
    qDebug()<<".........................LabelImage::showImage()"; //TODO remove

    if((currentImage.width() == 0) || (currentImage.height() == 0))
    {
        return;
    }

    int x, x1, x2, y, y1, y2, w , h;
    QPixmap pixmap = QPixmap::fromImage(currentImage);
    pixmap = pixmap.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    pixmapWidth = pixmap.width();
    pixmapHeight = pixmap.height();


    QPainter painter(&pixmap);
    painter.setPen(QPen(QColor(200, 200, 200), 2));

    if(pixelInfoSelected){
        QPixmap crossHairPixmap = QPixmap(":/cursors/cursors/cursor_crosshair.png");
        x = imageToPixmapX(infoX) - (crossHairPixmap.width() / 2);
        y = imageToPixmapY(infoY) - (crossHairPixmap.height()/ 2);
        painter.drawPixmap(x, y, crossHairPixmap);
    }

    if(pixelScopeSelected){
        x  = pixmapLineBand.x();
        y  = pixmapLineBand.y();
        w  = pixmapLineBand.width();
        x1  = imageToPixmapX(x);
        x2 = imageToPixmapX(x + w);
        y  = imageToPixmapY(y);

        QLine line(x1, y, x2, y);
        painter.drawLine(line);
    }

    if(timeScopeSelected){
        x = pixmapRectBand.x();
        y = pixmapRectBand.y();
        w = pixmapRectBand.width();
        h = pixmapRectBand.height();
        x1 = imageToPixmapX(x);
        y1 = imageToPixmapY(y);
        x2 = imageToPixmapX(x + w);
        y2 = imageToPixmapY(y + h);

        QRectF rect(x1, y1, x2-x1, y2-y1);
        painter.drawRect(rect);
    }

    if(rotate){
        QMatrix rm;
        rm.rotate(90);
        pixmap = pixmap.transformed(rm);
    }

    setPixmap(pixmap.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void LabelImage::mouseDoubleClickEvent(QMouseEvent*){

    emit mouseDoubleClick();
}

//==============================================================================================


void LabelImage::mousePressEvent(QMouseEvent *event)
{
    bool isInside = isOnPixmap(event->x(), event->y());

    if(!isInside || (event->button() != Qt::LeftButton)) return; //pixel outside pixmap or left button only

    rubberStartX = event->x();
    rubberStartY = event->y();
    rubberStopX  = event->x();
    rubberStopY  = event->y();

    if(event->modifiers() == (Qt::AltModifier | Qt::ControlModifier) || selectPixelScopeEnable) //pixel scope
    {
        ctrlAltKeyFlag = true;

        QPalette pal;
        pal.setBrush(QPalette::Highlight, QBrush(Qt::white));
        rubberBandLine.setPalette(pal);        
        updateRubberX(event->x());
        emit clearRubberBandLine();

    }else if(event->modifiers() == Qt::ControlModifier || selectPixelInfoEnable){  //pixel info

        ctrlKeyFlag = true;
        emit clearPixelInfo();

    }else if(event->modifiers() == Qt::AltModifier || selectTimeScopeEnable){  //time scope

        altKeyFlag = true;

        QPalette pal;
        pal.setBrush(QPalette::Highlight, QBrush(Qt::red));
        rubberBandRect.setPalette(pal);
        updateRubber(event->x(), event->y());
        emit clearRubberBandRect();

    } else if(event->modifiers() == Qt::ShiftModifier || selectRoiEnable) { //ROI

        shiftKeyFlag = true;
        QPalette pal;
        pal.setBrush(QPalette::Highlight, QBrush(Qt::green));        
        rubberBandRect.setPalette(pal);

    }else{

        ctrlKeyFlag = false;
        altKeyFlag  = false;        
    }

}


void LabelImage::mouseMoveEvent(QMouseEvent* event)
{
    if(ctrlAltKeyFlag) { //pixel scope

        updateRubberX(event->x());

    }else if(altKeyFlag){ //time scope

        updateRubber(event->x(), event->y());

    } else if(shiftKeyFlag){ //ROI

        int dy1 = (height() - pixmapHeight)/2;
        int dy2 = height() - dy1;

        if(rubberStartY < dy1) rubberStartY = dy1;
        else if(rubberStartY > dy2) rubberStartY = dy2;

        updateRubber(event->x(), height() - rubberStartY);
    }


    if (isOnPixmap(event->x(), event->y())){ //only do this, if the cursor is on the pixmap. The pixmap does not fill the whole label
        int x = convertToFinalXCoordinate(event->x());
        int y = convertToFinalYCoordinate(event->y());
        emit mouseHover(x, y);

    }else{

        emit mouseOutOfRange();
    }

    if(pixmap() == nullptr) return; //cancel, no pixmap yet

    int x = getCoordinates(width(), pixmap()->width(), event->pos().x());
    int y = getCoordinates(height(), pixmap()->height(), event->pos().y());

    double relationX = - 1.0;
    double relationY = - 1.0;

    if(x >= 0){
        relationX = static_cast<double>(x) / pixmap()->width();
        if(mirrorHorizontal){
            relationX = 1.0 - relationX;
        }
    }

    if(y >= 0){
        relationY = static_cast<double>(y) / pixmap()->height();
        if (mirrorVertical){
            relationY = 1.0 - relationY;
        }
    }

    emit mouseChanged(relationX, relationY);
}



void LabelImage::mouseReleaseEvent (QMouseEvent * event){

    if(event->button() == Qt::LeftButton){ //select operations

        if(ctrlKeyFlag) { //select pixel info

            infoX = convertToFinalXCoordinate(event->x());
            infoY = convertToFinalYCoordinate(event->y());                        
            pixelInfoSelected = true;
            emit infoSelected(infoX, infoY);

        }else if(altKeyFlag) { //select time scope

            //First scale the coordinates to the real image: the pixmap has not the same size as the label and the label not as the real image
            x1 = convertToFinalXCoordinate(x1);
            x2 = convertToFinalXCoordinate(x2);
            y1 = convertToFinalYCoordinate(y1);
            y2 = convertToFinalYCoordinate(y2);

            swapIfNeeded(x1, x2); //swap the values; value2 must always be bigger than value1
            swapIfNeeded(y1, y2);

            pixmapRectBand.setX(x1);
            pixmapRectBand.setY(y1);
            pixmapRectBand.setWidth(x2 - x1);
            pixmapRectBand.setHeight(y2 - y1);
            timeScopeSelected = true;

            emit timescopeSelected(x1, x2, y1, y2);            

        }else if(ctrlAltKeyFlag) { //select pixel scope

            //First scale the coordinates to the real image: the pixmap has not the same size as the label and the label not as the real image
            x1 = convertToFinalXCoordinate(x1);
            x2 = convertToFinalXCoordinate(x2);
            y1 = convertToFinalYCoordinate(rubberStartY);

            swapIfNeeded(x1, x2); //swap the values; value2 must always be bigger than value1

            pixmapLineBand.setX(x1);
            pixmapLineBand.setY(y1);
            pixmapLineBand.setWidth(x2 - x1);
            pixmapLineBand.setHeight(2);

            pixelScopeSelected = true;
            emit pixelscopeSelected(x1, x2, y1, y1);


        }else if(shiftKeyFlag){   //roi

            //First scale the coordinates to the real image: the pixmap has not the same size as the label and the label not as the real image
            x1 = convertToFinalXCoordinate(x1);
            x2 = convertToFinalXCoordinate(x2);
            y1 = convertToFinalYCoordinate(y1);
            y2 = convertToFinalYCoordinate(y2);

            //Swap the values; value2 must always be bigger than value1
            swapIfNeeded(x1, x2);
            swapIfNeeded(y1, y2);

            emit regionSelected(x1, x2, y1, y2);
        }

        altKeyFlag = false;
        ctrlKeyFlag = false;
        shiftKeyFlag = false;
        ctrlAltKeyFlag = false;

        //============================

    }else if(event->button() == Qt::RightButton){ //remove operations

        if(event->modifiers() == Qt::ControlModifier) //remove pixel info
        {                        
            pixelInfoSelected = false;
            emit pixelInfoSelectionCleared(false);

        }else if(event->modifiers() == Qt::AltModifier){ //remove timescope

            timeScopeSelected = false;
            emit timeScopeSelectionCleared(false);

        }else if(event->modifiers() == (Qt::AltModifier | Qt::ControlModifier)){ //remove pixel scope

            pixelScopeSelected = false;
            emit pixelScopeSelectionCleared(false);

        }else if(event->modifiers() == (Qt::AltModifier | Qt::ShiftModifier)){    //save image as png

            QPixmap pixmap= *this->pixmap();
            QString filename = QFileDialog::getSaveFileName(this,"save image as", "", ".png");
            if(!filename.isNull())
            {
                //Add file ending, if not present
                if (filename.contains(QString(".png")) == false)                
                    filename.append(".png");

                pixmap.save(filename);
            }

        }else{ //remove all

            removeAllElements();
        }


    } //end if Qt::RighttButton

    rubberBandLine.hide();
    rubberBandRect.hide();

    showImage();

}










