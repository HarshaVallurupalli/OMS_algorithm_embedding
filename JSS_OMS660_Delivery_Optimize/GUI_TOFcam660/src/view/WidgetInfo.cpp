/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "WidgetInfo.h"
#include "ui_widget_info.h"
#include "MeasurementType.h"
#include "ImageColorizer.h"
#include <math.h>


const unsigned int STATISTICS_NUBER_OF_VALUES = 100;

WidgetInfo::WidgetInfo(ApplicationContext &context, QWidget *parent) :
    QWidget(parent),
    context(context),
    ui(new Ui::WidgetInfo),
    statisticsDistance(STATISTICS_NUBER_OF_VALUES),
    statisticsAmplitude(STATISTICS_NUBER_OF_VALUES),
    statisticsGrayscale(STATISTICS_NUBER_OF_VALUES)
{
    ui->setupUi(this);

    setWindowFlags ( Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowStaysOnTopHint | Qt::WindowCloseButtonHint);
    //Settings update
    connect(&context.getSettings(), &Settings::showInfoChanged, this, &WidgetInfo::onShowInfoChanged);
    connect(&context.getSettings(), &Settings::measurementTypeChanged, this, &WidgetInfo::onMeasurementTypeChanged);
    connect(&context.getSettings().getPixelInfoSelection(), qOverload<int, int, int, int>(&Selection::selectionChanged), this, &WidgetInfo::onSelectionChanged);
    connect(&context.getSettings().getPixelInfoSelection(), qOverload<int, int, int, int, int>(&Selection::selectionChanged), this, &WidgetInfo::onSelectionChanged);

    numMeasurements = 0;
    updateAmplitude = false;
    updateDistance = false;
    updateGrayscale = false;
    updateDcs = false;

    fpsTimer = new QTimer(this);
    connect(fpsTimer, &QTimer::timeout, this, &WidgetInfo::onFpsTimerTimeout);
    fpsTimer->start(1000);

    onMeasurementTypeChanged();
    onSelectionChanged(context.getSettings().getPixelInfoSelection().getX(), context.getSettings().getPixelInfoSelection().getY(), context.getSettings().getPixelInfoSelection().getWidth(), context.getSettings().getPixelInfoSelection().getHeight());

    if(context.getSettings().getPixelInfoRect().width() !=0 && context.getSettings().getPixelInfoRect().height() !=0 ){
        this->setGeometry(context.getSettings().getPixelInfoRect());
    }

    ui->labelTemperature->setVisible(false);

}

WidgetInfo::~WidgetInfo()
{
    delete fpsTimer;
    delete ui;
}

void WidgetInfo::closeEvent(QCloseEvent *event  __attribute__((unused)))
{    
    context.getSettings().setShowInfo(false);    
    context.getSettings().setPixelInfoRect(this->geometry());
}

void WidgetInfo::onShowInfoChanged(const bool checked)
{
    if(checked){
        show();

    }else{
        hide();
    }
}

void WidgetInfo::clearDataLeft()
{
    ui->labelCurrentLeft->setText("-");
    ui->labelVariationLeft->setText("-");
    ui->labelAverageLeft->setText("-");
    ui->labelMaximumLeft->setText("-");
    ui->labelMinimumLeft->setText("-");
}

void WidgetInfo::clearDataRight()
{
    ui->labelCurrentRight->setText("-");
    ui->labelVariationRight->setText("-");
    ui->labelAverageRight->setText("-");
    ui->labelMaximumRight->setText("-");
    ui->labelMinimumRight->setText("-");
}

