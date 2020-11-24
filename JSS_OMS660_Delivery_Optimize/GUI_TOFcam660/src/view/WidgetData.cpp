/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "WidgetData.h"
#include "ui_widget_data.h"
#include "ImageColorizer.h"
#include "math.h"
#include <QDebug>
#include <QKeyEvent>
#include <QDateTime>

const double maxAmplitudeValue = 2900.0;
const unsigned int maxValidValue = 15000;


WidgetData::WidgetData(ApplicationContext &context, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetData),
    settings(context.getSettings())
{
    ui->setupUi(this);
    lastWndowState = Qt::WindowActive;

    widgetInfo = new WidgetInfo(context);
    widgetTimeScope = new WidgetTimeScope(context);
    widgetPixelScope = new WidgetPixelScope(context);

    connect(ui->labelLeftTopImage, &LabelImage::mouseChanged, this, &WidgetData::onDistanceMousePositionChange);
    connect(ui->labelLeftTopImage, &LabelImage::mouseDoubleClick, this, &WidgetData::onMouseDoubleClick);

    connect(ui->labelLeftTopImage, &LabelImage::regionSelected, this, &WidgetData::onRoiSelected);
    connect(ui->labelLeftTopImage, &LabelImage::infoSelected, &context.getSettings().getPixelInfoSelection(), [&context](int x, int y) {context.getSettings().getPixelInfoSelection().setSinglePixel(x, y, 0); });
    connect(ui->labelLeftTopImage, &LabelImage::timescopeSelected, &context.getSettings().getTimeScopeSelection(), &Selection::setRange);
    connect(ui->labelLeftTopImage, &LabelImage::pixelscopeSelected, &context.getSettings().getPixelScopeSelection(), &Selection::setRange);
    connect(ui->labelLeftTopImage, &LabelImage::mouseHover, this, &WidgetData::onMouseHover);
    connect(ui->labelLeftTopImage, &LabelImage::mouseOutOfRange, this, &WidgetData::onMouseOutOfRange);
    connect(ui->labelLeftTopImage, &LabelImage::infoSelected, this, &WidgetData::onSelectionPixelInfoChanged);
    connect(ui->labelLeftTopImage, &LabelImage::timescopeSelected, this, &WidgetData::onSelectionTimeScopeChanged);
    connect(ui->labelLeftTopImage, &LabelImage::pixelscopeSelected, this, &WidgetData::onSelectionPixelScopeChanged);
    connect(ui->labelLeftTopImage, &LabelImage::pixelInfoSelectionCleared, this, &WidgetData::selectionPixelInfoCleared);
    connect(ui->labelLeftTopImage, &LabelImage::pixelScopeSelectionCleared, this, &WidgetData::selectionPixelScopeCleared);
    connect(ui->labelLeftTopImage, &LabelImage::timeScopeSelectionCleared, this, &WidgetData::selectionTimeScopeCleared);
    connect(ui->labelLeftTopImage,  &LabelImage::clearPixelInfo, this, &WidgetData::clearPixelInfo);
    connect(ui->labelLeftTopImage,  &LabelImage::clearRubberBandRect, this,&WidgetData::clearTimeScopeROI);
    connect(ui->labelLeftTopImage,  &LabelImage::clearRubberBandLine, this, &WidgetData::clearPixelScopeLine);
    connect(ui->labelLeftTopImage,  &LabelImage::setRoiDefault, &context.getSettings(), &Settings::setRoiDefault);


    connect(ui->labelRightTopImage, &LabelImage::regionSelected, this, &WidgetData::onRoiSelected);
    connect(ui->labelRightTopImage, &LabelImage::infoSelected, &context.getSettings().getPixelInfoSelection(), [&context](int x, int y) {context.getSettings().getPixelInfoSelection().setSinglePixel(x, y, 1); });
    connect(ui->labelRightTopImage, &LabelImage::timescopeSelected, &context.getSettings().getTimeScopeSelection(), &Selection::setRange);
    connect(ui->labelRightTopImage, &LabelImage::pixelscopeSelected, &context.getSettings().getPixelScopeSelection(), &Selection::setRange);
    connect(ui->labelRightTopImage, &LabelImage::mouseHover, this, &WidgetData::onMouseHover);
    connect(ui->labelRightTopImage, &LabelImage::mouseOutOfRange, this, &WidgetData::onMouseOutOfRange);
    connect(ui->labelRightTopImage, &LabelImage::infoSelected, this, &WidgetData::onSelectionPixelInfoChanged);
    connect(ui->labelRightTopImage, &LabelImage::timescopeSelected, this, &WidgetData::onSelectionTimeScopeChanged);
    connect(ui->labelRightTopImage, &LabelImage::pixelscopeSelected, this, &WidgetData::onSelectionPixelScopeChanged);
    connect(ui->labelRightTopImage, &LabelImage::pixelInfoSelectionCleared, this, &WidgetData::selectionPixelInfoCleared);
    connect(ui->labelRightTopImage, &LabelImage::pixelScopeSelectionCleared, this, &WidgetData::selectionPixelScopeCleared);
    connect(ui->labelRightTopImage, &LabelImage::timeScopeSelectionCleared, this, &WidgetData::selectionTimeScopeCleared);
    connect(ui->labelRightTopImage, &LabelImage::clearPixelInfo, this, &WidgetData::clearPixelInfo);
    connect(ui->labelRightTopImage, &LabelImage::clearRubberBandRect, this, &WidgetData::clearTimeScopeROI);
    connect(ui->labelRightTopImage, &LabelImage::clearRubberBandLine, this, &WidgetData::clearPixelScopeLine);
    connect(ui->labelRightTopImage, &LabelImage::setRoiDefault, &context.getSettings(), &Settings::setRoiDefault);

    //============================

    connect(ui->labelLeftBottomImage, &LabelImage::regionSelected, this, &WidgetData::onRoiSelected);
    connect(ui->labelLeftBottomImage, &LabelImage::infoSelected, &context.getSettings().getPixelInfoSelection(), [&context](int x, int y) {context.getSettings().getPixelInfoSelection().setSinglePixel(x, y, 0); });
    connect(ui->labelLeftBottomImage, &LabelImage::timescopeSelected, &context.getSettings().getTimeScopeSelection(), &Selection::setRange);
    connect(ui->labelLeftBottomImage, &LabelImage::pixelscopeSelected, &context.getSettings().getPixelScopeSelection(), &Selection::setRange);
    connect(ui->labelLeftBottomImage, &LabelImage::mouseHover, this, &WidgetData::onMouseHover);
    connect(ui->labelLeftBottomImage, &LabelImage::mouseOutOfRange, this, &WidgetData::onMouseOutOfRange);
    connect(ui->labelLeftBottomImage, &LabelImage::infoSelected, this, &WidgetData::onSelectionPixelInfoChanged);
    connect(ui->labelLeftBottomImage, &LabelImage::timescopeSelected, this, &WidgetData::onSelectionTimeScopeChanged);
    connect(ui->labelLeftBottomImage, &LabelImage::pixelscopeSelected, this, &WidgetData::onSelectionPixelScopeChanged);
    connect(ui->labelLeftBottomImage, &LabelImage::pixelInfoSelectionCleared, this, &WidgetData::selectionPixelInfoCleared);
    connect(ui->labelLeftBottomImage, &LabelImage::pixelScopeSelectionCleared, this, &WidgetData::selectionPixelScopeCleared);
    connect(ui->labelLeftBottomImage, &LabelImage::timeScopeSelectionCleared, this, &WidgetData::selectionTimeScopeCleared);
    connect(ui->labelLeftBottomImage, &LabelImage::clearPixelInfo, this, &WidgetData::clearPixelInfo);
    connect(ui->labelLeftBottomImage, &LabelImage::clearRubberBandRect, this,&WidgetData::clearTimeScopeROI);
    connect(ui->labelLeftBottomImage, &LabelImage::clearRubberBandLine, this, &WidgetData::clearPixelScopeLine);
    connect(ui->labelLeftBottomImage, &LabelImage::setRoiDefault, &context.getSettings(), &Settings::setRoiDefault);


    connect(ui->labelRightBottomImage, &LabelImage::regionSelected, this, &WidgetData::onRoiSelected);
    connect(ui->labelRightBottomImage, &LabelImage::infoSelected, &context.getSettings().getPixelInfoSelection(), [&context](int x, int y) {context.getSettings().getPixelInfoSelection().setSinglePixel(x, y, 1); });
    connect(ui->labelRightBottomImage, &LabelImage::timescopeSelected, &context.getSettings().getTimeScopeSelection(), &Selection::setRange);
    connect(ui->labelRightBottomImage, &LabelImage::pixelscopeSelected, &context.getSettings().getPixelScopeSelection(), &Selection::setRange);
    connect(ui->labelRightBottomImage, &LabelImage::mouseHover, this, &WidgetData::onMouseHover);
    connect(ui->labelRightBottomImage, &LabelImage::mouseOutOfRange, this, &WidgetData::onMouseOutOfRange);
    connect(ui->labelRightBottomImage, &LabelImage::infoSelected, this, &WidgetData::onSelectionPixelInfoChanged);
    connect(ui->labelRightBottomImage, &LabelImage::timescopeSelected, this, &WidgetData::onSelectionTimeScopeChanged);
    connect(ui->labelRightBottomImage, &LabelImage::pixelscopeSelected, this, &WidgetData::onSelectionPixelScopeChanged);
    connect(ui->labelRightBottomImage, &LabelImage::pixelInfoSelectionCleared, this, &WidgetData::selectionPixelInfoCleared);
    connect(ui->labelRightBottomImage, &LabelImage::pixelScopeSelectionCleared, this, &WidgetData::selectionPixelScopeCleared);
    connect(ui->labelRightBottomImage, &LabelImage::timeScopeSelectionCleared, this, &WidgetData::selectionTimeScopeCleared);
    connect(ui->labelRightBottomImage, &LabelImage::clearPixelInfo, this, &WidgetData::clearPixelInfo);
    connect(ui->labelRightBottomImage, &LabelImage::clearRubberBandRect, this, &WidgetData::clearTimeScopeROI);
    connect(ui->labelRightBottomImage, &LabelImage::clearRubberBandLine, this, &WidgetData::clearPixelScopeLine);
    connect(ui->labelRightBottomImage, &LabelImage::setRoiDefault, &context.getSettings(), &Settings::setRoiDefault);

    //===================

    connect(&context.getSettings(), &Settings::showInfoChanged, this, &WidgetData::selectionPixelInfoCleared);
    connect(&context.getSettings(), &Settings::showPixelScopeChanged, this, &WidgetData::selectionPixelScopeCleared);
    connect(&context.getSettings(), &Settings::showTimeScopeChanged, this, &WidgetData::selectionTimeScopeCleared);
    connect(&context.getSettings(), &Settings::roiChanged, this, &WidgetData::onRoiChanged);
    connect(this, &WidgetData::setRoiDefault, &context.getSettings(), &Settings::setRoiDefault);

    //Some stylesheet setups
    ui->labelFps->setStyleSheet("QLabel { color : red; }");

    screen16_9 = false;
    leftImageSelectionX = -1.0;
    leftImageSelectionY = -1.0;
    firstLogFlag = true;
    pixelInfoSelected = false;
    pixelScopeSelected = false;
    timeScopeSelected = false;

    if(settings.getWinDataWidth()!=0 && settings.getWinDataHeight()!=0){
        this->setGeometry(settings.getWinDataPosX(), settings.getWinDataPosY(), settings.getWinDataWidth(), settings.getWinDataHeight());
    }

}

