/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "WidgetTimeScope.h"
#include "ui_widget_timescope.h"
#include "MeasurementType.h"

QT_CHARTS_USE_NAMESPACE

///minimal distance difference between max value and min value for the graph
const int MIN_DISTANCE_DIFF_MAX_MIN = 20;
const int MIN_AMPLITUDE_DIFF_MAX_MIN = 20;
const int MIN_GRAYSCALE_DIFF_MAX_MIN = 20;
const int MIN_DCS_DIFF_MAX_MIN = 20;

///Default settings for the spinBoxes for the maximum value
const int MAX_DISTANCE_DEFAULT = 3000;
const int MAX_AMPLIUDE_DEFAULT = 2800;
const int MAX_CONFIDENCE_DEFAULT = 3;
const int MAX_GRAYSCALE_DEFAULT = 255;
const int MAX_DCS_DEFAULT = 4095;

const int MAX_DISTANCE_MAX = 15000;
const int MAX_AMPLITUDE_MAX = 2800;
const int MAX_CONFIDENCE_MAX = 3;
const int MAX_GRAYSCALE_MAX = 3000;
const int MAX_DCS_MAX = 4095;

const unsigned int VALID_PIXEL_CODE_LIMIT = 16000;

WidgetTimeScope::WidgetTimeScope(ApplicationContext &context, QWidget *parent) :
QWidget(parent),
context(context),
ui(new Ui::WidgetTimeScope)
{
    ui->setupUi(this);

    setWindowFlags ( Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowStaysOnTopHint | Qt::WindowCloseButtonHint);

    //Signals from the settings
    connect(&context.getSettings(), &Settings::showTimeScopeChanged, this, &WidgetTimeScope::onShowTimeScopeChanged);
    connect(&context.getSettings().getTimeScopeSelection(), qOverload<int, int, int, int>(&Selection::selectionChanged), this, &WidgetTimeScope::onSelectionChanged);

    //Settings update
    connect(&context.getSettings(), &Settings::measurementTypeChanged, this, &WidgetTimeScope::onMeasurementTypeChanged);

    measurementIndex = 0;

    chart = new QChart();
    chartView = new QChartView(chart);

    seriesLeft = new QLineSeries();
    seriesRight = new QLineSeries();
    seriesDummy = new QLineSeries();

    for(unsigned int i = 0; i < 4; i++){
        seriesDcs[i] = new QLineSeries();
        seriesDcs[i]->setName("DCS" + QString::number(i));
    }

    chart->addSeries(seriesLeft);
    chart->addSeries(seriesRight);
    chart->addSeries(seriesDummy);

    for (unsigned int i = 0; i < 4; i++)
    {
        chart->addSeries(seriesDcs[i]);
    }

    axisLeft = new QValueAxis;
    axisRight = new QValueAxis;

    chart->createDefaultAxes();

    chart->addAxis(axisLeft, Qt::AlignLeft);
    chart->addAxis(axisRight, Qt::AlignRight);

    chart->setAxisY(axisLeft, seriesLeft);
    chart->setAxisY(axisRight, seriesRight);

    for (unsigned int i = 0; i < 4; i++)
    {
        chart->setAxisY(axisLeft, seriesDcs[i]);
    }

    axisLeft->setRange(ui->spinBoxLeftMin->value(), ui->spinBoxLeftMax->value());
    axisRight->setRange(ui->spinBoxRightMin->value(), ui->spinBoxRightMax->value());

    chartView->setRenderHint(QPainter::Antialiasing);
    ui->gridLayout->addWidget(chartView);

    ui->spinBoxLeftMax->setMinimum(ui->spinBoxLeftMin->value() + MIN_DISTANCE_DIFF_MAX_MIN);

    seriesDummy->hide();
    ui->checkBoxAutoScale->setChecked(true);
    ui->spinBoxLeftMin->setEnabled(false);
    ui->spinBoxLeftMax->setEnabled(false);
    ui->spinBoxRightMin->setEnabled(false);
    ui->spinBoxRightMax->setEnabled(false);

    onMeasurementTypeChanged();

    onSelectionChanged(context.getSettings().getTimeScopeSelection().getX(), context.getSettings().getTimeScopeSelection().getY(), context.getSettings().getTimeScopeSelection().getWidth(), context.getSettings().getTimeScopeSelection().getHeight());

    if(context.getSettings().getTimeScopeRect().width() !=0 && context.getSettings().getTimeScopeRect().height() !=0){
        this->setGeometry(context.getSettings().getTimeScopeRect());
    }

}

