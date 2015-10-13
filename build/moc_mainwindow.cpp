/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[15];
    char stringdata0[312];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 17), // "cboProfileChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 21), // "cboControlModeChanged"
QT_MOC_LITERAL(4, 52, 20), // "cboColourModeChanged"
QT_MOC_LITERAL(5, 73, 19), // "cboAnimationChanged"
QT_MOC_LITERAL(6, 93, 26), // "on_btnSelectColour_clicked"
QT_MOC_LITERAL(7, 120, 24), // "on_btnFavourite1_clicked"
QT_MOC_LITERAL(8, 145, 24), // "on_btnFavourite2_clicked"
QT_MOC_LITERAL(9, 170, 24), // "on_btnFavourite3_clicked"
QT_MOC_LITERAL(10, 195, 24), // "on_btnFavourite4_clicked"
QT_MOC_LITERAL(11, 220, 24), // "on_btnFavourite5_clicked"
QT_MOC_LITERAL(12, 245, 24), // "on_btnFavourite6_clicked"
QT_MOC_LITERAL(13, 270, 20), // "on_btnCancel_clicked"
QT_MOC_LITERAL(14, 291, 20) // "on_btnUpdate_clicked"

    },
    "MainWindow\0cboProfileChanged\0\0"
    "cboControlModeChanged\0cboColourModeChanged\0"
    "cboAnimationChanged\0on_btnSelectColour_clicked\0"
    "on_btnFavourite1_clicked\0"
    "on_btnFavourite2_clicked\0"
    "on_btnFavourite3_clicked\0"
    "on_btnFavourite4_clicked\0"
    "on_btnFavourite5_clicked\0"
    "on_btnFavourite6_clicked\0on_btnCancel_clicked\0"
    "on_btnUpdate_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x08 /* Private */,
       3,    1,   82,    2, 0x08 /* Private */,
       4,    1,   85,    2, 0x08 /* Private */,
       5,    1,   88,    2, 0x08 /* Private */,
       6,    0,   91,    2, 0x08 /* Private */,
       7,    0,   92,    2, 0x08 /* Private */,
       8,    0,   93,    2, 0x08 /* Private */,
       9,    0,   94,    2, 0x08 /* Private */,
      10,    0,   95,    2, 0x08 /* Private */,
      11,    0,   96,    2, 0x08 /* Private */,
      12,    0,   97,    2, 0x08 /* Private */,
      13,    0,   98,    2, 0x08 /* Private */,
      14,    0,   99,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cboProfileChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->cboControlModeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->cboColourModeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->cboAnimationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_btnSelectColour_clicked(); break;
        case 5: _t->on_btnFavourite1_clicked(); break;
        case 6: _t->on_btnFavourite2_clicked(); break;
        case 7: _t->on_btnFavourite3_clicked(); break;
        case 8: _t->on_btnFavourite4_clicked(); break;
        case 9: _t->on_btnFavourite5_clicked(); break;
        case 10: _t->on_btnFavourite6_clicked(); break;
        case 11: _t->on_btnCancel_clicked(); break;
        case 12: _t->on_btnUpdate_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
