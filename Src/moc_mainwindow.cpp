/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Thu Jun 11 21:59:44 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      24,   11,   11,   11, 0x08,
      37,   11,   11,   11, 0x08,
      70,   11,   11,   11, 0x08,
      92,   11,   11,   11, 0x08,
     113,   11,   11,   11, 0x08,
     131,   11,   11,   11, 0x08,
     143,   11,   11,   11, 0x08,
     151,   11,   11,   11, 0x08,
     163,   11,   11,   11, 0x08,
     170,   11,   11,   11, 0x08,
     177,   11,   11,   11, 0x08,
     185,   11,   11,   11, 0x08,
     197,   11,   11,   11, 0x08,
     209,   11,   11,   11, 0x08,
     217,   11,   11,   11, 0x08,
     227,   11,   11,   11, 0x08,
     239,   11,   11,   11, 0x08,
     249,   11,   11,   11, 0x08,
     259,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0openImage()\0saveResult()\0"
    "setCurrentPage(QTreeWidgetItem*)\0"
    "setAction_SelRegion()\0setAction_SelTWard()\0"
    "setAction_SelCP()\0northWest()\0north()\0"
    "northEast()\0east()\0west()\0south()\0"
    "southWest()\0southEast()\0sobel()\0"
    "prewitt()\0hightpass()\0lowpass()\0"
    "roberts()\0frei_chen()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

const QMetaObject *MainWindow::metaObject() const
{
    return &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: openImage(); break;
        case 1: saveResult(); break;
        case 2: setCurrentPage((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 3: setAction_SelRegion(); break;
        case 4: setAction_SelTWard(); break;
        case 5: setAction_SelCP(); break;
        case 6: northWest(); break;
        case 7: north(); break;
        case 8: northEast(); break;
        case 9: east(); break;
        case 10: west(); break;
        case 11: south(); break;
        case 12: southWest(); break;
        case 13: southEast(); break;
        case 14: sobel(); break;
        case 15: prewitt(); break;
        case 16: hightpass(); break;
        case 17: lowpass(); break;
        case 18: roberts(); break;
        case 19: frei_chen(); break;
        default: ;
        }
        _id -= 20;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
