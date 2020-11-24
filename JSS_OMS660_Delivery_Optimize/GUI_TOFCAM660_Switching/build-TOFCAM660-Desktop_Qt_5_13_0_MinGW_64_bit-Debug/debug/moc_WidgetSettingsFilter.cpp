/****************************************************************************
** Meta object code from reading C++ file 'WidgetSettingsFilter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../include/view/WidgetSettingsFilter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WidgetSettingsFilter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WidgetSettingsFilter_t {
    QByteArrayData data[18];
    char stringdata0[468];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WidgetSettingsFilter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WidgetSettingsFilter_t qt_meta_stringdata_WidgetSettingsFilter = {
    {
QT_MOC_LITERAL(0, 0, 20), // "WidgetSettingsFilter"
QT_MOC_LITERAL(1, 21, 25), // "on_cbMedianFilter_toggled"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 7), // "checked"
QT_MOC_LITERAL(4, 56, 26), // "on_cbAverageFilter_toggled"
QT_MOC_LITERAL(5, 83, 27), // "on_cbTemporalFilter_toggled"
QT_MOC_LITERAL(6, 111, 24), // "on_sbFactor_valueChanged"
QT_MOC_LITERAL(7, 136, 4), // "arg1"
QT_MOC_LITERAL(8, 141, 27), // "on_sbThreshold_valueChanged"
QT_MOC_LITERAL(9, 169, 23), // "on_cbEdgeFilter_toggled"
QT_MOC_LITERAL(10, 193, 31), // "on_sbEdgeThreshold_valueChanged"
QT_MOC_LITERAL(11, 225, 31), // "on_cbTemporalEdgeFilter_toggled"
QT_MOC_LITERAL(12, 257, 34), // "on_cbInterferenceDetection_to..."
QT_MOC_LITERAL(13, 292, 42), // "on_sbTemporalEdgeThresholdLow..."
QT_MOC_LITERAL(14, 335, 43), // "on_sbTemporalEdgeThresholdHig..."
QT_MOC_LITERAL(15, 379, 44), // "on_sbInterferenceDetectionLim..."
QT_MOC_LITERAL(16, 424, 25), // "on_cbUseLastValue_toggled"
QT_MOC_LITERAL(17, 450, 17) // "modulationChanged"

    },
    "WidgetSettingsFilter\0on_cbMedianFilter_toggled\0"
    "\0checked\0on_cbAverageFilter_toggled\0"
    "on_cbTemporalFilter_toggled\0"
    "on_sbFactor_valueChanged\0arg1\0"
    "on_sbThreshold_valueChanged\0"
    "on_cbEdgeFilter_toggled\0"
    "on_sbEdgeThreshold_valueChanged\0"
    "on_cbTemporalEdgeFilter_toggled\0"
    "on_cbInterferenceDetection_toggled\0"
    "on_sbTemporalEdgeThresholdLow_valueChanged\0"
    "on_sbTemporalEdgeThresholdHigh_valueChanged\0"
    "on_sbInterferenceDetectionLimit_valueChanged\0"
    "on_cbUseLastValue_toggled\0modulationChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WidgetSettingsFilter[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x08 /* Private */,
       4,    1,   87,    2, 0x08 /* Private */,
       5,    1,   90,    2, 0x08 /* Private */,
       6,    1,   93,    2, 0x08 /* Private */,
       8,    1,   96,    2, 0x08 /* Private */,
       9,    1,   99,    2, 0x08 /* Private */,
      10,    1,  102,    2, 0x08 /* Private */,
      11,    1,  105,    2, 0x08 /* Private */,
      12,    1,  108,    2, 0x08 /* Private */,
      13,    1,  111,    2, 0x08 /* Private */,
      14,    1,  114,    2, 0x08 /* Private */,
      15,    1,  117,    2, 0x08 /* Private */,
      16,    1,  120,    2, 0x08 /* Private */,
      17,    0,  123,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,

       0        // eod
};

void WidgetSettingsFilter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WidgetSettingsFilter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_cbMedianFilter_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_cbAverageFilter_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_cbTemporalFilter_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_sbFactor_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->on_sbThreshold_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_cbEdgeFilter_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_sbEdgeThreshold_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_cbTemporalEdgeFilter_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_cbInterferenceDetection_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_sbTemporalEdgeThresholdLow_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_sbTemporalEdgeThresholdHigh_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_sbInterferenceDetectionLimit_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_cbUseLastValue_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->modulationChanged(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WidgetSettingsFilter::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_WidgetSettingsFilter.data,
    qt_meta_data_WidgetSettingsFilter,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WidgetSettingsFilter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidgetSettingsFilter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WidgetSettingsFilter.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WidgetSettingsFilter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
