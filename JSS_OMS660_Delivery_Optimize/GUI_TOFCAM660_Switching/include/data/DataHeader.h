/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef DATA_HEADER_H
#define DATA_HEADER_H

#include <stdint.h>
#include <QByteArray>

class DataHeader
{
public:
  DataHeader(const char *data, const int length);
  uint8_t version;
  uint16_t dataType;
  uint16_t width;
  uint16_t height;
  uint16_t roiX0;
  uint16_t roiY0;
  uint16_t roiX1;
  uint16_t roiY1;
  uint16_t intTime0;
  uint16_t intTime1;
  uint16_t intTime2;
  uint16_t offset;
  QByteArray userData;

  void getFromBuffer(const char *data, const int length);

private:
  uint16_t getUint16FromCharBuffer(const char *data);

  const int HEADER_SIZE = 25;
};

#endif // DATA_HEADER_H
