/****************************************************************************
** Meta object code from reading C++ file 'SimpleWebView.h'
**
** Created: Tue Aug 7 13:23:26 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SimpleWebView.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SimpleWebView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SimpleWebView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   15,   14,   14, 0x0a,
      36,   14,   14,   14, 0x0a,
      47,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SimpleWebView[] = {
    "SimpleWebView\0\0url\0LoadUrl(QString)\0"
    "LoadHome()\0RefreshPage()\0"
};

void SimpleWebView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SimpleWebView *_t = static_cast<SimpleWebView *>(_o);
        switch (_id) {
        case 0: _t->LoadUrl((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->LoadHome(); break;
        case 2: _t->RefreshPage(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SimpleWebView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SimpleWebView::staticMetaObject = {
    { &QWebView::staticMetaObject, qt_meta_stringdata_SimpleWebView,
      qt_meta_data_SimpleWebView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SimpleWebView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SimpleWebView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SimpleWebView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SimpleWebView))
        return static_cast<void*>(const_cast< SimpleWebView*>(this));
    return QWebView::qt_metacast(_clname);
}

int SimpleWebView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWebView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
