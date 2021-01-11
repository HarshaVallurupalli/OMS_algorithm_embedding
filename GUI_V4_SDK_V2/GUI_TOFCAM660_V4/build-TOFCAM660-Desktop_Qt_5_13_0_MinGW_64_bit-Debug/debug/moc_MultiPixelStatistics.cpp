/****************************************************************************
** Meta object code from reading C++ file 'MultiPixelStatistics.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../include/application/MultiPixelStatistics.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MultiPixelStatistics.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MultiPixelStatistics_t {
    QByteArrayData data[24];
    char stringdata0[331];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MultiPixelStatistics_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MultiPixelStatistics_t qt_meta_stringdata_MultiPixelStatistics = {
    {
QT_MOC_LITERAL(0, 0, 20), // "MultiPixelStatistics"
QT_MOC_LITERAL(1, 21, 16), // "newDistanceValue"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 8), // "distance"
QT_MOC_LITERAL(4, 48, 10), // "confidence"
QT_MOC_LITERAL(5, 59, 25), // "newDistanceAmplitudeValue"
QT_MOC_LITERAL(6, 85, 9), // "amplitude"
QT_MOC_LITERAL(7, 95, 17), // "newGrayscaleValue"
QT_MOC_LITERAL(8, 113, 9), // "grayscale"
QT_MOC_LITERAL(9, 123, 25), // "newDistanceGrayscaleValue"
QT_MOC_LITERAL(10, 149, 11), // "newDcsValue"
QT_MOC_LITERAL(11, 161, 4), // "dcs0"
QT_MOC_LITERAL(12, 166, 4), // "dcs1"
QT_MOC_LITERAL(13, 171, 4), // "dcs2"
QT_MOC_LITERAL(14, 176, 4), // "dcs3"
QT_MOC_LITERAL(15, 181, 19), // "onGrayscaleReceived"
QT_MOC_LITERAL(16, 201, 11), // "const char*"
QT_MOC_LITERAL(17, 213, 5), // "pData"
QT_MOC_LITERAL(18, 219, 11), // "DataHeader&"
QT_MOC_LITERAL(19, 231, 10), // "dataHeader"
QT_MOC_LITERAL(20, 242, 18), // "onDistanceReceived"
QT_MOC_LITERAL(21, 261, 27), // "onDistanceAmplitudeReceived"
QT_MOC_LITERAL(22, 289, 27), // "onDistanceGrayscaleReceived"
QT_MOC_LITERAL(23, 317, 13) // "onDcsReceived"

    },
    "MultiPixelStatistics\0newDistanceValue\0"
    "\0distance\0confidence\0newDistanceAmplitudeValue\0"
    "amplitude\0newGrayscaleValue\0grayscale\0"
    "newDistanceGrayscaleValue\0newDcsValue\0"
    "dcs0\0dcs1\0dcs2\0dcs3\0onGrayscaleReceived\0"
    "const char*\0pData\0DataHeader&\0dataHeader\0"
    "onDistanceReceived\0onDistanceAmplitudeReceived\0"
    "onDistanceGrayscaleReceived\0onDcsReceived"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MultiPixelStatistics[] = {

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
       1,    2,   64,    2, 0x06 /* Public */,
       5,    2,   69,    2, 0x06 /* Public */,
       7,    1,   74,    2, 0x06 /* Public */,
       9,    2,   77,    2, 0x06 /* Public */,
      10,    4,   82,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    2,   91,    2, 0x0a /* Public */,
      20,    2,   96,    2, 0x0a /* Public */,
      21,    2,  101,    2, 0x0a /* Public */,
      22,    2,  106,    2, 0x0a /* Public */,
      23,    2,  111,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    3,    4,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    3,    6,
    QMetaType::Void, QMetaType::UInt,    8,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    3,    8,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt,   11,   12,   13,   14,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 16, 0x80000000 | 18,   17,   19,
    QMetaType::Void, 0x80000000 | 16, 0x80000000 | 18,   17,   19,
    QMetaType::Void, 0x80000000 | 16, 0x80000000 | 18,   17,   19,
    QMetaType::Void, 0x80000000 | 16, 0x80000000 | 18,   17,   19,
    QMetaType::Void, 0x80000000 | 16, 0x80000000 | 18,   17,   19,

       0        // eod
};

void MultiPixelStatistics::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MultiPixelStatistics *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newDistanceValue((*reinterpret_cast< const uint(*)>(_a[1])),(*reinterpret_cast< const uint(*)>(_a[2]))); break;
        case 1: _t->newDistanceAmplitudeValue((*reinterpret_cast< const uint(*)>(_a[1])),(*reinterpret_cast< const uint(*)>(_a[2]))); break;
        case 2: _t->newGrayscaleValue((*reinterpret_cast< const uint(*)>(_a[1]))); break;
        case 3: _t->newDistanceGrayscaleValue((*reinterpret_cast< const uint(*)>(_a[1])),(*reinterpret_cast< const uint(*)>(_a[2]))); break;
        case 4: _t->newDcsValue((*reinterpret_cast< const uint(*)>(_a[1])),(*reinterpret_cast< const uint(*)>(_a[2])),(*reinterpret_cast< const uint(*)>(_a[3])),(*reinterpret_cast< const uint(*)>(_a[4]))); break;
        case 5: _t->onGrayscaleReceived((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< DataHeader(*)>(_a[2]))); break;
        case 6: _t->onDistanceReceived((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< DataHeader(*)>(_a[2]))); break;
        case 7: _t->onDistanceAmplitudeReceived((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< DataHeader(*)>(_a[2]))); break;
        case 8: _t->onDistanceGrayscaleReceived((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< DataHeader(*)>(_a[2]))); break;
        case 9: _t->onDcsReceived((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< DataHeader(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MultiPixelStatistics::*)(const unsigned int , const unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MultiPixelStatistics::newDistanceValue)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MultiPixelStatistics::*)(const unsigned int , const unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MultiPixelStatistics::newDistanceAmplitudeValue)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MultiPixelStatistics::*)(const unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MultiPixelStatistics::newGrayscaleValue)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MultiPixelStatistics::*)(const unsigned int , const unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MultiPixelStatistics::newDistanceGrayscaleValue)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MultiPixelStatistics::*)(const unsigned int , const unsigned int , const unsigned int , const unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MultiPixelStatistics::newDcsValue)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MultiPixelStatistics::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_MultiPixelStatistics.data,
    qt_meta_data_MultiPixelStatistics,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MultiPixelStatistics::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MultiPixelStatistics::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MultiPixelStatistics.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MultiPixelStatistics::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void MultiPixelStatistics::newDistanceValue(const unsigned int _t1, const unsigned int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MultiPixelStatistics::newDistanceAmplitudeValue(const unsigned int _t1, const unsigned int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MultiPixelStatistics::newGrayscaleValue(const unsigned int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MultiPixelStatistics::newDistanceGrayscaleValue(const unsigned int _t1, const unsigned int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MultiPixelStatistics::newDcsValue(const unsigned int _t1, const unsigned int _t2, const unsigned int _t3, const unsigned int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
