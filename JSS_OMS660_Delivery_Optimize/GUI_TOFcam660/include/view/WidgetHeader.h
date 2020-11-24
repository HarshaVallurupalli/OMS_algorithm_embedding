/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef WIDGET_HEADER_H
#define WIDGET_HEADER_H

#include <QWidget>
#include "DataHeader.h"

namespace Ui {
class WidgetHeader;
}

class WidgetHeader: public QWidget
{
   Q_OBJECT

public:
    explicit WidgetHeader(QWidget *parent = nullptr);
    ~WidgetHeader();
    void showHeaderData(DataHeader &dataHeader);

  private:
    Ui::WidgetHeader *ui;
};

#endif // WIDGET_HEADER_H
