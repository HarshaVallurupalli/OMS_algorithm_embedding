/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "WidgetPixelScope.h"
#include "ui_widget_pixelscope.h"
#include "MeasurementType.h"

QT_CHARTS_USE_NAMESPACE

WidgetPixelScope::WidgetPixelScope(ApplicationContext &context, QWidget *parent) :
    QWidget(parent),
    context(context),
    ui(new Ui::WidgetPixelScope)
{
    ui->setupUi(this);
    setWindowFlags ( Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowStaysOnTopHint | Qt::WindowCloseButtonHint);

    //Signals from the settings
    connect(&context.getSettings(), &Settings::showPixelScopeChanged, this, &WidgetPixelScope::onShowPixelScopeChanged);
    connect(&context.getSettings().getPixelScopeSelection(), qOverload<int, int, int, int>(&Selection::selectionChanged), this, &WidgetPixelScope::onSelectionChanged);

    //Settings update
    connect(&context.getSettings(), &Settings::measurementTypeChanged, this, &WidgetPixelScope::onMeasurementTypeChanged);

    //Hide all elements not needed at the moment
    ui->checkBoxShowDcs0->hide();
    ui->checkBoxShowDcs1->hide();
    ui->checkBoxShowDcs2->hide();
    ui->checkBoxShowDcs3->hide();
    ui->checkBoxShowLeft->hide();
    ui->checkBoxShowRight->hide();    
    ui->spinBoxRightMax->hide();
    ui->spinBoxRightMin->hide();
    ui->labelRightMax->hide();
    ui->labelRightMin->hide();    
    ui->checkBoxAutoScale->setChecked(true);
    ui->spinBoxLeftMin->setEnabled(false);
    ui->spinBoxLeftMax->setEnabled(false);
    ui->spinBoxRightMin->setEnabled(false);
    ui->spinBoxRightMax->setEnabled(false);

    chart = new QChart();
    chartView = new QChartView(chart);

    seriesPixelScope = new QLineSeries();
    chart->addSeries(seriesPixelScope);

    axisLeft = new QValueAxis;

    chart->createDefaultAxes();

    chart->addAxis(axisLeft, Qt::AlignLeft);
    chart->setAxisY(axisLeft, seriesPixelScope);

    axisLeft->setRange(ui->spinBoxLeftMin->value(), ui->spinBoxLeftMax->value());

    chartView->setRenderHint(QPainter::Antialiasing);
    ui->gridLayout->addWidget(chartView);

    onMeasurementTypeChanged();

    onSelectionChanged(context.getSettings().getTimeScopeSelection().getX(), context.getSettings().getTimeScopeSelection().getY(), context.getSettings().getTimeScopeSelection().getWidth(), context.getSettings().getTimeScopeSelection().getHeight());

    if(context.getSettings().getPixelScopeRect().width() !=0 && context.getSettings().getPixelScopeRect().height() !=0 ){
        this->setGeometry(context.getSettings().getPixelScopeRect());
    }

}

WidgetPixelScope::~WidgetPixelScope()
{
    qDebug() << "-----WidgetPixelScope destroying";    
    delete seriesPixelScope;
    delete axisLeft;
    delete chart;
    delete chartView;
    delete ui;
    qDebug() << "-----WidgetPixelScope destroyed";
}

void WidgetPixelScope::closeEvent (QCloseEvent *event  __attribute__((unused)))
{
    context.getSettings().setShowPixelScope(false);
    context.getSettings().setPixelScopeRect(this->geometry());
}

void WidgetPixelScope::onShowPixelScopeChanged(const bool checked)
{
    if(checked) show();
    else        hide();
}

void WidgetPixelScope::onSelectionChanged(const int x, const int y, const int width, const int height __attribute__((unused)))
{
    ui->labelCoordinates->setText(QString("Selection: x = %1  y = %2  width = %3").arg(x).arg(y).arg(width));
}

