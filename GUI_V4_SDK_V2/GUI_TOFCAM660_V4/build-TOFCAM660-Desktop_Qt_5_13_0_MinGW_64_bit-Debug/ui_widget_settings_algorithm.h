/********************************************************************************
** Form generated from reading UI file 'widget_settings_algorithm.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_SETTINGS_ALGORITHM_H
#define UI_WIDGET_SETTINGS_ALGORITHM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetSettingsAlgorithm
{
public:
    QGridLayout *gridLayout_2;
    QLabel *labelAlgorithms;
    QGridLayout *gridLayout;
    QLabel *lMDAImageType;
    QCheckBox *cbMovementDetectionAlgorithm;
    QLabel *lMDAWindowSize;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *cbSkeletonDetectionAlgorithm;
    QComboBox *comboboxMDAImageType;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QSpinBox *sbMDAWindowSize;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *WidgetSettingsAlgorithm)
    {
        if (WidgetSettingsAlgorithm->objectName().isEmpty())
            WidgetSettingsAlgorithm->setObjectName(QString::fromUtf8("WidgetSettingsAlgorithm"));
        WidgetSettingsAlgorithm->resize(547, 236);
        WidgetSettingsAlgorithm->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(WidgetSettingsAlgorithm);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(0);
        gridLayout_2->setVerticalSpacing(5);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        labelAlgorithms = new QLabel(WidgetSettingsAlgorithm);
        labelAlgorithms->setObjectName(QString::fromUtf8("labelAlgorithms"));
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
        labelAlgorithms->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI Black"));
        font.setBold(true);
        font.setWeight(75);
        labelAlgorithms->setFont(font);
        labelAlgorithms->setStyleSheet(QString::fromUtf8("padding:10px;\n"
"/*background-color:rgb(66, 138, 200);*/\n"
"/*background-color:rgb(76, 55, 108);*/\n"
"background-color:rgb(0,0,0);\n"
"color:rgb(255,255,255);\n"
""));

        gridLayout_2->addWidget(labelAlgorithms, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lMDAImageType = new QLabel(WidgetSettingsAlgorithm);
        lMDAImageType->setObjectName(QString::fromUtf8("lMDAImageType"));

        gridLayout->addWidget(lMDAImageType, 1, 6, 1, 1);

        cbMovementDetectionAlgorithm = new QCheckBox(WidgetSettingsAlgorithm);
        cbMovementDetectionAlgorithm->setObjectName(QString::fromUtf8("cbMovementDetectionAlgorithm"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cbMovementDetectionAlgorithm->sizePolicy().hasHeightForWidth());
        cbMovementDetectionAlgorithm->setSizePolicy(sizePolicy);
        cbMovementDetectionAlgorithm->setMinimumSize(QSize(0, 0));
        QFont font1;
        font1.setPointSize(10);
        cbMovementDetectionAlgorithm->setFont(font1);

        gridLayout->addWidget(cbMovementDetectionAlgorithm, 1, 1, 1, 1);

        lMDAWindowSize = new QLabel(WidgetSettingsAlgorithm);
        lMDAWindowSize->setObjectName(QString::fromUtf8("lMDAWindowSize"));

        gridLayout->addWidget(lMDAWindowSize, 1, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        cbSkeletonDetectionAlgorithm = new QCheckBox(WidgetSettingsAlgorithm);
        cbSkeletonDetectionAlgorithm->setObjectName(QString::fromUtf8("cbSkeletonDetectionAlgorithm"));
        sizePolicy.setHeightForWidth(cbSkeletonDetectionAlgorithm->sizePolicy().hasHeightForWidth());
        cbSkeletonDetectionAlgorithm->setSizePolicy(sizePolicy);
        cbSkeletonDetectionAlgorithm->setMinimumSize(QSize(0, 0));
        cbSkeletonDetectionAlgorithm->setFont(font1);

        gridLayout->addWidget(cbSkeletonDetectionAlgorithm, 0, 1, 1, 3);

        comboboxMDAImageType = new QComboBox(WidgetSettingsAlgorithm);
        comboboxMDAImageType->addItem(QString());
        comboboxMDAImageType->addItem(QString());
        comboboxMDAImageType->addItem(QString());
        comboboxMDAImageType->setObjectName(QString::fromUtf8("comboboxMDAImageType"));

        gridLayout->addWidget(comboboxMDAImageType, 1, 7, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 1, 8, 1, 1);

        horizontalSpacer = new QSpacerItem(13, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 5, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        sbMDAWindowSize = new QSpinBox(WidgetSettingsAlgorithm);
        sbMDAWindowSize->setObjectName(QString::fromUtf8("sbMDAWindowSize"));

        gridLayout->addWidget(sbMDAWindowSize, 1, 4, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);


        retranslateUi(WidgetSettingsAlgorithm);

        QMetaObject::connectSlotsByName(WidgetSettingsAlgorithm);
    } // setupUi

    void retranslateUi(QWidget *WidgetSettingsAlgorithm)
    {
        WidgetSettingsAlgorithm->setWindowTitle(QCoreApplication::translate("WidgetSettingsAlgorithm", "Form", nullptr));
        labelAlgorithms->setText(QCoreApplication::translate("WidgetSettingsAlgorithm", "<html><head/><body><p>ALGORITHM SETTINGS</p></body></html>", nullptr));
        lMDAImageType->setText(QCoreApplication::translate("WidgetSettingsAlgorithm", "Image Type", nullptr));
#if QT_CONFIG(tooltip)
        cbMovementDetectionAlgorithm->setToolTip(QCoreApplication::translate("WidgetSettingsAlgorithm", "<html><head/><body><p>Edge filter</p><p>Implementation of the algorithm:</p><p><span style=\" color:#aa5500;\">diff = abs(data[x, y] - data[x+1, y])</span></p><p><span style=\" color:#aa5500;\">if (threshold &lt; diff)</span></p><p><span style=\" color:#aa5500;\">filter value</span></p><p><br/></p><p><span style=\" color:#000000;\">Do the same for y</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbMovementDetectionAlgorithm->setText(QCoreApplication::translate("WidgetSettingsAlgorithm", "Movement Detection", nullptr));
        lMDAWindowSize->setText(QCoreApplication::translate("WidgetSettingsAlgorithm", "Window Size", nullptr));
#if QT_CONFIG(tooltip)
        cbSkeletonDetectionAlgorithm->setToolTip(QCoreApplication::translate("WidgetSettingsAlgorithm", "<html><head/><body><p>Kalman filter</p><p>Implemented is a simplified Kalman filter with two parameters to filter the distance:</p><p>Factor k: Kalman gain which changes the filter sensitivity. The range is between 0 and 1, whereas the lower the figure, the better filtering, but the slower the output response.</p><p>Threshold t: Filtering applies as long as the difference of the current and the previous value is below this value. If the difference is greater than this value, the filter is reset and start iterating at the new level. This parameter is used to reduce the response time on a large distance step.</p><p>Implementation of the algorithm:</p><p><span style=\" color:#aa5500;\">if (x[i]\342\200\223x[i-1]&lt;t)</span></p><p><span style=\" color:#aa5500;\">x[i]=k*x[i]+(1\342\200\223k)*x[i-1];</span></p><p>Whereas:</p><p>x[i]: Current measured value</p><p>x[i-1]: Previous measured value</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbSkeletonDetectionAlgorithm->setText(QCoreApplication::translate("WidgetSettingsAlgorithm", "Skeleton Detection", nullptr));
        comboboxMDAImageType->setItemText(0, QCoreApplication::translate("WidgetSettingsAlgorithm", "Amplitude", nullptr));
        comboboxMDAImageType->setItemText(1, QCoreApplication::translate("WidgetSettingsAlgorithm", "Distance", nullptr));
        comboboxMDAImageType->setItemText(2, QCoreApplication::translate("WidgetSettingsAlgorithm", "Distance & Amplitude", nullptr));

    } // retranslateUi

};

namespace Ui {
    class WidgetSettingsAlgorithm: public Ui_WidgetSettingsAlgorithm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_SETTINGS_ALGORITHM_H
