/********************************************************************************
** Form generated from reading UI file 'widget_settings_filter.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_SETTINGS_FILTER_H
#define UI_WIDGET_SETTINGS_FILTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetSettingsFilter
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *lTemporalEdgeThresholdLow;
    QCheckBox *cbTemporalEdgeFilter;
    QCheckBox *cbEdgeFilter;
    QCheckBox *cbInterferenceDetection;
    QLabel *lLimit;
    QCheckBox *cbTemporalFilter;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_8;
    QDoubleSpinBox *sbFactor;
    QLabel *lTemporalEdgeThresholdHigh;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *cbUseLastValue;
    QLabel *lFactor;
    QLabel *lThreshold;
    QCheckBox *cbAverageFilter;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_9;
    QLabel *lEdgeThreshold;
    QSpinBox *sbTemporalEdgeThresholdLow;
    QSpinBox *sbEdgeThreshold;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_4;
    QSpinBox *sbInterferenceDetectionLimit;
    QSpinBox *sbTemporalEdgeThresholdHigh;
    QSpinBox *sbThreshold;
    QCheckBox *cbMedianFilter;
    QSpacerItem *horizontalSpacer;
    QLabel *labelTitle;

    void setupUi(QWidget *WidgetSettingsFilter)
    {
        if (WidgetSettingsFilter->objectName().isEmpty())
            WidgetSettingsFilter->setObjectName(QString::fromUtf8("WidgetSettingsFilter"));
        WidgetSettingsFilter->resize(467, 224);
        WidgetSettingsFilter->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(WidgetSettingsFilter);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(0);
        gridLayout_2->setVerticalSpacing(5);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, -1, -1, -1);
        lTemporalEdgeThresholdLow = new QLabel(WidgetSettingsFilter);
        lTemporalEdgeThresholdLow->setObjectName(QString::fromUtf8("lTemporalEdgeThresholdLow"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lTemporalEdgeThresholdLow->sizePolicy().hasHeightForWidth());
        lTemporalEdgeThresholdLow->setSizePolicy(sizePolicy);
        lTemporalEdgeThresholdLow->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setPointSize(10);
        lTemporalEdgeThresholdLow->setFont(font);

        gridLayout->addWidget(lTemporalEdgeThresholdLow, 5, 2, 1, 1);

        cbTemporalEdgeFilter = new QCheckBox(WidgetSettingsFilter);
        cbTemporalEdgeFilter->setObjectName(QString::fromUtf8("cbTemporalEdgeFilter"));
        sizePolicy.setHeightForWidth(cbTemporalEdgeFilter->sizePolicy().hasHeightForWidth());
        cbTemporalEdgeFilter->setSizePolicy(sizePolicy);
        cbTemporalEdgeFilter->setMinimumSize(QSize(0, 0));
        cbTemporalEdgeFilter->setFont(font);

        gridLayout->addWidget(cbTemporalEdgeFilter, 5, 1, 1, 1);

        cbEdgeFilter = new QCheckBox(WidgetSettingsFilter);
        cbEdgeFilter->setObjectName(QString::fromUtf8("cbEdgeFilter"));
        sizePolicy.setHeightForWidth(cbEdgeFilter->sizePolicy().hasHeightForWidth());
        cbEdgeFilter->setSizePolicy(sizePolicy);
        cbEdgeFilter->setMinimumSize(QSize(0, 0));
        cbEdgeFilter->setFont(font);

        gridLayout->addWidget(cbEdgeFilter, 3, 1, 1, 1);

        cbInterferenceDetection = new QCheckBox(WidgetSettingsFilter);
        cbInterferenceDetection->setObjectName(QString::fromUtf8("cbInterferenceDetection"));
        sizePolicy.setHeightForWidth(cbInterferenceDetection->sizePolicy().hasHeightForWidth());
        cbInterferenceDetection->setSizePolicy(sizePolicy);
        cbInterferenceDetection->setMinimumSize(QSize(0, 0));
        cbInterferenceDetection->setFont(font);

        gridLayout->addWidget(cbInterferenceDetection, 6, 1, 1, 1);

        lLimit = new QLabel(WidgetSettingsFilter);
        lLimit->setObjectName(QString::fromUtf8("lLimit"));
        lLimit->setFont(font);

        gridLayout->addWidget(lLimit, 6, 2, 1, 1);

        cbTemporalFilter = new QCheckBox(WidgetSettingsFilter);
        cbTemporalFilter->setObjectName(QString::fromUtf8("cbTemporalFilter"));
        sizePolicy.setHeightForWidth(cbTemporalFilter->sizePolicy().hasHeightForWidth());
        cbTemporalFilter->setSizePolicy(sizePolicy);
        cbTemporalFilter->setMinimumSize(QSize(0, 0));
        cbTemporalFilter->setFont(font);

        gridLayout->addWidget(cbTemporalFilter, 4, 1, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_11, 2, 3, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 4, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 5, 5, 1, 1);

        sbFactor = new QDoubleSpinBox(WidgetSettingsFilter);
        sbFactor->setObjectName(QString::fromUtf8("sbFactor"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(sbFactor->sizePolicy().hasHeightForWidth());
        sbFactor->setSizePolicy(sizePolicy1);
        sbFactor->setMinimumSize(QSize(0, 0));
        sbFactor->setMaximumSize(QSize(16777215, 16777215));
        sbFactor->setFont(font);
        sbFactor->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbFactor->setMaximum(1.000000000000000);
        sbFactor->setSingleStep(0.100000000000000);

        gridLayout->addWidget(sbFactor, 4, 4, 1, 1);

        lTemporalEdgeThresholdHigh = new QLabel(WidgetSettingsFilter);
        lTemporalEdgeThresholdHigh->setObjectName(QString::fromUtf8("lTemporalEdgeThresholdHigh"));
        sizePolicy.setHeightForWidth(lTemporalEdgeThresholdHigh->sizePolicy().hasHeightForWidth());
        lTemporalEdgeThresholdHigh->setSizePolicy(sizePolicy);
        lTemporalEdgeThresholdHigh->setMinimumSize(QSize(0, 0));
        lTemporalEdgeThresholdHigh->setFont(font);

        gridLayout->addWidget(lTemporalEdgeThresholdHigh, 5, 6, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 4, 5, 1, 1);

        cbUseLastValue = new QCheckBox(WidgetSettingsFilter);
        cbUseLastValue->setObjectName(QString::fromUtf8("cbUseLastValue"));
        sizePolicy.setHeightForWidth(cbUseLastValue->sizePolicy().hasHeightForWidth());
        cbUseLastValue->setSizePolicy(sizePolicy);
        cbUseLastValue->setMinimumSize(QSize(0, 0));
        cbUseLastValue->setFont(font);

        gridLayout->addWidget(cbUseLastValue, 6, 6, 1, 3);

        lFactor = new QLabel(WidgetSettingsFilter);
        lFactor->setObjectName(QString::fromUtf8("lFactor"));
        sizePolicy.setHeightForWidth(lFactor->sizePolicy().hasHeightForWidth());
        lFactor->setSizePolicy(sizePolicy);
        lFactor->setMinimumSize(QSize(0, 0));
        lFactor->setFont(font);

        gridLayout->addWidget(lFactor, 4, 2, 1, 1);

        lThreshold = new QLabel(WidgetSettingsFilter);
        lThreshold->setObjectName(QString::fromUtf8("lThreshold"));
        sizePolicy.setHeightForWidth(lThreshold->sizePolicy().hasHeightForWidth());
        lThreshold->setSizePolicy(sizePolicy);
        lThreshold->setMinimumSize(QSize(0, 0));
        lThreshold->setFont(font);

        gridLayout->addWidget(lThreshold, 4, 6, 1, 1);

        cbAverageFilter = new QCheckBox(WidgetSettingsFilter);
        cbAverageFilter->setObjectName(QString::fromUtf8("cbAverageFilter"));
        sizePolicy.setHeightForWidth(cbAverageFilter->sizePolicy().hasHeightForWidth());
        cbAverageFilter->setSizePolicy(sizePolicy);
        cbAverageFilter->setMinimumSize(QSize(0, 0));
        cbAverageFilter->setFont(font);

        gridLayout->addWidget(cbAverageFilter, 2, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 4, 7, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 5, 10, 1, 1);

        lEdgeThreshold = new QLabel(WidgetSettingsFilter);
        lEdgeThreshold->setObjectName(QString::fromUtf8("lEdgeThreshold"));
        sizePolicy.setHeightForWidth(lEdgeThreshold->sizePolicy().hasHeightForWidth());
        lEdgeThreshold->setSizePolicy(sizePolicy);
        lEdgeThreshold->setMinimumSize(QSize(0, 0));
        lEdgeThreshold->setFont(font);

        gridLayout->addWidget(lEdgeThreshold, 3, 2, 1, 1);

        sbTemporalEdgeThresholdLow = new QSpinBox(WidgetSettingsFilter);
        sbTemporalEdgeThresholdLow->setObjectName(QString::fromUtf8("sbTemporalEdgeThresholdLow"));
        sizePolicy1.setHeightForWidth(sbTemporalEdgeThresholdLow->sizePolicy().hasHeightForWidth());
        sbTemporalEdgeThresholdLow->setSizePolicy(sizePolicy1);
        sbTemporalEdgeThresholdLow->setMinimumSize(QSize(0, 0));
        sbTemporalEdgeThresholdLow->setMaximumSize(QSize(16777215, 16777215));
        sbTemporalEdgeThresholdLow->setFont(font);
        sbTemporalEdgeThresholdLow->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbTemporalEdgeThresholdLow->setMaximum(5000);
        sbTemporalEdgeThresholdLow->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout->addWidget(sbTemporalEdgeThresholdLow, 5, 4, 1, 1);

        sbEdgeThreshold = new QSpinBox(WidgetSettingsFilter);
        sbEdgeThreshold->setObjectName(QString::fromUtf8("sbEdgeThreshold"));
        sizePolicy1.setHeightForWidth(sbEdgeThreshold->sizePolicy().hasHeightForWidth());
        sbEdgeThreshold->setSizePolicy(sizePolicy1);
        sbEdgeThreshold->setMinimumSize(QSize(0, 0));
        sbEdgeThreshold->setFont(font);
        sbEdgeThreshold->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbEdgeThreshold->setMaximum(5000);
        sbEdgeThreshold->setSingleStep(10);
        sbEdgeThreshold->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout->addWidget(sbEdgeThreshold, 3, 4, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 6, 10, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 4, 10, 1, 1);

        sbInterferenceDetectionLimit = new QSpinBox(WidgetSettingsFilter);
        sbInterferenceDetectionLimit->setObjectName(QString::fromUtf8("sbInterferenceDetectionLimit"));
        sizePolicy1.setHeightForWidth(sbInterferenceDetectionLimit->sizePolicy().hasHeightForWidth());
        sbInterferenceDetectionLimit->setSizePolicy(sizePolicy1);
        sbInterferenceDetectionLimit->setMinimumSize(QSize(0, 0));
        sbInterferenceDetectionLimit->setMaximumSize(QSize(16777215, 16777215));
        sbInterferenceDetectionLimit->setFont(font);
        sbInterferenceDetectionLimit->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbInterferenceDetectionLimit->setMaximum(5000);
        sbInterferenceDetectionLimit->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout->addWidget(sbInterferenceDetectionLimit, 6, 4, 1, 1);

        sbTemporalEdgeThresholdHigh = new QSpinBox(WidgetSettingsFilter);
        sbTemporalEdgeThresholdHigh->setObjectName(QString::fromUtf8("sbTemporalEdgeThresholdHigh"));
        sizePolicy1.setHeightForWidth(sbTemporalEdgeThresholdHigh->sizePolicy().hasHeightForWidth());
        sbTemporalEdgeThresholdHigh->setSizePolicy(sizePolicy1);
        sbTemporalEdgeThresholdHigh->setMinimumSize(QSize(0, 0));
        sbTemporalEdgeThresholdHigh->setFont(font);
        sbTemporalEdgeThresholdHigh->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbTemporalEdgeThresholdHigh->setMaximum(5000);
        sbTemporalEdgeThresholdHigh->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout->addWidget(sbTemporalEdgeThresholdHigh, 5, 8, 1, 1);

        sbThreshold = new QSpinBox(WidgetSettingsFilter);
        sbThreshold->setObjectName(QString::fromUtf8("sbThreshold"));
        sizePolicy1.setHeightForWidth(sbThreshold->sizePolicy().hasHeightForWidth());
        sbThreshold->setSizePolicy(sizePolicy1);
        sbThreshold->setMinimumSize(QSize(0, 0));
        sbThreshold->setFont(font);
        sbThreshold->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbThreshold->setMaximum(1000);
        sbThreshold->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout->addWidget(sbThreshold, 4, 8, 1, 1);

        cbMedianFilter = new QCheckBox(WidgetSettingsFilter);
        cbMedianFilter->setObjectName(QString::fromUtf8("cbMedianFilter"));
        sizePolicy.setHeightForWidth(cbMedianFilter->sizePolicy().hasHeightForWidth());
        cbMedianFilter->setSizePolicy(sizePolicy);
        cbMedianFilter->setMinimumSize(QSize(0, 0));
        cbMedianFilter->setFont(font);

        gridLayout->addWidget(cbMedianFilter, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 6, 5, 1, 1);

        labelTitle = new QLabel(WidgetSettingsFilter);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(255, 255, 255, 128));
        brush2.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush3(QColor(0, 0, 0, 128));
        brush3.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        labelTitle->setPalette(palette);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI Black"));
        font1.setBold(true);
        font1.setWeight(75);
        labelTitle->setFont(font1);
        labelTitle->setStyleSheet(QString::fromUtf8("padding:10px;\n"
"/*background-color:rgb(66, 138, 200);*/\n"
"/*background-color:rgb(76, 55, 108);*/\n"
"background-color:rgb(0,0,0);\n"
"color:rgb(255,255,255);\n"
""));

        gridLayout->addWidget(labelTitle, 0, 0, 1, 11);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(WidgetSettingsFilter);

        QMetaObject::connectSlotsByName(WidgetSettingsFilter);
    } // setupUi

    void retranslateUi(QWidget *WidgetSettingsFilter)
    {
        WidgetSettingsFilter->setWindowTitle(QCoreApplication::translate("WidgetSettingsFilter", "Form", nullptr));
        lTemporalEdgeThresholdLow->setText(QCoreApplication::translate("WidgetSettingsFilter", "Thresh. Low", nullptr));
#if QT_CONFIG(tooltip)
        cbTemporalEdgeFilter->setToolTip(QCoreApplication::translate("WidgetSettingsFilter", "<html><head/><body><p>Temporal edge filter</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbTemporalEdgeFilter->setText(QCoreApplication::translate("WidgetSettingsFilter", "Temp. Edge Filter", nullptr));
#if QT_CONFIG(tooltip)
        cbEdgeFilter->setToolTip(QCoreApplication::translate("WidgetSettingsFilter", "<html><head/><body><p>Edge filter</p><p>Implementation of the algorithm:</p><p><span style=\" color:#aa5500;\">diff = abs(data[x, y] - data[x+1, y])</span></p><p><span style=\" color:#aa5500;\">if (threshold &lt; diff)</span></p><p><span style=\" color:#aa5500;\">filter value</span></p><p><br/></p><p><span style=\" color:#000000;\">Do the same for y</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbEdgeFilter->setText(QCoreApplication::translate("WidgetSettingsFilter", "Edge Filter", nullptr));
#if QT_CONFIG(tooltip)
        cbInterferenceDetection->setToolTip(QCoreApplication::translate("WidgetSettingsFilter", "<html><head/><body><p>Interference detection</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbInterferenceDetection->setText(QCoreApplication::translate("WidgetSettingsFilter", "Interference Detect", nullptr));
        lLimit->setText(QCoreApplication::translate("WidgetSettingsFilter", "  Limit", nullptr));
#if QT_CONFIG(tooltip)
        cbTemporalFilter->setToolTip(QCoreApplication::translate("WidgetSettingsFilter", "<html><head/><body><p>Kalman filter</p><p>Implemented is a simplified Kalman filter with two parameters to filter the distance:</p><p>Factor k: Kalman gain which changes the filter sensitivity. The range is between 0 and 1, whereas the lower the figure, the better filtering, but the slower the output response.</p><p>Threshold t: Filtering applies as long as the difference of the current and the previous value is below this value. If the difference is greater than this value, the filter is reset and start iterating at the new level. This parameter is used to reduce the response time on a large distance step.</p><p>Implementation of the algorithm:</p><p><span style=\" color:#aa5500;\">if (x[i]\342\200\223x[i-1]&lt;t)</span></p><p><span style=\" color:#aa5500;\">x[i]=k*x[i]+(1\342\200\223k)*x[i-1];</span></p><p>Whereas:</p><p>x[i]: Current measured value</p><p>x[i-1]: Previous measured value</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbTemporalFilter->setText(QCoreApplication::translate("WidgetSettingsFilter", "Temporal  Filter", nullptr));
#if QT_CONFIG(tooltip)
        sbFactor->setToolTip(QCoreApplication::translate("WidgetSettingsFilter", "<html><head/><body><p>Kalman temporal filter gain factor K, where K = [0 ... 1].</p><p>y = K * y + (1-K) * x, y - the last measured value. x - the value before the last measured value. if K small - filtering strong, reaction slow. If K big - filtering weak, reaction fast.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lTemporalEdgeThresholdHigh->setText(QCoreApplication::translate("WidgetSettingsFilter", "Thresh. High", nullptr));
        cbUseLastValue->setText(QCoreApplication::translate("WidgetSettingsFilter", "Use Last Value", nullptr));
        lFactor->setText(QCoreApplication::translate("WidgetSettingsFilter", "Factor", nullptr));
        lThreshold->setText(QCoreApplication::translate("WidgetSettingsFilter", "Threshold", nullptr));
#if QT_CONFIG(tooltip)
        cbAverageFilter->setToolTip(QCoreApplication::translate("WidgetSettingsFilter", "<html><head/><body><p>Average Filter on distance level</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbAverageFilter->setText(QCoreApplication::translate("WidgetSettingsFilter", "Average Filter", nullptr));
        lEdgeThreshold->setText(QCoreApplication::translate("WidgetSettingsFilter", "Threshold", nullptr));
#if QT_CONFIG(tooltip)
        sbTemporalEdgeThresholdLow->setToolTip(QCoreApplication::translate("WidgetSettingsFilter", "<html><head/><body><p>Low threshold in mm of temporal edge filter</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        sbTemporalEdgeThresholdLow->setSuffix(QCoreApplication::translate("WidgetSettingsFilter", "mm ", nullptr));
#if QT_CONFIG(tooltip)
        sbEdgeThreshold->setToolTip(QCoreApplication::translate("WidgetSettingsFilter", "<html><head/><body><p>Edge filter threshold in mm</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        sbEdgeThreshold->setSuffix(QCoreApplication::translate("WidgetSettingsFilter", "mm", nullptr));
#if QT_CONFIG(tooltip)
        sbInterferenceDetectionLimit->setToolTip(QCoreApplication::translate("WidgetSettingsFilter", "<html><head/><body><p>Limit of interference detection</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        sbInterferenceDetectionLimit->setSuffix(QCoreApplication::translate("WidgetSettingsFilter", "LSB", nullptr));
        sbInterferenceDetectionLimit->setPrefix(QString());
#if QT_CONFIG(tooltip)
        sbTemporalEdgeThresholdHigh->setToolTip(QCoreApplication::translate("WidgetSettingsFilter", "<html><head/><body><p>High threshold in mm of temporal edge filter</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        sbTemporalEdgeThresholdHigh->setSuffix(QCoreApplication::translate("WidgetSettingsFilter", "mm", nullptr));
#if QT_CONFIG(tooltip)
        sbThreshold->setToolTip(QCoreApplication::translate("WidgetSettingsFilter", "<html><head/><body><p>Set signal step threshold in mm to reset Kalman filter prediction. Filter is active if the changing of signal is below threshold.</p><p>If Threshold == 0, the filter is off.</p><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        sbThreshold->setSuffix(QCoreApplication::translate("WidgetSettingsFilter", "mm", nullptr));
#if QT_CONFIG(tooltip)
        cbMedianFilter->setToolTip(QCoreApplication::translate("WidgetSettingsFilter", "<html><head/><body><p>Median filter on distance</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbMedianFilter->setText(QCoreApplication::translate("WidgetSettingsFilter", "Median Filter", nullptr));
        labelTitle->setText(QCoreApplication::translate("WidgetSettingsFilter", "<html><head/><body><p>FILTER SETTINGS</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetSettingsFilter: public Ui_WidgetSettingsFilter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_SETTINGS_FILTER_H
