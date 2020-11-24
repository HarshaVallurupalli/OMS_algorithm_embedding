/****************************************************************************
** Meta object code from reading C++ file 'WidgetPointCloudSettings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../include/view/WidgetPointCloudSettings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WidgetPointCloudSettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WidgetPointCloudSettings_t {
    QByteArrayData data[72];
    char stringdata0[1571];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WidgetPointCloudSettings_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WidgetPointCloudSettings_t qt_meta_stringdata_WidgetPointCloudSettings = {
    {
QT_MOC_LITERAL(0, 0, 24), // "WidgetPointCloudSettings"
QT_MOC_LITERAL(1, 25, 15), // "updateControlls"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 11), // "transform_e"
QT_MOC_LITERAL(4, 54, 4), // "type"
QT_MOC_LITERAL(5, 59, 21), // "grayPointCloudChanged"
QT_MOC_LITERAL(6, 81, 16), // "resetDefaultView"
QT_MOC_LITERAL(7, 98, 22), // "on_tbAxisColor_clicked"
QT_MOC_LITERAL(8, 121, 28), // "on_tbBackgroundColor_clicked"
QT_MOC_LITERAL(9, 150, 22), // "on_tbGridColor_clicked"
QT_MOC_LITERAL(10, 173, 27), // "on_sbCellWidth_valueChanged"
QT_MOC_LITERAL(11, 201, 4), // "arg1"
QT_MOC_LITERAL(12, 206, 26), // "on_sbNumCells_valueChanged"
QT_MOC_LITERAL(13, 233, 30), // "on_sbdTransparent_valueChanged"
QT_MOC_LITERAL(14, 264, 25), // "on_sbOffsetX_valueChanged"
QT_MOC_LITERAL(15, 290, 25), // "on_sbOffsetY_valueChanged"
QT_MOC_LITERAL(16, 316, 25), // "on_sbOffsetZ_valueChanged"
QT_MOC_LITERAL(17, 342, 24), // "on_sbAngleX_valueChanged"
QT_MOC_LITERAL(18, 367, 24), // "on_sbAngleY_valueChanged"
QT_MOC_LITERAL(19, 392, 24), // "on_sbAngleZ_valueChanged"
QT_MOC_LITERAL(20, 417, 18), // "on_tbClose_clicked"
QT_MOC_LITERAL(21, 436, 31), // "on_sbAxisLineWidth_valueChanged"
QT_MOC_LITERAL(22, 468, 33), // "on_dbAxisTransparent_valueCha..."
QT_MOC_LITERAL(23, 502, 29), // "on_sbAxisOffsetX_valueChanged"
QT_MOC_LITERAL(24, 532, 29), // "on_sbAxisOffsetY_valueChanged"
QT_MOC_LITERAL(25, 562, 29), // "on_sbAxisOffsetZ_valueChanged"
QT_MOC_LITERAL(26, 592, 32), // "on_sbCameraOffesetX_valueChanged"
QT_MOC_LITERAL(27, 625, 32), // "on_sbCameraOffesetY_valueChanged"
QT_MOC_LITERAL(28, 658, 19), // "vieportShiftChanged"
QT_MOC_LITERAL(29, 678, 7), // "offsetX"
QT_MOC_LITERAL(30, 686, 7), // "offsetY"
QT_MOC_LITERAL(31, 694, 11), // "zoomChanged"
QT_MOC_LITERAL(32, 706, 4), // "zoom"
QT_MOC_LITERAL(33, 711, 12), // "scaleChanged"
QT_MOC_LITERAL(34, 724, 15), // "rotationChanged"
QT_MOC_LITERAL(35, 740, 6), // "xAngle"
QT_MOC_LITERAL(36, 747, 6), // "yAngle"
QT_MOC_LITERAL(37, 754, 6), // "zAngle"
QT_MOC_LITERAL(38, 761, 12), // "shiftChanged"
QT_MOC_LITERAL(39, 774, 6), // "xShift"
QT_MOC_LITERAL(40, 781, 6), // "yShift"
QT_MOC_LITERAL(41, 788, 6), // "zShift"
QT_MOC_LITERAL(42, 795, 22), // "on_dbZoom_valueChanged"
QT_MOC_LITERAL(43, 818, 24), // "on_dbScaleX_valueChanged"
QT_MOC_LITERAL(44, 843, 24), // "on_dbScaleY_valueChanged"
QT_MOC_LITERAL(45, 868, 24), // "on_dbScaleZ_valueChanged"
QT_MOC_LITERAL(46, 893, 31), // "on_sbObjectOffsetX_valueChanged"
QT_MOC_LITERAL(47, 925, 31), // "on_sbObjectOffsetY_valueChanged"
QT_MOC_LITERAL(48, 957, 31), // "on_sbObjectOffsetZ_valueChanged"
QT_MOC_LITERAL(49, 989, 21), // "on_rbRectGrid_toggled"
QT_MOC_LITERAL(50, 1011, 7), // "checked"
QT_MOC_LITERAL(51, 1019, 30), // "on_sbAngleObjectZ_valueChanged"
QT_MOC_LITERAL(52, 1050, 23), // "on_tbLabelColor_clicked"
QT_MOC_LITERAL(53, 1074, 23), // "on_cbShowLabels_toggled"
QT_MOC_LITERAL(54, 1098, 23), // "on_cbShowLegend_toggled"
QT_MOC_LITERAL(55, 1122, 22), // "on_tbLabelFont_clicked"
QT_MOC_LITERAL(56, 1145, 32), // "on_cbSurfaceInterconnect_toggled"
QT_MOC_LITERAL(57, 1178, 19), // "on_cbPoints_toggled"
QT_MOC_LITERAL(58, 1198, 37), // "on_sbSurfaceInterconnect_valu..."
QT_MOC_LITERAL(59, 1236, 27), // "on_dbPointSize_valueChanged"
QT_MOC_LITERAL(60, 1264, 19), // "on_cbAxis2D_toggled"
QT_MOC_LITERAL(61, 1284, 19), // "on_cbAxis3D_toggled"
QT_MOC_LITERAL(62, 1304, 17), // "on_cbGrid_toggled"
QT_MOC_LITERAL(63, 1322, 28), // "on_cbPerspectiveView_toggled"
QT_MOC_LITERAL(64, 1351, 22), // "on_cbCartesian_toggled"
QT_MOC_LITERAL(65, 1374, 25), // "on_cbUndistortion_toggled"
QT_MOC_LITERAL(66, 1400, 31), // "on_sbSensorOffsetX_valueChanged"
QT_MOC_LITERAL(67, 1432, 31), // "on_sbSensorOffsetY_valueChanged"
QT_MOC_LITERAL(68, 1464, 22), // "on_rbWideField_toggled"
QT_MOC_LITERAL(69, 1487, 24), // "on_rbNarrowField_toggled"
QT_MOC_LITERAL(70, 1512, 28), // "on_tbSaveDefaultView_clicked"
QT_MOC_LITERAL(71, 1541, 29) // "on_tbResetDefaultView_clicked"

    },
    "WidgetPointCloudSettings\0updateControlls\0"
    "\0transform_e\0type\0grayPointCloudChanged\0"
    "resetDefaultView\0on_tbAxisColor_clicked\0"
    "on_tbBackgroundColor_clicked\0"
    "on_tbGridColor_clicked\0"
    "on_sbCellWidth_valueChanged\0arg1\0"
    "on_sbNumCells_valueChanged\0"
    "on_sbdTransparent_valueChanged\0"
    "on_sbOffsetX_valueChanged\0"
    "on_sbOffsetY_valueChanged\0"
    "on_sbOffsetZ_valueChanged\0"
    "on_sbAngleX_valueChanged\0"
    "on_sbAngleY_valueChanged\0"
    "on_sbAngleZ_valueChanged\0on_tbClose_clicked\0"
    "on_sbAxisLineWidth_valueChanged\0"
    "on_dbAxisTransparent_valueChanged\0"
    "on_sbAxisOffsetX_valueChanged\0"
    "on_sbAxisOffsetY_valueChanged\0"
    "on_sbAxisOffsetZ_valueChanged\0"
    "on_sbCameraOffesetX_valueChanged\0"
    "on_sbCameraOffesetY_valueChanged\0"
    "vieportShiftChanged\0offsetX\0offsetY\0"
    "zoomChanged\0zoom\0scaleChanged\0"
    "rotationChanged\0xAngle\0yAngle\0zAngle\0"
    "shiftChanged\0xShift\0yShift\0zShift\0"
    "on_dbZoom_valueChanged\0on_dbScaleX_valueChanged\0"
    "on_dbScaleY_valueChanged\0"
    "on_dbScaleZ_valueChanged\0"
    "on_sbObjectOffsetX_valueChanged\0"
    "on_sbObjectOffsetY_valueChanged\0"
    "on_sbObjectOffsetZ_valueChanged\0"
    "on_rbRectGrid_toggled\0checked\0"
    "on_sbAngleObjectZ_valueChanged\0"
    "on_tbLabelColor_clicked\0on_cbShowLabels_toggled\0"
    "on_cbShowLegend_toggled\0on_tbLabelFont_clicked\0"
    "on_cbSurfaceInterconnect_toggled\0"
    "on_cbPoints_toggled\0"
    "on_sbSurfaceInterconnect_valueChanged\0"
    "on_dbPointSize_valueChanged\0"
    "on_cbAxis2D_toggled\0on_cbAxis3D_toggled\0"
    "on_cbGrid_toggled\0on_cbPerspectiveView_toggled\0"
    "on_cbCartesian_toggled\0on_cbUndistortion_toggled\0"
    "on_sbSensorOffsetX_valueChanged\0"
    "on_sbSensorOffsetY_valueChanged\0"
    "on_rbWideField_toggled\0on_rbNarrowField_toggled\0"
    "on_tbSaveDefaultView_clicked\0"
    "on_tbResetDefaultView_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WidgetPointCloudSettings[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      57,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  299,    2, 0x06 /* Public */,
       5,    1,  302,    2, 0x06 /* Public */,
       6,    0,  305,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,  306,    2, 0x08 /* Private */,
       8,    0,  307,    2, 0x08 /* Private */,
       9,    0,  308,    2, 0x08 /* Private */,
      10,    1,  309,    2, 0x08 /* Private */,
      12,    1,  312,    2, 0x08 /* Private */,
      13,    1,  315,    2, 0x08 /* Private */,
      14,    1,  318,    2, 0x08 /* Private */,
      15,    1,  321,    2, 0x08 /* Private */,
      16,    1,  324,    2, 0x08 /* Private */,
      17,    1,  327,    2, 0x08 /* Private */,
      18,    1,  330,    2, 0x08 /* Private */,
      19,    1,  333,    2, 0x08 /* Private */,
      20,    0,  336,    2, 0x08 /* Private */,
      21,    1,  337,    2, 0x08 /* Private */,
      22,    1,  340,    2, 0x08 /* Private */,
      23,    1,  343,    2, 0x08 /* Private */,
      24,    1,  346,    2, 0x08 /* Private */,
      25,    1,  349,    2, 0x08 /* Private */,
      26,    1,  352,    2, 0x08 /* Private */,
      27,    1,  355,    2, 0x08 /* Private */,
      28,    2,  358,    2, 0x08 /* Private */,
      31,    1,  363,    2, 0x08 /* Private */,
      33,    3,  366,    2, 0x08 /* Private */,
      34,    3,  373,    2, 0x08 /* Private */,
      38,    3,  380,    2, 0x08 /* Private */,
      42,    1,  387,    2, 0x08 /* Private */,
      43,    1,  390,    2, 0x08 /* Private */,
      44,    1,  393,    2, 0x08 /* Private */,
      45,    1,  396,    2, 0x08 /* Private */,
      46,    1,  399,    2, 0x08 /* Private */,
      47,    1,  402,    2, 0x08 /* Private */,
      48,    1,  405,    2, 0x08 /* Private */,
      49,    1,  408,    2, 0x08 /* Private */,
      51,    1,  411,    2, 0x08 /* Private */,
      52,    0,  414,    2, 0x08 /* Private */,
      53,    1,  415,    2, 0x08 /* Private */,
      54,    1,  418,    2, 0x08 /* Private */,
      55,    0,  421,    2, 0x08 /* Private */,
      56,    1,  422,    2, 0x08 /* Private */,
      57,    1,  425,    2, 0x08 /* Private */,
      58,    1,  428,    2, 0x08 /* Private */,
      59,    1,  431,    2, 0x08 /* Private */,
      60,    1,  434,    2, 0x08 /* Private */,
      61,    1,  437,    2, 0x08 /* Private */,
      62,    1,  440,    2, 0x08 /* Private */,
      63,    1,  443,    2, 0x08 /* Private */,
      64,    1,  446,    2, 0x08 /* Private */,
      65,    1,  449,    2, 0x08 /* Private */,
      66,    1,  452,    2, 0x08 /* Private */,
      67,    1,  455,    2, 0x08 /* Private */,
      68,    1,  458,    2, 0x08 /* Private */,
      69,    1,  461,    2, 0x08 /* Private */,
      70,    0,  464,    2, 0x08 /* Private */,
      71,    0,  465,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,   29,   30,
    QMetaType::Void, QMetaType::Double,   32,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,    2,    2,    2,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,   35,   36,   37,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double,   39,   40,   41,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Bool,   50,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   50,
    QMetaType::Void, QMetaType::Bool,   50,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   50,
    QMetaType::Void, QMetaType::Bool,   50,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Bool,   50,
    QMetaType::Void, QMetaType::Bool,   50,
    QMetaType::Void, QMetaType::Bool,   50,
    QMetaType::Void, QMetaType::Bool,   50,
    QMetaType::Void, QMetaType::Bool,   50,
    QMetaType::Void, QMetaType::Bool,   50,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Bool,   50,
    QMetaType::Void, QMetaType::Bool,   50,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WidgetPointCloudSettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WidgetPointCloudSettings *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateControlls((*reinterpret_cast< transform_e(*)>(_a[1]))); break;
        case 1: _t->grayPointCloudChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->resetDefaultView(); break;
        case 3: _t->on_tbAxisColor_clicked(); break;
        case 4: _t->on_tbBackgroundColor_clicked(); break;
        case 5: _t->on_tbGridColor_clicked(); break;
        case 6: _t->on_sbCellWidth_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_sbNumCells_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_sbdTransparent_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->on_sbOffsetX_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_sbOffsetY_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_sbOffsetZ_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_sbAngleX_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_sbAngleY_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_sbAngleZ_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->on_tbClose_clicked(); break;
        case 16: _t->on_sbAxisLineWidth_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->on_dbAxisTransparent_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: _t->on_sbAxisOffsetX_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->on_sbAxisOffsetY_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->on_sbAxisOffsetZ_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->on_sbCameraOffesetX_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->on_sbCameraOffesetY_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->vieportShiftChanged((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 24: _t->zoomChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 25: _t->scaleChanged((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 26: _t->rotationChanged((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 27: _t->shiftChanged((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 28: _t->on_dbZoom_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 29: _t->on_dbScaleX_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 30: _t->on_dbScaleY_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 31: _t->on_dbScaleZ_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 32: _t->on_sbObjectOffsetX_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->on_sbObjectOffsetY_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->on_sbObjectOffsetZ_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->on_rbRectGrid_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 36: _t->on_sbAngleObjectZ_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: _t->on_tbLabelColor_clicked(); break;
        case 38: _t->on_cbShowLabels_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 39: _t->on_cbShowLegend_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 40: _t->on_tbLabelFont_clicked(); break;
        case 41: _t->on_cbSurfaceInterconnect_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 42: _t->on_cbPoints_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 43: _t->on_sbSurfaceInterconnect_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 44: _t->on_dbPointSize_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 45: _t->on_cbAxis2D_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 46: _t->on_cbAxis3D_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 47: _t->on_cbGrid_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 48: _t->on_cbPerspectiveView_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 49: _t->on_cbCartesian_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 50: _t->on_cbUndistortion_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 51: _t->on_sbSensorOffsetX_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 52: _t->on_sbSensorOffsetY_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 53: _t->on_rbWideField_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 54: _t->on_rbNarrowField_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 55: _t->on_tbSaveDefaultView_clicked(); break;
        case 56: _t->on_tbResetDefaultView_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WidgetPointCloudSettings::*)(transform_e );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetPointCloudSettings::updateControlls)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WidgetPointCloudSettings::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetPointCloudSettings::grayPointCloudChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (WidgetPointCloudSettings::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetPointCloudSettings::resetDefaultView)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WidgetPointCloudSettings::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_WidgetPointCloudSettings.data,
    qt_meta_data_WidgetPointCloudSettings,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WidgetPointCloudSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidgetPointCloudSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WidgetPointCloudSettings.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WidgetPointCloudSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 57)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 57;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 57)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 57;
    }
    return _id;
}

// SIGNAL 0
void WidgetPointCloudSettings::updateControlls(transform_e _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WidgetPointCloudSettings::grayPointCloudChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WidgetPointCloudSettings::resetDefaultView()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
