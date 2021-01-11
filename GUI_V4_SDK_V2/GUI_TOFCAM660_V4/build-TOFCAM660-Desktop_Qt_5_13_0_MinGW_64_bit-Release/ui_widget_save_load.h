/********************************************************************************
** Form generated from reading UI file 'widget_save_load.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_SAVE_LOAD_H
#define UI_WIDGET_SAVE_LOAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetSaveLoad
{
public:
    QGridLayout *gridLayout_3;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *labelTitle;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *tbSave;
    QSpacerItem *horizontalSpacer;
    QToolButton *tbLoad;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *WidgetSaveLoad)
    {
        if (WidgetSaveLoad->objectName().isEmpty())
            WidgetSaveLoad->setObjectName(QString::fromUtf8("WidgetSaveLoad"));
        WidgetSaveLoad->resize(280, 300);
        gridLayout_3 = new QGridLayout(WidgetSaveLoad);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(WidgetSaveLoad);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        labelTitle = new QLabel(widget);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI Black"));
        font.setBold(true);
        font.setWeight(75);
        labelTitle->setFont(font);
        labelTitle->setStyleSheet(QString::fromUtf8("padding:10px;\n"
"/*background-color:rgb(66, 138, 200);*/\n"
"/*background-color:rgb(76, 55, 108);*/\n"
"background-color:rgb(0, 0, 0);\n"
"color:rgb(255,255,255);\n"
""));
        labelTitle->setFrameShape(QFrame::NoFrame);
        labelTitle->setLineWidth(1);
        labelTitle->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(labelTitle, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        tbSave = new QToolButton(widget);
        tbSave->setObjectName(QString::fromUtf8("tbSave"));
        tbSave->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(tbSave, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        tbLoad = new QToolButton(widget);
        tbLoad->setObjectName(QString::fromUtf8("tbLoad"));
        tbLoad->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(tbLoad, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);


        gridLayout_3->addWidget(widget, 0, 0, 1, 1);


        retranslateUi(WidgetSaveLoad);

        QMetaObject::connectSlotsByName(WidgetSaveLoad);
    } // setupUi

    void retranslateUi(QWidget *WidgetSaveLoad)
    {
        WidgetSaveLoad->setWindowTitle(QCoreApplication::translate("WidgetSaveLoad", "Form", nullptr));
        labelTitle->setText(QCoreApplication::translate("WidgetSaveLoad", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">SAVE/LOAD</span></p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        tbSave->setToolTip(QCoreApplication::translate("WidgetSaveLoad", "<html><head/><body><p><span style=\" font-size:10pt;\">Save application configuration</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbSave->setText(QCoreApplication::translate("WidgetSaveLoad", "  Save  configuration and settings  ", nullptr));
#if QT_CONFIG(tooltip)
        tbLoad->setToolTip(QCoreApplication::translate("WidgetSaveLoad", "<html><head/><body><p><span style=\" font-size:10pt;\">Load application configuration</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbLoad->setText(QCoreApplication::translate("WidgetSaveLoad", "  Load  configuration and settings  ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetSaveLoad: public Ui_WidgetSaveLoad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_SAVE_LOAD_H