WidgetData::~WidgetData()
{   
    delete widgetInfo;
    delete widgetTimeScope;
    delete widgetPixelScope;
    delete ui;
}

void WidgetData::onSelectionPixelInfoChanged()
{
    ui->labelLeftTopImage->onSelectionChanged();
    ui->labelRightTopImage->onSelectionChanged();
    ui->labelLeftBottomImage->onSelectionChanged();
    ui->labelRightBottomImage->onSelectionChanged();

    pixelInfoSelected = true;
    emit selectedPixelInfo(true);
}

void WidgetData::onSelectionPixelScopeChanged()
{
    ui->labelLeftTopImage->onSelectionChanged();
    ui->labelRightTopImage->onSelectionChanged();
    ui->labelLeftBottomImage->onSelectionChanged();
    ui->labelRightBottomImage->onSelectionChanged();

    pixelScopeSelected = true;
    emit selectedPixelScope(true);
}

void WidgetData::onSelectionTimeScopeChanged()
{
    ui->labelLeftTopImage->onSelectionChanged();
    ui->labelRightTopImage->onSelectionChanged();
    ui->labelLeftBottomImage->onSelectionChanged();
    ui->labelRightBottomImage->onSelectionChanged();

    timeScopeSelected = true;
    emit selectedTimeScope(true);
}


