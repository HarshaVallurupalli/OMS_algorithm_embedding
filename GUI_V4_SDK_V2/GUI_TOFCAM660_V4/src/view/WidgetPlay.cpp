/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/


#include "WidgetData.h"
#include "WidgetPlay.h"
#include "ui_widget_play.h"

#include <QMessageBox>
#include <QFileDialog>
#include <iostream>
#include <cstdint>
#include <cstring>

WidgetPlay::WidgetPlay(ApplicationContext &context, Controller &controller_, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetPlay),
    set(context.getSettings()),
    controller(controller_)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updatePlay()));
    connect(&set.log, SIGNAL(streamModeChanged(int)), this, SLOT(streamModeChanged(int)));

    restoreSettings();

    updateFileIndexList();

    updateControls();

}

WidgetPlay::~WidgetPlay()
{
    delete ui;

}

void WidgetPlay::restoreSettings()
{
    ui->leFolderPath->setText(set.log.getLogPath());
    ui->leFileName->setText(set.log.getLogName());
    ui->sbFps->setValue(set.log.getFps());
}


void WidgetPlay::on_tbSelectPath_clicked()
{
    QFileDialog fileDialog(this);
    fileDialog.setFileMode(QFileDialog::DirectoryOnly);
    fileDialog.setOption(QFileDialog::ShowDirsOnly);

    fileDialog.setDirectory(set.log.getLogPath());

    if (fileDialog.exec()) {
        ui->leFolderPath->setText(fileDialog.selectedFiles()[0]);
        QString str = ui->leFolderPath->text();
        set.log.setLogPath(str);
        updateFileIndexList();
        updateControls();
    }

}

void WidgetPlay::updateControls(){

    int count = ui->listWidgetNames->count();

    if(count>0){
        selectedItem = count - 1;
        ui->listWidgetNames->setCurrentRow(selectedItem);
        QListWidgetItem *item = ui->listWidgetNames->currentItem();
        selectedIdxFile = item->text();
        ui->tbPlay->setEnabled(true);
        ui->tbDeleteFiles->setEnabled(true);
        ui->tbDeleteSelectedFile->setEnabled(true);
        ui->tbStop->setEnabled(true);

    }else{
        ui->tbPlay->setEnabled(false);
        ui->tbDeleteFiles->setEnabled(false);
        ui->tbDeleteSelectedFile->setEnabled(false);
        ui->tbStop->setEnabled(false);
    }

    ui->sliderPlay->setEnabled(false);

    counter = 0;
    selectedItem = 0;
    playState = false;
    recordState = false;

    ui->tbPlay->setStyleSheet("QToolButton{background-color: rgb(84, 141, 105);}");
    ui->tbStop->setStyleSheet("QToolButton{background-color: rgb(84, 141, 105);}");
    ui->tbRecord->setStyleSheet("QToolButton{background-color: rgb(84, 141, 105);}");
    currentDataType = -1; //default
}


void WidgetPlay::on_leFolderPath_textChanged(const QString &arg1)
{
    set.log.setLogPath(arg1);
    updateFileIndexList();
    updateControls();
}

void WidgetPlay::on_leFileName_textChanged(const QString &arg1)
{
    set.log.setLogName(arg1);
}


void WidgetPlay::updateFileIndexList(){
    QDir directory(set.log.getLogPath());
    QStringList images = directory.entryList(QStringList() << "*.idx",QDir::Files);
    ui->listWidgetNames->clear();
    foreach(QString str, images) {     
        int pos = str.lastIndexOf(QChar('.'));
        str =  str.left(pos);
        ui->listWidgetNames->addItem(str);
    }

}

void WidgetPlay::on_tbPlay_clicked()
{
    playState = !playState;
    ui->tbRecord->setDisabled(playState);

    if(playState){

        ui->tbPlay->setText("Pause");
        ui->tbPlay->setStyleSheet("QToolButton{background-color: rgb(251, 34, 50);}");
        set.log.setRecord(false);
        updateFileIndexList();
        createPlayList();

        ui->sliderPlay->setMinimum(0);
        ui->sliderPlay->setMaximum( static_cast<long>(fileList.size()-1));
        ui->sliderPlay->setValue(static_cast<int>(counter));
        ui->tbStop->setEnabled(true);        

        set.log.setStreamMode(SettingsLog::StreamMode::PLAY);

        int dt = static_cast<int>(1000.0 / set.log.getFps());
        timer->start(dt);

    }else{        
        ui->tbPlay->setText("Play");
        ui->tbPlay->setStyleSheet("QToolButton{background-color: rgb(84, 141, 105);}");
        set.log.setStreamMode(SettingsLog::StreamMode::STOP);
        timer->stop();
    }

    ui->sliderPlay->setEnabled(true);
    ui->listWidgetNames->setCurrentRow(selectedItem);
}

