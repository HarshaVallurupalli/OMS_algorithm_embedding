/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "WidgetData.h"
#include "CameraSelection.h"//edit
#include "ui_widget_data.h"
#include "ImageColorizer.h"
#include "math.h"
#include <QDebug>
#include <QKeyEvent>
#include <QDateTime>
#include "Settings.h"//edit

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

    connect(ui->labelLeftImage, &LabelImage::mouseChanged, this, &WidgetData::onDistanceMousePositionChange);
    connect(ui->labelLeftImage, &LabelImage::mouseDoubleClick, this, &WidgetData::onMouseDoubleClick);

    connect(ui->labelLeftImage, &LabelImage::regionSelected, this, &WidgetData::onRoiSelected);
    connect(ui->labelLeftImage, &LabelImage::infoSelected, &context.getSettings().getPixelInfoSelection(), [&context](int x, int y) {context.getSettings().getPixelInfoSelection().setSinglePixel(x, y, 0); });
    connect(ui->labelLeftImage, &LabelImage::timescopeSelected, &context.getSettings().getTimeScopeSelection(), &Selection::setRange);
    connect(ui->labelLeftImage, &LabelImage::pixelscopeSelected, &context.getSettings().getPixelScopeSelection(), &Selection::setRange);
    connect(ui->labelLeftImage, &LabelImage::mouseHover, this, &WidgetData::onMouseHover);
    connect(ui->labelLeftImage, &LabelImage::mouseOutOfRange, this, &WidgetData::onMouseOutOfRange);
    connect(ui->labelLeftImage, &LabelImage::infoSelected, this, &WidgetData::onSelectionPixelInfoChanged);
    connect(ui->labelLeftImage, &LabelImage::timescopeSelected, this, &WidgetData::onSelectionTimeScopeChanged);
    connect(ui->labelLeftImage, &LabelImage::pixelscopeSelected, this, &WidgetData::onSelectionPixelScopeChanged);
    connect(ui->labelLeftImage, &LabelImage::pixelInfoSelectionCleared, this, &WidgetData::selectionPixelInfoCleared);
    connect(ui->labelLeftImage, &LabelImage::pixelScopeSelectionCleared, this, &WidgetData::selectionPixelScopeCleared);
    connect(ui->labelLeftImage, &LabelImage::timeScopeSelectionCleared, this, &WidgetData::selectionTimeScopeCleared);
    connect(ui->labelLeftImage,  &LabelImage::clearPixelInfo, this, &WidgetData::clearPixelInfo);
    connect(ui->labelLeftImage,  &LabelImage::clearRubberBandRect, this,&WidgetData::clearTimeScopeROI);
    connect(ui->labelLeftImage,  &LabelImage::clearRubberBandLine, this, &WidgetData::clearPixelScopeLine);
    connect(ui->labelLeftImage,  &LabelImage::setRoiDefault, &context.getSettings(), &Settings::setRoiDefault);


    connect(ui->labelRightImage, &LabelImage::regionSelected, this, &WidgetData::onRoiSelected);
    connect(ui->labelRightImage, &LabelImage::infoSelected, &context.getSettings().getPixelInfoSelection(), [&context](int x, int y) {context.getSettings().getPixelInfoSelection().setSinglePixel(x, y, 1); });
    connect(ui->labelRightImage, &LabelImage::timescopeSelected, &context.getSettings().getTimeScopeSelection(), &Selection::setRange);
    connect(ui->labelRightImage, &LabelImage::pixelscopeSelected, &context.getSettings().getPixelScopeSelection(), &Selection::setRange);
    connect(ui->labelRightImage, &LabelImage::mouseHover, this, &WidgetData::onMouseHover);
    connect(ui->labelRightImage, &LabelImage::mouseOutOfRange, this, &WidgetData::onMouseOutOfRange);
    connect(ui->labelRightImage, &LabelImage::infoSelected, this, &WidgetData::onSelectionPixelInfoChanged);
    connect(ui->labelRightImage, &LabelImage::timescopeSelected, this, &WidgetData::onSelectionTimeScopeChanged);
    connect(ui->labelRightImage, &LabelImage::pixelscopeSelected, this, &WidgetData::onSelectionPixelScopeChanged);
    connect(ui->labelRightImage, &LabelImage::pixelInfoSelectionCleared, this, &WidgetData::selectionPixelInfoCleared);
    connect(ui->labelRightImage, &LabelImage::pixelScopeSelectionCleared, this, &WidgetData::selectionPixelScopeCleared);
    connect(ui->labelRightImage, &LabelImage::timeScopeSelectionCleared, this, &WidgetData::selectionTimeScopeCleared);        
    connect(ui->labelRightImage, &LabelImage::clearPixelInfo, this, &WidgetData::clearPixelInfo);    
    connect(ui->labelRightImage, &LabelImage::clearRubberBandRect, this, &WidgetData::clearTimeScopeROI);        
    connect(ui->labelRightImage, &LabelImage::clearRubberBandLine, this, &WidgetData::clearPixelScopeLine);        
    connect(ui->labelRightImage, &LabelImage::setRoiDefault, &context.getSettings(), &Settings::setRoiDefault);

   // connect(&context.getSettings(), &Settings::cameraSelectionChanged, this, &WidgetData::onCameraSelectionChanged); //edit
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
    ui->labelLeftImage->onSelectionChanged();
    ui->labelRightImage->onSelectionChanged();
    pixelInfoSelected = true;
    emit selectedPixelInfo(true);
}

