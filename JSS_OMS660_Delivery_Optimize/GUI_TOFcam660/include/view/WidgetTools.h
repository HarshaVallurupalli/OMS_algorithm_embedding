/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef WIDGETTOOLS_H
#define WIDGETTOOLS_H

#include <QWidget>
#include "ApplicationContext.h"
#include "DataHeader.h"

namespace Ui {
class WidgetTools;
}

class WidgetTools: public QWidget
{
  Q_OBJECT

  public:
    explicit WidgetTools(ApplicationContext &context, QWidget *parent = nullptr);
    ~WidgetTools();

    void updateHeaderData(DataHeader &dataHeader);

  private slots:
    void onUserDataChanged();

  private:
    void onRestoreSettings();

    ApplicationContext &context;
    Ui::WidgetTools *ui;
};

#endif // WIDGETTOOLS_H
