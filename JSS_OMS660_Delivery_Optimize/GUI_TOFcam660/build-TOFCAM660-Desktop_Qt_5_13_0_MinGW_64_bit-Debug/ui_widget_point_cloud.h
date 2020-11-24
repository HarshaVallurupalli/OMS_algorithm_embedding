/********************************************************************************
** Form generated from reading UI file 'widget_point_cloud.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_POINT_CLOUD_H
#define UI_WIDGET_POINT_CLOUD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetPointCloud
{
public:
    QGridLayout *gridLayout;
    QWidget *widget3D;
    QSpacerItem *horizontalSpacer_6;
    QGridLayout *gridLayout_2;
    QToolButton *tbReset;
    QToolButton *tbView;
    QCheckBox *cbHorizontalFlip;
    QToolButton *tbSide;
    QCheckBox *cbRotate90;
    QToolButton *tbTop;
    QCheckBox *cbZoom;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *cbVerticalFlip;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *tbFront;
    QSpacerItem *horizontalSpacer;
    QToolButton *tbSettings;
    QCheckBox *cbShift;
    QSpacerItem *horizontalSpacer_22;
    QCheckBox *cbAutoRotating;
    QToolButton *tbShowControls;
    QCheckBox *cbRotate;

    void setupUi(QWidget *WidgetPointCloud)
    {
        if (WidgetPointCloud->objectName().isEmpty())
            WidgetPointCloud->setObjectName(QString::fromUtf8("WidgetPointCloud"));
        WidgetPointCloud->resize(1122, 334);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WidgetPointCloud->sizePolicy().hasHeightForWidth());
        WidgetPointCloud->setSizePolicy(sizePolicy);
        WidgetPointCloud->setMinimumSize(QSize(0, 0));
        WidgetPointCloud->setTabletTracking(true);
        WidgetPointCloud->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(WidgetPointCloud);
        gridLayout->setSpacing(5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget3D = new QWidget(WidgetPointCloud);
        widget3D->setObjectName(QString::fromUtf8("widget3D"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget3D->sizePolicy().hasHeightForWidth());
        widget3D->setSizePolicy(sizePolicy1);
        widget3D->setMinimumSize(QSize(0, 0));
        widget3D->setStyleSheet(QString::fromUtf8("background-color:rgb(0, 0, 0);"));

        gridLayout->addWidget(widget3D, 0, 0, 1, 7);

        horizontalSpacer_6 = new QSpacerItem(5, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 2, 5, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_2->setHorizontalSpacing(15);
        gridLayout_2->setVerticalSpacing(10);
        gridLayout_2->setContentsMargins(-1, 15, -1, 20);
        tbReset = new QToolButton(WidgetPointCloud);
        tbReset->setObjectName(QString::fromUtf8("tbReset"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tbReset->sizePolicy().hasHeightForWidth());
        tbReset->setSizePolicy(sizePolicy2);
        tbReset->setMinimumSize(QSize(0, 0));
        tbReset->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        tbReset->setFont(font);
        tbReset->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));
        tbReset->setToolButtonStyle(Qt::ToolButtonIconOnly);

        gridLayout_2->addWidget(tbReset, 0, 7, 1, 1);

        tbView = new QToolButton(WidgetPointCloud);
        tbView->setObjectName(QString::fromUtf8("tbView"));
        sizePolicy2.setHeightForWidth(tbView->sizePolicy().hasHeightForWidth());
        tbView->setSizePolicy(sizePolicy2);
        tbView->setFont(font);
        tbView->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));

        gridLayout_2->addWidget(tbView, 1, 4, 1, 1);

        cbHorizontalFlip = new QCheckBox(WidgetPointCloud);
        cbHorizontalFlip->setObjectName(QString::fromUtf8("cbHorizontalFlip"));
        cbHorizontalFlip->setMinimumSize(QSize(0, 0));
        cbHorizontalFlip->setMaximumSize(QSize(16777215, 16777215));
        cbHorizontalFlip->setFont(font);
        cbHorizontalFlip->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));

        gridLayout_2->addWidget(cbHorizontalFlip, 0, 3, 1, 1);

        tbSide = new QToolButton(WidgetPointCloud);
        tbSide->setObjectName(QString::fromUtf8("tbSide"));
        sizePolicy2.setHeightForWidth(tbSide->sizePolicy().hasHeightForWidth());
        tbSide->setSizePolicy(sizePolicy2);
        tbSide->setMinimumSize(QSize(0, 0));
        tbSide->setMaximumSize(QSize(16777215, 16777215));
        tbSide->setFont(font);
        tbSide->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));

        gridLayout_2->addWidget(tbSide, 1, 16, 1, 1);

        cbRotate90 = new QCheckBox(WidgetPointCloud);
        cbRotate90->setObjectName(QString::fromUtf8("cbRotate90"));
        cbRotate90->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));

        gridLayout_2->addWidget(cbRotate90, 0, 4, 1, 1);

        tbTop = new QToolButton(WidgetPointCloud);
        tbTop->setObjectName(QString::fromUtf8("tbTop"));
        sizePolicy2.setHeightForWidth(tbTop->sizePolicy().hasHeightForWidth());
        tbTop->setSizePolicy(sizePolicy2);
        tbTop->setMinimumSize(QSize(0, 0));
        tbTop->setMaximumSize(QSize(16777215, 16777215));
        tbTop->setFont(font);
        tbTop->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));

        gridLayout_2->addWidget(tbTop, 1, 17, 1, 1);

        cbZoom = new QCheckBox(WidgetPointCloud);
        cbZoom->setObjectName(QString::fromUtf8("cbZoom"));
        cbZoom->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));

        gridLayout_2->addWidget(cbZoom, 0, 12, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 8, 1, 1);

        cbVerticalFlip = new QCheckBox(WidgetPointCloud);
        cbVerticalFlip->setObjectName(QString::fromUtf8("cbVerticalFlip"));
        cbVerticalFlip->setMinimumSize(QSize(0, 0));
        cbVerticalFlip->setFont(font);
        cbVerticalFlip->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));

        gridLayout_2->addWidget(cbVerticalFlip, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 10, 1, 1);

        tbFront = new QToolButton(WidgetPointCloud);
        tbFront->setObjectName(QString::fromUtf8("tbFront"));
        sizePolicy2.setHeightForWidth(tbFront->sizePolicy().hasHeightForWidth());
        tbFront->setSizePolicy(sizePolicy2);
        tbFront->setMinimumSize(QSize(0, 0));
        tbFront->setMaximumSize(QSize(16777215, 16777215));
        tbFront->setFont(font);
        tbFront->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));

        gridLayout_2->addWidget(tbFront, 0, 17, 1, 1);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 5, 1, 1);

        tbSettings = new QToolButton(WidgetPointCloud);
        tbSettings->setObjectName(QString::fromUtf8("tbSettings"));
        sizePolicy2.setHeightForWidth(tbSettings->sizePolicy().hasHeightForWidth());
        tbSettings->setSizePolicy(sizePolicy2);
        tbSettings->setMinimumSize(QSize(0, 0));
        tbSettings->setMaximumSize(QSize(16777215, 16777215));
        tbSettings->setFont(font);
        tbSettings->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));

        gridLayout_2->addWidget(tbSettings, 0, 9, 1, 1);

        cbShift = new QCheckBox(WidgetPointCloud);
        cbShift->setObjectName(QString::fromUtf8("cbShift"));
        cbShift->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));
        cbShift->setTristate(false);

        gridLayout_2->addWidget(cbShift, 0, 11, 1, 1);

        horizontalSpacer_22 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_22, 0, 0, 1, 1);

        cbAutoRotating = new QCheckBox(WidgetPointCloud);
        cbAutoRotating->setObjectName(QString::fromUtf8("cbAutoRotating"));
        cbAutoRotating->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));

        gridLayout_2->addWidget(cbAutoRotating, 0, 14, 1, 1);

        tbShowControls = new QToolButton(WidgetPointCloud);
        tbShowControls->setObjectName(QString::fromUtf8("tbShowControls"));
        sizePolicy2.setHeightForWidth(tbShowControls->sizePolicy().hasHeightForWidth());
        tbShowControls->setSizePolicy(sizePolicy2);
        tbShowControls->setMinimumSize(QSize(0, 0));
        tbShowControls->setMaximumSize(QSize(16777215, 16777215));
        tbShowControls->setFont(font);
        tbShowControls->setLayoutDirection(Qt::LeftToRight);
        tbShowControls->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));

        gridLayout_2->addWidget(tbShowControls, 0, 16, 1, 1);

        cbRotate = new QCheckBox(WidgetPointCloud);
        cbRotate->setObjectName(QString::fromUtf8("cbRotate"));
        cbRotate->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";\n"
""));

        gridLayout_2->addWidget(cbRotate, 0, 13, 1, 1);


        gridLayout->addLayout(gridLayout_2, 2, 0, 2, 3);


        retranslateUi(WidgetPointCloud);

        QMetaObject::connectSlotsByName(WidgetPointCloud);
    } // setupUi

    void retranslateUi(QWidget *WidgetPointCloud)
    {
        WidgetPointCloud->setWindowTitle(QCoreApplication::translate("WidgetPointCloud", "Point Cloud", nullptr));
#if QT_CONFIG(tooltip)
        tbReset->setToolTip(QCoreApplication::translate("WidgetPointCloud", "<html><head/><body><p>Default point cloud view</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbReset->setText(QCoreApplication::translate("WidgetPointCloud", "Default view", nullptr));
        tbView->setText(QCoreApplication::translate("WidgetPointCloud", "View...", nullptr));
#if QT_CONFIG(tooltip)
        cbHorizontalFlip->setToolTip(QCoreApplication::translate("WidgetPointCloud", "<html><head/><body><p>Point cloud horizontal mirroring</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbHorizontalFlip->setText(QCoreApplication::translate("WidgetPointCloud", "Horizontal Flip", nullptr));
#if QT_CONFIG(tooltip)
        tbSide->setToolTip(QCoreApplication::translate("WidgetPointCloud", "<html><head/><body><p>Show side orthogonal projection</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbSide->setText(QCoreApplication::translate("WidgetPointCloud", "Side view", nullptr));
        cbRotate90->setText(QCoreApplication::translate("WidgetPointCloud", "Rotate 90\302\260", nullptr));
#if QT_CONFIG(tooltip)
        tbTop->setToolTip(QCoreApplication::translate("WidgetPointCloud", "<html><head/><body><p>Show top orthogonal projection</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbTop->setText(QCoreApplication::translate("WidgetPointCloud", "Top view", nullptr));
        cbZoom->setText(QCoreApplication::translate("WidgetPointCloud", "Zoom", nullptr));
#if QT_CONFIG(tooltip)
        cbVerticalFlip->setToolTip(QCoreApplication::translate("WidgetPointCloud", "<html><head/><body><p>Point cloud vertical mirroring</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbVerticalFlip->setText(QCoreApplication::translate("WidgetPointCloud", "Vertical Flip", nullptr));
#if QT_CONFIG(tooltip)
        tbFront->setToolTip(QCoreApplication::translate("WidgetPointCloud", "<html><head/><body><p>Show front orthogonal projection</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbFront->setText(QCoreApplication::translate("WidgetPointCloud", "Front view", nullptr));
#if QT_CONFIG(tooltip)
        tbSettings->setToolTip(QCoreApplication::translate("WidgetPointCloud", "<html><head/><body><p>Point cloud settings</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbSettings->setText(QCoreApplication::translate("WidgetPointCloud", "Settings...", nullptr));
        cbShift->setText(QCoreApplication::translate("WidgetPointCloud", "Shift", nullptr));
        cbAutoRotating->setText(QCoreApplication::translate("WidgetPointCloud", "Demo", nullptr));
#if QT_CONFIG(tooltip)
        tbShowControls->setToolTip(QCoreApplication::translate("WidgetPointCloud", "<html><head/><body><p>Show point cloud handling controls</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbShowControls->setText(QCoreApplication::translate("WidgetPointCloud", "Controls...", nullptr));
        cbRotate->setText(QCoreApplication::translate("WidgetPointCloud", "Rotation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetPointCloud: public Ui_WidgetPointCloud {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_POINT_CLOUD_H
