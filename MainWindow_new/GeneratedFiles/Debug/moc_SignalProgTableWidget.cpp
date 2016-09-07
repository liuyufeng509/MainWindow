/****************************************************************************
** Meta object code from reading C++ file 'SignalProgTableWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SignalProgTableWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SignalProgTableWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SignalProgTableWidget_t {
    QByteArrayData data[12];
    char stringdata[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SignalProgTableWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SignalProgTableWidget_t qt_meta_stringdata_SignalProgTableWidget = {
    {
QT_MOC_LITERAL(0, 0, 21), // "SignalProgTableWidget"
QT_MOC_LITERAL(1, 22, 11), // "cellChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 14), // "SignalProgData"
QT_MOC_LITERAL(4, 50, 4), // "data"
QT_MOC_LITERAL(5, 55, 17), // "CellDoubleClicked"
QT_MOC_LITERAL(6, 73, 15), // "SignalProgData&"
QT_MOC_LITERAL(7, 89, 14), // "updateDataToUI"
QT_MOC_LITERAL(8, 104, 15), // "dealCellChanged"
QT_MOC_LITERAL(9, 120, 3), // "row"
QT_MOC_LITERAL(10, 124, 6), // "column"
QT_MOC_LITERAL(11, 131, 21) // "dealCellDoubleClicked"

    },
    "SignalProgTableWidget\0cellChanged\0\0"
    "SignalProgData\0data\0CellDoubleClicked\0"
    "SignalProgData&\0updateDataToUI\0"
    "dealCellChanged\0row\0column\0"
    "dealCellDoubleClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SignalProgTableWidget[] = {

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

void SignalProgTableWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SignalProgTableWidget *_t = static_cast<SignalProgTableWidget *>(_o);
        switch (_id) {
        case 0: _t->cellChanged((*reinterpret_cast< SignalProgData(*)>(_a[1]))); break;
        case 1: _t->CellDoubleClicked((*reinterpret_cast< SignalProgData(*)>(_a[1]))); break;
        case 2: _t->updateDataToUI(); break;
        case 3: _t->dealCellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->dealCellDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SignalProgTableWidget::*_t)(SignalProgData );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SignalProgTableWidget::cellChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (SignalProgTableWidget::*_t)(SignalProgData & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SignalProgTableWidget::CellDoubleClicked)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject SignalProgTableWidget::staticMetaObject = {
    { &QTableWidget::staticMetaObject, qt_meta_stringdata_SignalProgTableWidget.data,
      qt_meta_data_SignalProgTableWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SignalProgTableWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SignalProgTableWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SignalProgTableWidget.stringdata))
        return static_cast<void*>(const_cast< SignalProgTableWidget*>(this));
    return QTableWidget::qt_metacast(_clname);
}

int SignalProgTableWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void SignalProgTableWidget::cellChanged(SignalProgData _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SignalProgTableWidget::CellDoubleClicked(SignalProgData & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
