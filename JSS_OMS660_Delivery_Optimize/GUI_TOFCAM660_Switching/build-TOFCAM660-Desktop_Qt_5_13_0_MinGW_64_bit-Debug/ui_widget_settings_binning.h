/********************************************************************************
** Form generated from reading UI file 'widget_settings_binning.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_SETTINGS_BINNING_H
#define UI_WIDGET_SETTINGS_BINNING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetSettingsBinning
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QCheckBox *cbVerticalBinning;
    QCheckBox *cbHorizontalBinning;
    QLabel *lBinning;

    void setupUi(QWidget *WidgetSettingsBinning)
    {
        if (WidgetSettingsBinning->objectName().isEmpty())
            WidgetSettingsBinning->setObjectName(QString::fromUtf8("WidgetSettingsBinning"));
        WidgetSettingsBinning->resize(260, 85);
        WidgetSettingsBinning->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(WidgetSettingsBinning);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 9);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(10);
        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        cbVerticalBinning = new QCheckBox(WidgetSettingsBinning);
        cbVerticalBinning->setObjectName(QString::fromUtf8("cbVerticalBinning"));
        cbVerticalBinning->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(cbVerticalBinning, 1, 1, 1, 1);

        cbHorizontalBinning = new QCheckBox(WidgetSettingsBinning);
        cbHorizontalBinning->setObjectName(QString::fromUtf8("cbHorizontalBinning"));
        cbHorizontalBinning->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(cbHorizontalBinning, 2, 1, 1, 1);

        lBinning = new QLabel(WidgetSettingsBinning);
        lBinning->setObjectName(QString::fromUtf8("lBinning"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        lBinning->setFont(font);
        lBinning->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(lBinning, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(WidgetSettingsBinning);

        QMetaObject::connectSlotsByName(WidgetSettingsBinning);
    } // setupUi

    void retranslateUi(QWidget *WidgetSettingsBinning)
    {
        WidgetSettingsBinning->setWindowTitle(QCoreApplication::translate("WidgetSettingsBinning", "Form", nullptr));
#if QT_CONFIG(tooltip)
        cbVerticalBinning->setToolTip(QCoreApplication::translate("WidgetSettingsBinning", "<html><head/><body><p><span style=\" font-size:10pt;\">Switch on sensor vertical binning</span></p><p><span style=\" font-size:10pt;\">The vertical resolution will be reduced</span></p><p><span style=\" font-size:10pt;\">The camera speed and sensitivity will be increased</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbVerticalBinning->setText(QCoreApplication::translate("WidgetSettingsBinning", "Vertical binning", nullptr));
#if QT_CONFIG(tooltip)
        cbHorizontalBinning->setToolTip(QCoreApplication::translate("WidgetSettingsBinning", "<html><head/><body><p><span style=\" font-size:10pt;\">Switch on sensor horizontal binning</span></p><p><span style=\" font-size:10pt;\">The horizontal resolution will be reduced</span></p><p><span style=\" font-size:10pt;\">The camera speed and sensitivity will be increased</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbHorizontalBinning->setText(QCoreApplication::translate("WidgetSettingsBinning", "Horizontal binning", nullptr));
        lBinning->setText(QCoreApplication::translate("WidgetSettingsBinning", "BINNING", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetSettingsBinning: public Ui_WidgetSettingsBinning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_SETTINGS_BINNING_H
