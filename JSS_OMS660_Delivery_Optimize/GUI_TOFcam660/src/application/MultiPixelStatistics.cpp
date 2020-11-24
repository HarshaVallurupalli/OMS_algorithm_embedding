/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "MultiPixelStatistics.h"
#include "Statistics.h"
#include <QDebug>


MultiPixelStatistics::MultiPixelStatistics(Selection &selection): selection(selection)
{

}

MultiPixelStatistics::~MultiPixelStatistics()
{

}

void MultiPixelStatistics::onGrayscaleReceived(const char *pData, DataHeader &dataHeader)
{
  Statistics statistics(selection.getNumPixel());

  unsigned int index = 0;
  for (int y = 0; y < dataHeader.height; y++)
  {
    for (int x = 0; x < dataHeader.width; x++)
    {
      if (selection.contains(x, y))
      {
        uint8_t valueMsb = static_cast<uint8_t>(pData[2*index+1+dataHeader.offset]);
        uint8_t valueLsb = static_cast<uint8_t>(pData[2*index+0+dataHeader.offset]);
        unsigned int pixelValue = static_cast<unsigned int>((valueMsb << 8) + valueLsb);
        statistics.addSample(static_cast<double>(pixelValue));
      }

      index++;

      if (index >= dataHeader.width * dataHeader.height)
      {
        break;
      }

    }
  }

  unsigned int grayscale = static_cast<unsigned int>(statistics.getAverage());
  emit newGrayscaleValue(grayscale);
}

void MultiPixelStatistics::onDistanceReceived(const char *pData, DataHeader &dataHeader)
{
    Statistics statistics(selection.getNumPixel());

    unsigned int index = 0;
    for (int y = 0; y<dataHeader.height; y++){
        for (int x = 0; x < dataHeader.width; x++){
            if(selection.contains(x, y)){             
                uint8_t valueMsb = static_cast<uint8_t>(pData[2*index+1+dataHeader.offset]);
                uint8_t valueLsb = static_cast<uint8_t>(pData[2*index+0+dataHeader.offset]);
                unsigned int pixelValue = static_cast<unsigned int>((valueMsb << 8) + valueLsb);
                statistics.addSample(static_cast<double>(pixelValue));
            }

            index++;

            if (index >= dataHeader.width * dataHeader.height){
                break;
            }
        }

    }

    unsigned int distance = static_cast<unsigned int>(statistics.getAverage());

    //Take the first pixel for confidence, no statistics
    emit newDistanceValue(distance, 100000);

}

void MultiPixelStatistics::onDistanceAmplitudeReceived(const char *pData, DataHeader &dataHeader)
{
  Statistics statisticsDistance(selection.getNumPixel());
  Statistics statisticsAmplitude(selection.getNumPixel());

  unsigned int index = 0;
 for (int y =0; y < dataHeader.height; y++)
  {
    for (int x = 0; x < dataHeader.width; x++)
    {
      if (selection.contains(x, y))
      {
          uint8_t valueMsb = static_cast<uint8_t>(pData[4*index+1+dataHeader.offset]);
          uint8_t valueLsb = static_cast<uint8_t>(pData[4*index+0+dataHeader.offset]);
          unsigned int distance = static_cast<unsigned int>((valueMsb << 8) + valueLsb);
          statisticsDistance.addSample(static_cast<double>(distance));

          valueMsb = static_cast<uint8_t>(pData[4*index+3+dataHeader.offset]);
          valueLsb = static_cast<uint8_t>(pData[4*index+2+dataHeader.offset]);
          unsigned int amplitude = static_cast<unsigned int>((valueMsb << 8) + valueLsb);
          statisticsAmplitude.addSample(static_cast<double>(amplitude));
      }

      index++;

      if (index >= dataHeader.width * dataHeader.height){
        break;
      }

    }
  }

  unsigned int distance = static_cast<unsigned int>(statisticsDistance.getAverage());
  unsigned int amplitude = static_cast<unsigned int>(statisticsAmplitude.getAverage());
  emit newDistanceAmplitudeValue(distance, amplitude);
}

void MultiPixelStatistics::onDistanceGrayscaleReceived(const char *pData, DataHeader &dataHeader)
{
  Statistics statisticsDistance(selection.getNumPixel());
  Statistics statisticsGrayscale(selection.getNumPixel());

  unsigned int index = 0;
  for (int y =0; y < dataHeader.height; y++)
   {
     for (int x = 0; x < dataHeader.width; x++)
     {
       if (selection.contains(x, y))
       {
           uint8_t valueMsb = static_cast<uint8_t>(pData[4*index+1+dataHeader.offset]);
           uint8_t valueLsb = static_cast<uint8_t>(pData[4*index+0+dataHeader.offset]);
           unsigned int distance = static_cast<unsigned int>((valueMsb << 8) + valueLsb);
           statisticsDistance.addSample(static_cast<double>(distance));

           valueMsb = static_cast<uint8_t>(pData[4*index+3+dataHeader.offset]);
           valueLsb = static_cast<uint8_t>(pData[4*index+2+dataHeader.offset]);
           unsigned int amplitude = static_cast<unsigned int>((valueMsb << 8) + valueLsb);
           statisticsGrayscale.addSample(static_cast<double>(amplitude));
       }

       index++;

       if (index >= dataHeader.width * dataHeader.height){
         break;
       }

     }
   }

  unsigned int distance = static_cast<unsigned int>(statisticsDistance.getAverage());
  unsigned int grayscale = static_cast<unsigned int>(statisticsGrayscale.getAverage());
  emit newDistanceGrayscaleValue(distance, grayscale);
}

void MultiPixelStatistics::onDcsReceived(const char *pData, DataHeader &dataHeader)
{
  Statistics statisticsDcs0(selection.getNumPixel());
  Statistics statisticsDcs1(selection.getNumPixel());
  Statistics statisticsDcs2(selection.getNumPixel());
  Statistics statisticsDcs3(selection.getNumPixel());

  Statistics *statistics[4];
  statistics[0] = &statisticsDcs0;
  statistics[1] = &statisticsDcs1;
  statistics[2] = &statisticsDcs2;
  statistics[3] = &statisticsDcs3;


  unsigned int index = 0;

  for(int i= 0 ; i < 4; i++)
  {
      for (int y = 0; y < dataHeader.height; y++)
      {
          for (int x = 0; x < dataHeader.width; x++)
          {
              if (selection.contains(x, y))
              {
                  uint8_t valueMsb = static_cast<uint8_t>(pData[2*index+1+dataHeader.offset]);
                  uint8_t valueLsb = static_cast<uint8_t>(pData[2*index+0+dataHeader.offset]);
                  unsigned int value = static_cast<unsigned int>((valueMsb << 8) + valueLsb);
                  statistics[i]->addSample(static_cast<double>(value));
              }

              index++;

              if (index >= dataHeader.width * dataHeader.height * 4){
                  break;
              }

          }
      }
  }





  unsigned int dcs[4];
  for (unsigned int i = 0; i < 4; i++)
  {
    dcs[i] = static_cast<unsigned int>(statistics[i]->getAverage());
  }

  emit newDcsValue(dcs[0], dcs[1], dcs[2], dcs[3]);
}
