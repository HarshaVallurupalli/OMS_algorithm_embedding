/********************************************************************************
** Form generated from reading UI file 'window_controls.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_CONTROLS_H
#define UI_WINDOW_CONTROLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowControls
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *lZoom1;
    QLabel *lRotateY1_4;
    QLabel *lRotateY5_4;
    QLabel *lRotateY0_2;
    QLabel *lRotateY1_2;
    QLabel *lMove2;
    QLabel *lRotateY4;
    QLabel *lRotateY1_3;
    QLabel *lRotateY5_3;
    QLabel *lRotateY4_2;
    QLabel *lRotateX0_3;
    QLabel *lRotateY5_2;
    QLabel *lZoom0;
    QLabel *lRotateY5;
    QLabel *lRotateY3;
    QLabel *lZoom0_2;
    QLabel *lRotateY3_2;
    QLabel *lRotateY1;
    QLabel *lRotateY0_4;
    QLabel *lRotateY3_3;
    QLabel *lRotateY0_3;
    QLabel *lRotateY0;
    QLabel *lMove1;
    QLabel *lRotateX0_2;
    QLabel *lMove3;
    QLabel *lRotateY2;
    QLabel *lRotateZ2_2;
    QLabel *lMove0;

    void setupUi(QMainWindow *WindowControls)
    {
        if (WindowControls->objectName().isEmpty())
            WindowControls->setObjectName(QString::fromUtf8("WindowControls"));
        WindowControls->setWindowModality(Qt::NonModal);
        WindowControls->resize(371, 282);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WindowControls->sizePolicy().hasHeightForWidth());
        WindowControls->setSizePolicy(sizePolicy);
        WindowControls->setMinimumSize(QSize(0, 0));
        WindowControls->setMaximumSize(QSize(371, 282));
        centralwidget = new QWidget(WindowControls);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lZoom1 = new QLabel(centralwidget);
        lZoom1->setObjectName(QString::fromUtf8("lZoom1"));
        lZoom1->setMinimumSize(QSize(0, 0));
        lZoom1->setMaximumSize(QSize(150, 16777215));

        gridLayout->addWidget(lZoom1, 0, 6, 1, 1);

        lRotateY1_4 = new QLabel(centralwidget);
        lRotateY1_4->setObjectName(QString::fromUtf8("lRotateY1_4"));

        gridLayout->addWidget(lRotateY1_4, 1, 3, 1, 1);

        lRotateY5_4 = new QLabel(centralwidget);
        lRotateY5_4->setObjectName(QString::fromUtf8("lRotateY5_4"));

        gridLayout->addWidget(lRotateY5_4, 1, 6, 1, 1);

        lRotateY0_2 = new QLabel(centralwidget);
        lRotateY0_2->setObjectName(QString::fromUtf8("lRotateY0_2"));
        lRotateY0_2->setPixmap(QPixmap(QString::fromUtf8(":/icons/images/icons/shift.png")));

        gridLayout->addWidget(lRotateY0_2, 1, 1, 1, 1);

        lRotateY1_2 = new QLabel(centralwidget);
        lRotateY1_2->setObjectName(QString::fromUtf8("lRotateY1_2"));
        lRotateY1_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lRotateY1_2, 3, 1, 1, 1);

        lMove2 = new QLabel(centralwidget);
        lMove2->setObjectName(QString::fromUtf8("lMove2"));
        lMove2->setPixmap(QPixmap(QString::fromUtf8(":/icons/images/icons/mouse_left.png")));

        gridLayout->addWidget(lMove2, 5, 5, 1, 1);

        lRotateY4 = new QLabel(centralwidget);
        lRotateY4->setObjectName(QString::fromUtf8("lRotateY4"));
        lRotateY4->setPixmap(QPixmap(QString::fromUtf8(":/icons/images/icons/horizontal.png")));

        gridLayout->addWidget(lRotateY4, 2, 5, 1, 1);

        lRotateY1_3 = new QLabel(centralwidget);
        lRotateY1_3->setObjectName(QString::fromUtf8("lRotateY1_3"));
        lRotateY1_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lRotateY1_3, 4, 1, 1, 1);

        lRotateY5_3 = new QLabel(centralwidget);
        lRotateY5_3->setObjectName(QString::fromUtf8("lRotateY5_3"));

        gridLayout->addWidget(lRotateY5_3, 4, 6, 1, 1);

        lRotateY4_2 = new QLabel(centralwidget);
        lRotateY4_2->setObjectName(QString::fromUtf8("lRotateY4_2"));
        lRotateY4_2->setPixmap(QPixmap(QString::fromUtf8(":/icons/images/icons/horizontal.png")));

        gridLayout->addWidget(lRotateY4_2, 4, 5, 1, 1);

        lRotateX0_3 = new QLabel(centralwidget);
        lRotateX0_3->setObjectName(QString::fromUtf8("lRotateX0_3"));
        lRotateX0_3->setPixmap(QPixmap(QString::fromUtf8(":/icons/images/icons/mouse_left.png")));

        gridLayout->addWidget(lRotateX0_3, 3, 2, 1, 1);

        lRotateY5_2 = new QLabel(centralwidget);
        lRotateY5_2->setObjectName(QString::fromUtf8("lRotateY5_2"));

        gridLayout->addWidget(lRotateY5_2, 3, 6, 1, 1);

        lZoom0 = new QLabel(centralwidget);
        lZoom0->setObjectName(QString::fromUtf8("lZoom0"));
        lZoom0->setPixmap(QPixmap(QString::fromUtf8(":/icons/images/icons/mouse_middle.png")));

        gridLayout->addWidget(lZoom0, 0, 5, 1, 1);

        lRotateY5 = new QLabel(centralwidget);
        lRotateY5->setObjectName(QString::fromUtf8("lRotateY5"));

        gridLayout->addWidget(lRotateY5, 2, 6, 1, 1);

        lRotateY3 = new QLabel(centralwidget);
        lRotateY3->setObjectName(QString::fromUtf8("lRotateY3"));

        gridLayout->addWidget(lRotateY3, 2, 4, 1, 1);

        lZoom0_2 = new QLabel(centralwidget);
        lZoom0_2->setObjectName(QString::fromUtf8("lZoom0_2"));
        lZoom0_2->setPixmap(QPixmap(QString::fromUtf8(":/icons/images/icons/mouse_middle.png")));

        gridLayout->addWidget(lZoom0_2, 1, 5, 1, 1);

        lRotateY3_2 = new QLabel(centralwidget);
        lRotateY3_2->setObjectName(QString::fromUtf8("lRotateY3_2"));

        gridLayout->addWidget(lRotateY3_2, 4, 4, 1, 1);

        lRotateY1 = new QLabel(centralwidget);
        lRotateY1->setObjectName(QString::fromUtf8("lRotateY1"));
        lRotateY1->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lRotateY1, 2, 1, 1, 1);

        lRotateY0_4 = new QLabel(centralwidget);
        lRotateY0_4->setObjectName(QString::fromUtf8("lRotateY0_4"));
        lRotateY0_4->setPixmap(QPixmap(QString::fromUtf8(":/icons/images/icons/key_alt.png")));

        gridLayout->addWidget(lRotateY0_4, 4, 0, 1, 1);

        lRotateY3_3 = new QLabel(centralwidget);
        lRotateY3_3->setObjectName(QString::fromUtf8("lRotateY3_3"));

        gridLayout->addWidget(lRotateY3_3, 3, 4, 1, 1);

        lRotateY0_3 = new QLabel(centralwidget);
        lRotateY0_3->setObjectName(QString::fromUtf8("lRotateY0_3"));
        lRotateY0_3->setPixmap(QPixmap(QString::fromUtf8(":/icons/images/icons/key_alt.png")));

        gridLayout->addWidget(lRotateY0_3, 3, 0, 1, 1);

        lRotateY0 = new QLabel(centralwidget);
        lRotateY0->setObjectName(QString::fromUtf8("lRotateY0"));
        lRotateY0->setPixmap(QPixmap(QString::fromUtf8(":/icons/images/icons/shift.png")));

        gridLayout->addWidget(lRotateY0, 2, 0, 1, 1);

        lMove1 = new QLabel(centralwidget);
        lMove1->setObjectName(QString::fromUtf8("lMove1"));

        gridLayout->addWidget(lMove1, 5, 3, 1, 1);

        lRotateX0_2 = new QLabel(centralwidget);
        lRotateX0_2->setObjectName(QString::fromUtf8("lRotateX0_2"));
        lRotateX0_2->setPixmap(QPixmap(QString::fromUtf8(":/icons/images/icons/mouse_left.png")));

        gridLayout->addWidget(lRotateX0_2, 4, 2, 1, 1);

        lMove3 = new QLabel(centralwidget);
        lMove3->setObjectName(QString::fromUtf8("lMove3"));

        gridLayout->addWidget(lMove3, 5, 6, 1, 1);

        lRotateY2 = new QLabel(centralwidget);
        lRotateY2->setObjectName(QString::fromUtf8("lRotateY2"));
        lRotateY2->setPixmap(QPixmap(QString::fromUtf8(":/icons/images/icons/mouse_left.png")));

        gridLayout->addWidget(lRotateY2, 2, 2, 1, 1);

        lRotateZ2_2 = new QLabel(centralwidget);
        lRotateZ2_2->setObjectName(QString::fromUtf8("lRotateZ2_2"));
        lRotateZ2_2->setPixmap(QPixmap(QString::fromUtf8(":/icons/images/icons/vertical.png")));

        gridLayout->addWidget(lRotateZ2_2, 3, 5, 1, 1);

        lMove0 = new QLabel(centralwidget);
        lMove0->setObjectName(QString::fromUtf8("lMove0"));
        lMove0->setPixmap(QPixmap(QString::fromUtf8("../res/images/icons/key_ctrl.png")));

        gridLayout->addWidget(lMove0, 5, 1, 1, 1);

        WindowControls->setCentralWidget(centralwidget);

        retranslateUi(WindowControls);

        QMetaObject::connectSlotsByName(WindowControls);
    } // setupUi

    void retranslateUi(QMainWindow *WindowControls)
    {
        WindowControls->setWindowTitle(QCoreApplication::translate("WindowControls", "Controls", nullptr));
        lZoom1->setText(QCoreApplication::translate("WindowControls", "Zoom", nullptr));
        lRotateY1_4->setText(QCoreApplication::translate("WindowControls", "+", nullptr));
        lRotateY5_4->setText(QCoreApplication::translate("WindowControls", "Scale z", nullptr));
        lRotateY0_2->setText(QString());
        lRotateY1_2->setText(QCoreApplication::translate("WindowControls", "+", nullptr));
        lMove2->setText(QString());
        lRotateY4->setText(QString());
        lRotateY1_3->setText(QCoreApplication::translate("WindowControls", "+", nullptr));
        lRotateY5_3->setText(QCoreApplication::translate("WindowControls", "Scale x", nullptr));
        lRotateY4_2->setText(QString());
        lRotateX0_3->setText(QString());
        lRotateY5_2->setText(QCoreApplication::translate("WindowControls", "Scale y", nullptr));
        lZoom0->setText(QString());
        lRotateY5->setText(QCoreApplication::translate("WindowControls", "Rotate y", nullptr));
        lRotateY3->setText(QCoreApplication::translate("WindowControls", "+", nullptr));
        lZoom0_2->setText(QString());
        lRotateY3_2->setText(QCoreApplication::translate("WindowControls", "+", nullptr));
        lRotateY1->setText(QCoreApplication::translate("WindowControls", "+", nullptr));
        lRotateY0_4->setText(QString());
        lRotateY3_3->setText(QCoreApplication::translate("WindowControls", "+", nullptr));
        lRotateY0_3->setText(QString());
        lRotateY0->setText(QString());
        lMove1->setText(QCoreApplication::translate("WindowControls", "+", nullptr));
        lRotateX0_2->setText(QString());
        lMove3->setText(QCoreApplication::translate("WindowControls", "Move", nullptr));
        lRotateY2->setText(QString());
        lRotateZ2_2->setText(QString());
        lMove0->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WindowControls: public Ui_WindowControls {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_CONTROLS_H