WidgetTimeScope::~WidgetTimeScope()
{
    qDebug() << "-----WidgetTimeScope destroying";
    delete axisLeft;
    delete axisRight;
    delete seriesLeft;
    delete seriesRight;
    delete seriesDummy;
    delete chart;
    delete chartView;
    delete ui;
    qDebug() << "-----WidgetTimeScope destroyed";
}

void WidgetTimeScope::closeEvent (QCloseEvent *event  __attribute__((unused)))
{
    context.getSettings().setShowTimeScope(false);
    context.getSettings().setTimeScopeRect(this->geometry());
}

void WidgetTimeScope::connectSignals()
{
    //Signals from the multi pixel statistics
    connect(&context.getMultiPixelStatistics(), &MultiPixelStatistics::newDistanceValue, this, &WidgetTimeScope::onDistanceReceived);
    connect(&context.getMultiPixelStatistics(), &MultiPixelStatistics::newDistanceAmplitudeValue, this, &WidgetTimeScope::onDistanceAmplitudeReceived);
    connect(&context.getMultiPixelStatistics(), &MultiPixelStatistics::newGrayscaleValue, this, &WidgetTimeScope::onGrayscaleReceived);
    connect(&context.getMultiPixelStatistics(), &MultiPixelStatistics::newDistanceGrayscaleValue, this, &WidgetTimeScope::onDistanceGrayscaleReceived);
    connect(&context.getMultiPixelStatistics(), &MultiPixelStatistics::newDcsValue, this, &WidgetTimeScope::onDcsReceived);
}

void WidgetTimeScope::disconnectSignals()
{
    //Signals from the multi pixel statistics
    disconnect(&context.getMultiPixelStatistics(), &MultiPixelStatistics::newDistanceValue, this, &WidgetTimeScope::onDistanceReceived);
    disconnect(&context.getMultiPixelStatistics(), &MultiPixelStatistics::newDistanceAmplitudeValue, this, &WidgetTimeScope::onDistanceAmplitudeReceived);
    disconnect(&context.getMultiPixelStatistics(), &MultiPixelStatistics::newGrayscaleValue, this, &WidgetTimeScope::onGrayscaleReceived);
    disconnect(&context.getMultiPixelStatistics(), &MultiPixelStatistics::newDistanceGrayscaleValue, this, &WidgetTimeScope::onDistanceGrayscaleReceived);
    disconnect(&context.getMultiPixelStatistics(), &MultiPixelStatistics::newDcsValue, this, &WidgetTimeScope::onDcsReceived);
}

void WidgetTimeScope::onShowTimeScopeChanged(const bool checked)
{
    if (checked)
    {
        show();
        connectSignals();
    }
    else
    {
        hide();
        disconnectSignals();
    }
}

void WidgetTimeScope::onDcsReceived(const unsigned int dcs0, const unsigned int dcs1, const unsigned int dcs2, const unsigned int dcs3)
{
    addDataIfValid(seriesDcs[0], dcs0);
    addDataIfValid(seriesDcs[1], dcs2);
    addDataIfValid(seriesDcs[2], dcs1);
    addDataIfValid(seriesDcs[3], dcs3);
    addDummy(seriesDummy, 0);

    QtCharts::QLineSeries *data[4];
    for (unsigned int i = 0; i < 4; i++)
    {
        data[i] = seriesDcs[i];
    }

    handleAutoScale(data, 4, axisLeft, MIN_DCS_DIFF_MAX_MIN);

    ui->labelActValue->setText(QString("dcs0 = %1, dcs1 = %2, dcs2 = %3, dcs3 = %4").arg(dcs0).arg(dcs1).arg(dcs2).arg(dcs3));

    measurementIndex++;
}

void WidgetTimeScope::onGrayscaleReceived(const unsigned int grayscale)
{
    addDataIfValid(seriesLeft, grayscale);
    addDummy(seriesDummy, 0);
    handleAutoScale(seriesLeft, axisLeft, MIN_GRAYSCALE_DIFF_MAX_MIN);

    ui->labelActValue->setText(QString("grayscale = %1").arg(grayscale));

    measurementIndex++;
}

void WidgetTimeScope::onDistanceReceived(const unsigned int distance, const unsigned int confidence)
{
    addDataIfValid(seriesLeft, distance);
    addDataIfValid(seriesRight, confidence);
    addDummy(seriesDummy, 0);
    handleAutoScale(seriesLeft, axisLeft, MIN_DISTANCE_DIFF_MAX_MIN);

    ui->labelActValue->setText(QString("distance = %1 confidence = %2").arg(distance).arg(confidence));

    measurementIndex++;
}

