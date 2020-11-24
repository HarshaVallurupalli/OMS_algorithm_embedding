#-------------------------------------------------
#
# Project created by QtCreator 2017-08-07T23:46:12
#
#-------------------------------------------------

CONFIG += qt
QT += core gui network charts
QT += opengl
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

TARGET = TOFCAM660
TEMPLATE = app


SOURCES += ../src/main.cpp\
    ../src/application/ApplicationContext.cpp \
    ../src/application/ImageColorizer.cpp \
    ../src/application/Interface.cpp \
    ../src/application/InterfaceThread.cpp \
    ../src/application/IoControl.cpp \
    ../src/application/TcpCmdConnection.cpp \
    ../src/application/EpcTransform.cpp \
    ../src/application/FunctionDistance.cpp \
    ../src/application/UdpDataConnection.cpp \
    ../src/application/Statistics.cpp \
    ../src/application/MultiPixelStatistics.cpp \
    ../src/controller/Controller.cpp \
    ../src/data/DataHeader.cpp \
    ../src/data/Settings.cpp \
    ../src/data/Selection.cpp \
    ../src/data/SettingsBinning.cpp \
    ../src/data/SettingsLog.cpp \
    ../src/data/SettingsPointCloud.cpp \
    ../src/data/SettingsFilter.cpp \
    ../src/data/RoiSettings.cpp \
    ../src/view/WidgetImage.cpp \
    ../src/view/WidgetCalibration.cpp \
    ../src/view/WidgetPointCloud.cpp \
    ../src/view/WidgetPointCloudSettings.cpp \
    ../src/view/PlotSurface.cpp \
    ../src/view/MainWindow.cpp \
    ../src/view/WidgetData.cpp \
    ../src/view/WidgetHeader.cpp \
    ../src/view/WidgetTools.cpp \
    ../src/view/WindowControls.cpp \
    ../src/view/LabelImage.cpp \
    ../src/view/WidgetSettingsBase.cpp \
    ../src/view/WidgetSettingsFilter.cpp \
    ../src/view/WidgetSettingsModulation.cpp \
    ../src/view/WidgetRoi.cpp \
    ../src/application/TcpTraceClient.cpp \
    ../src/application/KeyHandler.cpp  \
    ../src/view/WidgetPlay.cpp \
    ../src/view/WidgetPixelScope.cpp \
    ../src/view/WidgetTimeScope.cpp \
    ../src/view/WidgetInfo.cpp \
    ../src/view/WidgetSaveLoad.cpp \
    ../src/view/WidgetSettings.cpp \
    ../src/view/WidgetSettingsBinning.cpp



SOURCES += \
    ../src/qwtplot3d/qwt3d_axis.cpp \
    ../src/qwtplot3d/qwt3d_color.cpp \
    ../src/qwtplot3d/qwt3d_coordsys.cpp \
    ../src/qwtplot3d/qwt3d_drawable.cpp \
    ../src/qwtplot3d/qwt3d_mousekeyboard.cpp \
    ../src/qwtplot3d/qwt3d_movements.cpp \
    ../src/qwtplot3d/qwt3d_lighting.cpp \
    ../src/qwtplot3d/qwt3d_colorlegend.cpp \
    ../src/qwtplot3d/qwt3d_plot.cpp \
    ../src/qwtplot3d/qwt3d_label.cpp \
    ../src/qwtplot3d/qwt3d_types.cpp \
    ../src/qwtplot3d/qwt3d_enrichment_std.cpp \
    ../src/qwtplot3d/qwt3d_autoscaler.cpp \
    ../src/qwtplot3d/qwt3d_io_reader.cpp \
    ../src/qwtplot3d/qwt3d_io.cpp \
    ../src/qwtplot3d/qwt3d_scale.cpp \
    ../src/qwtplot3d/qwt3d_gridmapping.cpp \
    ../src/qwtplot3d/qwt3d_function.cpp \
    ../src/qwtplot3d/qwt3d_io_gl2ps.cpp \
    ../src/qwtplot3d/3rdparty/gl2ps/gl2ps.c \
    ../src/qwtplot3d/qwt3d_surfaceplot.cpp \
    ../src/qwtplot3d/qwt3d_gridplot.cpp \
    ../src/qwtplot3d/qwt3d_meshplot.cpp