void WidgetInfo::setDistance(const unsigned int distance, const unsigned int confidence)
{

    if(distance >= LOW_AMPLITUDE){

        ui->labelCurrentLeft->setText("N/A");
        ui->labelVariationLeft->setText("N/A");
        ui->labelAverageLeft->setText("N/A");
        ui->labelMaximumLeft->setText("N/A");
        ui->labelMinimumLeft->setText("N/A");
        ui->labelCurrentRight->setText("N/A");

    }else{

        statisticsDistance.addSample(static_cast<double>(distance));

        ui->labelCurrentLeft->setText(QString::number(distance) + "mm");
        ui->labelCurrentRight->setText(QString::number(confidence));

        if ((fabs(statisticsDistance.getAverage()) < 0.000001) && (fabs(statisticsDistance.getStandardDeviation()) < 0.000001) &&
                (fabs(statisticsDistance.getMin()) < 0.000001) && (fabs(statisticsDistance.getMax()) < 0.000001))
        {
            ui->labelVariationLeft->setText("-");
            ui->labelAverageLeft->setText("-");
            ui->labelMaximumLeft->setText("-");
            ui->labelMinimumLeft->setText("-");

        }else{

            ui->labelVariationLeft->setText(QString::number(statisticsDistance.getStandardDeviation(), 'f', 1) + "mm");
            ui->labelAverageLeft->setText(QString::number(statisticsDistance.getAverage(), 'f', 1) + "mm");
            ui->labelMaximumLeft->setText(QString::number(statisticsDistance.getMax(), 'f', 1) + "mm");
            ui->labelMinimumLeft->setText(QString::number(statisticsDistance.getMin(), 'f', 1) + "mm");
        }
    }
}

void WidgetInfo::setAmplitude(const unsigned int amplitude)
{
    if (amplitude >= LOW_AMPLITUDE)
    {
        ui->labelCurrentRight->setText("N/A");
        ui->labelVariationRight->setText("N/A");
        ui->labelAverageRight->setText("N/A");
        ui->labelMaximumRight->setText("N/A");
        ui->labelMinimumRight->setText("N/A");
    } else {
        statisticsAmplitude.addSample(static_cast<double>(amplitude));

        //Print the first pixel at the moment
        ui->labelCurrentRight->setText(QString::number(amplitude) + "lsb");

        if ((fabs(statisticsAmplitude.getAverage()) < 0.000001) && (fabs(statisticsAmplitude.getStandardDeviation()) < 0.000001) &&
            (fabs(statisticsAmplitude.getMin()) < 0.000001) &&  (fabs(statisticsAmplitude.getMax()) < 0.000001))
        {
            ui->labelVariationRight->setText("-");
            ui->labelAverageRight->setText("-");
            ui->labelMaximumRight->setText("-");
            ui->labelMinimumRight->setText("-");

        } else {

            ui->labelVariationRight->setText(QString::number(statisticsAmplitude.getStandardDeviation(), 'f', 1) + "lsb");
            ui->labelAverageRight->setText(QString::number(statisticsAmplitude.getAverage(), 'f', 1) + "lsb");
            ui->labelMaximumRight->setText(QString::number(statisticsAmplitude.getMax(), 'f', 1) + "lsb");
            ui->labelMinimumRight->setText(QString::number(statisticsAmplitude.getMin(), 'f', 1) + "lsb");
        }
    }
}

void WidgetInfo::setGrayscale(const unsigned int grayscale)
{
    if (grayscale >= LOW_AMPLITUDE)
    {
        ui->labelCurrentRight->setText("N/A");
        ui->labelVariationRight->setText("N/A");
        ui->labelAverageRight->setText("N/A");
        ui->labelMaximumRight->setText("N/A");
        ui->labelMinimumRight->setText("N/A");
    }else {
        statisticsAmplitude.addSample(static_cast<double>(grayscale));

        //Print the first pixel at the moment
        ui->labelCurrentRight->setText(QString::number(grayscale) + "lsb");

        if ((fabs(statisticsAmplitude.getAverage()) < 0.000001) &&
            (fabs(statisticsAmplitude.getStandardDeviation()) < 0.0000010) &&
            (fabs(statisticsAmplitude.getMin()) < 0.000001) &&
            (fabs(statisticsAmplitude.getMax()) < 0.000001))
        {
            ui->labelVariationRight->setText("-");
            ui->labelAverageRight->setText("-");
            ui->labelMaximumRight->setText("-");
            ui->labelMinimumRight->setText("-");
        }
        else
        {
            ui->labelVariationRight->setText(QString::number(statisticsAmplitude.getStandardDeviation(), 'f', 1) + "lsb");
            ui->labelAverageRight->setText(QString::number(statisticsAmplitude.getAverage(), 'f', 1) + "lsb");
            ui->labelMaximumRight->setText(QString::number(statisticsAmplitude.getMax(), 'f', 1) + "lsb");
            ui->labelMinimumRight->setText(QString::number(statisticsAmplitude.getMin(), 'f', 1) + "lsb");
        }
    }
}

