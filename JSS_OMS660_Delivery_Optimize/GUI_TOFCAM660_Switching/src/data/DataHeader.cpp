/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "DataHeader.h"


DataHeader::DataHeader(const char *data, const int length)
{
  getFromBuffer(data, length);
}

uint16_t DataHeader::getUint16FromCharBuffer(const char *data)
{
  uint16_t value = (((uint8_t) data[0]) << 8) + (uint8_t)data[1];

  return value;
}

void DataHeader:: getFromBuffer(const char *data, const int length)
{
  if (length < HEADER_SIZE)
  {
    return;
  }

  version = data[0];
  dataType = getUint16FromCharBuffer(&data[1]);
  width = getUint16FromCharBuffer(&data[3]);
  height = getUint16FromCharBuffer(&data[5]);
  roiX0 = getUint16FromCharBuffer(&data[7]);
  roiY0 = getUint16FromCharBuffer(&data[9]);
  roiX1 = getUint16FromCharBuffer(&data[11]);
  roiY1 = getUint16FromCharBuffer(&data[13]);
  intTime0 = getUint16FromCharBuffer(&data[15]);
  intTime1 = getUint16FromCharBuffer(&data[17]);
  intTime2 = getUint16FromCharBuffer(&data[19]);
  offset = getUint16FromCharBuffer(&data[23]);

  int userDataSize = offset - HEADER_SIZE;

  userData = QByteArray::fromRawData(&data[HEADER_SIZE], userDataSize);
}
