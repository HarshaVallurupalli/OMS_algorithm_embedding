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
#include <QtWidgets/QFrame>
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
    QGridLayout *gridLayout_5;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QSpinBox *sbCellWidth;
    QCheckBox *cbPerspectiveView;
    QSpinBox *sbAxisLineWidth;
    QSpinBox *sbAxisOffsetY;
    QSpinBox *sbAngleZ;
    QLabel *lAxis;
    QDoubleSpinBox *dbScaleY;
    QLabel *lGridOffsetZ;
    QLabel *lObjectOffsetX;
    QCheckBox *cbPoints;
    QLabel *lAngleZ;
    QFrame *line_3;
    QCheckBox *cbCartesian;
    QSpinBox *sbNumCells;
    QHBoxLayout *horizontalLayout;
    QToolButton *tbAxisColor;
    QToolButton *tbBackgroundColor;
    QToolButton *tbGridColor;
    QToolButton *tbLabelColor;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *tbClose;
    QSpacerItem *horizontalSpacer_6;
    QLabel *lAxisOffsetZ;
    QLabel *lObject;
    QSpinBox *sbLensAngle;
    QLabel *lAxisLineWidth;
    QLabel *lCameraView;
    QCheckBox *cbShowLegend;
    QLabel *lGridOffsetX;
    QSpinBox *sbOffsetY;
    QLabel *lObjectOffsetY;
    QSpinBox *sbAxisOffsetX;
    QDoubleSpinBox *dbScaleX;
    QSpinBox *sbObjectOffsetZ;
    QSpinBox *sbAngleObjectZ;
    QLabel *lLens;
    QCheckBox *cbAxis2D;
    QDoubleSpinBox *dbPointSize;
    QSpinBox *sbSurfaceInterconnect;
    QLabel *lAxisOffsetX;
    QLabel *lCameraAngleZ;
    QSpinBox *sbAngleY;
    QLabel *lObjectOffsetZ;
    QFrame *line_4;
    QToolButton *tbLabelFont;
    QDoubleSpinBox *dbScaleZ;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *cbSurfaceInterconnect;
    QLabel *lZoom;
    QFrame *line_2;
    QLabel *lColors;
    QLabel *lCameraOffesetY;
    QLabel *lScaleZ;
    QSpinBox *sbCameraOffesetX;
    QSpinBox *sbObjectOffsetY;
    QLabel *lScaleX;
    QLabel *lCameraAngleX;
    QSpinBox *sbObjectOffsetX;
    QCheckBox *cbGrayPointCloud;
    QLabel *lScaleY;
    QSpinBox *sbOffsetX;
    QLabel *lNumberCells;
    QFrame *line;
    QLabel *lCameraAngleY;
    QSpinBox *sbCameraOffesetY;
    QLabel *lGridTransparent;
    QLabel *lGridOffsetY;
    QCheckBox *cbGrid;
    QCheckBox *cbShowLabels;
    QFrame *line_5;
    QRadioButton *rbPolarGrid;
    QSpinBox *sbAngleX;
    QLabel *lGrid;
    QLabel *lAxisTransparent;
    QDoubleSpinBox *dbZoom;
    QCheckBox *cbAxis3D;
    QDoubleSpinBox *sbdTransparent;
    QDoubleSpinBox *dbAxisTransparent;
    QLabel *lAxisOffsetY;
    QSpacerItem *horizontalSpacer_3;
    QLabel *lCameraOffesetX;
    QSpinBox *sbAxisOffsetZ;
    QLabel *lCellWidth;
    QSpinBox *sbOffsetZ;
    QLabel *lLensAngle;
    QRadioButton *rbRectGrid;
    QLabel *lSensorOffsetX;
    QSpinBox *sbSensorOffsetX;
    QLabel *lSensorOffsetY;
    QSpinBox *sbSensorOffsetY;
    QRadioButton *rbWideField;
    QRadioButton *rbNarrowField;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *tbSaveDefaultView;
    QToolButton *tbResetDefaultView;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *WidgetPointCloudSettings)
    {
        if (WidgetPointCloudSettings->objectName().isEmpty())
            WidgetPointCloudSettings->setObjectName(QString::fromUtf8("WidgetPointCloudSettings"));
        WidgetPointCloudSettings->resize(651, 646);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WidgetPointCloudSettings->sizePolicy().hasHeightForWidth());
        WidgetPointCloudSettings->setSizePolicy(sizePolicy);
        gridLayout_5 = new QGridLayout(WidgetPointCloudSettings);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
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
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 633, 628));
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
        sbCellWidth = new QSpinBox(scrollAreaWidgetContents);
        sbCellWidth->setObjectName(QString::fromUtf8("sbCellWidth"));
        sbCellWidth->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setPointSize(8);
        sbCellWidth->setFont(font);
        sbCellWidth->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbCellWidth->setMaximum(10000);
        sbCellWidth->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        sbCellWidth->setValue(100);

        gridLayout->addWidget(sbCellWidth, 12, 4, 1, 1);

        cbPerspectiveView = new QCheckBox(scrollAreaWidgetContents);
        cbPerspectiveView->setObjectName(QString::fromUtf8("cbPerspectiveView"));

        gridLayout->addWidget(cbPerspectiveView, 0, 5, 1, 2);

        sbAxisLineWidth = new QSpinBox(scrollAreaWidgetContents);
        sbAxisLineWidth->setObjectName(QString::fromUtf8("sbAxisLineWidth"));
        sbAxisLineWidth->setMinimumSize(QSize(0, 0));
        sbAxisLineWidth->setFont(font);
        sbAxisLineWidth->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbAxisLineWidth->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout->addWidget(sbAxisLineWidth, 10, 4, 1, 1);

        sbAxisOffsetY = new QSpinBox(scrollAreaWidgetContents);
        sbAxisOffsetY->setObjectName(QString::fromUtf8("sbAxisOffsetY"));
        sbAxisOffsetY->setMinimumSize(QSize(0, 0));
        sbAxisOffsetY->setFont(font);
        sbAxisOffsetY->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbAxisOffsetY->setMinimum(-10000);
        sbAxisOffsetY->setMaximum(10000);
        sbAxisOffsetY->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout->addWidget(sbAxisOffsetY, 9, 4, 1, 1);

        sbAngleZ = new QSpinBox(scrollAreaWidgetContents);
        sbAngleZ->setObjectName(QString::fromUtf8("sbAngleZ"));
        sbAngleZ->setMinimumSize(QSize(0, 0));
        sbAngleZ->setFont(font);
        sbAngleZ->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbAngleZ->setMinimum(-360);
        sbAngleZ->setMaximum(360);
        sbAngleZ->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        sbAngleZ->setValue(181);

        gridLayout->addWidget(sbAngleZ, 20, 6, 1, 1);

        lAxis = new QLabel(scrollAreaWidgetContents);
        lAxis->setObjectName(QString::fromUtf8("lAxis"));
        lAxis->setMinimumSize(QSize(0, 0));
        QFont font1;
        font1.setPointSize(8);
        font1.setBold(true);
        font1.setWeight(75);
        lAxis->setFont(font1);

        gridLayout->addWidget(lAxis, 10, 1, 1, 1);

        dbScaleY = new QDoubleSpinBox(scrollAreaWidgetContents);
        dbScaleY->setObjectName(QString::fromUtf8("dbScaleY"));
        dbScaleY->setMinimumSize(QSize(0, 0));
        dbScaleY->setFont(font);
        dbScaleY->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dbScaleY->setMaximum(99.000000000000000);
        dbScaleY->setSingleStep(0.100000000000000);

        gridLayout->addWidget(dbScaleY, 17, 4, 1, 1);

        lGridOffsetZ = new QLabel(scrollAreaWidgetContents);
        lGridOffsetZ->setObjectName(QString::fromUtf8("lGridOffsetZ"));
        lGridOffsetZ->setMinimumSize(QSize(0, 0));
        lGridOffsetZ->setFont(font);

        gridLayout->addWidget(lGridOffsetZ, 13, 5, 1, 1);

        lObjectOffsetX = new QLabel(scrollAreaWidgetContents);
        lObjectOffsetX->setObjectName(QString::fromUtf8("lObjectOffsetX"));
        lObjectOffsetX->setMinimumSize(QSize(0, 0));
        lObjectOffsetX->setFont(font);

        gridLayout->addWidget(lObjectOffsetX, 16, 1, 1, 1);

        cbPoints = new QCheckBox(scrollAreaWidgetContents);
        cbPoints->setObjectName(QString::fromUtf8("cbPoints"));

        gridLayout->addWidget(cbPoints, 2, 1, 1, 1);

        lAngleZ = new QLabel(scrollAreaWidgetContents);
        lAngleZ->setObjectName(QString::fromUtf8("lAngleZ"));
        lAngleZ->setMinimumSize(QSize(0, 0));
        lAngleZ->setFont(font);

        gridLayout->addWidget(lAngleZ, 15, 2, 1, 2);

        line_3 = new QFrame(scrollAreaWidgetContents);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 24, 1, 1, 6);

        cbCartesian = new QCheckBox(scrollAreaWidgetContents);
        cbCartesian->setObjectName(QString::fromUtf8("cbCartesian"));

        gridLayout->addWidget(cbCartesian, 1, 5, 1, 2);

        sbNumCells = new QSpinBox(scrollAreaWidgetContents);
        sbNumCells->setObjectName(QString::fromUtf8("sbNumCells"));
        sbNumCells->setMinimumSize(QSize(0, 0));
        sbNumCells->setFont(font);
        sbNumCells->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbNumCells->setMaximum(1000);
        sbNumCells->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        sbNumCells->setValue(20);

        gridLayout->addWidget(sbNumCells, 12, 6, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, 0);
        tbAxisColor = new QToolButton(scrollAreaWidgetContents);
        tbAxisColor->setObjectName(QString::fromUtf8("tbAxisColor"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
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


        gridLayout->addLayout(horizontalLayout, 26, 1, 1, 6);

        horizontalSpacer_6 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 12, 0, 1, 1);

        lAxisOffsetZ = new QLabel(scrollAreaWidgetContents);
        lAxisOffsetZ->setObjectName(QString::fromUtf8("lAxisOffsetZ"));
        lAxisOffsetZ->setMinimumSize(QSize(0, 0));
        lAxisOffsetZ->setFont(font);

        gridLayout->addWidget(lAxisOffsetZ, 9, 5, 1, 1);

        lObject = new QLabel(scrollAreaWidgetContents);
        lObject->setObjectName(QString::fromUtf8("lObject"));
        lObject->setMinimumSize(QSize(0, 0));
        lObject->setFont(font1);

        gridLayout->addWidget(lObject, 15, 1, 1, 1);

        sbLensAngle = new QSpinBox(scrollAreaWidgetContents);
        sbLensAngle->setObjectName(QString::fromUtf8("sbLensAngle"));
        sbLensAngle->setMinimumSize(QSize(0, 0));
        sbLensAngle->setFont(font);
        sbLensAngle->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbLensAngle->setMaximum(180);
        sbLensAngle->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout->addWidget(sbLensAngle, 2, 3, 1, 1);

        lAxisLineWidth = new QLabel(scrollAreaWidgetContents);
        lAxisLineWidth->setObjectName(QString::fromUtf8("lAxisLineWidth"));
        lAxisLineWidth->setMinimumSize(QSize(0, 0));
        lAxisLineWidth->setFont(font);

        gridLayout->addWidget(lAxisLineWidth, 10, 3, 1, 1);

        lCameraView = new QLabel(scrollAreaWidgetContents);
        lCameraView->setObjectName(QString::fromUtf8("lCameraView"));
        lCameraView->setMinimumSize(QSize(0, 0));
        lCameraView->setFont(font1);

        gridLayout->addWidget(lCameraView, 19, 1, 1, 1);

        cbShowLegend = new QCheckBox(scrollAreaWidgetContents);
        cbShowLegend->setObjectName(QString::fromUtf8("cbShowLegend"));
        cbShowLegend->setMinimumSize(QSize(0, 0));
        cbShowLegend->setFont(font);
        cbShowLegend->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(cbShowLegend, 25, 2, 1, 1);

        lGridOffsetX = new QLabel(scrollAreaWidgetContents);
        lGridOffsetX->setObjectName(QString::fromUtf8("lGridOffsetX"));
        lGridOffsetX->setMinimumSize(QSize(0, 0));
        lGridOffsetX->setFont(font);

        gridLayout->addWidget(lGridOffsetX, 13, 1, 1, 1);

        sbOffsetY = new QSpinBox(scrollAreaWidgetContents);
        sbOffsetY->setObjectName(QString::fromUtf8("sbOffsetY"));
        sbOffsetY->setMinimumSize(QSize(0, 0));
        sbOffsetY->setFont(font);
        sbOffsetY->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbOffsetY->setMinimum(-10000);
        sbOffsetY->setMaximum(10000);
        sbOffsetY->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout->addWidget(sbOffsetY, 13, 4, 1, 1);

        lObjectOffsetY = new QLabel(scrollAreaWidgetContents);
        lObjectOffsetY->setObjectName(QString::fromUtf8("lObjectOffsetY"));
        lObjectOffsetY->setMinimumSize(QSize(0, 0));
        lObjectOffsetY->setFont(font);

        gridLayout->addWidget(lObjectOffsetY, 16, 3, 1, 1);

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

        gridLayout->addWidget(sbAxisOffsetX, 9, 2, 1, 1);

        dbScaleX = new QDoubleSpinBox(scrollAreaWidgetContents);
        dbScaleX->setObjectName(QString::fromUtf8("dbScaleX"));
        dbScaleX->setMinimumSize(QSize(0, 0));
        dbScaleX->setFont(font);
        dbScaleX->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dbScaleX->setMaximum(99.000000000000000);
        dbScaleX->setSingleStep(0.100000000000000);

        gridLayout->addWidget(dbScaleX, 17, 2, 1, 1);

        sbObjectOffsetZ = new QSpinBox(scrollAreaWidgetContents);
        sbObjectOffsetZ->setObjectName(QString::fromUtf8("sbObjectOffsetZ"));
        sbObjectOffsetZ->setMinimumSize(QSize(0, 0));
        sbObjectOffsetZ->setFont(font);
        sbObjectOffsetZ->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbObjectOffsetZ->setMinimum(-100000);
        sbObjectOffsetZ->setMaximum(100000);
        sbObjectOffsetZ->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout->addWidget(sbObjectOffsetZ, 16, 6, 1, 1);

        sbAngleObjectZ = new QSpinBox(scrollAreaWidgetContents);
        sbAngleObjectZ->setObjectName(QString::fromUtf8("sbAngleObjectZ"));
        sbAngleObjectZ->setMinimumSize(QSize(0, 0));
        sbAngleObjectZ->setFont(font);
        sbAngleObjectZ->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbAngleObjectZ->setMinimum(-180);
        sbAngleObjectZ->setMaximum(180);
        sbAngleObjectZ->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout->addWidget(sbAngleObjectZ, 15, 4, 1, 1);

        lLens = new QLabel(scrollAreaWidgetContents);
        lLens->setObjectName(QString::fromUtf8("lLens"));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        lLens->setFont(font2);

        gridLayout->addWidget(lLens, 5, 1, 1, 1);

        cbAxis2D = new QCheckBox(scrollAreaWidgetContents);
        cbAxis2D->setObjectName(QString::fromUtf8("cbAxis2D"));

        gridLayout->addWidget(cbAxis2D, 0, 1, 1, 1);

        dbPointSize = new QDoubleSpinBox(scrollAreaWidgetContents);
        dbPointSize->setObjectName(QString::fromUtf8("dbPointSize"));
        sizePolicy.setHeightForWidth(dbPointSize->sizePolicy().hasHeightForWidth());
        dbPointSize->setSizePolicy(sizePolicy);

        gridLayout->addWidget(dbPointSize, 2, 4, 1, 1);

        sbSurfaceInterconnect = new QSpinBox(scrollAreaWidgetContents);
        sbSurfaceInterconnect->setObjectName(QString::fromUtf8("sbSurfaceInterconnect"));
        sizePolicy.setHeightForWidth(sbSurfaceInterconnect->sizePolicy().hasHeightForWidth());
        sbSurfaceInterconnect->setSizePolicy(sizePolicy);
        sbSurfaceInterconnect->setMaximum(10000);

        gridLayout->addWidget(sbSurfaceInterconnect, 1, 4, 1, 1);

        lAxisOffsetX = new QLabel(scrollAreaWidgetContents);
        lAxisOffsetX->setObjectName(QString::fromUtf8("lAxisOffsetX"));
        lAxisOffsetX->setMinimumSize(QSize(0, 0));
        lAxisOffsetX->setFont(font);

        gridLayout->addWidget(lAxisOffsetX, 9, 1, 1, 1);

        lCameraAngleZ = new QLabel(scrollAreaWidgetContents);
        lCameraAngleZ->setObjectName(QString::fromUtf8("lCameraAngleZ"));
        lCameraAngleZ->setMinimumSize(QSize(0, 0));
        lCameraAngleZ->setFont(font);

        gridLayout->addWidget(lCameraAngleZ, 20, 5, 1, 1);

        sbAngleY = new QSpinBox(scrollAreaWidgetContents);
        sbAngleY->setObjectName(QString::fromUtf8("sbAngleY"));
        sbAngleY->setMinimumSize(QSize(0, 0));
        sbAngleY->setFont(font);
        sbAngleY->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbAngleY->setMinimum(-360);
        sbAngleY->setMaximum(360);
        sbAngleY->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        sbAngleY->setValue(17);

        gridLayout->addWidget(sbAngleY, 20, 4, 1, 1);

        lObjectOffsetZ = new QLabel(scrollAreaWidgetContents);
        lObjectOffsetZ->setObjectName(QString::fromUtf8("lObjectOffsetZ"));
        lObjectOffsetZ->setMinimumSize(QSize(0, 0));
        lObjectOffsetZ->setFont(font);

        gridLayout->addWidget(lObjectOffsetZ, 16, 5, 1, 1);

        line_4 = new QFrame(scrollAreaWidgetContents);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setMinimumSize(QSize(0, 0));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_4, 3, 1, 1, 6);

        tbLabelFont = new QToolButton(scrollAreaWidgetContents);
        tbLabelFont->setObjectName(QString::fromUtf8("tbLabelFont"));
        sizePolicy3.setHeightForWidth(tbLabelFont->sizePolicy().hasHeightForWidth());
        tbLabelFont->setSizePolicy(sizePolicy3);
        tbLabelFont->setMinimumSize(QSize(0, 0));
        tbLabelFont->setFont(font);

        gridLayout->addWidget(tbLabelFont, 25, 3, 1, 1);

        dbScaleZ = new QDoubleSpinBox(scrollAreaWidgetContents);
        dbScaleZ->setObjectName(QString::fromUtf8("dbScaleZ"));
        dbScaleZ->setMinimumSize(QSize(0, 0));
        dbScaleZ->setFont(font);
        dbScaleZ->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dbScaleZ->setMaximum(99.000000000000000);
        dbScaleZ->setSingleStep(0.100000000000000);

        gridLayout->addWidget(dbScaleZ, 17, 6, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        cbSurfaceInterconnect = new QCheckBox(scrollAreaWidgetContents);
        cbSurfaceInterconnect->setObjectName(QString::fromUtf8("cbSurfaceInterconnect"));

        horizontalLayout_3->addWidget(cbSurfaceInterconnect);


        gridLayout->addLayout(horizontalLayout_3, 1, 1, 1, 3);

        lZoom = new QLabel(scrollAreaWidgetContents);
        lZoom->setObjectName(QString::fromUtf8("lZoom"));
        lZoom->setMinimumSize(QSize(0, 0));
        lZoom->setFont(font);

        gridLayout->addWidget(lZoom, 22, 5, 1, 1);

        line_2 = new QFrame(scrollAreaWidgetContents);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setMinimumSize(QSize(0, 0));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 18, 1, 1, 6);

        lColors = new QLabel(scrollAreaWidgetContents);
        lColors->setObjectName(QString::fromUtf8("lColors"));
        lColors->setMinimumSize(QSize(0, 0));
        lColors->setFont(font1);

        gridLayout->addWidget(lColors, 25, 1, 1, 1);

        lCameraOffesetY = new QLabel(scrollAreaWidgetContents);
        lCameraOffesetY->setObjectName(QString::fromUtf8("lCameraOffesetY"));
        lCameraOffesetY->setMinimumSize(QSize(0, 0));
        lCameraOffesetY->setFont(font);

        gridLayout->addWidget(lCameraOffesetY, 22, 3, 1, 1);

        lScaleZ = new QLabel(scrollAreaWidgetContents);
        lScaleZ->setObjectName(QString::fromUtf8("lScaleZ"));
        lScaleZ->setMinimumSize(QSize(0, 0));
        lScaleZ->setFont(font);

        gridLayout->addWidget(lScaleZ, 17, 5, 1, 1);

        sbCameraOffesetX = new QSpinBox(scrollAreaWidgetContents);
        sbCameraOffesetX->setObjectName(QString::fromUtf8("sbCameraOffesetX"));
        sbCameraOffesetX->setMinimumSize(QSize(0, 0));
        sbCameraOffesetX->setFont(font);
        sbCameraOffesetX->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbCameraOffesetX->setMinimum(-1000000);
        sbCameraOffesetX->setMaximum(1000000);
        sbCameraOffesetX->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout->addWidget(sbCameraOffesetX, 22, 2, 1, 1);

        sbObjectOffsetY = new QSpinBox(scrollAreaWidgetContents);
        sbObjectOffsetY->setObjectName(QString::fromUtf8("sbObjectOffsetY"));
        sbObjectOffsetY->setMinimumSize(QSize(0, 0));
        sbObjectOffsetY->setFont(font);
        sbObjectOffsetY->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbObjectOffsetY->setMinimum(-100000);
        sbObjectOffsetY->setMaximum(100000);
        sbObjectOffsetY->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout->addWidget(sbObjectOffsetY, 16, 4, 1, 1);

        lScaleX = new QLabel(scrollAreaWidgetContents);
        lScaleX->setObjectName(QString::fromUtf8("lScaleX"));
        lScaleX->setMinimumSize(QSize(0, 0));
        lScaleX->setFont(font);

        gridLayout->addWidget(lScaleX, 17, 1, 1, 1);

        lCameraAngleX = new QLabel(scrollAreaWidgetContents);
        lCameraAngleX->setObjectName(QString::fromUtf8("lCameraAngleX"));
        lCameraAngleX->setMinimumSize(QSize(0, 0));
        lCameraAngleX->setFont(font);

        gridLayout->addWidget(lCameraAngleX, 20, 1, 1, 1);

        sbObjectOffsetX = new QSpinBox(scrollAreaWidgetContents);
        sbObjectOffsetX->setObjectName(QString::fromUtf8("sbObjectOffsetX"));
        sbObjectOffsetX->setMinimumSize(QSize(0, 0));
        sbObjectOffsetX->setFont(font);
        sbObjectOffsetX->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbObjectOffsetX->setMinimum(-100000);
        sbObjectOffsetX->setMaximum(100000);
        sbObjectOffsetX->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout->addWidget(sbObjectOffsetX, 16, 2, 1, 1);

        cbGrayPointCloud = new QCheckBox(scrollAreaWidgetContents);
        cbGrayPointCloud->setObjectName(QString::fromUtf8("cbGrayPointCloud"));

        gridLayout->addWidget(cbGrayPointCloud, 0, 4, 1, 1);

        lScaleY = new QLabel(scrollAreaWidgetContents);
        lScaleY->setObjectName(QString::fromUtf8("lScaleY"));
        lScaleY->setMinimumSize(QSize(0, 0));
        lScaleY->setFont(font);

        gridLayout->addWidget(lScaleY, 17, 3, 1, 1);

        sbOffsetX = new QSpinBox(scrollAreaWidgetContents);
        sbOffsetX->setObjectName(QString::fromUtf8("sbOffsetX"));
        sbOffsetX->setMinimumSize(QSize(0, 0));
        sbOffsetX->setFont(font);
        sbOffsetX->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbOffsetX->setMinimum(-100000);
        sbOffsetX->setMaximum(100000);
        sbOffsetX->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout->addWidget(sbOffsetX, 13, 2, 1, 1);

        lNumberCells = new QLabel(scrollAreaWidgetContents);
        lNumberCells->setObjectName(QString::fromUtf8("lNumberCells"));
        lNumberCells->setMinimumSize(QSize(0, 0));
        lNumberCells->setFont(font);

        gridLayout->addWidget(lNumberCells, 12, 5, 1, 1);

        line = new QFrame(scrollAreaWidgetContents);
        line->setObjectName(QString::fromUtf8("line"));
        line->setMinimumSize(QSize(0, 0));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 7, 1, 1, 6);

        lCameraAngleY = new QLabel(scrollAreaWidgetContents);
        lCameraAngleY->setObjectName(QString::fromUtf8("lCameraAngleY"));
        lCameraAngleY->setMinimumSize(QSize(0, 0));
        lCameraAngleY->setFont(font);

        gridLayout->addWidget(lCameraAngleY, 20, 3, 1, 1);

        sbCameraOffesetY = new QSpinBox(scrollAreaWidgetContents);
        sbCameraOffesetY->setObjectName(QString::fromUtf8("sbCameraOffesetY"));
        sbCameraOffesetY->setMinimumSize(QSize(0, 0));
        sbCameraOffesetY->setFont(font);
        sbCameraOffesetY->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbCameraOffesetY->setMinimum(-1000000);
        sbCameraOffesetY->setMaximum(1000000);
        sbCameraOffesetY->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout->addWidget(sbCameraOffesetY, 22, 4, 1, 1);

        lGridTransparent = new QLabel(scrollAreaWidgetContents);
        lGridTransparent->setObjectName(QString::fromUtf8("lGridTransparent"));
        lGridTransparent->setMinimumSize(QSize(0, 0));
        lGridTransparent->setFont(font);

        gridLayout->addWidget(lGridTransparent, 8, 5, 1, 1);

        lGridOffsetY = new QLabel(scrollAreaWidgetContents);
        lGridOffsetY->setObjectName(QString::fromUtf8("lGridOffsetY"));
        lGridOffsetY->setMinimumSize(QSize(0, 0));
        lGridOffsetY->setFont(font);

        gridLayout->addWidget(lGridOffsetY, 13, 3, 1, 1);

        cbGrid = new QCheckBox(scrollAreaWidgetContents);
        cbGrid->setObjectName(QString::fromUtf8("cbGrid"));

        gridLayout->addWidget(cbGrid, 0, 3, 1, 1);

        cbShowLabels = new QCheckBox(scrollAreaWidgetContents);
        cbShowLabels->setObjectName(QString::fromUtf8("cbShowLabels"));
        cbShowLabels->setMinimumSize(QSize(0, 0));
        cbShowLabels->setFont(font);
        cbShowLabels->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(cbShowLabels, 2, 5, 1, 2);

        line_5 = new QFrame(scrollAreaWidgetContents);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setMinimumSize(QSize(0, 0));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_5, 14, 1, 1, 6);

        rbPolarGrid = new QRadioButton(scrollAreaWidgetContents);
        rbPolarGrid->setObjectName(QString::fromUtf8("rbPolarGrid"));
        rbPolarGrid->setMinimumSize(QSize(0, 0));
        rbPolarGrid->setFont(font);
        rbPolarGrid->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(rbPolarGrid, 8, 3, 1, 1);

        sbAngleX = new QSpinBox(scrollAreaWidgetContents);
        sbAngleX->setObjectName(QString::fromUtf8("sbAngleX"));
        sbAngleX->setMinimumSize(QSize(0, 0));
        sbAngleX->setFont(font);
        sbAngleX->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbAngleX->setMinimum(-360);
        sbAngleX->setMaximum(360);
        sbAngleX->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        sbAngleX->setValue(-67);

        gridLayout->addWidget(sbAngleX, 20, 2, 1, 1);

        lGrid = new QLabel(scrollAreaWidgetContents);
        lGrid->setObjectName(QString::fromUtf8("lGrid"));
        lGrid->setMinimumSize(QSize(0, 0));
        lGrid->setFont(font1);

        gridLayout->addWidget(lGrid, 12, 1, 1, 1);

        lAxisTransparent = new QLabel(scrollAreaWidgetContents);
        lAxisTransparent->setObjectName(QString::fromUtf8("lAxisTransparent"));
        lAxisTransparent->setMinimumSize(QSize(0, 0));
        lAxisTransparent->setFont(font);

        gridLayout->addWidget(lAxisTransparent, 25, 5, 1, 1);

        dbZoom = new QDoubleSpinBox(scrollAreaWidgetContents);
        dbZoom->setObjectName(QString::fromUtf8("dbZoom"));
        dbZoom->setMinimumSize(QSize(0, 0));
        dbZoom->setFont(font);
        dbZoom->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dbZoom->setMaximum(1000.000000000000000);
        dbZoom->setSingleStep(0.100000000000000);
        dbZoom->setStepType(QAbstractSpinBox::DefaultStepType);
        dbZoom->setValue(1.000000000000000);

        gridLayout->addWidget(dbZoom, 22, 6, 1, 1);

        cbAxis3D = new QCheckBox(scrollAreaWidgetContents);
        cbAxis3D->setObjectName(QString::fromUtf8("cbAxis3D"));

        gridLayout->addWidget(cbAxis3D, 0, 2, 1, 1);

        sbdTransparent = new QDoubleSpinBox(scrollAreaWidgetContents);
        sbdTransparent->setObjectName(QString::fromUtf8("sbdTransparent"));
        sbdTransparent->setMinimumSize(QSize(0, 0));
        sbdTransparent->setFont(font);
        sbdTransparent->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbdTransparent->setMaximum(1.000000000000000);
        sbdTransparent->setSingleStep(0.100000000000000);
        sbdTransparent->setValue(0.500000000000000);

        gridLayout->addWidget(sbdTransparent, 8, 6, 1, 1);

        dbAxisTransparent = new QDoubleSpinBox(scrollAreaWidgetContents);
        dbAxisTransparent->setObjectName(QString::fromUtf8("dbAxisTransparent"));
        dbAxisTransparent->setMinimumSize(QSize(0, 0));
        dbAxisTransparent->setFont(font);
        dbAxisTransparent->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dbAxisTransparent->setMaximum(1.000000000000000);
        dbAxisTransparent->setSingleStep(0.100000000000000);
        dbAxisTransparent->setValue(0.500000000000000);

        gridLayout->addWidget(dbAxisTransparent, 25, 6, 1, 1);

        lAxisOffsetY = new QLabel(scrollAreaWidgetContents);
        lAxisOffsetY->setObjectName(QString::fromUtf8("lAxisOffsetY"));
        lAxisOffsetY->setMinimumSize(QSize(0, 0));
        lAxisOffsetY->setFont(font);

        gridLayout->addWidget(lAxisOffsetY, 9, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 13, 7, 1, 1);

        lCameraOffesetX = new QLabel(scrollAreaWidgetContents);
        lCameraOffesetX->setObjectName(QString::fromUtf8("lCameraOffesetX"));
        lCameraOffesetX->setMinimumSize(QSize(0, 0));
        lCameraOffesetX->setFont(font);

        gridLayout->addWidget(lCameraOffesetX, 22, 1, 1, 1);

        sbAxisOffsetZ = new QSpinBox(scrollAreaWidgetContents);
        sbAxisOffsetZ->setObjectName(QString::fromUtf8("sbAxisOffsetZ"));
        sbAxisOffsetZ->setMinimumSize(QSize(0, 0));
        sbAxisOffsetZ->setFont(font);
        sbAxisOffsetZ->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbAxisOffsetZ->setMinimum(-100000);
        sbAxisOffsetZ->setMaximum(100000);
        sbAxisOffsetZ->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout->addWidget(sbAxisOffsetZ, 9, 6, 1, 1);

        lCellWidth = new QLabel(scrollAreaWidgetContents);
        lCellWidth->setObjectName(QString::fromUtf8("lCellWidth"));
        lCellWidth->setMinimumSize(QSize(0, 0));
        lCellWidth->setFont(font);

        gridLayout->addWidget(lCellWidth, 12, 3, 1, 1);

        sbOffsetZ = new QSpinBox(scrollAreaWidgetContents);
        sbOffsetZ->setObjectName(QString::fromUtf8("sbOffsetZ"));
        sbOffsetZ->setMinimumSize(QSize(0, 0));
        sbOffsetZ->setFont(font);
        sbOffsetZ->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        sbOffsetZ->setMinimum(-100000);
        sbOffsetZ->setMaximum(100000);
        sbOffsetZ->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        gridLayout->addWidget(sbOffsetZ, 13, 6, 1, 1);

        lLensAngle = new QLabel(scrollAreaWidgetContents);
        lLensAngle->setObjectName(QString::fromUtf8("lLensAngle"));
        lLensAngle->setMinimumSize(QSize(0, 0));
        lLensAngle->setFont(font);

        gridLayout->addWidget(lLensAngle, 2, 2, 1, 1);

        rbRectGrid = new QRadioButton(scrollAreaWidgetContents);
        rbRectGrid->setObjectName(QString::fromUtf8("rbRectGrid"));
        rbRectGrid->setMinimumSize(QSize(0, 0));
        rbRectGrid->setFont(font);
        rbRectGrid->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(rbRectGrid, 8, 2, 1, 1);

        lSensorOffsetX = new QLabel(scrollAreaWidgetContents);
        lSensorOffsetX->setObjectName(QString::fromUtf8("lSensorOffsetX"));

        gridLayout->addWidget(lSensorOffsetX, 6, 3, 1, 1);

        sbSensorOffsetX = new QSpinBox(scrollAreaWidgetContents);
        sbSensorOffsetX->setObjectName(QString::fromUtf8("sbSensorOffsetX"));
        sbSensorOffsetX->setMinimum(-100);
        sbSensorOffsetX->setMaximum(100);

        gridLayout->addWidget(sbSensorOffsetX, 6, 4, 1, 1);

        lSensorOffsetY = new QLabel(scrollAreaWidgetContents);
        lSensorOffsetY->setObjectName(QString::fromUtf8("lSensorOffsetY"));

        gridLayout->addWidget(lSensorOffsetY, 6, 5, 1, 1);

        sbSensorOffsetY = new QSpinBox(scrollAreaWidgetContents);
        sbSensorOffsetY->setObjectName(QString::fromUtf8("sbSensorOffsetY"));
        sbSensorOffsetY->setMinimum(-100);
        sbSensorOffsetY->setMaximum(100);

        gridLayout->addWidget(sbSensorOffsetY, 6, 6, 1, 1);

        rbWideField = new QRadioButton(scrollAreaWidgetContents);
        rbWideField->setObjectName(QString::fromUtf8("rbWideField"));

        gridLayout->addWidget(rbWideField, 6, 2, 1, 1);

        rbNarrowField = new QRadioButton(scrollAreaWidgetContents);
        rbNarrowField->setObjectName(QString::fromUtf8("rbNarrowField"));

        gridLayout->addWidget(rbNarrowField, 6, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tbSaveDefaultView = new QToolButton(scrollAreaWidgetContents);
        tbSaveDefaultView->setObjectName(QString::fromUtf8("tbSaveDefaultView"));

        horizontalLayout_2->addWidget(tbSaveDefaultView);

        tbResetDefaultView = new QToolButton(scrollAreaWidgetContents);
        tbResetDefaultView->setObjectName(QString::fromUtf8("tbResetDefaultView"));

        horizontalLayout_2->addWidget(tbResetDefaultView);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_2, 23, 1, 1, 4);


        gridLayout_3->addLayout(gridLayout, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 3, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_5->addWidget(scrollArea, 1, 0, 1, 1);


        retranslateUi(WidgetPointCloudSettings);

        QMetaObject::connectSlotsByName(WidgetPointCloudSettings);
    } // setupUi

    void retranslateUi(QWidget *WidgetPointCloudSettings)
    {
        WidgetPointCloudSettings->setWindowTitle(QCoreApplication::translate("WidgetPointCloudSettings", "Point cloud settings", nullptr));
#if QT_CONFIG(tooltip)
        sbCellWidth->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Grid cell width and height mm</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbPerspectiveView->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Perspective", nullptr));
#if QT_CONFIG(tooltip)
        sbAxisLineWidth->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Field of view line width</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        sbAngleZ->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Camera releative object angle around  z axis</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lAxis->setText(QCoreApplication::translate("WidgetPointCloudSettings", "FOV:", nullptr));
#if QT_CONFIG(tooltip)
        dbScaleY->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Object scale y axis direction</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lGridOffsetZ->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Offset Z [mm]", nullptr));
        lObjectOffsetX->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Offset X", nullptr));
        cbPoints->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Points", nullptr));
        lAngleZ->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Camera - Object angle Z [grad]", nullptr));
        cbCartesian->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Cartesian", nullptr));
#if QT_CONFIG(tooltip)
        sbNumCells->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Number of cells</span></p></body></html>", nullptr));
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
        lAxisOffsetZ->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Offset Z [mm]", nullptr));
        lObject->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Object:", nullptr));
#if QT_CONFIG(tooltip)
        sbLensAngle->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Camera lens FOV angle in degree</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lAxisLineWidth->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Line width", nullptr));
        lCameraView->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Camera view:", nullptr));
        cbShowLegend->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Show legend", nullptr));
        lGridOffsetX->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Offset X [mm]", nullptr));
#if QT_CONFIG(tooltip)
        sbOffsetY->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Grid plane offset y axis direction</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lObjectOffsetY->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Offset Y", nullptr));
#if QT_CONFIG(tooltip)
        dbScaleX->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Object scale x axis direction</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        sbObjectOffsetZ->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Object offset releative scene z direction</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        sbAngleObjectZ->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Camera angle releative object</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lLens->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Lens:", nullptr));
        cbAxis2D->setText(QCoreApplication::translate("WidgetPointCloudSettings", "FOV 2D  ", nullptr));
        lAxisOffsetX->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Offset X [mm]", nullptr));
        lCameraAngleZ->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Angle Z [grad]", nullptr));
#if QT_CONFIG(tooltip)
        sbAngleY->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Camera releative object angle around  y axis</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lObjectOffsetZ->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Offset Z", nullptr));
        tbLabelFont->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Label font", nullptr));
#if QT_CONFIG(tooltip)
        dbScaleZ->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Object scale z axis direction</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbSurfaceInterconnect->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Surface interconnect [mm]", nullptr));
        lZoom->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Zoom", nullptr));
        lColors->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Colors:", nullptr));
        lCameraOffesetY->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Offset Y", nullptr));
        lScaleZ->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Scale Z", nullptr));
#if QT_CONFIG(tooltip)
        sbCameraOffesetX->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Camera releative object offset x direction</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        sbObjectOffsetY->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Object offset releative scene y direction</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lScaleX->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Scale X", nullptr));
        lCameraAngleX->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Angle  X [grad]", nullptr));
#if QT_CONFIG(tooltip)
        sbObjectOffsetX->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Object offset releative scene x direction</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbGrayPointCloud->setText(QCoreApplication::translate("WidgetPointCloudSettings", "TOF amp", nullptr));
        lScaleY->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Scale Y", nullptr));
#if QT_CONFIG(tooltip)
        sbOffsetX->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Grid plane offset x axis direction</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lNumberCells->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Number of cells", nullptr));
        lCameraAngleY->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Angle Y [grad]", nullptr));
#if QT_CONFIG(tooltip)
        sbCameraOffesetY->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Camera releative object offset y direction</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lGridTransparent->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Transparent", nullptr));
        lGridOffsetY->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Offset Y [mm]", nullptr));
        cbGrid->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Grid", nullptr));
#if QT_CONFIG(tooltip)
        cbShowLabels->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Show distance labels</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbShowLabels->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Show labels", nullptr));
        rbPolarGrid->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Polar grid", nullptr));
#if QT_CONFIG(tooltip)
        sbAngleX->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Camera releative object angle around  x axis</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lGrid->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Grid:", nullptr));
        lAxisTransparent->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Transparent", nullptr));
#if QT_CONFIG(tooltip)
        dbZoom->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p>Camera zoom</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        cbAxis3D->setText(QCoreApplication::translate("WidgetPointCloudSettings", "FOV 3D ", nullptr));
        lAxisOffsetY->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Offset Y [mm]", nullptr));
        lCameraOffesetX->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Offset X", nullptr));
        lCellWidth->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Cell width [mm]", nullptr));
#if QT_CONFIG(tooltip)
        sbOffsetZ->setToolTip(QCoreApplication::translate("WidgetPointCloudSettings", "<html><head/><body><p><span style=\" font-size:10pt;\">Grid plane offset z axis direction</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lLensAngle->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Lens angle", nullptr));
        rbRectGrid->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Rect grid", nullptr));
        lSensorOffsetX->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Lens offset X", nullptr));
        lSensorOffsetY->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Lens offset Y", nullptr));
        rbWideField->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Wide field", nullptr));
        rbNarrowField->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Narrow field", nullptr));
        tbSaveDefaultView->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Save Default View", nullptr));
        tbResetDefaultView->setText(QCoreApplication::translate("WidgetPointCloudSettings", "Standard Default View", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetPointCloudSettings: public Ui_WidgetPointCloudSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_POINT_CLOUD_SETTINGS_H