void WidgetTimeScope::onDistanceAmplitudeReceived(const unsigned int distance, const unsigned int amplitude)
{
    addDataIfValid(seriesLeft, distance);
    addDataIfValid(seriesRight, amplitude);
    addDummy(seriesDummy, 0);
    handleAutoScale(seriesLeft, axisLeft, MIN_DISTANCE_DIFF_MAX_MIN);
    handleAutoScale(seriesRight, axisRight, MIN_AMPLITUDE_DIFF_MAX_MIN);

    ui->labelActValue->setText(QString("distance = %1  amplitude = %2").arg(distance).arg(amplitude));

    measurementIndex++;
}

void WidgetTimeScope::onDistanceGrayscaleReceived(const unsigned int distance, const unsigned int grayscale)
{
    addDataIfValid(seriesLeft, distance);
    addDataIfValid(seriesRight, grayscale);
    addDummy(seriesDummy, 0);
    handleAutoScale(seriesLeft, axisLeft, MIN_DISTANCE_DIFF_MAX_MIN);
    handleAutoScale(seriesRight, axisRight, MIN_GRAYSCALE_DIFF_MAX_MIN);

    ui->labelActValue->setText(QString("distance = %1  grayscale = %2").arg(distance).arg(grayscale));

    measurementIndex++;
}

void WidgetTimeScope::handleAutoScale(QtCharts::QLineSeries *data, QValueAxis *axis, int graphMinDiff)
{
    QtCharts::QLineSeries *dataArray[1];
    dataArray[0] = data;
    handleAutoScale(dataArray, 1, axis, graphMinDiff);
}

void WidgetTimeScope::handleAutoScale(QtCharts::QLineSeries *data[], unsigned int numSeries, QValueAxis *axis, int graphMinDiff)
{
    double min = 1000000;
    double max = 0;
    bool atLeastOneValuePresent = false;

    if (ui->checkBoxAutoScale->isChecked() == false)
    {
        return;
    } // Don't do anything, no auto scaling -------------------------->

    for (unsigned int i = 0; i < numSeries; i++)
    {
        QVector<QPointF> currentPoints = data[i]->pointsVector();
        foreach(QPointF point, currentPoints)
        {
            atLeastOneValuePresent = true;
            if (point.y() > max)
                max = point.y();

            if (point.y() < min)
                min = point.y();
        }
    }

    //Auto scaling only if there is at least one value
    if (atLeastOneValuePresent)
    {
        applyAutoScale(max, min, axis, graphMinDiff);
    }
}

void WidgetTimeScope::applyAutoScale(double max, double min, QValueAxis *axis, int graphMinDiff)
{    
    //Limit, so the maximum is not too near to the minimum
    if ((max - min) < graphMinDiff)
    {
        double diff = graphMinDiff - (max - min);

        //Subtract the half of the remaining from the min
        min -= diff/2;
        if (min < 0)
        {
            min = 0;
        }

        //Set the max depending on the min
        max = min + graphMinDiff;
    }

    axis->setRange(min, max);
}

void WidgetTimeScope::addDataIfValid(QtCharts::QLineSeries *series, const unsigned int data)
{
    if (data < VALID_PIXEL_CODE_LIMIT)
    {
        addData(series, data);
    }
}

void WidgetTimeScope::addData(QtCharts::QLineSeries *series, const unsigned int data)
{
    QVector<QPointF> currentPoints = series->pointsVector();

    //Limit to the number of elements
    if (currentPoints.length() > ui->spinBoxNumberOfValues->value())
    {
        int toMany = currentPoints.length() - ui->spinBoxNumberOfValues->value();
        currentPoints.remove(0, toMany);
    }

    currentPoints.append(QPointF(measurementIndex, data));

    series->replace(currentPoints);
}

void WidgetTimeScope::addDummy(QtCharts::QLineSeries *series, const unsigned int data)
{
    QVector<QPointF> currentPoints = series->pointsVector();

    //Limit to the number of elements
    if (currentPoints.length() > ui->spinBoxNumberOfValues->value())
    {
        int toMany = currentPoints.length() - ui->spinBoxNumberOfValues->value();
        currentPoints.remove(0, toMany);
    }

    currentPoints.append(QPointF(measurementIndex, data));

    //Update the x axis    
    chart->axes(Qt::Horizontal).back()->setRange(currentPoints.at(0).x(), currentPoints.last().x());

    series->replace(currentPoints);
}

