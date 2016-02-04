/****************************************************************************
** Meta object code from reading C++ file 'scene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../graphicsview/boxes/scene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ColorEdit_t {
    QByteArrayData data[7];
    char stringdata[47];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ColorEdit_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ColorEdit_t qt_meta_stringdata_ColorEdit = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ColorEdit"
QT_MOC_LITERAL(1, 10, 12), // "colorChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 4), // "QRgb"
QT_MOC_LITERAL(4, 29, 5), // "color"
QT_MOC_LITERAL(5, 35, 2), // "id"
QT_MOC_LITERAL(6, 38, 8) // "editDone"

    },
    "ColorEdit\0colorChanged\0\0QRgb\0color\0"
    "id\0editDone"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ColorEdit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   29,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void ColorEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ColorEdit *_t = static_cast<ColorEdit *>(_o);
        switch (_id) {
        case 0: _t->colorChanged((*reinterpret_cast< QRgb(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->editDone(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ColorEdit::*_t)(QRgb , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ColorEdit::colorChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ColorEdit::staticMetaObject = {
    { &ParameterEdit::staticMetaObject, qt_meta_stringdata_ColorEdit.data,
      qt_meta_data_ColorEdit,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ColorEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ColorEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ColorEdit.stringdata))
        return static_cast<void*>(const_cast< ColorEdit*>(this));
    return ParameterEdit::qt_metacast(_clname);
}

int ColorEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ParameterEdit::qt_metacall(_c, _id, _a);
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
void ColorEdit::colorChanged(QRgb _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_FloatEdit_t {
    QByteArrayData data[6];
    char stringdata[42];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FloatEdit_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FloatEdit_t qt_meta_stringdata_FloatEdit = {
    {
QT_MOC_LITERAL(0, 0, 9), // "FloatEdit"
QT_MOC_LITERAL(1, 10, 12), // "valueChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 5), // "value"
QT_MOC_LITERAL(4, 30, 2), // "id"
QT_MOC_LITERAL(5, 33, 8) // "editDone"

    },
    "FloatEdit\0valueChanged\0\0value\0id\0"
    "editDone"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FloatEdit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   29,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Float, QMetaType::Int,    3,    4,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void FloatEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FloatEdit *_t = static_cast<FloatEdit *>(_o);
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->editDone(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FloatEdit::*_t)(float , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FloatEdit::valueChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject FloatEdit::staticMetaObject = {
    { &ParameterEdit::staticMetaObject, qt_meta_stringdata_FloatEdit.data,
      qt_meta_data_FloatEdit,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FloatEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FloatEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FloatEdit.stringdata))
        return static_cast<void*>(const_cast< FloatEdit*>(this));
    return ParameterEdit::qt_metacast(_clname);
}

int FloatEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ParameterEdit::qt_metacall(_c, _id, _a);
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
void FloatEdit::valueChanged(float _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_TwoSidedGraphicsWidget_t {
    QByteArrayData data[4];
    char stringdata[41];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TwoSidedGraphicsWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TwoSidedGraphicsWidget_t qt_meta_stringdata_TwoSidedGraphicsWidget = {
    {
QT_MOC_LITERAL(0, 0, 22), // "TwoSidedGraphicsWidget"
QT_MOC_LITERAL(1, 23, 4), // "flip"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 11) // "animateFlip"

    },
    "TwoSidedGraphicsWidget\0flip\0\0animateFlip"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TwoSidedGraphicsWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x0a /* Public */,
       3,    0,   25,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TwoSidedGraphicsWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TwoSidedGraphicsWidget *_t = static_cast<TwoSidedGraphicsWidget *>(_o);
        switch (_id) {
        case 0: _t->flip(); break;
        case 1: _t->animateFlip(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject TwoSidedGraphicsWidget::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TwoSidedGraphicsWidget.data,
      qt_meta_data_TwoSidedGraphicsWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TwoSidedGraphicsWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TwoSidedGraphicsWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TwoSidedGraphicsWidget.stringdata))
        return static_cast<void*>(const_cast< TwoSidedGraphicsWidget*>(this));
    return QObject::qt_metacast(_clname);
}

int TwoSidedGraphicsWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_stringdata_RenderOptionsDialog_t {
    QByteArrayData data[14];
    char stringdata[186];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RenderOptionsDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RenderOptionsDialog_t qt_meta_stringdata_RenderOptionsDialog = {
    {
QT_MOC_LITERAL(0, 0, 19), // "RenderOptionsDialog"
QT_MOC_LITERAL(1, 20, 21), // "dynamicCubemapToggled"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 21), // "colorParameterChanged"
QT_MOC_LITERAL(4, 65, 4), // "QRgb"
QT_MOC_LITERAL(5, 70, 21), // "floatParameterChanged"
QT_MOC_LITERAL(6, 92, 14), // "textureChanged"
QT_MOC_LITERAL(7, 107, 13), // "shaderChanged"
QT_MOC_LITERAL(8, 121, 13), // "doubleClicked"
QT_MOC_LITERAL(9, 135, 17), // "setColorParameter"
QT_MOC_LITERAL(10, 153, 5), // "color"
QT_MOC_LITERAL(11, 159, 2), // "id"
QT_MOC_LITERAL(12, 162, 17), // "setFloatParameter"
QT_MOC_LITERAL(13, 180, 5) // "value"

    },
    "RenderOptionsDialog\0dynamicCubemapToggled\0"
    "\0colorParameterChanged\0QRgb\0"
    "floatParameterChanged\0textureChanged\0"
    "shaderChanged\0doubleClicked\0"
    "setColorParameter\0color\0id\0setFloatParameter\0"
    "value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RenderOptionsDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       3,    2,   57,    2, 0x06 /* Public */,
       5,    2,   62,    2, 0x06 /* Public */,
       6,    1,   67,    2, 0x06 /* Public */,
       7,    1,   70,    2, 0x06 /* Public */,
       8,    0,   73,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    2,   74,    2, 0x09 /* Protected */,
      12,    2,   79,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Float,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4, QMetaType::Int,   10,   11,
    QMetaType::Void, QMetaType::Float, QMetaType::Int,   13,   11,

       0        // eod
};

void RenderOptionsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RenderOptionsDialog *_t = static_cast<RenderOptionsDialog *>(_o);
        switch (_id) {
        case 0: _t->dynamicCubemapToggled((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->colorParameterChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QRgb(*)>(_a[2]))); break;
        case 2: _t->floatParameterChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 3: _t->textureChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->shaderChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->doubleClicked(); break;
        case 6: _t->setColorParameter((*reinterpret_cast< QRgb(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->setFloatParameter((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (RenderOptionsDialog::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RenderOptionsDialog::dynamicCubemapToggled)) {
                *result = 0;
            }
        }
        {
            typedef void (RenderOptionsDialog::*_t)(const QString & , QRgb );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RenderOptionsDialog::colorParameterChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (RenderOptionsDialog::*_t)(const QString & , float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RenderOptionsDialog::floatParameterChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (RenderOptionsDialog::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RenderOptionsDialog::textureChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (RenderOptionsDialog::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RenderOptionsDialog::shaderChanged)) {
                *result = 4;
            }
        }
        {
            typedef void (RenderOptionsDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&RenderOptionsDialog::doubleClicked)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject RenderOptionsDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_RenderOptionsDialog.data,
      qt_meta_data_RenderOptionsDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RenderOptionsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RenderOptionsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RenderOptionsDialog.stringdata))
        return static_cast<void*>(const_cast< RenderOptionsDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int RenderOptionsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void RenderOptionsDialog::dynamicCubemapToggled(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RenderOptionsDialog::colorParameterChanged(const QString & _t1, QRgb _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void RenderOptionsDialog::floatParameterChanged(const QString & _t1, float _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void RenderOptionsDialog::textureChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void RenderOptionsDialog::shaderChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void RenderOptionsDialog::doubleClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
struct qt_meta_stringdata_ItemDialog_t {
    QByteArrayData data[9];
    char stringdata[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ItemDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ItemDialog_t qt_meta_stringdata_ItemDialog = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ItemDialog"
QT_MOC_LITERAL(1, 11, 13), // "doubleClicked"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 16), // "newItemTriggered"
QT_MOC_LITERAL(4, 43, 20), // "ItemDialog::ItemType"
QT_MOC_LITERAL(5, 64, 4), // "type"
QT_MOC_LITERAL(6, 69, 15), // "triggerNewQtBox"
QT_MOC_LITERAL(7, 85, 20), // "triggerNewCircleItem"
QT_MOC_LITERAL(8, 106, 20) // "triggerNewSquareItem"

    },
    "ItemDialog\0doubleClicked\0\0newItemTriggered\0"
    "ItemDialog::ItemType\0type\0triggerNewQtBox\0"
    "triggerNewCircleItem\0triggerNewSquareItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ItemDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    1,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   43,    2, 0x0a /* Public */,
       7,    0,   44,    2, 0x0a /* Public */,
       8,    0,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ItemDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ItemDialog *_t = static_cast<ItemDialog *>(_o);
        switch (_id) {
        case 0: _t->doubleClicked(); break;
        case 1: _t->newItemTriggered((*reinterpret_cast< ItemDialog::ItemType(*)>(_a[1]))); break;
        case 2: _t->triggerNewQtBox(); break;
        case 3: _t->triggerNewCircleItem(); break;
        case 4: _t->triggerNewSquareItem(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ItemDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ItemDialog::doubleClicked)) {
                *result = 0;
            }
        }
        {
            typedef void (ItemDialog::*_t)(ItemDialog::ItemType );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ItemDialog::newItemTriggered)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject ItemDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ItemDialog.data,
      qt_meta_data_ItemDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ItemDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ItemDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ItemDialog.stringdata))
        return static_cast<void*>(const_cast< ItemDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ItemDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ItemDialog::doubleClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void ItemDialog::newItemTriggered(ItemDialog::ItemType _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_Scene_t {
    QByteArrayData data[16];
    char stringdata[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Scene_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Scene_t qt_meta_stringdata_Scene = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Scene"
QT_MOC_LITERAL(1, 6, 9), // "setShader"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 5), // "index"
QT_MOC_LITERAL(4, 23, 10), // "setTexture"
QT_MOC_LITERAL(5, 34, 20), // "toggleDynamicCubemap"
QT_MOC_LITERAL(6, 55, 5), // "state"
QT_MOC_LITERAL(7, 61, 17), // "setColorParameter"
QT_MOC_LITERAL(8, 79, 4), // "name"
QT_MOC_LITERAL(9, 84, 4), // "QRgb"
QT_MOC_LITERAL(10, 89, 5), // "color"
QT_MOC_LITERAL(11, 95, 17), // "setFloatParameter"
QT_MOC_LITERAL(12, 113, 5), // "value"
QT_MOC_LITERAL(13, 119, 7), // "newItem"
QT_MOC_LITERAL(14, 127, 20), // "ItemDialog::ItemType"
QT_MOC_LITERAL(15, 148, 4) // "type"

    },
    "Scene\0setShader\0\0index\0setTexture\0"
    "toggleDynamicCubemap\0state\0setColorParameter\0"
    "name\0QRgb\0color\0setFloatParameter\0"
    "value\0newItem\0ItemDialog::ItemType\0"
    "type"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Scene[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a /* Public */,
       4,    1,   47,    2, 0x0a /* Public */,
       5,    1,   50,    2, 0x0a /* Public */,
       7,    2,   53,    2, 0x0a /* Public */,
      11,    2,   58,    2, 0x0a /* Public */,
      13,    1,   63,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 9,    8,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::Float,    8,   12,
    QMetaType::Void, 0x80000000 | 14,   15,

       0        // eod
};

void Scene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Scene *_t = static_cast<Scene *>(_o);
        switch (_id) {
        case 0: _t->setShader((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setTexture((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->toggleDynamicCubemap((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setColorParameter((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QRgb(*)>(_a[2]))); break;
        case 4: _t->setFloatParameter((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 5: _t->newItem((*reinterpret_cast< ItemDialog::ItemType(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Scene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_Scene.data,
      qt_meta_data_Scene,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Scene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Scene::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Scene.stringdata))
        return static_cast<void*>(const_cast< Scene*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int Scene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