void WidgetPlay::on_tbStop_clicked()
{

    if(set.log.isRecord() || recordState){
        recordState = false;
        set.log.setRecord(false);
        ui->tbPlay->setEnabled(true);
        ui->tbRecord->setText("Record");
        updateFileIndexList();
        selectedItem = ui->listWidgetNames->count() - 1;
        ui->listWidgetNames->setCurrentRow(selectedItem);
        QListWidgetItem *item = ui->listWidgetNames->currentItem();
        selectedIdxFile = item->text();        
        emit recordClicked(false);
    }

    if(playState){
        playState = false;
        ui->tbPlay->setText("Play");
        ui->tbRecord->setEnabled(true);    
    }

    set.log.setStreamMode(SettingsLog::StreamMode::STOP);

    timer->stop();
    counter = 0;
    ui->sliderPlay->setValue(0);
    ui->listWidgetNames->setCurrentRow(selectedItem);
    ui->tbPlay->setStyleSheet("QToolButton{background-color: rgb(84, 141, 105);}");
    ui->tbRecord->setStyleSheet("QToolButton{background-color: rgb(84, 141, 105);}");   

}



void WidgetPlay::on_tbRecord_clicked()
{
    recordState = !recordState;

    if(recordState){
        ui->tbRecord->setText("Stop record");
        ui->tbRecord->setStyleSheet("QToolButton{background-color: rgb(251, 170, 0);}");
        ui->tbStop->setEnabled(true);
        set.log.setStreamMode(SettingsLog::StreamMode::RECORD);        
    }else{        
        ui->tbRecord->setText("Record");
        ui->tbRecord->setStyleSheet("QToolButton{background-color: rgb(84, 141, 105);}");
        set.log.setStreamMode(SettingsLog::StreamMode::STOP);

        updateFileIndexList();
        selectedItem = ui->listWidgetNames->count() - 1;
        ui->listWidgetNames->setCurrentRow(selectedItem);
        QListWidgetItem *item = ui->listWidgetNames->currentItem();
        selectedIdxFile = item->text();

        if(ui->listWidgetNames->count() > 0){
            ui->tbDeleteFiles->setEnabled(true);
            ui->tbDeleteSelectedFile->setEnabled(true);            
        }

    }

    counter = 0;
    ui->sliderPlay->setValue(0);
    ui->tbPlay->setDisabled(recordState);
    set.log.setRecord(recordState);
    emit recordClicked(recordState);
}



void WidgetPlay::on_sbFps_valueChanged(double arg1)
{
    set.log.setFps(arg1);
}


void WidgetPlay::on_listWidgetNames_itemClicked(QListWidgetItem *item)
{
    if(!playState && !recordState){
        selectedIdxFile = item->text();
        selectedItem =  ui->listWidgetNames->currentRow();
    }else{
        ui->tbStop->click();
    }
}


void WidgetPlay::createPlayList(){

    QString fname = set.log.getLogPath() + "/" + selectedIdxFile + ".idx";    

    QString str;
    QFile file(fname);
    file.open( QIODevice::ReadOnly );
    QTextStream stream(&file);

    fileList.clear();

    while(!stream.atEnd()){
        stream >> str;
        fileList.emplace_back(str);
    }

    str = fileList.back();
    if(str.isEmpty())
        fileList.pop_back();

    file.close();

}



void WidgetPlay::openPlayFile(QString &name, char* pData, uint& length){

    QString fname = set.log.getLogPath() + "/" + name + ".bin";
    QFile file(fname);
    char* data;

    if(file.open(QIODevice::ReadOnly)) {
        QDataStream reader(&file);
        reader.readBytes(data, length);
        std::memcpy(pData, data, length);
    }

    file.close();
}

void WidgetPlay::updatePlay(){

    uint length;

    if(counter < fileList.size()){
        openPlayFile(fileList[counter], dataBuffer, length);
        DataHeader dataHeader(dataBuffer, static_cast<int>(length));

        if( currentDataType != dataHeader.dataType){
            currentDataType = dataHeader.dataType;
            dataTypeChanged();            
        }

        emit receivedMeasurementData(dataBuffer, length, dataHeader);        
        emit ui->sliderPlay->setValue(static_cast<int>(counter));
        counter++;
    }else{
        ui->tbStop->click();
    }

}


void WidgetPlay::on_sliderPlay_sliderMoved(int position)
{
    counter = static_cast<uint>(position);
    uint length;
    openPlayFile(fileList[counter], dataBuffer, length);
    DataHeader dataHeader(dataBuffer, static_cast<int>(length));
    emit receivedMeasurementData(dataBuffer, length, dataHeader);
}