void WidgetTimeScope::on_spinBoxLeftMax_valueChanged(int arg1 __attribute__((unused)))
{
    axisLeft->setRange(ui->spinBoxLeftMin->value(), ui->spinBoxLeftMax->value());
}

void WidgetTimeScope::on_spinBoxLeftMin_valueChanged(int arg1 __attribute__((unused)))
{
    ui->spinBoxLeftMax->setMinimum(ui->spinBoxLeftMin->value() + MIN_DISTANCE_DIFF_MAX_MIN);
    axisLeft->setRange(ui->spinBoxLeftMin->value(), ui->spinBoxLeftMax->value());
}

void WidgetTimeScope::on_spinBoxRightMin_valueChanged(int arg1 __attribute__((unused)))
{
    axisRight->setRange(ui->spinBoxRightMin->value(), ui->spinBoxRightMax->value());
}

void WidgetTimeScope::on_spinBoxRightMax_valueChanged(int arg1 __attribute__((unused)))
{
    axisRight->setRange(ui->spinBoxRightMin->value(), ui->spinBoxRightMax->value());
}

void WidgetTimeScope::on_checkBoxAutoScale_clicked()
{
    if (ui->checkBoxAutoScale->isChecked() == false)
    {
        axisLeft->setRange(ui->spinBoxLeftMin->value(), ui->spinBoxLeftMax->value());
        axisRight->setRange(ui->spinBoxRightMin->value(), ui->spinBoxRightMax->value());
    }

    ui->spinBoxLeftMin->setEnabled(!ui->checkBoxAutoScale->isChecked());
    ui->spinBoxLeftMax->setEnabled(!ui->checkBoxAutoScale->isChecked());

    ui->spinBoxRightMin->setEnabled(!ui->checkBoxAutoScale->isChecked());
    ui->spinBoxRightMax->setEnabled(!ui->checkBoxAutoScale->isChecked());
}

void WidgetTimeScope::on_checkBoxShowLeft_clicked()
{
    updateAxis();
}

void WidgetTimeScope::on_checkBoxShowRight_clicked()
{
    updateAxis();
}

void WidgetTimeScope::onSelectionChanged(const int x, const int y, const int width, const int height)
{
    ui->labelCoordinates->setText(QString("x = %1  y = %2  width = %3  height = %4").arg(x).arg(y).arg(width).arg(height));
}

void WidgetTimeScope::showDcsCheckBoxes()
{
    ui->checkBoxShowDcs0->show();
    ui->checkBoxShowDcs1->show();
    ui->checkBoxShowDcs2->show();
    ui->checkBoxShowDcs3->show();
}

void WidgetTimeScope::hideDcsCheckBoxes()
{
    ui->checkBoxShowDcs0->hide();
    ui->checkBoxShowDcs1->hide();
    ui->checkBoxShowDcs2->hide();
    ui->checkBoxShowDcs3->hide();
}

void WidgetTimeScope::updateDcsSeries()
{
    QCheckBox *checkBoxes[4];

    checkBoxes[0] = ui->checkBoxShowDcs0;
    checkBoxes[1] = ui->checkBoxShowDcs1;
    checkBoxes[2] = ui->checkBoxShowDcs2;
    checkBoxes[3] = ui->checkBoxShowDcs3;

    for (unsigned int i = 0; i < 4; i++)
    {
        if (checkBoxes[i]->isChecked())
        {
            seriesDcs[i]->show();
        }
        else
        {
            seriesDcs[i]->hide();
        }
    }
}

void WidgetTimeScope::updateAxis()
{
    if (ui->checkBoxShowLeft->isChecked())
    {
        seriesLeft->show();
        axisLeft->show();
    }
    else
    {
        axisLeft->hide();
        seriesLeft->hide();
    }

    if (ui->checkBoxShowRight->isChecked())
    {
        axisRight->show();
        seriesRight->show();
    }
    else
    {
        axisRight->hide();
        seriesRight->hide();
    }
}

