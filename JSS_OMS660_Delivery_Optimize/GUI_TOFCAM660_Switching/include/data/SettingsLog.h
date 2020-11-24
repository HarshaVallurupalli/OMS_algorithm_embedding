/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef SETTINGSLOG_H
#define SETTINGSLOG_H

#include <QObject>

class SettingsLog : public QObject
{
    Q_OBJECT
public:
    explicit SettingsLog(QObject *parent = nullptr);

    enum StreamMode { STOP, STREAM, RECORD, PLAY };


public slots:

    void setRecord(bool state);
    bool isRecord();
    void setDisplayRecord(bool state);
    bool isDispalyRecord();
    void setLogPath(QString str);
    QString getLogPath();
    void setLogName(QString str);
    QString getLogName();
    void setFps(double val);
    double getFps();    
    void setStreamMode(int mode);
    int getStreamMode();

signals:
    void streamModeChanged(int);

private:

    bool record;
    bool display;
    int streamMode;

    QString fname;
    QString path;
    double fps;


};

#endif // SETTINGSLOG_H
