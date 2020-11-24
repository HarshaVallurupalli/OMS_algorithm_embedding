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
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QLabel *labelTitle;
    QGridLayout *gridLayout_5;
    QSpacerItem *horizontalSpacer_4;
    QCheckBox *cbPixelScope;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *cbDisplay;
    QSpacerItem *horizontalSpacer_6;
    QCheckBox *cbRecord;
    QLabel *label_9;
    QCheckBox *cbDataToDifferentIP;
    QCheckBox *cbPixelInfo;
    QPushButton *pushButtonSingle;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonStream;
    QCheckBox *cbTimeScope;
    QComboBox *comboBoxImageType;
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
        WidgetImage->setMinimumSize(QSize(0, 0));
        WidgetImage->setSizeIncrement(QSize(0, 0));
        QFont font;
        font.setPointSize(10);
        WidgetImage->setFont(font);
        gridLayout_3 = new QGridLayout(WidgetImage);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(WidgetImage);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setStyleSheet(QString::fromUtf8("background-color:rgb(237, 239, 238);"));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, 0, -1, 0);

        gridLayout_3->addWidget(widget_2, 1, 0, 1, 1);

        labelTitle = new QLabel(WidgetImage);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        labelTitle->setStyleSheet(QString::fromUtf8("padding:10px;\n"
"/*background-color:rgb(66, 138, 200);*/\n"
"/*background-color:rgb(76, 55, 108);*/\n"
"background-color:rgb(51, 51, 51);\n"
"color:rgb(255,255,255);\n"
""));

        gridLayout_3->addWidget(labelTitle, 0, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(-1, 0, -1, -1);
        horizontalSpacer_4 = new QSpacerItem(20, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_4, 0, 6, 1, 1);

        cbPixelScope = new QCheckBox(WidgetImage);
        cbPixelScope->setObjectName(QString::fromUtf8("cbPixelScope"));

        gridLayout_5->addWidget(cbPixelScope, 2, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(10, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        cbDisplay = new QCheckBox(WidgetImage);
        cbDisplay->setObjectName(QString::fromUtf8("cbDisplay"));

        gridLayout_5->addWidget(cbDisplay, 1, 3, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_6, 0, 4, 1, 1);

        cbRecord = new QCheckBox(WidgetImage);
        cbRecord->setObjectName(QString::fromUtf8("cbRecord"));

        gridLayout_5->addWidget(cbRecord, 1, 1, 1, 1);

        label_9 = new QLabel(WidgetImage);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(0, 0));
        QFont font1;
        font1.setPointSize(8);
        label_9->setFont(font1);

        gridLayout_5->addWidget(label_9, 0, 5, 1, 1);

        cbDataToDifferentIP = new QCheckBox(WidgetImage);
        cbDataToDifferentIP->setObjectName(QString::fromUtf8("cbDataToDifferentIP"));

        gridLayout_5->addWidget(cbDataToDifferentIP, 2, 7, 1, 1);

        cbPixelInfo = new QCheckBox(WidgetImage);
        cbPixelInfo->setObjectName(QString::fromUtf8("cbPixelInfo"));

        gridLayout_5->addWidget(cbPixelInfo, 2, 1, 1, 1);

        pushButtonSingle = new QPushButton(WidgetImage);
        pushButtonSingle->setObjectName(QString::fromUtf8("pushButtonSingle"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButtonSingle->sizePolicy().hasHeightForWidth());
        pushButtonSingle->setSizePolicy(sizePolicy1);
        pushButtonSingle->setMinimumSize(QSize(0, 0));
        pushButtonSingle->setFont(font1);
        pushButtonSingle->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(84, 141, 105);\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/images/icons/picture.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSingle->setIcon(icon);
        pushButtonSingle->setIconSize(QSize(16, 16));

        gridLayout_5->addWidget(pushButtonSingle, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_3, 0, 8, 1, 1);

        horizontalSpacer = new QSpacerItem(20, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer, 0, 0, 1, 1);

        pushButtonStream = new QPushButton(WidgetImage);
        pushButtonStream->setObjectName(QString::fromUtf8("pushButtonStream"));
        sizePolicy1.setHeightForWidth(pushButtonStream->sizePolicy().hasHeightForWidth());
        pushButtonStream->setSizePolicy(sizePolicy1);
        pushButtonStream->setMinimumSize(QSize(0, 0));
        pushButtonStream->setFont(font1);
        pushButtonStream->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: rgb(84, 141, 105);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/images/icons/videoStart.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonStream->setIcon(icon1);
        pushButtonStream->setIconSize(QSize(16, 16));

        gridLayout_5->addWidget(pushButtonStream, 0, 3, 1, 1);

        cbTimeScope = new QCheckBox(WidgetImage);
        cbTimeScope->setObjectName(QString::fromUtf8("cbTimeScope"));

        gridLayout_5->addWidget(cbTimeScope, 2, 4, 1, 2);

        comboBoxImageType = new QComboBox(WidgetImage);
        comboBoxImageType->addItem(QString());
        comboBoxImageType->addItem(QString());
        comboBoxImageType->addItem(QString());
        comboBoxImageType->addItem(QString());
        comboBoxImageType->addItem(QString());
        comboBoxImageType->addItem(QString());
        comboBoxImageType->setObjectName(QString::fromUtf8("comboBoxImageType"));
        comboBoxImageType->setEnabled(true);
        sizePolicy.setHeightForWidth(comboBoxImageType->sizePolicy().hasHeightForWidth());
        comboBoxImageType->setSizePolicy(sizePolicy);
        comboBoxImageType->setMinimumSize(QSize(180, 0));
        comboBoxImageType->setSizeIncrement(QSize(0, 1));
        QFont font2;
        font2.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font2.setPointSize(18);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        comboBoxImageType->setFont(font2);
        comboBoxImageType->setContextMenuPolicy(Qt::DefaultContextMenu);
        comboBoxImageType->setStyleSheet(QString::fromUtf8(""));
        comboBoxImageType->setMaxCount(10);
        comboBoxImageType->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        comboBoxImageType->setIconSize(QSize(16, 16));

        gridLayout_5->addWidget(comboBoxImageType, 0, 7, 1, 1);


        gridLayout_3->addLayout(gridLayout_5, 2, 0, 1, 1);

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
        sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy1);
        scrollArea->setStyleSheet(QString::fromUtf8(""));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setLineWidth(1);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 572, 181));
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


        retranslateUi(WidgetImage);

        comboBoxImageType->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(WidgetImage);
    } // setupUi

    void retranslateUi(QWidget *WidgetImage)
    {
        WidgetImage->setWindowTitle(QCoreApplication::translate("WidgetImage", "Form", nullptr));
        labelTitle->setText(QCoreApplication::translate("WidgetImage", "View", nullptr));
#if QT_CONFIG(tooltip)
        cbPixelScope->setToolTip(QCoreApplication::translate("WidgetImage", "<html><head/><body><p>On /Off pixel scope for spatial data visualisation</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbPixelScope->setText(QCoreApplication::translate("WidgetImage", "Pixel Scope", nullptr));
#if QT_CONFIG(tooltip)
        cbDisplay->setToolTip(QCoreApplication::translate("WidgetImage", "<html><head/><body><p>On / Off visualisation during recording</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbDisplay->setText(QCoreApplication::translate("WidgetImage", "Don't display", nullptr));
#if QT_CONFIG(tooltip)
        cbRecord->setToolTip(QCoreApplication::translate("WidgetImage", "<html><head/><body><p>Activate recording</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbRecord->setText(QCoreApplication::translate("WidgetImage", "Record", nullptr));
        label_9->setText(QCoreApplication::translate("WidgetImage", "Image Type", nullptr));
#if QT_CONFIG(tooltip)
        cbDataToDifferentIP->setToolTip(QCoreApplication::translate("WidgetImage", "<html><head/><body><p>Use different data computer with different IP address</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbDataToDifferentIP->setText(QCoreApplication::translate("WidgetImage", "Data to different IP", nullptr));
#if QT_CONFIG(tooltip)
        cbPixelInfo->setToolTip(QCoreApplication::translate("WidgetImage", "<html><head/><body><p>On /Off one pixel statistical information</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbPixelInfo->setText(QCoreApplication::translate("WidgetImage", "Pixel Info", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonSingle->setToolTip(QCoreApplication::translate("WidgetImage", "<html><head/><body><p><span style=\" font-size:10pt;\">Capture one image</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButtonSingle->setText(QCoreApplication::translate("WidgetImage", "Picture", nullptr));
#if QT_CONFIG(tooltip)
        pushButtonStream->setToolTip(QCoreApplication::translate("WidgetImage", "<html><head/><body><p><span style=\" font-size:10pt;\">Switch on/off video streaming</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButtonStream->setText(QCoreApplication::translate("WidgetImage", "Start", nullptr));
#if QT_CONFIG(tooltip)
        cbTimeScope->setToolTip(QCoreApplication::translate("WidgetImage", "<html><head/><body><p>On /Off time scope for temporal data visualisation</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbTimeScope->setText(QCoreApplication::translate("WidgetImage", "Time Scope", nullptr));
        comboBoxImageType->setItemText(0, QCoreApplication::translate("WidgetImage", "Distance", nullptr));
        comboBoxImageType->setItemText(1, QCoreApplication::translate("WidgetImage", "Distance & Amplitude", nullptr));
        comboBoxImageType->setItemText(2, QCoreApplication::translate("WidgetImage", "Grayscale", nullptr));
        comboBoxImageType->setItemText(3, QCoreApplication::translate("WidgetImage", "Point Cloud D", nullptr));
        comboBoxImageType->setItemText(4, QCoreApplication::translate("WidgetImage", "Point Cloud D&A", nullptr));
        comboBoxImageType->setItemText(5, QCoreApplication::translate("WidgetImage", "DCS", nullptr));

#if QT_CONFIG(tooltip)
        comboBoxImageType->setToolTip(QCoreApplication::translate("WidgetImage", "<html><head/><body><p>Streaming and visualisation type</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        gbRoi->setTitle(QString());
        gbFilters->setTitle(QString());
        gbBase->setTitle(QString());
        gbModulation->setTitle(QString());
        gbBinning->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class WidgetImage: public Ui_WidgetImage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_IMAGE_H
