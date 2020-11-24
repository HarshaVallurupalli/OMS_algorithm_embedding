#ifndef WIDGETPOINTCLOUDVIEW_H
#define WIDGETPOINTCLOUDVIEW_H

#include "Settings.h"
#include "PlotSurface.h"

#include <QWidget>

namespace Ui {
class WidgetPointCloudView;
}

class WidgetPointCloudView : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetPointCloudView(Settings &set, PlotSurface *surfacePlot, QWidget *parent = nullptr);
    ~WidgetPointCloudView();
    void restoreSettings();
    void initControls();
    void updateControls();
    void setPerspective(bool state);

private slots:
    void on_tbClose_clicked();
    void on_cbAxis2D_toggled(bool checked);
    void on_cbAxis3D_toggled(bool checked);
    void on_cbGrid_toggled(bool checked);
    void on_cbUndistortion_toggled(bool checked);
    void on_cbCartesian_toggled(bool checked);    
    void on_cbPerspectiveView_toggled(bool checked);
    void on_cbGrayPointCloud_toggled(bool checked);
    void on_sbSurfaceInterconnect_valueChanged(int arg1);
    void on_dbPointSize_valueChanged(double arg1);
    void on_cbPoints_toggled(bool checked);
    void on_cbSurfaceInterconnect_toggled(bool checked);
    void on_cbAutoRotating_toggled(bool checked);

signals:
    void grayPointCloudChanged(bool);
    void autoRotatingToggled(bool);



private:
    Ui::WidgetPointCloudView *ui;    
    PlotSurface *surfacePlot;
    Settings &set;
};

#endif // WIDGETPOINTCLOUDVIEW_H
