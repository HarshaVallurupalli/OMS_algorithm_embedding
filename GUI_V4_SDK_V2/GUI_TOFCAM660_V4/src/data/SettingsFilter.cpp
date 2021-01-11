/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "SettingsFilter.h"

SettingsFilter::SettingsFilter(QObject *parent) : QObject(parent),
    medianFilter(false),
    averageFilter(false),
    temporalFilter(false),   
    factor(1.0),
    temporalThreshold(0),
    edgeFilter(false),
    edgeThreshold(0),
    temporalEdgeFilter(false),
    temporalEdgeThresholdLow(0),
    temporalEdgeThresholdHigh(0),
    interferenceDetection(false),
    interferenceDetectionLimit(0),
    interferenceDetectionUseLastValue(0)
{

}

void SettingsFilter::setMedianFilter(bool state){
    medianFilter = state;
    emit filterChanged();
}

bool SettingsFilter::isMedianFilter(){
    return medianFilter;
}

void SettingsFilter::setAverageFilter(bool state){
    averageFilter = state;
    emit filterChanged();
}

bool SettingsFilter::isAverageFilter(){
    return averageFilter;
}

void SettingsFilter::setTemporalFilter(bool state){
    temporalFilter = state;
    emit filterChanged();
}

bool SettingsFilter::isTemporalFilter(){
    return temporalFilter;
}

void SettingsFilter::setEdgeFilter(bool state){
    edgeFilter = state;
    emit filterChanged();
}
bool SettingsFilter::isEdgeFilter(){
    return edgeFilter;
}

void SettingsFilter::setFactor(double val){
    factor = val;
    emit filterChanged();
}

double SettingsFilter::getFactor(){
    return factor;
}

void SettingsFilter::setTemporalThreshold(int val){
    temporalThreshold = val;
    emit filterChanged();
}

int SettingsFilter::getTemporalThreshold(){
    return temporalThreshold;
}

void SettingsFilter::setEdgeThreshold(int val){
    edgeThreshold = val;
    emit filterChanged();
}

int SettingsFilter::getEdgeThreshold(){
    return edgeThreshold;
}


void SettingsFilter::setTemporalEdgeFilter(bool state){
    temporalEdgeFilter = state;
    emit filterChanged();
}

bool SettingsFilter::isTemporalEdgeFilter(){
    return temporalEdgeFilter;
}

void SettingsFilter::setTemporalEdgeThresholdLow(int val){
    temporalEdgeThresholdLow = val;
    emit filterChanged();
}

int SettingsFilter::getTemporalEdgeThresholdLow(){
    return temporalEdgeThresholdLow;
}


void SettingsFilter::setTemporalEdgeThresholdHigh(int val){
    temporalEdgeThresholdHigh = val;
    emit filterChanged();
}

int SettingsFilter::getTemporalEdgeThresholdHigh(){
    return temporalEdgeThresholdHigh;
}

void SettingsFilter::setInterferenceDetection(bool state){
    interferenceDetection = state;
    emit filterChanged();
}

bool SettingsFilter::isInterferenceDetection(){
    return interferenceDetection;
}

void SettingsFilter::setInterferenceDetectionLimit(int value){
    interferenceDetectionLimit = value;
    emit filterChanged();
}

int SettingsFilter::getInterferenceDetectionLimit(){
    return interferenceDetectionLimit;
}

void SettingsFilter::setInterferenceDetectionUseLastValue(bool state){
    interferenceDetectionUseLastValue = state;
    emit filterChanged();
}

bool SettingsFilter::isInterferenceDetectionUseLastValue(){
    return interferenceDetectionUseLastValue;
}


void SettingsFilter::updateFilter(){
    emit filterChanged();
}
