/****************************************************************************
** Meta object code from reading C++ file 'loginform.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../DentistApp/loginform.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loginform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_LoginForm_t {
    uint offsetsAndSizes[10];
    char stringdata0[10];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[11];
    char stringdata4[27];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_LoginForm_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_LoginForm_t qt_meta_stringdata_LoginForm = {
    {
        QT_MOC_LITERAL(0, 9),  // "LoginForm"
        QT_MOC_LITERAL(10, 16),  // "sig_loginSuccess"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 10),  // "sig_idInfo"
        QT_MOC_LITERAL(39, 26)   // "on_loginToolButton_clicked"
    },
    "LoginForm",
    "sig_loginSuccess",
    "",
    "sig_idInfo",
    "on_loginToolButton_clicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_LoginForm[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   32,    2, 0x06,    1 /* Public */,
       3,    1,   35,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   38,    2, 0x08,    5 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject LoginForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_LoginForm.offsetsAndSizes,
    qt_meta_data_LoginForm,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_LoginForm_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<LoginForm, std::true_type>,
        // method 'sig_loginSuccess'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'sig_idInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'on_loginToolButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void LoginForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LoginForm *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sig_loginSuccess((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->sig_idInfo((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->on_loginToolButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LoginForm::*)(int );
            if (_t _q_method = &LoginForm::sig_loginSuccess; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LoginForm::*)(QString );
            if (_t _q_method = &LoginForm::sig_idInfo; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *LoginForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoginForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LoginForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int LoginForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void LoginForm::sig_loginSuccess(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LoginForm::sig_idInfo(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
