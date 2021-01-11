/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef DATA_CONNECTION_H
#define DATA_CONNECTION_H

#include <QObject>

class DataConnection: public QObject
{
  Q_OBJECT   

  public:    
    virtual ~DataConnection(){}
    virtual void setPort(const uint16_t port) = 0;

  public slots:
    virtual void startRunning() = 0;
    virtual void stopRunning() = 0;

  signals:
    void receivedData(const char *pData, const int length, const bool complete);

};

#endif // CONNECTION_H
