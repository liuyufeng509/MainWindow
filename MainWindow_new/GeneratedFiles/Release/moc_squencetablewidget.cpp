/****************************************************************************
** Meta object code from reading C++ file 'squencetablewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../squencetablewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'squencetablewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SquenceTableWidget_t {
    QByteArrayData data[9];
    char stringdata[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SquenceTableWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SquenceTableWidget_t qt_meta_stringdata_SquenceTableWidget = {
    {
QT_MOC_LITERAL(0, 0, 18), // "SquenceTableWidget"
QT_MOC_LITERAL(1, 19, 17), // "CellDoubleClicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 12), // "SquenceData&"
QT_MOC_LITERAL(4, 51, 4), // "data"
QT_MOC_LITERAL(5, 56, 14), // "updateDataToUI"
QT_MOC_LITERAL(6, 71, 21), // "dealCellDoubleClicked"
QT_MOC_LITERAL(7, 93, 3), // "row"
QT_MOC_LITERAL(8, 97, 6) // "column"

    },
    "SquenceTableWidget\0CellDoubleClicked\0"
    "\0SquenceData&\0data\0updateDataToUI\0"
    "dealCellDoubleClicked\0row\0column"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SquenceTableWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   32,    2, 0x0a /* Public */,
       6,    2,   33,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,

       0        // eod
};

void SquenceTableWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SquenceTableWidget *_t = static_cast<SquenceTableWidget *>(_o);
        switch (_id) {
        case 0: _t->CellDoubleClicked((*reinterpret_cast< SquenceData(*)>(_a[1]))); break;
        case 1: _t->updateDataToUI(); break;
        case 2: _t->dealCellDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SquenceTableWidget::*_t)(SquenceData & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SquenceTableWidget::CellDoubleClicked)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject SquenceTableWidget::staticMetaObject = {
    { &QTableWidget::staticMetaObject, qt_meta_stringdata_SquenceTableWidget.data,
      qt_meta_data_SquenceTableWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SquenceTableWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SquenceTableWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SquenceTableWidget.stringdata))
        return static_cast<void*>(const_cast< SquenceTableWidget*>(this));
    return QTableWidget::qt_metacast(_clname);
}

int SquenceTableWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void SquenceTableWidget::CellDoubleClicked(SquenceData & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