void WidgetData::selectionPixelInfoCleared(bool state)
{
    if(!state){
        pixelInfoSelected = false;
        widgetInfo->close();
        ui->tbPixelInfo->setChecked(false);
        clearPixelInfo();
    }
}

void WidgetData::selectionPixelScopeCleared(bool state){

    if(!state){
        pixelScopeSelected = false;
        widgetPixelScope->close();
        ui->tbPixelScope->setChecked(false);
        clearPixelScopeLine();
    }
}

void WidgetData::selectionTimeScopeCleared(bool state){

    if(!state){
        timeScopeSelected = false;
        widgetTimeScope->close();
        ui->tbTimeScope->setChecked(false);
        clearTimeScopeROI();
    }
}

void WidgetData::restoreSettings()
{    
    connect(&settings, SIGNAL(startClicked()), this, SLOT(resetFirstLogFlag()));

    if(settings.getWinDataWidth()!=0 && settings.getWinDataHeight()!=0){
        this->setGeometry(settings.getWinDataPosX(), settings.getWinDataPosY(), settings.getWinDataWidth(), settings.getWinDataHeight());
    }

    if(this->settings.getViewType() == Settings::ViewType::DISTANCE_AMPLITUDE){
        ui->checkBoxAmplitudeGrayscale->setVisible(true);
    }else{
        ui->checkBoxAmplitudeGrayscale->setVisible(false);
    }

    ui->checkBoxAmplitudeGrayscale->setChecked(this->settings.isAmplitudeGrayscale());

}

unsigned int WidgetData::calcLog(const unsigned int value)
{
    double multiplier = maxAmplitudeValue / log10(maxAmplitudeValue);

    //get zero
    if(value == 0)
        return 0;

    //get special values, for example ADC_OVERFLOW
    if (value > maxValidValue)    
        return value;

    unsigned int newValue = static_cast<unsigned int>(log10( static_cast<double>(value)) * multiplier);
    return newValue;
}

