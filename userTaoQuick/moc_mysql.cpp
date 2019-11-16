/****************************************************************************
** Meta object code from reading C++ file 'mysql.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "mysql.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mysql.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MySql_t {
    QByteArrayData data[18];
    char stringdata0[160];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MySql_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MySql_t qt_meta_stringdata_MySql = {
    {
QT_MOC_LITERAL(0, 0, 5), // "MySql"
QT_MOC_LITERAL(1, 6, 11), // "insertMusic"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 8), // "QString&"
QT_MOC_LITERAL(4, 28, 6), // "author"
QT_MOC_LITERAL(5, 35, 5), // "album"
QT_MOC_LITERAL(6, 41, 8), // "duration"
QT_MOC_LITERAL(7, 50, 8), // "filePath"
QT_MOC_LITERAL(8, 59, 11), // "removeMusic"
QT_MOC_LITERAL(9, 71, 8), // "filepath"
QT_MOC_LITERAL(10, 80, 14), // "insertTourList"
QT_MOC_LITERAL(11, 95, 9), // "className"
QT_MOC_LITERAL(12, 105, 9), // "dataArray"
QT_MOC_LITERAL(13, 115, 5), // "image"
QT_MOC_LITERAL(14, 121, 10), // "removeList"
QT_MOC_LITERAL(15, 132, 10), // "printError"
QT_MOC_LITERAL(16, 143, 10), // "QSqlQuery&"
QT_MOC_LITERAL(17, 154, 5) // "query"

    },
    "MySql\0insertMusic\0\0QString&\0author\0"
    "album\0duration\0filePath\0removeMusic\0"
    "filepath\0insertTourList\0className\0"
    "dataArray\0image\0removeList\0printError\0"
    "QSqlQuery&\0query"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MySql[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    4,   44,    2, 0x0a /* Public */,
       8,    1,   53,    2, 0x0a /* Public */,
      10,    3,   56,    2, 0x0a /* Public */,
      10,    2,   63,    2, 0x2a /* Public | MethodCloned */,
      14,    2,   68,    2, 0x0a /* Public */,
      15,    1,   73,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Bool, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3,    4,    5,    6,    7,
    QMetaType::Bool, 0x80000000 | 3,    9,
    QMetaType::Bool, 0x80000000 | 3, 0x80000000 | 3, QMetaType::QString,   11,   12,   13,
    QMetaType::Bool, 0x80000000 | 3, 0x80000000 | 3,   11,   12,
    QMetaType::Bool, 0x80000000 | 3, 0x80000000 | 3,   11,   12,
    QMetaType::Bool, 0x80000000 | 16,   17,

       0        // eod
};

void MySql::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MySql *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->insertMusic((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: { bool _r = _t->removeMusic((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: { bool _r = _t->insertTourList((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->insertTourList((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->removeList((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->printError((*reinterpret_cast< QSqlQuery(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MySql::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_MySql.data,
    qt_meta_data_MySql,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MySql::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MySql::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MySql.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MySql::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
