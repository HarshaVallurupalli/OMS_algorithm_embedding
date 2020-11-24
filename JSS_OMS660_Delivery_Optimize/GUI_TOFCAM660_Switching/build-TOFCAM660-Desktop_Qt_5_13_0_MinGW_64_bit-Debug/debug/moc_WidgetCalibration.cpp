/****************************************************************************
** Meta object code from reading C++ file 'WidgetCalibration.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../include/view/WidgetCalibration.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WidgetCalibration.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WidgetCalibration_t {
    QByteArrayData data[9];
    char stringdata0[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WidgetCalibration_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WidgetCalibration_t qt_meta_stringdata_WidgetCalibration = {
    {
QT_MOC_LITERAL(0, 0, 17), // "WidgetCalibration"
QT_MOC_LITERAL(1, 18, 13), // "onStateChange"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 30), // "onPushButtonCalibrationClicked"
QT_MOC_LITERAL(4, 64, 40), // "onPushButtonProductionCalibra..."
QT_MOC_LITERAL(5, 105, 15), // "onTraceReceived"
QT_MOC_LITERAL(6, 121, 4), // "text"
QT_MOC_LITERAL(7, 126, 16), // "sendDebugCommand"
QT_MOC_LITERAL(8, 143, 7) // "command"

    },
    "WidgetCalibration\0onStateChange\0\0"
    "onPushButtonCalibrationClicked\0"
    "onPushButtonProductionCalibrationClicked\0"
    "onTraceReceived\0text\0sendDebugCommand\0"
    "command"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WidgetCalibration[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    1,   42,    2, 0x08 /* Private */,
       7,    2,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::UInt,    6,    8,

       0        // eod
};

void WidgetCalibration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WidgetCalibration *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onStateChange(); break;
        case 1: _t->onPushButtonCalibrationClicked(); break;
        case 2: _t->onPushButtonProductionCalibrationClicked(); break;
        case 3: _t->onTraceReceived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->sendDebugCommand((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< const uint(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WidgetCalibration::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_WidgetCalibration.data,
    qt_meta_data_WidgetCalibration,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WidgetCalibration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidgetCalibration::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WidgetCalibration.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WidgetCalibration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