void WidgetData::updateImage(QLabel &label, const QImage &image)
{
    QImage newImage = image.mirrored(ui->checkBoxMirrorHorizontal->isChecked(), ui->checkBoxMirrorVertical->isChecked());

    QPixmap pixmap = QPixmap::fromImage(newImage);

    label.setPixmap(pixmap.scaled(label.size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    label.repaint();
}

void WidgetData::showDistance(const char *pData, DataHeader &dataHeader)
{
    int y0 = 0;
    int height = dataHeader.height;

    if(screen16_9){
        y0 = 30;
        height = dataHeader.height - 30;
    }

    QImage imageDistance(dataHeader.width, dataHeader.height - 2*y0, QImage::Format_RGB888);

    imageColorizerDistance.setRange(settings.getRangeMin(), settings.getRangeMax());

    ui->checkBoxAmplitudeGrayscale->setVisible(false);

    int index = 0;
    for(int y = 0; y < dataHeader.height; y++){
        for(int x = 0; x < dataHeader.width; x++, index++){

            if(y >= y0 && y < height){
                //First get the values of the distance
                uint8_t distanceMsb = static_cast<uint8_t>(pData[2*index+1+dataHeader.offset]);
                uint8_t distanceLsb = static_cast<uint8_t>(pData[2*index+0+dataHeader.offset]);

                //Combint to a value
                int pixelDistance = (distanceMsb << 8) + distanceLsb;

                //Colorize the pixel
                imageDistance.setPixelColor(x, y-y0, imageColorizerDistance.getColor(pixelDistance, ImageColorizer::REDTOBLUE));
            }
        }
    }

    ui->labelLeftTopImage->setImage(imageDistance);
    ui->labelRightTopImage->hide();
    ui->labelLeftBottomImage->hide();
    ui->labelRightBottomImage->hide();
}

void WidgetData::updateSelectedPixels(const unsigned int distance, const unsigned int amplitude, const int selectionX, const int selectionY)
{
  QString text = QString("x = %1 / y = %2, distance = %3, amplitude = %4").arg(selectionX).arg(selectionY).arg(distance).arg(amplitude);
  ui->labelInfo->setText(text);
}

void WidgetData::showDistanceAmplitude(const char *pData, DataHeader &dataHeader)
{
    int selectionX = -1;
    int selectionY = -1;

    ui->checkBoxAmplitudeGrayscale->setVisible(true);

    if (leftImageSelectionX >= 0.0)
    {
        selectionX = static_cast<int>(leftImageSelectionX * dataHeader.width);
        selectionY = static_cast<int>(leftImageSelectionY * dataHeader.height);
    }

    QImage imageDistance(dataHeader.width, dataHeader.height, QImage::Format_RGB888);
    QImage imageAmplitude(dataHeader.width, dataHeader.height, QImage::Format_RGB888);

    imageColorizerDistance.setRange(settings.getRangeMin(), settings.getRangeMax());
    imageColorizerAmplitude.setRange(0, int(maxAmplitudeValue));

    int index = 0;
    for (int y = 0; y < dataHeader.height; y++)
    {
        for (int x = 0; x < dataHeader.width; x++)
        {
            //First get the values of the distance
            uint8_t distanceMsb = static_cast<uint8_t>(pData[4*index+1+dataHeader.offset]);
            uint8_t distanceLsb = static_cast<uint8_t>(pData[4*index+0+dataHeader.offset]);

            //Then get the values of the amplitude
            uint8_t amplitudeMsb = static_cast<uint8_t>(pData[4*index+3+dataHeader.offset]);
            uint8_t amplitudeLsb = static_cast<uint8_t>(pData[4*index+2+dataHeader.offset]);

            //Combine to a value
            unsigned int pixelDistance = (distanceMsb << 8) + distanceLsb;
            unsigned int pixelAmplitude = (amplitudeMsb << 8) + amplitudeLsb;

            if ((x == selectionX) && (y == selectionY))
            {
                updateSelectedPixels(pixelDistance, pixelAmplitude, selectionX, selectionY);
            }

            ImageColorizer::ColorSpace colorSpace = ImageColorizer::BLUETORED;

            //scale logarithmic only if grayscale amplitude is selected
            if (ui->checkBoxAmplitudeGrayscale->isChecked())
            {
                pixelAmplitude = calcLog(pixelAmplitude);
                colorSpace = ImageColorizer::GRAYSCALE;
            }

            //Colorize the pixel
            imageDistance.setPixelColor(x, y, imageColorizerDistance.getColor(pixelDistance, ImageColorizer::REDTOBLUE));

            imageAmplitude.setPixelColor(x, y, imageColorizerAmplitude.getColor(pixelAmplitude, colorSpace));
            index++;
        }
    }

    ui->labelLeftTopImage->setImage(imageDistance);
    ui->labelRightTopImage->setImage(imageAmplitude);
    ui->labelRightTopImage->show();
    ui->labelLeftBottomImage->hide();
    ui->labelRightBottomImage->hide();

}

void WidgetData::showGrayscale(const char *pData, DataHeader &dataHeader)
{
    QImage imageGrayscale(dataHeader.width, dataHeader.height, QImage::Format_RGB888);

    imageColorizerGrayscale.setRange(0, 2048);

    int index = 0;
    for (int y = 0; y < dataHeader.height; y++)
    {
        for (int x = 0; x < dataHeader.width; x++)
        {
            //First get the values of the distance
            uint8_t distanceMsb = static_cast<uint8_t>(pData[2*index+1+dataHeader.offset]);
            uint8_t distanceLsb = static_cast<uint8_t>(pData[2*index+0+dataHeader.offset]);

            //Combine to a value
            unsigned int pixelGrayscale = (distanceMsb << 8) + distanceLsb;

            //Colorize the pixel
            imageGrayscale.setPixelColor(x, y, imageColorizerGrayscale.getColor(pixelGrayscale, ImageColorizer::GRAYSCALE));
            index++;
        }
    }

    ui->labelLeftTopImage->setImage(imageGrayscale);
    ui->labelRightTopImage->hide();
    ui->labelLeftBottomImage->hide();
    ui->labelRightBottomImage->hide();
}


void WidgetData::showDCS(const char *pData, DataHeader &dataHeader){

    //int selectionX = -1;
    //int selectionY = -1;

    ui->checkBoxAmplitudeGrayscale->setVisible(false);

    //if (leftImageSelectionX >= 0.0)
    //{
    //    selectionX = static_cast<int>(leftImageSelectionX * dataHeader.width);
    //    selectionY = static_cast<int>(leftImageSelectionY * dataHeader.height);
    //}

    QImage imageDCS0(dataHeader.width, dataHeader.height, QImage::Format_RGB888);
    QImage imageDCS1(dataHeader.width, dataHeader.height, QImage::Format_RGB888);
    QImage imageDCS2(dataHeader.width, dataHeader.height, QImage::Format_RGB888);
    QImage imageDCS3(dataHeader.width, dataHeader.height, QImage::Format_RGB888);

    imageColorizerDCS0.setRange(0, 4096);
    imageColorizerDCS1.setRange(0, 4096);
    imageColorizerDCS2.setRange(0, 4096);
    imageColorizerDCS3.setRange(0, 4096);

    uint8_t dcsMsb, dcsLsb;
    unsigned int dcs;

    int index = 0;
    for (int y = 0; y < dataHeader.height; y++){
        for (int x = 0; x < dataHeader.width; x++){
            dcsMsb = static_cast<uint8_t>(pData[2*index+1+dataHeader.offset]);
            dcsLsb = static_cast<uint8_t>(pData[2*index+0+dataHeader.offset]);
            dcs = (dcsMsb << 8) + dcsLsb;
            imageDCS0.setPixelColor(x, y, imageColorizerDCS0.getColor(dcs, ImageColorizer::GRAYSCALE));
            index++;
        }
    }

    for (int y = 0; y < dataHeader.height; y++){
        for (int x = 0; x < dataHeader.width; x++){
            dcsMsb = static_cast<uint8_t>(pData[2*index+1+dataHeader.offset]);
            dcsLsb = static_cast<uint8_t>(pData[2*index+0+dataHeader.offset]);
            dcs = (dcsMsb << 8) + dcsLsb;
            imageDCS2.setPixelColor(x, y, imageColorizerDCS2.getColor(dcs, ImageColorizer::GRAYSCALE));
            index++;
        }
    }

    for (int y = 0; y < dataHeader.height; y++){
        for (int x = 0; x < dataHeader.width; x++){
            dcsMsb = static_cast<uint8_t>(pData[2*index+1+dataHeader.offset]);
            dcsLsb = static_cast<uint8_t>(pData[2*index+0+dataHeader.offset]);
            dcs = (dcsMsb << 8) + dcsLsb;
            imageDCS1.setPixelColor(x, y, imageColorizerDCS1.getColor(dcs, ImageColorizer::GRAYSCALE));
            index++;
        }
    }

    for (int y = 0; y < dataHeader.height; y++){
        for (int x = 0; x < dataHeader.width; x++){
            dcsMsb = static_cast<uint8_t>(pData[2*index+1+dataHeader.offset]);
            dcsLsb = static_cast<uint8_t>(pData[2*index+0+dataHeader.offset]);
            dcs = (dcsMsb << 8) + dcsLsb;
            imageDCS3.setPixelColor(x, y, imageColorizerDCS3.getColor(dcs, ImageColorizer::GRAYSCALE));
            index++;
        }
    }

    ui->labelLeftTopImage->setImage(imageDCS0);
    ui->labelRightTopImage->setImage(imageDCS2);
    ui->labelLeftBottomImage->setImage(imageDCS1);
    ui->labelRightBottomImage->setImage(imageDCS3);
    ui->labelRightTopImage->show();
    ui->labelLeftBottomImage->show();
    ui->labelRightBottomImage->show();
}


void WidgetData::showData(const char *pData, DataHeader &dataHeader)
{
    ui->labelLeftTopImage->setMirror(ui->checkBoxMirrorHorizontal->isChecked(), ui->checkBoxMirrorVertical->isChecked());

    ui->labelLeftTopImage->setFormat(ui->checkBoxMirrorHorizontal->isChecked(), ui->checkBoxMirrorVertical->isChecked(), ui->checkBoxRotate->isChecked());
    ui->labelRightTopImage->setFormat(ui->checkBoxMirrorHorizontal->isChecked(), ui->checkBoxMirrorVertical->isChecked(), ui->checkBoxRotate->isChecked());
    ui->labelLeftBottomImage->setFormat(ui->checkBoxMirrorHorizontal->isChecked(), ui->checkBoxMirrorVertical->isChecked(), ui->checkBoxRotate->isChecked());
    ui->labelRightBottomImage->setFormat(ui->checkBoxMirrorHorizontal->isChecked(), ui->checkBoxMirrorVertical->isChecked(), ui->checkBoxRotate->isChecked());


    if(settings.getShowInfo() && pixelInfoSelected){ //Pixel Info
        widgetInfo->onDataReceived(pData, dataHeader);
    }

    if(settings.getShowTimeScope() && timeScopeSelected){ //Timescope

        switch(dataHeader.dataType){
        case TOFCAM_DATA_DISTANCE_AMPLITUDE:
            emit updateTimeScopeDistanceAmplitude(pData, dataHeader);
            break;
        case TOFCAM_DATA_DISTANCE:
            emit updateTimeScopeDistance(pData, dataHeader);
            break;
        case TOFCAM_DATA_GRAYSCALE:
            emit updateTimeScopeGrayscale(pData, dataHeader);
            break;            
        case TOFCAM_DATA_DCS:
            emit updateTimeScopeDCS(pData, dataHeader);
            break;

        default:
            break;
        }
    }

    if(settings.getShowPixelScope()){ //PixelScope

        switch(dataHeader.dataType){
        case TOFCAM_DATA_DISTANCE_AMPLITUDE:
            widgetPixelScope->onDataReceived(pData, dataHeader, true);
            break;
        case TOFCAM_DATA_DISTANCE:
            widgetPixelScope->onDataReceived(pData, dataHeader, false);
            break;
        case TOFCAM_DATA_GRAYSCALE:
            widgetPixelScope->onDataReceived(pData, dataHeader, false);
            break;
        case TOFCAM_DATA_DCS:                       
            widgetPixelScope->onDCSDataReceived(pData, dataHeader);
            break;

        }
    }

    switch(dataHeader.dataType){    //Image
    case TOFCAM_DATA_DISTANCE_AMPLITUDE:
        showDistanceAmplitude(pData, dataHeader);
        ui->lLeftTop->setText("");
        ui->lLeftBottom->setText("");
        ui->lRightTop->setText("");
        ui->lRightBottom->setText("");
        break;
    case TOFCAM_DATA_DISTANCE:
        showDistance(pData, dataHeader);
        ui->lLeftTop->setText("");
        ui->lLeftBottom->setText("");
        ui->lRightTop->setText("");
        ui->lRightBottom->setText("");
        break;
    case TOFCAM_DATA_GRAYSCALE:
        showGrayscale(pData, dataHeader);        
        ui->lLeftTop->setText("");
        ui->lLeftBottom->setText("");
        ui->lRightTop->setText("");
        ui->lRightBottom->setText("");

        break;
    case TOFCAM_DATA_DCS:
        showDCS(pData, dataHeader);
        ui->lLeftTop->setText("DCS0");
        ui->lLeftBottom->setText("DCS1");
        ui->lRightTop->setText("DCS2");
        ui->lRightBottom->setText("DCS3");
        break;
    default:        
        break;
    }

}


void WidgetData::updateFps(const unsigned int fps)
{
    if(fps == 0)
    {
         ui->labelFps->setVisible(false);
         ui->labelFps->setStyleSheet("QLabel { color : black; }");
    }else{
         ui->labelFps->setVisible(true);
         ui->labelFps->setStyleSheet("QLabel { color : green; }");
    }
    ui->labelFps->setText(QString::number(fps) + "Fps");
}

void WidgetData::onDistanceMousePositionChange(const double x, const double y)
{
    leftImageSelectionX = x;
    leftImageSelectionY = y;
}



void WidgetData::on_tbFullScreen_clicked()
{
    updateView(true);
}




void WidgetData::updateView(bool fullScreen){

    static QString style = this->styleSheet();

    if(fullScreen){
        lastWndowState = this->windowState();
        screen16_9 = true;

        //ui->label->setVisible(false);
        ui->checkBoxMirrorVertical->setVisible(false);
        ui->checkBoxMirrorHorizontal->setVisible(false);
        ui->checkBoxRotate->setVisible(false);
        ui->checkBoxAmplitudeGrayscale->setVisible(false);
        ui->tbFullScreen->setVisible(false);
        ui->tbPixelInfo->setVisible(false);
        ui->tbPixelScope->setVisible(false);
        ui->tbTimeScope->setVisible(false);
        ui->tbRoi->setVisible(false);
        ui->tbDefaultRoi->setVisible(false);

        this->setWindowState(Qt::WindowMaximized);
        this->setWindowState(Qt::WindowFullScreen);
        this->setStyleSheet("background-color: rgb(0, 0, 0, 255)");

    }else{

        screen16_9 = false;
        //ui->label->setVisible(true);
        ui->checkBoxMirrorVertical->setVisible(true);
        ui->checkBoxMirrorHorizontal->setVisible(true);
        ui->checkBoxRotate->setVisible(true);
        ui->checkBoxAmplitudeGrayscale->setVisible(true);
        ui->tbFullScreen->setVisible(true);
        ui->tbPixelInfo->setVisible(true);
        ui->tbPixelScope->setVisible(true);
        ui->tbTimeScope->setVisible(true);
        ui->tbRoi->setVisible(true);
        ui->tbDefaultRoi->setVisible(true);


        this->setWindowState(lastWndowState);
        this->setStyleSheet(style);
    }
}


void WidgetData::keyPressEvent(QKeyEvent *e){

    QWidget::keyPressEvent(e);

    if(e->key() == Qt::Key_Escape){
        updateView(false);
    }

}

void WidgetData::mouseDoubleClickEvent(QMouseEvent* e){
    Q_UNUSED(e)   
    updateView(false);
}

void WidgetData::moveEvent(QMoveEvent *)
{
    QRect rect = this->geometry();
    settings.setWinDataRect(rect);
}

void WidgetData::resizeEvent(QResizeEvent *)
{
    QRect rect = this->geometry();
    settings.setWinDataRect(rect);
}

void WidgetData::closeEvent(QCloseEvent*)
{
    widgetInfo->close();
    widgetPixelScope->close();
    widgetTimeScope->close();
}

void WidgetData::on_checkBoxMirrorHorizontal_toggled(bool checked)
{
    settings.setHorizontalFlip(checked);
}

void WidgetData::on_checkBoxMirrorVertical_toggled(bool checked)
{
    settings.setVerticalFlip(checked);
}

void  WidgetData::mirrorChanged(){

    if(ui->checkBoxMirrorVertical->isChecked() != settings.isVerticalFlip())
    {
        ui->checkBoxMirrorVertical->setChecked(settings.isVerticalFlip());
    }

    if(ui->checkBoxMirrorHorizontal->isChecked() != settings.isHorizontalFlip())
    {
        ui->checkBoxMirrorHorizontal->setChecked(settings.isHorizontalFlip());
    }
}

void  WidgetData::formatChanged(){

    if(ui->checkBoxMirrorVertical->isChecked() != settings.isVerticalFlip())
    {
        ui->checkBoxMirrorVertical->setChecked(settings.isVerticalFlip());
    }

    if(ui->checkBoxMirrorHorizontal->isChecked() != settings.isHorizontalFlip())
    {
        ui->checkBoxMirrorHorizontal->setChecked(settings.isHorizontalFlip());
    }

    if(ui->checkBoxRotate->isChecked() != settings.isRotated())
    {
        ui->checkBoxRotate->setChecked(settings.isRotated());
    }
}
void WidgetData::on_checkBoxAmplitudeGrayscale_toggled(bool checked)
{
    settings.setAmplitudeGrayscale(checked);
}


void WidgetData::onMouseDoubleClick(){

    screen16_9 = !screen16_9;
    updateView(screen16_9);
}

void WidgetData::on_checkBoxRotate_clicked(bool checked)
{
    settings.setRotate(checked);
}

void WidgetData::resetFirstLogFlag()
{
    firstLogFlag = true;
}

void WidgetData::clearPixelInfo()
{
    ui->labelLeftTopImage->selectionPixelInfoCleared();
    ui->labelRightTopImage->selectionPixelInfoCleared();
    ui->labelLeftBottomImage->selectionPixelInfoCleared();
    ui->labelRightBottomImage->selectionPixelInfoCleared();
}

void WidgetData::clearTimeScopeROI()
{
    ui->labelLeftTopImage->selectionTimeScopeCleared();
    ui->labelRightTopImage->selectionTimeScopeCleared();    
    ui->labelLeftBottomImage->selectionTimeScopeCleared();
    ui->labelRightBottomImage->selectionTimeScopeCleared();
}

void WidgetData::clearPixelScopeLine()
{
    ui->labelLeftTopImage->selectionPixelScopeCleared();
    ui->labelRightTopImage->selectionPixelScopeCleared();
    ui->labelLeftBottomImage->selectionPixelScopeCleared();
    ui->labelRightBottomImage->selectionPixelScopeCleared();
}

void WidgetData::logData(const char *pData, uint length){

    QDateTime dateTime = QDateTime::currentDateTime();
    QTime time = dateTime.time();
    int sec = time.second();

    if(sec != second){
        count = 0;
        second = sec;
    }else count++;

    QString str;
    str.sprintf("-%03d", count);

    pathToLoggingDir =  settings.log.getLogPath();
    filenameIdx = settings.log.getLogName() + "_" + dateTime.toString("yyyyMMdd-hhmmss");
    filename = filenameIdx + str;

    QFile::remove(pathToLoggingDir + "/" + filename + ".bin");
    indexFilePathCurrent = settings.log.getLogPath() + "/" + settings.log.getLogName();

    if(firstLogFlag || (indexFilePathLast != indexFilePathCurrent)){
        indexFilePathLast = settings.log.getLogPath() + "/" + settings.log.getLogName();
        indexFilePathCurrent = indexFilePathLast;
        indexFilePath = settings.log.getLogPath() + "/" + filenameIdx + ".idx";
        firstLogFlag = false;
    }

    if(!pathToLoggingDir.isEmpty()){        
        saveDataBin(pData, length, pathToLoggingDir+"/"+filename+".bin");
        saveIndex(indexFilePath, filename);
    }
}


void WidgetData::saveDataBin(const char *pData, uint length, QString filePath){
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly)) {
        QDataStream out(&file);
        out.writeBytes(pData, length);
    }

    file.close();
}

