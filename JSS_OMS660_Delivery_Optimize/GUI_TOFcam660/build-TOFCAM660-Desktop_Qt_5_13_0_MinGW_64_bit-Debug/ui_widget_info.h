/********************************************************************************
** Form generated from reading UI file 'widget_info.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_INFO_H
#define UI_WIDGET_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetInfo
{
public:
    QGridLayout *gridLayout;
    QWidget *widget_9;
    QGridLayout *gridLayout_9;
    QWidget *widgetDistanceAmplitude;
    QGridLayout *gridLayout_11;
    QWidget *widget_7;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_10;
    QLabel *labelNameLeft;
    QLabel *lMaxTitle;
    QLabel *lDistanceVariationTitle;
    QLabel *labelNameRight;
    QSpacerItem *horizontalSpacer_8;
    QLabel *labelCurrentRight;
    QLabel *lCurrentTitle;
    QLabel *lMinTitle;
    QLabel *lAverageTitle;
    QLabel *labelCurrentLeft;
    QLabel *labelVariationRight;
    QLabel *labelVariationLeft;
    QLabel *labelMaximumRight;
    QLabel *labelMaximumLeft;
    QLabel *labelMinimumRight;
    QLabel *labelMinimumLeft;
    QLabel *labelAverageLeft;
    QLabel *labelAverageRight;
    QLabel *labelStatistics;
    QWidget *widgetDCS;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_12;
    QLabel *lDCS0;
    QLabel *labelDCS0;
    QLabel *labelDCS3;
    QLabel *labelDCS1;
    QLabel *lDCS2;
    QLabel *labelDCS2;
    QLabel *lDCS3;
    QLabel *lDCS1;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QLabel *labelHeader;
    QWidget *widget;
    QGridLayout *gridLayout_8;
    QLabel *labelTemperature;
    QFrame *lineH;
    QLabel *labelSelect;
    QFrame *line;
    QLabel *labelFrameRate;
    QLabel *labelReset;

    void setupUi(QWidget *WidgetInfo)
    {
        if (WidgetInfo->objectName().isEmpty())
            WidgetInfo->setObjectName(QString::fromUtf8("WidgetInfo"));
        WidgetInfo->resize(244, 367);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WidgetInfo->sizePolicy().hasHeightForWidth());
        WidgetInfo->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(WidgetInfo);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, -1, 0, 0);
        widget_9 = new QWidget(WidgetInfo);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(widget_9->sizePolicy().hasHeightForWidth());
        widget_9->setSizePolicy(sizePolicy1);
        gridLayout_9 = new QGridLayout(widget_9);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        widgetDistanceAmplitude = new QWidget(widget_9);
        widgetDistanceAmplitude->setObjectName(QString::fromUtf8("widgetDistanceAmplitude"));
        gridLayout_11 = new QGridLayout(widgetDistanceAmplitude);
        gridLayout_11->setSpacing(0);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        widget_7 = new QWidget(widgetDistanceAmplitude);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        gridLayout_6 = new QGridLayout(widget_7);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        gridLayout_10 = new QGridLayout();
        gridLayout_10->setSpacing(10);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(-1, 0, -1, -1);
        labelNameLeft = new QLabel(widget_7);
        labelNameLeft->setObjectName(QString::fromUtf8("labelNameLeft"));
        labelNameLeft->setMinimumSize(QSize(60, 0));
        labelNameLeft->setMaximumSize(QSize(16777215, 16777215));
        labelNameLeft->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_10->addWidget(labelNameLeft, 1, 1, 1, 1);

        lMaxTitle = new QLabel(widget_7);
        lMaxTitle->setObjectName(QString::fromUtf8("lMaxTitle"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lMaxTitle->sizePolicy().hasHeightForWidth());
        lMaxTitle->setSizePolicy(sizePolicy2);
        lMaxTitle->setMinimumSize(QSize(0, 0));
        lMaxTitle->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_10->addWidget(lMaxTitle, 5, 0, 1, 1);

        lDistanceVariationTitle = new QLabel(widget_7);
        lDistanceVariationTitle->setObjectName(QString::fromUtf8("lDistanceVariationTitle"));
        lDistanceVariationTitle->setMinimumSize(QSize(50, 0));
        lDistanceVariationTitle->setMaximumSize(QSize(50, 16777215));

        gridLayout_10->addWidget(lDistanceVariationTitle, 6, 0, 1, 1);

        labelNameRight = new QLabel(widget_7);
        labelNameRight->setObjectName(QString::fromUtf8("labelNameRight"));
        labelNameRight->setMinimumSize(QSize(70, 0));
        labelNameRight->setMaximumSize(QSize(16777215, 16777215));
        labelNameRight->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_10->addWidget(labelNameRight, 1, 2, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_8, 1, 0, 1, 1);

        labelCurrentRight = new QLabel(widget_7);
        labelCurrentRight->setObjectName(QString::fromUtf8("labelCurrentRight"));
        labelCurrentRight->setMinimumSize(QSize(60, 0));
        labelCurrentRight->setMaximumSize(QSize(16777215, 16777215));
        labelCurrentRight->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_10->addWidget(labelCurrentRight, 2, 2, 1, 1);

        lCurrentTitle = new QLabel(widget_7);
        lCurrentTitle->setObjectName(QString::fromUtf8("lCurrentTitle"));
        sizePolicy2.setHeightForWidth(lCurrentTitle->sizePolicy().hasHeightForWidth());
        lCurrentTitle->setSizePolicy(sizePolicy2);
        lCurrentTitle->setMinimumSize(QSize(0, 0));
        lCurrentTitle->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_10->addWidget(lCurrentTitle, 2, 0, 1, 1);

        lMinTitle = new QLabel(widget_7);
        lMinTitle->setObjectName(QString::fromUtf8("lMinTitle"));
        sizePolicy2.setHeightForWidth(lMinTitle->sizePolicy().hasHeightForWidth());
        lMinTitle->setSizePolicy(sizePolicy2);
        lMinTitle->setMinimumSize(QSize(50, 0));
        lMinTitle->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_10->addWidget(lMinTitle, 4, 0, 1, 1);

        lAverageTitle = new QLabel(widget_7);
        lAverageTitle->setObjectName(QString::fromUtf8("lAverageTitle"));
        sizePolicy2.setHeightForWidth(lAverageTitle->sizePolicy().hasHeightForWidth());
        lAverageTitle->setSizePolicy(sizePolicy2);
        lAverageTitle->setMinimumSize(QSize(0, 0));
        lAverageTitle->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_10->addWidget(lAverageTitle, 3, 0, 1, 1);

        labelCurrentLeft = new QLabel(widget_7);
        labelCurrentLeft->setObjectName(QString::fromUtf8("labelCurrentLeft"));
        labelCurrentLeft->setMinimumSize(QSize(60, 0));
        labelCurrentLeft->setMaximumSize(QSize(16777215, 16777215));
        labelCurrentLeft->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_10->addWidget(labelCurrentLeft, 2, 1, 1, 1);

        labelVariationRight = new QLabel(widget_7);
        labelVariationRight->setObjectName(QString::fromUtf8("labelVariationRight"));
        sizePolicy2.setHeightForWidth(labelVariationRight->sizePolicy().hasHeightForWidth());
        labelVariationRight->setSizePolicy(sizePolicy2);
        labelVariationRight->setMinimumSize(QSize(60, 0));
        labelVariationRight->setMaximumSize(QSize(16777215, 16777215));
        labelVariationRight->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_10->addWidget(labelVariationRight, 6, 2, 1, 1);

        labelVariationLeft = new QLabel(widget_7);
        labelVariationLeft->setObjectName(QString::fromUtf8("labelVariationLeft"));
        sizePolicy2.setHeightForWidth(labelVariationLeft->sizePolicy().hasHeightForWidth());
        labelVariationLeft->setSizePolicy(sizePolicy2);
        labelVariationLeft->setMinimumSize(QSize(60, 0));
        labelVariationLeft->setMaximumSize(QSize(16777215, 16777215));
        labelVariationLeft->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_10->addWidget(labelVariationLeft, 6, 1, 1, 1);

        labelMaximumRight = new QLabel(widget_7);
        labelMaximumRight->setObjectName(QString::fromUtf8("labelMaximumRight"));
        labelMaximumRight->setMinimumSize(QSize(60, 0));
        labelMaximumRight->setMaximumSize(QSize(16777215, 16777215));
        labelMaximumRight->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_10->addWidget(labelMaximumRight, 5, 2, 1, 1);

        labelMaximumLeft = new QLabel(widget_7);
        labelMaximumLeft->setObjectName(QString::fromUtf8("labelMaximumLeft"));
        labelMaximumLeft->setMinimumSize(QSize(60, 0));
        labelMaximumLeft->setMaximumSize(QSize(16777215, 16777215));
        labelMaximumLeft->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_10->addWidget(labelMaximumLeft, 5, 1, 1, 1);

        labelMinimumRight = new QLabel(widget_7);
        labelMinimumRight->setObjectName(QString::fromUtf8("labelMinimumRight"));
        labelMinimumRight->setMinimumSize(QSize(60, 0));
        labelMinimumRight->setMaximumSize(QSize(16777215, 16777215));
        labelMinimumRight->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_10->addWidget(labelMinimumRight, 4, 2, 1, 1);

        labelMinimumLeft = new QLabel(widget_7);
        labelMinimumLeft->setObjectName(QString::fromUtf8("labelMinimumLeft"));
        labelMinimumLeft->setMinimumSize(QSize(60, 0));
        labelMinimumLeft->setMaximumSize(QSize(16777215, 16777215));
        labelMinimumLeft->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_10->addWidget(labelMinimumLeft, 4, 1, 1, 1);

        labelAverageLeft = new QLabel(widget_7);
        labelAverageLeft->setObjectName(QString::fromUtf8("labelAverageLeft"));
        labelAverageLeft->setMinimumSize(QSize(60, 0));
        labelAverageLeft->setMaximumSize(QSize(16777215, 16777215));
        labelAverageLeft->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_10->addWidget(labelAverageLeft, 3, 1, 1, 1);

        labelAverageRight = new QLabel(widget_7);
        labelAverageRight->setObjectName(QString::fromUtf8("labelAverageRight"));
        labelAverageRight->setMinimumSize(QSize(60, 0));
        labelAverageRight->setMaximumSize(QSize(16777215, 16777215));
        labelAverageRight->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_10->addWidget(labelAverageRight, 3, 2, 1, 1);

        labelStatistics = new QLabel(widget_7);
        labelStatistics->setObjectName(QString::fromUtf8("labelStatistics"));

        gridLayout_10->addWidget(labelStatistics, 0, 0, 1, 2);


        gridLayout_6->addLayout(gridLayout_10, 0, 0, 1, 3);


        gridLayout_11->addWidget(widget_7, 0, 0, 1, 1);


        gridLayout_9->addWidget(widgetDistanceAmplitude, 0, 0, 1, 1);

        widgetDCS = new QWidget(widget_9);
        widgetDCS->setObjectName(QString::fromUtf8("widgetDCS"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widgetDCS->sizePolicy().hasHeightForWidth());
        widgetDCS->setSizePolicy(sizePolicy3);
        widgetDCS->setMinimumSize(QSize(0, 0));
        gridLayout_5 = new QGridLayout(widgetDCS);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 10, 0, 10);
        gridLayout_12 = new QGridLayout();
        gridLayout_12->setSpacing(10);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_12->setContentsMargins(-1, 0, -1, 0);
        lDCS0 = new QLabel(widgetDCS);
        lDCS0->setObjectName(QString::fromUtf8("lDCS0"));

        gridLayout_12->addWidget(lDCS0, 0, 1, 1, 1);

        labelDCS0 = new QLabel(widgetDCS);
        labelDCS0->setObjectName(QString::fromUtf8("labelDCS0"));

        gridLayout_12->addWidget(labelDCS0, 0, 0, 1, 1);

        labelDCS3 = new QLabel(widgetDCS);
        labelDCS3->setObjectName(QString::fromUtf8("labelDCS3"));

        gridLayout_12->addWidget(labelDCS3, 1, 3, 1, 1);

        labelDCS1 = new QLabel(widgetDCS);
        labelDCS1->setObjectName(QString::fromUtf8("labelDCS1"));

        gridLayout_12->addWidget(labelDCS1, 1, 0, 1, 1);

        lDCS2 = new QLabel(widgetDCS);
        lDCS2->setObjectName(QString::fromUtf8("lDCS2"));

        gridLayout_12->addWidget(lDCS2, 0, 4, 1, 1);

        labelDCS2 = new QLabel(widgetDCS);
        labelDCS2->setObjectName(QString::fromUtf8("labelDCS2"));

        gridLayout_12->addWidget(labelDCS2, 0, 3, 1, 1);

        lDCS3 = new QLabel(widgetDCS);
        lDCS3->setObjectName(QString::fromUtf8("lDCS3"));

        gridLayout_12->addWidget(lDCS3, 1, 4, 1, 1);

        lDCS1 = new QLabel(widgetDCS);
        lDCS1->setObjectName(QString::fromUtf8("lDCS1"));

        gridLayout_12->addWidget(lDCS1, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_12->addItem(horizontalSpacer, 0, 2, 1, 1);


        gridLayout_5->addLayout(gridLayout_12, 0, 0, 1, 4);


        gridLayout_9->addWidget(widgetDCS, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_9->addItem(verticalSpacer, 1, 0, 1, 1);


        gridLayout->addWidget(widget_9, 1, 0, 1, 1);

        labelHeader = new QLabel(WidgetInfo);
        labelHeader->setObjectName(QString::fromUtf8("labelHeader"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        labelHeader->setFont(font);
        labelHeader->setStyleSheet(QString::fromUtf8("background-color:rgb(41, 87, 126);\n"
"color:rgb(255, 255, 255);"));
        labelHeader->setMargin(5);

        gridLayout->addWidget(labelHeader, 0, 0, 1, 1);

        widget = new QWidget(WidgetInfo);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_8 = new QGridLayout(widget);
        gridLayout_8->setSpacing(0);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(5, 0, 0, 0);
        labelTemperature = new QLabel(widget);
        labelTemperature->setObjectName(QString::fromUtf8("labelTemperature"));

        gridLayout_8->addWidget(labelTemperature, 1, 0, 1, 1);

        lineH = new QFrame(widget);
        lineH->setObjectName(QString::fromUtf8("lineH"));
        lineH->setFrameShape(QFrame::HLine);
        lineH->setFrameShadow(QFrame::Sunken);

        gridLayout_8->addWidget(lineH, 0, 0, 1, 1);

        labelSelect = new QLabel(widget);
        labelSelect->setObjectName(QString::fromUtf8("labelSelect"));

        gridLayout_8->addWidget(labelSelect, 4, 0, 1, 1);

        line = new QFrame(widget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_8->addWidget(line, 3, 0, 1, 1);

        labelFrameRate = new QLabel(widget);
        labelFrameRate->setObjectName(QString::fromUtf8("labelFrameRate"));

        gridLayout_8->addWidget(labelFrameRate, 2, 0, 1, 1);

        labelReset = new QLabel(widget);
        labelReset->setObjectName(QString::fromUtf8("labelReset"));
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(labelReset->sizePolicy().hasHeightForWidth());
        labelReset->setSizePolicy(sizePolicy4);

        gridLayout_8->addWidget(labelReset, 5, 0, 1, 1);


        gridLayout->addWidget(widget, 4, 0, 1, 1);


        retranslateUi(WidgetInfo);

        QMetaObject::connectSlotsByName(WidgetInfo);
    } // setupUi

    void retranslateUi(QWidget *WidgetInfo)
    {
        WidgetInfo->setWindowTitle(QCoreApplication::translate("WidgetInfo", "Info", nullptr));
        labelNameLeft->setText(QCoreApplication::translate("WidgetInfo", "Distance:", nullptr));
        lMaxTitle->setText(QCoreApplication::translate("WidgetInfo", "Maximum:", nullptr));
#if QT_CONFIG(tooltip)
        lDistanceVariationTitle->setToolTip(QCoreApplication::translate("WidgetInfo", "<html><head/><body><p><span style=\" font-size:10pt;\">Standart deviation from 100 values</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lDistanceVariationTitle->setText(QCoreApplication::translate("WidgetInfo", "\317\203:", nullptr));
        labelNameRight->setText(QCoreApplication::translate("WidgetInfo", "Confidence:", nullptr));
        labelCurrentRight->setText(QString());
        lCurrentTitle->setText(QCoreApplication::translate("WidgetInfo", "Current:", nullptr));
        lMinTitle->setText(QCoreApplication::translate("WidgetInfo", "Minimum:", nullptr));
        lAverageTitle->setText(QCoreApplication::translate("WidgetInfo", "Average:", nullptr));
        labelCurrentLeft->setText(QString());
        labelVariationRight->setText(QString());
        labelVariationLeft->setText(QString());
        labelMaximumRight->setText(QString());
        labelMaximumLeft->setText(QString());
        labelMinimumRight->setText(QString());
        labelMinimumLeft->setText(QString());
        labelAverageLeft->setText(QString());
        labelAverageRight->setText(QString());
        labelStatistics->setText(QCoreApplication::translate("WidgetInfo", "Statistics over  100 samples", nullptr));
        lDCS0->setText(QCoreApplication::translate("WidgetInfo", "0", nullptr));
        labelDCS0->setText(QCoreApplication::translate("WidgetInfo", "DCS0:", nullptr));
        labelDCS3->setText(QCoreApplication::translate("WidgetInfo", "DCS3:", nullptr));
        labelDCS1->setText(QCoreApplication::translate("WidgetInfo", "DCS1:", nullptr));
        lDCS2->setText(QCoreApplication::translate("WidgetInfo", "0", nullptr));
        labelDCS2->setText(QCoreApplication::translate("WidgetInfo", "DCS2:", nullptr));
        lDCS3->setText(QCoreApplication::translate("WidgetInfo", "0", nullptr));
        lDCS1->setText(QCoreApplication::translate("WidgetInfo", "0", nullptr));
        labelHeader->setText(QCoreApplication::translate("WidgetInfo", "Pixel data(x, y)", nullptr));
        labelTemperature->setText(QCoreApplication::translate("WidgetInfo", "Temperature:", nullptr));
        labelSelect->setText(QCoreApplication::translate("WidgetInfo", "Select: Ctrl + left mouse button", nullptr));
        labelFrameRate->setText(QCoreApplication::translate("WidgetInfo", "Frame rate:", nullptr));
        labelReset->setText(QCoreApplication::translate("WidgetInfo", "Deselect: Ctrl + right mouse button", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetInfo: public Ui_WidgetInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_INFO_H
