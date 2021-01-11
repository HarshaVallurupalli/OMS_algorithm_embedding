/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef WIDGETINFO_H
#define WIDGETINFO_H

#include <QWidget>
#include <QTimer>
#include <Statistics.h>
#include "ApplicationContext.h"
#include "DataHeader.h"

namespace Ui {
class WidgetInfo;
}

class WidgetInfo : public QWidget
{
    Q_OBJECT

  public:
    explicit WidgetInfo(ApplicationContext &context, QWidget *parent = nullptr);
    ~WidgetInfo();
    void onDataReceived(const char *pData, DataHeader &dataHeader);

  private slots:
    void onFpsTimerTimeout();
    void onShowInfoChanged(const bool checked);    
    void onMeasurementTypeChanged();
    void onSelectionChanged(const int x, const int y, const int width, const int height);

  protected:
    void closeEvent(QCloseEvent *event  __attribute__((unused)));

  private:    
    unsigned int getPixelValue(const char *pData, DataHeader &dataHeader, unsigned int index, int imageType);
    void setDistance(const unsigned int distance, const unsigned int confidence);
    void setAmplitude(const unsigned int amplitude);
    void setGrayscale(const unsigned int grayscale);
    void setDcs(const unsigned int dcs);
    void clearDataLeft();
    void clearDataRight();


    ApplicationContext &context;
    Ui::WidgetInfo *ui;
    QTimer *fpsTimer;
    unsigned int numMeasurements;
    Statistics statisticsDistance;
    Statistics statisticsAmplitude;
    Statistics statisticsGrayscale;
    bool updateAmplitude;
    bool updateDistance;
    bool updateGrayscale;
    bool updateDcs;
};

#endif // WIDGETINFO_H
