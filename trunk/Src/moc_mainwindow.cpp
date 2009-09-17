/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Thu Sep 17 14:35:21 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      31,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      41,   11,   11,   11, 0x08,
      69,   11,   11,   11, 0x08,
     103,   11,   11,   11, 0x08,
     138,   11,   11,   11, 0x08,
     150,   11,   11,   11, 0x08,
     163,   11,   11,   11, 0x08,
     196,   11,   11,   11, 0x08,
     218,   11,   11,   11, 0x08,
     239,   11,   11,   11, 0x08,
     257,   11,   11,   11, 0x08,
     296,  294,   11,   11, 0x08,
     341,   11,   11,   11, 0x08,
     353,   11,   11,   11, 0x08,
     361,   11,   11,   11, 0x08,
     373,   11,   11,   11, 0x08,
     380,   11,   11,   11, 0x08,
     387,   11,   11,   11, 0x08,
     395,   11,   11,   11, 0x08,
     407,   11,   11,   11, 0x08,
     419,   11,   11,   11, 0x08,
     427,   11,   11,   11, 0x08,
     437,   11,   11,   11, 0x08,
     449,   11,   11,   11, 0x08,
     459,   11,   11,   11, 0x08,
     471,   11,   11,   11, 0x08,
     481,   11,   11,   11, 0x08,
     498,  493,   11,   11, 0x08,
     509,   11,   11,   11, 0x08,
     519,   11,   11,   11, 0x08,
     533,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_tbDiagnosticate_clicked()\0"
    "on_actionUmbral_triggered()\0"
    "on_actionEcualizacion_triggered()\0"
    "on_actionNormalizacion_triggered()\0"
    "openImage()\0saveResult()\0"
    "setCurrentPage(QTreeWidgetItem*)\0"
    "setAction_SelRegion()\0setAction_SelTWard()\0"
    "setAction_SelCP()\0"
    "addUserSelection(OsteoporosisImage*)\0"
    ",\0addModifiedImage(OsteoporosisImage*,QString)\0"
    "northWest()\0north()\0northEast()\0east()\0"
    "west()\0south()\0southWest()\0southEast()\0"
    "sobel()\0prewitt()\0hightpass()\0lowpass()\0"
    "gaussiano()\0roberts()\0frei_chen()\0"
    "tool\0tools(int)\0erosion()\0erosionCond()\0"
    "dilatation()\0"
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
        case 0: on_tbDiagnosticate_clicked(); break;
        case 1: on_actionUmbral_triggered(); break;
        case 2: on_actionEcualizacion_triggered(); break;
        case 3: on_actionNormalizacion_triggered(); break;
        case 4: openImage(); break;
        case 5: saveResult(); break;
        case 6: setCurrentPage((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 7: setAction_SelRegion(); break;
        case 8: setAction_SelTWard(); break;
        case 9: setAction_SelCP(); break;
        case 10: addUserSelection((*reinterpret_cast< OsteoporosisImage*(*)>(_a[1]))); break;
        case 11: addModifiedImage((*reinterpret_cast< OsteoporosisImage*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 12: northWest(); break;
        case 13: north(); break;
        case 14: northEast(); break;
        case 15: east(); break;
        case 16: west(); break;
        case 17: south(); break;
        case 18: southWest(); break;
        case 19: southEast(); break;
        case 20: sobel(); break;
        case 21: prewitt(); break;
        case 22: hightpass(); break;
        case 23: lowpass(); break;
        case 24: gaussiano(); break;
        case 25: roberts(); break;
        case 26: frei_chen(); break;
        case 27: tools((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: erosion(); break;
        case 29: erosionCond(); break;
        case 30: dilatation(); break;
        default: ;
        }
        _id -= 31;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