void WidgetTimeScope::showSingleAxis(const QString name, const QString unit)
{
    //ui->labelRight->hide();
    ui->checkBoxShowRight->hide();
    axisRight->hide();
    ui->spinBoxRightMin->hide();
    ui->spinBoxRightMax->hide();
    ui->labelRightMax->hide();
    ui->labelRightMin->hide();

    //ui->labelLeft->setText(name);
    ui->checkBoxShowLeft->setChecked(true);
    ui->checkBoxShowLeft->hide();
    seriesLeft->setName(name);
    axisLeft->setTitleText(name);
    axisLeft->show();
    //ui->spinBoxLeftMax->setSuffix(unit);
    //ui->spinBoxLeftMin->setSuffix(unit);
    ui->spinBoxLeftMin->show();
    ui->spinBoxLeftMax->show();
    ui->labelLeftMax->show();
    ui->labelLeftMin->show();
    ui->spinBoxLeftMin->setToolTip("Minimum value for " + name);
    ui->spinBoxLeftMax->setToolTip("Maximum value for " + name);

    for (unsigned int i = 0; i < 4; i++)
    {
        seriesDcs[i]->hide();
    }

    hideDcsCheckBoxes();
}

void WidgetTimeScope::showDcsAxis(const QString name, const QString unit)
{
    //ui->labelRight->hide();
    ui->checkBoxShowRight->hide();
    axisRight->hide();
    ui->spinBoxRightMin->hide();
    ui->spinBoxRightMax->hide();
    ui->labelRightMax->hide();
    ui->labelRightMin->hide();

    //ui->labelLeft->setText(name);
    ui->checkBoxShowLeft->setChecked(true);
    ui->checkBoxShowLeft->hide();

    for (unsigned int i = 0; i < 4; i++)
    {
        seriesDcs[i]->show();
    }

    axisLeft->setTitleText(name);
    axisLeft->show();
    //ui->spinBoxLeftMax->setSuffix(unit);
    //ui->spinBoxLeftMin->setSuffix(unit);
    ui->spinBoxLeftMin->show();
    ui->spinBoxLeftMax->show();
    ui->labelLeftMax->show();
    ui->labelLeftMin->show();

    ui->spinBoxLeftMin->setToolTip("Minimum value for DCS");
    ui->spinBoxLeftMax->setToolTip("Maximum value for DCS");

    seriesLeft->hide();
    seriesRight->hide();

    showDcsCheckBoxes();
}

void WidgetTimeScope::showDualAxis(const QString nameLeft, const QString unitLeft, const QString nameRight, const QString unitRight)
{
    //ui->labelRight->setText(nameRight);
    //ui->labelRight->show();
    ui->checkBoxShowRight->show();
    seriesRight->setName(nameRight);
    axisRight->setTitleText(nameRight);
    axisRight->show();
    //ui->spinBoxRightMax->setSuffix(unitRight);
    //ui->spinBoxRightMin->setSuffix(unitRight);
    ui->spinBoxRightMin->show();
    ui->spinBoxRightMax->show();
    ui->labelRightMax->show();
    ui->labelRightMin->show();
    ui->checkBoxShowLeft->setToolTip("show " + nameLeft + " curve");
    ui->spinBoxLeftMin->setToolTip("Minimum value for " + nameLeft);
    ui->spinBoxLeftMax->setToolTip("Maximum value for " + nameLeft);

    //ui->labelLeft->setText(nameLeft);
    ui->checkBoxShowLeft->setChecked(true);
    ui->checkBoxShowLeft->show();
    seriesLeft->setName(nameLeft);
    axisLeft->setTitleText(nameLeft);
    axisLeft->show();
    //ui->spinBoxLeftMax->setSuffix(unitLeft);
    //ui->spinBoxLeftMin->setSuffix(unitLeft);
    ui->spinBoxLeftMin->show();
    ui->spinBoxLeftMax->show();
    ui->labelLeftMax->show();
    ui->labelLeftMin->show();
    ui->checkBoxShowRight->setToolTip("show " + nameRight + " curve");
    ui->spinBoxRightMin->setToolTip("Minimum value for " + nameRight);
    ui->spinBoxRightMax->setToolTip("Maximum value for " + nameRight);

    for (unsigned int i = 0; i < 4; i++)
    {
        seriesDcs[i]->hide();
    }

    hideDcsCheckBoxes();
}

