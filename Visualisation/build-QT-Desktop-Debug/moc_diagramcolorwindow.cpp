/****************************************************************************
** Meta object code from reading C++ file 'diagramcolorwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QT/diagramcolorwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'diagramcolorwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DiagramColorWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x08,
      43,   19,   19,   19, 0x08,
      66,   19,   19,   19, 0x08,
      89,   19,   19,   19, 0x08,
     112,   19,   19,   19, 0x08,
     136,   19,   19,   19, 0x08,
     160,   19,   19,   19, 0x08,
     186,   19,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DiagramColorWindow[] = {
    "DiagramColorWindow\0\0on_checkBoxR_clicked()\0"
    "on_checkBoxG_clicked()\0on_checkBoxB_clicked()\0"
    "on_checkBoxY_clicked()\0on_checkBoxCb_clicked()\0"
    "on_checkBoxCr_clicked()\0"
    "on_checkBoxCumu_clicked()\0ferm()\0"
};

void DiagramColorWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DiagramColorWindow *_t = static_cast<DiagramColorWindow *>(_o);
        switch (_id) {
        case 0: _t->on_checkBoxR_clicked(); break;
        case 1: _t->on_checkBoxG_clicked(); break;
        case 2: _t->on_checkBoxB_clicked(); break;
        case 3: _t->on_checkBoxY_clicked(); break;
        case 4: _t->on_checkBoxCb_clicked(); break;
        case 5: _t->on_checkBoxCr_clicked(); break;
        case 6: _t->on_checkBoxCumu_clicked(); break;
        case 7: _t->ferm(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData DiagramColorWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DiagramColorWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DiagramColorWindow,
      qt_meta_data_DiagramColorWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DiagramColorWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DiagramColorWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DiagramColorWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DiagramColorWindow))
        return static_cast<void*>(const_cast< DiagramColorWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int DiagramColorWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
