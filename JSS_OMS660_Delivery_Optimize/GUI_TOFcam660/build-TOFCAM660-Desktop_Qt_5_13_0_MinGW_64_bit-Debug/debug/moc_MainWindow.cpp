/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../include/view/MainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[32];
    char stringdata0[476];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 8), // "showData"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 11), // "const char*"
QT_MOC_LITERAL(4, 33, 5), // "pData"
QT_MOC_LITERAL(5, 39, 11), // "DataHeader&"
QT_MOC_LITERAL(6, 51, 10), // "dataHeader"
QT_MOC_LITERAL(7, 62, 18), // "getFirmwareVersion"
QT_MOC_LITERAL(8, 81, 15), // "restoreSettings"
QT_MOC_LITERAL(9, 97, 23), // "receivedMeasurementData"
QT_MOC_LITERAL(10, 121, 6), // "length"
QT_MOC_LITERAL(11, 128, 7), // "onError"
QT_MOC_LITERAL(12, 136, 8), // "uint16_t"
QT_MOC_LITERAL(13, 145, 11), // "errorNumber"
QT_MOC_LITERAL(14, 157, 9), // "updateFps"
QT_MOC_LITERAL(15, 167, 3), // "fps"
QT_MOC_LITERAL(16, 171, 13), // "onStateChange"
QT_MOC_LITERAL(17, 185, 22), // "onDeveloperModeEnabled"
QT_MOC_LITERAL(18, 208, 23), // "onPushButtonLogoClicked"
QT_MOC_LITERAL(19, 232, 23), // "on_actionView_triggered"
QT_MOC_LITERAL(20, 256, 30), // "on_actionCalibration_triggered"
QT_MOC_LITERAL(21, 287, 24), // "on_actionTools_triggered"
QT_MOC_LITERAL(22, 312, 23), // "on_actionPlay_triggered"
QT_MOC_LITERAL(23, 336, 27), // "on_actionSettings_triggered"
QT_MOC_LITERAL(24, 364, 28), // "on_actionSave_Load_triggered"
QT_MOC_LITERAL(25, 393, 23), // "receivedFirmwareRelease"
QT_MOC_LITERAL(26, 417, 5), // "major"
QT_MOC_LITERAL(27, 423, 5), // "minor"
QT_MOC_LITERAL(28, 429, 16), // "receivedChipInfo"
QT_MOC_LITERAL(29, 446, 7), // "waferID"
QT_MOC_LITERAL(30, 454, 6), // "ChipID"
QT_MOC_LITERAL(31, 461, 14) // "showSystemInfo"

    },
    "MainWindow\0showData\0\0const char*\0pData\0"
    "DataHeader&\0dataHeader\0getFirmwareVersion\0"
    "restoreSettings\0receivedMeasurementData\0"
    "length\0onError\0uint16_t\0errorNumber\0"
    "updateFps\0fps\0onStateChange\0"
    "onDeveloperModeEnabled\0onPushButtonLogoClicked\0"
    "on_actionView_triggered\0"
    "on_actionCalibration_triggered\0"
    "on_actionTools_triggered\0"
    "on_actionPlay_triggered\0"
    "on_actionSettings_triggered\0"
    "on_actionSave_Load_triggered\0"
    "receivedFirmwareRelease\0major\0minor\0"
    "receivedChipInfo\0waferID\0ChipID\0"
    "showSystemInfo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  104,    2, 0x06 /* Public */,
       7,    0,  109,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,  110,    2, 0x08 /* Private */,
       9,    3,  111,    2, 0x08 /* Private */,
      11,    1,  118,    2, 0x08 /* Private */,
      14,    1,  121,    2, 0x08 /* Private */,
      16,    0,  124,    2, 0x08 /* Private */,
      17,    0,  125,    2, 0x08 /* Private */,
      18,    0,  126,    2, 0x08 /* Private */,
      19,    0,  127,    2, 0x08 /* Private */,
      20,    0,  128,    2, 0x08 /* Private */,
      21,    0,  129,    2, 0x08 /* Private */,
      22,    0,  130,    2, 0x08 /* Private */,
      23,    0,  131,    2, 0x08 /* Private */,
      24,    0,  132,    2, 0x08 /* Private */,
      25,    2,  133,    2, 0x08 /* Private */,
      28,    2,  138,    2, 0x08 /* Private */,
      31,    0,  143,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3, QMetaType::UInt, 0x80000000 | 5,    4,   10,    6,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::UInt,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   26,   27,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   29,   30,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showData((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< DataHeader(*)>(_a[2]))); break;
        case 1: _t->getFirmwareVersion(); break;
        case 2: _t->restoreSettings(); break;
        case 3: _t->receivedMeasurementData((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< DataHeader(*)>(_a[3]))); break;
        case 4: _t->onError((*reinterpret_cast< const uint16_t(*)>(_a[1]))); break;
        case 5: _t->updateFps((*reinterpret_cast< const uint(*)>(_a[1]))); break;
        case 6: _t->onStateChange(); break;
        case 7: _t->onDeveloperModeEnabled(); break;
        case 8: _t->onPushButtonLogoClicked(); break;
        case 9: _t->on_actionView_triggered(); break;
        case 10: _t->on_actionCalibration_triggered(); break;
        case 11: _t->on_actionTools_triggered(); break;
        case 12: _t->on_actionPlay_triggered(); break;
        case 13: _t->on_actionSettings_triggered(); break;
        case 14: _t->on_actionSave_Load_triggered(); break;
        case 15: _t->receivedFirmwareRelease((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 16: _t->receivedChipInfo((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 17: _t->showSystemInfo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(const char * , DataHeader & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::showData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::getFirmwareVersion)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::showData(const char * _t1, DataHeader & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::getFirmwareVersion()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
