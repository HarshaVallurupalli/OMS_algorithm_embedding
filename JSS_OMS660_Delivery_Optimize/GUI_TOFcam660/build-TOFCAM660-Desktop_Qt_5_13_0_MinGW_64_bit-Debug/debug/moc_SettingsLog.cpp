/****************************************************************************
** Meta object code from reading C++ file 'SettingsLog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../include/data/SettingsLog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SettingsLog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SettingsLog_t {
    QByteArrayData data[19];
    char stringdata0[188];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SettingsLog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SettingsLog_t qt_meta_stringdata_SettingsLog = {
    {
QT_MOC_LITERAL(0, 0, 11), // "SettingsLog"
QT_MOC_LITERAL(1, 12, 17), // "streamModeChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 9), // "setRecord"
QT_MOC_LITERAL(4, 41, 5), // "state"
QT_MOC_LITERAL(5, 47, 8), // "isRecord"
QT_MOC_LITERAL(6, 56, 16), // "setDisplayRecord"
QT_MOC_LITERAL(7, 73, 15), // "isDispalyRecord"
QT_MOC_LITERAL(8, 89, 10), // "setLogPath"
QT_MOC_LITERAL(9, 100, 3), // "str"
QT_MOC_LITERAL(10, 104, 10), // "getLogPath"
QT_MOC_LITERAL(11, 115, 10), // "setLogName"
QT_MOC_LITERAL(12, 126, 10), // "getLogName"
QT_MOC_LITERAL(13, 137, 6), // "setFps"
QT_MOC_LITERAL(14, 144, 3), // "val"
QT_MOC_LITERAL(15, 148, 6), // "getFps"
QT_MOC_LITERAL(16, 155, 13), // "setStreamMode"
QT_MOC_LITERAL(17, 169, 4), // "mode"
QT_MOC_LITERAL(18, 174, 13) // "getStreamMode"

    },
    "SettingsLog\0streamModeChanged\0\0setRecord\0"
    "state\0isRecord\0setDisplayRecord\0"
    "isDispalyRecord\0setLogPath\0str\0"
    "getLogPath\0setLogName\0getLogName\0"
    "setFps\0val\0getFps\0setStreamMode\0mode\0"
    "getStreamMode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SettingsLog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   82,    2, 0x0a /* Public */,
       5,    0,   85,    2, 0x0a /* Public */,
       6,    1,   86,    2, 0x0a /* Public */,
       7,    0,   89,    2, 0x0a /* Public */,
       8,    1,   90,    2, 0x0a /* Public */,
      10,    0,   93,    2, 0x0a /* Public */,
      11,    1,   94,    2, 0x0a /* Public */,
      12,    0,   97,    2, 0x0a /* Public */,
      13,    1,   98,    2, 0x0a /* Public */,
      15,    0,  101,    2, 0x0a /* Public */,
      16,    1,  102,    2, 0x0a /* Public */,
      18,    0,  105,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::QString,
    QMetaType::Void, QMetaType::Double,   14,
    QMetaType::Double,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Int,

       0        // eod
};

void SettingsLog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SettingsLog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->streamModeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setRecord((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: { bool _r = _t->isRecord();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->setDisplayRecord((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: { bool _r = _t->isDispalyRecord();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->setLogPath((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: { QString _r = _t->getLogPath();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->setLogName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: { QString _r = _t->getLogName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->setFps((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: { double _r = _t->getFps();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->setStreamMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: { int _r = _t->getStreamMode();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SettingsLog::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingsLog::streamModeChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SettingsLog::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_SettingsLog.data,
    qt_meta_data_SettingsLog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SettingsLog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SettingsLog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SettingsLog.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SettingsLog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void SettingsLog::streamModeChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
