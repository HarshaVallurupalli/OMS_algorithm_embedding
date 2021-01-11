/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef WIDGETPLAY_H
#define WIDGETPLAY_H


#include "ApplicationContext.h"
#include "Controller.h"
#include <QListWidgetItem>
#include <QWidget>
#include <QTimer>
#include <vector>

namespace Ui {
class WidgetPlay;
}

class WidgetPlay : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetPlay(ApplicationContext &context, Controller &controller_, QWidget *parent = nullptr);
    ~WidgetPlay();
    void restoreSettings();

signals:    
    void receivedMeasurementData(const char *pData, uint length, DataHeader &dataHeader);
    void recordClicked(bool);
    void indexViewChanged(int index);

private slots:
    void updatePlay();
    void updateFileIndexList();    
    void on_tbSelectPath_clicked();
    void on_leFolderPath_textChanged(const QString &arg1);
    void on_leFileName_textChanged(const QString &arg1);    
    void on_tbPlay_clicked();    
    void on_listWidgetNames_itemClicked(QListWidgetItem *item);
    void on_tbStop_clicked();   
    void on_sbFps_valueChanged(double arg1);    
    void on_sliderPlay_sliderMoved(int position);
    void on_tbRecord_clicked();
    void on_tbDeleteFiles_clicked();
    void on_tbDeleteSelectedFile_clicked();
    void streamModeChanged(int val);
    void on_comBoxImageType_currentIndexChanged(int index);
    void currentIndexChanged(int index);
    void on_listWidgetNames_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::WidgetPlay *ui;
    Settings &set;
    Controller &controller;
    QString selectedIdxFile;
    std::vector<QString> fileList;
    QTimer *timer;
    uint counter;
    int selectedItem;
    int imageType;
    int currentDataType;
    char dataBuffer[10000000];
    bool playState;
    bool recordState;


    void createPlayList();
    void updateControls();
    void openPlayFile(QString &name, char *pData, uint &length);
    void dataTypeChanged();

};

#endif // WIDGETPLAY_H
