/****************************************************************************
** Meta object code from reading C++ file 'InputHooks.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../AnalystInputCapture/InputHooks.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'InputHooks.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_InputCapture__InputHooks_t {
    QByteArrayData data[5];
    char stringdata0[60];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InputCapture__InputHooks_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InputCapture__InputHooks_t qt_meta_stringdata_InputCapture__InputHooks = {
    {
QT_MOC_LITERAL(0, 0, 24), // "InputCapture::InputHooks"
QT_MOC_LITERAL(1, 25, 12), // "addKeystroke"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 14), // "addMouseaction"
QT_MOC_LITERAL(4, 54, 5) // "POINT"

    },
    "InputCapture::InputHooks\0addKeystroke\0"
    "\0addMouseaction\0POINT"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InputCapture__InputHooks[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   24,    2, 0x06 /* Public */,
       3,    5,   33,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UShort, QMetaType::UShort, QMetaType::UShort, QMetaType::LongLong,    2,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 4, QMetaType::UInt, QMetaType::QString, QMetaType::UInt, QMetaType::LongLong,    2,    2,    2,    2,    2,

       0        // eod
};

void InputCapture::InputHooks::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        InputHooks *_t = static_cast<InputHooks *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addKeystroke((*reinterpret_cast< quint16(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2])),(*reinterpret_cast< quint16(*)>(_a[3])),(*reinterpret_cast< qint64(*)>(_a[4]))); break;
        case 1: _t->addMouseaction((*reinterpret_cast< POINT(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< quint32(*)>(_a[4])),(*reinterpret_cast< qint64(*)>(_a[5]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (InputHooks::*)(quint16 , quint16 , quint16 , qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputHooks::addKeystroke)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (InputHooks::*)(POINT , quint32 , QString , quint32 , qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputHooks::addMouseaction)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject InputCapture::InputHooks::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_InputCapture__InputHooks.data,
      qt_meta_data_InputCapture__InputHooks,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *InputCapture::InputHooks::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InputCapture::InputHooks::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_InputCapture__InputHooks.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int InputCapture::InputHooks::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void InputCapture::InputHooks::addKeystroke(quint16 _t1, quint16 _t2, quint16 _t3, qint64 _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void InputCapture::InputHooks::addMouseaction(POINT _t1, quint32 _t2, QString _t3, quint32 _t4, qint64 _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
