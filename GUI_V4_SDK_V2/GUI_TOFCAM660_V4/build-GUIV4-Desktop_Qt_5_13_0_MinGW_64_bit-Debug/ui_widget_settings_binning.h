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
    QCheckBox *cbVerticalBinning;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *cbHorizontalBinning;
    QSpacerItem *horizontalSpacer;
    QLabel *labelTitle_2;

    void setupUi(QWidget *WidgetSettingsBinning)
    {
        if (WidgetSettingsBinning->objectName().isEmpty())
            WidgetSettingsBinning->setObjectName(QString::fromUtf8("WidgetSettingsBinning"));
        WidgetSettingsBinning->resize(404, 114);
        WidgetSettingsBinning->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(WidgetSettingsBinning);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(0);
        gridLayout_2->setVerticalSpacing(5);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        cbVerticalBinning = new QCheckBox(WidgetSettingsBinning);
        cbVerticalBinning->setObjectName(QString::fromUtf8("cbVerticalBinning"));
        cbVerticalBinning->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(cbVerticalBinning, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        cbHorizontalBinning = new QCheckBox(WidgetSettingsBinning);
        cbHorizontalBinning->setObjectName(QString::fromUtf8("cbHorizontalBinning"));
        cbHorizontalBinning->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(cbHorizontalBinning, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        labelTitle_2 = new QLabel(WidgetSettingsBinning);
        labelTitle_2->setObjectName(QString::fromUtf8("labelTitle_2"));
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
        labelTitle_2->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI Black"));
        font.setBold(true);
        font.setWeight(75);
        labelTitle_2->setFont(font);
        labelTitle_2->setStyleSheet(QString::fromUtf8("padding:10px;\n"
"/*background-color:rgb(66, 138, 200);*/\n"
"/*background-color:rgb(76, 55, 108);*/\n"
"background-color:rgb(0,0,0);\n"
"color:rgb(255,255,255);\n"
""));

        gridLayout_2->addWidget(labelTitle_2, 0, 0, 1, 2);


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
        labelTitle_2->setText(QCoreApplication::translate("WidgetSettingsBinning", "<html><head/><body><p>BINNING SETTINGS</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetSettingsBinning: public Ui_WidgetSettingsBinning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_SETTINGS_BINNING_H
