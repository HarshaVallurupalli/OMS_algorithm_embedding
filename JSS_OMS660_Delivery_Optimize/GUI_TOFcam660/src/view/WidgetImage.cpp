/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "WidgetImage.h"
#include "ui_widget_image.h"

WidgetImage::WidgetImage(ApplicationContext &context, Controller &controller, QWidget *parent):
    QWidget(parent),
    context(context),
    controller(controller),
    ui(new Ui::WidgetImage)
{
  ui->setupUi(this);

  QVBoxLayout *vboxSettingsBase = new QVBoxLayout();
  widgetSettingsBase = new WidgetSettingsBase(context);
  vboxSettingsBase->setMargin(0);
  vboxSettingsBase->addWidget(widgetSettingsBase);
  ui->gbBase->setLayout(vboxSettingsBase);

  QVBoxLayout *vboxSettingsFilter = new QVBoxLayout();
  widgetSettingsFilter = new WidgetSettingsFilter(context);
  vboxSettingsFilter->setMargin(0);
  vboxSettingsFilter->addWidget(widgetSettingsFilter);
  ui->gbFilters->setLayout(vboxSettingsFilter);

  QVBoxLayout *vboxSettingsModulation = new QVBoxLayout();
  widgetSettingsModulation = new WidgetSettingsModulation(context);
  vboxSettingsModulation->setMargin(0);
  vboxSettingsModulation->addWidget(widgetSettingsModulation);
  ui->gbModulation->setLayout(vboxSettingsModulation);

  QVBoxLayout *vboxSettingsBinning = new QVBoxLayout();
  widgetSettingsBinning = new WidgetSettingsBinning(context);
  vboxSettingsBinning->setMargin(0);
  vboxSettingsBinning->addWidget(widgetSettingsBinning);
  ui->gbBinning->setLayout(vboxSettingsBinning);

  QVBoxLayout *vboxSettingsROI= new QVBoxLayout();
  widgetSettingsROI = new WidgetSettingsROI(context);
  vboxSettingsROI->setMargin(0);
  vboxSettingsROI->addWidget(widgetSettingsROI);
  ui->gbRoi->setLayout(vboxSettingsROI);

  context.getSettings().log.setDisplayRecord(true);
  context.getSettings().log.setRecord(false);
  ui->cbDisplay->setChecked(false);
  ui->cbDisplay->setEnabled(false);
  ui->cbRecord->setChecked(false);


  //Signals from context to this
  connect(&context, &ApplicationContext::stateChanged, this, &WidgetImage::onStateChange);  
  connect(&context.getSettings().log, SIGNAL(streamModeChanged(int)), this, SLOT(streamModeChanged(int)));  
  connect(&context.getSettings(), SIGNAL(showInfoChanged(bool)), ui->cbPixelInfo, SLOT(setChecked(bool)));
  connect(&context.getSettings(), SIGNAL(showPixelScopeChanged(bool)), ui->cbPixelScope, SLOT(setChecked(bool)));
  connect(&context.getSettings(), SIGNAL(showTimeScopeChanged(bool)), ui->cbTimeScope, SLOT(setChecked(bool)));

  restoreSettings();
  onStateChange();

}

WidgetImage::~WidgetImage()
{
    delete ui;
}

void WidgetImage::restoreSettings()
{        

    int viewType = context.getSettings().getViewType();

    qDebug()<<"WidgetImage::restoreSettings: viewType"<< viewType; //TODO remove

    if(viewType < 0 ) viewType = 0;

    ui->comboBoxImageType->setCurrentIndex(viewType);
    widgetSettingsBase->restoreSettings();
    widgetSettingsFilter->restoreSettings();
    widgetSettingsModulation->restoreSettings();
    widgetSettingsROI->restoreSettings();
    widgetSettingsBinning->restoreSettings();
}