HEADERS  += \
    ../include/application/ApplicationContext.h \
    ../include/application/CameraSelection.h \
    ../include/application/CommunicationConstants.h \
    ../include/application/ImageColorizer.h \
    ../include/application/Interface.h \
    ../include/application/InterfaceThread.h \
    ../include/application/EpcTransform.h \
    ../include/application/FunctionDistance.h \
    ../include/application/IoControl.h \
    ../include/application/TcpCmdConnection.h \
    ../include/application/UdpDataConnection.h \
    ../include/application/CmdConnection.h \
    ../include/application/DataConnection.h \
    ../include/application/Statistics.h \
    ../include/application/TypeApplicationState.h \
    ../include/application/TcpTraceClient.h \
    ../include/application/KeyHandler.h \
    ../include/application/MeasurementType.h \
    ../include/application/MultiPixelStatistics.h \
    ../include/controller/Controller.h \
    ../include/data/DataHeader.h \
    ../include/data/Settings.h \
    ../include/data/Selection.h \
    ../include/data/SettingsBinning.h \
    ../include/data/SettingsPointCloud.h \
    ../include/data/SettingsFilter.h \
    ../include/data/SettingsLog.h \
    ../include/data/RoiSettings.h \
    ../include/global/EPC660.h \
    ../include/global/ChipSelection.h \
    ../include/global/Release.h \
    ../include/view/WidgetImage.h \
    ../include/view/WidgetCalibration.h \
    ../include/view/WidgetPointCloud.h \
    ../include/view/WidgetPointCloudSettings.h \
    ../include/view/PlotSurface.h \
    ../include/view/MainWindow.h \
    ../include/view/WidgetData.h \
    ../include/view/WidgetHeader.h \
    ../include/view/WidgetTools.h \
    ../include/view/WindowControls.h \
    ../include/view/WidgetSettingsBase.h \
    ../include/view/WidgetSettingsBinning.h \
    ../include/view/WidgetSettingsFilter.h \
    ../include/view/WidgetSettingsModulation.h \
    ../include/view/LabelImage.h \
    ../include/view/WidgetPixelScope.h \
    ../include/view/WidgetTimeScope.h \
    ../include/view/WidgetInfo.h \
    ../include/view/WidgetPlay.h \
    ../include/view/WidgetSaveLoad.h \
    ../include/view/WidgetSettings.h \
    ../include/view/WidgetRoi.h



HEADERS += \
    ../include/qwtplot3d/qwt3d_color.h \
    ../include/qwtplot3d/qwt3d_global.h \
    ../include/qwtplot3d/qwt3d_types.h \
    ../include/qwtplot3d/qwt3d_axis.h \
    ../include/qwtplot3d/qwt3d_coordsys.h \
    ../include/qwtplot3d/qwt3d_drawable.h \
    ../include/qwtplot3d/qwt3d_helper.h \
    ../include/qwtplot3d/qwt3d_label.h \
    ../include/qwtplot3d/qwt3d_openglhelper.h \
    ../include/qwtplot3d/qwt3d_colorlegend.h \
    ../include/qwtplot3d/qwt3d_plot.h \
    ../include/qwtplot3d/qwt3d_enrichment.h \
    ../include/qwtplot3d/qwt3d_enrichment_std.h \
    ../include/qwtplot3d/qwt3d_autoscaler.h \
    ../include/qwtplot3d/qwt3d_autoptr.h \
    ../include/qwtplot3d/qwt3d_io.h \
    ../include/qwtplot3d/qwt3d_io_reader.h \
    ../include/qwtplot3d/qwt3d_scale.h \
    ../include/qwtplot3d/qwt3d_portability.h  \
    ../include/qwtplot3d/qwt3d_mapping.h \
    ../include/qwtplot3d/qwt3d_gridmapping.h \
    ../include/qwtplot3d/qwt3d_function.h \
    ../include/qwtplot3d/qwt3d_surfaceplot.h \
    ../include/qwtplot3d/qwt3d_io_gl2ps.h



FORMS    += \
    ../ui/mainwindow.ui \
    ../ui/widget_header.ui \
    ../ui/widget_data.ui \
    ../ui/widget_image.ui \
    ../ui/widget_calibration.ui \
    ../ui/widget_point_cloud.ui \
    ../ui/widget_point_cloud_settings.ui \
    ../ui/widget_tools.ui \
    ../ui/widget_settings_base.ui \
    ../ui/widget_settings_binning.ui \
    ../ui/widget_settings_filter.ui \
    ../ui/widget_settings_modulation.ui \
    ../ui/window_controls.ui \
    ../ui/widget_play.ui \
    ../ui/widget_pixelscope.ui \
    ../ui/widget_timescope.ui \
    ../ui/widget_info.ui \
    ../ui/widget_save_load.ui \
    ../ui/widget_settings.ui \
    ../ui/widget_roi.ui


INCLUDEPATH += \
     ../include/ \
     ../include/view \
     ../include/application \
     ../include/data \
     ../include/controller \
     ../include/qwtplot3d

RESOURCES += \    
    ../res/images.qrc \
    ../res/stylesheets.qrc

win32{
    message("We are on Windows 32")
    LIBS += -lopengl32
    RC_FILE = ../res/icon/application_icon.rc
    LIBS   += -lopengl32
    LIBS   += -lglu32    
}

macx{
    message ("We are on MAC OS X")
    ICON = ../res/icon/application_icon.icns
}

unix:!macx{
    message ("We are on Linux")
    LIBS += -lGLU
}
