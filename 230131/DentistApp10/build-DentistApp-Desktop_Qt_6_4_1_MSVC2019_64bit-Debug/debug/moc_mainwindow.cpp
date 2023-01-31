/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../DentistApp/mainwindow.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[38];
    char stringdata0[11];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[11];
    char stringdata4[17];
    char stringdata5[15];
    char stringdata6[16];
    char stringdata7[9];
    char stringdata8[33];
    char stringdata9[28];
    char stringdata10[29];
    char stringdata11[32];
    char stringdata12[33];
    char stringdata13[36];
    char stringdata14[18];
    char stringdata15[15];
    char stringdata16[5];
    char stringdata17[13];
    char stringdata18[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 14),  // "sig_doctorInfo"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 10),  // "selectItem"
        QT_MOC_LITERAL(38, 16),  // "QListWidgetItem*"
        QT_MOC_LITERAL(55, 14),  // "previousScreen"
        QT_MOC_LITERAL(70, 15),  // "slot_doctorInfo"
        QT_MOC_LITERAL(86, 8),  // "DoctorID"
        QT_MOC_LITERAL(95, 32),  // "on_layoutClearPushButton_clicked"
        QT_MOC_LITERAL(128, 27),  // "on_zoomInToolButton_clicked"
        QT_MOC_LITERAL(156, 28),  // "on_zoomOutToolButton_clicked"
        QT_MOC_LITERAL(185, 31),  // "on_leftRotateToolButton_clicked"
        QT_MOC_LITERAL(217, 32),  // "on_rightRotateToolButton_clicked"
        QT_MOC_LITERAL(250, 35),  // "on_imageSizeClearPushButton_c..."
        QT_MOC_LITERAL(286, 17),  // "layoutSizeChanged"
        QT_MOC_LITERAL(304, 14),  // "QGraphicsView*"
        QT_MOC_LITERAL(319, 4),  // "grid"
        QT_MOC_LITERAL(324, 12),  // "DoubleWidget"
        QT_MOC_LITERAL(337, 15)   // "showContextMenu"
    },
    "MainWindow",
    "sig_doctorInfo",
    "",
    "selectItem",
    "QListWidgetItem*",
    "previousScreen",
    "slot_doctorInfo",
    "DoctorID",
    "on_layoutClearPushButton_clicked",
    "on_zoomInToolButton_clicked",
    "on_zoomOutToolButton_clicked",
    "on_leftRotateToolButton_clicked",
    "on_rightRotateToolButton_clicked",
    "on_imageSizeClearPushButton_clicked",
    "layoutSizeChanged",
    "QGraphicsView*",
    "grid",
    "DoubleWidget",
    "showContextMenu"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   92,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    1,   95,    2, 0x0a,    3 /* Public */,
       5,    0,   98,    2, 0x0a,    5 /* Public */,
       6,    1,   99,    2, 0x0a,    6 /* Public */,
       8,    0,  102,    2, 0x08,    8 /* Private */,
       9,    0,  103,    2, 0x08,    9 /* Private */,
      10,    0,  104,    2, 0x08,   10 /* Private */,
      11,    0,  105,    2, 0x08,   11 /* Private */,
      12,    0,  106,    2, 0x08,   12 /* Private */,
      13,    0,  107,    2, 0x08,   13 /* Private */,
      14,    1,  108,    2, 0x08,   14 /* Private */,
      17,    1,  111,    2, 0x08,   16 /* Private */,
      18,    1,  114,    2, 0x08,   18 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, QMetaType::QPoint,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'sig_doctorInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'selectItem'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'previousScreen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_doctorInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'on_layoutClearPushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_zoomInToolButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_zoomOutToolButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_leftRotateToolButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_rightRotateToolButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_imageSizeClearPushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'layoutSizeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QGraphicsView *, std::false_type>,
        // method 'DoubleWidget'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QGraphicsView *, std::false_type>,
        // method 'showContextMenu'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sig_doctorInfo((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->selectItem((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 2: _t->previousScreen(); break;
        case 3: _t->slot_doctorInfo((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->on_layoutClearPushButton_clicked(); break;
        case 5: _t->on_zoomInToolButton_clicked(); break;
        case 6: _t->on_zoomOutToolButton_clicked(); break;
        case 7: _t->on_leftRotateToolButton_clicked(); break;
        case 8: _t->on_rightRotateToolButton_clicked(); break;
        case 9: _t->on_imageSizeClearPushButton_clicked(); break;
        case 10: _t->layoutSizeChanged((*reinterpret_cast< std::add_pointer_t<QGraphicsView*>>(_a[1]))); break;
        case 11: _t->DoubleWidget((*reinterpret_cast< std::add_pointer_t<QGraphicsView*>>(_a[1]))); break;
        case 12: _t->showContextMenu((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(QString );
            if (_t _q_method = &MainWindow::sig_doctorInfo; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::sig_doctorInfo(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
