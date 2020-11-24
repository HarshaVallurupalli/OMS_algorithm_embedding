/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef MULTIPIXELSTATISTICS_H
#define MULTIPIXELSTATISTICS_H

#include <QObject>
#include "Selection.h"
#include "DataHeader.h"

class MultiPixelStatistics: public QObject
{
  Q_OBJECT

  public:
    MultiPixelStatistics(Selection &selection);
    ~MultiPixelStatistics();

  signals:
    void newDistanceValue(const unsigned int distance, const unsigned int confidence);
    void newDistanceAmplitudeValue(const unsigned int distance, const unsigned int amplitude);
    void newGrayscaleValue(const unsigned int grayscale);
    void newDistanceGrayscaleValue(const unsigned int distance, const unsigned int grayscale);
    void newDcsValue(const unsigned int dcs0, const unsigned int dcs1, const unsigned int dcs2, const unsigned int dcs3);

  public slots:
    void onGrayscaleReceived(const char *pData, DataHeader &dataHeader);
    void onDistanceReceived(const char *pData, DataHeader &dataHeader);
    void onDistanceAmplitudeReceived(const char *pData, DataHeader &dataHeader);
    void onDistanceGrayscaleReceived(const char *pData, DataHeader &dataHeader);
    void onDcsReceived(const char *pData, DataHeader &dataHeader);

  private:
    Selection &selection;
};

#endif // MULTIPIXELSTATISTICS_H
