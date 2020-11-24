/********************************************************************************
** Form generated from reading UI file 'widget_settings.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_SETTINGS_H
#define UI_WIDGET_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetSettings
{
public:
    QGridLayout *gridLayout;
    QLabel *labelTitle;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QToolButton *tbApply;
    QLabel *lComputer_IP_Address;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEditIP;
    QSpacerItem *verticalSpacer;
    QLabel *lCurrentIPAddress;

    void setupUi(QWidget *WidgetSettings)
    {
        if (WidgetSettings->objectName().isEmpty())
            WidgetSettings->setObjectName(QString::fromUtf8("WidgetSettings"));
        WidgetSettings->resize(337, 300);
        gridLayout = new QGridLayout(WidgetSettings);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelTitle = new QLabel(WidgetSettings);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelTitle->sizePolicy().hasHeightForWidth());
        labelTitle->setSizePolicy(sizePolicy);
        labelTitle->setStyleSheet(QString::fromUtf8("padding:10px;\n"
"background-color:rgb(51, 51, 51);\n"
"color:rgb(255,255,255);\n"
""));

        gridLayout->addWidget(labelTitle, 0, 0, 1, 1);

        widget = new QWidget(WidgetSettings);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(20);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, 40, -1, -1);
        tbApply = new QToolButton(widget);
        tbApply->setObjectName(QString::fromUtf8("tbApply"));

        gridLayout_2->addWidget(tbApply, 1, 3, 1, 1);

        lComputer_IP_Address = new QLabel(widget);
        lComputer_IP_Address->setObjectName(QString::fromUtf8("lComputer_IP_Address"));

        gridLayout_2->addWidget(lComputer_IP_Address, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 4, 1, 1);

        lineEditIP = new QLineEdit(widget);
        lineEditIP->setObjectName(QString::fromUtf8("lineEditIP"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEditIP->sizePolicy().hasHeightForWidth());
        lineEditIP->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(lineEditIP, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 3, 2, 1, 1);

        lCurrentIPAddress = new QLabel(widget);
        lCurrentIPAddress->setObjectName(QString::fromUtf8("lCurrentIPAddress"));

        gridLayout_2->addWidget(lCurrentIPAddress, 0, 1, 1, 2);


        gridLayout->addWidget(widget, 1, 0, 1, 1);


        retranslateUi(WidgetSettings);

        QMetaObject::connectSlotsByName(WidgetSettings);
    } // setupUi

    void retranslateUi(QWidget *WidgetSettings)
    {
        WidgetSettings->setWindowTitle(QCoreApplication::translate("WidgetSettings", "Form", nullptr));
        labelTitle->setText(QCoreApplication::translate("WidgetSettings", "Settings", nullptr));
#if QT_CONFIG(tooltip)
        tbApply->setToolTip(QCoreApplication::translate("WidgetSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Apply data computer IP address</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbApply->setText(QCoreApplication::translate("WidgetSettings", "  Apply  ", nullptr));
        lComputer_IP_Address->setText(QCoreApplication::translate("WidgetSettings", "Computer IP address", nullptr));
#if QT_CONFIG(tooltip)
        lineEditIP->setToolTip(QCoreApplication::translate("WidgetSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Data computer IP address</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lCurrentIPAddress->setText(QCoreApplication::translate("WidgetSettings", "Current IP address: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetSettings: public Ui_WidgetSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_SETTINGS_H