void WidgetTimeScope::onMeasurementTypeChanged()
{

    ui->checkBoxShowDcs0->setVisible(false);
    ui->checkBoxShowDcs1->setVisible(false);
    ui->checkBoxShowDcs2->setVisible(false);
    ui->checkBoxShowDcs3->setVisible(false);

    switch(context.getSettings().getMeasurementType())
    {
    case MeasurementType_e::MEASUREMENT_TYPE_DISTANCE:
        ui->spinBoxLeftMax->setMaximum(MAX_DISTANCE_MAX);
        ui->spinBoxLeftMax->setValue(MAX_DISTANCE_DEFAULT);
        ui->spinBoxRightMax->setMaximum(MAX_CONFIDENCE_MAX);
        ui->spinBoxRightMax->setValue(MAX_CONFIDENCE_DEFAULT);
        ui->spinBoxLeftMin->setSingleStep(1);
        ui->spinBoxRightMax->setSingleStep(1);
        showDualAxis("Distance", "mm", "Confidence", "");
        updateAxis();

        ui->lMeasurementType->setText("Distance   [mm]");
        ui->lMeasurementType->setVisible(true);
        ui->labelRightMax->setVisible(false);
        ui->labelRightMin->setVisible(false);
        ui->checkBoxShowLeft->setVisible(false);
        ui->checkBoxShowRight->setVisible(false);
        ui->spinBoxRightMin->setVisible(false);
        ui->spinBoxRightMax->setVisible(false);
        break;

    case MeasurementType_e::MEASUREMENT_TYPE_DISTANCE_AMPLITUDE:

        ui->spinBoxLeftMax->setMaximum(MAX_DISTANCE_MAX);
        ui->spinBoxLeftMax->setValue(MAX_DISTANCE_DEFAULT);
        ui->spinBoxRightMax->setMaximum(MAX_AMPLITUDE_MAX);
        ui->spinBoxRightMax->setValue(MAX_AMPLIUDE_DEFAULT);
        showDualAxis("Distance", "mm", "Amplitude", "lsb");
        updateAxis();

        ui->lMeasurementType->setVisible(false);
        ui->labelRightMax->setVisible(true);
        ui->labelRightMin->setVisible(true);
        ui->checkBoxShowRight->setVisible(true);
        ui->spinBoxRightMin->setVisible(true);
        ui->spinBoxRightMax->setVisible(true);
        break;

    case MeasurementType_e::MEASUREMENT_TYPE_GRAYSCALE:
        ui->spinBoxLeftMax->setMaximum(MAX_GRAYSCALE_MAX);
        ui->spinBoxLeftMax->setValue(MAX_GRAYSCALE_DEFAULT);
        showSingleAxis("Grayscale", "lsb");        
        ui->lMeasurementType->setText("Grayscale [LSB]");
        ui->lMeasurementType->setVisible(true);
        ui->labelRightMax->setVisible(false);
        ui->labelRightMin->setVisible(false);
        ui->checkBoxShowLeft->setVisible(false);
        ui->checkBoxShowRight->setVisible(false);
        ui->spinBoxRightMin->setVisible(false);
        ui->spinBoxRightMax->setVisible(false);
        break;

    case MeasurementType_e::MEASUREMENT_TYPE_DISTANCE_GRAYSCALE:
        ui->spinBoxLeftMax->setMaximum(MAX_DISTANCE_MAX);
        ui->spinBoxLeftMax->setValue(MAX_DISTANCE_DEFAULT);
        ui->spinBoxRightMax->setMaximum(MAX_GRAYSCALE_MAX);
        ui->spinBoxRightMax->setValue(MAX_GRAYSCALE_DEFAULT);
        showDualAxis("Distance", "mm", "Grayscale", "lsb");
        updateAxis();
        break;

    case MeasurementType_e::MEASUREMENT_TYPE_DCS:
        ui->checkBoxShowDcs0->setVisible(true);
        ui->checkBoxShowDcs1->setVisible(true);
        ui->checkBoxShowDcs2->setVisible(true);
        ui->checkBoxShowDcs3->setVisible(true);
        ui->lMeasurementType->setVisible(true);
        ui->lMeasurementType->setText("Amplitude [LSB]");
        ui->spinBoxLeftMax->setMaximum(MAX_DCS_MAX);
        ui->spinBoxLeftMax->setValue(MAX_DCS_DEFAULT);
        showDcsAxis("DCS", "lsb");
        updateDcsSeries();
        break;
    }

}


void WidgetTimeScope::on_checkBoxShowDcs0_clicked()
{
    updateDcsSeries();
}

void WidgetTimeScope::on_checkBoxShowDcs1_clicked()
{
    updateDcsSeries();
}

void WidgetTimeScope::on_checkBoxShowDcs2_clicked()
{
    updateDcsSeries();
}

void WidgetTimeScope::on_checkBoxShowDcs3_clicked()
{
    updateDcsSeries();
}
