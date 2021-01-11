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

        if ((statisticsDistance.getAverage() == 0) && (statisticsDistance.getStandardDeviation() == 0) &&
                (statisticsDistance.getMin() == 0) && (statisticsDistance.getMax() == 0))
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

        if ((statisticsAmplitude.getAverage() == 0) && (statisticsAmplitude.getStandardDeviation() == 0) &&
                (statisticsAmplitude.getMin() == 0) &&  (statisticsAmplitude.getMax() == 0))
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

        if ((statisticsAmplitude.getAverage() == 0) &&
                (statisticsAmplitude.getStandardDeviation() == 0) &&
                (statisticsAmplitude.getMin() == 0) &&
                (statisticsAmplitude.getMax() == 0))
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

void WidgetInfo::setDcs(const unsigned int dcs)
{
    if (dcs >= LOW_AMPLITUDE)
    {
      ui->labelCurrentRight->setText("N/A");
      ui->labelVariationRight->setText("N/A");
      ui->labelAverageRight->setText("N/A");
      ui->labelMaximumRight->setText("N/A");
     ui->labelMinimumRight->setText("N/A");
    } else {
    statisticsAmplitude.addSample(static_cast<double>(dcs));

    //Print the first pixel at the moment
    ui->labelCurrentRight->setText(QString::number(dcs) + "lsb");

    if ((statisticsAmplitude.getAverage() == 0) && (statisticsAmplitude.getStandardDeviation() == 0) &&
            (statisticsAmplitude.getMin() == 0) && (statisticsAmplitude.getMax() == 0))
    {
        ui->labelVariationRight->setText("-");
        ui->labelAverageRight->setText("-");
        ui->labelMaximumRight->setText("-");
        ui->labelMinimumRight->setText("-");

    }else {

        ui->labelVariationRight->setText(QString::number(statisticsAmplitude.getStandardDeviation(), 'f', 1) + "lsb");
        ui->labelAverageRight->setText(QString::number(statisticsAmplitude.getAverage(), 'f', 1) + "lsb");
        ui->labelMaximumRight->setText(QString::number(statisticsAmplitude.getMax(), 'f', 1) + "lsb");
        ui->labelMinimumRight->setText(QString::number(statisticsAmplitude.getMin(), 'f', 1) + "lsb");
    }
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
        //unsigned int dcsIndex = context.getSettings().getPixelInfoSelection().getDcsIndex();
        //setDcs(getPixelValue(pData, dataHeader, pixelIndex, 2));
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

    switch(context.getSettings().getMeasurementType())
    {
    case MeasurementType_e::MEASUREMENT_TYPE_DISTANCE:
        ui->labelNameLeft->setText("Distance");
        ui->labelNameRight->setText("Confidence");
        updateDistance = true;
        break;
    case MeasurementType_e::MEASUREMENT_TYPE_DISTANCE_AMPLITUDE:
        ui->labelNameLeft->setText("Distance");
        ui->labelNameRight->setText("Amplitude");
        updateAmplitude = true;
        updateDistance = true;
        break;
    case MeasurementType_e::MEASUREMENT_TYPE_GRAYSCALE:
        ui->labelNameLeft->clear();
        ui->labelNameRight->setText("Grayscale");
        updateGrayscale = true;
        break;
    case MeasurementType_e::MEASUREMENT_TYPE_DISTANCE_GRAYSCALE:
        ui->labelNameLeft->setText("Distance");
        ui->labelNameRight->setText("Grayscale");
        updateDistance = true;
        updateGrayscale = true;
        break;
    case MeasurementType_e::MEASUREMENT_TYPE_DCS:
    {
        unsigned int dcsIndex = context.getSettings().getPixelInfoSelection().getDcsIndex();
        ui->labelNameLeft->clear();
        ui->labelNameRight->setText("DCS" + QString::number(dcsIndex));
        updateDcs = true;
        break;
    }
    }
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
