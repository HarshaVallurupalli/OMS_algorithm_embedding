/********************************************************************************
** Form generated from reading UI file 'widget_calibration.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_CALIBRATION_H
#define UI_WIDGET_CALIBRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetCalibration
{
public:
    QGridLayout *gridLayout_2;
    QLabel *labelTitle;
    QWidget *widget;
    QGridLayout *gridLayout;
    QCheckBox *checkBoxVerifyOnly;
    QSpinBox *spinBoxCommand2;
    QLabel *label_3;
    QLineEdit *lineEditDescription1;
    QSpinBox *spinBoxCommand1;
    QLineEdit *lineEditData1;
    QSpacerItem *horizontalSpacer;
    QSpinBox *spinBoxCommand3;
    QLineEdit *lineEditData0;
    QCheckBox *checkBoxOffsetOnly;
    QPushButton *pushButtonProductionCalibration;
    QLineEdit *lineEditData3;
    QPushButton *pushButtonDebugCommand0;
    QPushButton *pushButtonDebugCommand3;
    QLabel *label;
    QLineEdit *lineEditDescription0;
    QLineEdit *lineEditData2;
    QLabel *label_6;
    QPushButton *pushButtonDebugCommand2;
    QSpinBox *spinBoxIndex;
    QSpinBox *spinBoxCommand0;
    QLabel *label_2;
    QPushButton *pushButtonDebugCommand1;
    QFrame *line;
    QTextEdit *textEditCalibration;
    QLineEdit *lineEditDescription3;
    QPushButton *pushButtonCalibration;
    QLineEdit *lineEditDescription2;
    QLabel *lIndex;
    QLabel *label_4;

    void setupUi(QWidget *WidgetCalibration)
    {
        if (WidgetCalibration->objectName().isEmpty())
            WidgetCalibration->setObjectName(QString::fromUtf8("WidgetCalibration"));
        WidgetCalibration->resize(485, 293);
        WidgetCalibration->setMinimumSize(QSize(0, 10));
        gridLayout_2 = new QGridLayout(WidgetCalibration);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        labelTitle = new QLabel(WidgetCalibration);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        labelTitle->setStyleSheet(QString::fromUtf8("padding:10px;\n"
"/*background-color:rgb(66, 138, 200);*/\n"
"/*background-color:rgb(76, 55, 108);*/\n"
"background-color:rgb(51, 51, 51);\n"
"color:rgb(255,255,255);\n"
""));

        gridLayout_2->addWidget(labelTitle, 0, 0, 1, 1);

        widget = new QWidget(WidgetCalibration);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        checkBoxVerifyOnly = new QCheckBox(widget);
        checkBoxVerifyOnly->setObjectName(QString::fromUtf8("checkBoxVerifyOnly"));

        gridLayout->addWidget(checkBoxVerifyOnly, 1, 2, 1, 2);

        spinBoxCommand2 = new QSpinBox(widget);
        spinBoxCommand2->setObjectName(QString::fromUtf8("spinBoxCommand2"));
        spinBoxCommand2->setMaximum(255);

        gridLayout->addWidget(spinBoxCommand2, 10, 3, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        lineEditDescription1 = new QLineEdit(widget);
        lineEditDescription1->setObjectName(QString::fromUtf8("lineEditDescription1"));

        gridLayout->addWidget(lineEditDescription1, 8, 13, 1, 1);

        spinBoxCommand1 = new QSpinBox(widget);
        spinBoxCommand1->setObjectName(QString::fromUtf8("spinBoxCommand1"));
        spinBoxCommand1->setMaximum(255);

        gridLayout->addWidget(spinBoxCommand1, 8, 3, 1, 1);

        lineEditData1 = new QLineEdit(widget);
        lineEditData1->setObjectName(QString::fromUtf8("lineEditData1"));

        gridLayout->addWidget(lineEditData1, 8, 4, 1, 9);

        horizontalSpacer = new QSpacerItem(178, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 7, 1, 7);

        spinBoxCommand3 = new QSpinBox(widget);
        spinBoxCommand3->setObjectName(QString::fromUtf8("spinBoxCommand3"));
        spinBoxCommand3->setMaximum(255);

        gridLayout->addWidget(spinBoxCommand3, 11, 3, 1, 1);

        lineEditData0 = new QLineEdit(widget);
        lineEditData0->setObjectName(QString::fromUtf8("lineEditData0"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEditData0->sizePolicy().hasHeightForWidth());
        lineEditData0->setSizePolicy(sizePolicy);

        gridLayout->addWidget(lineEditData0, 7, 4, 1, 9);

        checkBoxOffsetOnly = new QCheckBox(widget);
        checkBoxOffsetOnly->setObjectName(QString::fromUtf8("checkBoxOffsetOnly"));

        gridLayout->addWidget(checkBoxOffsetOnly, 1, 4, 1, 1);

        pushButtonProductionCalibration = new QPushButton(widget);
        pushButtonProductionCalibration->setObjectName(QString::fromUtf8("pushButtonProductionCalibration"));

        gridLayout->addWidget(pushButtonProductionCalibration, 2, 0, 1, 1);

        lineEditData3 = new QLineEdit(widget);
        lineEditData3->setObjectName(QString::fromUtf8("lineEditData3"));

        gridLayout->addWidget(lineEditData3, 11, 4, 1, 9);

        pushButtonDebugCommand0 = new QPushButton(widget);
        pushButtonDebugCommand0->setObjectName(QString::fromUtf8("pushButtonDebugCommand0"));

        gridLayout->addWidget(pushButtonDebugCommand0, 7, 0, 1, 1);

        pushButtonDebugCommand3 = new QPushButton(widget);
        pushButtonDebugCommand3->setObjectName(QString::fromUtf8("pushButtonDebugCommand3"));

        gridLayout->addWidget(pushButtonDebugCommand3, 11, 0, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 4, 3, 1, 1);

        lineEditDescription0 = new QLineEdit(widget);
        lineEditDescription0->setObjectName(QString::fromUtf8("lineEditDescription0"));

        gridLayout->addWidget(lineEditDescription0, 7, 13, 1, 1);

        lineEditData2 = new QLineEdit(widget);
        lineEditData2->setObjectName(QString::fromUtf8("lineEditData2"));

        gridLayout->addWidget(lineEditData2, 10, 4, 1, 9);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 4, 13, 1, 1);

        pushButtonDebugCommand2 = new QPushButton(widget);
        pushButtonDebugCommand2->setObjectName(QString::fromUtf8("pushButtonDebugCommand2"));

        gridLayout->addWidget(pushButtonDebugCommand2, 10, 0, 1, 1);

        spinBoxIndex = new QSpinBox(widget);
        spinBoxIndex->setObjectName(QString::fromUtf8("spinBoxIndex"));
        spinBoxIndex->setMinimumSize(QSize(50, 0));

        gridLayout->addWidget(spinBoxIndex, 1, 5, 1, 1);

        spinBoxCommand0 = new QSpinBox(widget);
        spinBoxCommand0->setObjectName(QString::fromUtf8("spinBoxCommand0"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinBoxCommand0->sizePolicy().hasHeightForWidth());
        spinBoxCommand0->setSizePolicy(sizePolicy1);
        spinBoxCommand0->setMaximum(255);

        gridLayout->addWidget(spinBoxCommand0, 7, 3, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 4, 4, 1, 1);

        pushButtonDebugCommand1 = new QPushButton(widget);
        pushButtonDebugCommand1->setObjectName(QString::fromUtf8("pushButtonDebugCommand1"));

        gridLayout->addWidget(pushButtonDebugCommand1, 8, 0, 1, 1);

        line = new QFrame(widget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 3, 0, 1, 14);

        textEditCalibration = new QTextEdit(widget);
        textEditCalibration->setObjectName(QString::fromUtf8("textEditCalibration"));
        textEditCalibration->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(textEditCalibration, 12, 0, 1, 14);

        lineEditDescription3 = new QLineEdit(widget);
        lineEditDescription3->setObjectName(QString::fromUtf8("lineEditDescription3"));

        gridLayout->addWidget(lineEditDescription3, 11, 13, 1, 1);

        pushButtonCalibration = new QPushButton(widget);
        pushButtonCalibration->setObjectName(QString::fromUtf8("pushButtonCalibration"));

        gridLayout->addWidget(pushButtonCalibration, 1, 0, 1, 1);

        lineEditDescription2 = new QLineEdit(widget);
        lineEditDescription2->setObjectName(QString::fromUtf8("lineEditDescription2"));

        gridLayout->addWidget(lineEditDescription2, 10, 13, 1, 1);

        lIndex = new QLabel(widget);
        lIndex->setObjectName(QString::fromUtf8("lIndex"));

        gridLayout->addWidget(lIndex, 1, 6, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);


        gridLayout_2->addWidget(widget, 1, 0, 1, 1);


        retranslateUi(WidgetCalibration);

        QMetaObject::connectSlotsByName(WidgetCalibration);
    } // setupUi

    void retranslateUi(QWidget *WidgetCalibration)
    {
        WidgetCalibration->setWindowTitle(QCoreApplication::translate("WidgetCalibration", "Form", nullptr));
        labelTitle->setText(QCoreApplication::translate("WidgetCalibration", "Calibration / Debug", nullptr));
        checkBoxVerifyOnly->setText(QCoreApplication::translate("WidgetCalibration", "Verify only", nullptr));
        label_3->setText(QCoreApplication::translate("WidgetCalibration", "Calibration", nullptr));
        checkBoxOffsetOnly->setText(QCoreApplication::translate("WidgetCalibration", "Offset only", nullptr));
        pushButtonProductionCalibration->setText(QCoreApplication::translate("WidgetCalibration", "Production Calibration", nullptr));
        pushButtonDebugCommand0->setText(QCoreApplication::translate("WidgetCalibration", "DebugCommand", nullptr));
        pushButtonDebugCommand3->setText(QCoreApplication::translate("WidgetCalibration", "DebugCommand", nullptr));
        label->setText(QCoreApplication::translate("WidgetCalibration", "command", nullptr));
        label_6->setText(QCoreApplication::translate("WidgetCalibration", "Description", nullptr));
        pushButtonDebugCommand2->setText(QCoreApplication::translate("WidgetCalibration", "DebugCommand", nullptr));
        label_2->setText(QCoreApplication::translate("WidgetCalibration", "data", nullptr));
        pushButtonDebugCommand1->setText(QCoreApplication::translate("WidgetCalibration", "DebugCommand", nullptr));
        pushButtonCalibration->setText(QCoreApplication::translate("WidgetCalibration", "Calibrate DRNU", nullptr));
        lIndex->setText(QCoreApplication::translate("WidgetCalibration", "Index", nullptr));
        label_4->setText(QCoreApplication::translate("WidgetCalibration", "Debug", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetCalibration: public Ui_WidgetCalibration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_CALIBRATION_H
