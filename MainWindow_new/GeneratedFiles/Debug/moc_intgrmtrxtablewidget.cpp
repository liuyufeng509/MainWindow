/****************************************************************************
** Meta object code from reading C++ file 'intgrmtrxtablewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../intgrmtrxtablewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'intgrmtrxtablewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IntGrMtrxTableWidget_t {
    QByteArrayData data[12];
    char stringdata[164];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IntGrMtrxTableWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IntGrMtrxTableWidget_t qt_meta_stringdata_IntGrMtrxTableWidget = {
    {
QT_MOC_LITERAL(0, 0, 20), // "IntGrMtrxTableWidget"
QT_MOC_LITERAL(1, 21, 11), // "cellChanged"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 20), // "InterGreenMatrixData"
QT_MOC_LITERAL(4, 55, 4), // "data"
QT_MOC_LITERAL(5, 60, 17), // "CellDoubleClicked"
QT_MOC_LITERAL(6, 78, 21), // "InterGreenMatrixData&"
QT_MOC_LITERAL(7, 100, 14), // "updateDataToUI"
QT_MOC_LITERAL(8, 115, 15), // "dealCellChanged"
QT_MOC_LITERAL(9, 131, 3), // "row"
QT_MOC_LITERAL(10, 135, 6), // "column"
QT_MOC_LITERAL(11, 142, 21) // "dealCellDoubleClicked"

    },
    "IntGrMtrxTableWidget\0cellChanged\0\0"
    "InterGreenMatrixData\0data\0CellDoubleClicked\0"
    "InterGreenMatrixData&\0updateDataToUI\0"
    "dealCellChanged\0row\0column\0"
    "dealCellDoubleClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IntGrMtrxTableWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       5,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   45,    2, 0x0a /* Public */,
       8,    2,   46,    2, 0x0a /* Public */,
      11,    2,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,

       0        // eod
};

void IntGrMtrxTableWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IntGrMtrxTableWidget *_t = static_cast<IntGrMtrxTableWidget *>(_o);
        switch (_id) {
        case 0: _t->cellChanged((*reinterpret_cast< InterGreenMatrixData(*)>(_a[1]))); break;
        case 1: _t->CellDoubleClicked((*reinterpret_cast< InterGreenMatrixData(*)>(_a[1]))); break;
        case 2: _t->updateDataToUI(); break;
        case 3: _t->dealCellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->dealCellDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (IntGrMtrxTableWidget::*_t)(InterGreenMatrixData );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IntGrMtrxTableWidget::cellChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (IntGrMtrxTableWidget::*_t)(InterGreenMatrixData & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&IntGrMtrxTableWidget::CellDoubleClicked)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject IntGrMtrxTableWidget::staticMetaObject = {
    { &QTableWidget::staticMetaObject, qt_meta_stringdata_IntGrMtrxTableWidget.data,
      qt_meta_data_IntGrMtrxTableWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IntGrMtrxTableWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IntGrMtrxTableWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IntGrMtrxTableWidget.stringdata))
        return static_cast<void*>(const_cast< IntGrMtrxTableWidget*>(this));
    return QTableWidget::qt_metacast(_clname);
}

int IntGrMtrxTableWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void IntGrMtrxTableWidget::cellChanged(InterGreenMatrixData _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void IntGrMtrxTableWidget::CellDoubleClicked(InterGreenMatrixData & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