void WidgetData::saveIndex(QString filePath, QString str){
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QTextStream out(&file);
        out << str << "\n";
    }

    file.close();
}

void WidgetData::onRoiSelected(const int x1, const int x2, const int y1, const int y2)
{
  int finalX1 = settings.getRoiSettings().getX1() + x1;
  int finalY1 = settings.getRoiSettings().getY1() + y1;
  int finalX2 = finalX1 + (x2 - x1);
  int finalY2 = finalY1 + (y2 - y1);

  settings.setRoi(finalX1, finalY1, finalX2, finalY2);
}

void WidgetData::onRoiChanged()
{
    //Clear timescope when ROI changes
    settings.getPixelInfoSelection().clear();
    settings.getTimeScopeSelection().clear();
    settings.getPixelScopeSelection().clear();

    emit selectedPixelInfo(false);
    emit selectedPixelScope(false);
    emit selectedTimeScope(false);
}

void WidgetData::onMouseHover(const int x, const int y)
{
  ui->labelCoordinates->setText(QString("x = %1 / y = %2").arg(x).arg(y));
}

void WidgetData::onMouseOutOfRange()
{
  ui->labelCoordinates->setText("");
}




void WidgetData::deselectAllSelections()
{
    ui->labelLeftTopImage->selectPixelInfo(false);
    ui->labelRightTopImage->selectPixelInfo(false);
    ui->labelLeftTopImage->selectPixelScope(false);
    ui->labelRightTopImage->selectPixelScope(false);
    ui->labelLeftTopImage->selectTimeScope(false);
    ui->labelRightTopImage->selectTimeScope(false);

    ui->labelLeftBottomImage->selectPixelInfo(false);
    ui->labelRightBottomImage->selectPixelInfo(false);
    ui->labelLeftBottomImage->selectPixelScope(false);
    ui->labelRightBottomImage->selectPixelScope(false);
    ui->labelLeftBottomImage->selectTimeScope(false);
    ui->labelRightBottomImage->selectTimeScope(false);
}