void WidgetInfo::setDcs(const unsigned int dcs0, const unsigned int dcs1, const unsigned int dcs2, const unsigned int dcs3)
{
   if (dcs0 >= LOW_AMPLITUDE || dcs1 >= LOW_AMPLITUDE || dcs2 >= LOW_AMPLITUDE || dcs3 >= LOW_AMPLITUDE)
   {
        ui->lDCS0->setText("N/A");
        ui->lDCS1->setText("N/A");
        ui->lDCS2->setText("N/A");
        ui->lDCS3->setText("N/A");

    } else {

       QString str;
       str.sprintf("%d lsb", dcs0);
       ui->lDCS0->setText(str);
       str.sprintf("%d lsb", dcs2);
       ui->lDCS1->setText(str);
       str.sprintf("%d lsb", dcs1);
       ui->lDCS2->setText(str);
       str.sprintf("%d lsb", dcs3);
       ui->lDCS3->setText(str);
    }
}

void WidgetInfo::onDataReceived(const char *pData, DataHeader &dataHeader)
{
    numMeasurements++;
    //ui->labelTemperature->setText("Temperature: " + image->getTemperatureC());

    unsigned int pixelIndex = context.getSettings().getPixelInfoSelection().getPixelIndex(dataHeader.width);

    if(pixelIndex >= dataHeader.width * dataHeader.height) //---- Cancel ----
    {
        return;
    }

    if(updateDistance){
        setDistance(getPixelValue(pData, dataHeader, pixelIndex, 0), 0);
    }

    if(updateAmplitude){
        setAmplitude(getPixelValue(pData, dataHeader, pixelIndex, 1));
    }

    if(updateGrayscale){
        setGrayscale(getPixelValue(pData, dataHeader, pixelIndex, 0));
    }

    if(updateDcs){
        uint dcs0, dcs1, dcs2, dcs3;        
        getDCSPixelValue(pData, dataHeader, pixelIndex, dcs0, dcs1, dcs2, dcs3);
        setDcs(dcs0, dcs1, dcs2, dcs3);
    }
}

void WidgetInfo::onMeasurementTypeChanged()
{
    statisticsAmplitude.clear();
    statisticsDistance.clear();
    statisticsGrayscale.clear();

    clearDataRight();
    clearDataLeft();

    updateAmplitude = false;
    updateDistance = false;
    updateGrayscale = false;
    updateDcs = false;

    ui->widgetDistanceAmplitude->hide();
    ui->widgetDCS->hide();

    switch(context.getSettings().getMeasurementType())
    {
    case MeasurementType_e::MEASUREMENT_TYPE_DISTANCE:
        ui->labelNameLeft->setText("Distance");
        ui->labelNameRight->setText("Confidence");
        ui->widgetDistanceAmplitude->show();        
        updateDistance = true;
        break;
    case MeasurementType_e::MEASUREMENT_TYPE_DISTANCE_AMPLITUDE:
        ui->labelNameLeft->setText("Distance");
        ui->labelNameRight->setText("Amplitude");
        ui->widgetDistanceAmplitude->show();        
        updateAmplitude = true;
        updateDistance = true;
        break;
    case MeasurementType_e::MEASUREMENT_TYPE_GRAYSCALE:
        ui->labelNameLeft->clear();
        ui->labelNameRight->setText("Grayscale");
        ui->widgetDistanceAmplitude->show();
        ui->widgetDCS->hide();
        updateGrayscale = true;
        break;
    case MeasurementType_e::MEASUREMENT_TYPE_DISTANCE_GRAYSCALE:
        ui->labelNameLeft->setText("Distance");
        ui->labelNameRight->setText("Grayscale");
        ui->widgetDistanceAmplitude->show();        
        updateDistance = true;
        updateGrayscale = true;
        break;
    case MeasurementType_e::MEASUREMENT_TYPE_DCS:
        {
            unsigned int dcsIndex = context.getSettings().getPixelInfoSelection().getDcsIndex();
            ui->labelNameLeft->clear();
            ui->labelNameRight->setText("DCS" + QString::number(dcsIndex));
            updateDcs = true;            
            ui->widgetDCS->show();
            break;
        }
    }

    this->resize(100,100); //to minimize dialig size
}

