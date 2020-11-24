/****************************************************************************
** Meta object code from reading C++ file 'Controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../include/controller/Controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Controller_t {
    QByteArrayData data[21];
    char stringdata0[239];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Controller_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Controller_t qt_meta_stringdata_Controller = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Controller"
QT_MOC_LITERAL(1, 11, 23), // "receivedMeasurementData"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 11), // "const char*"
QT_MOC_LITERAL(4, 48, 5), // "pData"
QT_MOC_LITERAL(5, 54, 6), // "length"
QT_MOC_LITERAL(6, 61, 11), // "DataHeader&"
QT_MOC_LITERAL(7, 73, 10), // "dataHeader"
QT_MOC_LITERAL(8, 84, 9), // "updateFps"
QT_MOC_LITERAL(9, 94, 3), // "fps"
QT_MOC_LITERAL(10, 98, 9), // "connected"
QT_MOC_LITERAL(11, 108, 12), // "disconnected"
QT_MOC_LITERAL(12, 121, 5), // "error"
QT_MOC_LITERAL(13, 127, 8), // "uint16_t"
QT_MOC_LITERAL(14, 136, 11), // "errorNumber"
QT_MOC_LITERAL(15, 148, 12), // "receivedData"
QT_MOC_LITERAL(16, 161, 8), // "complete"
QT_MOC_LITERAL(17, 170, 11), // "onFpsUpdate"
QT_MOC_LITERAL(18, 182, 22), // "cmdConnectionConnected"
QT_MOC_LITERAL(19, 205, 25), // "cmdConnectionDisconnected"
QT_MOC_LITERAL(20, 231, 7) // "onError"

    },
    "Controller\0receivedMeasurementData\0\0"
    "const char*\0pData\0length\0DataHeader&\0"
    "dataHeader\0updateFps\0fps\0connected\0"
    "disconnected\0error\0uint16_t\0errorNumber\0"
    "receivedData\0complete\0onFpsUpdate\0"
    "cmdConnectionConnected\0cmdConnectionDisconnected\0"
    "onError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Controller[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   64,    2, 0x06 /* Public */,
       8,    1,   71,    2, 0x06 /* Public */,
      10,    0,   74,    2, 0x06 /* Public */,
      11,    0,   75,    2, 0x06 /* Public */,
      12,    1,   76,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    3,   79,    2, 0x08 /* Private */,
      17,    1,   86,    2, 0x08 /* Private */,
      18,    0,   89,    2, 0x08 /* Private */,
      19,    0,   90,    2, 0x08 /* Private */,
      20,    1,   91,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::UInt, 0x80000000 | 6,    4,    5,    7,
    QMetaType::Void, QMetaType::UInt,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Bool,    4,    5,   16,
    QMetaType::Void, QMetaType::UInt,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,

       0        // eod
};

void Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Controller *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receivedMeasurementData((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< DataHeader(*)>(_a[3]))); break;
        case 1: _t->updateFps((*reinterpret_cast< const uint(*)>(_a[1]))); break;
        case 2: _t->connected(); break;
        case 3: _t->disconnected(); break;
        case 4: _t->error((*reinterpret_cast< const uint16_t(*)>(_a[1]))); break;
        case 5: _t->receivedData((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const bool(*)>(_a[3]))); break;
        case 6: _t->onFpsUpdate((*reinterpret_cast< const uint(*)>(_a[1]))); break;
        case 7: _t->cmdConnectionConnected(); break;
        case 8: _t->cmdConnectionDisconnected(); break;
        case 9: _t->onError((*reinterpret_cast< const uint16_t(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Controller::*)(const char * , uint , DataHeader & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::receivedMeasurementData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Controller::*)(const unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::updateFps)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Controller::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::connected)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Controller::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::disconnected)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Controller::*)(const uint16_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::error)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Controller::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Controller.data,
    qt_meta_data_Controller,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Controller.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Controller::receivedMeasurementData(const char * _t1, uint _t2, DataHeader & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Controller::updateFps(const unsigned int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Controller::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Controller::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Controller::error(const uint16_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
