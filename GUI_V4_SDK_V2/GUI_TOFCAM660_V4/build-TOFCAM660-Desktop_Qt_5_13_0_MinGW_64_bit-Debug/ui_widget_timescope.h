/********************************************************************************
** Form generated from reading UI file 'widget_timescope.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_TIMESCOPE_H
#define UI_WIDGET_TIMESCOPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetTimeScope
{
public:
    QGridLayout *gridLayout_3;
    QLabel *labelActValue;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *labelCoordinates;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout_2;
    QCheckBox *checkBoxShowDcs3;
    QLabel *labelLeftMin;
    QCheckBox *checkBoxShowRight;
    QLabel *labelRightMax;
    QLabel *labelLeftMax;
    QLabel *lNumberOfSamples_2;
    QLabel *lMeasurementType;
    QSpinBox *spinBoxLeftMax;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *checkBoxShowDcs0;
    QSpinBox *spinBoxRightMin;
    QCheckBox *checkBoxShowDcs2;
    QCheckBox *checkBoxShowDcs1;
    QSpinBox *spinBoxNumberOfValues;
    QSpacerItem *horizontalSpacer;
    QCheckBox *checkBoxShowLeft;
    QLabel *labelRightMin;
    QSpinBox *spinBoxRightMax;
    QCheckBox *checkBoxAutoScale;
    QSpinBox *spinBoxLeftMin;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *WidgetTimeScope)
    {
        if (WidgetTimeScope->objectName().isEmpty())
            WidgetTimeScope->setObjectName(QString::fromUtf8("WidgetTimeScope"));
        WidgetTimeScope->resize(681, 132);
        gridLayout_3 = new QGridLayout(WidgetTimeScope);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        labelActValue = new QLabel(WidgetTimeScope);
        labelActValue->setObjectName(QString::fromUtf8("labelActValue"));

        gridLayout_3->addWidget(labelActValue, 2, 3, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        gridLayout_3->addLayout(gridLayout, 1, 0, 1, 4);

        label = new QLabel(WidgetTimeScope);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(label, 2, 0, 1, 1);

        labelCoordinates = new QLabel(WidgetTimeScope);
        labelCoordinates->setObjectName(QString::fromUtf8("labelCoordinates"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelCoordinates->sizePolicy().hasHeightForWidth());
        labelCoordinates->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(labelCoordinates, 2, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 2, 1, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(10);
        checkBoxShowDcs3 = new QCheckBox(WidgetTimeScope);
        checkBoxShowDcs3->setObjectName(QString::fromUtf8("checkBoxShowDcs3"));
        checkBoxShowDcs3->setChecked(true);

        gridLayout_2->addWidget(checkBoxShowDcs3, 4, 14, 1, 1);

        labelLeftMin = new QLabel(WidgetTimeScope);
        labelLeftMin->setObjectName(QString::fromUtf8("labelLeftMin"));
        labelLeftMin->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(labelLeftMin, 3, 6, 1, 1);

        checkBoxShowRight = new QCheckBox(WidgetTimeScope);
        checkBoxShowRight->setObjectName(QString::fromUtf8("checkBoxShowRight"));
        sizePolicy.setHeightForWidth(checkBoxShowRight->sizePolicy().hasHeightForWidth());
        checkBoxShowRight->setSizePolicy(sizePolicy);
        checkBoxShowRight->setMinimumSize(QSize(0, 0));
        checkBoxShowRight->setFocusPolicy(Qt::NoFocus);
        checkBoxShowRight->setLayoutDirection(Qt::LeftToRight);

        gridLayout_2->addWidget(checkBoxShowRight, 4, 3, 1, 1);

        labelRightMax = new QLabel(WidgetTimeScope);
        labelRightMax->setObjectName(QString::fromUtf8("labelRightMax"));

        gridLayout_2->addWidget(labelRightMax, 4, 8, 1, 1);

        labelLeftMax = new QLabel(WidgetTimeScope);
        labelLeftMax->setObjectName(QString::fromUtf8("labelLeftMax"));
        labelLeftMax->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(labelLeftMax, 3, 8, 1, 1);

        lNumberOfSamples_2 = new QLabel(WidgetTimeScope);
        lNumberOfSamples_2->setObjectName(QString::fromUtf8("lNumberOfSamples_2"));
        lNumberOfSamples_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(lNumberOfSamples_2, 3, 14, 1, 1);

        lMeasurementType = new QLabel(WidgetTimeScope);
        lMeasurementType->setObjectName(QString::fromUtf8("lMeasurementType"));

        gridLayout_2->addWidget(lMeasurementType, 3, 2, 1, 1);

        spinBoxLeftMax = new QSpinBox(WidgetTimeScope);
        spinBoxLeftMax->setObjectName(QString::fromUtf8("spinBoxLeftMax"));
        spinBoxLeftMax->setMinimumSize(QSize(0, 0));
        spinBoxLeftMax->setKeyboardTracking(false);
        spinBoxLeftMax->setMinimum(1);
        spinBoxLeftMax->setMaximum(99999);
        spinBoxLeftMax->setSingleStep(10);
        spinBoxLeftMax->setValue(2000);

        gridLayout_2->addWidget(spinBoxLeftMax, 3, 7, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 3, 1, 1, 1);

        checkBoxShowDcs0 = new QCheckBox(WidgetTimeScope);
        checkBoxShowDcs0->setObjectName(QString::fromUtf8("checkBoxShowDcs0"));
        checkBoxShowDcs0->setChecked(true);

        gridLayout_2->addWidget(checkBoxShowDcs0, 4, 2, 1, 1);

        spinBoxRightMin = new QSpinBox(WidgetTimeScope);
        spinBoxRightMin->setObjectName(QString::fromUtf8("spinBoxRightMin"));
        spinBoxRightMin->setMinimumSize(QSize(0, 0));
        spinBoxRightMin->setKeyboardTracking(false);
        spinBoxRightMin->setMaximum(200000);
        spinBoxRightMin->setSingleStep(10);

        gridLayout_2->addWidget(spinBoxRightMin, 4, 4, 1, 1);

        checkBoxShowDcs2 = new QCheckBox(WidgetTimeScope);
        checkBoxShowDcs2->setObjectName(QString::fromUtf8("checkBoxShowDcs2"));
        checkBoxShowDcs2->setChecked(true);

        gridLayout_2->addWidget(checkBoxShowDcs2, 4, 15, 1, 1);

        checkBoxShowDcs1 = new QCheckBox(WidgetTimeScope);
        checkBoxShowDcs1->setObjectName(QString::fromUtf8("checkBoxShowDcs1"));
        checkBoxShowDcs1->setChecked(true);

        gridLayout_2->addWidget(checkBoxShowDcs1, 4, 0, 1, 1);

        spinBoxNumberOfValues = new QSpinBox(WidgetTimeScope);
        spinBoxNumberOfValues->setObjectName(QString::fromUtf8("spinBoxNumberOfValues"));
        spinBoxNumberOfValues->setMinimumSize(QSize(0, 0));
        spinBoxNumberOfValues->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        spinBoxNumberOfValues->setFont(font);
        spinBoxNumberOfValues->setStyleSheet(QString::fromUtf8(""));
        spinBoxNumberOfValues->setKeyboardTracking(false);
        spinBoxNumberOfValues->setMinimum(10);
        spinBoxNumberOfValues->setMaximum(100000);
        spinBoxNumberOfValues->setSingleStep(10);
        spinBoxNumberOfValues->setValue(2000);

        gridLayout_2->addWidget(spinBoxNumberOfValues, 3, 15, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 3, 13, 1, 1);

        checkBoxShowLeft = new QCheckBox(WidgetTimeScope);
        checkBoxShowLeft->setObjectName(QString::fromUtf8("checkBoxShowLeft"));
        sizePolicy.setHeightForWidth(checkBoxShowLeft->sizePolicy().hasHeightForWidth());
        checkBoxShowLeft->setSizePolicy(sizePolicy);
        checkBoxShowLeft->setFocusPolicy(Qt::NoFocus);
        checkBoxShowLeft->setLayoutDirection(Qt::LeftToRight);

        gridLayout_2->addWidget(checkBoxShowLeft, 3, 3, 1, 1);

        labelRightMin = new QLabel(WidgetTimeScope);
        labelRightMin->setObjectName(QString::fromUtf8("labelRightMin"));

        gridLayout_2->addWidget(labelRightMin, 4, 6, 1, 1);

        spinBoxRightMax = new QSpinBox(WidgetTimeScope);
        spinBoxRightMax->setObjectName(QString::fromUtf8("spinBoxRightMax"));
        sizePolicy.setHeightForWidth(spinBoxRightMax->sizePolicy().hasHeightForWidth());
        spinBoxRightMax->setSizePolicy(sizePolicy);
        spinBoxRightMax->setMinimumSize(QSize(0, 0));
        spinBoxRightMax->setKeyboardTracking(false);
        spinBoxRightMax->setMinimum(1);
        spinBoxRightMax->setMaximum(3000);
        spinBoxRightMax->setSingleStep(10);
        spinBoxRightMax->setValue(3000);

        gridLayout_2->addWidget(spinBoxRightMax, 4, 7, 1, 1);

        checkBoxAutoScale = new QCheckBox(WidgetTimeScope);
        checkBoxAutoScale->setObjectName(QString::fromUtf8("checkBoxAutoScale"));
        sizePolicy.setHeightForWidth(checkBoxAutoScale->sizePolicy().hasHeightForWidth());
        checkBoxAutoScale->setSizePolicy(sizePolicy);
        checkBoxAutoScale->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(checkBoxAutoScale, 3, 0, 1, 1);

        spinBoxLeftMin = new QSpinBox(WidgetTimeScope);
        spinBoxLeftMin->setObjectName(QString::fromUtf8("spinBoxLeftMin"));
        spinBoxLeftMin->setMinimumSize(QSize(0, 0));
        spinBoxLeftMin->setKeyboardTracking(false);
        spinBoxLeftMin->setMaximum(99999);
        spinBoxLeftMin->setSingleStep(10);
        spinBoxLeftMin->setValue(0);

        gridLayout_2->addWidget(spinBoxLeftMin, 3, 4, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 3, 16, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 4);


        retranslateUi(WidgetTimeScope);

        QMetaObject::connectSlotsByName(WidgetTimeScope);
    } // setupUi

    void retranslateUi(QWidget *WidgetTimeScope)
    {
        WidgetTimeScope->setWindowTitle(QCoreApplication::translate("WidgetTimeScope", "TimeScope", nullptr));
        labelActValue->setText(QString());
#if QT_CONFIG(tooltip)
        label->setToolTip(QCoreApplication::translate("WidgetTimeScope", "<html><head/><body><p>Select: Alt + left mouse button</p><p>Deselect: Alt + Right mouse button</p><p>Deselect all: Right mouse button</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label->setText(QCoreApplication::translate("WidgetTimeScope", "Select: Alt + left mouse button", nullptr));
        labelCoordinates->setText(QString());
#if QT_CONFIG(tooltip)
        checkBoxShowDcs3->setToolTip(QCoreApplication::translate("WidgetTimeScope", "show DCS3 curve", nullptr));
#endif // QT_CONFIG(tooltip)
        checkBoxShowDcs3->setText(QCoreApplication::translate("WidgetTimeScope", "DCS3", nullptr));
        labelLeftMin->setText(QCoreApplication::translate("WidgetTimeScope", "min  ", nullptr));
#if QT_CONFIG(tooltip)
        checkBoxShowRight->setToolTip(QCoreApplication::translate("WidgetTimeScope", "<html><head/><body><p><span style=\" font-size:10pt;\">Select amplitude curve</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        checkBoxShowRight->setText(QCoreApplication::translate("WidgetTimeScope", "Amplitude [LSB]", nullptr));
        labelRightMax->setText(QCoreApplication::translate("WidgetTimeScope", "max", nullptr));
        labelLeftMax->setText(QCoreApplication::translate("WidgetTimeScope", "max", nullptr));
        lNumberOfSamples_2->setText(QCoreApplication::translate("WidgetTimeScope", "Number frames", nullptr));
        lMeasurementType->setText(QCoreApplication::translate("WidgetTimeScope", "Distance [mm]", nullptr));
#if QT_CONFIG(tooltip)
        spinBoxLeftMax->setToolTip(QCoreApplication::translate("WidgetTimeScope", "<html><head/><body><p><span style=\" font-size:10pt;\">Maximum value for distance axis</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        spinBoxLeftMax->setSuffix(QString());
#if QT_CONFIG(tooltip)
        checkBoxShowDcs0->setToolTip(QCoreApplication::translate("WidgetTimeScope", "show DCS0 curve", nullptr));
#endif // QT_CONFIG(tooltip)
        checkBoxShowDcs0->setText(QCoreApplication::translate("WidgetTimeScope", "DCS0", nullptr));
#if QT_CONFIG(tooltip)
        spinBoxRightMin->setToolTip(QCoreApplication::translate("WidgetTimeScope", "<html><head/><body><p><span style=\" font-size:10pt;\">Minimum value for amplitude axis</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        checkBoxShowDcs2->setToolTip(QCoreApplication::translate("WidgetTimeScope", "show DCS2 curve", nullptr));
#endif // QT_CONFIG(tooltip)
        checkBoxShowDcs2->setText(QCoreApplication::translate("WidgetTimeScope", "DCS2", nullptr));
#if QT_CONFIG(tooltip)
        checkBoxShowDcs1->setToolTip(QCoreApplication::translate("WidgetTimeScope", "show DCS1 curve", nullptr));
#endif // QT_CONFIG(tooltip)
        checkBoxShowDcs1->setText(QCoreApplication::translate("WidgetTimeScope", "DCS1", nullptr));
#if QT_CONFIG(tooltip)
        spinBoxNumberOfValues->setToolTip(QCoreApplication::translate("WidgetTimeScope", "<html><head/><body><p><span style=\" font-size:10pt;\">The number of values represented in time scope</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        spinBoxNumberOfValues->setSuffix(QString());
#if QT_CONFIG(tooltip)
        checkBoxShowLeft->setToolTip(QCoreApplication::translate("WidgetTimeScope", "<html><head/><body><p><span style=\" font-size:10pt;\">Select distance curve</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        checkBoxShowLeft->setText(QCoreApplication::translate("WidgetTimeScope", "Distance   [mm]", nullptr));
        labelRightMin->setText(QCoreApplication::translate("WidgetTimeScope", "min  ", nullptr));
#if QT_CONFIG(tooltip)
        spinBoxRightMax->setToolTip(QCoreApplication::translate("WidgetTimeScope", "<html><head/><body><p><span style=\" font-size:10pt;\">Maximum value for amplitude axis</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        checkBoxAutoScale->setToolTip(QCoreApplication::translate("WidgetTimeScope", "<html><head/><body><p><span style=\" font-size:10pt;\">Turn on/off auto scaling. If auto scale is on the axis range is floating depending from current minimal and maximal signal level.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        checkBoxAutoScale->setText(QCoreApplication::translate("WidgetTimeScope", "Auto range", nullptr));
#if QT_CONFIG(tooltip)
        spinBoxLeftMin->setToolTip(QCoreApplication::translate("WidgetTimeScope", "<html><head/><body><p><span style=\" font-size:10pt;\">Minimum value for distance axis</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        spinBoxLeftMin->setSuffix(QString());
    } // retranslateUi

};

namespace Ui {
    class WidgetTimeScope: public Ui_WidgetTimeScope {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_TIMESCOPE_H
