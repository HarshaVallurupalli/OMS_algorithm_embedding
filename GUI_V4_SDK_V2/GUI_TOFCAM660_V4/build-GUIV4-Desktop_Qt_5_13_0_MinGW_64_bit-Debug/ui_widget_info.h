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
    QLabel *labelHeader;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_2;
    QGridLayout *gridLayout_5;
    QWidget *widget_6;
    QGridLayout *gridLayout_11;
    QWidget *widget_3;
    QGridLayout *gridLayout_2;
    QLabel *labelCurrentLeft;
    QLabel *lCurrentTitle;
    QLabel *labelCurrentRight;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_4;
    QGridLayout *gridLayout_3;
    QLabel *labelMinimumRight;
    QLabel *lMinTitle;
    QLabel *labelMinimumLeft;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widget_5;
    QGridLayout *gridLayout_4;
    QLabel *labelMaximumRight;
    QLabel *lMaxTitle;
    QLabel *labelMaximumLeft;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_12;
    QGridLayout *gridLayout_13;
    QLabel *labelAverageRight;
    QLabel *lAverageTitle;
    QLabel *labelAverageLeft;
    QSpacerItem *horizontalSpacer_6;
    QWidget *widget_7;
    QGridLayout *gridLayout_6;
    QSpacerItem *horizontalSpacer_8;
    QLabel *labelNameRight;
    QLabel *labelNameLeft;
    QLabel *labelStatistics;
    QWidget *widget_8;
    QGridLayout *gridLayout_7;
    QLabel *labelVariationLeft;
    QLabel *labelVariationRight;
    QSpacerItem *horizontalSpacer_9;
    QLabel *lDistanceVariationTitle;
    QWidget *widget;
    QGridLayout *gridLayout_8;
    QLabel *labelFrameRate;
    QLabel *labelSelect;
    QFrame *lineH;
    QLabel *labelReset;
    QLabel *labelTemperature;
    QFrame *line;

    void setupUi(QWidget *WidgetInfo)
    {
        if (WidgetInfo->objectName().isEmpty())
            WidgetInfo->setObjectName(QString::fromUtf8("WidgetInfo"));
        WidgetInfo->resize(320, 265);
        gridLayout = new QGridLayout(WidgetInfo);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, -1, 0, 0);
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

        verticalSpacer_2 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 0, 1, 1);

        widget_2 = new QWidget(WidgetInfo);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        gridLayout_5 = new QGridLayout(widget_2);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(5, 0, 5, 0);
        widget_6 = new QWidget(widget_2);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        gridLayout_11 = new QGridLayout(widget_6);
        gridLayout_11->setSpacing(0);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(widget_6);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(widget_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(6);
        gridLayout_2->setContentsMargins(5, 0, 0, 0);
        labelCurrentLeft = new QLabel(widget_3);
        labelCurrentLeft->setObjectName(QString::fromUtf8("labelCurrentLeft"));
        labelCurrentLeft->setMinimumSize(QSize(60, 0));
        labelCurrentLeft->setMaximumSize(QSize(16777215, 16777215));
        labelCurrentLeft->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(labelCurrentLeft, 0, 2, 1, 1);

        lCurrentTitle = new QLabel(widget_3);
        lCurrentTitle->setObjectName(QString::fromUtf8("lCurrentTitle"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lCurrentTitle->sizePolicy().hasHeightForWidth());
        lCurrentTitle->setSizePolicy(sizePolicy1);
        lCurrentTitle->setMinimumSize(QSize(0, 0));
        lCurrentTitle->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(lCurrentTitle, 0, 0, 1, 1);

        labelCurrentRight = new QLabel(widget_3);
        labelCurrentRight->setObjectName(QString::fromUtf8("labelCurrentRight"));
        labelCurrentRight->setMinimumSize(QSize(60, 0));
        labelCurrentRight->setMaximumSize(QSize(16777215, 16777215));
        labelCurrentRight->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(labelCurrentRight, 0, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 1, 1, 1);


        gridLayout_11->addWidget(widget_3, 1, 0, 1, 1);

        widget_4 = new QWidget(widget_6);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        gridLayout_3 = new QGridLayout(widget_4);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(5, 0, 0, 0);
        labelMinimumRight = new QLabel(widget_4);
        labelMinimumRight->setObjectName(QString::fromUtf8("labelMinimumRight"));
        labelMinimumRight->setMinimumSize(QSize(60, 0));
        labelMinimumRight->setMaximumSize(QSize(16777215, 16777215));
        labelMinimumRight->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(labelMinimumRight, 0, 3, 1, 1);

        lMinTitle = new QLabel(widget_4);
        lMinTitle->setObjectName(QString::fromUtf8("lMinTitle"));
        sizePolicy1.setHeightForWidth(lMinTitle->sizePolicy().hasHeightForWidth());
        lMinTitle->setSizePolicy(sizePolicy1);
        lMinTitle->setMinimumSize(QSize(50, 0));
        lMinTitle->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(lMinTitle, 0, 0, 1, 1);

        labelMinimumLeft = new QLabel(widget_4);
        labelMinimumLeft->setObjectName(QString::fromUtf8("labelMinimumLeft"));
        labelMinimumLeft->setMinimumSize(QSize(60, 0));
        labelMinimumLeft->setMaximumSize(QSize(16777215, 16777215));
        labelMinimumLeft->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(labelMinimumLeft, 0, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 0, 1, 1, 1);


        gridLayout_11->addWidget(widget_4, 4, 0, 1, 1);

        widget_5 = new QWidget(widget_6);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        gridLayout_4 = new QGridLayout(widget_5);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(5, 0, 0, 0);
        labelMaximumRight = new QLabel(widget_5);
        labelMaximumRight->setObjectName(QString::fromUtf8("labelMaximumRight"));
        labelMaximumRight->setMinimumSize(QSize(60, 0));
        labelMaximumRight->setMaximumSize(QSize(16777215, 16777215));
        labelMaximumRight->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(labelMaximumRight, 0, 3, 1, 1);

        lMaxTitle = new QLabel(widget_5);
        lMaxTitle->setObjectName(QString::fromUtf8("lMaxTitle"));
        sizePolicy1.setHeightForWidth(lMaxTitle->sizePolicy().hasHeightForWidth());
        lMaxTitle->setSizePolicy(sizePolicy1);
        lMaxTitle->setMinimumSize(QSize(0, 0));
        lMaxTitle->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(lMaxTitle, 0, 0, 1, 1);

        labelMaximumLeft = new QLabel(widget_5);
        labelMaximumLeft->setObjectName(QString::fromUtf8("labelMaximumLeft"));
        labelMaximumLeft->setMinimumSize(QSize(60, 0));
        labelMaximumLeft->setMaximumSize(QSize(16777215, 16777215));
        labelMaximumLeft->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(labelMaximumLeft, 0, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_4, 0, 1, 1, 1);


        gridLayout_11->addWidget(widget_5, 5, 0, 1, 1);

        widget_12 = new QWidget(widget_6);
        widget_12->setObjectName(QString::fromUtf8("widget_12"));
        widget_12->setStyleSheet(QString::fromUtf8("background-color:rgb(202,202,202)"));
        gridLayout_13 = new QGridLayout(widget_12);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_13->setContentsMargins(5, 0, 0, 0);
        labelAverageRight = new QLabel(widget_12);
        labelAverageRight->setObjectName(QString::fromUtf8("labelAverageRight"));
        labelAverageRight->setMinimumSize(QSize(60, 0));
        labelAverageRight->setMaximumSize(QSize(16777215, 16777215));
        labelAverageRight->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_13->addWidget(labelAverageRight, 0, 3, 1, 1);

        lAverageTitle = new QLabel(widget_12);
        lAverageTitle->setObjectName(QString::fromUtf8("lAverageTitle"));
        sizePolicy1.setHeightForWidth(lAverageTitle->sizePolicy().hasHeightForWidth());
        lAverageTitle->setSizePolicy(sizePolicy1);
        lAverageTitle->setMinimumSize(QSize(0, 0));
        lAverageTitle->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_13->addWidget(lAverageTitle, 0, 0, 1, 1);

        labelAverageLeft = new QLabel(widget_12);
        labelAverageLeft->setObjectName(QString::fromUtf8("labelAverageLeft"));
        labelAverageLeft->setMinimumSize(QSize(60, 0));
        labelAverageLeft->setMaximumSize(QSize(16777215, 16777215));
        labelAverageLeft->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_13->addWidget(labelAverageLeft, 0, 2, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_13->addItem(horizontalSpacer_6, 0, 1, 1, 1);


        gridLayout_11->addWidget(widget_12, 2, 0, 1, 1);

        widget_7 = new QWidget(widget_6);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        gridLayout_6 = new QGridLayout(widget_7);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setHorizontalSpacing(6);
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_8, 1, 0, 1, 1);

        labelNameRight = new QLabel(widget_7);
        labelNameRight->setObjectName(QString::fromUtf8("labelNameRight"));
        labelNameRight->setMinimumSize(QSize(60, 0));
        labelNameRight->setMaximumSize(QSize(16777215, 16777215));
        labelNameRight->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(labelNameRight, 1, 2, 1, 1);

        labelNameLeft = new QLabel(widget_7);
        labelNameLeft->setObjectName(QString::fromUtf8("labelNameLeft"));
        labelNameLeft->setMinimumSize(QSize(60, 0));
        labelNameLeft->setMaximumSize(QSize(16777215, 16777215));
        labelNameLeft->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_6->addWidget(labelNameLeft, 1, 1, 1, 1);

        labelStatistics = new QLabel(widget_7);
        labelStatistics->setObjectName(QString::fromUtf8("labelStatistics"));

        gridLayout_6->addWidget(labelStatistics, 0, 0, 1, 1);


        gridLayout_11->addWidget(widget_7, 0, 0, 1, 1);

        widget_8 = new QWidget(widget_6);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        widget_8->setStyleSheet(QString::fromUtf8(""));
        gridLayout_7 = new QGridLayout(widget_8);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(5, 0, 0, 0);
        labelVariationLeft = new QLabel(widget_8);
        labelVariationLeft->setObjectName(QString::fromUtf8("labelVariationLeft"));
        sizePolicy1.setHeightForWidth(labelVariationLeft->sizePolicy().hasHeightForWidth());
        labelVariationLeft->setSizePolicy(sizePolicy1);
        labelVariationLeft->setMinimumSize(QSize(60, 0));
        labelVariationLeft->setMaximumSize(QSize(16777215, 16777215));
        labelVariationLeft->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(labelVariationLeft, 0, 2, 1, 1);

        labelVariationRight = new QLabel(widget_8);
        labelVariationRight->setObjectName(QString::fromUtf8("labelVariationRight"));
        sizePolicy1.setHeightForWidth(labelVariationRight->sizePolicy().hasHeightForWidth());
        labelVariationRight->setSizePolicy(sizePolicy1);
        labelVariationRight->setMinimumSize(QSize(60, 0));
        labelVariationRight->setMaximumSize(QSize(16777215, 16777215));
        labelVariationRight->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(labelVariationRight, 0, 3, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_9, 0, 1, 1, 1);

        lDistanceVariationTitle = new QLabel(widget_8);
        lDistanceVariationTitle->setObjectName(QString::fromUtf8("lDistanceVariationTitle"));
        lDistanceVariationTitle->setMinimumSize(QSize(50, 0));
        lDistanceVariationTitle->setMaximumSize(QSize(50, 16777215));

        gridLayout_7->addWidget(lDistanceVariationTitle, 0, 0, 1, 1);


        gridLayout_11->addWidget(widget_8, 6, 0, 1, 1);


        gridLayout_5->addWidget(widget_6, 0, 0, 1, 1);


        gridLayout->addWidget(widget_2, 1, 0, 1, 1);

        widget = new QWidget(WidgetInfo);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_8 = new QGridLayout(widget);
        gridLayout_8->setSpacing(0);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(5, 0, 0, 0);
        labelFrameRate = new QLabel(widget);
        labelFrameRate->setObjectName(QString::fromUtf8("labelFrameRate"));

        gridLayout_8->addWidget(labelFrameRate, 2, 0, 1, 1);

        labelSelect = new QLabel(widget);
        labelSelect->setObjectName(QString::fromUtf8("labelSelect"));

        gridLayout_8->addWidget(labelSelect, 4, 0, 1, 1);

        lineH = new QFrame(widget);
        lineH->setObjectName(QString::fromUtf8("lineH"));
        lineH->setFrameShape(QFrame::HLine);
        lineH->setFrameShadow(QFrame::Sunken);

        gridLayout_8->addWidget(lineH, 0, 0, 1, 1);

        labelReset = new QLabel(widget);
        labelReset->setObjectName(QString::fromUtf8("labelReset"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelReset->sizePolicy().hasHeightForWidth());
        labelReset->setSizePolicy(sizePolicy2);

        gridLayout_8->addWidget(labelReset, 5, 0, 1, 1);

        labelTemperature = new QLabel(widget);
        labelTemperature->setObjectName(QString::fromUtf8("labelTemperature"));

        gridLayout_8->addWidget(labelTemperature, 1, 0, 1, 1);

        line = new QFrame(widget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_8->addWidget(line, 3, 0, 1, 1);


        gridLayout->addWidget(widget, 4, 0, 1, 1);


        retranslateUi(WidgetInfo);

        QMetaObject::connectSlotsByName(WidgetInfo);
    } // setupUi

    void retranslateUi(QWidget *WidgetInfo)
    {
        WidgetInfo->setWindowTitle(QCoreApplication::translate("WidgetInfo", "Info", nullptr));
        labelHeader->setText(QCoreApplication::translate("WidgetInfo", "Pixel data(x, y)", nullptr));
        labelCurrentLeft->setText(QString());
        lCurrentTitle->setText(QCoreApplication::translate("WidgetInfo", "Current:", nullptr));
        labelCurrentRight->setText(QString());
        labelMinimumRight->setText(QString());
        lMinTitle->setText(QCoreApplication::translate("WidgetInfo", "Minimum:", nullptr));
        labelMinimumLeft->setText(QString());
        labelMaximumRight->setText(QString());
        lMaxTitle->setText(QCoreApplication::translate("WidgetInfo", "Maximum:", nullptr));
        labelMaximumLeft->setText(QString());
        labelAverageRight->setText(QString());
        lAverageTitle->setText(QCoreApplication::translate("WidgetInfo", "Average:", nullptr));
        labelAverageLeft->setText(QString());
        labelNameRight->setText(QCoreApplication::translate("WidgetInfo", "Amplitude:", nullptr));
        labelNameLeft->setText(QCoreApplication::translate("WidgetInfo", "Distance:", nullptr));
        labelStatistics->setText(QCoreApplication::translate("WidgetInfo", "Statistics over  100 samples", nullptr));
        labelVariationLeft->setText(QString());
        labelVariationRight->setText(QString());
#if QT_CONFIG(tooltip)
        lDistanceVariationTitle->setToolTip(QCoreApplication::translate("WidgetInfo", "<html><head/><body><p><span style=\" font-size:10pt;\">Standart deviation from 100 values</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lDistanceVariationTitle->setText(QCoreApplication::translate("WidgetInfo", "\317\203:", nullptr));
        labelFrameRate->setText(QCoreApplication::translate("WidgetInfo", "Frame rate:", nullptr));
        labelSelect->setText(QCoreApplication::translate("WidgetInfo", "Select: Ctrl + left mouse button", nullptr));
        labelReset->setText(QCoreApplication::translate("WidgetInfo", "Deselect: Ctrl + right mouse button", nullptr));
        labelTemperature->setText(QCoreApplication::translate("WidgetInfo", "Temperature:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetInfo: public Ui_WidgetInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_INFO_H
