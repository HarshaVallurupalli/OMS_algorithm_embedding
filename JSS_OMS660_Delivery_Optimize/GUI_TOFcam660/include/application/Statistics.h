/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef STATISTICS_H_
#define STATISTICS_H_

#include <QVector>

/// \addtogroup Statistics
/// @{

//! Helper statistics class for calculation statistical data
/*!
 * This class calulates statistical data like minimum, maximum, average, standard deviation.
 */
class Statistics {
public:
    Statistics(int maxSamples);
    ~Statistics();
    void addSample(double value);
    void clear();
    double getStandardDeviation();
    double getAverage();
    double getMin();
    double getMax();
    double getSum();

private:
    QVector<double> data;
    int maxSamples;

};

/// @}

#endif // STATISTICS_H_