void WidgetPlay::on_tbDeleteFiles_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Attention!");
    msgBox.setText("Are you sure you want to delete all records?");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::Yes){
        QString path = set.log.getLogPath();
        QDir dir(path);
        dir.setNameFilters(QStringList() << "*.*");
        dir.setFilter(QDir::Files);
        foreach(QString dirFile, dir.entryList()){
            dir.remove(dirFile);
        }

        updateFileIndexList();
        ui->tbPlay->setEnabled(false);
        ui->tbDeleteFiles->setEnabled(false);
        ui->tbDeleteSelectedFile->setEnabled(false);
        ui->sliderPlay->setEnabled(false);
        ui->tbStop->setEnabled(false);
    }
}


void WidgetPlay::on_tbDeleteSelectedFile_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Attention!");
    msgBox.setText("Are you sure you want to delete selected record?");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::Yes){
        QString path = set.log.getLogPath();
        QDir dir(path);

        QListWidgetItem *item = ui->listWidgetNames->currentItem();
        selectedIdxFile = item->text();
        createPlayList();

        for(uint i=0; i < fileList.size(); i++){
            QString str = fileList[i] + ".bin";
            dir.remove(str);
        }

        dir.remove(selectedIdxFile + ".idx");
        updateFileIndexList();
    }

    int count = ui->listWidgetNames->count();

    if(count > 0){
        selectedItem = count - 1;
        ui->listWidgetNames->setCurrentRow(selectedItem);
        QListWidgetItem *item = ui->listWidgetNames->currentItem();
        selectedIdxFile = item->text();
    }else{
        ui->tbPlay->setEnabled(false);
        ui->tbDeleteFiles->setEnabled(false);
        ui->tbDeleteSelectedFile->setEnabled(false);
        ui->sliderPlay->setEnabled(false);
        ui->tbStop->setEnabled(false);
    }



}

void WidgetPlay::streamModeChanged(int val){

    switch(val) {
        case SettingsLog::StreamMode::STOP:
            ui->tbPlay->setEnabled(true);
            ui->tbRecord->setEnabled(true);
            if(set.log.isRecord() || recordState){
                recordState = false;
                set.log.setRecord(false);
                ui->tbRecord->setText("Record");
                updateFileIndexList();
                selectedItem = ui->listWidgetNames->count() - 1;
                ui->listWidgetNames->setCurrentRow(selectedItem);
                QListWidgetItem *item = ui->listWidgetNames->currentItem();
                selectedIdxFile = item->text();                
            }

            if(playState){
                playState = false;
                ui->tbPlay->setText("Play");
            }

            timer->stop();
            //counter = 0;
            //ui->sliderPlay->setValue(0);
            ui->listWidgetNames->setCurrentRow(selectedItem);
            ui->tbPlay->setStyleSheet("QToolButton{background-color: rgb(84, 141, 105);}");
            ui->tbRecord->setStyleSheet("QToolButton{background-color: rgb(84, 141, 105);}");

            break;

        case SettingsLog::StreamMode::STREAM:
            ui->tbPlay->setEnabled(false);
            ui->tbRecord->setEnabled(false);
            break;

        case SettingsLog::StreamMode::RECORD:
            recordState = true;
            ui->tbPlay->setEnabled(false);
            ui->tbRecord->setText("Stop record");
            ui->tbRecord->setStyleSheet("QToolButton{background-color: rgb(251, 170, 0);}");
            ui->tbStop->setEnabled(true);

            break;

        case SettingsLog::StreamMode::PLAY:
            break;
    }

}


void WidgetPlay::currentIndexChanged(int index){

    if(index < 3) imageType = 0; //image
    else imageType = 1;  //point cloud

    ui->comBoxImageType->setCurrentIndex(imageType);


}

void WidgetPlay::on_comBoxImageType_currentIndexChanged(int index)
{
    imageType = index;
    dataTypeChanged();
}


void WidgetPlay::dataTypeChanged(){

    int index=0;

    switch(currentDataType)
    {
    case tofCamData_e::TOFCAM_DATA_DISTANCE_AMPLITUDE:
        if(imageType == 0) index = 1; //image
        else index = 4; //point cloud
        break;
    case tofCamData_e::TOFCAM_DATA_DISTANCE:
        if(imageType == 0) index = 0;
        else index = 3;
        break;
    case tofCamData_e::TOFCAM_DATA_GRAYSCALE:
        index = 2;
        imageType = 0;
        ui->comBoxImageType->setCurrentIndex(imageType);
        break;
    }

   emit indexViewChanged(index);
}


void WidgetPlay::on_listWidgetNames_itemDoubleClicked(QListWidgetItem *item)
{
    selectedIdxFile = item->text();
    selectedItem =  ui->listWidgetNames->currentRow();
    ui->tbPlay->click();

}
