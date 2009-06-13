/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sat Jun 13 11:20:54 2009
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
      21,   12, // methods
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
     168,   11,   11,   11, 0x08,
     180,   11,   11,   11, 0x08,
     188,   11,   11,   11, 0x08,
     200,   11,   11,   11, 0x08,
     207,   11,   11,   11, 0x08,
     214,   11,   11,   11, 0x08,
     222,   11,   11,   11, 0x08,
     234,   11,   11,   11, 0x08,
     246,   11,   11,   11, 0x08,
     254,   11,   11,   11, 0x08,
     264,   11,   11,   11, 0x08,
     276,   11,   11,   11, 0x08,
     286,   11,   11,   11, 0x08,
     296,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0openImage()\0saveResult()\0"
    "setCurrentPage(QTreeWidgetItem*)\0"
    "setAction_SelRegion()\0setAction_SelTWard()\0"
    "setAction_SelCP()\0"
    "addUserSelection(OsteoporosisImage*)\0"
    "northWest()\0north()\0northEast()\0east()\0"
    "west()\0south()\0southWest()\0southEast()\0"
    "sobel()\0prewitt()\0hightpass()\0lowpass()\0"
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
        case 6: addUserSelection((*reinterpret_cast< OsteoporosisImage*(*)>(_a[1]))); break;
        case 7: northWest(); break;
        case 8: north(); break;
        case 9: northEast(); break;
        case 10: east(); break;
        case 11: west(); break;
        case 12: south(); break;
        case 13: southWest(); break;
        case 14: southEast(); break;
        case 15: sobel(); break;
        case 16: prewitt(); break;
        case 17: hightpass(); break;
        case 18: lowpass(); break;
        case 19: roberts(); break;
        case 20: frei_chen(); break;
        default: ;
        }
        _id -= 21;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