void WidgetInfo::onFpsTimerTimeout()
{
    ui->labelFrameRate->setText("Frame rate: " + QString::number(numMeasurements) + "Fps");
    numMeasurements = 0;
}

void WidgetInfo::onSelectionChanged(const int x, const int y, const int width __attribute__((unused)), const int height __attribute__((unused)))
{
    ui->labelHeader->setText(QString("Pixel data(%1/%2)").arg(x).arg(y));

    onMeasurementTypeChanged();
}


unsigned int WidgetInfo::getPixelValue(const char* pData, DataHeader &dataHeader, unsigned int index, int imageType){

    uint8_t valueMsb=0,  valueLsb=0;

    if(context.getSettings().getMeasurementType() != 1){

        valueMsb = static_cast<uint8_t>(pData[2*index+1+dataHeader.offset]);
        valueLsb = static_cast<uint8_t>(pData[2*index+0+dataHeader.offset]);

    }else{

        if(imageType == 0){

            valueMsb = static_cast<uint8_t>(pData[4*index+1+dataHeader.offset]);
            valueLsb = static_cast<uint8_t>(pData[4*index+0+dataHeader.offset]);

        }else if(imageType == 1){

            valueMsb = static_cast<uint8_t>(pData[4*index+3+dataHeader.offset]);
            valueLsb = static_cast<uint8_t>(pData[4*index+2+dataHeader.offset]);
        }
    }

    //Combine to a value
    unsigned int pixelValue = static_cast<unsigned int>((valueMsb << 8) + valueLsb);
    return pixelValue;
}

void WidgetInfo::getDCSPixelValue(const char *pData, DataHeader &dataHeader, unsigned int index, uint &dcs0, uint &dcs1, uint &dcs2, uint &dcs3){

    uint8_t valueMsb=0,  valueLsb=0;
    uint offset = dataHeader.width * dataHeader.height;
    valueMsb = static_cast<uint8_t>(pData[2*index+1+dataHeader.offset]);
    valueLsb = static_cast<uint8_t>(pData[2*index+0+dataHeader.offset]);
    dcs0 = static_cast<unsigned int>((valueMsb << 8) + valueLsb);

    index += offset;
    valueMsb = static_cast<uint8_t>(pData[2*index+1+dataHeader.offset]);
    valueLsb = static_cast<uint8_t>(pData[2*index+0+dataHeader.offset]);
    dcs1 = static_cast<unsigned int>((valueMsb << 8) + valueLsb);

    index += offset;
    valueMsb = static_cast<uint8_t>(pData[2*index+1+dataHeader.offset]);
    valueLsb = static_cast<uint8_t>(pData[2*index+0+dataHeader.offset]);
    dcs2 = static_cast<unsigned int>((valueMsb << 8) + valueLsb);

    index += offset;
    valueMsb = static_cast<uint8_t>(pData[2*index+1+dataHeader.offset]);
    valueLsb = static_cast<uint8_t>(pData[2*index+0+dataHeader.offset]);
    dcs3 = static_cast<unsigned int>((valueMsb << 8) + valueLsb);

}



