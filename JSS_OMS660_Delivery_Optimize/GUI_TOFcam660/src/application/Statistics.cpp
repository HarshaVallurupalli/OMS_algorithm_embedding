/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "Statistics.h"
#include <QDebug>
#include <cmath>

/// \addtogroup Statistics
/// @{


Statistics::Statistics(int maxSamples) {
    this->maxSamples = maxSamples;
    clear();
}

Statistics::~Statistics(){
}

void Statistics::addSample(double value){
    data.push_back(value);
    if (data.size() > maxSamples){
        data.pop_front();
    }
}

void Statistics::clear(){
    data.clear();
}

double Statistics::getStandardDeviation(){
    if (data.size() < 2){
        return 0.0;
    }
    double average = getAverage();
    double sumDeviation{};
    for (double val : data){
        sumDeviation += (val-average)*(val-average);
    }
    return sqrt(sumDeviation/(data.size()-1));
}

double Statistics::getAverage()
{
  if (data.size() == 0)
  {
    return 0.0;
  }
  else if (data.size() < 2)
  {
    return data.at(0);
  }
  else return std::accumulate(data.begin(), data.end(), 0.0) / data.size();
}

double Statistics::getMin(){
    if (data.size() < 2){
        return 0.0;
    }
    return *std::min_element(data.begin(),data.end());
}

double Statistics::getMax(){
    if (data.size() < 2){
        return 0.0;
    }
    return *std::max_element(data.begin(), data.end());
}

double Statistics::getSum()
{
  return std::accumulate(data.begin(), data.end(), 0.0);
}


/// @}
