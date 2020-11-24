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
    QGridLayout *gridLayout;
    QGridLayout *gridLayoutROI;
    QLabel *lCorner2;
    QLabel *lY;
    QLabel *lX;
    QLabel *labelTitle;
    QSpinBox *sbBottomRightY;
    QSpinBox *sbTopLeftX;
    QSpinBox *sbTopLeftY;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpinBox *sbBottomRightX;
    QLabel *lCorner1;
    QToolButton *tbDefaultROI;

    void setupUi(QWidget *WidgetSettingsROI)
    {
        if (WidgetSettingsROI->objectName().isEmpty())
            WidgetSettingsROI->setObjectName(QString::fromUtf8("WidgetSettingsROI"));
        WidgetSettingsROI->resize(347, 161);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WidgetSettingsROI->sizePolicy().hasHeightForWidth());
        WidgetSettingsROI->setSizePolicy(sizePolicy);
        WidgetSettingsROI->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(WidgetSettingsROI);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayoutROI = new QGridLayout();
        gridLayoutROI->setSpacing(10);
        gridLayoutROI->setObjectName(QString::fromUtf8("gridLayoutROI"));
        lCorner2 = new QLabel(WidgetSettingsROI);
        lCorner2->setObjectName(QString::fromUtf8("lCorner2"));
        lCorner2->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lCorner2->sizePolicy().hasHeightForWidth());
        lCorner2->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setBold(false);
        font.setWeight(50);
        lCorner2->setFont(font);
        lCorner2->setStyleSheet(QString::fromUtf8("background-color:transparent;"));

        gridLayoutROI->addWidget(lCorner2, 2, 0, 1, 1);

        lY = new QLabel(WidgetSettingsROI);
        lY->setObjectName(QString::fromUtf8("lY"));
        lY->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lY->sizePolicy().hasHeightForWidth());
        lY->setSizePolicy(sizePolicy2);
        lY->setFont(font);
        lY->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        lY->setAlignment(Qt::AlignCenter);

        gridLayoutROI->addWidget(lY, 0, 3, 1, 1);

        lX = new QLabel(WidgetSettingsROI);
        lX->setObjectName(QString::fromUtf8("lX"));
        lX->setEnabled(true);
        sizePolicy2.setHeightForWidth(lX->sizePolicy().hasHeightForWidth());
        lX->setSizePolicy(sizePolicy2);
        lX->setFont(font);
        lX->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        lX->setAlignment(Qt::AlignCenter);

        gridLayoutROI->addWidget(lX, 0, 2, 1, 1);

        labelTitle = new QLabel(WidgetSettingsROI);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        sizePolicy1.setHeightForWidth(labelTitle->sizePolicy().hasHeightForWidth());
        labelTitle->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        labelTitle->setFont(font1);
        labelTitle->setStyleSheet(QString::fromUtf8("background-color:transparent;"));

        gridLayoutROI->addWidget(labelTitle, 0, 0, 1, 1);

        sbBottomRightY = new QSpinBox(WidgetSettingsROI);
        sbBottomRightY->setObjectName(QString::fromUtf8("sbBottomRightY"));
        sbBottomRightY->setEnabled(true);
        sizePolicy1.setHeightForWidth(sbBottomRightY->sizePolicy().hasHeightForWidth());
        sbBottomRightY->setSizePolicy(sizePolicy1);
        sbBottomRightY->setMinimumSize(QSize(0, 0));
        sbBottomRightY->setMaximumSize(QSize(16777215, 16777215));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        sbBottomRightY->setFont(font2);
        sbBottomRightY->setStyleSheet(QString::fromUtf8(""));
        sbBottomRightY->setKeyboardTracking(false);
        sbBottomRightY->setMinimum(120);
        sbBottomRightY->setMaximum(239);
        sbBottomRightY->setSingleStep(1);
        sbBottomRightY->setValue(239);

        gridLayoutROI->addWidget(sbBottomRightY, 2, 3, 1, 1);

        sbTopLeftX = new QSpinBox(WidgetSettingsROI);
        sbTopLeftX->setObjectName(QString::fromUtf8("sbTopLeftX"));
        sbTopLeftX->setEnabled(true);
        sizePolicy1.setHeightForWidth(sbTopLeftX->sizePolicy().hasHeightForWidth());
        sbTopLeftX->setSizePolicy(sizePolicy1);
        sbTopLeftX->setMinimumSize(QSize(0, 0));
        sbTopLeftX->setMaximumSize(QSize(16777215, 16777215));
        sbTopLeftX->setFont(font2);
        sbTopLeftX->setStyleSheet(QString::fromUtf8(""));
        sbTopLeftX->setKeyboardTracking(false);
        sbTopLeftX->setMaximum(319);
        sbTopLeftX->setSingleStep(1);
        sbTopLeftX->setValue(0);

        gridLayoutROI->addWidget(sbTopLeftX, 1, 2, 1, 1);

        sbTopLeftY = new QSpinBox(WidgetSettingsROI);
        sbTopLeftY->setObjectName(QString::fromUtf8("sbTopLeftY"));
        sbTopLeftY->setEnabled(true);
        sizePolicy1.setHeightForWidth(sbTopLeftY->sizePolicy().hasHeightForWidth());
        sbTopLeftY->setSizePolicy(sizePolicy1);
        sbTopLeftY->setMinimumSize(QSize(0, 0));
        sbTopLeftY->setMaximumSize(QSize(16777215, 16777215));
        sbTopLeftY->setFont(font2);
        sbTopLeftY->setStyleSheet(QString::fromUtf8(""));
        sbTopLeftY->setKeyboardTracking(false);
        sbTopLeftY->setMaximum(119);
        sbTopLeftY->setSingleStep(1);
        sbTopLeftY->setValue(0);

        gridLayoutROI->addWidget(sbTopLeftY, 1, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayoutROI->addItem(horizontalSpacer, 2, 1, 1, 1);

        label = new QLabel(WidgetSettingsROI);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(0, 0));
        label->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));

        gridLayoutROI->addWidget(label, 4, 2, 1, 2);

        sbBottomRightX = new QSpinBox(WidgetSettingsROI);
        sbBottomRightX->setObjectName(QString::fromUtf8("sbBottomRightX"));
        sbBottomRightX->setEnabled(true);
        sizePolicy1.setHeightForWidth(sbBottomRightX->sizePolicy().hasHeightForWidth());
        sbBottomRightX->setSizePolicy(sizePolicy1);
        sbBottomRightX->setMinimumSize(QSize(0, 0));
        sbBottomRightX->setMaximumSize(QSize(16777215, 16777215));
        sbBottomRightX->setFont(font2);
        sbBottomRightX->setStyleSheet(QString::fromUtf8(""));
        sbBottomRightX->setKeyboardTracking(false);
        sbBottomRightX->setMinimum(0);
        sbBottomRightX->setMaximum(319);
        sbBottomRightX->setSingleStep(1);
        sbBottomRightX->setValue(319);

        gridLayoutROI->addWidget(sbBottomRightX, 2, 2, 1, 1);

        lCorner1 = new QLabel(WidgetSettingsROI);
        lCorner1->setObjectName(QString::fromUtf8("lCorner1"));
        lCorner1->setEnabled(true);
        sizePolicy1.setHeightForWidth(lCorner1->sizePolicy().hasHeightForWidth());
        lCorner1->setSizePolicy(sizePolicy1);
        lCorner1->setFont(font);
        lCorner1->setStyleSheet(QString::fromUtf8("background-color:transparent;"));

        gridLayoutROI->addWidget(lCorner1, 1, 0, 1, 1);

        tbDefaultROI = new QToolButton(WidgetSettingsROI);
        tbDefaultROI->setObjectName(QString::fromUtf8("tbDefaultROI"));
        sizePolicy1.setHeightForWidth(tbDefaultROI->sizePolicy().hasHeightForWidth());
        tbDefaultROI->setSizePolicy(sizePolicy1);
        tbDefaultROI->setMinimumSize(QSize(0, 0));
        QFont font3;
        font3.setPointSize(10);
        tbDefaultROI->setFont(font3);
        tbDefaultROI->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	background-color: rgb(84, 141, 105);\n"
