/****************************************************************************
** Meta object code from reading C++ file 'Settings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../include/data/Settings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Settings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Settings_t {
    QByteArrayData data[95];
    char stringdata0[1237];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Settings_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Settings_t qt_meta_stringdata_Settings = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Settings"
QT_MOC_LITERAL(1, 9, 14), // "settingsLoaded"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 15), // "settingsChanged"
QT_MOC_LITERAL(4, 41, 19), // "minAmplitudeChanged"
QT_MOC_LITERAL(5, 61, 13), // "offsetChanged"
QT_MOC_LITERAL(6, 75, 22), // "integrationTimeChanged"
QT_MOC_LITERAL(7, 98, 17), // "modulationChanged"
QT_MOC_LITERAL(8, 116, 13), // "mirrorChanged"
QT_MOC_LITERAL(9, 130, 13), // "formatChanged"
QT_MOC_LITERAL(10, 144, 12), // "startClicked"
QT_MOC_LITERAL(11, 157, 15), // "showInfoChanged"
QT_MOC_LITERAL(12, 173, 7), // "checked"
QT_MOC_LITERAL(13, 181, 20), // "showTimeScopeChanged"
QT_MOC_LITERAL(14, 202, 21), // "showPixelScopeChanged"
QT_MOC_LITERAL(15, 224, 22), // "measurementTypeChanged"
QT_MOC_LITERAL(16, 247, 10), // "roiChanged"
QT_MOC_LITERAL(17, 258, 2), // "x1"
QT_MOC_LITERAL(18, 261, 2), // "y1"
QT_MOC_LITERAL(19, 264, 2), // "x2"
QT_MOC_LITERAL(20, 267, 2), // "y2"
QT_MOC_LITERAL(21, 270, 17), // "systemInfoChanged"
QT_MOC_LITERAL(22, 288, 14), // "setMainWinPosX"
QT_MOC_LITERAL(23, 303, 5), // "value"
QT_MOC_LITERAL(24, 309, 14), // "setMainWinPosY"
QT_MOC_LITERAL(25, 324, 15), // "setMainWinWidth"
QT_MOC_LITERAL(26, 340, 16), // "setMainWinHeight"
QT_MOC_LITERAL(27, 357, 14), // "setMainWinRect"
QT_MOC_LITERAL(28, 372, 4), // "rect"
QT_MOC_LITERAL(29, 377, 14), // "setWinDataPosX"
QT_MOC_LITERAL(30, 392, 14), // "setWinDataPosY"
QT_MOC_LITERAL(31, 407, 15), // "setWinDataWidth"
QT_MOC_LITERAL(32, 423, 16), // "setWinDataHeight"
QT_MOC_LITERAL(33, 440, 14), // "setWinDataRect"
QT_MOC_LITERAL(34, 455, 16), // "setPixelInfoRect"
QT_MOC_LITERAL(35, 472, 17), // "setPixelScopeRect"
QT_MOC_LITERAL(36, 490, 16), // "setTimeScopeRect"
QT_MOC_LITERAL(37, 507, 15), // "setVerticalFlip"
QT_MOC_LITERAL(38, 523, 5), // "state"
QT_MOC_LITERAL(39, 529, 17), // "setHorizontalFlip"
QT_MOC_LITERAL(40, 547, 9), // "setRotate"
QT_MOC_LITERAL(41, 557, 6), // "rotate"
QT_MOC_LITERAL(42, 564, 21), // "setAmplitudeGrayscale"
QT_MOC_LITERAL(43, 586, 20), // "isAmplitudeGrayscale"
QT_MOC_LITERAL(44, 607, 11), // "setShowInfo"
QT_MOC_LITERAL(45, 619, 8), // "showInfo"
QT_MOC_LITERAL(46, 628, 16), // "setShowTimeScope"
QT_MOC_LITERAL(47, 645, 13), // "showTimeScope"
QT_MOC_LITERAL(48, 659, 17), // "setShowPixelScope"
QT_MOC_LITERAL(49, 677, 14), // "showPixelScope"
QT_MOC_LITERAL(50, 692, 6), // "setRoi"
QT_MOC_LITERAL(51, 699, 13), // "setRoiDefault"
QT_MOC_LITERAL(52, 713, 15), // "setMinAmplitude"
QT_MOC_LITERAL(53, 729, 9), // "amplitude"
QT_MOC_LITERAL(54, 739, 19), // "setIntegrationTime0"
QT_MOC_LITERAL(55, 759, 15), // "integrationTime"
QT_MOC_LITERAL(56, 775, 19), // "setIntegrationTime1"
QT_MOC_LITERAL(57, 795, 19), // "setIntegrationTime2"
QT_MOC_LITERAL(58, 815, 22), // "setMaxIntegrationTime0"
QT_MOC_LITERAL(59, 838, 22), // "setMaxIntegrationTime1"
QT_MOC_LITERAL(60, 861, 27), // "setIntegrationTimeGrayscale"
QT_MOC_LITERAL(61, 889, 18), // "setMeasurementType"
QT_MOC_LITERAL(62, 908, 15), // "measurementType"
QT_MOC_LITERAL(63, 924, 11), // "setRangeMin"
QT_MOC_LITERAL(64, 936, 8), // "rangeMin"
QT_MOC_LITERAL(65, 945, 11), // "setRangeMax"
QT_MOC_LITERAL(66, 957, 8), // "rangeMax"
QT_MOC_LITERAL(67, 966, 9), // "setOffset"
QT_MOC_LITERAL(68, 976, 6), // "offset"
QT_MOC_LITERAL(69, 983, 11), // "setUserData"
QT_MOC_LITERAL(70, 995, 8), // "userData"
QT_MOC_LITERAL(71, 1004, 9), // "setDestIp"
QT_MOC_LITERAL(72, 1014, 6), // "destIp"
QT_MOC_LITERAL(73, 1021, 13), // "setComputerIp"
QT_MOC_LITERAL(74, 1035, 5), // "srcIP"
QT_MOC_LITERAL(75, 1041, 11), // "setViewType"
QT_MOC_LITERAL(76, 1053, 3), // "val"
QT_MOC_LITERAL(77, 1057, 11), // "getViewType"
QT_MOC_LITERAL(78, 1069, 13), // "setModulation"
QT_MOC_LITERAL(79, 1083, 7), // "uint8_t"
QT_MOC_LITERAL(80, 1091, 3), // "mod"
QT_MOC_LITERAL(81, 1095, 13), // "getModulation"
QT_MOC_LITERAL(82, 1109, 10), // "setChannel"
QT_MOC_LITERAL(83, 1120, 10), // "getChannel"
QT_MOC_LITERAL(84, 1131, 18), // "setFirmwareRelease"
QT_MOC_LITERAL(85, 1150, 8), // "uint16_t"
QT_MOC_LITERAL(86, 1159, 5), // "major"
QT_MOC_LITERAL(87, 1165, 5), // "minor"
QT_MOC_LITERAL(88, 1171, 11), // "setChipInfo"
QT_MOC_LITERAL(89, 1183, 7), // "waferID"
QT_MOC_LITERAL(90, 1191, 6), // "chipID"
QT_MOC_LITERAL(91, 1198, 8), // "getMajor"
QT_MOC_LITERAL(92, 1207, 8), // "getMinor"
QT_MOC_LITERAL(93, 1216, 10), // "getWaferID"
QT_MOC_LITERAL(94, 1227, 9) // "getChipID"

    },
    "Settings\0settingsLoaded\0\0settingsChanged\0"
    "minAmplitudeChanged\0offsetChanged\0"
    "integrationTimeChanged\0modulationChanged\0"
    "mirrorChanged\0formatChanged\0startClicked\0"
    "showInfoChanged\0checked\0showTimeScopeChanged\0"
    "showPixelScopeChanged\0measurementTypeChanged\0"
    "roiChanged\0x1\0y1\0x2\0y2\0systemInfoChanged\0"
    "setMainWinPosX\0value\0setMainWinPosY\0"
    "setMainWinWidth\0setMainWinHeight\0"
    "setMainWinRect\0rect\0setWinDataPosX\0"
    "setWinDataPosY\0setWinDataWidth\0"
    "setWinDataHeight\0setWinDataRect\0"
    "setPixelInfoRect\0setPixelScopeRect\0"
    "setTimeScopeRect\0setVerticalFlip\0state\0"
    "setHorizontalFlip\0setRotate\0rotate\0"
    "setAmplitudeGrayscale\0isAmplitudeGrayscale\0"
    "setShowInfo\0showInfo\0setShowTimeScope\0"
    "showTimeScope\0setShowPixelScope\0"
    "showPixelScope\0setRoi\0setRoiDefault\0"
    "setMinAmplitude\0amplitude\0setIntegrationTime0\0"
    "integrationTime\0setIntegrationTime1\0"
    "setIntegrationTime2\0setMaxIntegrationTime0\0"
    "setMaxIntegrationTime1\0"
    "setIntegrationTimeGrayscale\0"
    "setMeasurementType\0measurementType\0"
    "setRangeMin\0rangeMin\0setRangeMax\0"
    "rangeMax\0setOffset\0offset\0setUserData\0"
    "userData\0setDestIp\0destIp\0setComputerIp\0"
    "srcIP\0setViewType\0val\0getViewType\0"
    "setModulation\0uint8_t\0mod\0getModulation\0"
    "setChannel\0getChannel\0setFirmwareRelease\0"
    "uint16_t\0major\0minor\0setChipInfo\0"
    "waferID\0chipID\0getMajor\0getMinor\0"
    "getWaferID\0getChipID"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Settings[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      64,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      15,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  334,    2, 0x06 /* Public */,
       3,    0,  335,    2, 0x06 /* Public */,
       4,    0,  336,    2, 0x06 /* Public */,
       5,    0,  337,    2, 0x06 /* Public */,
       6,    0,  338,    2, 0x06 /* Public */,
       7,    0,  339,    2, 0x06 /* Public */,
       8,    0,  340,    2, 0x06 /* Public */,
       9,    0,  341,    2, 0x06 /* Public */,
      10,    0,  342,    2, 0x06 /* Public */,
      11,    1,  343,    2, 0x06 /* Public */,
      13,    1,  346,    2, 0x06 /* Public */,
      14,    1,  349,    2, 0x06 /* Public */,
      15,    1,  352,    2, 0x06 /* Public */,
      16,    4,  355,    2, 0x06 /* Public */,
      21,    0,  364,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      22,    1,  365,    2, 0x0a /* Public */,
      24,    1,  368,    2, 0x0a /* Public */,
      25,    1,  371,    2, 0x0a /* Public */,
      26,    1,  374,    2, 0x0a /* Public */,
      27,    1,  377,    2, 0x0a /* Public */,
      29,    1,  380,    2, 0x0a /* Public */,
      30,    1,  383,    2, 0x0a /* Public */,
      31,    1,  386,    2, 0x0a /* Public */,
      32,    1,  389,    2, 0x0a /* Public */,
      33,    1,  392,    2, 0x0a /* Public */,
      34,    1,  395,    2, 0x0a /* Public */,
      35,    1,  398,    2, 0x0a /* Public */,
      36,    1,  401,    2, 0x0a /* Public */,
      37,    1,  404,    2, 0x0a /* Public */,
      39,    1,  407,    2, 0x0a /* Public */,
      40,    1,  410,    2, 0x0a /* Public */,
      42,    1,  413,    2, 0x0a /* Public */,
      43,    0,  416,    2, 0x0a /* Public */,
      44,    1,  417,    2, 0x0a /* Public */,
      46,    1,  420,    2, 0x0a /* Public */,
      48,    1,  423,    2, 0x0a /* Public */,
      50,    4,  426,    2, 0x0a /* Public */,
      51,    0,  435,    2, 0x0a /* Public */,
      52,    1,  436,    2, 0x0a /* Public */,
      54,    1,  439,    2, 0x0a /* Public */,
      56,    1,  442,    2, 0x0a /* Public */,
      57,    1,  445,    2, 0x0a /* Public */,
      58,    1,  448,    2, 0x0a /* Public */,
      59,    1,  451,    2, 0x0a /* Public */,
      60,    1,  454,    2, 0x0a /* Public */,
      61,    1,  457,    2, 0x0a /* Public */,
      63,    1,  460,    2, 0x0a /* Public */,
      65,    1,  463,    2, 0x0a /* Public */,
      67,    1,  466,    2, 0x0a /* Public */,
      69,    1,  469,    2, 0x0a /* Public */,
      71,    1,  472,    2, 0x0a /* Public */,
      73,    1,  475,    2, 0x0a /* Public */,
      75,    1,  478,    2, 0x0a /* Public */,
      77,    0,  481,    2, 0x0a /* Public */,
      78,    1,  482,    2, 0x0a /* Public */,
      81,    0,  485,    2, 0x0a /* Public */,
      82,    1,  486,    2, 0x0a /* Public */,
      83,    0,  489,    2, 0x0a /* Public */,
      84,    2,  490,    2, 0x0a /* Public */,
      88,    2,  495,    2, 0x0a /* Public */,
      91,    0,  500,    2, 0x0a /* Public */,
      92,    0,  501,    2, 0x0a /* Public */,
      93,    0,  502,    2, 0x0a /* Public */,
      94,    0,  503,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   17,   18,   19,   20,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::QRect,   28,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::QRect,   28,
    QMetaType::Void, QMetaType::QRect,   28,
    QMetaType::Void, QMetaType::QRect,   28,
    QMetaType::Void, QMetaType::QRect,   28,
    QMetaType::Void, QMetaType::Bool,   38,
    QMetaType::Void, QMetaType::Bool,   38,
    QMetaType::Void, QMetaType::Bool,   41,
    QMetaType::Void, QMetaType::Bool,   38,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,   45,
    QMetaType::Void, QMetaType::Bool,   47,
    QMetaType::Void, QMetaType::Bool,   49,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   17,   18,   19,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt,   53,
    QMetaType::Void, QMetaType::UInt,   55,
    QMetaType::Void, QMetaType::UInt,   55,
    QMetaType::Void, QMetaType::UInt,   55,
    QMetaType::Void, QMetaType::UInt,   55,
    QMetaType::Void, QMetaType::UInt,   55,
    QMetaType::Void, QMetaType::UInt,   55,
    QMetaType::Void, QMetaType::Int,   62,
    QMetaType::Void, QMetaType::UInt,   64,
    QMetaType::Void, QMetaType::UInt,   66,
    QMetaType::Void, QMetaType::Int,   68,
    QMetaType::Void, QMetaType::QByteArray,   70,
    QMetaType::Void, QMetaType::QString,   72,
    QMetaType::Void, QMetaType::QString,   74,
    QMetaType::Void, QMetaType::UInt,   76,
    QMetaType::UInt,
    QMetaType::Void, 0x80000000 | 79,   80,
    0x80000000 | 79,
    QMetaType::Void, 0x80000000 | 79,   23,
    0x80000000 | 79,
    QMetaType::Void, 0x80000000 | 85, 0x80000000 | 85,   86,   87,
    QMetaType::Void, 0x80000000 | 85, 0x80000000 | 85,   89,   90,
    0x80000000 | 85,
    0x80000000 | 85,
    0x80000000 | 85,
    0x80000000 | 85,

       0        // eod
};