void WidgetData::onSelectionPixelScopeChanged()
{
    ui->labelLeftImage->onSelectionChanged();
    ui->labelRightImage->onSelectionChanged();
    pixelScopeSelected = true;
    emit selectedPixelScope(true);
}

void WidgetData::onSelectionTimeScopeChanged()
{
    ui->labelLeftImage->onSelectionChanged();
    ui->labelRightImage->onSelectionChanged();
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
                uint8_t distanceMsb = (uint8_t) pData[2*index+1+dataHeader.offset];
                uint8_t distanceLsb = (uint8_t) pData[2*index+0+dataHeader.offset];

                //Combint to a value
                unsigned int pixelDistance = (distanceMsb << 8) + distanceLsb;

                //Colorize the pixel
                imageDistance.setPixelColor(x, y-y0, imageColorizerDistance.getColor(pixelDistance, ImageColorizer::REDTOBLUE));
            }
        }
    }

    ui->labelLeftImage->setImage(imageDistance);
    ui->labelRightImage->hide();
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
            uint8_t distanceMsb = (uint8_t) pData[4*index+1+dataHeader.offset];
            uint8_t distanceLsb = (uint8_t) pData[4*index+0+dataHeader.offset];

            //Then get the values of the amplitude
            uint8_t amplitudeMsb = (uint8_t) pData[4*index+3+dataHeader.offset];
            uint8_t amplitudeLsb = (uint8_t) pData[4*index+2+dataHeader.offset];

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

    ui->labelLeftImage->setImage(imageDistance);
    ui->labelRightImage->setImage(imageAmplitude);    
    ui->labelRightImage->show();
}

void WidgetData::showGrayscale(const char *pData, DataHeader &dataHeader)
{
    QImage imageGrayscale(dataHeader.width, dataHeader.height, QImage::Format_RGB888);

    imageColorizerGrayscale.setRange(0, 1024);

    int index = 0;
    for (int y = 0; y < dataHeader.height; y++)
    {
        for (int x = 0; x < dataHeader.width; x++)
        {
            //First get the values of the distance
            uint8_t distanceMsb = (uint8_t) pData[2*index+1+dataHeader.offset];
            uint8_t distanceLsb = (uint8_t) pData[2*index+0+dataHeader.offset];

            //Combine to a value
            unsigned int pixelGrayscale = (distanceMsb << 8) + distanceLsb;

            //Colorize the pixel
            imageGrayscale.setPixelColor(x, y, imageColorizerGrayscale.getColor(pixelGrayscale, ImageColorizer::GRAYSCALE));
            index++;
        }
    }

     ui->labelLeftImage->setImage(imageGrayscale);    
    ui->labelRightImage->hide();
}

