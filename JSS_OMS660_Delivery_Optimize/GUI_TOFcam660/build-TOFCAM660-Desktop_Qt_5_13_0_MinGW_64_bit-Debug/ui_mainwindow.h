/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionView;
    QAction *actionCalibration;
    QAction *actionTools;
    QAction *actionPlay;
    QAction *actionSettings;
    QAction *actionSave_Load;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButtonLogo;
    QStackedWidget *stackedView;
    QLabel *labelProduct;
    QLabel *labelSystemInfo;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(487, 320);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setSizeIncrement(QSize(2, 2));
        MainWindow->setIconSize(QSize(16, 16));
        actionView = new QAction(MainWindow);
        actionView->setObjectName(QString::fromUtf8("actionView"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/toolbar/images/toolbar/view.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/toolbar/images/toolbar/view_hovered.png"), QSize(), QIcon::Active, QIcon::Off);
        actionView->setIcon(icon);
        actionCalibration = new QAction(MainWindow);
        actionCalibration->setObjectName(QString::fromUtf8("actionCalibration"));
        actionCalibration->setEnabled(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/toolbar/images/toolbar/calibration.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QString::fromUtf8(":/toolbar/images/toolbar/calibration_hovered.png"), QSize(), QIcon::Active, QIcon::Off);
        actionCalibration->setIcon(icon1);
        actionCalibration->setVisible(true);
        actionTools = new QAction(MainWindow);
        actionTools->setObjectName(QString::fromUtf8("actionTools"));
        actionTools->setEnabled(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/toolbar/images/toolbar/test.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon2.addFile(QString::fromUtf8(":/toolbar/images/toolbar/test_hovered.png"), QSize(), QIcon::Active, QIcon::Off);
        actionTools->setIcon(icon2);
        actionTools->setVisible(true);
        actionPlay = new QAction(MainWindow);
        actionPlay->setObjectName(QString::fromUtf8("actionPlay"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/toolbar/images/toolbar/command.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon3.addFile(QString::fromUtf8(":/toolbar/images/toolbar/command_hovered.png"), QSize(), QIcon::Active, QIcon::On);
        actionPlay->setIcon(icon3);
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/toolbar/images/toolbar/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSettings->setIcon(icon4);
        actionSave_Load = new QAction(MainWindow);
        actionSave_Load->setObjectName(QString::fromUtf8("actionSave_Load"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/toolbar/images/toolbar/save_load.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_Load->setIcon(icon5);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        centralWidget->setSizeIncrement(QSize(2, 2));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonLogo = new QPushButton(centralWidget);
        pushButtonLogo->setObjectName(QString::fromUtf8("pushButtonLogo"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButtonLogo->sizePolicy().hasHeightForWidth());
        pushButtonLogo->setSizePolicy(sizePolicy2);
        pushButtonLogo->setMinimumSize(QSize(140, 70));
        pushButtonLogo->setMaximumSize(QSize(140, 16777215));
        pushButtonLogo->setStyleSheet(QString::fromUtf8("border:none;\n"
"border-image:url(:/logo/images/logo/logo_tablet.png);\n"
""));

        gridLayout->addWidget(pushButtonLogo, 0, 2, 1, 1);

        stackedView = new QStackedWidget(centralWidget);
        stackedView->setObjectName(QString::fromUtf8("stackedView"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(stackedView->sizePolicy().hasHeightForWidth());
        stackedView->setSizePolicy(sizePolicy3);
        stackedView->setFrameShape(QFrame::NoFrame);

        gridLayout->addWidget(stackedView, 1, 0, 1, 3);

        labelProduct = new QLabel(centralWidget);
        labelProduct->setObjectName(QString::fromUtf8("labelProduct"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(14);
        font.setBold(false);
        font.setWeight(50);
        labelProduct->setFont(font);
        labelProduct->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"/*color:rgb(255, 253, 251);*/\n"
"color:rgb(0,0,0);"));
        labelProduct->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelProduct, 0, 0, 1, 1);

        labelSystemInfo = new QLabel(centralWidget);
        labelSystemInfo->setObjectName(QString::fromUtf8("labelSystemInfo"));
        labelSystemInfo->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"/*color:rgb(255, 253, 251);*/\n"
"color:rgb(0,0,0);"));

        gridLayout->addWidget(labelSystemInfo, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(mainToolBar->sizePolicy().hasHeightForWidth());
        mainToolBar->setSizePolicy(sizePolicy4);
        mainToolBar->setMaximumSize(QSize(16777215, 16777215));
        mainToolBar->setMovable(false);
        mainToolBar->setAllowedAreas(Qt::LeftToolBarArea);
        mainToolBar->setOrientation(Qt::Vertical);
        mainToolBar->setIconSize(QSize(24, 24));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        mainToolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::LeftToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        mainToolBar->addAction(actionView);
        mainToolBar->addAction(actionPlay);
        mainToolBar->addAction(actionSettings);
        mainToolBar->addAction(actionCalibration);
        mainToolBar->addAction(actionTools);
        mainToolBar->addAction(actionSave_Load);

        retranslateUi(MainWindow);

        stackedView->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "TOF>cam 660", nullptr));
        actionView->setText(QCoreApplication::translate("MainWindow", "View", nullptr));
        actionCalibration->setText(QCoreApplication::translate("MainWindow", "Calibration", nullptr));
        actionTools->setText(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        actionPlay->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        actionSettings->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
#if QT_CONFIG(tooltip)
        actionSettings->setToolTip(QCoreApplication::translate("MainWindow", "Settings", nullptr));
#endif // QT_CONFIG(tooltip)
        actionSave_Load->setText(QCoreApplication::translate("MainWindow", "Save/Load", nullptr));
        pushButtonLogo->setText(QString());
        labelProduct->setText(QCoreApplication::translate("MainWindow", "TOF>cam 660", nullptr));
#if QT_CONFIG(tooltip)
        labelSystemInfo->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">GUI - application version</span></p><p><span style=\" font-size:10pt;\">WF - firmware version</span></p><p><span style=\" font-size:10pt;\">WID - wafer identification number</span></p><p><span style=\" font-size:10pt;\">CID - chip identification number</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        labelSystemInfo->setText(QCoreApplication::translate("MainWindow", " GUI \n"
" FW \n"
" WID \n"
" CID  ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
