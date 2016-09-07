/****************************************************************************
** Meta object code from reading C++ file 'qdlgnetconfigfront.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qdlgnetconfigfront.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdlgnetconfigfront.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QDlgNetConfigFront_t {
    QByteArrayData data[10];
    char stringdata[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QDlgNetConfigFront_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QDlgNetConfigFront_t qt_meta_stringdata_QDlgNetConfigFront = {
    {
QT_MOC_LITERAL(0, 0, 18), // "QDlgNetConfigFront"
QT_MOC_LITERAL(1, 19, 23), // "processPendingDatagrams"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 11), // "applyReturn"
QT_MOC_LITERAL(4, 56, 9), // "searchDev"
QT_MOC_LITERAL(5, 66, 21), // "CurrentRowChangedSlot"
QT_MOC_LITERAL(6, 88, 3), // "row"
QT_MOC_LITERAL(7, 92, 9), // "applySlot"
QT_MOC_LITERAL(8, 102, 11), // "connClicked"
QT_MOC_LITERAL(9, 114, 11) // "timeOutSlot"

    },
    "QDlgNetConfigFront\0processPendingDatagrams\0"
    "\0applyReturn\0searchDev\0CurrentRowChangedSlot\0"
    "row\0applySlot\0connClicked\0timeOutSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QDlgNetConfigFront[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x0a /* Public */,
       4,    0,   51,    2, 0x0a /* Public */,
       5,    1,   52,    2, 0x0a /* Public */,
       7,    0,   55,    2, 0x0a /* Public */,
       8,    0,   56,    2, 0x0a /* Public */,
       9,    0,   57,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QDlgNetConfigFront::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QDlgNetConfigFront *_t = static_cast<QDlgNetConfigFront *>(_o);
        switch (_id) {
        case 0: _t->processPendingDatagrams(); break;
        case 1: _t->applyReturn(); break;
        case 2: _t->searchDev(); break;
        case 3: _t->CurrentRowChangedSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->applySlot(); break;
        case 5: _t->connClicked(); break;
        case 6: _t->timeOutSlot(); break;
        default: ;
        }
    }
}

const QMetaObject QDlgNetConfigFront::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QDlgNetConfigFront.data,
      qt_meta_data_QDlgNetConfigFront,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QDlgNetConfigFront::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDlgNetConfigFront::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QDlgNetConfigFront.stringdata))
        return static_cast<void*>(const_cast< QDlgNetConfigFront*>(this));
    return QDialog::qt_metacast(_clname);
}

int QDlgNetConfigFront::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