void Settings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Settings *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->settingsLoaded(); break;
        case 1: _t->settingsChanged(); break;
        case 2: _t->minAmplitudeChanged(); break;
        case 3: _t->offsetChanged(); break;
        case 4: _t->integrationTimeChanged(); break;
        case 5: _t->modulationChanged(); break;
        case 6: _t->mirrorChanged(); break;
        case 7: _t->formatChanged(); break;
        case 8: _t->startClicked(); break;
        case 9: _t->showInfoChanged((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 10: _t->showTimeScopeChanged((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 11: _t->showPixelScopeChanged((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 12: _t->measurementTypeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->roiChanged((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])),(*reinterpret_cast< const int(*)>(_a[4]))); break;
        case 14: _t->systemInfoChanged(); break;
        case 15: _t->setMainWinPosX((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 16: _t->setMainWinPosY((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 17: _t->setMainWinWidth((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 18: _t->setMainWinHeight((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 19: _t->setMainWinRect((*reinterpret_cast< const QRect(*)>(_a[1]))); break;
        case 20: _t->setWinDataPosX((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 21: _t->setWinDataPosY((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 22: _t->setWinDataWidth((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 23: _t->setWinDataHeight((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 24: _t->setWinDataRect((*reinterpret_cast< const QRect(*)>(_a[1]))); break;
        case 25: _t->setPixelInfoRect((*reinterpret_cast< const QRect(*)>(_a[1]))); break;
        case 26: _t->setPixelScopeRect((*reinterpret_cast< const QRect(*)>(_a[1]))); break;
        case 27: _t->setTimeScopeRect((*reinterpret_cast< const QRect(*)>(_a[1]))); break;
        case 28: _t->setVerticalFlip((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 29: _t->setHorizontalFlip((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 30: _t->setRotate((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 31: _t->setAmplitudeGrayscale((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 32: { bool _r = _t->isAmplitudeGrayscale();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 33: _t->setShowInfo((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 34: _t->setShowTimeScope((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 35: _t->setShowPixelScope((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 36: _t->setRoi((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3])),(*reinterpret_cast< const int(*)>(_a[4]))); break;
        case 37: _t->setRoiDefault(); break;
        case 38: _t->setMinAmplitude((*reinterpret_cast< const uint(*)>(_a[1]))); break;
        case 39: _t->setIntegrationTime0((*reinterpret_cast< const uint(*)>(_a[1]))); break;
        case 40: _t->setIntegrationTime1((*reinterpret_cast< const uint(*)>(_a[1]))); break;
        case 41: _t->setIntegrationTime2((*reinterpret_cast< const uint(*)>(_a[1]))); break;
        case 42: _t->setMaxIntegrationTime0((*reinterpret_cast< const uint(*)>(_a[1]))); break;
        case 43: _t->setMaxIntegrationTime1((*reinterpret_cast< const uint(*)>(_a[1]))); break;
        case 44: _t->setIntegrationTimeGrayscale((*reinterpret_cast< const uint(*)>(_a[1]))); break;
        case 45: _t->setMeasurementType((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 46: _t->setRangeMin((*reinterpret_cast< const uint(*)>(_a[1]))); break;
        case 47: _t->setRangeMax((*reinterpret_cast< const uint(*)>(_a[1]))); break;
        case 48: _t->setOffset((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 49: _t->setUserData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 50: _t->setDestIp((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 51: _t->setComputerIp((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 52: _t->setViewType((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 53: { uint _r = _t->getViewType();
            if (_a[0]) *reinterpret_cast< uint*>(_a[0]) = std::move(_r); }  break;
        case 54: _t->setModulation((*reinterpret_cast< uint8_t(*)>(_a[1]))); break;
        case 55: { uint8_t _r = _t->getModulation();
            if (_a[0]) *reinterpret_cast< uint8_t*>(_a[0]) = std::move(_r); }  break;
        case 56: _t->setChannel((*reinterpret_cast< uint8_t(*)>(_a[1]))); break;
        case 57: { uint8_t _r = _t->getChannel();
            if (_a[0]) *reinterpret_cast< uint8_t*>(_a[0]) = std::move(_r); }  break;
        case 58: _t->setFirmwareRelease((*reinterpret_cast< const uint16_t(*)>(_a[1])),(*reinterpret_cast< const uint16_t(*)>(_a[2]))); break;
        case 59: _t->setChipInfo((*reinterpret_cast< const uint16_t(*)>(_a[1])),(*reinterpret_cast< const uint16_t(*)>(_a[2]))); break;
        case 60: { uint16_t _r = _t->getMajor();
            if (_a[0]) *reinterpret_cast< uint16_t*>(_a[0]) = std::move(_r); }  break;
        case 61: { uint16_t _r = _t->getMinor();
            if (_a[0]) *reinterpret_cast< uint16_t*>(_a[0]) = std::move(_r); }  break;
        case 62: { uint16_t _r = _t->getWaferID();
            if (_a[0]) *reinterpret_cast< uint16_t*>(_a[0]) = std::move(_r); }  break;
        case 63: { uint16_t _r = _t->getChipID();
            if (_a[0]) *reinterpret_cast< uint16_t*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Settings::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::settingsLoaded)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Settings::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::settingsChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Settings::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::minAmplitudeChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Settings::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::offsetChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Settings::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::integrationTimeChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Settings::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::modulationChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Settings::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::mirrorChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Settings::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::formatChanged)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Settings::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::startClicked)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Settings::*)(const bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::showInfoChanged)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (Settings::*)(const bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::showTimeScopeChanged)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (Settings::*)(const bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::showPixelScopeChanged)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (Settings::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::measurementTypeChanged)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (Settings::*)(const int , const int , const int , const int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::roiChanged)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (Settings::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings::systemInfoChanged)) {
                *result = 14;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Settings::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Settings.data,
    qt_meta_data_Settings,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Settings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Settings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Settings.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Settings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 64)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 64;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 64)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 64;
    }
    return _id;
}

// SIGNAL 0
void Settings::settingsLoaded()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Settings::settingsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Settings::minAmplitudeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Settings::offsetChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Settings::integrationTimeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Settings::modulationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Settings::mirrorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Settings::formatChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void Settings::startClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void Settings::showInfoChanged(const bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Settings::showTimeScopeChanged(const bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Settings::showPixelScopeChanged(const bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void Settings::measurementTypeChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void Settings::roiChanged(const int _t1, const int _t2, const int _t3, const int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void Settings::systemInfoChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
