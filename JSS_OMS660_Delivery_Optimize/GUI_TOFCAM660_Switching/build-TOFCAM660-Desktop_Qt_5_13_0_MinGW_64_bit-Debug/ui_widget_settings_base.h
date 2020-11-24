/********************************************************************************
** Form generated from reading UI file 'widget_settings_base.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_SETTINGS_BASE_H
#define UI_WIDGET_SETTINGS_BASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetSettingsBase
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_4;
    QSpinBox *spinBoxRangeMax;
    QLabel *labelOffset;
    QSpinBox *spinBoxOffset;
    QSpacerItem *horizontalSpacer;
    QSpinBox *spinBoxIntTime0;
    QLabel *labelIntegrationTime3d1;
    QLabel *labelIntegrationTime3d0;
    QSpinBox *spinBoxRangeMin;
    QSpinBox *spinBoxIntTimeGrayscale;
    QLabel *labelRangeMin;
    QSpinBox *spinBoxMinAmplitude;
    QLabel *lableMinAmplitude;
    QLabel *labelIntegrationTimeGrayscale;
    QSpinBox *spinBoxIntTime1;
    QLabel *labelRangeMax;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *WidgetSettingsBase)
    {
        if (WidgetSettingsBase->objectName().isEmpty())
            WidgetSettingsBase->setObjectName(QString::fromUtf8("WidgetSettingsBase"));
        WidgetSettingsBase->resize(404, 234);
        gridLayout = new QGridLayout(WidgetSettingsBase);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 9, 0, 9);
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setHorizontalSpacing(0);
        gridLayout_4->setVerticalSpacing(10);
        gridLayout_4->setContentsMargins(-1, 0, -1, -1);
        spinBoxRangeMax = new QSpinBox(WidgetSettingsBase);
        spinBoxRangeMax->setObjectName(QString::fromUtf8("spinBoxRangeMax"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spinBoxRangeMax->sizePolicy().hasHeightForWidth());
        spinBoxRangeMax->setSizePolicy(sizePolicy);
        spinBoxRangeMax->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setPointSize(10);
        spinBoxRangeMax->setFont(font);
        spinBoxRangeMax->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBoxRangeMax->setMaximum(70000);
        spinBoxRangeMax->setSingleStep(100);
        spinBoxRangeMax->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        spinBoxRangeMax->setValue(4000);

        gridLayout_4->addWidget(spinBoxRangeMax, 8, 2, 1, 1);

        labelOffset = new QLabel(WidgetSettingsBase);
        labelOffset->setObjectName(QString::fromUtf8("labelOffset"));
        labelOffset->setMinimumSize(QSize(0, 0));
        labelOffset->setFont(font);
        labelOffset->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        gridLayout_4->addWidget(labelOffset, 6, 1, 1, 1);

        spinBoxOffset = new QSpinBox(WidgetSettingsBase);
        spinBoxOffset->setObjectName(QString::fromUtf8("spinBoxOffset"));
        sizePolicy.setHeightForWidth(spinBoxOffset->sizePolicy().hasHeightForWidth());
        spinBoxOffset->setSizePolicy(sizePolicy);
        spinBoxOffset->setMinimumSize(QSize(0, 0));
        spinBoxOffset->setFont(font);
        spinBoxOffset->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBoxOffset->setMinimum(-15000);
        spinBoxOffset->setMaximum(15000);
        spinBoxOffset->setSingleStep(100);
        spinBoxOffset->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout_4->addWidget(spinBoxOffset, 6, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 1, 0, 1, 1);

        spinBoxIntTime0 = new QSpinBox(WidgetSettingsBase);
        spinBoxIntTime0->setObjectName(QString::fromUtf8("spinBoxIntTime0"));
        sizePolicy.setHeightForWidth(spinBoxIntTime0->sizePolicy().hasHeightForWidth());
        spinBoxIntTime0->setSizePolicy(sizePolicy);
        spinBoxIntTime0->setMinimumSize(QSize(0, 0));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        spinBoxIntTime0->setFont(font1);
        spinBoxIntTime0->setStyleSheet(QString::fromUtf8(""));
        spinBoxIntTime0->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBoxIntTime0->setAccelerated(true);
        spinBoxIntTime0->setMinimum(0);
        spinBoxIntTime0->setMaximum(2000);
        spinBoxIntTime0->setSingleStep(1);
        spinBoxIntTime0->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        spinBoxIntTime0->setValue(100);

        gridLayout_4->addWidget(spinBoxIntTime0, 1, 2, 1, 1);

        labelIntegrationTime3d1 = new QLabel(WidgetSettingsBase);
        labelIntegrationTime3d1->setObjectName(QString::fromUtf8("labelIntegrationTime3d1"));
        labelIntegrationTime3d1->setMinimumSize(QSize(0, 0));
        labelIntegrationTime3d1->setFont(font);
        labelIntegrationTime3d1->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        gridLayout_4->addWidget(labelIntegrationTime3d1, 2, 1, 1, 1);

        labelIntegrationTime3d0 = new QLabel(WidgetSettingsBase);
        labelIntegrationTime3d0->setObjectName(QString::fromUtf8("labelIntegrationTime3d0"));
        labelIntegrationTime3d0->setMinimumSize(QSize(0, 0));
        labelIntegrationTime3d0->setMaximumSize(QSize(16777215, 16777215));
        QFont font2;
        font2.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font2.setPointSize(10);
        labelIntegrationTime3d0->setFont(font2);
        labelIntegrationTime3d0->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        gridLayout_4->addWidget(labelIntegrationTime3d0, 1, 1, 1, 1);

        spinBoxRangeMin = new QSpinBox(WidgetSettingsBase);
        spinBoxRangeMin->setObjectName(QString::fromUtf8("spinBoxRangeMin"));
        sizePolicy.setHeightForWidth(spinBoxRangeMin->sizePolicy().hasHeightForWidth());
        spinBoxRangeMin->setSizePolicy(sizePolicy);
        spinBoxRangeMin->setMinimumSize(QSize(0, 0));
        spinBoxRangeMin->setFont(font);
        spinBoxRangeMin->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBoxRangeMin->setMaximum(70000);
        spinBoxRangeMin->setSingleStep(100);
        spinBoxRangeMin->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout_4->addWidget(spinBoxRangeMin, 7, 2, 1, 1);

        spinBoxIntTimeGrayscale = new QSpinBox(WidgetSettingsBase);
        spinBoxIntTimeGrayscale->setObjectName(QString::fromUtf8("spinBoxIntTimeGrayscale"));
        spinBoxIntTimeGrayscale->setEnabled(true);
        sizePolicy.setHeightForWidth(spinBoxIntTimeGrayscale->sizePolicy().hasHeightForWidth());
        spinBoxIntTimeGrayscale->setSizePolicy(sizePolicy);
        spinBoxIntTimeGrayscale->setMinimumSize(QSize(0, 0));
        spinBoxIntTimeGrayscale->setFont(font);
        spinBoxIntTimeGrayscale->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBoxIntTimeGrayscale->setMinimum(1);
        spinBoxIntTimeGrayscale->setMaximum(100000);
        spinBoxIntTimeGrayscale->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        spinBoxIntTimeGrayscale->setValue(1000);

        gridLayout_4->addWidget(spinBoxIntTimeGrayscale, 3, 2, 1, 1);

        labelRangeMin = new QLabel(WidgetSettingsBase);
        labelRangeMin->setObjectName(QString::fromUtf8("labelRangeMin"));
        labelRangeMin->setMinimumSize(QSize(0, 0));
        labelRangeMin->setFont(font);
        labelRangeMin->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        gridLayout_4->addWidget(labelRangeMin, 7, 1, 1, 1);

        spinBoxMinAmplitude = new QSpinBox(WidgetSettingsBase);
        spinBoxMinAmplitude->setObjectName(QString::fromUtf8("spinBoxMinAmplitude"));
        sizePolicy.setHeightForWidth(spinBoxMinAmplitude->sizePolicy().hasHeightForWidth());
        spinBoxMinAmplitude->setSizePolicy(sizePolicy);
        spinBoxMinAmplitude->setMinimumSize(QSize(0, 0));
        spinBoxMinAmplitude->setFont(font);
        spinBoxMinAmplitude->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBoxMinAmplitude->setMaximum(6000);
        spinBoxMinAmplitude->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout_4->addWidget(spinBoxMinAmplitude, 5, 2, 1, 1);

        lableMinAmplitude = new QLabel(WidgetSettingsBase);
        lableMinAmplitude->setObjectName(QString::fromUtf8("lableMinAmplitude"));
        lableMinAmplitude->setMinimumSize(QSize(0, 0));
        lableMinAmplitude->setFont(font);
        lableMinAmplitude->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        gridLayout_4->addWidget(lableMinAmplitude, 5, 1, 1, 1);

        labelIntegrationTimeGrayscale = new QLabel(WidgetSettingsBase);
        labelIntegrationTimeGrayscale->setObjectName(QString::fromUtf8("labelIntegrationTimeGrayscale"));
        labelIntegrationTimeGrayscale->setMinimumSize(QSize(0, 0));
        labelIntegrationTimeGrayscale->setFont(font);
        labelIntegrationTimeGrayscale->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        gridLayout_4->addWidget(labelIntegrationTimeGrayscale, 3, 1, 1, 1);

        spinBoxIntTime1 = new QSpinBox(WidgetSettingsBase);
        spinBoxIntTime1->setObjectName(QString::fromUtf8("spinBoxIntTime1"));
        sizePolicy.setHeightForWidth(spinBoxIntTime1->sizePolicy().hasHeightForWidth());
        spinBoxIntTime1->setSizePolicy(sizePolicy);
        spinBoxIntTime1->setMinimumSize(QSize(0, 0));
        spinBoxIntTime1->setFont(font1);
        spinBoxIntTime1->setStyleSheet(QString::fromUtf8(""));
        spinBoxIntTime1->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinBoxIntTime1->setMinimum(0);
        spinBoxIntTime1->setMaximum(2000);
        spinBoxIntTime1->setSingleStep(1);
        spinBoxIntTime1->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        spinBoxIntTime1->setValue(0);

        gridLayout_4->addWidget(spinBoxIntTime1, 2, 2, 1, 1);

        labelRangeMax = new QLabel(WidgetSettingsBase);
        labelRangeMax->setObjectName(QString::fromUtf8("labelRangeMax"));
        labelRangeMax->setMinimumSize(QSize(0, 0));
        labelRangeMax->setFont(font);
        labelRangeMax->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        gridLayout_4->addWidget(labelRangeMax, 8, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 1, 3, 1, 1);


        gridLayout->addLayout(gridLayout_4, 0, 0, 1, 1);


        retranslateUi(WidgetSettingsBase);

        QMetaObject::connectSlotsByName(WidgetSettingsBase);
    } // setupUi

    void retranslateUi(QWidget *WidgetSettingsBase)
    {
        WidgetSettingsBase->setWindowTitle(QCoreApplication::translate("WidgetSettingsBase", "Form", nullptr));
#if QT_CONFIG(tooltip)
        spinBoxRangeMax->setToolTip(QCoreApplication::translate("WidgetSettingsBase", "<html><head/><body><p>Distance max range for the distance image and point cloud color space</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        spinBoxRangeMax->setSuffix(QCoreApplication::translate("WidgetSettingsBase", "mm", nullptr));
#if QT_CONFIG(tooltip)
        labelOffset->setToolTip(QCoreApplication::translate("WidgetSettingsBase", "Offset. For calibrated camera set it to zero. Else set it to a value, so that a near object get's red", nullptr));
#endif // QT_CONFIG(tooltip)
        labelOffset->setText(QCoreApplication::translate("WidgetSettingsBase", "Offset", nullptr));
#if QT_CONFIG(tooltip)
        spinBoxOffset->setToolTip(QCoreApplication::translate("WidgetSettingsBase", "<html><head/><body><p>Additional offset to add to the resulting distance</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        spinBoxOffset->setSuffix(QCoreApplication::translate("WidgetSettingsBase", "mm", nullptr));
#if QT_CONFIG(tooltip)
        spinBoxIntTime0->setToolTip(QCoreApplication::translate("WidgetSettingsBase", "<html><head/><body><p>First TOF integration time or single integration time</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        spinBoxIntTime0->setSuffix(QCoreApplication::translate("WidgetSettingsBase", "us", nullptr));
#if QT_CONFIG(tooltip)
        labelIntegrationTime3d1->setToolTip(QCoreApplication::translate("WidgetSettingsBase", "Second integration time. Set to zero for one integration time.", nullptr));
#endif // QT_CONFIG(tooltip)
        labelIntegrationTime3d1->setText(QCoreApplication::translate("WidgetSettingsBase", "Integration Time 3D high", nullptr));
#if QT_CONFIG(tooltip)
        labelIntegrationTime3d0->setToolTip(QCoreApplication::translate("WidgetSettingsBase", "First integration time", nullptr));
#endif // QT_CONFIG(tooltip)
        labelIntegrationTime3d0->setText(QCoreApplication::translate("WidgetSettingsBase", "Integration Time 3D low/single", nullptr));
#if QT_CONFIG(tooltip)
        spinBoxRangeMin->setToolTip(QCoreApplication::translate("WidgetSettingsBase", "<html><head/><body><p>Distance min range for the distance image and point cloud color space</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        spinBoxRangeMin->setSuffix(QCoreApplication::translate("WidgetSettingsBase", "mm", nullptr));
#if QT_CONFIG(tooltip)
        spinBoxIntTimeGrayscale->setToolTip(QCoreApplication::translate("WidgetSettingsBase", "<html><head/><body><p>Integration time for grayscale. </p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        spinBoxIntTimeGrayscale->setSuffix(QCoreApplication::translate("WidgetSettingsBase", "us", nullptr));
        labelRangeMin->setText(QCoreApplication::translate("WidgetSettingsBase", "Distance Range min", nullptr));
#if QT_CONFIG(tooltip)
        spinBoxMinAmplitude->setToolTip(QCoreApplication::translate("WidgetSettingsBase", "<html><head/><body><p>Amplitude limit for valid distance or error code</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        spinBoxMinAmplitude->setSuffix(QCoreApplication::translate("WidgetSettingsBase", "lsb", nullptr));
#if QT_CONFIG(tooltip)
        lableMinAmplitude->setToolTip(QCoreApplication::translate("WidgetSettingsBase", "Amplitude limit where the pixel is set to \"low Amplitude\"", nullptr));
#endif // QT_CONFIG(tooltip)
        lableMinAmplitude->setText(QCoreApplication::translate("WidgetSettingsBase", "Minimum Amplitude", nullptr));
#if QT_CONFIG(tooltip)
        labelIntegrationTimeGrayscale->setToolTip(QCoreApplication::translate("WidgetSettingsBase", "Integration time for grayscale", nullptr));
#endif // QT_CONFIG(tooltip)
        labelIntegrationTimeGrayscale->setText(QCoreApplication::translate("WidgetSettingsBase", "Integration Time Grayscale", nullptr));
#if QT_CONFIG(tooltip)
        spinBoxIntTime1->setToolTip(QCoreApplication::translate("WidgetSettingsBase", "<html><head/><body><p>Second TOF integration time</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        spinBoxIntTime1->setSuffix(QCoreApplication::translate("WidgetSettingsBase", "us", nullptr));
#if QT_CONFIG(tooltip)
        labelRangeMax->setToolTip(QCoreApplication::translate("WidgetSettingsBase", "Range for the colormap", nullptr));
#endif // QT_CONFIG(tooltip)
        labelRangeMax->setText(QCoreApplication::translate("WidgetSettingsBase", "Distance Range max", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetSettingsBase: public Ui_WidgetSettingsBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_SETTINGS_BASE_H
