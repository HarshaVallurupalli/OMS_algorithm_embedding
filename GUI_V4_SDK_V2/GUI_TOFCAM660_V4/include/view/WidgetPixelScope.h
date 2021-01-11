/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef WIDGET_PIXEL_SCOPE_H
#define WIDGET_PIXEL_SCOPE_H

#include <QWidget>
#include <QTimer>
#include "ApplicationContext.h"
#include "DataHeader.h"
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QCategoryAxis>

namespace Ui {
class WidgetPixelScope;
}

class WidgetPixelScope : public QWidget
{
    Q_OBJECT

  public:
    explicit WidgetPixelScope(ApplicationContext &context, QWidget *parent = nullptr);
    ~WidgetPixelScope();

  private slots:    
    void onShowPixelScopeChanged(const bool checked);
    void onSelectionChanged(const int x, const int y, const int width, const int height);
    void onMeasurementTypeChanged();
    void on_spinBoxLeftMin_valueChanged(int arg1);
    void on_spinBoxLeftMax_valueChanged(int arg1);
    void on_checkBoxAutoScale_clicked();

public slots:
    void onDataReceived(const char *pData, DataHeader &dataHeader, bool amplitude);

private:

    void handleAutoScale(QtCharts::QLineSeries *data[], unsigned int numSeries, QtCharts::QValueAxis *axis);
    void handleAutoScale(QtCharts::QLineSeries *data, QtCharts::QValueAxis *axis);
    void closeEvent (QCloseEvent *event);    

    ApplicationContext &context;
    Ui::WidgetPixelScope *ui;    
    QtCharts::QLineSeries *seriesPixelScope;
    QtCharts::QValueAxis *axisLeft;    
    QtCharts::QChart *chart;
    QtCharts::QChartView *chartView;    
    QTimer m_timer;
};

#endif // WIDGET_PIXEL_SCOPE_H
