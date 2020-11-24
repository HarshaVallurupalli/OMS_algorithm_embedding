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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetSaveLoad
{
public:
    QGridLayout *gridLayout;
    QLabel *labelTitle;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *tbSave;
    QSpacerItem *horizontalSpacer;
    QToolButton *tbUpdateFirmware;
    QSpacerItem *verticalSpacer;
    QToolButton *tbLoad;
    QFrame *line;

    void setupUi(QWidget *WidgetSaveLoad)
    {
        if (WidgetSaveLoad->objectName().isEmpty())
            WidgetSaveLoad->setObjectName(QString::fromUtf8("WidgetSaveLoad"));
        WidgetSaveLoad->resize(280, 300);
        gridLayout = new QGridLayout(WidgetSaveLoad);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelTitle = new QLabel(WidgetSaveLoad);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        labelTitle->setStyleSheet(QString::fromUtf8("padding:10px;\n"
"/*background-color:rgb(66, 138, 200);*/\n"
"/*background-color:rgb(76, 55, 108);*/\n"
"background-color:rgb(51, 51, 51);\n"
"color:rgb(255,255,255);\n"
""));

        gridLayout->addWidget(labelTitle, 0, 0, 1, 1);

        widget = new QWidget(WidgetSaveLoad);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(20);
        gridLayout_2->setContentsMargins(0, 40, -1, -1);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        tbSave = new QToolButton(widget);
        tbSave->setObjectName(QString::fromUtf8("tbSave"));
        tbSave->setMinimumSize(QSize(100, 0));

        gridLayout_2->addWidget(tbSave, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 2, 1, 1);

        tbUpdateFirmware = new QToolButton(widget);
        tbUpdateFirmware->setObjectName(QString::fromUtf8("tbUpdateFirmware"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tbUpdateFirmware->sizePolicy().hasHeightForWidth());
        tbUpdateFirmware->setSizePolicy(sizePolicy1);
        tbUpdateFirmware->setMinimumSize(QSize(100, 0));

        gridLayout_2->addWidget(tbUpdateFirmware, 5, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 7, 1, 1, 1);

        tbLoad = new QToolButton(widget);
        tbLoad->setObjectName(QString::fromUtf8("tbLoad"));
        tbLoad->setMinimumSize(QSize(100, 0));

        gridLayout_2->addWidget(tbLoad, 3, 1, 1, 1);

        line = new QFrame(widget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line, 4, 1, 1, 1);


        gridLayout->addWidget(widget, 1, 0, 1, 1);


        retranslateUi(WidgetSaveLoad);

        QMetaObject::connectSlotsByName(WidgetSaveLoad);
    } // setupUi

    void retranslateUi(QWidget *WidgetSaveLoad)
    {
        WidgetSaveLoad->setWindowTitle(QCoreApplication::translate("WidgetSaveLoad", "Form", nullptr));
        labelTitle->setText(QCoreApplication::translate("WidgetSaveLoad", "Save / Load", nullptr));
#if QT_CONFIG(tooltip)
        tbSave->setToolTip(QCoreApplication::translate("WidgetSaveLoad", "<html><head/><body><p><span style=\" font-size:10pt;\">Save application configuration</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbSave->setText(QCoreApplication::translate("WidgetSaveLoad", "  Save  configuration and settings  ", nullptr));
        tbUpdateFirmware->setText(QCoreApplication::translate("WidgetSaveLoad", "Update firmware", nullptr));
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