void WidgetImage::requestData(const bool isStream)
{

  switch(ui->comboBoxImageType->currentIndex())
  {
    case 0:      
      context.getSettings().setViewType(Settings::ViewType::DISTANCE);
      controller.requestDistance(isStream);      
      break;
    case 1:      
      context.getSettings().setViewType(Settings::ViewType::DISTANCE_AMPLITUDE);
      controller.requestDistanceAmplitude(isStream);      
      break;
    case 2:
      context.getSettings().setViewType(Settings::ViewType::GRAYSCALE);
      controller.requestGrayscale(isStream);      
      break;
    case 3:
      context.getSettings().setViewType(Settings::ViewType::POINT_CLOUD_DISTANCE);
      controller.requestPointCloudDistance(isStream);
      break;
    case 4:
      context.getSettings().setViewType(Settings::ViewType::POINT_CLOUD_DISTANCE_AMPLITUDE);
      controller.requestPointCloudDistanceAmplitude(isStream);      
      break;
    case 5:
      context.getSettings().setViewType(Settings::ViewType::DCS);
      controller.requestDCS(isStream);
      break;

  }
}


void WidgetImage::changeImageType()
{

  switch(ui->comboBoxImageType->currentIndex())
  {
    case 0:
      context.getSettings().setViewType(Settings::ViewType::DISTANCE);
      break;
    case 1:
      context.getSettings().setViewType(Settings::ViewType::DISTANCE_AMPLITUDE);
      break;
    case 2:
      context.getSettings().setViewType(Settings::ViewType::GRAYSCALE);
      break;
    case 3:
      context.getSettings().setViewType(Settings::ViewType::POINT_CLOUD_DISTANCE);
      break;
    case 4:
      context.getSettings().setViewType(Settings::ViewType::POINT_CLOUD_DISTANCE_AMPLITUDE);
      break;
    case 5:
      context.getSettings().setViewType(Settings::ViewType::DCS);
      break;

  }
}



void WidgetImage::on_pushButtonSingle_clicked()
{
  requestData(false);  
}

void WidgetImage::on_pushButtonStream_clicked()
{
    if(context.isStreaming()) {
        controller.stopStream();
        ui->cbRecord->setEnabled(true);
        ui->cbRecord->setChecked(false);
        context.getSettings().log.setStreamMode(SettingsLog::StreamMode::STOP);
    }else{
        requestData(true);
        ui->cbRecord->setEnabled(false);
        if(context.getSettings().log.isRecord()){
            context.getSettings().start();
            context.getSettings().log.setStreamMode(SettingsLog::StreamMode::RECORD);
        }else{
            context.getSettings().log.setStreamMode(SettingsLog::StreamMode::STREAM);
        }
    }
}

void WidgetImage::onStateChange()
{
  switch(context.getApplicationState())
  {
    case TypeApplicationState::STATE_UNCONNECTED:
      ui->pushButtonStream->setText("Start");
      ui->pushButtonStream->setStyleSheet("QPushButton{background-color: rgb(84, 141, 105);}");
      ui->pushButtonStream->setIcon(QIcon(":/icons/images/icons/videoStart.png"));
      ui->pushButtonSingle->setEnabled(false);
      ui->pushButtonStream->setEnabled(false);
      break;
    case TypeApplicationState::STATE_CONNECTED:
      ui->pushButtonStream->setText("Start");
      ui->pushButtonStream->setStyleSheet("QPushButton{background-color: rgb(84, 141, 105);}");
      ui->pushButtonStream->setIcon(QIcon(":/icons/images/icons/videoStart.png"));
      ui->pushButtonSingle->setEnabled(true);
      ui->pushButtonStream->setEnabled(true);
      break;
    case TypeApplicationState::STATE_STREAM:
      ui->pushButtonStream->setText("Stop");

      if(context.getSettings().log.isRecord()){
          ui->pushButtonStream->setStyleSheet("QPushButton{background-color: rgb(251, 170, 0);}");
      }else{
          ui->pushButtonStream->setStyleSheet("QPushButton{background-color: rgb(251, 34, 50);}");
      }

      ui->pushButtonStream->setIcon(QIcon(":/icons/images/icons/videoStop.png"));
      ui->pushButtonSingle->setEnabled(false);
      ui->pushButtonStream->setEnabled(true);
      break;
    case TypeApplicationState::STATE_CALIBRATION:

      break;
    case TypeApplicationState::STATE_CALIBRATION_SYSTEM_OFFSET:

      break;
  }
}

