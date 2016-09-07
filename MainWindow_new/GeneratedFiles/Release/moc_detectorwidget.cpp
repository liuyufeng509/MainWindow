/****************************************************************************
** Meta object code from reading C++ file 'detectorwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../detectorwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'detectorwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DetectorWidget_t {
    QByteArrayData data[13];
    char stringdata[175];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DetectorWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DetectorWidget_t qt_meta_stringdata_DetectorWidget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "DetectorWidget"
QT_MOC_LITERAL(1, 15, 20), // "detectVehDataChanged"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 19), // "DetectorVehicleData"
QT_MOC_LITERAL(4, 57, 4), // "data"
QT_MOC_LITERAL(5, 62, 20), // "detectBusDataChanged"
QT_MOC_LITERAL(6, 83, 15), // "DetectorBusData"
QT_MOC_LITERAL(7, 99, 20), // "detectPedDataChanged"
QT_MOC_LITERAL(8, 120, 24), // "DetectorsPedestrainsData"
QT_MOC_LITERAL(9, 145, 12), // "foucsChanged"
QT_MOC_LITERAL(10, 158, 8), // "QWidget*"
QT_MOC_LITERAL(11, 167, 3), // "old"
QT_MOC_LITERAL(12, 171, 3) // "now"

    },
    "DetectorWidget\0detectVehDataChanged\0"
    "\0DetectorVehicleData\0data\0"
    "detectBusDataChanged\0DetectorBusData\0"
    "detectPedDataChanged\0DetectorsPedestrainsData\0"
    "foucsChanged\0QWidget*\0old\0now"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DetectorWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       5,    1,   37,    2, 0x06 /* Public */,
       7,    1,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    2,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    4,
    QMetaType::Void, 0x80000000 | 8,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 10,   11,   12,

       0        // eod
};

void DetectorWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DetectorWidget *_t = static_cast<DetectorWidget *>(_o);
        switch (_id) {
        case 0: _t->detectVehDataChanged((*reinterpret_cast< DetectorVehicleData(*)>(_a[1]))); break;
        case 1: _t->detectBusDataChanged((*reinterpret_cast< DetectorBusData(*)>(_a[1]))); break;
        case 2: _t->detectPedDataChanged((*reinterpret_cast< DetectorsPedestrainsData(*)>(_a[1]))); break;
        case 3: _t->foucsChanged((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DetectorWidget::*_t)(DetectorVehicleData );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DetectorWidget::detectVehDataChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (DetectorWidget::*_t)(DetectorBusData );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DetectorWidget::detectBusDataChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (DetectorWidget::*_t)(DetectorsPedestrainsData );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DetectorWidget::detectPedDataChanged)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject DetectorWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DetectorWidget.data,
      qt_meta_data_DetectorWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DetectorWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DetectorWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DetectorWidget.stringdata))
        return static_cast<void*>(const_cast< DetectorWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int DetectorWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void DetectorWidget::detectVehDataChanged(DetectorVehicleData _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DetectorWidget::detectBusDataChanged(DetectorBusData _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DetectorWidget::detectPedDataChanged(DetectorsPedestrainsData _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
