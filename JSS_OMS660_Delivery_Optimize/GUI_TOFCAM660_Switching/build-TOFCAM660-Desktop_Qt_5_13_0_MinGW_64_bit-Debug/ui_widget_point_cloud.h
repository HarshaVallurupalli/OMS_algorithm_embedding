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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetPointCloud
{
public:
    QGridLayout *gridLayout;
    QWidget *widget3D;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_15;
    QSpacerItem *horizontalSpacer_17;
    QToolButton *tbFront;
    QSpacerItem *horizontalSpacer_18;
    QToolButton *tbSide;
    QSpacerItem *horizontalSpacer_19;
    QToolButton *tbTop;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_13;
    QCheckBox *cbCartesian;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *cbSurfaceInterconnect;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_15;
    QCheckBox *cbUndistortion;
    QHBoxLayout *horizontalLayout;
    QCheckBox *cbGrayPointCloud;
    QSpacerItem *horizontalSpacer_14;
    QCheckBox *cbAxis2D;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_11;
    QCheckBox *cbPoints;
    QCheckBox *cbVerticalFlip;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *cbAxis3D;
    QHBoxLayout *horizontalLayout_3;
    QSpinBox *sbSurfaceInterconnect;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_11;
    QDoubleSpinBox *dbPointSize;
    QToolButton *tbShowControls;
    QSpacerItem *horizontalSpacer_22;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_16;
    QCheckBox *cbPerspectiveView;
    QHBoxLayout *horizontalLayout_12;
    QCheckBox *cbHorizontalFlip;
    QHBoxLayout *horizontalLayout_10;
    QCheckBox *cbGrid;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *cbAutoRotating;
    QToolButton *tbReset;
    QToolButton *tbFullScreenPC;
    QToolButton *tbSettings;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QWidget *WidgetPointCloud)
    {
        if (WidgetPointCloud->objectName().isEmpty())
            WidgetPointCloud->setObjectName(QString::fromUtf8("WidgetPointCloud"));
        WidgetPointCloud->resize(1065, 334);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WidgetPointCloud->sizePolicy().hasHeightForWidth());
        WidgetPointCloud->setSizePolicy(sizePolicy);
        WidgetPointCloud->setMinimumSize(QSize(0, 0));
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

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout_2->setContentsMargins(-1, 3, -1, 5);
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalSpacer_17 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_17);

        tbFront = new QToolButton(WidgetPointCloud);
        tbFront->setObjectName(QString::fromUtf8("tbFront"));
        tbFront->setMinimumSize(QSize(0, 0));
        tbFront->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        tbFront->setFont(font);
        tbFront->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));

        horizontalLayout_15->addWidget(tbFront);

        horizontalSpacer_18 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_18);

        tbSide = new QToolButton(WidgetPointCloud);
        tbSide->setObjectName(QString::fromUtf8("tbSide"));
        tbSide->setMinimumSize(QSize(0, 0));
        tbSide->setMaximumSize(QSize(16777215, 16777215));
        tbSide->setFont(font);
        tbSide->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));

        horizontalLayout_15->addWidget(tbSide);

        horizontalSpacer_19 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_19);

        tbTop = new QToolButton(WidgetPointCloud);
        tbTop->setObjectName(QString::fromUtf8("tbTop"));
        tbTop->setMinimumSize(QSize(0, 0));
        tbTop->setMaximumSize(QSize(16777215, 16777215));
        tbTop->setFont(font);
        tbTop->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));

        horizontalLayout_15->addWidget(tbTop);

        horizontalSpacer_5 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_5);


        gridLayout_2->addLayout(horizontalLayout_15, 0, 10, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 8, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_13 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_13);

        cbCartesian = new QCheckBox(WidgetPointCloud);
        cbCartesian->setObjectName(QString::fromUtf8("cbCartesian"));
        cbCartesian->setMinimumSize(QSize(0, 0));
        cbCartesian->setFont(font);
        cbCartesian->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));

        horizontalLayout_9->addWidget(cbCartesian);


        gridLayout_2->addLayout(horizontalLayout_9, 0, 5, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        cbSurfaceInterconnect = new QCheckBox(WidgetPointCloud);
        cbSurfaceInterconnect->setObjectName(QString::fromUtf8("cbSurfaceInterconnect"));
        cbSurfaceInterconnect->setMinimumSize(QSize(0, 0));
        cbSurfaceInterconnect->setFont(font);
        cbSurfaceInterconnect->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));

        horizontalLayout_7->addWidget(cbSurfaceInterconnect);

        horizontalSpacer_10 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_10);


        gridLayout_2->addLayout(horizontalLayout_7, 1, 1, 1, 1);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalSpacer_15 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_15);

        cbUndistortion = new QCheckBox(WidgetPointCloud);
        cbUndistortion->setObjectName(QString::fromUtf8("cbUndistortion"));
        cbUndistortion->setMinimumSize(QSize(0, 0));
        cbUndistortion->setFont(font);
        cbUndistortion->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));

        horizontalLayout_13->addWidget(cbUndistortion);


        gridLayout_2->addLayout(horizontalLayout_13, 2, 5, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cbGrayPointCloud = new QCheckBox(WidgetPointCloud);
        cbGrayPointCloud->setObjectName(QString::fromUtf8("cbGrayPointCloud"));
        cbGrayPointCloud->setMinimumSize(QSize(0, 0));
        cbGrayPointCloud->setFont(font);
        cbGrayPointCloud->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));

        horizontalLayout->addWidget(cbGrayPointCloud);

        horizontalSpacer_14 = new QSpacerItem(10, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_14);

        cbAxis2D = new QCheckBox(WidgetPointCloud);
        cbAxis2D->setObjectName(QString::fromUtf8("cbAxis2D"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cbAxis2D->sizePolicy().hasHeightForWidth());
        cbAxis2D->setSizePolicy(sizePolicy2);
        cbAxis2D->setMinimumSize(QSize(0, 0));
        cbAxis2D->setFont(font);
        cbAxis2D->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));

        horizontalLayout->addWidget(cbAxis2D);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        gridLayout_2->addLayout(horizontalLayout, 0, 1, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        cbPoints = new QCheckBox(WidgetPointCloud);
        cbPoints->setObjectName(QString::fromUtf8("cbPoints"));
        cbPoints->setMinimumSize(QSize(0, 0));
        cbPoints->setFont(font);
        cbPoints->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));

        horizontalLayout_11->addWidget(cbPoints);


        gridLayout_2->addLayout(horizontalLayout_11, 1, 3, 1, 1);

        cbVerticalFlip = new QCheckBox(WidgetPointCloud);
        cbVerticalFlip->setObjectName(QString::fromUtf8("cbVerticalFlip"));
        cbVerticalFlip->setMinimumSize(QSize(0, 0));
        cbVerticalFlip->setFont(font);
        cbVerticalFlip->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));

        gridLayout_2->addWidget(cbVerticalFlip, 2, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        cbAxis3D = new QCheckBox(WidgetPointCloud);
        cbAxis3D->setObjectName(QString::fromUtf8("cbAxis3D"));
        cbAxis3D->setMinimumSize(QSize(0, 0));
        cbAxis3D->setMaximumSize(QSize(170, 16777215));
        cbAxis3D->setFont(font);
        cbAxis3D->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));

        horizontalLayout_4->addWidget(cbAxis3D);


        gridLayout_2->addLayout(horizontalLayout_4, 0, 2, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        sbSurfaceInterconnect = new QSpinBox(WidgetPointCloud);
        sbSurfaceInterconnect->setObjectName(QString::fromUtf8("sbSurfaceInterconnect"));
        sbSurfaceInterconnect->setMinimumSize(QSize(0, 0));
        sbSurfaceInterconnect->setFont(font);
        sbSurfaceInterconnect->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));
        sbSurfaceInterconnect->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbSurfaceInterconnect->setMaximum(99999);
        sbSurfaceInterconnect->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        horizontalLayout_3->addWidget(sbSurfaceInterconnect);

        horizontalSpacer_9 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);


        gridLayout_2->addLayout(horizontalLayout_3, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 6, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_11 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_11);

        dbPointSize = new QDoubleSpinBox(WidgetPointCloud);
        dbPointSize->setObjectName(QString::fromUtf8("dbPointSize"));
        dbPointSize->setMinimumSize(QSize(0, 0));
        dbPointSize->setFont(font);
        dbPointSize->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));
        dbPointSize->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dbPointSize->setMaximum(999.990000000000009);
        dbPointSize->setSingleStep(0.500000000000000);
        dbPointSize->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        dbPointSize->setValue(2.500000000000000);

        horizontalLayout_6->addWidget(dbPointSize);


        gridLayout_2->addLayout(horizontalLayout_6, 1, 4, 1, 1);

        tbShowControls = new QToolButton(WidgetPointCloud);
        tbShowControls->setObjectName(QString::fromUtf8("tbShowControls"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tbShowControls->sizePolicy().hasHeightForWidth());
        tbShowControls->setSizePolicy(sizePolicy3);
        tbShowControls->setMinimumSize(QSize(0, 0));
        tbShowControls->setMaximumSize(QSize(16777215, 16777215));
        tbShowControls->setFont(font);
        tbShowControls->setLayoutDirection(Qt::LeftToRight);
        tbShowControls->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));

        gridLayout_2->addWidget(tbShowControls, 0, 7, 1, 1);

        horizontalSpacer_22 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_22, 0, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_16 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_16);

        cbPerspectiveView = new QCheckBox(WidgetPointCloud);
        cbPerspectiveView->setObjectName(QString::fromUtf8("cbPerspectiveView"));
        cbPerspectiveView->setFont(font);
        cbPerspectiveView->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));

        horizontalLayout_8->addWidget(cbPerspectiveView);


        gridLayout_2->addLayout(horizontalLayout_8, 1, 5, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        cbHorizontalFlip = new QCheckBox(WidgetPointCloud);
        cbHorizontalFlip->setObjectName(QString::fromUtf8("cbHorizontalFlip"));
        cbHorizontalFlip->setMinimumSize(QSize(0, 0));
        cbHorizontalFlip->setMaximumSize(QSize(16777215, 16777215));
        cbHorizontalFlip->setFont(font);
        cbHorizontalFlip->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));

        horizontalLayout_12->addWidget(cbHorizontalFlip);


        gridLayout_2->addLayout(horizontalLayout_12, 2, 2, 1, 2);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        cbGrid = new QCheckBox(WidgetPointCloud);
        cbGrid->setObjectName(QString::fromUtf8("cbGrid"));
        cbGrid->setMinimumSize(QSize(0, 0));
        cbGrid->setFont(font);
        cbGrid->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));

        horizontalLayout_10->addWidget(cbGrid);

        horizontalSpacer_4 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_4);


        gridLayout_2->addLayout(horizontalLayout_10, 0, 3, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        cbAutoRotating = new QCheckBox(WidgetPointCloud);
        cbAutoRotating->setObjectName(QString::fromUtf8("cbAutoRotating"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(cbAutoRotating->sizePolicy().hasHeightForWidth());
        cbAutoRotating->setSizePolicy(sizePolicy4);
        cbAutoRotating->setMinimumSize(QSize(0, 0));
        cbAutoRotating->setMaximumSize(QSize(150, 16777215));
        cbAutoRotating->setFont(font);
        cbAutoRotating->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));

        horizontalLayout_5->addWidget(cbAutoRotating);


        gridLayout_2->addLayout(horizontalLayout_5, 0, 4, 1, 1);

        tbReset = new QToolButton(WidgetPointCloud);
        tbReset->setObjectName(QString::fromUtf8("tbReset"));
        sizePolicy3.setHeightForWidth(tbReset->sizePolicy().hasHeightForWidth());
        tbReset->setSizePolicy(sizePolicy3);
        tbReset->setMinimumSize(QSize(0, 0));
        tbReset->setMaximumSize(QSize(16777215, 16777215));
        tbReset->setFont(font);
        tbReset->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));
        tbReset->setToolButtonStyle(Qt::ToolButtonIconOnly);

        gridLayout_2->addWidget(tbReset, 0, 9, 1, 1);

        tbFullScreenPC = new QToolButton(WidgetPointCloud);
        tbFullScreenPC->setObjectName(QString::fromUtf8("tbFullScreenPC"));
        sizePolicy3.setHeightForWidth(tbFullScreenPC->sizePolicy().hasHeightForWidth());
        tbFullScreenPC->setSizePolicy(sizePolicy3);
        tbFullScreenPC->setMinimumSize(QSize(0, 0));
        tbFullScreenPC->setMaximumSize(QSize(16777215, 16777215));
        tbFullScreenPC->setFont(font);
        tbFullScreenPC->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));
        tbFullScreenPC->setCheckable(true);

        gridLayout_2->addWidget(tbFullScreenPC, 1, 7, 1, 1);

        tbSettings = new QToolButton(WidgetPointCloud);
        tbSettings->setObjectName(QString::fromUtf8("tbSettings"));
        sizePolicy3.setHeightForWidth(tbSettings->sizePolicy().hasHeightForWidth());
        tbSettings->setSizePolicy(sizePolicy3);
        tbSettings->setMinimumSize(QSize(0, 0));
        tbSettings->setMaximumSize(QSize(16777215, 16777215));
        tbSettings->setFont(font);
        tbSettings->setStyleSheet(QString::fromUtf8("font: 10pt \"MS Shell Dlg 2\";"));

        gridLayout_2->addWidget(tbSettings, 1, 9, 1, 1);


        gridLayout->addLayout(gridLayout_2, 2, 0, 2, 5);

        horizontalSpacer_6 = new QSpacerItem(5, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 2, 5, 1, 1);


        retranslateUi(WidgetPointCloud);

        QMetaObject::connectSlotsByName(WidgetPointCloud);
    } // setupUi

    void retranslateUi(QWidget *WidgetPointCloud)
    {
        WidgetPointCloud->setWindowTitle(QCoreApplication::translate("WidgetPointCloud", "Point Cloud", nullptr));
#if QT_CONFIG(tooltip)
        tbFront->setToolTip(QCoreApplication::translate("WidgetPointCloud", "<html><head/><body><p>Show front orthogonal projection</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbFront->setText(QCoreApplication::translate("WidgetPointCloud", "Front", nullptr));
#if QT_CONFIG(tooltip)
        tbSide->setToolTip(QCoreApplication::translate("WidgetPointCloud", "<html><head/><body><p>Show side orthogonal projection</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbSide->setText(QCoreApplication::translate("WidgetPointCloud", "Side", nullptr));
#if QT_CONFIG(tooltip)
        tbTop->setToolTip(QCoreApplication::translate("WidgetPointCloud", "<html><head/><body><p>Show top orthogonal projection</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbTop->setText(QCoreApplication::translate("WidgetPointCloud", "Top", nullptr));
#if QT_CONFIG(tooltip)
        cbCartesian->setToolTip(QCoreApplication::translate("WidgetPointCloud", "<html><head/><body><p>Switch between raw data and cartesiant space</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbCartesian->setText(QCoreApplication::translate("WidgetPointCloud", "Cartesian", nullptr));
#if QT_CONFIG(tooltip)
        cbSurfaceInterconnect->setToolTip(QCoreApplication::translate("WidgetPointCloud", "<html><head/><body><p>Surface visualisation</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbSurfaceInterconnect->setText(QCoreApplication::translate("WidgetPointCloud", "Surface interconnect [mm]", nullptr));
#if QT_CONFIG(tooltip)
        cbUndistortion->setToolTip(QCoreApplication::translate("WidgetPointCloud", "<html><head/><body><p>Switch on/off optical lens undistortion</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbUndistortion->setText(QCoreApplication::translate("WidgetPointCloud", "Undistortion", nullptr));
#if QT_CONFIG(tooltip)
        cbGrayPointCloud->setToolTip(QCoreApplication::translate("WidgetPointCloud", "<html><head/><body><p>Grayscale surface created from amplitude</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbGrayPointCloud->setText(QCoreApplication::translate("WidgetPointCloud", "TOF amp OV", nullptr));
#if QT_CONFIG(tooltip)
        cbAxis2D->setToolTip(QCoreApplication::translate("WidgetPointCloud", "<html><head/><body><p>Plane field of view on the grid</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbAxis2D->setText(QCoreApplication::translate("WidgetPointCloud", "FOV 2D", nullptr));
#if QT_CONFIG(tooltip)
        cbPoints->setToolTip(QCoreApplication::translate("WidgetPointCloud", "<html><head/><body><p>Pont cloud visualisation</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbPoints->setText(QCoreApplication::translate("WidgetPointCloud", "Points", nullptr));
#if QT_CONFIG(tooltip)
        cbVerticalFlip->setToolTip(QCoreApplication::translate("WidgetPointCloud", "<html><head/><body><p>Point cloud vertical mirroring</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbVerticalFlip->setText(QCoreApplication::translate("WidgetPointCloud", "Vertical Flip", nullptr));
#if QT_CONFIG(tooltip)
        cbAxis3D->setToolTip(QCoreApplication::translate("WidgetPointCloud", "<html><head/><body><p>3D field of view</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbAxis3D->setText(QCoreApplication::translate("WidgetPointCloud", "FOV 3D", nullptr));
#if QT_CONFIG(tooltip)
        sbSurfaceInterconnect->setToolTip(QCoreApplication::translate("WidgetPointCloud", "<html><head/><body><p>Surface visualisation mesh filter threshold.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        dbPointSize->setToolTip(QCoreApplication::translate("WidgetPointCloud", "<html><head/><body><p>Point cloud pixel size</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        tbShowControls->setToolTip(QCoreApplication::translate("WidgetPointCloud", "<html><head/><body><p>Show point cloud handling controls</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbShowControls->setText(QCoreApplication::translate("WidgetPointCloud", "Controls...", nullptr));
#if QT_CONFIG(tooltip)
        cbPerspectiveView->setToolTip(QCoreApplication::translate("WidgetPointCloud", "<html><head/><body><p>Switch persective / orthogonal projections</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbPerspectiveView->setText(QCoreApplication::translate("WidgetPointCloud", "Perspective", nullptr));
#if QT_CONFIG(tooltip)
        cbHorizontalFlip->setToolTip(QCoreApplication::translate("WidgetPointCloud", "<html><head/><body><p>Point cloud horizontal mirroring</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbHorizontalFlip->setText(QCoreApplication::translate("WidgetPointCloud", "Horizontal Flip", nullptr));
#if QT_CONFIG(tooltip)
        cbGrid->setToolTip(QCoreApplication::translate("WidgetPointCloud", "<html><head/><body><p>The position of grid releative camera: offset x, y, z, cell size, cell number, color can be changed in settings</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbGrid->setText(QCoreApplication::translate("WidgetPointCloud", "Grid", nullptr));
#if QT_CONFIG(tooltip)
        cbAutoRotating->setToolTip(QCoreApplication::translate("WidgetPointCloud", "<html><head/><body><p>Point cloud auto rotation. The rotation can be programmed in script file</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbAutoRotating->setText(QCoreApplication::translate("WidgetPointCloud", "Auto", nullptr));
#if QT_CONFIG(tooltip)
        tbReset->setToolTip(QCoreApplication::translate("WidgetPointCloud", "<html><head/><body><p>Default point cloud view</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbReset->setText(QCoreApplication::translate("WidgetPointCloud", "Default view", nullptr));
#if QT_CONFIG(tooltip)
        tbFullScreenPC->setToolTip(QCoreApplication::translate("WidgetPointCloud", "<html><head/><body><p>Turn on full screen visualisation</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbFullScreenPC->setText(QCoreApplication::translate("WidgetPointCloud", "Full screen", nullptr));
#if QT_CONFIG(tooltip)
        tbSettings->setToolTip(QCoreApplication::translate("WidgetPointCloud", "<html><head/><body><p>Point cloud settings</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbSettings->setText(QCoreApplication::translate("WidgetPointCloud", "Settings...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetPointCloud: public Ui_WidgetPointCloud {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_POINT_CLOUD_H
