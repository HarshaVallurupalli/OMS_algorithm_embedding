/********************************************************************************
** Form generated from reading UI file 'widget_play.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_PLAY_H
#define UI_WIDGET_PLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetPlay
{
public:
    QGridLayout *gridLayout;
    QLabel *labelTitle;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QListWidget *listWidgetNames;
    QLabel *lFolderPath;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *tbPlay;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *tbStop;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *tbRecord;
    QSpacerItem *horizontalSpacer_4;
    QLabel *lFrameRate;
    QSpacerItem *hp_widgetPlay1;
    QDoubleSpinBox *sbFps;
    QSpacerItem *horizontalSpacer_8;
    QVBoxLayout *verticalLayout;
    QToolButton *tbDeleteFiles;
    QSpacerItem *verticalSpacer_2;
    QToolButton *tbDeleteSelectedFile;
    QSpacerItem *verticalSpacer;
    QLabel *lFileName;
    QSlider *sliderPlay;
    QLineEdit *leFolderPath;
    QComboBox *comBoxImageType;
    QLineEdit *leFileName;
    QToolButton *tbSelectPath;

    void setupUi(QWidget *WidgetPlay)
    {
        if (WidgetPlay->objectName().isEmpty())
            WidgetPlay->setObjectName(QString::fromUtf8("WidgetPlay"));
        WidgetPlay->resize(555, 324);
        gridLayout = new QGridLayout(WidgetPlay);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelTitle = new QLabel(WidgetPlay);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        labelTitle->setStyleSheet(QString::fromUtf8("padding:10px;\n"
"/*background-color:rgb(66, 138, 200);*/\n"
"/*background-color:rgb(76, 55, 108);*/\n"
"background-color:rgb(51, 51, 51);\n"
"color:rgb(255,255,255);\n"
""));

        gridLayout->addWidget(labelTitle, 0, 0, 1, 1);

        widget = new QWidget(WidgetPlay);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(20);
        gridLayout_2->setContentsMargins(9, 25, -1, -1);
        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 3, 1, 1);

        listWidgetNames = new QListWidget(widget);
        new QListWidgetItem(listWidgetNames);
        new QListWidgetItem(listWidgetNames);
        new QListWidgetItem(listWidgetNames);
        listWidgetNames->setObjectName(QString::fromUtf8("listWidgetNames"));
        listWidgetNames->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        listWidgetNames->setSelectionRectVisible(false);

        gridLayout_2->addWidget(listWidgetNames, 2, 0, 1, 6);

        lFolderPath = new QLabel(widget);
        lFolderPath->setObjectName(QString::fromUtf8("lFolderPath"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lFolderPath->sizePolicy().hasHeightForWidth());
        lFolderPath->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(lFolderPath, 1, 4, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        tbPlay = new QToolButton(widget);
        tbPlay->setObjectName(QString::fromUtf8("tbPlay"));
        tbPlay->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        tbPlay->setArrowType(Qt::RightArrow);

        horizontalLayout_2->addWidget(tbPlay);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        tbStop = new QToolButton(widget);
        tbStop->setObjectName(QString::fromUtf8("tbStop"));

        horizontalLayout_2->addWidget(tbStop);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        tbRecord = new QToolButton(widget);
        tbRecord->setObjectName(QString::fromUtf8("tbRecord"));

        horizontalLayout_2->addWidget(tbRecord);

        horizontalSpacer_4 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        lFrameRate = new QLabel(widget);
        lFrameRate->setObjectName(QString::fromUtf8("lFrameRate"));

        horizontalLayout_2->addWidget(lFrameRate);

        hp_widgetPlay1 = new QSpacerItem(0, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(hp_widgetPlay1);

        sbFps = new QDoubleSpinBox(widget);
        sbFps->setObjectName(QString::fromUtf8("sbFps"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(sbFps->sizePolicy().hasHeightForWidth());
        sbFps->setSizePolicy(sizePolicy2);
        sbFps->setMaximumSize(QSize(60, 16777215));
        sbFps->setMaximum(1000000.000000000000000);

        horizontalLayout_2->addWidget(sbFps);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 6);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tbDeleteFiles = new QToolButton(widget);
        tbDeleteFiles->setObjectName(QString::fromUtf8("tbDeleteFiles"));
        sizePolicy2.setHeightForWidth(tbDeleteFiles->sizePolicy().hasHeightForWidth());
        tbDeleteFiles->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(tbDeleteFiles);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        tbDeleteSelectedFile = new QToolButton(widget);
        tbDeleteSelectedFile->setObjectName(QString::fromUtf8("tbDeleteSelectedFile"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tbDeleteSelectedFile->sizePolicy().hasHeightForWidth());
        tbDeleteSelectedFile->setSizePolicy(sizePolicy3);
        tbDeleteSelectedFile->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(tbDeleteSelectedFile);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout_2->addLayout(verticalLayout, 2, 6, 1, 1);

        lFileName = new QLabel(widget);
        lFileName->setObjectName(QString::fromUtf8("lFileName"));

        gridLayout_2->addWidget(lFileName, 1, 0, 1, 1);

        sliderPlay = new QSlider(widget);
        sliderPlay->setObjectName(QString::fromUtf8("sliderPlay"));
        sliderPlay->setMouseTracking(false);
        sliderPlay->setMaximum(99);
        sliderPlay->setOrientation(Qt::Horizontal);
        sliderPlay->setTickPosition(QSlider::TicksBelow);
        sliderPlay->setTickInterval(10);

        gridLayout_2->addWidget(sliderPlay, 3, 0, 1, 7);

        leFolderPath = new QLineEdit(widget);
        leFolderPath->setObjectName(QString::fromUtf8("leFolderPath"));

        gridLayout_2->addWidget(leFolderPath, 1, 5, 1, 1);

        comBoxImageType = new QComboBox(widget);
        comBoxImageType->addItem(QString());
        comBoxImageType->addItem(QString());
        comBoxImageType->setObjectName(QString::fromUtf8("comBoxImageType"));
        comBoxImageType->setMinimumSize(QSize(125, 0));

        gridLayout_2->addWidget(comBoxImageType, 0, 6, 1, 1);

        leFileName = new QLineEdit(widget);
        leFileName->setObjectName(QString::fromUtf8("leFileName"));
        sizePolicy2.setHeightForWidth(leFileName->sizePolicy().hasHeightForWidth());
        leFileName->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(leFileName, 1, 1, 1, 1);

        tbSelectPath = new QToolButton(widget);
        tbSelectPath->setObjectName(QString::fromUtf8("tbSelectPath"));
        sizePolicy2.setHeightForWidth(tbSelectPath->sizePolicy().hasHeightForWidth());
        tbSelectPath->setSizePolicy(sizePolicy2);
        tbSelectPath->setMinimumSize(QSize(0, 0));

        gridLayout_2->addWidget(tbSelectPath, 1, 6, 1, 1);


        gridLayout->addWidget(widget, 2, 0, 1, 1);


        retranslateUi(WidgetPlay);

        QMetaObject::connectSlotsByName(WidgetPlay);
    } // setupUi

    void retranslateUi(QWidget *WidgetPlay)
    {
        WidgetPlay->setWindowTitle(QCoreApplication::translate("WidgetPlay", "Form", nullptr));
        labelTitle->setText(QCoreApplication::translate("WidgetPlay", "Play", nullptr));

        const bool __sortingEnabled = listWidgetNames->isSortingEnabled();
        listWidgetNames->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidgetNames->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("WidgetPlay", "Image 1", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidgetNames->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("WidgetPlay", "Image 2", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidgetNames->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("WidgetPlay", "Image 3", nullptr));
        listWidgetNames->setSortingEnabled(__sortingEnabled);

#if QT_CONFIG(tooltip)
        listWidgetNames->setToolTip(QCoreApplication::translate("WidgetPlay", "<html><head/><body><p><span style=\" font-size:10pt;\">Playlist</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lFolderPath->setText(QCoreApplication::translate("WidgetPlay", "Folder path ", nullptr));
#if QT_CONFIG(tooltip)
        tbPlay->setToolTip(QCoreApplication::translate("WidgetPlay", "<html><head/><body><p><span style=\" font-size:10pt;\">Play movies from playlist</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbPlay->setText(QCoreApplication::translate("WidgetPlay", "Play", nullptr));
#if QT_CONFIG(tooltip)
        tbStop->setToolTip(QCoreApplication::translate("WidgetPlay", "<html><head/><body><p><span style=\" font-size:10pt;\">Stop all operations</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbStop->setText(QCoreApplication::translate("WidgetPlay", "Stop", nullptr));
#if QT_CONFIG(tooltip)
        tbRecord->setToolTip(QCoreApplication::translate("WidgetPlay", "<html><head/><body><p><span style=\" font-size:10pt;\">Start image capturing and  recording</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbRecord->setText(QCoreApplication::translate("WidgetPlay", "Record", nullptr));
        lFrameRate->setText(QCoreApplication::translate("WidgetPlay", "FPS  ", nullptr));
#if QT_CONFIG(tooltip)
        sbFps->setToolTip(QCoreApplication::translate("WidgetPlay", "<html><head/><body><p><span style=\" font-size:10pt;\">Set play framerate</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        tbDeleteFiles->setToolTip(QCoreApplication::translate("WidgetPlay", "<html><head/><body><p><span style=\" font-size:10pt;\">Delete all logs from playlist</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbDeleteFiles->setText(QCoreApplication::translate("WidgetPlay", "Delete all logs", nullptr));
#if QT_CONFIG(tooltip)
        tbDeleteSelectedFile->setToolTip(QCoreApplication::translate("WidgetPlay", "<html><head/><body><p><span style=\" font-size:10pt;\">Delete selected log</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbDeleteSelectedFile->setText(QCoreApplication::translate("WidgetPlay", "Delete selected log", nullptr));
        lFileName->setText(QCoreApplication::translate("WidgetPlay", "File name", nullptr));
#if QT_CONFIG(tooltip)
        sliderPlay->setToolTip(QCoreApplication::translate("WidgetPlay", "<html><head/><body><p><span style=\" font-size:10pt;\">Slider with current play position</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        leFolderPath->setToolTip(QCoreApplication::translate("WidgetPlay", "<html><head/><body><p><span style=\" font-size:10pt;\">Playlist path</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        comBoxImageType->setItemText(0, QCoreApplication::translate("WidgetPlay", "Image", nullptr));
        comBoxImageType->setItemText(1, QCoreApplication::translate("WidgetPlay", "Point Cloud", nullptr));

#if QT_CONFIG(tooltip)
        comBoxImageType->setToolTip(QCoreApplication::translate("WidgetPlay", "<html><head/><body><p><span style=\" font-size:10pt;\">Show image or point cloud</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        comBoxImageType->setCurrentText(QCoreApplication::translate("WidgetPlay", "Image", nullptr));
#if QT_CONFIG(tooltip)
        leFileName->setToolTip(QCoreApplication::translate("WidgetPlay", "<html><head/><body><p><span style=\" font-size:10pt;\">This fiile name will be used for recording.</span></p><p><span style=\" font-size:10pt;\">The full file name will be created by adding selected file name and time stamp.</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        tbSelectPath->setToolTip(QCoreApplication::translate("WidgetPlay", "<html><head/><body><p><span style=\" font-size:10pt;\">Select playlist  path</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        tbSelectPath->setText(QCoreApplication::translate("WidgetPlay", "  Select Folder...  ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WidgetPlay: public Ui_WidgetPlay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_PLAY_H
