/****************************************************************************
** Meta object code from reading C++ file 'Interface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../include/application/Interface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Interface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Interface_t {
    QByteArrayData data[30];
    char stringdata0[351];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Interface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Interface_t qt_meta_stringdata_Interface = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Interface"
QT_MOC_LITERAL(1, 10, 11), // "receivedAck"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 13), // "receivedError"
QT_MOC_LITERAL(4, 37, 9), // "errorCode"
QT_MOC_LITERAL(5, 47, 23), // "receivedMeasurementData"
QT_MOC_LITERAL(6, 71, 11), // "const char*"
QT_MOC_LITERAL(7, 83, 5), // "pData"
QT_MOC_LITERAL(8, 89, 6), // "length"
QT_MOC_LITERAL(9, 96, 8), // "complete"
QT_MOC_LITERAL(10, 105, 23), // "receivedFirmwareRelease"
QT_MOC_LITERAL(11, 129, 5), // "major"
QT_MOC_LITERAL(12, 135, 5), // "minor"
QT_MOC_LITERAL(13, 141, 16), // "receivedChipInfo"
QT_MOC_LITERAL(14, 158, 7), // "waferID"
QT_MOC_LITERAL(15, 166, 6), // "chipID"
QT_MOC_LITERAL(16, 173, 9), // "connected"
QT_MOC_LITERAL(17, 183, 12), // "disconnected"
QT_MOC_LITERAL(18, 196, 11), // "stopRunning"
QT_MOC_LITERAL(19, 208, 9), // "updateFps"
QT_MOC_LITERAL(20, 218, 3), // "fps"
QT_MOC_LITERAL(21, 222, 13), // "traceReceived"
QT_MOC_LITERAL(22, 236, 4), // "text"
QT_MOC_LITERAL(23, 241, 14), // "receivedAnswer"
QT_MOC_LITERAL(24, 256, 4), // "data"
QT_MOC_LITERAL(25, 261, 12), // "receivedData"
QT_MOC_LITERAL(26, 274, 22), // "cmdConnectionConnected"
QT_MOC_LITERAL(27, 297, 25), // "cmdConnectionDisconnected"
QT_MOC_LITERAL(28, 323, 11), // "onUpdateFps"
QT_MOC_LITERAL(29, 335, 15) // "onTraceReceived"

    },
    "Interface\0receivedAck\0\0receivedError\0"
    "errorCode\0receivedMeasurementData\0"
    "const char*\0pData\0length\0complete\0"
    "receivedFirmwareRelease\0major\0minor\0"
    "receivedChipInfo\0waferID\0chipID\0"
    "connected\0disconnected\0stopRunning\0"
    "updateFps\0fps\0traceReceived\0text\0"
    "receivedAnswer\0data\0receivedData\0"
    "cmdConnectionConnected\0cmdConnectionDisconnected\0"
    "onUpdateFps\0onTraceReceived"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Interface[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    1,   95,    2, 0x06 /* Public */,
       5,    3,   98,    2, 0x06 /* Public */,
      10,    2,  105,    2, 0x06 /* Public */,
      13,    2,  110,    2, 0x06 /* Public */,
      16,    0,  115,    2, 0x06 /* Public */,
      17,    0,  116,    2, 0x06 /* Public */,
      18,    0,  117,    2, 0x06 /* Public */,
      19,    1,  118,    2, 0x06 /* Public */,
      21,    1,  121,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      23,    1,  124,    2, 0x08 /* Private */,
      25,    3,  127,    2, 0x08 /* Private */,
      26,    0,  134,    2, 0x08 /* Private */,
      27,    0,  135,    2, 0x08 /* Private */,
      28,    0,  136,    2, 0x08 /* Private */,
      29,    1,  137,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Int, QMetaType::Bool,    7,    8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt,   20,
    QMetaType::Void, QMetaType::QString,   22,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,   24,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Int, QMetaType::Bool,    7,    8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   22,

       0        // eod
};

void Interface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Interface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receivedAck(); break;
        case 1: _t->receivedError((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 2: _t->receivedMeasurementData((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 3: _t->receivedFirmwareRelease((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 4: _t->receivedChipInfo((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 5: _t->connected(); break;
        case 6: _t->disconnected(); break;
        case 7: _t->stopRunning(); break;
        case 8: _t->updateFps((*reinterpret_cast< const uint(*)>(_a[1]))); break;
        case 9: _t->traceReceived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->receivedAnswer((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 11: _t->receivedData((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 12: _t->cmdConnectionConnected(); break;
        case 13: _t->cmdConnectionDisconnected(); break;
        case 14: _t->onUpdateFps(); break;
        case 15: _t->onTraceReceived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Interface::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Interface::receivedAck)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Interface::*)(const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Interface::receivedError)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Interface::*)(const char * , const int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Interface::receivedMeasurementData)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Interface::*)(const int , const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Interface::receivedFirmwareRelease)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Interface::*)(const int , const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Interface::receivedChipInfo)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Interface::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Interface::connected)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Interface::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Interface::disconnected)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Interface::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Interface::stopRunning)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Interface::*)(const unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Interface::updateFps)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Interface::*)(const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Interface::traceReceived)) {
                *result = 9;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Interface::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Interface.data,
    qt_meta_data_Interface,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Interface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Interface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Interface.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Interface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void Interface::receivedAck()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Interface::receivedError(const int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Interface::receivedMeasurementData(const char * _t1, const int _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Interface::receivedFirmwareRelease(const int _t1, const int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Interface::receivedChipInfo(const int _t1, const int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Interface::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Interface::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Interface::stopRunning()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void Interface::updateFps(const unsigned int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Interface::traceReceived(const QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
