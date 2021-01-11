/********************************************************************************
** Form generated from reading UI file 'widget_image.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_IMAGE_H
#define UI_WIDGET_IMAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetImage
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_5;
    QComboBox *comboBoxStreamConnectionType;
    QCheckBox *cbDataToDifferentIP;
    QLabel *label_10;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label_9;
    QComboBox *comboBoxImageType;
    QCheckBox *cbTimeScope;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLabel *label_4;
    QCheckBox *cbPixelInfo;
    QComboBox *comboBoxCameraNumber;
    QSpacerItem *horizontalSpacer_6;
    QCheckBox *cbRecord;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButtonStream;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_9;
    QLabel *label_7;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButtonSingle;
    QCheckBox *cbPixelScope;
    QLabel *label_8;
    QLabel *label_3;
    QCheckBox *cbDisplay;
    QLabel *labelTitle;
    QWidget *widget_3;
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QGroupBox *gbBase;
    QGroupBox *gbFilters;
    QGroupBox *gbModulation;
    QGroupBox *gbAlgorithms;
    QGroupBox *gbRoi;
    QGroupBox *gbBinning;

    void setupUi(QWidget *WidgetImage)
    {
        if (WidgetImage->objectName().isEmpty())
            WidgetImage->setObjectName(QString::fromUtf8("WidgetImage"));
        WidgetImage->resize(715, 426);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(WidgetImage->sizePolicy().hasHeightForWidth());
        WidgetImage->setSizePolicy(sizePolicy);
        WidgetImage->setMinimumSize(QSize(550, 322));
        WidgetImage->setSizeIncrement(QSize(0, 0));
        QFont font;
        font.setPointSize(10);
        WidgetImage->setFont(font);
        gridLayout_3 = new QGridLayout(WidgetImage);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(-1, 0, -1, -1);
        comboBoxStreamConnectionType = new QComboBox(WidgetImage);
        comboBoxStreamConnectionType->addItem(QString());
        comboBoxStreamConnectionType->addItem(QString());
        comboBoxStreamConnectionType->setObjectName(QString::fromUtf8("comboBoxStreamConnectionType"));
        comboBoxStreamConnectionType->setMinimumSize(QSize(75, 0));
        QFont font1;
        font1.setPointSize(8);
        comboBoxStreamConnectionType->setFont(font1);

        gridLayout_5->addWidget(comboBoxStreamConnectionType, 1, 8, 1, 1);

        cbDataToDifferentIP = new QCheckBox(WidgetImage);
        cbDataToDifferentIP->setObjectName(QString::fromUtf8("cbDataToDifferentIP"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cbDataToDifferentIP->sizePolicy().hasHeightForWidth());
        cbDataToDifferentIP->setSizePolicy(sizePolicy1);
        cbDataToDifferentIP->setMinimumSize(QSize(100, 0));
        cbDataToDifferentIP->setFont(font1);

        gridLayout_5->addWidget(cbDataToDifferentIP, 2, 5, 1, 1);

        label_10 = new QLabel(WidgetImage);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_10, 2, 6, 1, 1);

        label_5 = new QLabel(WidgetImage);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_5, 2, 2, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_10, 0, 0, 1, 1);

        label_9 = new QLabel(WidgetImage);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy3);
        label_9->setMinimumSize(QSize(70, 0));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        label_9->setFont(font2);
        label_9->setLayoutDirection(Qt::LeftToRight);
        label_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_9, 0, 5, 1, 1);

        comboBoxImageType = new QComboBox(WidgetImage);
        comboBoxImageType->addItem(QString());
        comboBoxImageType->addItem(QString());
        comboBoxImageType->addItem(QString());
        comboBoxImageType->addItem(QString());
        comboBoxImageType->addItem(QString());
        comboBoxImageType->addItem(QString());
        comboBoxImageType->setObjectName(QString::fromUtf8("comboBoxImageType"));
        comboBoxImageType->setEnabled(true);
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(comboBoxImageType->sizePolicy().hasHeightForWidth());
        comboBoxImageType->setSizePolicy(sizePolicy4);
        comboBoxImageType->setMinimumSize(QSize(150, 0));
        QFont font3;
        font3.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font3.setPointSize(8);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setWeight(50);
        comboBoxImageType->setFont(font3);
        comboBoxImageType->setContextMenuPolicy(Qt::DefaultContextMenu);
        comboBoxImageType->setStyleSheet(QString::fromUtf8(""));
        comboBoxImageType->setMaxCount(10);
        comboBoxImageType->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        comboBoxImageType->setIconSize(QSize(16, 16));

        gridLayout_5->addWidget(comboBoxImageType, 0, 7, 1, 2);

        cbTimeScope = new QCheckBox(WidgetImage);
        cbTimeScope->setObjectName(QString::fromUtf8("cbTimeScope"));
        sizePolicy4.setHeightForWidth(cbTimeScope->sizePolicy().hasHeightForWidth());
        cbTimeScope->setSizePolicy(sizePolicy4);
        cbTimeScope->setMinimumSize(QSize(90, 0));
        cbTimeScope->setFont(font1);

        gridLayout_5->addWidget(cbTimeScope, 1, 5, 1, 1);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer, 0, 9, 1, 1);

        label = new QLabel(WidgetImage);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy5);
        label->setMinimumSize(QSize(90, 0));
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8(""));
        label->setFrameShape(QFrame::NoFrame);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label, 0, 1, 1, 1);

        label_4 = new QLabel(WidgetImage);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_4, 1, 2, 1, 1);

        cbPixelInfo = new QCheckBox(WidgetImage);
        cbPixelInfo->setObjectName(QString::fromUtf8("cbPixelInfo"));
        sizePolicy4.setHeightForWidth(cbPixelInfo->sizePolicy().hasHeightForWidth());
        cbPixelInfo->setSizePolicy(sizePolicy4);
        cbPixelInfo->setMinimumSize(QSize(120, 0));
        cbPixelInfo->setFont(font);

        gridLayout_5->addWidget(cbPixelInfo, 1, 7, 1, 1);

        comboBoxCameraNumber = new QComboBox(WidgetImage);
        comboBoxCameraNumber->addItem(QString());
        comboBoxCameraNumber->addItem(QString());
        comboBoxCameraNumber->addItem(QString());
        comboBoxCameraNumber->addItem(QString());
        comboBoxCameraNumber->setObjectName(QString::fromUtf8("comboBoxCameraNumber"));
        sizePolicy2.setHeightForWidth(comboBoxCameraNumber->sizePolicy().hasHeightForWidth());
        comboBoxCameraNumber->setSizePolicy(sizePolicy2);
        comboBoxCameraNumber->setMinimumSize(QSize(80, 0));
        QFont font4;
        font4.setPointSize(8);
        font4.setKerning(true);
        comboBoxCameraNumber->setFont(font4);
        comboBoxCameraNumber->setStyleSheet(QString::fromUtf8(""));
        comboBoxCameraNumber->setMaxCount(10);
        comboBoxCameraNumber->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_5->addWidget(comboBoxCameraNumber, 0, 3, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_6, 2, 0, 1, 1);

        cbRecord = new QCheckBox(WidgetImage);
        cbRecord->setObjectName(QString::fromUtf8("cbRecord"));
        cbRecord->setFont(font1);

        gridLayout_5->addWidget(cbRecord, 1, 3, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        pushButtonStream = new QPushButton(WidgetImage);
        pushButtonStream->setObjectName(QString::fromUtf8("pushButtonStream"));
        sizePolicy4.setHeightForWidth(pushButtonStream->sizePolicy().hasHeightForWidth());
        pushButtonStream->setSizePolicy(sizePolicy4);
        pushButtonStream->setMinimumSize(QSize(0, 0));
        pushButtonStream->setFont(font1);
        pushButtonStream->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(84, 141, 105);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/images/icons/videoStart.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonStream->setIcon(icon);
        pushButtonStream->setIconSize(QSize(16, 16));

        gridLayout_5->addWidget(pushButtonStream, 2, 1, 1, 1);

        label_6 = new QLabel(WidgetImage);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);

        gridLayout_5->addWidget(label_6, 1, 4, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_7, 0, 4, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_9, 2, 9, 1, 1);

        label_7 = new QLabel(WidgetImage);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);

        gridLayout_5->addWidget(label_7, 2, 4, 1, 1);

        label_2 = new QLabel(WidgetImage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font5;
        font5.setBold(true);
        font5.setWeight(75);
        label_2->setFont(font5);

        gridLayout_5->addWidget(label_2, 0, 2, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_8, 1, 9, 1, 1);

        pushButtonSingle = new QPushButton(WidgetImage);
        pushButtonSingle->setObjectName(QString::fromUtf8("pushButtonSingle"));
        sizePolicy4.setHeightForWidth(pushButtonSingle->sizePolicy().hasHeightForWidth());
        pushButtonSingle->setSizePolicy(sizePolicy4);
        pushButtonSingle->setMinimumSize(QSize(0, 0));
        pushButtonSingle->setFont(font1);
        pushButtonSingle->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(84, 141, 105);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/images/icons/picture.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSingle->setIcon(icon1);
        pushButtonSingle->setIconSize(QSize(16, 16));

        gridLayout_5->addWidget(pushButtonSingle, 1, 1, 1, 1);

        cbPixelScope = new QCheckBox(WidgetImage);
        cbPixelScope->setObjectName(QString::fromUtf8("cbPixelScope"));
        sizePolicy4.setHeightForWidth(cbPixelScope->sizePolicy().hasHeightForWidth());
        cbPixelScope->setSizePolicy(sizePolicy4);
        cbPixelScope->setMinimumSize(QSize(120, 0));
        cbPixelScope->setFont(font1);

        gridLayout_5->addWidget(cbPixelScope, 2, 7, 1, 1);

        label_8 = new QLabel(WidgetImage);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy6);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_8, 1, 6, 1, 1);

        label_3 = new QLabel(WidgetImage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);

        gridLayout_5->addWidget(label_3, 0, 6, 1, 1);

        cbDisplay = new QCheckBox(WidgetImage);
        cbDisplay->setObjectName(QString::fromUtf8("cbDisplay"));
        cbDisplay->setMinimumSize(QSize(110, 0));
        cbDisplay->setFont(font1);

        gridLayout_5->addWidget(cbDisplay, 2, 3, 1, 1);


        gridLayout_3->addLayout(gridLayout_5, 1, 0, 1, 1);

        labelTitle = new QLabel(WidgetImage);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Segoe UI Black"));
        font6.setBold(true);
        font6.setWeight(75);
        labelTitle->setFont(font6);
        labelTitle->setStyleSheet(QString::fromUtf8("padding:10px;\n"
"/*background-color:rgb(66, 138, 200);*/\n"
"/*background-color:rgb(76, 55, 108);*/\n"
"background-color:rgb(0, 0, 0);\n"
"color:rgb(255,255,255);\n"
""));
        labelTitle->setFrameShape(QFrame::NoFrame);
        labelTitle->setLineWidth(1);
        labelTitle->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(labelTitle, 0, 0, 1, 1);

        widget_3 = new QWidget(WidgetImage);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        sizePolicy.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy);
        widget_3->setStyleSheet(QString::fromUtf8("background-color:rgb(250, 250, 250);"));
        gridLayout_2 = new QGridLayout(widget_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(widget_3);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        sizePolicy4.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy4);
        scrollArea->setToolTipDuration(0);
        scrollArea->setStyleSheet(QString::fromUtf8(""));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setLineWidth(1);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 715, 295));
        scrollAreaWidgetContents->setAutoFillBackground(false);
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(5);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gbBase = new QGroupBox(scrollAreaWidgetContents);
        gbBase->setObjectName(QString::fromUtf8("gbBase"));
        sizePolicy.setHeightForWidth(gbBase->sizePolicy().hasHeightForWidth());
        gbBase->setSizePolicy(sizePolicy);
        gbBase->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"	background-color:rgb(217, 219, 218);\n"