void WidgetData::showData(const char *pData, DataHeader &dataHeader)
{
    ui->labelLeftImage->setMirror(ui->checkBoxMirrorHorizontal->isChecked(), ui->checkBoxMirrorVertical->isChecked());
    ui->labelLeftImage->setFormat(ui->checkBoxMirrorHorizontal->isChecked(), ui->checkBoxMirrorVertical->isChecked(), ui->checkBoxRotate->isChecked());
    ui->labelRightImage->setFormat(ui->checkBoxMirrorHorizontal->isChecked(), ui->checkBoxMirrorVertical->isChecked(), ui->checkBoxRotate->isChecked());


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
        }
    }



    switch(dataHeader.dataType){    //Image
    case TOFCAM_DATA_DISTANCE_AMPLITUDE:
        showDistanceAmplitude(pData, dataHeader);
        break;
    case TOFCAM_DATA_DISTANCE:
        showDistance(pData, dataHeader);
        break;
    case TOFCAM_DATA_GRAYSCALE:
        showGrayscale(pData, dataHeader);
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
    ui->labelLeftImage->selectionPixelInfoCleared();
    ui->labelRightImage->selectionPixelInfoCleared();
}

void WidgetData::clearTimeScopeROI()
{
    ui->labelLeftImage->selectionTimeScopeCleared();
    ui->labelRightImage->selectionTimeScopeCleared();
}

void WidgetData::clearPixelScopeLine()
{
    ui->labelLeftImage->selectionPixelScopeCleared();
    ui->labelRightImage->selectionPixelScopeCleared();
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
    ui->labelLeftImage->selectPixelInfo(false);
    ui->labelRightImage->selectPixelInfo(false);
    ui->labelLeftImage->selectPixelScope(false);
    ui->labelRightImage->selectPixelScope(false);
    ui->labelLeftImage->selectTimeScope(false);
    ui->labelRightImage->selectTimeScope(false);
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

    ui->labelLeftImage->selectPixelInfo(checked);
    ui->labelRightImage->selectPixelInfo(checked);
    ui->labelLeftImage->selectPixelScope(false);
    ui->labelRightImage->selectPixelScope(false);
    ui->labelLeftImage->selectTimeScope(false);
    ui->labelRightImage->selectTimeScope(false);
    ui->labelLeftImage->selectRoi(false);
    ui->labelRightImage->selectRoi(false);


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
    ui->labelLeftImage->selectPixelInfo(false);
    ui->labelRightImage->selectPixelInfo(false);
    ui->labelLeftImage->selectPixelScope(checked);
    ui->labelRightImage->selectPixelScope(checked);
    ui->labelLeftImage->selectTimeScope(false);
    ui->labelRightImage->selectTimeScope(false);
    ui->labelLeftImage->selectRoi(false);
    ui->labelRightImage->selectRoi(false);

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

    ui->labelLeftImage->selectPixelInfo(false);
    ui->labelRightImage->selectPixelInfo(false);
    ui->labelLeftImage->selectPixelScope(false);
    ui->labelRightImage->selectPixelScope(false);
    ui->labelLeftImage->selectTimeScope(checked);
    ui->labelRightImage->selectTimeScope(checked);
    ui->labelLeftImage->selectRoi(false);
    ui->labelRightImage->selectRoi(false);

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

    ui->labelLeftImage->selectRoi(true);
    ui->labelRightImage->selectRoi(true);
    ui->labelLeftImage->selectPixelInfo(false);
    ui->labelRightImage->selectPixelInfo(false);
    ui->labelLeftImage->selectPixelScope(false);
    ui->labelRightImage->selectPixelScope(false);
    ui->labelLeftImage->selectTimeScope(false);
    ui->labelRightImage->selectTimeScope(false);
}


void WidgetData::on_tbDefaultRoi_clicked()
{
    ui->tbPixelInfo->setChecked(false);
    ui->tbPixelScope->setChecked(false);
    ui->tbTimeScope->setChecked(false);
    ui->tbRoi->setChecked(false);

    emit setRoiDefault();
}
//void WidgetData::onCameraSelectionChanged()
//{
//    switch(context.getSettings().getCameraSelection())
//    {
//    case CameraSelection_e::CAMERA_SELECTION_CAM1:
//        ui->labelNameTop->setText("Camera 1 Streaming");
//        break;
 //   case CameraSelection_e::CAMERA_SELECTION_CAM2:
 //       ui->labelNameTop->setText("Camera 2 Streaming");
//        break;
//    case CameraSelection_e::CAMERA_SELECTION_CAM3:
 //       ui->labelNameTop->setText("Camera 3 not connected");
 //       break;
 //   case CameraSelection_e::CAMERA_SELECTION_CAM4:
 //       ui->labelNameTop->setText("Camera 4 not connected");
  //      break;
//     default:
//        ui->labelNameTop->clear();
 //       break;
 //   }
//}


