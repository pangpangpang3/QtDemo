/****************************************************************************
** Meta object code from reading C++ file 'spreadsheet.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../itemviews/spreadsheet/spreadsheet.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'spreadsheet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SpreadSheet_t {
    QByteArrayData data[18];
    char stringdata[198];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SpreadSheet_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SpreadSheet_t qt_meta_stringdata_SpreadSheet = {
    {
QT_MOC_LITERAL(0, 0, 11), // "SpreadSheet"
QT_MOC_LITERAL(1, 12, 12), // "updateStatus"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(4, 44, 4), // "item"
QT_MOC_LITERAL(5, 49, 11), // "updateColor"
QT_MOC_LITERAL(6, 61, 14), // "updateLineEdit"
QT_MOC_LITERAL(7, 76, 13), // "returnPressed"
QT_MOC_LITERAL(8, 90, 11), // "selectColor"
QT_MOC_LITERAL(9, 102, 10), // "selectFont"
QT_MOC_LITERAL(10, 113, 5), // "clear"
QT_MOC_LITERAL(11, 119, 9), // "showAbout"
QT_MOC_LITERAL(12, 129, 5), // "print"
QT_MOC_LITERAL(13, 135, 9), // "actionSum"
QT_MOC_LITERAL(14, 145, 14), // "actionSubtract"
QT_MOC_LITERAL(15, 160, 9), // "actionAdd"
QT_MOC_LITERAL(16, 170, 14), // "actionMultiply"
QT_MOC_LITERAL(17, 185, 12) // "actionDivide"

    },
    "SpreadSheet\0updateStatus\0\0QTableWidgetItem*\0"
    "item\0updateColor\0updateLineEdit\0"
    "returnPressed\0selectColor\0selectFont\0"
    "clear\0showAbout\0print\0actionSum\0"
    "actionSubtract\0actionAdd\0actionMultiply\0"
    "actionDivide"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SpreadSheet[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x0a /* Public */,
       5,    1,   87,    2, 0x0a /* Public */,
       6,    1,   90,    2, 0x0a /* Public */,
       7,    0,   93,    2, 0x0a /* Public */,
       8,    0,   94,    2, 0x0a /* Public */,
       9,    0,   95,    2, 0x0a /* Public */,
      10,    0,   96,    2, 0x0a /* Public */,
      11,    0,   97,    2, 0x0a /* Public */,
      12,    0,   98,    2, 0x0a /* Public */,
      13,    0,   99,    2, 0x0a /* Public */,
      14,    0,  100,    2, 0x0a /* Public */,
      15,    0,  101,    2, 0x0a /* Public */,
      16,    0,  102,    2, 0x0a /* Public */,
      17,    0,  103,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
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

void SpreadSheet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SpreadSheet *_t = static_cast<SpreadSheet *>(_o);
        switch (_id) {
        case 0: _t->updateStatus((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 1: _t->updateColor((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->updateLineEdit((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->returnPressed(); break;
        case 4: _t->selectColor(); break;
        case 5: _t->selectFont(); break;
        case 6: _t->clear(); break;
        case 7: _t->showAbout(); break;
        case 8: _t->print(); break;
        case 9: _t->actionSum(); break;
        case 10: _t->actionSubtract(); break;
        case 11: _t->actionAdd(); break;
        case 12: _t->actionMultiply(); break;
        case 13: _t->actionDivide(); break;
        default: ;
        }
    }
}

const QMetaObject SpreadSheet::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SpreadSheet.data,
      qt_meta_data_SpreadSheet,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SpreadSheet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SpreadSheet::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SpreadSheet.stringdata))
        return static_cast<void*>(const_cast< SpreadSheet*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SpreadSheet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