void WidgetData::on_tbPixelInfo_toggled(bool checked)
{
    if(checked){
        ui->tbPixelInfo->setStyleSheet("QToolButton{background-color: rgb(255, 214, 106);}");
        ui->tbPixelScope->setChecked(false);
        ui->tbTimeScope->setChecked(false);
        ui->tbRoi->setChecked(false);
    }else{
        ui->tbPixelInfo->setStyleSheet("QToolButton{background-color: rgb(35, 142, 194);}");
    }

    ui->labelLeftTopImage->selectPixelInfo(checked);
    ui->labelRightTopImage->selectPixelInfo(checked);
    ui->labelLeftTopImage->selectPixelScope(false);
    ui->labelRightTopImage->selectPixelScope(false);
    ui->labelLeftTopImage->selectTimeScope(false);
    ui->labelRightTopImage->selectTimeScope(false);
    ui->labelLeftTopImage->selectRoi(false);
    ui->labelRightTopImage->selectRoi(false);

    ui->labelLeftBottomImage->selectPixelInfo(checked);
    ui->labelRightBottomImage->selectPixelInfo(checked);
    ui->labelLeftBottomImage->selectPixelScope(false);
    ui->labelRightBottomImage->selectPixelScope(false);
    ui->labelLeftBottomImage->selectTimeScope(false);
    ui->labelRightBottomImage->selectTimeScope(false);
    ui->labelLeftBottomImage->selectRoi(false);
    ui->labelRightBottomImage->selectRoi(false);
}

