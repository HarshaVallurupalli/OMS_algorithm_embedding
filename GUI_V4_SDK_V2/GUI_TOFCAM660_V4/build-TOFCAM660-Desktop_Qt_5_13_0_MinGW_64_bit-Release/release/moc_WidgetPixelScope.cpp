/****************************************************************************
** Meta object code from reading C++ file 'WidgetPixelScope.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../include/view/WidgetPixelScope.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WidgetPixelScope.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WidgetPixelScope_t {
    QByteArrayData data[20];
    char stringdata0[273];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WidgetPixelScope_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WidgetPixelScope_t qt_meta_stringdata_WidgetPixelScope = {
    {
QT_MOC_LITERAL(0, 0, 16), // "WidgetPixelScope"
QT_MOC_LITERAL(1, 17, 23), // "onShowPixelScopeChanged"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 7), // "checked"
QT_MOC_LITERAL(4, 50, 18), // "onSelectionChanged"
QT_MOC_LITERAL(5, 69, 1), // "x"
QT_MOC_LITERAL(6, 71, 1), // "y"
QT_MOC_LITERAL(7, 73, 5), // "width"
QT_MOC_LITERAL(8, 79, 6), // "height"
QT_MOC_LITERAL(9, 86, 24), // "onMeasurementTypeChanged"
QT_MOC_LITERAL(10, 111, 30), // "on_spinBoxLeftMin_valueChanged"
QT_MOC_LITERAL(11, 142, 4), // "arg1"
QT_MOC_LITERAL(12, 147, 30), // "on_spinBoxLeftMax_valueChanged"
QT_MOC_LITERAL(13, 178, 28), // "on_checkBoxAutoScale_clicked"
QT_MOC_LITERAL(14, 207, 14), // "onDataReceived"
QT_MOC_LITERAL(15, 222, 11), // "const char*"
QT_MOC_LITERAL(16, 234, 5), // "pData"
QT_MOC_LITERAL(17, 240, 11), // "DataHeader&"
QT_MOC_LITERAL(18, 252, 10), // "dataHeader"
QT_MOC_LITERAL(19, 263, 9) // "amplitude"

    },
    "WidgetPixelScope\0onShowPixelScopeChanged\0"
    "\0checked\0onSelectionChanged\0x\0y\0width\0"
    "height\0onMeasurementTypeChanged\0"
    "on_spinBoxLeftMin_valueChanged\0arg1\0"
    "on_spinBoxLeftMax_valueChanged\0"
    "on_checkBoxAutoScale_clicked\0"
    "onDataReceived\0const char*\0pData\0"
    "DataHeader&\0dataHeader\0amplitude"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WidgetPixelScope[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x08 /* Private */,
       4,    4,   52,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,
      10,    1,   62,    2, 0x08 /* Private */,
      12,    1,   65,    2, 0x08 /* Private */,
      13,    0,   68,    2, 0x08 /* Private */,
      14,    3,   69,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    5,    6,    7,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15, 0x80000000 | 17, QMetaType::Bool,   16,   18,   19,

       0        // eod
};

void WidgetPixelScope::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WidgetPixelScope *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onShowPixelScopeChanged((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 1: _t->onSelectionChanged((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])),(*reinterpret_cast< const int(*)>(_a[4]))); break;
        case 2: _t->onMeasurementTypeChanged(); break;
        case 3: _t->on_spinBoxLeftMin_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_spinBoxLeftMax_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_checkBoxAutoScale_clicked(); break;
        case 6: _t->onDataReceived((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< DataHeader(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WidgetPixelScope::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_WidgetPixelScope.data,
    qt_meta_data_WidgetPixelScope,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WidgetPixelScope::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidgetPixelScope::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WidgetPixelScope.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WidgetPixelScope::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
