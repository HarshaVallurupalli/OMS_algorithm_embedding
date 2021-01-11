/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "ImageColorizer.h"
#include <QImage>
#include <QApplication>
#include <QDesktopServices>
#include <QUrl>
#include <QMessageBox>
#include "UdpDataConnection.h"
#include "TcpCmdConnection.h"
#include <QTimer>
#include "global/Release.h"
#include "DataHeader.h"
#include "math.h"
#include <QKeyEvent>
#include <QThread>


const QString release("Release 1.5");

MainWindow::MainWindow(ApplicationContext &context, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    context(context),
    controller(context)
{
    ui->setupUi(this);

    widgetImage = new WidgetImage(context, controller, this);
    widgetPlay  = new WidgetPlay(context, controller, this);
    widgetCalibration = new WidgetCalibration(context, controller, this);
    widgetMetaData = new WidgetTools(context, this);
    widgetData  = new WidgetData(context);
    widgetPointCloud = new WidgetPointCloud(context);    
    widgetSettings = new WidgetSettings(context, this);
    widgetSaveLoad = new WidgetSaveLoad(context, this);

    ui->stackedView->addWidget(widgetImage);
    ui->stackedView->addWidget(widgetPlay);
    ui->stackedView->addWidget(widgetSettings);
    ui->stackedView->addWidget(widgetCalibration);
    ui->stackedView->addWidget(widgetMetaData);
    ui->stackedView->addWidget(widgetSaveLoad);

    storage = QStorageInfo::root();

    labelStatus = new QLabel();
    ui->statusBar->addWidget(labelStatus);

    //Signals from the controller to the main window
    connect(&controller, &Controller::receivedMeasurementData, this, &MainWindow::receivedMeasurementData);
    connect(&controller, &Controller::updateFps, this, &MainWindow::updateFps);
    connect(&controller, &Controller::error, this, &MainWindow::onError);
    connect(this, &MainWindow::showData, widgetPointCloud, &WidgetPointCloud::showData);    
    connect(&context.getSettings(), SIGNAL(formatChanged()), widgetData, SLOT(formatChanged()));
    connect(&context.getSettings(), SIGNAL(formatChanged()), widgetPointCloud, SLOT(formatChanged()));
    connect(&context.getSettings(), SIGNAL(mirrorChanged()), widgetData, SLOT(mirrorChanged()));
    connect(&context.getSettings(), SIGNAL(mirrorChanged()), widgetPointCloud, SLOT(mirrorChanged()));
    connect(widgetPlay, &WidgetPlay::receivedMeasurementData, this, &MainWindow::receivedMeasurementData);
    connect(widgetPlay, SIGNAL(recordClicked(bool)), widgetImage, SLOT(recordClicked(bool)));
    connect(widgetImage, SIGNAL(updatePlayList()),   widgetPlay, SLOT(updateFileIndexList()));    
    connect(widgetImage, SIGNAL(currentIndexChanged(int)),   widgetPlay, SLOT(currentIndexChanged(int)));
    connect(widgetImage, SIGNAL(cameraIPAddressChanged()),   widgetSettings, SLOT(on_tbApply_clicked()));
    connect(widgetData, SIGNAL(updateTimeScopeDistance(const char*, DataHeader&)),   &context.getMultiPixelStatistics(), SLOT(onDistanceReceived(const char*, DataHeader&)));
    connect(widgetData, SIGNAL(updateTimeScopeDistanceAmplitude(const char*, DataHeader&)),   &context.getMultiPixelStatistics(), SLOT(onDistanceAmplitudeReceived(const char*, DataHeader&)));
    connect(widgetData, SIGNAL(updateTimeScopeGrayscale(const char*, DataHeader&)),   &context.getMultiPixelStatistics(), SLOT(onGrayscaleReceived(const char*, DataHeader&)));
    connect(&context.getSettings(), SIGNAL(settingsLoaded()), this,  SLOT(restoreSettings()));
    connect(widgetData, SIGNAL(selectedPixelInfo(bool)),  widgetImage, SLOT(onSelectionPixelInfoChanged(bool)));
    connect(widgetData, SIGNAL(selectedPixelScope(bool)), widgetImage, SLOT(onSelectionPixelScopeChanged(bool)));
    connect(widgetData, SIGNAL(selectedTimeScope(bool)),  widgetImage, SLOT(onSelectionTimeScopeChanged(bool)));    
    connect(&context.getInterface(), SIGNAL(receivedFirmwareRelease(int, int)),  this, SLOT(receivedFirmwareRelease(int, int)));
    connect(&context.getInterface(), SIGNAL(receivedChipInfo(int, int)),  this, SLOT(receivedChipInfo(int, int)));
    connect(&context.getSettings(),  SIGNAL(systemInfoChanged()), this, SLOT(showSystemInfo()));

    //Signals from context to this
    connect(&context, &ApplicationContext::stateChanged, this, &MainWindow::onStateChange);

    //Signals from GUI elements
    connect(ui->pushButtonLogo, SIGNAL(clicked(bool)), this, SLOT(onPushButtonLogoClicked()));

    //From key handler
    connect(&context.getKeyHandler(), &KeyHandler::developerModeEnabled, this, &MainWindow::onDeveloperModeEnabled);

    //Get init state
    onStateChange();

    ui->actionTools->setVisible(false);
    ui->actionCalibration->setVisible(false);

    widgetData->restoreSettings();

    widgetPointCloud->hide();

    Settings &set = context.getSettings();

    emit set.formatChanged();
    emit set.mirrorChanged();

    if(set.getMainWinWidth()!=0 && set.getMainWinHeight()!=0){
        this->setGeometry(set.getMainWinPosX(), set.getMainWinPosY(), set.getMainWinWidth(), set.getMainWinHeight());
    }
}

MainWindow::~MainWindow()
{
    delete widgetSaveLoad;
    delete widgetSettings;
    delete widgetPointCloud;
    delete widgetData;
    delete widgetCalibration;
    delete widgetImage;
    delete widgetMetaData;
    delete ui;
}

void MainWindow::restoreSettings()
{
    Settings &set = context.getSettings();
    if(set.getMainWinWidth()!=0 && set.getMainWinHeight()!=0){
        this->setGeometry(set.getMainWinPosX(), set.getMainWinPosY(), set.getMainWinWidth(), set.getMainWinHeight());
    }

    widgetImage->restoreSettings();
    widgetData->restoreSettings();
    widgetPointCloud->restoreSettings();
    widgetPlay->restoreSettings();

}


void MainWindow::showSystemInfo()
{
  QString guiString = "    GUI Version            #  " + QString::number(GUI_RELEASE, 'f', 2) + "\r\n";

  uint16_t major = context.getSettings().getMajor();
  uint16_t minor = context.getSettings().getMinor();
  QString firmwareString = "    FirmWare Version  #  " + QString::number(major) + "." + QString::number(minor) + "\r\n";

  uint16_t waferID = context.getSettings().getWaferID();
  uint16_t chipID  = context.getSettings().getChipID();

  QString waferIdString = "    Camera WaferID    #  " + QString::number(waferID) + "\r\n";
  QString chipIdString = "    Camera ChipID      #  " + QString::number(chipID);

ui->labelSystemInfo->setText(guiString + firmwareString + waferIdString + chipIdString);
}



void MainWindow::keyPressEvent(QKeyEvent *event)
{
  context.getKeyHandler().keyPressEvent(event);
}

void MainWindow::onDeveloperModeEnabled()
{
    ui->actionCalibration->setEnabled(true);
    ui->actionCalibration->setVisible(true);
    ui->actionTools->setEnabled(true);
    ui->actionTools->setVisible(true);
}

void MainWindow::closeEvent (QCloseEvent *event  __attribute__((unused)))
{    
    QRect rect = this->geometry();
    context.getSettings().setMainWinRect(rect);

    rect = widgetData->geometry();
    context.getSettings().setWinDataRect(rect);

    widgetPointCloud->close();
    widgetData->close();
    controller.close();
}

void MainWindow::moveEvent(QMoveEvent *)
{
    QRect rect = this->geometry();
    context.getSettings().setMainWinRect(rect);
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    QRect rect = this->geometry();
    context.getSettings().setMainWinRect(rect);
}

void MainWindow::updateFps(const unsigned int fps)
{  
    widgetData->updateFps(fps);
}

void MainWindow::receivedMeasurementData(const char *pData, uint length, DataHeader &dataHeader)
{
    widgetMetaData->updateHeaderData(dataHeader);

    if(context.getSettings().getViewType() == Settings::ViewType::POINT_CLOUD_DISTANCE ||
            context.getSettings().getViewType() == Settings::ViewType::POINT_CLOUD_DISTANCE_AMPLITUDE){

        widgetData->hide();
        widgetPointCloud->show();
        emit showData(pData, dataHeader);

    }else{
        widgetData->show();
        widgetPointCloud->hide();

        if(context.getSettings().log.isRecord()){

            if(context.getSettings().log.isDispalyRecord())
                widgetData->showData(context,pData, dataHeader);

            widgetData->logData(pData, length);

        }else{
            widgetData->showData(context,pData, dataHeader);
        }


    }

}

void MainWindow::onStateChange()
{
    QString str;        

    switch(context.getApplicationState())
    {
    case TypeApplicationState::STATE_UNCONNECTED:
        labelStatus->setStyleSheet("QLabel { color : orange; }");
        labelStatus->setText("Disconnected from " + context.getSettings().getDestIp());
        break;
    case TypeApplicationState::STATE_CONNECTED:
        labelStatus->setStyleSheet("QLabel { color : green; }");
        labelStatus->setText("Connected to" + context.getSettings().getDestIp());
        break;

    case TypeApplicationState::STATE_STREAM:

        if(context.getSettings().log.isRecord()){
            storage.refresh();
            str.sprintf( "Recording: available size: %d MB", static_cast<int>(storage.bytesAvailable()/1000/1000));
        }else{
            str.sprintf( "Streaming");
        }

        labelStatus->setStyleSheet("QLabel { color : green; }");        
        labelStatus->setText(str);
        break;
    case TypeApplicationState::STATE_CALIBRATION:
        labelStatus->setStyleSheet("QLabel { color : green; }");
        labelStatus->setText("Calibrating");
        break;
    case TypeApplicationState::STATE_CALIBRATION_SYSTEM_OFFSET:
        labelStatus->setStyleSheet("QLabel { color : green; }");
        labelStatus->setText("System Offset");
        break;
    default:
        labelStatus->setText("");
        break;
    }
}

void MainWindow::onError(const uint16_t errorNumber)
{
    labelStatus->setStyleSheet("QLabel { color : red; }");
    labelStatus->setText("eror " + QString::number(errorNumber));
}

void MainWindow::onPushButtonLogoClicked()
{
    QDesktopServices::openUrl(QUrl("http://www.joysonsafety.com", QUrl::TolerantMode));
}

void MainWindow::on_actionView_triggered()
{
    disconnect(widgetPlay, SIGNAL(indexViewChanged(int)),   widgetImage, SLOT(indexViewChanged(int)));
    ui->stackedView->setCurrentIndex(0);    
}


void MainWindow::on_actionPlay_triggered()
{
    connect(widgetPlay, SIGNAL(indexViewChanged(int)),   widgetImage, SLOT(indexViewChanged(int)));
    ui->stackedView->setCurrentIndex(1);
}

void MainWindow::on_actionSettings_triggered()
{
    ui->stackedView->setCurrentIndex(2);
}

void MainWindow::on_actionCalibration_triggered()
{
    ui->stackedView->setCurrentIndex(3);
}

void MainWindow::on_actionTools_triggered()
{
    ui->stackedView->setCurrentIndex(4);
}

void MainWindow::on_actionSave_Load_triggered()
{
    ui->stackedView->setCurrentIndex(5);
}

void MainWindow::receivedFirmwareRelease(int major, int minor)
{
    context.getSettings().setFirmwareRelease(major, minor);
}

void MainWindow::receivedChipInfo(const int waferID, const int ChipID)
{
    context.getSettings().setChipInfo(waferID, ChipID);
}


