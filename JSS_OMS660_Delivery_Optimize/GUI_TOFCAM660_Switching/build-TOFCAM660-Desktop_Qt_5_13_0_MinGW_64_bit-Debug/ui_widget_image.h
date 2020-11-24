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
    QLabel *labelTitle;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QWidget *widget_3;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_4;
    QGroupBox *gbRoi;
    QGroupBox *gbFilters;
    QGroupBox *gbBase;
    QGroupBox *gbModulation;
    QGroupBox *gbBinning;
    QGridLayout *gridLayout_5;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_2;
    QLabel *label_7;
    QLabel *label;
    QCheckBox *cbDataToDifferentIP;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *pushButtonStream;
    QComboBox *comboBoxImageType;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButtonSingle;
    QCheckBox *cbRecord;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_9;
    QLabel *label_5;
    QCheckBox *cbDisplay;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_12;
    QLabel *label_4;
    QCheckBox *cbTimeScope;
    QComboBox *comboBoxCameraNumber;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *cbPixelInfo;
    QCheckBox *cbPixelScope;
    QComboBox *comboBoxStreamConnectionType;
    QLabel *label_8;
    QLabel *label_10;

    void setupUi(QWidget *WidgetImage)
    {
        if (WidgetImage->objectName().isEmpty())
            WidgetImage->setObjectName(QString::fromUtf8("WidgetImage"));
        WidgetImage->resize(572, 322);
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
        labelTitle = new QLabel(WidgetImage);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        labelTitle->setStyleSheet(QString::fromUtf8("padding:10px;\n"
"/*background-color:rgb(66, 138, 200);*/\n"
"/*background-color:rgb(76, 55, 108);*/\n"
"background-color:rgb(51, 51, 51);\n"
"color:rgb(255,255,255);\n"
""));
        labelTitle->setFrameShape(QFrame::NoFrame);
        labelTitle->setLineWidth(1);

        gridLayout_3->addWidget(labelTitle, 0, 0, 1, 1);

        widget_2 = new QWidget(WidgetImage);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setStyleSheet(QString::fromUtf8("background-color:rgb(237, 239, 238);"));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, 0, -1, 0);

        gridLayout_3->addWidget(widget_2, 1, 0, 1, 1);

        widget_3 = new QWidget(WidgetImage);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        sizePolicy.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy);
        widget_3->setStyleSheet(QString::fromUtf8("background-color:rgb(250, 250, 250);"));
        gridLayout = new QGridLayout(widget_3);
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(widget_3);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy1);
        scrollArea->setStyleSheet(QString::fromUtf8(""));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setLineWidth(1);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 572, 189));
        scrollAreaWidgetContents->setAutoFillBackground(false);
        gridLayout_4 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        gbRoi = new QGroupBox(scrollAreaWidgetContents);
        gbRoi->setObjectName(QString::fromUtf8("gbRoi"));
        sizePolicy.setHeightForWidth(gbRoi->sizePolicy().hasHeightForWidth());
        gbRoi->setSizePolicy(sizePolicy);
        gbRoi->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"	background-color:rgb(217, 219, 218);\n"
"}"));

        gridLayout_4->addWidget(gbRoi, 4, 0, 1, 1);

        gbFilters = new QGroupBox(scrollAreaWidgetContents);
        gbFilters->setObjectName(QString::fromUtf8("gbFilters"));
        sizePolicy.setHeightForWidth(gbFilters->sizePolicy().hasHeightForWidth());
        gbFilters->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(gbFilters, 1, 0, 1, 1);

        gbBase = new QGroupBox(scrollAreaWidgetContents);
        gbBase->setObjectName(QString::fromUtf8("gbBase"));
        sizePolicy.setHeightForWidth(gbBase->sizePolicy().hasHeightForWidth());
        gbBase->setSizePolicy(sizePolicy);
        gbBase->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"	background-color:rgb(217, 219, 218);\n"
