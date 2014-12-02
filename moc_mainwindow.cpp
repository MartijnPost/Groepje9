/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata[421];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 21),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 7),
QT_MOC_LITERAL(4, 42, 22),
QT_MOC_LITERAL(5, 65, 26),
QT_MOC_LITERAL(6, 92, 27),
QT_MOC_LITERAL(7, 120, 25),
QT_MOC_LITERAL(8, 146, 26),
QT_MOC_LITERAL(9, 173, 29),
QT_MOC_LITERAL(10, 203, 30),
QT_MOC_LITERAL(11, 234, 27),
QT_MOC_LITERAL(12, 262, 28),
QT_MOC_LITERAL(13, 291, 20),
QT_MOC_LITERAL(14, 312, 23),
QT_MOC_LITERAL(15, 336, 24),
QT_MOC_LITERAL(16, 361, 20),
QT_MOC_LITERAL(17, 382, 32),
QT_MOC_LITERAL(18, 415, 5)
    },
    "MainWindow\0on_KnoopRadio_toggled\0\0"
    "checked\0on_KnoopButton_clicked\0"
    "on_StartKnoopRadio_toggled\0"
    "on_StartKnoopButton_clicked\0"
    "on_EindKnoopRadio_toggled\0"
    "on_EindKnoopButton_clicked\0"
    "on_OngerichteTakRadio_toggled\0"
    "on_OngerichteTakButton_clicked\0"
    "on_GerichteTakRadio_toggled\0"
    "on_GerichteTakButton_clicked\0"
    "on_StartKnop_clicked\0on_InvoegenKnop_clicked\0"
    "on_AfsluitenKnop_clicked\0on_ClearKnop_clicked\0"
    "on_algChoice_currentIndexChanged\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x08 /* Private */,
       4,    0,   92,    2, 0x08 /* Private */,
       5,    1,   93,    2, 0x08 /* Private */,
       6,    0,   96,    2, 0x08 /* Private */,
       7,    1,   97,    2, 0x08 /* Private */,
       8,    0,  100,    2, 0x08 /* Private */,
       9,    1,  101,    2, 0x08 /* Private */,
      10,    0,  104,    2, 0x08 /* Private */,
      11,    1,  105,    2, 0x08 /* Private */,
      12,    0,  108,    2, 0x08 /* Private */,
      13,    0,  109,    2, 0x08 /* Private */,
      14,    0,  110,    2, 0x08 /* Private */,
      15,    0,  111,    2, 0x08 /* Private */,
      16,    0,  112,    2, 0x08 /* Private */,
      17,    1,  113,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_KnoopRadio_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_KnoopButton_clicked(); break;
        case 2: _t->on_StartKnoopRadio_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_StartKnoopButton_clicked(); break;
        case 4: _t->on_EindKnoopRadio_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_EindKnoopButton_clicked(); break;
        case 6: _t->on_OngerichteTakRadio_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_OngerichteTakButton_clicked(); break;
        case 8: _t->on_GerichteTakRadio_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_GerichteTakButton_clicked(); break;
        case 10: _t->on_StartKnop_clicked(); break;
        case 11: _t->on_InvoegenKnop_clicked(); break;
        case 12: _t->on_AfsluitenKnop_clicked(); break;
        case 13: _t->on_ClearKnop_clicked(); break;
        case 14: _t->on_algChoice_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