"}"));

        gridLayout->addWidget(gbBase, 0, 0, 1, 1);

        gbFilters = new QGroupBox(scrollAreaWidgetContents);
        gbFilters->setObjectName(QString::fromUtf8("gbFilters"));
        sizePolicy.setHeightForWidth(gbFilters->sizePolicy().hasHeightForWidth());
        gbFilters->setSizePolicy(sizePolicy);

        gridLayout->addWidget(gbFilters, 1, 0, 1, 1);

        gbModulation = new QGroupBox(scrollAreaWidgetContents);
        gbModulation->setObjectName(QString::fromUtf8("gbModulation"));
        sizePolicy.setHeightForWidth(gbModulation->sizePolicy().hasHeightForWidth());
        gbModulation->setSizePolicy(sizePolicy);
        gbModulation->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"	background-color:rgb(217, 219, 218);\n"
"}"));

        gridLayout->addWidget(gbModulation, 2, 0, 1, 1);

        gbAlgorithms = new QGroupBox(scrollAreaWidgetContents);
        gbAlgorithms->setObjectName(QString::fromUtf8("gbAlgorithms"));
        sizePolicy.setHeightForWidth(gbAlgorithms->sizePolicy().hasHeightForWidth());
        gbAlgorithms->setSizePolicy(sizePolicy);
        gbAlgorithms->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(gbAlgorithms, 3, 0, 1, 1);

        gbRoi = new QGroupBox(scrollAreaWidgetContents);
        gbRoi->setObjectName(QString::fromUtf8("gbRoi"));
        sizePolicy.setHeightForWidth(gbRoi->sizePolicy().hasHeightForWidth());
        gbRoi->setSizePolicy(sizePolicy);
        gbRoi->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"	background-color:rgb(217, 219, 218);\n"
