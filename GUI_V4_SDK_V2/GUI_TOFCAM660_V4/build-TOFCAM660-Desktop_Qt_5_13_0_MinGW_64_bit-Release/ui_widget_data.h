/********************************************************************************
** Form generated from reading UI file 'widget_data.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_DATA_H
#define UI_WIDGET_DATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "LabelImage.h"

QT_BEGIN_NAMESPACE

class Ui_WidgetData
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_2;
    LabelImage *labelRightImage;
    LabelImage *labelLeftImage;
    QGridLayout *gridLayout;
    QCheckBox *checkBoxAmplitudeGrayscale;
    QCheckBox *checkBoxRotate;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *checkBoxMirrorHorizontal;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer;
    QCheckBox *checkBoxMirrorVertical;
    QLabel *labelCoordinates;
    QLabel *labelFps;
    QSpacerItem *horizontalSpacer_13;
    QLabel *labelImageCamno;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *horizontalSpacer_15;
    QSpacerItem *horizontalSpacer_16;
    QToolButton *tbPixelInfo;
    QToolButton *tbPixelScope;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_6;
    QToolButton *tbTimeScope;
    QToolButton *tbRoi;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_8;
    QToolButton *tbDefaultRoi;
    QToolButton *tbFullScreen;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_10;
    QLabel *labelInfo;

    void setupUi(QWidget *WidgetData)
    {
        if (WidgetData->objectName().isEmpty())
            WidgetData->setObjectName(QString::fromUtf8("WidgetData"));
        WidgetData->resize(782, 409);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(10);
        sizePolicy.setVerticalStretch(10);
        sizePolicy.setHeightForWidth(WidgetData->sizePolicy().hasHeightForWidth());
        WidgetData->setSizePolicy(sizePolicy);
        WidgetData->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 202, 247);"));
        verticalLayout = new QVBoxLayout(WidgetData);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        labelRightImage = new LabelImage(WidgetData);
        labelRightImage->setObjectName(QString::fromUtf8("labelRightImage"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(labelRightImage->sizePolicy().hasHeightForWidth());
        labelRightImage->setSizePolicy(sizePolicy1);
        labelRightImage->setMinimumSize(QSize(320, 240));
        labelRightImage->setMaximumSize(QSize(16777215, 16777215));
        labelRightImage->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelRightImage, 0, 1, 1, 1);

        labelLeftImage = new LabelImage(WidgetData);
        labelLeftImage->setObjectName(QString::fromUtf8("labelLeftImage"));
        sizePolicy1.setHeightForWidth(labelLeftImage->sizePolicy().hasHeightForWidth());
        labelLeftImage->setSizePolicy(sizePolicy1);
        labelLeftImage->setMinimumSize(QSize(320, 240));
        labelLeftImage->setMaximumSize(QSize(16777215, 16777215));
        labelLeftImage->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelLeftImage, 0, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 3, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        checkBoxAmplitudeGrayscale = new QCheckBox(WidgetData);
        checkBoxAmplitudeGrayscale->setObjectName(QString::fromUtf8("checkBoxAmplitudeGrayscale"));
        checkBoxAmplitudeGrayscale->setMinimumSize(QSize(120, 0));

        gridLayout->addWidget(checkBoxAmplitudeGrayscale, 0, 8, 1, 3);

        checkBoxRotate = new QCheckBox(WidgetData);
        checkBoxRotate->setObjectName(QString::fromUtf8("checkBoxRotate"));
        checkBoxRotate->setMinimumSize(QSize(120, 0));

        gridLayout->addWidget(checkBoxRotate, 0, 13, 1, 3);

        horizontalSpacer_12 = new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_12, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 11, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 7, 1, 1);

        checkBoxMirrorHorizontal = new QCheckBox(WidgetData);
        checkBoxMirrorHorizontal->setObjectName(QString::fromUtf8("checkBoxMirrorHorizontal"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(checkBoxMirrorHorizontal->sizePolicy().hasHeightForWidth());
        checkBoxMirrorHorizontal->setSizePolicy(sizePolicy2);
        checkBoxMirrorHorizontal->setMinimumSize(QSize(120, 0));

        gridLayout->addWidget(checkBoxMirrorHorizontal, 0, 1, 1, 3);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 16, 1, 1);

        checkBoxMirrorVertical = new QCheckBox(WidgetData);
        checkBoxMirrorVertical->setObjectName(QString::fromUtf8("checkBoxMirrorVertical"));
        checkBoxMirrorVertical->setMinimumSize(QSize(120, 0));

        gridLayout->addWidget(checkBoxMirrorVertical, 0, 5, 1, 2);

        labelCoordinates = new QLabel(WidgetData);
        labelCoordinates->setObjectName(QString::fromUtf8("labelCoordinates"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(labelCoordinates->sizePolicy().hasHeightForWidth());
        labelCoordinates->setSizePolicy(sizePolicy3);
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        labelCoordinates->setFont(font);
        labelCoordinates->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 0);"));
        labelCoordinates->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelCoordinates, 5, 1, 1, 4);

        labelFps = new QLabel(WidgetData);
        labelFps->setObjectName(QString::fromUtf8("labelFps"));
        sizePolicy3.setHeightForWidth(labelFps->sizePolicy().hasHeightForWidth());
        labelFps->setSizePolicy(sizePolicy3);
        labelFps->setFont(font);
        labelFps->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 0);"));
        labelFps->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(labelFps, 5, 13, 1, 3);

        horizontalSpacer_13 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_13, 5, 16, 1, 1);

        labelImageCamno = new QLabel(WidgetData);
        labelImageCamno->setObjectName(QString::fromUtf8("labelImageCamno"));
        sizePolicy3.setHeightForWidth(labelImageCamno->sizePolicy().hasHeightForWidth());
        labelImageCamno->setSizePolicy(sizePolicy3);
        labelImageCamno->setMinimumSize(QSize(100, 0));
        labelImageCamno->setFont(font);
        labelImageCamno->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 0);"));
        labelImageCamno->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelImageCamno, 5, 6, 1, 5);

        horizontalSpacer_14 = new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_14, 5, 11, 1, 2);

        horizontalSpacer_15 = new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_15, 5, 5, 1, 1);

        horizontalSpacer_16 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_16, 5, 0, 1, 1);

        tbPixelInfo = new QToolButton(WidgetData);
        tbPixelInfo->setObjectName(QString::fromUtf8("tbPixelInfo"));
        tbPixelInfo->setMinimumSize(QSize(100, 0));
        tbPixelInfo->setStyleSheet(QString::fromUtf8("background-color: rgb(19, 10, 113);"));
        tbPixelInfo->setCheckable(true);
        tbPixelInfo->setChecked(false);
        tbPixelInfo->setAutoRaise(false);

        gridLayout->addWidget(tbPixelInfo, 1, 1, 4, 1);

        tbPixelScope = new QToolButton(WidgetData);
        tbPixelScope->setObjectName(QString::fromUtf8("tbPixelScope"));
        tbPixelScope->setMinimumSize(QSize(100, 0));
        tbPixelScope->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 90);"));
        tbPixelScope->setCheckable(true);

        gridLayout->addWidget(tbPixelScope, 1, 3, 4, 1);

        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 2, 4, 1);

        horizontalSpacer_11 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_11, 1, 0, 4, 1);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 1, 4, 4, 1);

        tbTimeScope = new QToolButton(WidgetData);
        tbTimeScope->setObjectName(QString::fromUtf8("tbTimeScope"));
        tbTimeScope->setMinimumSize(QSize(100, 0));
        tbTimeScope->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 90);"));
        tbTimeScope->setCheckable(true);

        gridLayout->addWidget(tbTimeScope, 1, 5, 4, 2);

        tbRoi = new QToolButton(WidgetData);
        tbRoi->setObjectName(QString::fromUtf8("tbRoi"));
        tbRoi->setMinimumSize(QSize(100, 0));
        tbRoi->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 90);"));
        tbRoi->setCheckable(true);

        gridLayout->addWidget(tbRoi, 1, 8, 4, 1);

        horizontalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 1, 7, 4, 1);

        horizontalSpacer_8 = new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 1, 9, 4, 1);

        tbDefaultRoi = new QToolButton(WidgetData);
        tbDefaultRoi->setObjectName(QString::fromUtf8("tbDefaultRoi"));
        tbDefaultRoi->setMinimumSize(QSize(100, 0));
        tbDefaultRoi->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 90);"));

        gridLayout->addWidget(tbDefaultRoi, 1, 10, 4, 2);

        tbFullScreen = new QToolButton(WidgetData);
        tbFullScreen->setObjectName(QString::fromUtf8("tbFullScreen"));
        tbFullScreen->setMinimumSize(QSize(100, 0));
        tbFullScreen->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 90);"));

        gridLayout->addWidget(tbFullScreen, 1, 13, 4, 3);

        horizontalSpacer_9 = new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 1, 12, 4, 1);

        horizontalSpacer_10 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 1, 16, 4, 1);


        gridLayout_4->addLayout(gridLayout, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_4);

        labelInfo = new QLabel(WidgetData);
        labelInfo->setObjectName(QString::fromUtf8("labelInfo"));
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(labelInfo->sizePolicy().hasHeightForWidth());
        labelInfo->setSizePolicy(sizePolicy4);
        labelInfo->setMinimumSize(QSize(380, 0));
        labelInfo->setFont(font);
        labelInfo->setStyleSheet(QString::fromUtf8("background-color: rgb(255,170,0);"));

        verticalLayout->addWidget(labelInfo);


        retranslateUi(WidgetData);

        QMetaObject::connectSlotsByName(WidgetData);
    } // setupUi

    void retranslateUi(QWidget *WidgetData)
    {
        WidgetData->setWindowTitle(QCoreApplication::translate("WidgetData", "Image", nullptr));
        labelRightImage->setText(QString());
        labelLeftImage->setText(QString());
#if QT_CONFIG(tooltip)
        checkBoxAmplitudeGrayscale->setToolTip(QCoreApplication::translate("WidgetData", "<html><head/><body><p><span style=\" font-size:10pt;\">Turn on/off amplitude grayscale</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        checkBoxAmplitudeGrayscale->setText(QCoreApplication::translate("WidgetData", "Show Amplitude Grayscale", nullptr));
#if QT_CONFIG(tooltip)
        checkBoxRotate->setToolTip(QCoreApplication::translate("WidgetData", "<html><head/><body><p><span style=\" font-size:10pt;\">Rotate image 90 degree to right</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        checkBoxRotate->setText(QCoreApplication::translate("WidgetData", "rotate 90\302\260", nullptr));
#if QT_CONFIG(tooltip)
        checkBoxMirrorHorizontal->setToolTip(QCoreApplication::translate("WidgetData", "<html><head/><body><p><span style=\" font-size:10pt;\">Mirroring around the horizontal image axis</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        checkBoxMirrorHorizontal->setText(QCoreApplication::translate("WidgetData", "mirror horizontal", nullptr));
#if QT_CONFIG(tooltip)
        checkBoxMirrorVertical->setToolTip(QCoreApplication::translate("WidgetData", "<html><head/><body><p><span style=\" font-size:10pt;\">Mirroring around the vertical image axis</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        checkBoxMirrorVertical->setText(QCoreApplication::translate("WidgetData", "mirror vertical", nullptr));
        labelCoordinates->setText(QString());
#if QT_CONFIG(tooltip)
        labelFps->setToolTip(QCoreApplication::translate("WidgetData", "<html><head/><body><p><span style=\" font-size:10pt;\">Video streaming frame rate frames / sec</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        labelFps->setText(QCoreApplication::translate("WidgetData", "Fps: 0", nullptr));
        labelImageCamno->setText(QCoreApplication::translate("WidgetData", "Streaming from Camera #", nullptr));
#if QT_CONFIG(tooltip)
        tbPixelInfo->setToolTip(QCoreApplication::translate("WidgetData", "<html><head/><body><p><span style=\" font-size:10pt;\">Turn on: activate pixel info selection</span></p><p><span style=\" font-size:10pt;\">Turn off: deactivate pixel info selection</span></p><p><span style=\" font-size:10pt;\">Select: left mouse button</span></p><p><span style=\" font-size:10pt;\">Deselect: ctrl + right mouse button or right mouse button only</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbPixelInfo->setText(QCoreApplication::translate("WidgetData", "Pixelinfo", nullptr));
#if QT_CONFIG(tooltip)
        tbPixelScope->setToolTip(QCoreApplication::translate("WidgetData", "<html><head/><body><p><span style=\" font-size:10pt;\">Turn on: activate pixel scope selection</span></p><p><span style=\" font-size:10pt;\">Turn off: deactivate pixel scope selection</span></p><p><span style=\" font-size:10pt;\">Select: left mouse button</span></p><p><span style=\" font-size:10pt;\">Deselect: ctrl+alt + right mouse button or right mouse button only</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbPixelScope->setText(QCoreApplication::translate("WidgetData", "Pixelscope", nullptr));
#if QT_CONFIG(tooltip)
        tbTimeScope->setToolTip(QCoreApplication::translate("WidgetData", "<html><head/><body><p><span style=\" font-size:10pt;\">Turn on: activate time scope for temporal pixel analysis selection</span></p><p><span style=\" font-size:10pt;\">Turn off: deactivate time scope selection</span></p><p><span style=\" font-size:10pt;\">Select: left mouse button</span></p><p><span style=\" font-size:10pt;\">Deselect: ctrl+alt + right mouse button or right mouse button only</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbTimeScope->setText(QCoreApplication::translate("WidgetData", "Timescope", nullptr));
#if QT_CONFIG(tooltip)
        tbRoi->setToolTip(QCoreApplication::translate("WidgetData", "<html><head/><body><p><span style=\" font-size:10pt;\">Turn on: activate ROI (region of interest) selection</span></p><p><span style=\" font-size:10pt;\">Turn off: deactivate ROI selection</span></p><p><span style=\" font-size:10pt;\">Select: left mouse button</span></p><p><span style=\" font-size:10pt;\"><br/></span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbRoi->setText(QCoreApplication::translate("WidgetData", "ROI", nullptr));
#if QT_CONFIG(tooltip)
        tbDefaultRoi->setToolTip(QCoreApplication::translate("WidgetData", "<html><head/><body><p><span style=\" font-size:10pt;\">Select full 320 x 240 ROI size</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbDefaultRoi->setText(QCoreApplication::translate("WidgetData", "Default ROI", nullptr));
#if QT_CONFIG(tooltip)
        tbFullScreen->setToolTip(QCoreApplication::translate("WidgetData", "<html><head/><body><p><span style=\" font-size:10pt;\">Turn on full screen</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbFullScreen->setText(QCoreApplication::translate("WidgetData", "Full Screen", nullptr));
        labelInfo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WidgetData: public Ui_WidgetData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_DATA_H
