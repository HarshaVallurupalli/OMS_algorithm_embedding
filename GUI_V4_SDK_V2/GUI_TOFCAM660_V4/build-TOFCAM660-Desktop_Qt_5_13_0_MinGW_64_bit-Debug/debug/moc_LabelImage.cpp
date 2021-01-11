/****************************************************************************
** Meta object code from reading C++ file 'LabelImage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../include/view/LabelImage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LabelImage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LabelImage_t {
    QByteArrayData data[24];
    char stringdata0[304];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LabelImage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LabelImage_t qt_meta_stringdata_LabelImage = {
    {
QT_MOC_LITERAL(0, 0, 10), // "LabelImage"
QT_MOC_LITERAL(1, 11, 12), // "mouseChanged"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 1), // "x"
QT_MOC_LITERAL(4, 27, 1), // "y"
QT_MOC_LITERAL(5, 29, 16), // "mouseDoubleClick"
QT_MOC_LITERAL(6, 46, 12), // "infoSelected"
QT_MOC_LITERAL(7, 59, 17), // "timescopeSelected"
QT_MOC_LITERAL(8, 77, 2), // "x1"
QT_MOC_LITERAL(9, 80, 2), // "x2"
QT_MOC_LITERAL(10, 83, 2), // "y1"
QT_MOC_LITERAL(11, 86, 2), // "y2"
QT_MOC_LITERAL(12, 89, 18), // "pixelscopeSelected"
QT_MOC_LITERAL(13, 108, 14), // "regionSelected"
QT_MOC_LITERAL(14, 123, 10), // "mouseHover"
QT_MOC_LITERAL(15, 134, 25), // "pixelInfoSelectionCleared"
QT_MOC_LITERAL(16, 160, 5), // "state"
QT_MOC_LITERAL(17, 166, 26), // "pixelScopeSelectionCleared"
QT_MOC_LITERAL(18, 193, 25), // "timeScopeSelectionCleared"
QT_MOC_LITERAL(19, 219, 15), // "mouseOutOfRange"
QT_MOC_LITERAL(20, 235, 14), // "clearPixelInfo"
QT_MOC_LITERAL(21, 250, 19), // "clearRubberBandRect"
QT_MOC_LITERAL(22, 270, 19), // "clearRubberBandLine"
QT_MOC_LITERAL(23, 290, 13) // "setRoiDefault"

    },
    "LabelImage\0mouseChanged\0\0x\0y\0"
    "mouseDoubleClick\0infoSelected\0"
    "timescopeSelected\0x1\0x2\0y1\0y2\0"
    "pixelscopeSelected\0regionSelected\0"
    "mouseHover\0pixelInfoSelectionCleared\0"
    "state\0pixelScopeSelectionCleared\0"
    "timeScopeSelectionCleared\0mouseOutOfRange\0"
    "clearPixelInfo\0clearRubberBandRect\0"
    "clearRubberBandLine\0setRoiDefault"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LabelImage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      15,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   89,    2, 0x06 /* Public */,
       5,    0,   94,    2, 0x06 /* Public */,
       6,    2,   95,    2, 0x06 /* Public */,
       7,    4,  100,    2, 0x06 /* Public */,
      12,    4,  109,    2, 0x06 /* Public */,
      13,    4,  118,    2, 0x06 /* Public */,
      14,    2,  127,    2, 0x06 /* Public */,
      15,    1,  132,    2, 0x06 /* Public */,
      17,    1,  135,    2, 0x06 /* Public */,
      18,    1,  138,    2, 0x06 /* Public */,
      19,    0,  141,    2, 0x06 /* Public */,
      20,    0,  142,    2, 0x06 /* Public */,
      21,    0,  143,    2, 0x06 /* Public */,
      22,    0,  144,    2, 0x06 /* Public */,
      23,    0,  145,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    8,    9,   10,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    8,    9,   10,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    8,    9,   10,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LabelImage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LabelImage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mouseChanged((*reinterpret_cast< const double(*)>(_a[1])),(*reinterpret_cast< const double(*)>(_a[2]))); break;
        case 1: _t->mouseDoubleClick(); break;
        case 2: _t->infoSelected((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->timescopeSelected((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 4: _t->pixelscopeSelected((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 5: _t->regionSelected((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 6: _t->mouseHover((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->pixelInfoSelectionCleared((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->pixelScopeSelectionCleared((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->timeScopeSelectionCleared((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->mouseOutOfRange(); break;
        case 11: _t->clearPixelInfo(); break;
        case 12: _t->clearRubberBandRect(); break;
        case 13: _t->clearRubberBandLine(); break;
        case 14: _t->setRoiDefault(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LabelImage::*)(const double , const double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LabelImage::mouseChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LabelImage::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LabelImage::mouseDoubleClick)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (LabelImage::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LabelImage::infoSelected)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (LabelImage::*)(int , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LabelImage::timescopeSelected)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (LabelImage::*)(int , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LabelImage::pixelscopeSelected)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (LabelImage::*)(int , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LabelImage::regionSelected)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (LabelImage::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LabelImage::mouseHover)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (LabelImage::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LabelImage::pixelInfoSelectionCleared)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (LabelImage::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LabelImage::pixelScopeSelectionCleared)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (LabelImage::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LabelImage::timeScopeSelectionCleared)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (LabelImage::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LabelImage::mouseOutOfRange)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (LabelImage::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LabelImage::clearPixelInfo)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (LabelImage::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LabelImage::clearRubberBandRect)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (LabelImage::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LabelImage::clearRubberBandLine)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (LabelImage::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LabelImage::setRoiDefault)) {
                *result = 14;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LabelImage::staticMetaObject = { {
    &QLabel::staticMetaObject,
    qt_meta_stringdata_LabelImage.data,
    qt_meta_data_LabelImage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LabelImage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LabelImage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LabelImage.stringdata0))
        return static_cast<void*>(this);
    return QLabel::qt_metacast(_clname);
}

int LabelImage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
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
void LabelImage::mouseChanged(const double _t1, const double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LabelImage::mouseDoubleClick()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void LabelImage::infoSelected(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void LabelImage::timescopeSelected(int _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void LabelImage::pixelscopeSelected(int _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void LabelImage::regionSelected(int _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void LabelImage::mouseHover(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void LabelImage::pixelInfoSelectionCleared(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void LabelImage::pixelScopeSelectionCleared(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void LabelImage::timeScopeSelectionCleared(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void LabelImage::mouseOutOfRange()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void LabelImage::clearPixelInfo()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void LabelImage::clearRubberBandRect()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void LabelImage::clearRubberBandLine()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void LabelImage::setRoiDefault()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
