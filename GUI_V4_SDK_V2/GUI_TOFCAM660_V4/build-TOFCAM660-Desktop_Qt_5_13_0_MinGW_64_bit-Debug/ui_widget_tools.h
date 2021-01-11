/********************************************************************************
** Form generated from reading UI file 'widget_tools.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_TOOLS_H
#define UI_WIDGET_TOOLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "WidgetHeader.h"

QT_BEGIN_NAMESPACE

class Ui_WidgetTools
{
public:
    QGridLayout *gridLayout_2;
    QLabel *labelTitle;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_4;
    QTextEdit *textEditUserDataToSend;
    WidgetHeader *widgetHeaderData;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *WidgetTools)
    {
        if (WidgetTools->objectName().isEmpty())
            WidgetTools->setObjectName(QString::fromUtf8("WidgetTools"));
        WidgetTools->resize(480, 272);
        gridLayout_2 = new QGridLayout(WidgetTools);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        labelTitle = new QLabel(WidgetTools);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        labelTitle->setStyleSheet(QString::fromUtf8("padding:10px;\n"
"/*background-color:rgb(66, 138, 200);*/\n"
"/*background-color:rgb(76, 55, 108);*/\n"
"background-color:rgb(51, 51, 51);\n"
"color:rgb(255,255,255);\n"
""));

        gridLayout_2->addWidget(labelTitle, 0, 0, 1, 1);

        widget = new QWidget(WidgetTools);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 1, 1, 1);

        textEditUserDataToSend = new QTextEdit(widget);
        textEditUserDataToSend->setObjectName(QString::fromUtf8("textEditUserDataToSend"));
        textEditUserDataToSend->setEnabled(true);
        sizePolicy.setHeightForWidth(textEditUserDataToSend->sizePolicy().hasHeightForWidth());
        textEditUserDataToSend->setSizePolicy(sizePolicy);
        textEditUserDataToSend->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(textEditUserDataToSend, 1, 0, 1, 1);

        widgetHeaderData = new WidgetHeader(widget);
        widgetHeaderData->setObjectName(QString::fromUtf8("widgetHeaderData"));
        sizePolicy.setHeightForWidth(widgetHeaderData->sizePolicy().hasHeightForWidth());
        widgetHeaderData->setSizePolicy(sizePolicy);
        widgetHeaderData->setMinimumSize(QSize(200, 0));

        gridLayout->addWidget(widgetHeaderData, 1, 1, 1, 1);


        gridLayout_2->addWidget(widget, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 0, 1, 1);


        retranslateUi(WidgetTools);

        QMetaObject::connectSlotsByName(WidgetTools);
    } // setupUi

    void retranslateUi(QWidget *WidgetTools)
    {
        WidgetTools->setWindowTitle(QCoreApplication::translate("WidgetTools", "Form", nullptr));
        labelTitle->setText(QCoreApplication::translate("WidgetTools", "Tools", nullptr));
        label_3->setText(QCoreApplication::translate("WidgetTools", "User Data", nullptr));
        label_4->setText(QCoreApplication::translate("WidgetTools", "Header Data", nullptr));
#if QT_CONFIG(tooltip)
        textEditUserDataToSend->setToolTip(QCoreApplication::translate("WidgetTools", "Here you can put user data which will be included in the header", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        widgetHeaderData->setToolTip(QCoreApplication::translate("WidgetTools", "Shows the Header Data received from the camera", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class WidgetTools: public Ui_WidgetTools {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_TOOLS_H
