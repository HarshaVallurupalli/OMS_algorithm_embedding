/****************************************************************************
** Meta object code from reading C++ file 'WidgetRoi.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../include/view/WidgetRoi.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WidgetRoi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WidgetSettingsROI_t {
    QByteArrayData data[13];
    char stringdata0[202];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WidgetSettingsROI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WidgetSettingsROI_t qt_meta_stringdata_WidgetSettingsROI = {
    {
QT_MOC_LITERAL(0, 0, 17), // "WidgetSettingsROI"
QT_MOC_LITERAL(1, 18, 26), // "on_sbTopLeftX_valueChanged"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 30), // "on_sbBottomRightX_valueChanged"
QT_MOC_LITERAL(4, 77, 26), // "on_sbTopLeftY_valueChanged"
QT_MOC_LITERAL(5, 104, 30), // "on_sbBottomRightY_valueChanged"
QT_MOC_LITERAL(6, 135, 23), // "on_tbDefaultROI_clicked"
QT_MOC_LITERAL(7, 159, 12), // "onRoiChanged"
QT_MOC_LITERAL(8, 172, 2), // "x1"
QT_MOC_LITERAL(9, 175, 2), // "y1"
QT_MOC_LITERAL(10, 178, 2), // "x2"
QT_MOC_LITERAL(11, 181, 2), // "y2"
QT_MOC_LITERAL(12, 184, 17) // "onSettingsChanged"

    },
    "WidgetSettingsROI\0on_sbTopLeftX_valueChanged\0"
    "\0on_sbBottomRightX_valueChanged\0"
    "on_sbTopLeftY_valueChanged\0"
    "on_sbBottomRightY_valueChanged\0"
    "on_tbDefaultROI_clicked\0onRoiChanged\0"
    "x1\0y1\0x2\0y2\0onSettingsChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WidgetSettingsROI[] = {

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
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    4,   54,    2, 0x08 /* Private */,
      12,    0,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    8,    9,   10,   11,
    QMetaType::Void,

       0        // eod
};

void WidgetSettingsROI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WidgetSettingsROI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_sbTopLeftX_valueChanged(); break;
        case 1: _t->on_sbBottomRightX_valueChanged(); break;
        case 2: _t->on_sbTopLeftY_valueChanged(); break;
        case 3: _t->on_sbBottomRightY_valueChanged(); break;
        case 4: _t->on_tbDefaultROI_clicked(); break;
        case 5: _t->onRoiChanged((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])),(*reinterpret_cast< const int(*)>(_a[4]))); break;
        case 6: _t->onSettingsChanged(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WidgetSettingsROI::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_WidgetSettingsROI.data,
    qt_meta_data_WidgetSettingsROI,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WidgetSettingsROI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidgetSettingsROI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WidgetSettingsROI.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WidgetSettingsROI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
