/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Thu Jun 4 13:01:52 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      24,   11,   11,   11, 0x08,
      37,   11,   11,   11, 0x08,
      70,   11,   11,   11, 0x08,
      82,   11,   11,   11, 0x08,
      90,   11,   11,   11, 0x08,
     102,   11,   11,   11, 0x08,
     109,   11,   11,   11, 0x08,
     116,   11,   11,   11, 0x08,
     124,   11,   11,   11, 0x08,
     136,   11,   11,   11, 0x08,
     148,   11,   11,   11, 0x08,
     156,   11,   11,   11, 0x08,
     166,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0openImage()\0saveResult()\0"
    "setCurrentPage(QTreeWidgetItem*)\0"
    "northWest()\0north()\0northEast()\0east()\0"
    "west()\0south()\0southWest()\0southEast()\0"
    "sobel()\0prewitt()\0complete()\0"
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
        case 3: northWest(); break;
        case 4: north(); break;
        case 5: northEast(); break;
        case 6: east(); break;
        case 7: west(); break;
        case 8: south(); break;
        case 9: southWest(); break;
        case 10: southEast(); break;
        case 11: sobel(); break;
        case 12: prewitt(); break;
        case 13: complete(); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
