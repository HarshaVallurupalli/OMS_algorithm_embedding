/********************************************************************************
** Form generated from reading UI file 'widget_point_cloud_settings.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_POINT_CLOUD_SETTINGS_H
#define UI_WIDGET_POINT_CLOUD_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetPointCloudSettings
{
public:
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLabel *lObjectOffsetZ;
    QDoubleSpinBox *dbScaleZ;
    QSpinBox *sbAngleZ;
    QLabel *lCameraView;
    QSpinBox *sbCameraOffesetX;
    QLabel *lAngleZ;
    QLabel *lScaleZ;
    QToolButton *tbLabelFont;
    QLabel *lCameraAngleX;
    QSpinBox *sbAngleObjectZ;
    QDoubleSpinBox *dbScaleX;
    QLabel *lZoom;
    QSpinBox *sbAngleY;
    QCheckBox *cbShowLegend;
    QLabel *lColors;
    QCheckBox *cbShowLabels;
    QSpinBox *sbAxisLineWidth;
    QSpinBox *sbOffsetZ;
    QLabel *lAxisOffsetY;
    QLabel *lObjectOffsetY;
    QLabel *lNumberCells;
    QLabel *lScaleY;
    QSpinBox *sbOffsetY;
    QLabel *lAxis;
    QLabel *lAxisLineWidth;
    QSpinBox *sbObjectOffsetY;
    QLabel *lGridOffsetZ;
    QSpacerItem *horizontalSpacer_6;
    QDoubleSpinBox *sbdTransparent;
    QSpinBox *sbAxisOffsetZ;
    QSpinBox *sbAxisOffsetX;
    QDoubleSpinBox *dbAxisTransparent;
    QLabel *lAxisTransparent;
    QLabel *lCellWidth;
    QLabel *lLensAngle;
    QLabel *lAxisOffsetZ;
    QLabel *lScaleX;
    QLabel *lGridOffsetY;
    QSpinBox *sbLensAngle;
    QLabel *lCameraAngleY;
    QSpinBox *sbObjectOffsetZ;
    QLabel *lCameraOffesetY;
    QSpinBox *sbAngleX;
    QHBoxLayout *horizontalLayout;
    QToolButton *tbAxisColor;
    QToolButton *tbBackgroundColor;
    QToolButton *tbGridColor;
    QToolButton *tbLabelColor;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *tbClose;
    QLabel *lAxisOffsetX;
    QSpinBox *sbCameraOffesetY;
    QRadioButton *rbPolarGrid;
    QSpinBox *sbOffsetX;
    QLabel *lObjectOffsetX;
    QSpinBox *sbObjectOffsetX;
    QLabel *lCameraAngleZ;
    QLabel *lGridOffsetX;
    QDoubleSpinBox *dbScaleY;
    QDoubleSpinBox *dbZoom;
    QLabel *lCameraOffesetX;
    QSpinBox *sbAxisOffsetY;
    QLabel *lObject;
    QSpinBox *sbNumCells;
    QRadioButton *rbRectGrid;
    QLabel *lGridTransparent;
    QLabel *lGrid;
    QSpinBox *sbCellWidth;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *WidgetPointCloudSettings)
    {
        if (WidgetPointCloudSettings->objectName().isEmpty())
            WidgetPointCloudSettings->setObjectName(QString::fromUtf8("WidgetPointCloudSettings"));
        WidgetPointCloudSettings->resize(632, 416);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WidgetPointCloudSettings->sizePolicy().hasHeightForWidth());
        WidgetPointCloudSettings->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(WidgetPointCloudSettings);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, 6, -1, -1);
        scrollArea = new QScrollArea(WidgetPointCloudSettings);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy1);
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setLineWidth(0);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 614, 420));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy2);
        gridLayout_3 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 6, 0, -1);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(20);
        gridLayout->setVerticalSpacing(9);
        lObjectOffsetZ = new QLabel(scrollAreaWidgetContents);
        lObjectOffsetZ->setObjectName(QString::fromUtf8("lObjectOffsetZ"));
        lObjectOffsetZ->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setPointSize(8);
        lObjectOffsetZ->setFont(font);

        gridLayout->addWidget(lObjectOffsetZ, 7, 5, 1, 1);

        dbScaleZ = new QDoubleSpinBox(scrollAreaWidgetContents);
        dbScaleZ->setObjectName(QString::fromUtf8("dbScaleZ"));
        dbScaleZ->setMinimumSize(QSize(0, 0));
        dbScaleZ->setFont(font);
        dbScaleZ->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dbScaleZ->setMaximum(99.000000000000000);
        dbScaleZ->setSingleStep(0.100000000000000);

        gridLayout->addWidget(dbScaleZ, 8, 6, 1, 1);

        sbAngleZ = new QSpinBox(scrollAreaWidgetContents);
        sbAngleZ->setObjectName(QString::fromUtf8("sbAngleZ"));
        sbAngleZ->setMinimumSize(QSize(0, 0));
        sbAngleZ->setFont(font);
        sbAngleZ->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbAngleZ->setMinimum(-360);
        sbAngleZ->setMaximum(360);
        sbAngleZ->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        sbAngleZ->setValue(181);

        gridLayout->addWidget(sbAngleZ, 10, 6, 1, 1);

        lCameraView = new QLabel(scrollAreaWidgetContents);
        lCameraView->setObjectName(QString::fromUtf8("lCameraView"));
        lCameraView->setMinimumSize(QSize(0, 0));
        QFont font1;
        font1.setPointSize(8);
        font1.setBold(true);
        font1.setWeight(75);
        lCameraView->setFont(font1);

        gridLayout->addWidget(lCameraView, 9, 1, 1, 1);

        sbCameraOffesetX = new QSpinBox(scrollAreaWidgetContents);
        sbCameraOffesetX->setObjectName(QString::fromUtf8("sbCameraOffesetX"));
        sbCameraOffesetX->setMinimumSize(QSize(0, 0));
        sbCameraOffesetX->setFont(font);
        sbCameraOffesetX->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbCameraOffesetX->setMinimum(-1000000);
        sbCameraOffesetX->setMaximum(1000000);
        sbCameraOffesetX->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout->addWidget(sbCameraOffesetX, 12, 2, 1, 1);

        lAngleZ = new QLabel(scrollAreaWidgetContents);
        lAngleZ->setObjectName(QString::fromUtf8("lAngleZ"));
        lAngleZ->setMinimumSize(QSize(0, 0));
        lAngleZ->setFont(font);

        gridLayout->addWidget(lAngleZ, 6, 5, 1, 1);

        lScaleZ = new QLabel(scrollAreaWidgetContents);
        lScaleZ->setObjectName(QString::fromUtf8("lScaleZ"));
        lScaleZ->setMinimumSize(QSize(0, 0));
        lScaleZ->setFont(font);

        gridLayout->addWidget(lScaleZ, 8, 5, 1, 1);

        tbLabelFont = new QToolButton(scrollAreaWidgetContents);
        tbLabelFont->setObjectName(QString::fromUtf8("tbLabelFont"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tbLabelFont->sizePolicy().hasHeightForWidth());
        tbLabelFont->setSizePolicy(sizePolicy3);
        tbLabelFont->setMinimumSize(QSize(0, 0));
        tbLabelFont->setFont(font);

        gridLayout->addWidget(tbLabelFont, 13, 3, 1, 1);

        lCameraAngleX = new QLabel(scrollAreaWidgetContents);
        lCameraAngleX->setObjectName(QString::fromUtf8("lCameraAngleX"));
        lCameraAngleX->setMinimumSize(QSize(0, 0));
        lCameraAngleX->setFont(font);

        gridLayout->addWidget(lCameraAngleX, 10, 1, 1, 1);

        sbAngleObjectZ = new QSpinBox(scrollAreaWidgetContents);
        sbAngleObjectZ->setObjectName(QString::fromUtf8("sbAngleObjectZ"));
        sbAngleObjectZ->setMinimumSize(QSize(0, 0));
        sbAngleObjectZ->setFont(font);
        sbAngleObjectZ->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbAngleObjectZ->setMinimum(-180);
        sbAngleObjectZ->setMaximum(180);
        sbAngleObjectZ->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout->addWidget(sbAngleObjectZ, 6, 6, 1, 1);

        dbScaleX = new QDoubleSpinBox(scrollAreaWidgetContents);
        dbScaleX->setObjectName(QString::fromUtf8("dbScaleX"));
        dbScaleX->setMinimumSize(QSize(0, 0));
        dbScaleX->setFont(font);
        dbScaleX->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dbScaleX->setMaximum(99.000000000000000);
        dbScaleX->setSingleStep(0.100000000000000);

        gridLayout->addWidget(dbScaleX, 8, 2, 1, 1);

        lZoom = new QLabel(scrollAreaWidgetContents);
        lZoom->setObjectName(QString::fromUtf8("lZoom"));
        lZoom->setMinimumSize(QSize(0, 0));
        lZoom->setFont(font);

        gridLayout->addWidget(lZoom, 12, 5, 1, 1);

        sbAngleY = new QSpinBox(scrollAreaWidgetContents);
        sbAngleY->setObjectName(QString::fromUtf8("sbAngleY"));
        sbAngleY->setMinimumSize(QSize(0, 0));
        sbAngleY->setFont(font);
        sbAngleY->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbAngleY->setMinimum(-360);
        sbAngleY->setMaximum(360);
        sbAngleY->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        sbAngleY->setValue(17);

        gridLayout->addWidget(sbAngleY, 10, 4, 1, 1);

        cbShowLegend = new QCheckBox(scrollAreaWidgetContents);
        cbShowLegend->setObjectName(QString::fromUtf8("cbShowLegend"));
        cbShowLegend->setMinimumSize(QSize(0, 0));
        cbShowLegend->setFont(font);
        cbShowLegend->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(cbShowLegend, 13, 2, 1, 1);

        lColors = new QLabel(scrollAreaWidgetContents);
        lColors->setObjectName(QString::fromUtf8("lColors"));
        lColors->setMinimumSize(QSize(0, 0));
        lColors->setFont(font1);

        gridLayout->addWidget(lColors, 13, 1, 1, 1);

        cbShowLabels = new QCheckBox(scrollAreaWidgetContents);
        cbShowLabels->setObjectName(QString::fromUtf8("cbShowLabels"));
        cbShowLabels->setMinimumSize(QSize(0, 0));
        cbShowLabels->setFont(font);
        cbShowLabels->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(cbShowLabels, 2, 5, 1, 1);

        sbAxisLineWidth = new QSpinBox(scrollAreaWidgetContents);
        sbAxisLineWidth->setObjectName(QString::fromUtf8("sbAxisLineWidth"));
        sbAxisLineWidth->setMinimumSize(QSize(0, 0));
        sbAxisLineWidth->setFont(font);
        sbAxisLineWidth->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbAxisLineWidth->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout->addWidget(sbAxisLineWidth, 2, 4, 1, 1);

        sbOffsetZ = new QSpinBox(scrollAreaWidgetContents);
        sbOffsetZ->setObjectName(QString::fromUtf8("sbOffsetZ"));
        sbOffsetZ->setMinimumSize(QSize(0, 0));
        sbOffsetZ->setFont(font);
        sbOffsetZ->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbOffsetZ->setMinimum(-100000);
        sbOffsetZ->setMaximum(100000);
        sbOffsetZ->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout->addWidget(sbOffsetZ, 5, 6, 1, 1);

        lAxisOffsetY = new QLabel(scrollAreaWidgetContents);
        lAxisOffsetY->setObjectName(QString::fromUtf8("lAxisOffsetY"));
        lAxisOffsetY->setMinimumSize(QSize(0, 0));
        lAxisOffsetY->setFont(font);

        gridLayout->addWidget(lAxisOffsetY, 1, 3, 1, 1);

        lObjectOffsetY = new QLabel(scrollAreaWidgetContents);
        lObjectOffsetY->setObjectName(QString::fromUtf8("lObjectOffsetY"));
        lObjectOffsetY->setMinimumSize(QSize(0, 0));
        lObjectOffsetY->setFont(font);

        gridLayout->addWidget(lObjectOffsetY, 7, 3, 1, 1);

        lNumberCells = new QLabel(scrollAreaWidgetContents);
        lNumberCells->setObjectName(QString::fromUtf8("lNumberCells"));
        lNumberCells->setMinimumSize(QSize(0, 0));
        lNumberCells->setFont(font);

        gridLayout->addWidget(lNumberCells, 4, 5, 1, 1);

        lScaleY = new QLabel(scrollAreaWidgetContents);
        lScaleY->setObjectName(QString::fromUtf8("lScaleY"));
        lScaleY->setMinimumSize(QSize(0, 0));
        lScaleY->setFont(font);

        gridLayout->addWidget(lScaleY, 8, 3, 1, 1);

        sbOffsetY = new QSpinBox(scrollAreaWidgetContents);
        sbOffsetY->setObjectName(QString::fromUtf8("sbOffsetY"));
        sbOffsetY->setMinimumSize(QSize(0, 0));
        sbOffsetY->setFont(font);
        sbOffsetY->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbOffsetY->setMinimum(-10000);
        sbOffsetY->setMaximum(10000);
        sbOffsetY->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout->addWidget(sbOffsetY, 5, 4, 1, 1);

        lAxis = new QLabel(scrollAreaWidgetContents);
        lAxis->setObjectName(QString::fromUtf8("lAxis"));
        lAxis->setMinimumSize(QSize(0, 0));
        lAxis->setFont(font1);

        gridLayout->addWidget(lAxis, 2, 1, 1, 1);

        lAxisLineWidth = new QLabel(scrollAreaWidgetContents);
        lAxisLineWidth->setObjectName(QString::fromUtf8("lAxisLineWidth"));
        lAxisLineWidth->setMinimumSize(QSize(0, 0));
        lAxisLineWidth->setFont(font);

        gridLayout->addWidget(lAxisLineWidth, 2, 3, 1, 1);

        sbObjectOffsetY = new QSpinBox(scrollAreaWidgetContents);
        sbObjectOffsetY->setObjectName(QString::fromUtf8("sbObjectOffsetY"));
        sbObjectOffsetY->setMinimumSize(QSize(0, 0));
        sbObjectOffsetY->setFont(font);
        sbObjectOffsetY->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbObjectOffsetY->setMinimum(-100000);
        sbObjectOffsetY->setMaximum(100000);
        sbObjectOffsetY->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout->addWidget(sbObjectOffsetY, 7, 4, 1, 1);

        lGridOffsetZ = new QLabel(scrollAreaWidgetContents);
        lGridOffsetZ->setObjectName(QString::fromUtf8("lGridOffsetZ"));
        lGridOffsetZ->setMinimumSize(QSize(0, 0));
        lGridOffsetZ->setFont(font);

        gridLayout->addWidget(lGridOffsetZ, 5, 5, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 4, 0, 1, 1);

        sbdTransparent = new QDoubleSpinBox(scrollAreaWidgetContents);
        sbdTransparent->setObjectName(QString::fromUtf8("sbdTransparent"));
        sbdTransparent->setMinimumSize(QSize(0, 0));
        sbdTransparent->setFont(font);
        sbdTransparent->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbdTransparent->setMaximum(1.000000000000000);
        sbdTransparent->setSingleStep(0.100000000000000);
        sbdTransparent->setValue(0.500000000000000);

        gridLayout->addWidget(sbdTransparent, 0, 6, 1, 1);

        sbAxisOffsetZ = new QSpinBox(scrollAreaWidgetContents);
        sbAxisOffsetZ->setObjectName(QString::fromUtf8("sbAxisOffsetZ"));
        sbAxisOffsetZ->setMinimumSize(QSize(0, 0));
        sbAxisOffsetZ->setFont(font);
        sbAxisOffsetZ->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbAxisOffsetZ->setMinimum(-100000);
        sbAxisOffsetZ->setMaximum(100000);
        sbAxisOffsetZ->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout->addWidget(sbAxisOffsetZ, 1, 6, 1, 1);

        sbAxisOffsetX = new QSpinBox(scrollAreaWidgetContents);
        sbAxisOffsetX->setObjectName(QString::fromUtf8("sbAxisOffsetX"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(sbAxisOffsetX->sizePolicy().hasHeightForWidth());
        sbAxisOffsetX->setSizePolicy(sizePolicy4);
        sbAxisOffsetX->setMinimumSize(QSize(0, 0));
        sbAxisOffsetX->setFont(font);
        sbAxisOffsetX->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbAxisOffsetX->setMinimum(-100000);
        sbAxisOffsetX->setMaximum(100000);
        sbAxisOffsetX->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout->addWidget(sbAxisOffsetX, 1, 2, 1, 1);

        dbAxisTransparent = new QDoubleSpinBox(scrollAreaWidgetContents);
        dbAxisTransparent->setObjectName(QString::fromUtf8("dbAxisTransparent"));
        dbAxisTransparent->setMinimumSize(QSize(0, 0));
        dbAxisTransparent->setFont(font);
        dbAxisTransparent->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dbAxisTransparent->setMaximum(1.000000000000000);
        dbAxisTransparent->setSingleStep(0.100000000000000);
        dbAxisTransparent->setValue(0.500000000000000);

        gridLayout->addWidget(dbAxisTransparent, 13, 6, 1, 1);

        lAxisTransparent = new QLabel(scrollAreaWidgetContents);
        lAxisTransparent->setObjectName(QString::fromUtf8("lAxisTransparent"));
        lAxisTransparent->setMinimumSize(QSize(0, 0));
        lAxisTransparent->setFont(font);

        gridLayout->addWidget(lAxisTransparent, 13, 5, 1, 1);

        lCellWidth = new QLabel(scrollAreaWidgetContents);
        lCellWidth->setObjectName(QString::fromUtf8("lCellWidth"));
        lCellWidth->setMinimumSize(QSize(0, 0));
        lCellWidth->setFont(font);

        gridLayout->addWidget(lCellWidth, 4, 3, 1, 1);

        lLensAngle = new QLabel(scrollAreaWidgetContents);
        lLensAngle->setObjectName(QString::fromUtf8("lLensAngle"));
        lLensAngle->setMinimumSize(QSize(0, 0));
        lLensAngle->setFont(font);

        gridLayout->addWidget(lLensAngle, 6, 3, 1, 1);

        lAxisOffsetZ = new QLabel(scrollAreaWidgetContents);
        lAxisOffsetZ->setObjectName(QString::fromUtf8("lAxisOffsetZ"));
        lAxisOffsetZ->setMinimumSize(QSize(0, 0));
        lAxisOffsetZ->setFont(font);

        gridLayout->addWidget(lAxisOffsetZ, 1, 5, 1, 1);

        lScaleX = new QLabel(scrollAreaWidgetContents);
        lScaleX->setObjectName(QString::fromUtf8("lScaleX"));
        lScaleX->setMinimumSize(QSize(0, 0));
        lScaleX->setFont(font);

        gridLayout->addWidget(lScaleX, 8, 1, 1, 1);

        lGridOffsetY = new QLabel(scrollAreaWidgetContents);
        lGridOffsetY->setObjectName(QString::fromUtf8("lGridOffsetY"));
        lGridOffsetY->setMinimumSize(QSize(0, 0));
        lGridOffsetY->setFont(font);

        gridLayout->addWidget(lGridOffsetY, 5, 3, 1, 1);

        sbLensAngle = new QSpinBox(scrollAreaWidgetContents);
        sbLensAngle->setObjectName(QString::fromUtf8("sbLensAngle"));
        sbLensAngle->setMinimumSize(QSize(0, 0));
        sbLensAngle->setFont(font);
        sbLensAngle->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbLensAngle->setMaximum(180);
        sbLensAngle->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout->addWidget(sbLensAngle, 6, 4, 1, 1);

        lCameraAngleY = new QLabel(scrollAreaWidgetContents);
        lCameraAngleY->setObjectName(QString::fromUtf8("lCameraAngleY"));
        lCameraAngleY->setMinimumSize(QSize(0, 0));
        lCameraAngleY->setFont(font);

        gridLayout->addWidget(lCameraAngleY, 10, 3, 1, 1);

        sbObjectOffsetZ = new QSpinBox(scrollAreaWidgetContents);
        sbObjectOffsetZ->setObjectName(QString::fromUtf8("sbObjectOffsetZ"));
        sbObjectOffsetZ->setMinimumSize(QSize(0, 0));
        sbObjectOffsetZ->setFont(font);
        sbObjectOffsetZ->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbObjectOffsetZ->setMinimum(-100000);
        sbObjectOffsetZ->setMaximum(100000);
        sbObjectOffsetZ->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout->addWidget(sbObjectOffsetZ, 7, 6, 1, 1);

        lCameraOffesetY = new QLabel(scrollAreaWidgetContents);
        lCameraOffesetY->setObjectName(QString::fromUtf8("lCameraOffesetY"));
        lCameraOffesetY->setMinimumSize(QSize(0, 0));
        lCameraOffesetY->setFont(font);

        gridLayout->addWidget(lCameraOffesetY, 12, 3, 1, 1);

        sbAngleX = new QSpinBox(scrollAreaWidgetContents);
        sbAngleX->setObjectName(QString::fromUtf8("sbAngleX"));
        sbAngleX->setMinimumSize(QSize(0, 0));
        sbAngleX->setFont(font);
        sbAngleX->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbAngleX->setMinimum(-360);
        sbAngleX->setMaximum(360);
        sbAngleX->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        sbAngleX->setValue(-67);

        gridLayout->addWidget(sbAngleX, 10, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, 0);
        tbAxisColor = new QToolButton(scrollAreaWidgetContents);
        tbAxisColor->setObjectName(QString::fromUtf8("tbAxisColor"));
        sizePolicy3.setHeightForWidth(tbAxisColor->sizePolicy().hasHeightForWidth());
        tbAxisColor->setSizePolicy(sizePolicy3);
        tbAxisColor->setMinimumSize(QSize(0, 0));
        tbAxisColor->setMaximumSize(QSize(16777215, 16777215));
        tbAxisColor->setFont(font);

        horizontalLayout->addWidget(tbAxisColor);

        tbBackgroundColor = new QToolButton(scrollAreaWidgetContents);
        tbBackgroundColor->setObjectName(QString::fromUtf8("tbBackgroundColor"));
        sizePolicy3.setHeightForWidth(tbBackgroundColor->sizePolicy().hasHeightForWidth());
        tbBackgroundColor->setSizePolicy(sizePolicy3);
        tbBackgroundColor->setMinimumSize(QSize(0, 0));
        tbBackgroundColor->setMaximumSize(QSize(16777215, 16777215));
        tbBackgroundColor->setFont(font);

        horizontalLayout->addWidget(tbBackgroundColor);

        tbGridColor = new QToolButton(scrollAreaWidgetContents);
        tbGridColor->setObjectName(QString::fromUtf8("tbGridColor"));
        sizePolicy3.setHeightForWidth(tbGridColor->sizePolicy().hasHeightForWidth());
        tbGridColor->setSizePolicy(sizePolicy3);
        tbGridColor->setMinimumSize(QSize(0, 0));
        tbGridColor->setMaximumSize(QSize(16777215, 16777215));
        tbGridColor->setFont(font);

        horizontalLayout->addWidget(tbGridColor);

        tbLabelColor = new QToolButton(scrollAreaWidgetContents);
        tbLabelColor->setObjectName(QString::fromUtf8("tbLabelColor"));
        sizePolicy3.setHeightForWidth(tbLabelColor->sizePolicy().hasHeightForWidth());
        tbLabelColor->setSizePolicy(sizePolicy3);
        tbLabelColor->setMinimumSize(QSize(0, 0));
        tbLabelColor->setMaximumSize(QSize(16777215, 16777215));
        tbLabelColor->setFont(font);

        horizontalLayout->addWidget(tbLabelColor);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        tbClose = new QToolButton(scrollAreaWidgetContents);
        tbClose->setObjectName(QString::fromUtf8("tbClose"));
        sizePolicy3.setHeightForWidth(tbClose->sizePolicy().hasHeightForWidth());
        tbClose->setSizePolicy(sizePolicy3);
        tbClose->setMinimumSize(QSize(0, 0));
        tbClose->setMaximumSize(QSize(16777215, 16777215));
        tbClose->setFont(font);

        horizontalLayout->addWidget(tbClose);


        gridLayout->addLayout(horizontalLayout, 14, 1, 1, 6);

        lAxisOffsetX = new QLabel(scrollAreaWidgetContents);
        lAxisOffsetX->setObjectName(QString::fromUtf8("lAxisOffsetX"));
        lAxisOffsetX->setMinimumSize(QSize(0, 0));
        lAxisOffsetX->setFont(font);

        gridLayout->addWidget(lAxisOffsetX, 1, 1, 1, 1);

        sbCameraOffesetY = new QSpinBox(scrollAreaWidgetContents);
        sbCameraOffesetY->setObjectName(QString::fromUtf8("sbCameraOffesetY"));
        sbCameraOffesetY->setMinimumSize(QSize(0, 0));
        sbCameraOffesetY->setFont(font);
        sbCameraOffesetY->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbCameraOffesetY->setMinimum(-1000000);
        sbCameraOffesetY->setMaximum(1000000);
        sbCameraOffesetY->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout->addWidget(sbCameraOffesetY, 12, 4, 1, 1);

        rbPolarGrid = new QRadioButton(scrollAreaWidgetContents);
        rbPolarGrid->setObjectName(QString::fromUtf8("rbPolarGrid"));
        rbPolarGrid->setMinimumSize(QSize(0, 0));
        rbPolarGrid->setFont(font);
        rbPolarGrid->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(rbPolarGrid, 0, 3, 1, 1);

        sbOffsetX = new QSpinBox(scrollAreaWidgetContents);
        sbOffsetX->setObjectName(QString::fromUtf8("sbOffsetX"));
        sbOffsetX->setMinimumSize(QSize(0, 0));
        sbOffsetX->setFont(font);
        sbOffsetX->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbOffsetX->setMinimum(-100000);
        sbOffsetX->setMaximum(100000);
        sbOffsetX->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout->addWidget(sbOffsetX, 5, 2, 1, 1);

        lObjectOffsetX = new QLabel(scrollAreaWidgetContents);
        lObjectOffsetX->setObjectName(QString::fromUtf8("lObjectOffsetX"));
        lObjectOffsetX->setMinimumSize(QSize(0, 0));
        lObjectOffsetX->setFont(font);

        gridLayout->addWidget(lObjectOffsetX, 7, 1, 1, 1);

        sbObjectOffsetX = new QSpinBox(scrollAreaWidgetContents);
        sbObjectOffsetX->setObjectName(QString::fromUtf8("sbObjectOffsetX"));
        sbObjectOffsetX->setMinimumSize(QSize(0, 0));
        sbObjectOffsetX->setFont(font);
        sbObjectOffsetX->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbObjectOffsetX->setMinimum(-100000);
        sbObjectOffsetX->setMaximum(100000);
        sbObjectOffsetX->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout->addWidget(sbObjectOffsetX, 7, 2, 1, 1);

        lCameraAngleZ = new QLabel(scrollAreaWidgetContents);
        lCameraAngleZ->setObjectName(QString::fromUtf8("lCameraAngleZ"));
        lCameraAngleZ->setMinimumSize(QSize(0, 0));
        lCameraAngleZ->setFont(font);

        gridLayout->addWidget(lCameraAngleZ, 10, 5, 1, 1);

        lGridOffsetX = new QLabel(scrollAreaWidgetContents);
        lGridOffsetX->setObjectName(QString::fromUtf8("lGridOffsetX"));
        lGridOffsetX->setMinimumSize(QSize(0, 0));
        lGridOffsetX->setFont(font);

        gridLayout->addWidget(lGridOffsetX, 5, 1, 1, 1);

        dbScaleY = new QDoubleSpinBox(scrollAreaWidgetContents);
        dbScaleY->setObjectName(QString::fromUtf8("dbScaleY"));
        dbScaleY->setMinimumSize(QSize(0, 0));
        dbScaleY->setFont(font);
        dbScaleY->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dbScaleY->setMaximum(99.000000000000000);
        dbScaleY->setSingleStep(0.100000000000000);

        gridLayout->addWidget(dbScaleY, 8, 4, 1, 1);

        dbZoom = new QDoubleSpinBox(scrollAreaWidgetContents);
        dbZoom->setObjectName(QString::fromUtf8("dbZoom"));
        dbZoom->setMinimumSize(QSize(0, 0));
        dbZoom->setFont(font);
        dbZoom->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dbZoom->setMaximum(1000.000000000000000);
        dbZoom->setSingleStep(0.100000000000000);
        dbZoom->setStepType(QAbstractSpinBox::DefaultStepType);
        dbZoom->setValue(1.000000000000000);

        gridLayout->addWidget(dbZoom, 12, 6, 1, 1);

        lCameraOffesetX = new QLabel(scrollAreaWidgetContents);
        lCameraOffesetX->setObjectName(QString::fromUtf8("lCameraOffesetX"));
        lCameraOffesetX->setMinimumSize(QSize(0, 0));
        lCameraOffesetX->setFont(font);

        gridLayout->addWidget(lCameraOffesetX, 12, 1, 1, 1);

        sbAxisOffsetY = new QSpinBox(scrollAreaWidgetContents);
        sbAxisOffsetY->setObjectName(QString::fromUtf8("sbAxisOffsetY"));
        sbAxisOffsetY->setMinimumSize(QSize(0, 0));
        sbAxisOffsetY->setFont(font);
        sbAxisOffsetY->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbAxisOffsetY->setMinimum(-10000);
        sbAxisOffsetY->setMaximum(10000);
        sbAxisOffsetY->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout->addWidget(sbAxisOffsetY, 1, 4, 1, 1);

        lObject = new QLabel(scrollAreaWidgetContents);
        lObject->setObjectName(QString::fromUtf8("lObject"));
        lObject->setMinimumSize(QSize(0, 0));
        lObject->setFont(font1);

        gridLayout->addWidget(lObject, 6, 1, 1, 1);

        sbNumCells = new QSpinBox(scrollAreaWidgetContents);
        sbNumCells->setObjectName(QString::fromUtf8("sbNumCells"));
        sbNumCells->setMinimumSize(QSize(0, 0));
        sbNumCells->setFont(font);
        sbNumCells->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbNumCells->setMaximum(1000);
        sbNumCells->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        sbNumCells->setValue(20);

        gridLayout->addWidget(sbNumCells, 4, 6, 1, 1);

        rbRectGrid = new QRadioButton(scrollAreaWidgetContents);
        rbRectGrid->setObjectName(QString::fromUtf8("rbRectGrid"));
        rbRectGrid->setMinimumSize(QSize(0, 0));
        rbRectGrid->setFont(font);
        rbRectGrid->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(rbRectGrid, 0, 2, 1, 1);

        lGridTransparent = new QLabel(scrollAreaWidgetContents);
        lGridTransparent->setObjectName(QString::fromUtf8("lGridTransparent"));
        lGridTransparent->setMinimumSize(QSize(0, 0));
        lGridTransparent->setFont(font);

        gridLayout->addWidget(lGridTransparent, 0, 5, 1, 1);

        lGrid = new QLabel(scrollAreaWidgetContents);
        lGrid->setObjectName(QString::fromUtf8("lGrid"));
        lGrid->setMinimumSize(QSize(0, 0));
        lGrid->setFont(font1);

        gridLayout->addWidget(lGrid, 4, 1, 1, 1);

        sbCellWidth = new QSpinBox(scrollAreaWidgetContents);
        sbCellWidth->setObjectName(QString::fromUtf8("sbCellWidth"));
        sbCellWidth->setMinimumSize(QSize(0, 0));
        sbCellWidth->setFont(font);
        sbCellWidth->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbCellWidth->setMaximum(10000);
        sbCellWidth->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        sbCellWidth->setValue(100);

        gridLayout->addWidget(sbCellWidth, 4, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 5, 7, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(WidgetPointCloudSettings);

        QMetaObject::connectSlotsByName(WidgetPointCloudSettings);
    } // setupUi

    void retranslateUi(QWidget *WidgetPointCloudSettings)
    {
        WidgetPointCloudSettings->setWindowTitle(QCoreApplication::translate("WidgetPointCloudSettings", "Point cloud settings", nullptr));
        lObjectOffsetZ->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Offset Z", nullptr));
#if QT_CONFIG(tooltip)
        dbScaleZ->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Object scale z axis direction</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        sbAngleZ->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Camera releative object angle around  z axis</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lCameraView->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Camera view:", nullptr));
#if QT_CONFIG(tooltip)
        sbCameraOffesetX->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Camera releative object offset x direction</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lAngleZ->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Angle Z", nullptr));
        lScaleZ->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Scale Z", nullptr));
        tbLabelFont->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Label font", nullptr));
        lCameraAngleX->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Angle  X [grad]", nullptr));
#if QT_CONFIG(tooltip)
        sbAngleObjectZ->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Camera angle releative object</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        dbScaleX->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Object scale x axis direction</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lZoom->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Zoom", nullptr));
#if QT_CONFIG(tooltip)
        sbAngleY->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Camera releative object angle around  y axis</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbShowLegend->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Show legend", nullptr));
        lColors->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Colors:", nullptr));
#if QT_CONFIG(tooltip)
        cbShowLabels->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Show distance labels</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbShowLabels->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Show labels", nullptr));
#if QT_CONFIG(tooltip)
        sbAxisLineWidth->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Field of view line width</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        sbOffsetZ->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Grid plane offset z axis direction</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lAxisOffsetY->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Offset Y [mm]", nullptr));
        lObjectOffsetY->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Offset Y", nullptr));
        lNumberCells->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Number of cells", nullptr));
        lScaleY->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Scale Y", nullptr));
#if QT_CONFIG(tooltip)
        sbOffsetY->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Grid plane offset y axis direction</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lAxis->setText(QCoreApplication::translate("WidgetPointCloudSettings", "FOV:", nullptr));
        lAxisLineWidth->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Line width", nullptr));
#if QT_CONFIG(tooltip)
        sbObjectOffsetY->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Object offset releative scene y direction</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lGridOffsetZ->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Offset Z [mm]", nullptr));
        lAxisTransparent->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Transparent", nullptr));
        lCellWidth->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Cell width [mm]", nullptr));
        lLensAngle->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Lens angle", nullptr));
        lAxisOffsetZ->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Offset Z [mm]", nullptr));
        lScaleX->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Scale X", nullptr));
        lGridOffsetY->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Offset Y [mm]", nullptr));
#if QT_CONFIG(tooltip)
        sbLensAngle->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Camera lens FOV angle in degree</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lCameraAngleY->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Angle Y [grad]", nullptr));
#if QT_CONFIG(tooltip)
        sbObjectOffsetZ->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Object offset releative scene z direction</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lCameraOffesetY->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Offset Y", nullptr));
#if QT_CONFIG(tooltip)
        sbAngleX->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Camera releative object angle around  x axis</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        tbAxisColor->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Field of view color</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbAxisColor->setText(QCoreApplication::translate("WidgetPointCloudSettings", "FOV...", nullptr));
#if QT_CONFIG(tooltip)
        tbBackgroundColor->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Scene background color</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbBackgroundColor->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Background...", nullptr));
#if QT_CONFIG(tooltip)
        tbGridColor->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Grid color</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbGridColor->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Grid...", nullptr));
#if QT_CONFIG(tooltip)
        tbLabelColor->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Label color</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbLabelColor->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Labels...", nullptr));
        tbClose->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Close", nullptr));
        lAxisOffsetX->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Offset X [mm]", nullptr));
#if QT_CONFIG(tooltip)
        sbCameraOffesetY->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Camera releative object offset y direction</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        rbPolarGrid->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Polar grid", nullptr));
#if QT_CONFIG(tooltip)
        sbOffsetX->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Grid plane offset x axis direction</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lObjectOffsetX->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Offset X", nullptr));
#if QT_CONFIG(tooltip)
        sbObjectOffsetX->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Object offset releative scene x direction</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lCameraAngleZ->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Angle Z [grad]", nullptr));
        lGridOffsetX->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Offset X [mm]", nullptr));
#if QT_CONFIG(tooltip)
        dbScaleY->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Object scale y axis direction</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        dbZoom->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p>Camera zoom</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lCameraOffesetX->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Offset X", nullptr));
        lObject->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Object:", nullptr));
#if QT_CONFIG(tooltip)
        sbNumCells->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Number of cells</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        rbRectGrid->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Rect grid", nullptr));
        lGridTransparent->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Transparent", nullptr));
        lGrid->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Grid:", nullptr));
#if QT_CONFIG(tooltip)
        sbCellWidth->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Grid cell width and height mm</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class WidgetPointCloudSettings: public Ui_WidgetPointCloudSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_POINT_CLOUD_SETTINGS_H
