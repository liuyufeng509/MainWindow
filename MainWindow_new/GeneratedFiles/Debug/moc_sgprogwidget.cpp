/****************************************************************************
** Meta object code from reading C++ file 'sgprogwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../sgprogwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sgprogwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SgProgWidget_t {
    QByteArrayData data[17];
    char stringdata[194];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SgProgWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SgProgWidget_t qt_meta_stringdata_SgProgWidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SgProgWidget"
QT_MOC_LITERAL(1, 13, 17), // "sgProgDataChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 14), // "SignalProgData"
QT_MOC_LITERAL(4, 47, 4), // "data"
QT_MOC_LITERAL(5, 52, 23), // "currentIndexChangedSlot"
QT_MOC_LITERAL(6, 76, 5), // "index"
QT_MOC_LITERAL(7, 82, 3), // "row"
QT_MOC_LITERAL(8, 86, 20), // "sgTypeOrCoordChanged"
QT_MOC_LITERAL(9, 107, 15), // "cellChangedSlot"
QT_MOC_LITERAL(10, 123, 6), // "column"
QT_MOC_LITERAL(11, 130, 16), // "paintChangedSlot"
QT_MOC_LITERAL(12, 147, 16), // "cycleChangedSlot"
QT_MOC_LITERAL(13, 164, 12), // "foucsChanged"
QT_MOC_LITERAL(14, 177, 8), // "QWidget*"
QT_MOC_LITERAL(15, 186, 3), // "old"
QT_MOC_LITERAL(16, 190, 3) // "now"

    },
    "SgProgWidget\0sgProgDataChanged\0\0"
    "SignalProgData\0data\0currentIndexChangedSlot\0"
    "index\0row\0sgTypeOrCoordChanged\0"
    "cellChangedSlot\0column\0paintChangedSlot\0"
    "cycleChangedSlot\0foucsChanged\0QWidget*\0"
    "old\0now"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SgProgWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   52,    2, 0x0a /* Public */,
       8,    2,   57,    2, 0x0a /* Public */,
       9,    4,   62,    2, 0x0a /* Public */,
      11,    2,   71,    2, 0x0a /* Public */,
      12,    1,   76,    2, 0x0a /* Public */,
      13,    2,   79,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    7,   10,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 14, 0x80000000 | 14,   15,   16,

       0        // eod
};

void SgProgWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SgProgWidget *_t = static_cast<SgProgWidget *>(_o);
        switch (_id) {
        case 0: _t->sgProgDataChanged((*reinterpret_cast< SignalProgData(*)>(_a[1]))); break;
        case 1: _t->currentIndexChangedSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->sgTypeOrCoordChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->cellChangedSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 4: _t->paintChangedSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->cycleChangedSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->foucsChanged((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
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
            typedef void (SgProgWidget::*_t)(SignalProgData );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SgProgWidget::sgProgDataChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject SgProgWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SgProgWidget.data,
      qt_meta_data_SgProgWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SgProgWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SgProgWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SgProgWidget.stringdata))
        return static_cast<void*>(const_cast< SgProgWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int SgProgWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void SgProgWidget::sgProgDataChanged(SignalProgData _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
