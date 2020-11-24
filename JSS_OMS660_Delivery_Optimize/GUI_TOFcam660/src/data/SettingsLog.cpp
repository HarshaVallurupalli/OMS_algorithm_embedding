/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "SettingsLog.h"

SettingsLog::SettingsLog(QObject *parent) : QObject(parent)
{
    fname = "image";
    fps = 10;
    streamMode = StreamMode::STOP;

}

void SettingsLog::setRecord(bool state){
    record = state;
}

bool SettingsLog::isRecord(){
    return record;
}

void SettingsLog::setDisplayRecord(bool state){
    display = state;
}

bool SettingsLog::isDispalyRecord(){
    return display;
}

void SettingsLog::setLogPath(QString str){
    path = str;
}

QString SettingsLog::getLogPath(){
    return path;
}

void SettingsLog::setLogName(QString str){
    fname = str;
}

QString SettingsLog::getLogName(){
    return fname;
}

void SettingsLog::setFps(double val){
    fps = val;
}


double SettingsLog::getFps(){
    return fps;
}

void SettingsLog::setStreamMode(int val){
    streamMode = val;
    emit streamModeChanged(streamMode);
}

int SettingsLog::getStreamMode(){
    return streamMode;
}
