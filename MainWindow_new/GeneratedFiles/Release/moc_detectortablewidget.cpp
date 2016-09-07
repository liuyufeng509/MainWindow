/****************************************************************************
** Meta object code from reading C++ file 'detectortablewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../detectortablewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'detectortablewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VirDetectorTableWidget_t {
    QByteArrayData data[11];
    char stringdata[193];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VirDetectorTableWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VirDetectorTableWidget_t qt_meta_stringdata_VirDetectorTableWidget = {
    {
QT_MOC_LITERAL(0, 0, 22), // "VirDetectorTableWidget"
QT_MOC_LITERAL(1, 23, 20), // "VehCellDoubleClicked"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 20), // "DetectorVehicleData&"
QT_MOC_LITERAL(4, 66, 4), // "data"
QT_MOC_LITERAL(5, 71, 20), // "BusCellDoubleClicked"
QT_MOC_LITERAL(6, 92, 16), // "DetectorBusData&"
QT_MOC_LITERAL(7, 109, 20), // "PedCellDoubleClicked"
QT_MOC_LITERAL(8, 130, 25), // "DetectorsPedestrainsData&"
QT_MOC_LITERAL(9, 156, 14), // "updateDataToUI"
QT_MOC_LITERAL(10, 171, 21) // "dealCellDoubleClicked"

    },
    "VirDetectorTableWidget\0VehCellDoubleClicked\0"
    "\0DetectorVehicleData&\0data\0"
    "BusCellDoubleClicked\0DetectorBusData&\0"
    "PedCellDoubleClicked\0DetectorsPedestrainsData&\0"
    "updateDataToUI\0dealCellDoubleClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VirDetectorTableWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       5,    1,   42,    2, 0x06 /* Public */,
       7,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   48,    2, 0x0a /* Public */,
      10,    2,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    4,
    QMetaType::Void, 0x80000000 | 8,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

       0        // eod
};

void VirDetectorTableWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VirDetectorTableWidget *_t = static_cast<VirDetectorTableWidget *>(_o);
        switch (_id) {
        case 0: _t->VehCellDoubleClicked((*reinterpret_cast< DetectorVehicleData(*)>(_a[1]))); break;
        case 1: _t->BusCellDoubleClicked((*reinterpret_cast< DetectorBusData(*)>(_a[1]))); break;
        case 2: _t->PedCellDoubleClicked((*reinterpret_cast< DetectorsPedestrainsData(*)>(_a[1]))); break;
        case 3: _t->updateDataToUI(); break;
        case 4: _t->dealCellDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (VirDetectorTableWidget::*_t)(DetectorVehicleData & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VirDetectorTableWidget::VehCellDoubleClicked)) {
                *result = 0;
            }
        }
        {
            typedef void (VirDetectorTableWidget::*_t)(DetectorBusData & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VirDetectorTableWidget::BusCellDoubleClicked)) {
                *result = 1;
            }
        }
        {
            typedef void (VirDetectorTableWidget::*_t)(DetectorsPedestrainsData & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VirDetectorTableWidget::PedCellDoubleClicked)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject VirDetectorTableWidget::staticMetaObject = {
    { &QTableWidget::staticMetaObject, qt_meta_stringdata_VirDetectorTableWidget.data,
      qt_meta_data_VirDetectorTableWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *VirDetectorTableWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VirDetectorTableWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_VirDetectorTableWidget.stringdata))
        return static_cast<void*>(const_cast< VirDetectorTableWidget*>(this));
    return QTableWidget::qt_metacast(_clname);
}

int VirDetectorTableWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void VirDetectorTableWidget::VehCellDoubleClicked(DetectorVehicleData & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void VirDetectorTableWidget::BusCellDoubleClicked(DetectorBusData & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void VirDetectorTableWidget::PedCellDoubleClicked(DetectorsPedestrainsData & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