void WidgetPixelScope::onMeasurementTypeChanged()
{                
    switch(context.getSettings().getMeasurementType()){

    case MeasurementType_e::MEASUREMENT_TYPE_DISTANCE:
        this->setWindowTitle("PixelScope: Distance");
        seriesPixelScope->setName("Distance");
        ui->lMeasurementType->setText("Distance [mm]:  ");
        break;
    case MeasurementType_e::MEASUREMENT_TYPE_DISTANCE_AMPLITUDE:
        this->setWindowTitle("PixelScope: Amplitude");
        seriesPixelScope->setName("Amplitude");
        ui->lMeasurementType->setText("Amplitude [LSB]:");
        break;
    case MeasurementType_e::MEASUREMENT_TYPE_GRAYSCALE:
        this->setWindowTitle("PixelScope: Grayscale");
        seriesPixelScope->setName("Grayscale");
        ui->lMeasurementType->setText("Amplitude [LSB]:");
        break;
    case MeasurementType_e::MEASUREMENT_TYPE_DISTANCE_GRAYSCALE:
        break;
    case MeasurementType_e::MEASUREMENT_TYPE_DCS:
        break;        
    }

}


void WidgetPixelScope::onDataReceived(const char *pData, DataHeader &dataHeader, bool amplitude)
{
    QVector<QPointF> currentPoints = seriesPixelScope->pointsVector();

    currentPoints.clear();

    int ySelection = context.getSettings().getPixelScopeSelection().getY();

    unsigned int index = 0;
    uint8_t distanceMsb, distanceLsb;

    for(int y = 0; y < dataHeader.height; y++)
    {
        for(int x = 0; x < dataHeader.width; x++)
        {
            if(y == ySelection)
            {
                if(amplitude){
                    distanceMsb = static_cast<uint8_t>(pData[4*index+3+dataHeader.offset]);
                    distanceLsb = static_cast<uint8_t>(pData[4*index+2+dataHeader.offset]);
                }else{
                    distanceMsb = static_cast<uint8_t>(pData[2*index+1+dataHeader.offset]);
                    distanceLsb = static_cast<uint8_t>(pData[2*index+0+dataHeader.offset]);
                }

                //Combint to a value
                int pixelDistance = (distanceMsb << 8) + distanceLsb;

                if(pixelDistance< 64000)
                    currentPoints.append(QPointF(x, pixelDistance));
            }

            index++;
        }
    }

    seriesPixelScope->replace(currentPoints);
    //chart->axisX()->setRange(context.getSettings().getPixelScopeSelection().getX(), context.getSettings().getPixelScopeSelection().getX2()); //deprecated
    chart->axes(Qt::Horizontal).back()->setRange(context.getSettings().getPixelScopeSelection().getX(), context.getSettings().getPixelScopeSelection().getX2());

    handleAutoScale(seriesPixelScope, axisLeft);

}

void WidgetPixelScope::on_spinBoxLeftMin_valueChanged(int arg1  __attribute__((unused)))
{
    axisLeft->setRange(ui->spinBoxLeftMin->value(), ui->spinBoxLeftMax->value());
}

void WidgetPixelScope::on_spinBoxLeftMax_valueChanged(int arg1 __attribute__((unused)))
{
    axisLeft->setRange(ui->spinBoxLeftMin->value(), ui->spinBoxLeftMax->value());
}

void WidgetPixelScope::on_checkBoxAutoScale_clicked()
{
    if (ui->checkBoxAutoScale->isChecked() == false)
    {
        axisLeft->setRange(ui->spinBoxLeftMin->value(), ui->spinBoxLeftMax->value());
    }

    ui->spinBoxLeftMin->setEnabled(!ui->checkBoxAutoScale->isChecked());
    ui->spinBoxLeftMax->setEnabled(!ui->checkBoxAutoScale->isChecked());
}

void WidgetPixelScope::handleAutoScale(QLineSeries *data[], unsigned int numSeries, QValueAxis *axis)
{
    double min = 1000000;
    double max = 0;
    bool atLeastOneValuePresent = false;

    if (ui->checkBoxAutoScale->isChecked() == false)
        return; // Don't do anything, no auto scaling


    for (unsigned int i = 0; i < numSeries; i++)
    {
        QVector<QPointF> currentPoints = data[i]->pointsVector();
        foreach(QPointF point, currentPoints)
        {
            atLeastOneValuePresent = true;

            if (point.y() > max)
                max = point.y();
            else if (point.y() < min)
                min = point.y();
        }
    }

    //Auto scaling only if there is at least one value
    if(atLeastOneValuePresent){
        axis->setRange(min, max);
    }
}

void WidgetPixelScope::handleAutoScale(QLineSeries *data, QValueAxis *axis)
{
    QtCharts::QLineSeries *dataArray[1];
    dataArray[0] = data;
    handleAutoScale(dataArray, 1, axis);
}




