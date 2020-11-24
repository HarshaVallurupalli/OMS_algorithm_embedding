/****************************************************************************
** Meta object code from reading C++ file 'WidgetPointCloudView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../include/view/WidgetPointCloudView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WidgetPointCloudView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WidgetPointCloudView_t {
    QByteArrayData data[19];
    char stringdata0[405];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WidgetPointCloudView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WidgetPointCloudView_t qt_meta_stringdata_WidgetPointCloudView = {
    {
QT_MOC_LITERAL(0, 0, 20), // "WidgetPointCloudView"
QT_MOC_LITERAL(1, 21, 21), // "grayPointCloudChanged"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 19), // "autoRotatingToggled"
QT_MOC_LITERAL(4, 64, 18), // "on_tbClose_clicked"
QT_MOC_LITERAL(5, 83, 19), // "on_cbAxis2D_toggled"
QT_MOC_LITERAL(6, 103, 7), // "checked"
QT_MOC_LITERAL(7, 111, 19), // "on_cbAxis3D_toggled"
QT_MOC_LITERAL(8, 131, 17), // "on_cbGrid_toggled"
QT_MOC_LITERAL(9, 149, 25), // "on_cbUndistortion_toggled"
QT_MOC_LITERAL(10, 175, 22), // "on_cbCartesian_toggled"
QT_MOC_LITERAL(11, 198, 28), // "on_cbPerspectiveView_toggled"
QT_MOC_LITERAL(12, 227, 27), // "on_cbGrayPointCloud_toggled"
QT_MOC_LITERAL(13, 255, 37), // "on_sbSurfaceInterconnect_valu..."
QT_MOC_LITERAL(14, 293, 4), // "arg1"
QT_MOC_LITERAL(15, 298, 27), // "on_dbPointSize_valueChanged"
QT_MOC_LITERAL(16, 326, 19), // "on_cbPoints_toggled"
QT_MOC_LITERAL(17, 346, 32), // "on_cbSurfaceInterconnect_toggled"
QT_MOC_LITERAL(18, 379, 25) // "on_cbAutoRotating_toggled"

    },
    "WidgetPointCloudView\0grayPointCloudChanged\0"
    "\0autoRotatingToggled\0on_tbClose_clicked\0"
    "on_cbAxis2D_toggled\0checked\0"
    "on_cbAxis3D_toggled\0on_cbGrid_toggled\0"
    "on_cbUndistortion_toggled\0"
    "on_cbCartesian_toggled\0"
    "on_cbPerspectiveView_toggled\0"
    "on_cbGrayPointCloud_toggled\0"
    "on_sbSurfaceInterconnect_valueChanged\0"
    "arg1\0on_dbPointSize_valueChanged\0"
    "on_cbPoints_toggled\0"
    "on_cbSurfaceInterconnect_toggled\0"
    "on_cbAutoRotating_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WidgetPointCloudView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       3,    1,   92,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   95,    2, 0x08 /* Private */,
       5,    1,   96,    2, 0x08 /* Private */,
       7,    1,   99,    2, 0x08 /* Private */,
       8,    1,  102,    2, 0x08 /* Private */,
       9,    1,  105,    2, 0x08 /* Private */,
      10,    1,  108,    2, 0x08 /* Private */,
      11,    1,  111,    2, 0x08 /* Private */,
      12,    1,  114,    2, 0x08 /* Private */,
      13,    1,  117,    2, 0x08 /* Private */,
      15,    1,  120,    2, 0x08 /* Private */,
      16,    1,  123,    2, 0x08 /* Private */,
      17,    1,  126,    2, 0x08 /* Private */,
      18,    1,  129,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Double,   14,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    6,

       0        // eod
};

void WidgetPointCloudView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WidgetPointCloudView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->grayPointCloudChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->autoRotatingToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_tbClose_clicked(); break;
        case 3: _t->on_cbAxis2D_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_cbAxis3D_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_cbGrid_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_cbUndistortion_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_cbCartesian_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_cbPerspectiveView_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_cbGrayPointCloud_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_sbSurfaceInterconnect_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_dbPointSize_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->on_cbPoints_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->on_cbSurfaceInterconnect_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->on_cbAutoRotating_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WidgetPointCloudView::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetPointCloudView::grayPointCloudChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WidgetPointCloudView::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetPointCloudView::autoRotatingToggled)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WidgetPointCloudView::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_WidgetPointCloudView.data,
    qt_meta_data_WidgetPointCloudView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WidgetPointCloudView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidgetPointCloudView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WidgetPointCloudView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WidgetPointCloudView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void WidgetPointCloudView::grayPointCloudChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void WidgetPointCloudView::autoRotatingToggled(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
