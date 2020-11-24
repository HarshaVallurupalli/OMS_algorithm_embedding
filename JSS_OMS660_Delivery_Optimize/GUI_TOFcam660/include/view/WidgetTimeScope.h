/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef WIDGET_TIME_SCOPE_H
#define WIDGET_TIME_SCOPE_H

#include <QWidget>
#include <QTimer>
#include "ApplicationContext.h"
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QCategoryAxis>

namespace Ui {
class WidgetTimeScope;
}

class WidgetTimeScope : public QWidget
{
    Q_OBJECT

  public:
    explicit WidgetTimeScope(ApplicationContext &context, QWidget *parent = nullptr);
    ~WidgetTimeScope();

  private slots:    
    void onShowTimeScopeChanged(const bool checked);
    void onDistanceReceived(const unsigned int distance, const unsigned int confidence);
    void onDistanceAmplitudeReceived(const unsigned int distance, const unsigned int amplitude);
    void onGrayscaleReceived(const unsigned int grayscale);
    void onDistanceGrayscaleReceived(const unsigned int distance, const unsigned int grayscale);
    void onDcsReceived(const unsigned int dcs0, const unsigned int dcs1, const unsigned int dcs2, const unsigned int dcs3);
    void onSelectionChanged(const int x, const int y, const int width, const int height);
    void onMeasurementTypeChanged();

    void on_spinBoxLeftMax_valueChanged(int arg1);
    void on_spinBoxLeftMin_valueChanged(int arg1);
    void on_spinBoxRightMin_valueChanged(int arg1);
    void on_spinBoxRightMax_valueChanged(int arg1);
    void on_checkBoxAutoScale_clicked();
    void on_checkBoxShowLeft_clicked();
    void on_checkBoxShowRight_clicked();
    void on_checkBoxShowDcs0_clicked();
    void on_checkBoxShowDcs1_clicked();
    void on_checkBoxShowDcs2_clicked();
    void on_checkBoxShowDcs3_clicked();    

private:
    void closeEvent (QCloseEvent *event);
    void addData(QtCharts::QLineSeries *series, const unsigned int data);
    void addDataIfValid(QtCharts::QLineSeries *series, const unsigned int data);
    void addDummy(QtCharts::QLineSeries *series, const unsigned int data);
    void handleAutoScale(QtCharts::QLineSeries *data, QtCharts::QValueAxis *axis, int graphMinDiff);
    void handleAutoScale(QtCharts::QLineSeries *data[], unsigned int numSeries, QtCharts::QValueAxis *axis, int graphMinDiff);
    void applyAutoScale(double max, double min, QtCharts::QValueAxis *axis, int graphMinDiff);
    void showSingleAxis(const QString name, const QString unit);
    void showDualAxis(const QString nameLeft, const QString unitLeft, const QString nameRight, const QString unitRight);
    void showDcsAxis(const QString name, const QString unit);
    void updateAxis();
    void showDcsCheckBoxes();
    void hideDcsCheckBoxes();
    void updateDcsSeries();
    void connectSignals();
    void disconnectSignals();

    ApplicationContext &context;
    Ui::WidgetTimeScope *ui;
    QtCharts::QLineSeries *seriesLeft;
    QtCharts::QLineSeries *seriesRight;
    QtCharts::QLineSeries *seriesDummy;    
    QtCharts::QLineSeries *seriesDcs[4];

    QtCharts::QValueAxis *axisLeft;
    QtCharts::QValueAxis *axisRight;    

    QtCharts::QChart *chart;
    QtCharts::QChartView *chartView;   

    int measurementIndex;
    QTimer m_timer;
};

#endif // WIDGET_TIME_SCOPE_H