"}"));

        gridLayout_4->addWidget(gbBase, 0, 0, 1, 1);

        gbModulation = new QGroupBox(scrollAreaWidgetContents);
        gbModulation->setObjectName(QString::fromUtf8("gbModulation"));
        sizePolicy.setHeightForWidth(gbModulation->sizePolicy().hasHeightForWidth());
        gbModulation->setSizePolicy(sizePolicy);
        gbModulation->setStyleSheet(QString::fromUtf8("QGroupBox{\n"
"	background-color:rgb(217, 219, 218);\n"
"}"));

        gridLayout_4->addWidget(gbModulation, 2, 0, 1, 1);

        gbBinning = new QGroupBox(scrollAreaWidgetContents);
        gbBinning->setObjectName(QString::fromUtf8("gbBinning"));
        sizePolicy.setHeightForWidth(gbBinning->sizePolicy().hasHeightForWidth());
        gbBinning->setSizePolicy(sizePolicy);
        gbBinning->setStyleSheet(QString::fromUtf8(""));

        gridLayout_4->addWidget(gbBinning, 3, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 5, 1, 1, 1);


        gridLayout_3->addWidget(widget_3, 3, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_8, 1, 10, 1, 1);

        label_2 = new QLabel(WidgetImage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);

        gridLayout_5->addWidget(label_2, 0, 3, 1, 1);

        label_7 = new QLabel(WidgetImage);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);

        gridLayout_5->addWidget(label_7, 2, 5, 1, 1);

        label = new QLabel(WidgetImage);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);
        label->setMinimumSize(QSize(90, 0));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8(""));
        label->setFrameShape(QFrame::NoFrame);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label, 0, 2, 1, 1);

        cbDataToDifferentIP = new QCheckBox(WidgetImage);
        cbDataToDifferentIP->setObjectName(QString::fromUtf8("cbDataToDifferentIP"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(cbDataToDifferentIP->sizePolicy().hasHeightForWidth());
        cbDataToDifferentIP->setSizePolicy(sizePolicy4);
        cbDataToDifferentIP->setMinimumSize(QSize(100, 0));
        QFont font3;
        font3.setPointSize(8);
        cbDataToDifferentIP->setFont(font3);

        gridLayout_5->addWidget(cbDataToDifferentIP, 2, 6, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_6, 2, 0, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_10, 0, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        label_3 = new QLabel(WidgetImage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);

        gridLayout_5->addWidget(label_3, 0, 7, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer, 0, 10, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_11, 1, 1, 1, 1);

        pushButtonStream = new QPushButton(WidgetImage);
        pushButtonStream->setObjectName(QString::fromUtf8("pushButtonStream"));
        sizePolicy1.setHeightForWidth(pushButtonStream->sizePolicy().hasHeightForWidth());
        pushButtonStream->setSizePolicy(sizePolicy1);
        pushButtonStream->setMinimumSize(QSize(0, 0));
        pushButtonStream->setFont(font3);
        pushButtonStream->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(84, 141, 105);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/images/icons/videoStart.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonStream->setIcon(icon);
        pushButtonStream->setIconSize(QSize(16, 16));

        gridLayout_5->addWidget(pushButtonStream, 2, 2, 1, 1);

        comboBoxImageType = new QComboBox(WidgetImage);
        comboBoxImageType->addItem(QString());
        comboBoxImageType->addItem(QString());
        comboBoxImageType->addItem(QString());
        comboBoxImageType->addItem(QString());
        comboBoxImageType->addItem(QString());
        comboBoxImageType->setObjectName(QString::fromUtf8("comboBoxImageType"));
        comboBoxImageType->setEnabled(true);
        sizePolicy1.setHeightForWidth(comboBoxImageType->sizePolicy().hasHeightForWidth());
        comboBoxImageType->setSizePolicy(sizePolicy1);
        comboBoxImageType->setMinimumSize(QSize(150, 0));
        QFont font4;
        font4.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font4.setPointSize(8);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(50);
        comboBoxImageType->setFont(font4);
        comboBoxImageType->setContextMenuPolicy(Qt::DefaultContextMenu);
        comboBoxImageType->setStyleSheet(QString::fromUtf8(""));
        comboBoxImageType->setMaxCount(10);
        comboBoxImageType->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        comboBoxImageType->setIconSize(QSize(16, 16));

        gridLayout_5->addWidget(comboBoxImageType, 0, 8, 1, 2);

        horizontalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_7, 0, 5, 1, 1);

        pushButtonSingle = new QPushButton(WidgetImage);
        pushButtonSingle->setObjectName(QString::fromUtf8("pushButtonSingle"));
        sizePolicy1.setHeightForWidth(pushButtonSingle->sizePolicy().hasHeightForWidth());
        pushButtonSingle->setSizePolicy(sizePolicy1);
        pushButtonSingle->setMinimumSize(QSize(0, 0));
        pushButtonSingle->setFont(font3);
        pushButtonSingle->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(84, 141, 105);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/images/icons/picture.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSingle->setIcon(icon1);
        pushButtonSingle->setIconSize(QSize(16, 16));

        gridLayout_5->addWidget(pushButtonSingle, 1, 2, 1, 1);

        cbRecord = new QCheckBox(WidgetImage);
        cbRecord->setObjectName(QString::fromUtf8("cbRecord"));
        cbRecord->setFont(font3);

        gridLayout_5->addWidget(cbRecord, 1, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_3, 0, 11, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_9, 2, 10, 1, 1);

        label_5 = new QLabel(WidgetImage);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_5, 2, 3, 1, 1);

        cbDisplay = new QCheckBox(WidgetImage);
        cbDisplay->setObjectName(QString::fromUtf8("cbDisplay"));
        cbDisplay->setMinimumSize(QSize(110, 0));
        cbDisplay->setFont(font3);

        gridLayout_5->addWidget(cbDisplay, 2, 4, 1, 1);

        label_9 = new QLabel(WidgetImage);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy5);
        label_9->setMinimumSize(QSize(70, 0));
        label_9->setFont(font2);
        label_9->setLayoutDirection(Qt::LeftToRight);
        label_9->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_9, 0, 6, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_12, 2, 1, 1, 1);

        label_4 = new QLabel(WidgetImage);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_4, 1, 3, 1, 1);

        cbTimeScope = new QCheckBox(WidgetImage);
        cbTimeScope->setObjectName(QString::fromUtf8("cbTimeScope"));
        sizePolicy1.setHeightForWidth(cbTimeScope->sizePolicy().hasHeightForWidth());
        cbTimeScope->setSizePolicy(sizePolicy1);
        cbTimeScope->setMinimumSize(QSize(90, 0));
        cbTimeScope->setFont(font3);

        gridLayout_5->addWidget(cbTimeScope, 1, 6, 1, 1);

        comboBoxCameraNumber = new QComboBox(WidgetImage);
        comboBoxCameraNumber->addItem(QString());
        comboBoxCameraNumber->addItem(QString());
        comboBoxCameraNumber->addItem(QString());
        comboBoxCameraNumber->addItem(QString());
        comboBoxCameraNumber->setObjectName(QString::fromUtf8("comboBoxCameraNumber"));
        sizePolicy2.setHeightForWidth(comboBoxCameraNumber->sizePolicy().hasHeightForWidth());
        comboBoxCameraNumber->setSizePolicy(sizePolicy2);
        comboBoxCameraNumber->setMinimumSize(QSize(80, 0));
        QFont font5;
        font5.setPointSize(8);
        font5.setKerning(true);
        comboBoxCameraNumber->setFont(font5);
        comboBoxCameraNumber->setStyleSheet(QString::fromUtf8(""));
        comboBoxCameraNumber->setMaxCount(10);
        comboBoxCameraNumber->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_5->addWidget(comboBoxCameraNumber, 0, 4, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_4, 2, 11, 1, 1);

        label_6 = new QLabel(WidgetImage);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);

        gridLayout_5->addWidget(label_6, 1, 5, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_2, 1, 11, 1, 1);

        cbPixelInfo = new QCheckBox(WidgetImage);
        cbPixelInfo->setObjectName(QString::fromUtf8("cbPixelInfo"));
        sizePolicy1.setHeightForWidth(cbPixelInfo->sizePolicy().hasHeightForWidth());
        cbPixelInfo->setSizePolicy(sizePolicy1);
        cbPixelInfo->setMinimumSize(QSize(120, 0));
        cbPixelInfo->setFont(font);

        gridLayout_5->addWidget(cbPixelInfo, 1, 8, 1, 1);

        cbPixelScope = new QCheckBox(WidgetImage);
        cbPixelScope->setObjectName(QString::fromUtf8("cbPixelScope"));
        sizePolicy1.setHeightForWidth(cbPixelScope->sizePolicy().hasHeightForWidth());
        cbPixelScope->setSizePolicy(sizePolicy1);
        cbPixelScope->setMinimumSize(QSize(120, 0));
        cbPixelScope->setFont(font3);

        gridLayout_5->addWidget(cbPixelScope, 2, 8, 1, 1);

        comboBoxStreamConnectionType = new QComboBox(WidgetImage);
        comboBoxStreamConnectionType->addItem(QString());
        comboBoxStreamConnectionType->addItem(QString());
        comboBoxStreamConnectionType->setObjectName(QString::fromUtf8("comboBoxStreamConnectionType"));
        comboBoxStreamConnectionType->setMinimumSize(QSize(75, 0));
        comboBoxStreamConnectionType->setFont(font3);

        gridLayout_5->addWidget(comboBoxStreamConnectionType, 1, 9, 1, 1);

        label_8 = new QLabel(WidgetImage);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy6);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_8, 1, 7, 1, 1);

        label_10 = new QLabel(WidgetImage);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(label_10, 2, 7, 1, 1);


        gridLayout_3->addLayout(gridLayout_5, 2, 0, 1, 1);


        retranslateUi(WidgetImage);

        comboBoxImageType->setCurrentIndex(0);
        comboBoxCameraNumber->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(WidgetImage);
    } // setupUi

    void retranslateUi(QWidget *WidgetImage)
    {
        WidgetImage->setWindowTitle(QCoreApplication::translate("WidgetImage", "Form", nullptr));
        labelTitle->setText(QCoreApplication::translate("WidgetImage", "VIEW", nullptr));
        gbRoi->setTitle(QString());
        gbFilters->setTitle(QString());
        gbBase->setTitle(QString());
        gbModulation->setTitle(QString());
        gbBinning->setTitle(QString());
        label_2->setText(QCoreApplication::translate("WidgetImage", ">>>", nullptr));
        label_7->setText(QCoreApplication::translate("WidgetImage", " ||", nullptr));
#if QT_CONFIG(tooltip)
        label->setToolTip(QCoreApplication::translate("WidgetImage", "<html><head/><body><p>Select the Camera to Stream data from</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label->setText(QCoreApplication::translate("WidgetImage", "CAM SELECT", nullptr));
#if QT_CONFIG(tooltip)
        cbDataToDifferentIP->setToolTip(QCoreApplication::translate("WidgetImage", "<html><head/><body><p>Use different data computer with different IP address</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbDataToDifferentIP->setText(QCoreApplication::translate("WidgetImage", "Data to diff IP", nullptr));
        label_3->setText(QCoreApplication::translate("WidgetImage", ">>>", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonStream->setToolTip(QCoreApplication::translate("WidgetImage", "<html><head/><body><p><span style=\" font-size:10pt;\">Switch on/off video streaming</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButtonStream->setText(QCoreApplication::translate("WidgetImage", "Start", nullptr));
        comboBoxImageType->setItemText(0, QCoreApplication::translate("WidgetImage", "Distance", nullptr));
        comboBoxImageType->setItemText(1, QCoreApplication::translate("WidgetImage", "Distance & Amplitude", nullptr));
        comboBoxImageType->setItemText(2, QCoreApplication::translate("WidgetImage", "Grayscale", nullptr));
        comboBoxImageType->setItemText(3, QCoreApplication::translate("WidgetImage", "Point Cloud D", nullptr));
        comboBoxImageType->setItemText(4, QCoreApplication::translate("WidgetImage", "Point Cloud D&A", nullptr));

#if QT_CONFIG(tooltip)
        comboBoxImageType->setToolTip(QCoreApplication::translate("WidgetImage", "<html><head/><body><p>Streaming and visualisation type</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        pushButtonSingle->setToolTip(QCoreApplication::translate("WidgetImage", "<html><head/><body><p><span style=\" font-size:10pt;\">Capture one image</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButtonSingle->setText(QCoreApplication::translate("WidgetImage", "Picture", nullptr));
#if QT_CONFIG(tooltip)
        cbRecord->setToolTip(QCoreApplication::translate("WidgetImage", "<html><head/><body><p>Activate recording</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbRecord->setText(QCoreApplication::translate("WidgetImage", "Record", nullptr));
        label_5->setText(QCoreApplication::translate("WidgetImage", "     ||", nullptr));
#if QT_CONFIG(tooltip)
        cbDisplay->setToolTip(QCoreApplication::translate("WidgetImage", "<html><head/><body><p>On / Off visualisation during recording</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbDisplay->setText(QCoreApplication::translate("WidgetImage", "Don't display", nullptr));
#if QT_CONFIG(tooltip)
        label_9->setToolTip(QCoreApplication::translate("WidgetImage", "<html><head/><body><p>Select the Measurement type</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_9->setText(QCoreApplication::translate("WidgetImage", "IMAGE TYPE", nullptr));
        label_4->setText(QCoreApplication::translate("WidgetImage", "     ||", nullptr));
#if QT_CONFIG(tooltip)
        cbTimeScope->setToolTip(QCoreApplication::translate("WidgetImage", "<html><head/><body><p>On /Off time scope for temporal data visualisation</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbTimeScope->setText(QCoreApplication::translate("WidgetImage", "Time Scope", nullptr));
        comboBoxCameraNumber->setItemText(0, QCoreApplication::translate("WidgetImage", "Camera-1", nullptr));
        comboBoxCameraNumber->setItemText(1, QCoreApplication::translate("WidgetImage", "Camera-2", nullptr));
        comboBoxCameraNumber->setItemText(2, QCoreApplication::translate("WidgetImage", "Camera-3", nullptr));
        comboBoxCameraNumber->setItemText(3, QCoreApplication::translate("WidgetImage", "Camera-4", nullptr));

#if QT_CONFIG(tooltip)
        comboBoxCameraNumber->setToolTip(QCoreApplication::translate("WidgetImage", "<html><head/><body><p>Camera Selection</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_6->setText(QCoreApplication::translate("WidgetImage", " ||", nullptr));
#if QT_CONFIG(tooltip)
        cbPixelInfo->setToolTip(QCoreApplication::translate("WidgetImage", "<html><head/><body><p>On /Off one pixel statistical information</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbPixelInfo->setText(QCoreApplication::translate("WidgetImage", "Pixel Info      ||", nullptr));
#if QT_CONFIG(tooltip)
        cbPixelScope->setToolTip(QCoreApplication::translate("WidgetImage", "<html><head/><body><p>On /Off pixel scope for spatial data visualisation</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbPixelScope->setText(QCoreApplication::translate("WidgetImage", "Pixel Scope  ||", nullptr));
        comboBoxStreamConnectionType->setItemText(0, QCoreApplication::translate("WidgetImage", "TCP/IP", nullptr));
        comboBoxStreamConnectionType->setItemText(1, QCoreApplication::translate("WidgetImage", "UDP/IP", nullptr));

#if QT_CONFIG(tooltip)
        comboBoxStreamConnectionType->setToolTip(QCoreApplication::translate("WidgetImage", "<html><head/><body><p>Select the Protocol to use for Streaming Data</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_8->setText(QCoreApplication::translate("WidgetImage", "||", nullptr));
        label_10->setText(QCoreApplication::translate("WidgetImage", "||", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetImage: public Ui_WidgetImage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_IMAGE_H