"}"));

        gridLayout->addWidget(gbRoi, 4, 0, 1, 1);

        gbBinning = new QGroupBox(scrollAreaWidgetContents);
        gbBinning->setObjectName(QString::fromUtf8("gbBinning"));
        sizePolicy.setHeightForWidth(gbBinning->sizePolicy().hasHeightForWidth());
        gbBinning->setSizePolicy(sizePolicy);
        gbBinning->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(gbBinning, 5, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 0, 0, 1, 1);


        gridLayout_3->addWidget(widget_3, 2, 0, 1, 1);


        retranslateUi(WidgetImage);

        comboBoxImageType->setCurrentIndex(0);
        comboBoxCameraNumber->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(WidgetImage);
    } // setupUi

    void retranslateUi(QWidget *WidgetImage)
    {
        WidgetImage->setWindowTitle(QCoreApplication::translate("WidgetImage", "Form", nullptr));
        comboBoxStreamConnectionType->setItemText(0, QCoreApplication::translate("WidgetImage", "TCP/IP", nullptr));
        comboBoxStreamConnectionType->setItemText(1, QCoreApplication::translate("WidgetImage", "UDP/IP", nullptr));

#if QT_CONFIG(tooltip)
        comboBoxStreamConnectionType->setToolTip(QCoreApplication::translate("WidgetImage", "<html><head/><body><p>Select the Protocol to use for Streaming Data</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        cbDataToDifferentIP->setToolTip(QCoreApplication::translate("WidgetImage", "<html><head/><body><p>Use different data computer with different IP address</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbDataToDifferentIP->setText(QCoreApplication::translate("WidgetImage", "Data to diff IP", nullptr));
        label_10->setText(QCoreApplication::translate("WidgetImage", "||", nullptr));
        label_5->setText(QCoreApplication::translate("WidgetImage", "     ||", nullptr));
#if QT_CONFIG(tooltip)
        label_9->setToolTip(QCoreApplication::translate("WidgetImage", "<html><head/><body><p>Select the Measurement type</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_9->setText(QCoreApplication::translate("WidgetImage", "IMAGE TYPE", nullptr));
        comboBoxImageType->setItemText(0, QCoreApplication::translate("WidgetImage", "Distance", nullptr));
        comboBoxImageType->setItemText(1, QCoreApplication::translate("WidgetImage", "Distance & Amplitude", nullptr));
        comboBoxImageType->setItemText(2, QCoreApplication::translate("WidgetImage", "Grayscale", nullptr));
        comboBoxImageType->setItemText(3, QCoreApplication::translate("WidgetImage", "Point Cloud D", nullptr));
        comboBoxImageType->setItemText(4, QCoreApplication::translate("WidgetImage", "Point Cloud D&A", nullptr));
        comboBoxImageType->setItemText(5, QCoreApplication::translate("WidgetImage", "Movement Detection", nullptr));

#if QT_CONFIG(tooltip)
        comboBoxImageType->setToolTip(QCoreApplication::translate("WidgetImage", "<html><head/><body><p>Streaming and visualisation type</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        cbTimeScope->setToolTip(QCoreApplication::translate("WidgetImage", "<html><head/><body><p>On /Off time scope for temporal data visualisation</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbTimeScope->setText(QCoreApplication::translate("WidgetImage", "Time Scope", nullptr));
#if QT_CONFIG(tooltip)
        label->setToolTip(QCoreApplication::translate("WidgetImage", "<html><head/><body><p>Select the Camera to Stream data from</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label->setText(QCoreApplication::translate("WidgetImage", "CAM SELECT", nullptr));
        label_4->setText(QCoreApplication::translate("WidgetImage", "     ||", nullptr));
#if QT_CONFIG(tooltip)
        cbPixelInfo->setToolTip(QCoreApplication::translate("WidgetImage", "<html><head/><body><p>On /Off one pixel statistical information</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbPixelInfo->setText(QCoreApplication::translate("WidgetImage", "Pixel Info    ", nullptr));
        comboBoxCameraNumber->setItemText(0, QCoreApplication::translate("WidgetImage", "Camera-1", nullptr));
        comboBoxCameraNumber->setItemText(1, QCoreApplication::translate("WidgetImage", "Camera-2", nullptr));
        comboBoxCameraNumber->setItemText(2, QCoreApplication::translate("WidgetImage", "Camera-3", nullptr));
        comboBoxCameraNumber->setItemText(3, QCoreApplication::translate("WidgetImage", "Camera-4", nullptr));

#if QT_CONFIG(tooltip)
        comboBoxCameraNumber->setToolTip(QCoreApplication::translate("WidgetImage", "<html><head/><body><p>Camera Selection</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        cbRecord->setToolTip(QCoreApplication::translate("WidgetImage", "<html><head/><body><p>Activate recording</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbRecord->setText(QCoreApplication::translate("WidgetImage", "Record", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonStream->setToolTip(QCoreApplication::translate("WidgetImage", "<html><head/><body><p><span style=\" font-size:10pt;\">Switch on/off video streaming</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButtonStream->setText(QCoreApplication::translate("WidgetImage", "Start", nullptr));
        label_6->setText(QCoreApplication::translate("WidgetImage", " ||", nullptr));
        label_7->setText(QCoreApplication::translate("WidgetImage", " ||", nullptr));
        label_2->setText(QCoreApplication::translate("WidgetImage", ">>>", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonSingle->setToolTip(QCoreApplication::translate("WidgetImage", "<html><head/><body><p><span style=\" font-size:10pt;\">Capture one image</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButtonSingle->setText(QCoreApplication::translate("WidgetImage", "Picture", nullptr));
#if QT_CONFIG(tooltip)
        cbPixelScope->setToolTip(QCoreApplication::translate("WidgetImage", "<html><head/><body><p>On /Off pixel scope for spatial data visualisation</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbPixelScope->setText(QCoreApplication::translate("WidgetImage", "Pixel Scope  ||", nullptr));
        label_8->setText(QCoreApplication::translate("WidgetImage", "||", nullptr));
        label_3->setText(QCoreApplication::translate("WidgetImage", ">>>", nullptr));
#if QT_CONFIG(tooltip)
        cbDisplay->setToolTip(QCoreApplication::translate("WidgetImage", "<html><head/><body><p>On / Off visualisation during recording</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbDisplay->setText(QCoreApplication::translate("WidgetImage", "Don't display", nullptr));
        labelTitle->setText(QCoreApplication::translate("WidgetImage", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; font-weight:600;\">VIEW</span></p></body></html>", nullptr));
        gbBase->setTitle(QString());
        gbFilters->setTitle(QString());
        gbModulation->setTitle(QString());
        gbAlgorithms->setTitle(QString());
        gbRoi->setTitle(QString());
        gbBinning->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class WidgetImage: public Ui_WidgetImage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_IMAGE_H
