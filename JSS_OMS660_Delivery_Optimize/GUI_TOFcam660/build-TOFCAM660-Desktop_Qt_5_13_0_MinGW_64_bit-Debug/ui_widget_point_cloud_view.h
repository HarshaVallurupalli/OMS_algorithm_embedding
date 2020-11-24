/********************************************************************************
** Form generated from reading UI file 'widget_point_cloud_view.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_POINT_CLOUD_VIEW_H
#define UI_WIDGET_POINT_CLOUD_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetPointCloudView
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QCheckBox *cbGrayPointCloud;
    QCheckBox *cbAxis3D;
    QCheckBox *cbGrid;
    QCheckBox *cbCartesian;
    QSpinBox *sbSurfaceInterconnect;
    QCheckBox *cbPoints;
    QCheckBox *cbPerspectiveView;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QToolButton *tbClose;
    QDoubleSpinBox *dbPointSize;
    QCheckBox *cbUndistortion;
    QHBoxLayout *horizontalLayout;
    QCheckBox *cbSurfaceInterconnect;
    QCheckBox *cbAxis2D;
    QCheckBox *cbAutoRotating;

    void setupUi(QWidget *WidgetPointCloudView)
    {
        if (WidgetPointCloudView->objectName().isEmpty())
            WidgetPointCloudView->setObjectName(QString::fromUtf8("WidgetPointCloudView"));
        WidgetPointCloudView->resize(541, 112);
        gridLayout_2 = new QGridLayout(WidgetPointCloudView);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(15);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, -1, -1, 6);
        cbGrayPointCloud = new QCheckBox(WidgetPointCloudView);
        cbGrayPointCloud->setObjectName(QString::fromUtf8("cbGrayPointCloud"));

        gridLayout->addWidget(cbGrayPointCloud, 0, 0, 1, 1);

        cbAxis3D = new QCheckBox(WidgetPointCloudView);
        cbAxis3D->setObjectName(QString::fromUtf8("cbAxis3D"));

        gridLayout->addWidget(cbAxis3D, 0, 2, 1, 1);

        cbGrid = new QCheckBox(WidgetPointCloudView);
        cbGrid->setObjectName(QString::fromUtf8("cbGrid"));

        gridLayout->addWidget(cbGrid, 0, 3, 1, 1);

        cbCartesian = new QCheckBox(WidgetPointCloudView);
        cbCartesian->setObjectName(QString::fromUtf8("cbCartesian"));

        gridLayout->addWidget(cbCartesian, 1, 5, 1, 1);

        sbSurfaceInterconnect = new QSpinBox(WidgetPointCloudView);
        sbSurfaceInterconnect->setObjectName(QString::fromUtf8("sbSurfaceInterconnect"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sbSurfaceInterconnect->sizePolicy().hasHeightForWidth());
        sbSurfaceInterconnect->setSizePolicy(sizePolicy);
        sbSurfaceInterconnect->setMaximum(10000);

        gridLayout->addWidget(sbSurfaceInterconnect, 1, 2, 1, 1);

        cbPoints = new QCheckBox(WidgetPointCloudView);
        cbPoints->setObjectName(QString::fromUtf8("cbPoints"));

        gridLayout->addWidget(cbPoints, 2, 0, 1, 1);

        cbPerspectiveView = new QCheckBox(WidgetPointCloudView);
        cbPerspectiveView->setObjectName(QString::fromUtf8("cbPerspectiveView"));

        gridLayout->addWidget(cbPerspectiveView, 0, 5, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        tbClose = new QToolButton(WidgetPointCloudView);
        tbClose->setObjectName(QString::fromUtf8("tbClose"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tbClose->sizePolicy().hasHeightForWidth());
        tbClose->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(tbClose);


        gridLayout->addLayout(verticalLayout, 1, 6, 2, 1);

        dbPointSize = new QDoubleSpinBox(WidgetPointCloudView);
        dbPointSize->setObjectName(QString::fromUtf8("dbPointSize"));
        sizePolicy.setHeightForWidth(dbPointSize->sizePolicy().hasHeightForWidth());
        dbPointSize->setSizePolicy(sizePolicy);

        gridLayout->addWidget(dbPointSize, 2, 2, 1, 1);

        cbUndistortion = new QCheckBox(WidgetPointCloudView);
        cbUndistortion->setObjectName(QString::fromUtf8("cbUndistortion"));

        gridLayout->addWidget(cbUndistortion, 2, 5, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cbSurfaceInterconnect = new QCheckBox(WidgetPointCloudView);
        cbSurfaceInterconnect->setObjectName(QString::fromUtf8("cbSurfaceInterconnect"));

        horizontalLayout->addWidget(cbSurfaceInterconnect);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 2);

        cbAxis2D = new QCheckBox(WidgetPointCloudView);
        cbAxis2D->setObjectName(QString::fromUtf8("cbAxis2D"));

        gridLayout->addWidget(cbAxis2D, 0, 1, 1, 1);

        cbAutoRotating = new QCheckBox(WidgetPointCloudView);
        cbAutoRotating->setObjectName(QString::fromUtf8("cbAutoRotating"));

        gridLayout->addWidget(cbAutoRotating, 0, 6, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(WidgetPointCloudView);

        QMetaObject::connectSlotsByName(WidgetPointCloudView);
    } // setupUi

    void retranslateUi(QWidget *WidgetPointCloudView)
    {
        WidgetPointCloudView->setWindowTitle(QCoreApplication::translate("WidgetPointCloudView", "Form", nullptr));
        cbGrayPointCloud->setText(QCoreApplication::translate("WidgetPointCloudView", "TOF amp OV  ", nullptr));
        cbAxis3D->setText(QCoreApplication::translate("WidgetPointCloudView", "FOV 3D ", nullptr));
        cbGrid->setText(QCoreApplication::translate("WidgetPointCloudView", "Grid", nullptr));
        cbCartesian->setText(QCoreApplication::translate("WidgetPointCloudView", "Cartesian", nullptr));
        cbPoints->setText(QCoreApplication::translate("WidgetPointCloudView", "Points", nullptr));
        cbPerspectiveView->setText(QCoreApplication::translate("WidgetPointCloudView", "Perspective  ", nullptr));
        tbClose->setText(QCoreApplication::translate("WidgetPointCloudView", "Close", nullptr));
        cbUndistortion->setText(QCoreApplication::translate("WidgetPointCloudView", "Undistortion", nullptr));
        cbSurfaceInterconnect->setText(QCoreApplication::translate("WidgetPointCloudView", "Surface interconnect [mm]", nullptr));
        cbAxis2D->setText(QCoreApplication::translate("WidgetPointCloudView", "FOV 2D  ", nullptr));
        cbAutoRotating->setText(QCoreApplication::translate("WidgetPointCloudView", "Auto rotation  ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetPointCloudView: public Ui_WidgetPointCloudView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_POINT_CLOUD_VIEW_H