void WidgetData::on_tbPixelScope_toggled(bool checked)
{
    if(checked){
        ui->tbPixelScope->setStyleSheet("QToolButton{background-color: rgb(255, 214, 106);}");
        ui->tbPixelInfo->setChecked(false);
        ui->tbTimeScope->setChecked(false);
        ui->tbRoi->setChecked(false);
    }else{
        ui->tbPixelScope->setStyleSheet("QToolButton{background-color: rgb(35, 142, 194);}");
    }
    ui->labelLeftTopImage->selectPixelInfo(false);
    ui->labelRightTopImage->selectPixelInfo(false);
    ui->labelLeftTopImage->selectPixelScope(checked);
    ui->labelRightTopImage->selectPixelScope(checked);
    ui->labelLeftTopImage->selectTimeScope(false);
    ui->labelRightTopImage->selectTimeScope(false);
    ui->labelLeftTopImage->selectRoi(false);
    ui->labelRightTopImage->selectRoi(false);

    ui->labelLeftBottomImage->selectPixelInfo(false);
    ui->labelRightBottomImage->selectPixelInfo(false);
    ui->labelLeftBottomImage->selectPixelScope(checked);
    ui->labelRightBottomImage->selectPixelScope(checked);
    ui->labelLeftBottomImage->selectTimeScope(false);
    ui->labelRightBottomImage->selectTimeScope(false);
    ui->labelLeftBottomImage->selectRoi(false);
    ui->labelRightBottomImage->selectRoi(false);
}

