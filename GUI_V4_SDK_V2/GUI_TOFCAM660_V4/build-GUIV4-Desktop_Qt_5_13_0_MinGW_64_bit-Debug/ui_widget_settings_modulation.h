/********************************************************************************
** Form generated from reading UI file 'widget_settings_modulation.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_SETTINGS_MODULATION_H
#define UI_WIDGET_SETTINGS_MODULATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetSettingsModulation
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *labelTitle;
    QSpacerItem *horizontalSpacer_3;
    QLabel *lChannel;
    QComboBox *cbModeFrequency;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lModeFrequency;
    QComboBox *cmbChannel;

    void setupUi(QWidget *WidgetSettingsModulation)
    {
        if (WidgetSettingsModulation->objectName().isEmpty())
            WidgetSettingsModulation->setObjectName(QString::fromUtf8("WidgetSettingsModulation"));
        WidgetSettingsModulation->resize(366, 153);
        WidgetSettingsModulation->setMinimumSize(QSize(100, 0));
        gridLayout = new QGridLayout(WidgetSettingsModulation);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(5);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(5);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 2, 1, 1);

        labelTitle = new QLabel(WidgetSettingsModulation);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
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
        labelTitle->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI Black"));
        font.setBold(true);
        font.setWeight(75);
        labelTitle->setFont(font);
        labelTitle->setStyleSheet(QString::fromUtf8("padding:10px;\n"
"/*background-color:rgb(66, 138, 200);*/\n"
"/*background-color:rgb(76, 55, 108);*/\n"
"background-color:rgb(0,0,0);\n"
"color:rgb(255,255,255);\n"
""));

        gridLayout_2->addWidget(labelTitle, 0, 0, 1, 5);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 1, 4, 1, 1);

        lChannel = new QLabel(WidgetSettingsModulation);
        lChannel->setObjectName(QString::fromUtf8("lChannel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        lChannel->setFont(font1);
        lChannel->setStyleSheet(QString::fromUtf8("background-color:transparent;"));

        gridLayout_2->addWidget(lChannel, 2, 1, 1, 1);

        cbModeFrequency = new QComboBox(WidgetSettingsModulation);
        cbModeFrequency->addItem(QString());
        cbModeFrequency->addItem(QString());
        cbModeFrequency->addItem(QString());
        cbModeFrequency->addItem(QString());
        cbModeFrequency->addItem(QString());
        cbModeFrequency->addItem(QString());
        cbModeFrequency->setObjectName(QString::fromUtf8("cbModeFrequency"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cbModeFrequency->sizePolicy().hasHeightForWidth());
        cbModeFrequency->setSizePolicy(sizePolicy);
        cbModeFrequency->setMinimumSize(QSize(100, 0));
        cbModeFrequency->setMaximumSize(QSize(16777215, 16777215));
        cbModeFrequency->setFont(font1);
        cbModeFrequency->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);"));
        cbModeFrequency->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_2->addWidget(cbModeFrequency, 1, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        lModeFrequency = new QLabel(WidgetSettingsModulation);
        lModeFrequency->setObjectName(QString::fromUtf8("lModeFrequency"));
        lModeFrequency->setEnabled(true);
        sizePolicy.setHeightForWidth(lModeFrequency->sizePolicy().hasHeightForWidth());
        lModeFrequency->setSizePolicy(sizePolicy);
        lModeFrequency->setMinimumSize(QSize(0, 0));
        lModeFrequency->setMaximumSize(QSize(16777215, 16777215));
        lModeFrequency->setFont(font1);
        lModeFrequency->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
""));

        gridLayout_2->addWidget(lModeFrequency, 1, 1, 1, 1);

        cmbChannel = new QComboBox(WidgetSettingsModulation);
        cmbChannel->addItem(QString());
        cmbChannel->addItem(QString());
        cmbChannel->addItem(QString());
        cmbChannel->addItem(QString());
        cmbChannel->addItem(QString());
        cmbChannel->addItem(QString());
        cmbChannel->addItem(QString());
        cmbChannel->addItem(QString());
        cmbChannel->addItem(QString());
        cmbChannel->addItem(QString());
        cmbChannel->addItem(QString());
        cmbChannel->addItem(QString());
        cmbChannel->addItem(QString());
        cmbChannel->addItem(QString());
        cmbChannel->addItem(QString());
        cmbChannel->addItem(QString());
        cmbChannel->setObjectName(QString::fromUtf8("cmbChannel"));
        sizePolicy.setHeightForWidth(cmbChannel->sizePolicy().hasHeightForWidth());
        cmbChannel->setSizePolicy(sizePolicy);
        cmbChannel->setMinimumSize(QSize(0, 0));
        cmbChannel->setFont(font1);
        cmbChannel->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);"));

        gridLayout_2->addWidget(cmbChannel, 2, 3, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);


        retranslateUi(WidgetSettingsModulation);

        cbModeFrequency->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(WidgetSettingsModulation);
    } // setupUi

    void retranslateUi(QWidget *WidgetSettingsModulation)
    {
        WidgetSettingsModulation->setWindowTitle(QCoreApplication::translate("WidgetSettingsModulation", "Form", nullptr));
        labelTitle->setText(QCoreApplication::translate("WidgetSettingsModulation", "<html><head/><body><p>MODULATION SETTINGS</p></body></html>", nullptr));
        lChannel->setText(QCoreApplication::translate("WidgetSettingsModulation", "Channel", nullptr));
        cbModeFrequency->setItemText(0, QCoreApplication::translate("WidgetSettingsModulation", "24 Mhz", nullptr));
        cbModeFrequency->setItemText(1, QCoreApplication::translate("WidgetSettingsModulation", "12 Mhz", nullptr));
        cbModeFrequency->setItemText(2, QCoreApplication::translate("WidgetSettingsModulation", "  6 Mhz", nullptr));
        cbModeFrequency->setItemText(3, QCoreApplication::translate("WidgetSettingsModulation", "  3 Mhz", nullptr));
        cbModeFrequency->setItemText(4, QCoreApplication::translate("WidgetSettingsModulation", "1.5 Mhz", nullptr));
        cbModeFrequency->setItemText(5, QCoreApplication::translate("WidgetSettingsModulation", "0.75 Mhz", nullptr));

#if QT_CONFIG(tooltip)
        cbModeFrequency->setToolTip(QCoreApplication::translate("WidgetSettingsModulation", "<html><head/><body><p>Choose the modulation frequency</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbModeFrequency->setCurrentText(QCoreApplication::translate("WidgetSettingsModulation", "12 Mhz", nullptr));
        lModeFrequency->setText(QCoreApplication::translate("WidgetSettingsModulation", "Modulation frequency", nullptr));
        cmbChannel->setItemText(0, QCoreApplication::translate("WidgetSettingsModulation", "0", nullptr));
        cmbChannel->setItemText(1, QCoreApplication::translate("WidgetSettingsModulation", "1", nullptr));
        cmbChannel->setItemText(2, QCoreApplication::translate("WidgetSettingsModulation", "2", nullptr));
        cmbChannel->setItemText(3, QCoreApplication::translate("WidgetSettingsModulation", "3", nullptr));
        cmbChannel->setItemText(4, QCoreApplication::translate("WidgetSettingsModulation", "4", nullptr));
        cmbChannel->setItemText(5, QCoreApplication::translate("WidgetSettingsModulation", "5", nullptr));
        cmbChannel->setItemText(6, QCoreApplication::translate("WidgetSettingsModulation", "6", nullptr));
        cmbChannel->setItemText(7, QCoreApplication::translate("WidgetSettingsModulation", "7", nullptr));
        cmbChannel->setItemText(8, QCoreApplication::translate("WidgetSettingsModulation", "8", nullptr));
        cmbChannel->setItemText(9, QCoreApplication::translate("WidgetSettingsModulation", "9", nullptr));
        cmbChannel->setItemText(10, QCoreApplication::translate("WidgetSettingsModulation", "10", nullptr));
        cmbChannel->setItemText(11, QCoreApplication::translate("WidgetSettingsModulation", "11", nullptr));
        cmbChannel->setItemText(12, QCoreApplication::translate("WidgetSettingsModulation", "12", nullptr));
        cmbChannel->setItemText(13, QCoreApplication::translate("WidgetSettingsModulation", "13", nullptr));
        cmbChannel->setItemText(14, QCoreApplication::translate("WidgetSettingsModulation", "14", nullptr));
        cmbChannel->setItemText(15, QCoreApplication::translate("WidgetSettingsModulation", "15", nullptr));

#if QT_CONFIG(tooltip)
        cmbChannel->setToolTip(QCoreApplication::translate("WidgetSettingsModulation", "<html><head/><body><p>The modulation channel slightly changes the modulation frequency</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class WidgetSettingsModulation: public Ui_WidgetSettingsModulation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_SETTINGS_MODULATION_H
