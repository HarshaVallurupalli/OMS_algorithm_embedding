/********************************************************************************
** Form generated from reading UI file 'widget_header.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_HEADER_H
#define UI_WIDGET_HEADER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetHeader
{
public:
    QVBoxLayout *verticalLayout;
    QTextBrowser *textInfo;

    void setupUi(QWidget *WidgetHeader)
    {
        if (WidgetHeader->objectName().isEmpty())
            WidgetHeader->setObjectName(QString::fromUtf8("WidgetHeader"));
        WidgetHeader->resize(309, 262);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WidgetHeader->sizePolicy().hasHeightForWidth());
        WidgetHeader->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(WidgetHeader);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textInfo = new QTextBrowser(WidgetHeader);
        textInfo->setObjectName(QString::fromUtf8("textInfo"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textInfo->sizePolicy().hasHeightForWidth());
        textInfo->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(textInfo);


        retranslateUi(WidgetHeader);

        QMetaObject::connectSlotsByName(WidgetHeader);
    } // setupUi

    void retranslateUi(QWidget *WidgetHeader)
    {
        WidgetHeader->setWindowTitle(QCoreApplication::translate("WidgetHeader", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetHeader: public Ui_WidgetHeader {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_HEADER_H