"}"));

        gridLayoutROI->addWidget(tbDefaultROI, 3, 2, 1, 2);


        gridLayout->addLayout(gridLayoutROI, 5, 2, 1, 1);


        retranslateUi(WidgetSettingsROI);

        QMetaObject::connectSlotsByName(WidgetSettingsROI);
    } // setupUi

    void retranslateUi(QWidget *WidgetSettingsROI)
    {
        WidgetSettingsROI->setWindowTitle(QCoreApplication::translate("WidgetSettingsROI", "Form", nullptr));
        lCorner2->setText(QCoreApplication::translate("WidgetSettingsROI", "Upper right corner", nullptr));
        lY->setText(QCoreApplication::translate("WidgetSettingsROI", "y", nullptr));
        lX->setText(QCoreApplication::translate("WidgetSettingsROI", "x", nullptr));
        labelTitle->setText(QCoreApplication::translate("WidgetSettingsROI", "ROI", nullptr));
#if QT_CONFIG(tooltip)
        sbBottomRightY->setToolTip(QCoreApplication::translate("WidgetSettingsROI", "<html><head/><body><p><span style=\" font-size:10pt;\">Defines the right upper corner of the ROI.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        sbTopLeftX->setToolTip(QCoreApplication::translate("WidgetSettingsROI", "<html><head/><body><p><span style=\" font-size:10pt;\">Defines the left lower corner of the ROI.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        sbTopLeftY->setToolTip(QCoreApplication::translate("WidgetSettingsROI", "<html><head/><body><p><span style=\" font-size:10pt;\">Defines the left lower corner of the ROI.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label->setText(QCoreApplication::translate("WidgetSettingsROI", "Select ROI: Shift + left mouse", nullptr));
#if QT_CONFIG(tooltip)
        sbBottomRightX->setToolTip(QCoreApplication::translate("WidgetSettingsROI", "<html><head/><body><p><span style=\" font-size:10pt;\">Defines the right upper corner of the ROI.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lCorner1->setText(QCoreApplication::translate("WidgetSettingsROI", "Lower left corner", nullptr));
#if QT_CONFIG(tooltip)
        tbDefaultROI->setToolTip(QCoreApplication::translate("WidgetSettingsROI", "<html><head/><body><p><span style=\" font-size:10pt;\">Resets the region of interest.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbDefaultROI->setText(QCoreApplication::translate("WidgetSettingsROI", "Default ROI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetSettingsROI: public Ui_WidgetSettingsROI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_ROI_H