void WidgetImage::on_comboBoxImageType_currentIndexChanged(int index)
{
    Q_UNUSED(index)

    if (context.isStreaming())
    {
        requestData(true);
    }

    changeImageType();


    context.getSettings().setViewType(static_cast<uint>(index));

    if(index == 3) context.getSettings().setMeasurementType(0);
    else if(index == 4) context.getSettings().setMeasurementType(1);
    else context.getSettings().setMeasurementType(index);

    //if(index == 0 || index == 2) ui->cbPixelScope->setEnabled(true);
    //else ui->cbPixelScope->setEnabled(false);

    if(index == 3 || index == 4){
        ui->cbTimeScope->setEnabled(false);
        ui->cbPixelInfo->setEnabled(false);
    }else{
        ui->cbTimeScope->setEnabled(true);
        ui->cbPixelInfo->setEnabled(true);
    }

    emit currentIndexChanged(index);
}

void WidgetImage::on_cbRecord_toggled(bool checked)
{
    if(!checked){
        ui->cbDisplay->setChecked(checked);
        emit updatePlayList();
    }

    ui->cbDisplay->setEnabled(checked);
    context.getSettings().log.setRecord(checked);
}

void WidgetImage::on_cbDisplay_toggled(bool checked)
{
    context.getSettings().log.setDisplayRecord(!checked);
}


void WidgetImage::recordClicked(bool state){

    context.getSettings().log.setRecord(state);

    if(context.isStreaming() && state) {
        context.getSettings().start();
    }

    emit ui->pushButtonStream->click();
}


void WidgetImage::streamModeChanged(int state){

    switch (state) {
        case SettingsLog::StreamMode::STOP:

            if(context.isStreaming()) {
                controller.stopStream();
            }

            ui->pushButtonStream->setEnabled(true);
            ui->pushButtonSingle->setEnabled(true);
            ui->cbRecord->setEnabled(true);
            break;

        case SettingsLog::StreamMode::STREAM:
            break;

        case SettingsLog::StreamMode::RECORD:
            break;

        case SettingsLog::StreamMode::PLAY:
            ui->pushButtonStream->setEnabled(false);
            ui->pushButtonSingle->setEnabled(false);
            ui->cbRecord->setEnabled(false);
            break;
    }
}


void WidgetImage::indexViewChanged(int index)
{
    ui->comboBoxImageType->setCurrentIndex(index);    
}

void WidgetImage::on_cbPixelInfo_toggled(bool checked)
{
    context.getSettings().setShowInfo(checked);
}

void WidgetImage::on_cbPixelScope_toggled(bool checked)
{
    context.getSettings().setShowPixelScope(checked);
}

void WidgetImage::on_cbTimeScope_toggled(bool checked)
{
    context.getSettings().setShowTimeScope(checked);
}

void WidgetImage::on_cbDataToDifferentIP_toggled(bool checked)
{
    context.getSettings().setDataDestinationIP(checked);
    emit cameraIPAddressChanged();
}

void WidgetImage::onSelectionPixelInfoChanged(bool state)
{
    ui->cbPixelInfo->setChecked(state);
}

void WidgetImage::onSelectionPixelScopeChanged(bool state)
{
    ui->cbPixelScope->setChecked(state);
}

void WidgetImage::onSelectionTimeScopeChanged(bool state)
{
    ui->cbTimeScope->setChecked(state);
}











