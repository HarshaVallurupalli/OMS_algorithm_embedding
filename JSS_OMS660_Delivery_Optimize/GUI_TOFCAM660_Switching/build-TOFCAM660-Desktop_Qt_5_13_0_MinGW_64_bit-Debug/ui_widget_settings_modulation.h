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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetSettingsModulation
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *lModeFrequency;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QComboBox *cbModeFrequency;
    QComboBox *cmbChannel;
    QLabel *lChannel;

    void setupUi(QWidget *WidgetSettingsModulation)
    {
        if (WidgetSettingsModulation->objectName().isEmpty())
            WidgetSettingsModulation->setObjectName(QString::fromUtf8("WidgetSettingsModulation"));
        WidgetSettingsModulation->resize(366, 153);
        WidgetSettingsModulation->setMinimumSize(QSize(100, 0));
        gridLayout = new QGridLayout(WidgetSettingsModulation);
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(10);
        gridLayout_2->setContentsMargins(-1, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 1, 4, 1, 1);

        lModeFrequency = new QLabel(WidgetSettingsModulation);
        lModeFrequency->setObjectName(QString::fromUtf8("lModeFrequency"));
        lModeFrequency->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lModeFrequency->sizePolicy().hasHeightForWidth());
        lModeFrequency->setSizePolicy(sizePolicy);
        lModeFrequency->setMinimumSize(QSize(0, 0));
        lModeFrequency->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        lModeFrequency->setFont(font);
        lModeFrequency->setStyleSheet(QString::fromUtf8("background-color:transparent;\n"
""));

        gridLayout_2->addWidget(lModeFrequency, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 10, -1, 5);
        label = new QLabel(WidgetSettingsModulation);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 0));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        horizontalLayout->addWidget(label);


        gridLayout_2->addLayout(horizontalLayout, 0, 1, 1, 3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 4, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer, 3, 3, 1, 1);

        cbModeFrequency = new QComboBox(WidgetSettingsModulation);
        cbModeFrequency->addItem(QString());
        cbModeFrequency->addItem(QString());
        cbModeFrequency->addItem(QString());
        cbModeFrequency->addItem(QString());
        cbModeFrequency->addItem(QString());
        cbModeFrequency->addItem(QString());
        cbModeFrequency->setObjectName(QString::fromUtf8("cbModeFrequency"));
        sizePolicy.setHeightForWidth(cbModeFrequency->sizePolicy().hasHeightForWidth());
        cbModeFrequency->setSizePolicy(sizePolicy);
        cbModeFrequency->setMinimumSize(QSize(100, 0));
        cbModeFrequency->setMaximumSize(QSize(16777215, 16777215));
        cbModeFrequency->setFont(font);
        cbModeFrequency->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);"));
        cbModeFrequency->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_2->addWidget(cbModeFrequency, 1, 3, 1, 1);

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
        cmbChannel->setFont(font);
        cmbChannel->setStyleSheet(QString::fromUtf8("border-color: rgb(0, 0, 0);"));

        gridLayout_2->addWidget(cmbChannel, 2, 3, 1, 1);

        lChannel = new QLabel(WidgetSettingsModulation);
        lChannel->setObjectName(QString::fromUtf8("lChannel"));
        lChannel->setFont(font);
        lChannel->setStyleSheet(QString::fromUtf8("background-color:transparent;"));

        gridLayout_2->addWidget(lChannel, 2, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 1, 0, 1, 3);


        retranslateUi(WidgetSettingsModulation);

        cbModeFrequency->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(WidgetSettingsModulation);
    } // setupUi

    void retranslateUi(QWidget *WidgetSettingsModulation)
    {
        WidgetSettingsModulation->setWindowTitle(QCoreApplication::translate("WidgetSettingsModulation", "Form", nullptr));
        lModeFrequency->setText(QCoreApplication::translate("WidgetSettingsModulation", "Modulation frequency", nullptr));
        label->setText(QCoreApplication::translate("WidgetSettingsModulation", "MODULATION", nullptr));
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
        lChannel->setText(QCoreApplication::translate("WidgetSettingsModulation", "Channel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetSettingsModulation: public Ui_WidgetSettingsModulation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_SETTINGS_MODULATION_H
