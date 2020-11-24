/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef SETTINGSFILTER_H
#define SETTINGSFILTER_H

#include <QObject>

class SettingsFilter : public QObject
{
    Q_OBJECT
public:
    explicit SettingsFilter(QObject *parent = nullptr);
    void updateFilter();

    void setMedianFilter(bool state);
    bool isMedianFilter();

    void setAverageFilter(bool state);
    bool isAverageFilter();

    void setTemporalFilter(bool state);
    bool isTemporalFilter();

    void setEdgeFilter(bool state);
    bool isEdgeFilter();

    void setInterferenceDetection(bool state);
    bool isInterferenceDetection();

    void setTemporalEdgeFilter(bool state);
    bool isTemporalEdgeFilter();

    void setFactor(double val);
    double getFactor();

    void setTemporalThreshold(int val);
    int getTemporalThreshold();

    void setEdgeThreshold(int val);
    int getEdgeThreshold();

    void setTemporalEdgeThresholdLow(int val);
    int getTemporalEdgeThresholdLow();

    void setTemporalEdgeThresholdHigh(int val);
    int getTemporalEdgeThresholdHigh();

    void setInterferenceDetectionLimit(int value);
    int getInterferenceDetectionLimit();

    void setInterferenceDetectionUseLastValue(bool state);
    bool isInterferenceDetectionUseLastValue();


signals:
    void filterChanged();    

public slots:

private:

    bool medianFilter;
    bool averageFilter;
    bool temporalFilter;    
    double factor;
    int temporalThreshold;
    bool edgeFilter;
    int edgeThreshold;
    bool temporalEdgeFilter;
    int temporalEdgeThresholdLow;
    int temporalEdgeThresholdHigh;
    bool interferenceDetection;
    int interferenceDetectionLimit;
    bool interferenceDetectionUseLastValue;


};

#endif // SETTINGSFILTER_H
