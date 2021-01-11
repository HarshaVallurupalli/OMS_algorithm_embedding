/********************************************************************************
** Form generated from reading UI file 'widget_pixelscope.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_PIXELSCOPE_H
#define UI_WIDGET_PIXELSCOPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetPixelScope
{
public:
    QGridLayout *gridLayout_3;
    QLabel *labelActValue;
    QLabel *labelCoordinates;
    QGridLayout *gridLayout_2;
    QCheckBox *checkBoxShowLeft;
    QLabel *lMeasurementType;
    QLabel *labelLeftMin;
    QCheckBox *checkBoxShowDcs3;
    QCheckBox *checkBoxAutoScale;
    QSpinBox *spinBoxLeftMin;
    QCheckBox *checkBoxShowDcs2;
    QSpinBox *spinBoxRightMin;
    QCheckBox *checkBoxShowRight;
    QSpinBox *spinBoxLeftMax;
    QCheckBox *checkBoxShowDcs1;
    QLabel *labelLeftMax;
    QCheckBox *checkBoxShowDcs0;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QSpinBox *spinBoxRightMax;
    QLabel *labelRightMax;
    QLabel *labelRightMin;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *WidgetPixelScope)
    {
        if (WidgetPixelScope->objectName().isEmpty())
            WidgetPixelScope->setObjectName(QString::fromUtf8("WidgetPixelScope"));
        WidgetPixelScope->resize(702, 322);
        gridLayout_3 = new QGridLayout(WidgetPixelScope);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        labelActValue = new QLabel(WidgetPixelScope);
        labelActValue->setObjectName(QString::fromUtf8("labelActValue"));

        gridLayout_3->addWidget(labelActValue, 2, 3, 1, 1);

        labelCoordinates = new QLabel(WidgetPixelScope);
        labelCoordinates->setObjectName(QString::fromUtf8("labelCoordinates"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelCoordinates->sizePolicy().hasHeightForWidth());
        labelCoordinates->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(labelCoordinates, 2, 2, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(10);
        checkBoxShowLeft = new QCheckBox(WidgetPixelScope);
        checkBoxShowLeft->setObjectName(QString::fromUtf8("checkBoxShowLeft"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(checkBoxShowLeft->sizePolicy().hasHeightForWidth());
        checkBoxShowLeft->setSizePolicy(sizePolicy1);
        checkBoxShowLeft->setFocusPolicy(Qt::NoFocus);
        checkBoxShowLeft->setLayoutDirection(Qt::LeftToRight);

        gridLayout_2->addWidget(checkBoxShowLeft, 1, 3, 1, 1);

        lMeasurementType = new QLabel(WidgetPixelScope);
        lMeasurementType->setObjectName(QString::fromUtf8("lMeasurementType"));

        gridLayout_2->addWidget(lMeasurementType, 2, 2, 1, 1);

        labelLeftMin = new QLabel(WidgetPixelScope);
        labelLeftMin->setObjectName(QString::fromUtf8("labelLeftMin"));
        labelLeftMin->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(labelLeftMin, 2, 5, 1, 1);

        checkBoxShowDcs3 = new QCheckBox(WidgetPixelScope);
        checkBoxShowDcs3->setObjectName(QString::fromUtf8("checkBoxShowDcs3"));
        checkBoxShowDcs3->setChecked(true);

        gridLayout_2->addWidget(checkBoxShowDcs3, 1, 12, 1, 1);

        checkBoxAutoScale = new QCheckBox(WidgetPixelScope);
        checkBoxAutoScale->setObjectName(QString::fromUtf8("checkBoxAutoScale"));
        sizePolicy1.setHeightForWidth(checkBoxAutoScale->sizePolicy().hasHeightForWidth());
        checkBoxAutoScale->setSizePolicy(sizePolicy1);
        checkBoxAutoScale->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(checkBoxAutoScale, 2, 0, 1, 1);

        spinBoxLeftMin = new QSpinBox(WidgetPixelScope);
        spinBoxLeftMin->setObjectName(QString::fromUtf8("spinBoxLeftMin"));
        spinBoxLeftMin->setMinimumSize(QSize(0, 0));
        spinBoxLeftMin->setKeyboardTracking(false);
        spinBoxLeftMin->setMaximum(99999);
        spinBoxLeftMin->setSingleStep(10);
        spinBoxLeftMin->setValue(0);

        gridLayout_2->addWidget(spinBoxLeftMin, 2, 3, 1, 2);

        checkBoxShowDcs2 = new QCheckBox(WidgetPixelScope);
        checkBoxShowDcs2->setObjectName(QString::fromUtf8("checkBoxShowDcs2"));
        checkBoxShowDcs2->setChecked(true);

        gridLayout_2->addWidget(checkBoxShowDcs2, 1, 11, 1, 1);

        spinBoxRightMin = new QSpinBox(WidgetPixelScope);
        spinBoxRightMin->setObjectName(QString::fromUtf8("spinBoxRightMin"));
        spinBoxRightMin->setMinimumSize(QSize(0, 0));
        spinBoxRightMin->setKeyboardTracking(false);
        spinBoxRightMin->setMaximum(200000);
        spinBoxRightMin->setSingleStep(10);

        gridLayout_2->addWidget(spinBoxRightMin, 3, 10, 1, 1);

        checkBoxShowRight = new QCheckBox(WidgetPixelScope);
        checkBoxShowRight->setObjectName(QString::fromUtf8("checkBoxShowRight"));
        sizePolicy1.setHeightForWidth(checkBoxShowRight->sizePolicy().hasHeightForWidth());
        checkBoxShowRight->setSizePolicy(sizePolicy1);
        checkBoxShowRight->setMinimumSize(QSize(0, 0));
        checkBoxShowRight->setFocusPolicy(Qt::NoFocus);
        checkBoxShowRight->setLayoutDirection(Qt::LeftToRight);

        gridLayout_2->addWidget(checkBoxShowRight, 1, 6, 1, 1);

        spinBoxLeftMax = new QSpinBox(WidgetPixelScope);
        spinBoxLeftMax->setObjectName(QString::fromUtf8("spinBoxLeftMax"));
        spinBoxLeftMax->setMinimumSize(QSize(0, 0));
        spinBoxLeftMax->setKeyboardTracking(false);
        spinBoxLeftMax->setMinimum(1);
        spinBoxLeftMax->setMaximum(99999);
        spinBoxLeftMax->setSingleStep(10);
        spinBoxLeftMax->setValue(2000);

        gridLayout_2->addWidget(spinBoxLeftMax, 2, 6, 1, 1);

        checkBoxShowDcs1 = new QCheckBox(WidgetPixelScope);
        checkBoxShowDcs1->setObjectName(QString::fromUtf8("checkBoxShowDcs1"));
        checkBoxShowDcs1->setChecked(true);

        gridLayout_2->addWidget(checkBoxShowDcs1, 1, 10, 1, 1);

        labelLeftMax = new QLabel(WidgetPixelScope);
        labelLeftMax->setObjectName(QString::fromUtf8("labelLeftMax"));
        labelLeftMax->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(labelLeftMax, 2, 7, 1, 1);

        checkBoxShowDcs0 = new QCheckBox(WidgetPixelScope);
        checkBoxShowDcs0->setObjectName(QString::fromUtf8("checkBoxShowDcs0"));
        checkBoxShowDcs0->setChecked(true);

        gridLayout_2->addWidget(checkBoxShowDcs0, 1, 8, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 2, 13, 1, 1);

        spinBoxRightMax = new QSpinBox(WidgetPixelScope);
        spinBoxRightMax->setObjectName(QString::fromUtf8("spinBoxRightMax"));
        spinBoxRightMax->setMinimumSize(QSize(0, 0));
        spinBoxRightMax->setKeyboardTracking(false);
        spinBoxRightMax->setMinimum(1);
        spinBoxRightMax->setMaximum(3000);
        spinBoxRightMax->setSingleStep(10);
        spinBoxRightMax->setValue(3000);

        gridLayout_2->addWidget(spinBoxRightMax, 2, 8, 1, 1);

        labelRightMax = new QLabel(WidgetPixelScope);
        labelRightMax->setObjectName(QString::fromUtf8("labelRightMax"));

        gridLayout_2->addWidget(labelRightMax, 3, 7, 1, 1);

        labelRightMin = new QLabel(WidgetPixelScope);
        labelRightMin->setObjectName(QString::fromUtf8("labelRightMin"));

        gridLayout_2->addWidget(labelRightMin, 3, 11, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 4);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        gridLayout_3->addLayout(gridLayout, 1, 0, 1, 4);

        label = new QLabel(WidgetPixelScope);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(label, 2, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 2, 1, 1, 1);


        retranslateUi(WidgetPixelScope);

        QMetaObject::connectSlotsByName(WidgetPixelScope);
    } // setupUi

    void retranslateUi(QWidget *WidgetPixelScope)
    {
        WidgetPixelScope->setWindowTitle(QCoreApplication::translate("WidgetPixelScope", "PixelScope", nullptr));
        labelActValue->setText(QString());
        labelCoordinates->setText(QString());
#if QT_CONFIG(tooltip)
        checkBoxShowLeft->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        checkBoxShowLeft->setText(QCoreApplication::translate("WidgetPixelScope", "distance", nullptr));
        lMeasurementType->setText(QCoreApplication::translate("WidgetPixelScope", "Distance [mm]", nullptr));
        labelLeftMin->setText(QCoreApplication::translate("WidgetPixelScope", "min  ", nullptr));
#if QT_CONFIG(tooltip)
        checkBoxShowDcs3->setToolTip(QCoreApplication::translate("WidgetPixelScope", "show DCS3 curve", nullptr));
#endif // QT_CONFIG(tooltip)
        checkBoxShowDcs3->setText(QCoreApplication::translate("WidgetPixelScope", "DCS3", nullptr));
#if QT_CONFIG(tooltip)
        checkBoxAutoScale->setToolTip(QCoreApplication::translate("WidgetPixelScope", "<html><head/><body><p><span style=\" font-size:10pt;\">Turn on/off auto scaling. If auto scale is on the axis range is floating depending from current minimal and maximal signal level.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        checkBoxAutoScale->setText(QCoreApplication::translate("WidgetPixelScope", "Auto range", nullptr));
#if QT_CONFIG(tooltip)
        spinBoxLeftMin->setToolTip(QCoreApplication::translate("WidgetPixelScope", "<html><head/><body><p><span style=\" font-size:10pt;\">Minimum value for distance or amplitude axis</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        spinBoxLeftMin->setSuffix(QString());
#if QT_CONFIG(tooltip)
        checkBoxShowDcs2->setToolTip(QCoreApplication::translate("WidgetPixelScope", "show DCS2 curve", nullptr));
#endif // QT_CONFIG(tooltip)
        checkBoxShowDcs2->setText(QCoreApplication::translate("WidgetPixelScope", "DCS2", nullptr));
#if QT_CONFIG(tooltip)
        spinBoxRightMin->setToolTip(QCoreApplication::translate("WidgetPixelScope", "<html><head/><body><p>Minimum value for amplitude axis</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        checkBoxShowRight->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        checkBoxShowRight->setText(QCoreApplication::translate("WidgetPixelScope", "amplitude", nullptr));
#if QT_CONFIG(tooltip)
        spinBoxLeftMax->setToolTip(QCoreApplication::translate("WidgetPixelScope", "<html><head/><body><p><span style=\" font-size:10pt;\">Maximum value for distance or amplitude axis</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        spinBoxLeftMax->setSuffix(QString());
#if QT_CONFIG(tooltip)
        checkBoxShowDcs1->setToolTip(QCoreApplication::translate("WidgetPixelScope", "show DCS1 curve", nullptr));
#endif // QT_CONFIG(tooltip)
        checkBoxShowDcs1->setText(QCoreApplication::translate("WidgetPixelScope", "DCS1", nullptr));
        labelLeftMax->setText(QCoreApplication::translate("WidgetPixelScope", "max  ", nullptr));
#if QT_CONFIG(tooltip)
        checkBoxShowDcs0->setToolTip(QCoreApplication::translate("WidgetPixelScope", "show DCS0 curve", nullptr));
#endif // QT_CONFIG(tooltip)
        checkBoxShowDcs0->setText(QCoreApplication::translate("WidgetPixelScope", "DCS0", nullptr));
#if QT_CONFIG(tooltip)
        spinBoxRightMax->setToolTip(QCoreApplication::translate("WidgetPixelScope", "<html><head/><body><p>Maximum value for amplitude axis</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        labelRightMax->setText(QCoreApplication::translate("WidgetPixelScope", "max", nullptr));
        labelRightMin->setText(QCoreApplication::translate("WidgetPixelScope", "min", nullptr));
#if QT_CONFIG(tooltip)
        label->setToolTip(QCoreApplication::translate("WidgetPixelScope", "<html><head/><body><p><span style=\" font-size:10pt;\">Select pixels: Ctrl + Alt + left mouse button</span></p><p><span style=\" font-size:10pt;\">Deselect: Ctrl + Alt + right mouse button</span></p><p><span style=\" font-size:10pt;\">Deselect all: right mouse button</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label->setText(QCoreApplication::translate("WidgetPixelScope", "Select pixels: Ctrl + Alt + left mouse button", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetPixelScope: public Ui_WidgetPixelScope {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_PIXELSCOPE_H
