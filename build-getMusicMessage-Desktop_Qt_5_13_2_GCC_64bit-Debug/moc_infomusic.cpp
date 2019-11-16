/****************************************************************************
** Meta object code from reading C++ file 'infomusic.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../getMusicMessage/infomusic.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'infomusic.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_InfoMusic_t {
    QByteArrayData data[13];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InfoMusic_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InfoMusic_t qt_meta_stringdata_InfoMusic = {
    {
QT_MOC_LITERAL(0, 0, 9), // "InfoMusic"
QT_MOC_LITERAL(1, 10, 10), // "urlChanged"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 14), // "getInformation"
QT_MOC_LITERAL(4, 37, 13), // "InfoMusicType"
QT_MOC_LITERAL(5, 51, 4), // "data"
QT_MOC_LITERAL(6, 56, 13), // "getCoverImage"
QT_MOC_LITERAL(7, 70, 7), // "resouce"
QT_MOC_LITERAL(8, 78, 13), // "errorResource"
QT_MOC_LITERAL(9, 92, 6), // "setUrl"
QT_MOC_LITERAL(10, 99, 8), // "filePath"
QT_MOC_LITERAL(11, 108, 6), // "getUrl"
QT_MOC_LITERAL(12, 115, 10) // "getMessage"

    },
    "InfoMusic\0urlChanged\0\0getInformation\0"
    "InfoMusicType\0data\0getCoverImage\0"
    "resouce\0errorResource\0setUrl\0filePath\0"
    "getUrl\0getMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InfoMusic[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       3,    1,   52,    2, 0x06 /* Public */,
       6,    1,   55,    2, 0x06 /* Public */,
       8,    1,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   61,    2, 0x0a /* Public */,
      11,    0,   64,    2, 0x0a /* Public */,
      12,    0,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QUrl,    2,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::QPixmap,    7,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::QString,
    QMetaType::Void,

       0        // eod
};

void InfoMusic::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<InfoMusic *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->urlChanged((*reinterpret_cast< QUrl(*)>(_a[1]))); break;
        case 1: _t->getInformation((*reinterpret_cast< const InfoMusicType(*)>(_a[1]))); break;
        case 2: _t->getCoverImage((*reinterpret_cast< QPixmap(*)>(_a[1]))); break;
        case 3: _t->errorResource((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->setUrl((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: { QString _r = _t->getUrl();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->getMessage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (InfoMusic::*)(QUrl );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InfoMusic::urlChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (InfoMusic::*)(const InfoMusicType );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InfoMusic::getInformation)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (InfoMusic::*)(QPixmap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InfoMusic::getCoverImage)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (InfoMusic::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InfoMusic::errorResource)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject InfoMusic::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_InfoMusic.data,
    qt_meta_data_InfoMusic,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *InfoMusic::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InfoMusic::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_InfoMusic.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int InfoMusic::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void InfoMusic::urlChanged(QUrl _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void InfoMusic::getInformation(const InfoMusicType _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void InfoMusic::getCoverImage(QPixmap _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void InfoMusic::errorResource(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
