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
#include <QtWidgets/QWidget>
#include "LabelImage.h"

QT_BEGIN_NAMESPACE

class Ui_WidgetData
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout;
    QToolButton *tbTimeScope;
    QToolButton *tbRoi;
    QCheckBox *checkBoxMirrorHorizontal;
    QLabel *labelCoordinates;
    QLabel *labelFps;
    QToolButton *tbPixelInfo;
    QToolButton *tbFullScreen;
    QCheckBox *checkBoxMirrorVertical;
    QToolButton *tbPixelScope;
    QToolButton *tbDefaultRoi;
    QCheckBox *checkBoxRotate;
    QSpacerItem *horizontalSpacer;
    QCheckBox *checkBoxAmplitudeGrayscale;
    QGridLayout *gridLayout_2;
    LabelImage *labelLeftBottomImage;
    LabelImage *labelRightBottomImage;
    LabelImage *labelRightTopImage;
    QLabel *lLeftBottom;
    LabelImage *labelLeftTopImage;
    QLabel *lRightBottom;
    QLabel *lLeftTop;
    QLabel *lRightTop;
    QLabel *labelInfo;

    void setupUi(QWidget *WidgetData)
    {
        if (WidgetData->objectName().isEmpty())
            WidgetData->setObjectName(QString::fromUtf8("WidgetData"));
        WidgetData->resize(523, 398);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(10);
        sizePolicy.setVerticalStretch(10);
        sizePolicy.setHeightForWidth(WidgetData->sizePolicy().hasHeightForWidth());
        WidgetData->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(WidgetData);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tbTimeScope = new QToolButton(WidgetData);
        tbTimeScope->setObjectName(QString::fromUtf8("tbTimeScope"));
        tbTimeScope->setCheckable(true);

        gridLayout->addWidget(tbTimeScope, 1, 3, 1, 1);

        tbRoi = new QToolButton(WidgetData);
        tbRoi->setObjectName(QString::fromUtf8("tbRoi"));
        tbRoi->setCheckable(true);

        gridLayout->addWidget(tbRoi, 1, 4, 1, 1);

        checkBoxMirrorHorizontal = new QCheckBox(WidgetData);
        checkBoxMirrorHorizontal->setObjectName(QString::fromUtf8("checkBoxMirrorHorizontal"));

        gridLayout->addWidget(checkBoxMirrorHorizontal, 0, 0, 1, 1);

        labelCoordinates = new QLabel(WidgetData);
        labelCoordinates->setObjectName(QString::fromUtf8("labelCoordinates"));

        gridLayout->addWidget(labelCoordinates, 2, 0, 1, 1);

        labelFps = new QLabel(WidgetData);
        labelFps->setObjectName(QString::fromUtf8("labelFps"));

        gridLayout->addWidget(labelFps, 0, 8, 1, 1);

        tbPixelInfo = new QToolButton(WidgetData);
        tbPixelInfo->setObjectName(QString::fromUtf8("tbPixelInfo"));
        tbPixelInfo->setCheckable(true);
        tbPixelInfo->setChecked(false);
        tbPixelInfo->setAutoRaise(false);

        gridLayout->addWidget(tbPixelInfo, 1, 1, 1, 1);

        tbFullScreen = new QToolButton(WidgetData);
        tbFullScreen->setObjectName(QString::fromUtf8("tbFullScreen"));

        gridLayout->addWidget(tbFullScreen, 1, 8, 1, 1);

        checkBoxMirrorVertical = new QCheckBox(WidgetData);
        checkBoxMirrorVertical->setObjectName(QString::fromUtf8("checkBoxMirrorVertical"));

        gridLayout->addWidget(checkBoxMirrorVertical, 1, 0, 1, 1);

        tbPixelScope = new QToolButton(WidgetData);
        tbPixelScope->setObjectName(QString::fromUtf8("tbPixelScope"));
        tbPixelScope->setCheckable(true);

        gridLayout->addWidget(tbPixelScope, 1, 2, 1, 1);

        tbDefaultRoi = new QToolButton(WidgetData);
        tbDefaultRoi->setObjectName(QString::fromUtf8("tbDefaultRoi"));

        gridLayout->addWidget(tbDefaultRoi, 1, 5, 1, 1);

        checkBoxRotate = new QCheckBox(WidgetData);
        checkBoxRotate->setObjectName(QString::fromUtf8("checkBoxRotate"));

        gridLayout->addWidget(checkBoxRotate, 0, 5, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 6, 1, 1);

        checkBoxAmplitudeGrayscale = new QCheckBox(WidgetData);
        checkBoxAmplitudeGrayscale->setObjectName(QString::fromUtf8("checkBoxAmplitudeGrayscale"));

        gridLayout->addWidget(checkBoxAmplitudeGrayscale, 0, 1, 1, 3);


        gridLayout_4->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        labelLeftBottomImage = new LabelImage(WidgetData);
        labelLeftBottomImage->setObjectName(QString::fromUtf8("labelLeftBottomImage"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(labelLeftBottomImage->sizePolicy().hasHeightForWidth());
        labelLeftBottomImage->setSizePolicy(sizePolicy1);
        labelLeftBottomImage->setMinimumSize(QSize(160, 120));
        labelLeftBottomImage->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelLeftBottomImage, 3, 0, 1, 1);

        labelRightBottomImage = new LabelImage(WidgetData);
        labelRightBottomImage->setObjectName(QString::fromUtf8("labelRightBottomImage"));
        sizePolicy1.setHeightForWidth(labelRightBottomImage->sizePolicy().hasHeightForWidth());
        labelRightBottomImage->setSizePolicy(sizePolicy1);
        labelRightBottomImage->setMinimumSize(QSize(160, 120));
        labelRightBottomImage->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelRightBottomImage, 3, 1, 1, 1);

        labelRightTopImage = new LabelImage(WidgetData);
        labelRightTopImage->setObjectName(QString::fromUtf8("labelRightTopImage"));
        sizePolicy1.setHeightForWidth(labelRightTopImage->sizePolicy().hasHeightForWidth());
        labelRightTopImage->setSizePolicy(sizePolicy1);
        labelRightTopImage->setMinimumSize(QSize(160, 120));
        labelRightTopImage->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelRightTopImage, 1, 1, 1, 1);

        lLeftBottom = new QLabel(WidgetData);
        lLeftBottom->setObjectName(QString::fromUtf8("lLeftBottom"));

        gridLayout_2->addWidget(lLeftBottom, 2, 0, 1, 1);

        labelLeftTopImage = new LabelImage(WidgetData);
        labelLeftTopImage->setObjectName(QString::fromUtf8("labelLeftTopImage"));
        sizePolicy1.setHeightForWidth(labelLeftTopImage->sizePolicy().hasHeightForWidth());
        labelLeftTopImage->setSizePolicy(sizePolicy1);
        labelLeftTopImage->setMinimumSize(QSize(160, 120));
        labelLeftTopImage->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelLeftTopImage, 1, 0, 1, 1);

        lRightBottom = new QLabel(WidgetData);
        lRightBottom->setObjectName(QString::fromUtf8("lRightBottom"));

        gridLayout_2->addWidget(lRightBottom, 2, 1, 1, 1);

        lLeftTop = new QLabel(WidgetData);
        lLeftTop->setObjectName(QString::fromUtf8("lLeftTop"));

        gridLayout_2->addWidget(lLeftTop, 0, 0, 1, 1);

        lRightTop = new QLabel(WidgetData);
        lRightTop->setObjectName(QString::fromUtf8("lRightTop"));

        gridLayout_2->addWidget(lRightTop, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 3, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_4, 0, 0, 1, 1);

        labelInfo = new QLabel(WidgetData);
        labelInfo->setObjectName(QString::fromUtf8("labelInfo"));

        gridLayout_3->addWidget(labelInfo, 2, 0, 1, 1);


        retranslateUi(WidgetData);

        QMetaObject::connectSlotsByName(WidgetData);
    } // setupUi

    void retranslateUi(QWidget *WidgetData)
    {
        WidgetData->setWindowTitle(QCoreApplication::translate("WidgetData", "Image", nullptr));
#if QT_CONFIG(tooltip)
        tbTimeScope->setToolTip(QCoreApplication::translate("WidgetData", "<html><head/><body><p><span style=\" font-size:10pt;\">Turn on: activate time scope for temporal pixel analysis selection</span></p><p><span style=\" font-size:10pt;\">Turn off: deactivate time scope selection</span></p><p><span style=\" font-size:10pt;\">Select: left mouse button</span></p><p><span style=\" font-size:10pt;\">Deselect: ctrl+alt + right mouse button or right mouse button only</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbTimeScope->setText(QCoreApplication::translate("WidgetData", "Timescope", nullptr));
#if QT_CONFIG(tooltip)
        tbRoi->setToolTip(QCoreApplication::translate("WidgetData", "<html><head/><body><p><span style=\" font-size:10pt;\">Turn on: activate ROI (region of interest) selection</span></p><p><span style=\" font-size:10pt;\">Turn off: deactivate ROI selection</span></p><p><span style=\" font-size:10pt;\">Select: left mouse button</span></p><p><span style=\" font-size:10pt;\"><br/></span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbRoi->setText(QCoreApplication::translate("WidgetData", "ROI", nullptr));
#if QT_CONFIG(tooltip)
        checkBoxMirrorHorizontal->setToolTip(QCoreApplication::translate("WidgetData", "<html><head/><body><p><span style=\" font-size:10pt;\">Mirroring around the horizontal image axis</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        checkBoxMirrorHorizontal->setText(QCoreApplication::translate("WidgetData", "mirror horizontal", nullptr));
        labelCoordinates->setText(QString());
#if QT_CONFIG(tooltip)
        labelFps->setToolTip(QCoreApplication::translate("WidgetData", "<html><head/><body><p><span style=\" font-size:10pt;\">Video streaming frame rate frames / sec</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        labelFps->setText(QCoreApplication::translate("WidgetData", "Fps: 0", nullptr));
#if QT_CONFIG(tooltip)
        tbPixelInfo->setToolTip(QCoreApplication::translate("WidgetData", "<html><head/><body><p><span style=\" font-size:10pt;\">Turn on: activate pixel info selection</span></p><p><span style=\" font-size:10pt;\">Turn off: deactivate pixel info selection</span></p><p><span style=\" font-size:10pt;\">Select: left mouse button</span></p><p><span style=\" font-size:10pt;\">Deselect: ctrl + right mouse button or right mouse button only</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbPixelInfo->setText(QCoreApplication::translate("WidgetData", "Pixelinfo", nullptr));
#if QT_CONFIG(tooltip)
        tbFullScreen->setToolTip(QCoreApplication::translate("WidgetData", "<html><head/><body><p><span style=\" font-size:10pt;\">Turn on full screen</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbFullScreen->setText(QCoreApplication::translate("WidgetData", "Full Screen", nullptr));
#if QT_CONFIG(tooltip)
        checkBoxMirrorVertical->setToolTip(QCoreApplication::translate("WidgetData", "<html><head/><body><p><span style=\" font-size:10pt;\">Mirroring around the vertical image axis</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        checkBoxMirrorVertical->setText(QCoreApplication::translate("WidgetData", "mirror vertical", nullptr));
#if QT_CONFIG(tooltip)
        tbPixelScope->setToolTip(QCoreApplication::translate("WidgetData", "<html><head/><body><p><span style=\" font-size:10pt;\">Turn on: activate pixel scope selection</span></p><p><span style=\" font-size:10pt;\">Turn off: deactivate pixel scope selection</span></p><p><span style=\" font-size:10pt;\">Select: left mouse button</span></p><p><span style=\" font-size:10pt;\">Deselect: ctrl+alt + right mouse button or right mouse button only</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbPixelScope->setText(QCoreApplication::translate("WidgetData", "Pixelscope", nullptr));
#if QT_CONFIG(tooltip)
        tbDefaultRoi->setToolTip(QCoreApplication::translate("WidgetData", "<html><head/><body><p><span style=\" font-size:10pt;\">Select full 320 x 240 ROI size</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbDefaultRoi->setText(QCoreApplication::translate("WidgetData", "Default ROI", nullptr));
#if QT_CONFIG(tooltip)
        checkBoxRotate->setToolTip(QCoreApplication::translate("WidgetData", "<html><head/><body><p><span style=\" font-size:10pt;\">Rotate image 90 degree to right</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        checkBoxRotate->setText(QCoreApplication::translate("WidgetData", "rotate 90\302\260", nullptr));
#if QT_CONFIG(tooltip)
        checkBoxAmplitudeGrayscale->setToolTip(QCoreApplication::translate("WidgetData", "<html><head/><body><p><span style=\" font-size:10pt;\">Turn on/off amplitude grayscale</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        checkBoxAmplitudeGrayscale->setText(QCoreApplication::translate("WidgetData", "Show Amplitude Grayscale", nullptr));
        labelLeftBottomImage->setText(QString());
        labelRightBottomImage->setText(QString());
        labelRightTopImage->setText(QString());
        lLeftBottom->setText(QCoreApplication::translate("WidgetData", "lLeftBottom", nullptr));
        labelLeftTopImage->setText(QString());
        lRightBottom->setText(QCoreApplication::translate("WidgetData", "lRightBottom", nullptr));
        lLeftTop->setText(QCoreApplication::translate("WidgetData", "lLeftTop", nullptr));
        lRightTop->setText(QCoreApplication::translate("WidgetData", "lRightTop", nullptr));
        labelInfo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WidgetData: public Ui_WidgetData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_DATA_H
