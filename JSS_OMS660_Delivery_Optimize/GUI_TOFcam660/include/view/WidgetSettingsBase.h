/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef WIDGETSETTINGSBASE_H
#define WIDGETSETTINGSBASE_H

#include "ApplicationContext.h"
#include <QWidget>

namespace Ui {
class WidgetSettingsBase;
}

class WidgetSettingsBase : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetSettingsBase(ApplicationContext &context_, QWidget *parent = nullptr);
    ~WidgetSettingsBase();
    void restoreSettings();

private slots:
    void modulationChanged();


private:

    Ui::WidgetSettingsBase *ui;
    ApplicationContext &context;
};

#endif // WIDGETSETTINGSBASE_H