void WidgetData::on_tbTimeScope_toggled(bool checked)
{
    if(checked){
        ui->tbTimeScope->setStyleSheet("QToolButton{background-color: rgb(255, 214, 106);}");
        ui->tbPixelInfo->setChecked(false);
        ui->tbPixelScope->setChecked(false);
        ui->tbRoi->setChecked(false);
    }
    else {
        ui->tbTimeScope->setStyleSheet("QToolButton{background-color: rgb(35, 142, 194);}");
    }

    ui->labelLeftTopImage->selectPixelInfo(false);
    ui->labelRightTopImage->selectPixelInfo(false);
    ui->labelLeftTopImage->selectPixelScope(false);
    ui->labelRightTopImage->selectPixelScope(false);
    ui->labelLeftTopImage->selectTimeScope(checked);
    ui->labelRightTopImage->selectTimeScope(checked);
    ui->labelLeftTopImage->selectRoi(false);
    ui->labelRightTopImage->selectRoi(false);

    ui->labelLeftBottomImage->selectPixelInfo(false);
    ui->labelRightBottomImage->selectPixelInfo(false);
    ui->labelLeftBottomImage->selectPixelScope(false);
    ui->labelRightBottomImage->selectPixelScope(false);
    ui->labelLeftBottomImage->selectTimeScope(checked);
    ui->labelRightBottomImage->selectTimeScope(checked);
    ui->labelLeftBottomImage->selectRoi(false);
    ui->labelRightBottomImage->selectRoi(false);
}

void WidgetData::on_tbRoi_toggled(bool checked)
{
    if(checked){
        ui->tbRoi->setStyleSheet("QToolButton{background-color: rgb(255, 214, 106);}");
        ui->tbPixelInfo->setChecked(false);
        ui->tbPixelScope->setChecked(false);
        ui->tbTimeScope->setChecked(false);
    }
    else {
        ui->tbRoi->setStyleSheet("QToolButton{background-color: rgb(35, 142, 194);}");
    }

    ui->labelLeftTopImage->selectRoi(true);
    ui->labelRightTopImage->selectRoi(true);
    ui->labelLeftTopImage->selectPixelInfo(false);
    ui->labelRightTopImage->selectPixelInfo(false);
    ui->labelLeftTopImage->selectPixelScope(false);
    ui->labelRightTopImage->selectPixelScope(false);
    ui->labelLeftTopImage->selectTimeScope(false);
    ui->labelRightTopImage->selectTimeScope(false);

    ui->labelLeftBottomImage->selectRoi(true);
    ui->labelRightBottomImage->selectRoi(true);
    ui->labelLeftBottomImage->selectPixelInfo(false);
    ui->labelRightBottomImage->selectPixelInfo(false);
    ui->labelLeftBottomImage->selectPixelScope(false);
    ui->labelRightBottomImage->selectPixelScope(false);
    ui->labelLeftBottomImage->selectTimeScope(false);
    ui->labelRightBottomImage->selectTimeScope(false);

}


void WidgetData::on_tbDefaultRoi_clicked()
{
    ui->tbPixelInfo->setChecked(false);
    ui->tbPixelScope->setChecked(false);
    ui->tbTimeScope->setChecked(false);
    ui->tbRoi->setChecked(false);

    emit setRoiDefault();
}
