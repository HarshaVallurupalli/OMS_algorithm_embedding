/****************************************************************************
** Meta object code from reading C++ file 'WidgetInfo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../include/view/WidgetInfo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WidgetInfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WidgetInfo_t {
    QByteArrayData data[11];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WidgetInfo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WidgetInfo_t qt_meta_stringdata_WidgetInfo = {
    {
QT_MOC_LITERAL(0, 0, 10), // "WidgetInfo"
QT_MOC_LITERAL(1, 11, 17), // "onFpsTimerTimeout"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 17), // "onShowInfoChanged"
QT_MOC_LITERAL(4, 48, 7), // "checked"
QT_MOC_LITERAL(5, 56, 24), // "onMeasurementTypeChanged"
QT_MOC_LITERAL(6, 81, 18), // "onSelectionChanged"
QT_MOC_LITERAL(7, 100, 1), // "x"
QT_MOC_LITERAL(8, 102, 1), // "y"
QT_MOC_LITERAL(9, 104, 5), // "width"
QT_MOC_LITERAL(10, 110, 6) // "height"

    },
    "WidgetInfo\0onFpsTimerTimeout\0\0"
    "onShowInfoChanged\0checked\0"
    "onMeasurementTypeChanged\0onSelectionChanged\0"
    "x\0y\0width\0height"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WidgetInfo[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    1,   35,    2, 0x08 /* Private */,
       5,    0,   38,    2, 0x08 /* Private */,
       6,    4,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    7,    8,    9,   10,

       0        // eod
};

void WidgetInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WidgetInfo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onFpsTimerTimeout(); break;
        case 1: _t->onShowInfoChanged((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 2: _t->onMeasurementTypeChanged(); break;
        case 3: _t->onSelectionChanged((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])),(*reinterpret_cast< const int(*)>(_a[4]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WidgetInfo::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_WidgetInfo.data,
    qt_meta_data_WidgetInfo,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WidgetInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidgetInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WidgetInfo.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WidgetInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
