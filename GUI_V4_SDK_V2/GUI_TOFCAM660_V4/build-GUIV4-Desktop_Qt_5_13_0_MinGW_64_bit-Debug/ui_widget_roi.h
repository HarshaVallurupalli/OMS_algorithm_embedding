/********************************************************************************
** Form generated from reading UI file 'widget_roi.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_ROI_H
#define UI_WIDGET_ROI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetSettingsROI
{
public:
    QGridLayout *gridLayout_2;
    QLabel *labelTitle;
    QGridLayout *gridLayout;
    QToolButton *tbDefaultROI;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lCorner1;
    QSpinBox *sbTopLeftY;
    QSpacerItem *horizontalSpacer;
    QSpinBox *sbTopLeftX;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSpinBox *sbBottomRightY;
    QLabel *lY;
    QSpinBox *sbBottomRightX;
    QLabel *lX;
    QLabel *lCorner2;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_7;

    void setupUi(QWidget *WidgetSettingsROI)
    {
        if (WidgetSettingsROI->objectName().isEmpty())
            WidgetSettingsROI->setObjectName(QString::fromUtf8("WidgetSettingsROI"));
        WidgetSettingsROI->resize(422, 258);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WidgetSettingsROI->sizePolicy().hasHeightForWidth());
        WidgetSettingsROI->setSizePolicy(sizePolicy);
        WidgetSettingsROI->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(WidgetSettingsROI);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        labelTitle = new QLabel(WidgetSettingsROI);
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

        gridLayout_2->addWidget(labelTitle, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tbDefaultROI = new QToolButton(WidgetSettingsROI);
        tbDefaultROI->setObjectName(QString::fromUtf8("tbDefaultROI"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tbDefaultROI->sizePolicy().hasHeightForWidth());
        tbDefaultROI->setSizePolicy(sizePolicy1);
        tbDefaultROI->setMinimumSize(QSize(0, 0));
        QFont font1;
        font1.setPointSize(10);
        tbDefaultROI->setFont(font1);
        tbDefaultROI->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	background-color: rgb(84, 141, 105);\n"
"}"));

        gridLayout->addWidget(tbDefaultROI, 3, 3, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        lCorner1 = new QLabel(WidgetSettingsROI);
        lCorner1->setObjectName(QString::fromUtf8("lCorner1"));
        lCorner1->setEnabled(true);
        sizePolicy1.setHeightForWidth(lCorner1->sizePolicy().hasHeightForWidth());
        lCorner1->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setBold(false);
        font2.setWeight(50);
        lCorner1->setFont(font2);
        lCorner1->setStyleSheet(QString::fromUtf8("background-color:transparent;"));

        gridLayout->addWidget(lCorner1, 1, 1, 1, 1);

        sbTopLeftY = new QSpinBox(WidgetSettingsROI);
        sbTopLeftY->setObjectName(QString::fromUtf8("sbTopLeftY"));
        sbTopLeftY->setEnabled(true);
        sizePolicy1.setHeightForWidth(sbTopLeftY->sizePolicy().hasHeightForWidth());
        sbTopLeftY->setSizePolicy(sizePolicy1);
        sbTopLeftY->setMinimumSize(QSize(0, 0));
        sbTopLeftY->setMaximumSize(QSize(16777215, 16777215));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        sbTopLeftY->setFont(font3);
        sbTopLeftY->setStyleSheet(QString::fromUtf8(""));
        sbTopLeftY->setKeyboardTracking(false);
        sbTopLeftY->setMaximum(119);
        sbTopLeftY->setSingleStep(1);
        sbTopLeftY->setValue(0);

        gridLayout->addWidget(sbTopLeftY, 1, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 2, 1, 1);

        sbTopLeftX = new QSpinBox(WidgetSettingsROI);
        sbTopLeftX->setObjectName(QString::fromUtf8("sbTopLeftX"));
        sbTopLeftX->setEnabled(true);
        sizePolicy1.setHeightForWidth(sbTopLeftX->sizePolicy().hasHeightForWidth());
        sbTopLeftX->setSizePolicy(sizePolicy1);
        sbTopLeftX->setMinimumSize(QSize(0, 0));
        sbTopLeftX->setMaximumSize(QSize(16777215, 16777215));
        sbTopLeftX->setFont(font3);
        sbTopLeftX->setStyleSheet(QString::fromUtf8(""));
        sbTopLeftX->setKeyboardTracking(false);
        sbTopLeftX->setMaximum(319);
        sbTopLeftX->setSingleStep(1);
        sbTopLeftX->setValue(0);

        gridLayout->addWidget(sbTopLeftX, 1, 3, 1, 1);

        label = new QLabel(WidgetSettingsROI);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(0, 0));
        label->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        gridLayout->addWidget(label, 3, 1, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 3, 0, 1, 1);

        sbBottomRightY = new QSpinBox(WidgetSettingsROI);
        sbBottomRightY->setObjectName(QString::fromUtf8("sbBottomRightY"));
        sbBottomRightY->setEnabled(true);
        sizePolicy1.setHeightForWidth(sbBottomRightY->sizePolicy().hasHeightForWidth());
        sbBottomRightY->setSizePolicy(sizePolicy1);
        sbBottomRightY->setMinimumSize(QSize(0, 0));
        sbBottomRightY->setMaximumSize(QSize(16777215, 16777215));
        sbBottomRightY->setFont(font3);
        sbBottomRightY->setStyleSheet(QString::fromUtf8(""));
        sbBottomRightY->setKeyboardTracking(false);
        sbBottomRightY->setMinimum(120);
        sbBottomRightY->setMaximum(239);
        sbBottomRightY->setSingleStep(1);
        sbBottomRightY->setValue(239);

        gridLayout->addWidget(sbBottomRightY, 2, 4, 1, 1);

        lY = new QLabel(WidgetSettingsROI);
        lY->setObjectName(QString::fromUtf8("lY"));
        lY->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lY->sizePolicy().hasHeightForWidth());
        lY->setSizePolicy(sizePolicy2);
        lY->setFont(font2);
        lY->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        lY->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lY, 0, 4, 1, 1);

        sbBottomRightX = new QSpinBox(WidgetSettingsROI);
        sbBottomRightX->setObjectName(QString::fromUtf8("sbBottomRightX"));
        sbBottomRightX->setEnabled(true);
        sizePolicy1.setHeightForWidth(sbBottomRightX->sizePolicy().hasHeightForWidth());
        sbBottomRightX->setSizePolicy(sizePolicy1);
        sbBottomRightX->setMinimumSize(QSize(0, 0));
        sbBottomRightX->setMaximumSize(QSize(16777215, 16777215));
        sbBottomRightX->setFont(font3);
        sbBottomRightX->setStyleSheet(QString::fromUtf8(""));
        sbBottomRightX->setKeyboardTracking(false);
        sbBottomRightX->setMinimum(0);
        sbBottomRightX->setMaximum(319);
        sbBottomRightX->setSingleStep(1);
        sbBottomRightX->setValue(319);

        gridLayout->addWidget(sbBottomRightX, 2, 3, 1, 1);

        lX = new QLabel(WidgetSettingsROI);
        lX->setObjectName(QString::fromUtf8("lX"));
        lX->setEnabled(true);
        sizePolicy2.setHeightForWidth(lX->sizePolicy().hasHeightForWidth());
        lX->setSizePolicy(sizePolicy2);
        lX->setFont(font2);
        lX->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        lX->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lX, 0, 3, 1, 1);

        lCorner2 = new QLabel(WidgetSettingsROI);
        lCorner2->setObjectName(QString::fromUtf8("lCorner2"));
        lCorner2->setEnabled(true);
        sizePolicy1.setHeightForWidth(lCorner2->sizePolicy().hasHeightForWidth());
        lCorner2->setSizePolicy(sizePolicy1);
        lCorner2->setFont(font2);
        lCorner2->setStyleSheet(QString::fromUtf8("background-color:transparent;"));

        gridLayout->addWidget(lCorner2, 2, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 5, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 2, 5, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 3, 5, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);


        retranslateUi(WidgetSettingsROI);

        QMetaObject::connectSlotsByName(WidgetSettingsROI);
    } // setupUi

    void retranslateUi(QWidget *WidgetSettingsROI)
    {
        WidgetSettingsROI->setWindowTitle(QCoreApplication::translate("WidgetSettingsROI", "Form", nullptr));
        labelTitle->setText(QCoreApplication::translate("WidgetSettingsROI", "<html><head/><body><p>ROI SETTINGS</p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        tbDefaultROI->setToolTip(QCoreApplication::translate("WidgetSettingsROI", "<html><head/><body><p><span style=\" font-size:10pt;\">Resets the region of interest.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbDefaultROI->setText(QCoreApplication::translate("WidgetSettingsROI", "Default ROI", nullptr));
        lCorner1->setText(QCoreApplication::translate("WidgetSettingsROI", "Lower left corner", nullptr));
#if QT_CONFIG(tooltip)
        sbTopLeftY->setToolTip(QCoreApplication::translate("WidgetSettingsROI", "<html><head/><body><p><span style=\" font-size:10pt;\">Defines the left lower corner of the ROI.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        sbTopLeftX->setToolTip(QCoreApplication::translate("WidgetSettingsROI", "<html><head/><body><p><span style=\" font-size:10pt;\">Defines the left lower corner of the ROI.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label->setText(QCoreApplication::translate("WidgetSettingsROI", "Select ROI: Shift + left mouse", nullptr));
#if QT_CONFIG(tooltip)
        sbBottomRightY->setToolTip(QCoreApplication::translate("WidgetSettingsROI", "<html><head/><body><p><span style=\" font-size:10pt;\">Defines the right upper corner of the ROI.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lY->setText(QCoreApplication::translate("WidgetSettingsROI", "y", nullptr));
#if QT_CONFIG(tooltip)
        sbBottomRightX->setToolTip(QCoreApplication::translate("WidgetSettingsROI", "<html><head/><body><p><span style=\" font-size:10pt;\">Defines the right upper corner of the ROI.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lX->setText(QCoreApplication::translate("WidgetSettingsROI", "x", nullptr));
        lCorner2->setText(QCoreApplication::translate("WidgetSettingsROI", "Upper right corner", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetSettingsROI: public Ui_WidgetSettingsROI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_ROI_H
