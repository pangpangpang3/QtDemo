// This is the implementation of the QPyQmlObject classes.
//
// Copyright (c) 2014 Riverbank Computing Limited <info@riverbankcomputing.com>
// 
// This file is part of PyQt5.
// 
// This file may be used under the terms of the GNU General Public License
// version 3.0 as published by the Free Software Foundation and appearing in
// the file LICENSE included in the packaging of this file.  Please review the
// following information to ensure the GNU General Public License version 3.0
// requirements will be met: http://www.gnu.org/copyleft/gpl.html.
// 
// If you do not wish to use this file under the terms of the GPL version 3.0
// then you may purchase a commercial license.  For more information contact
// info@riverbankcomputing.com.
// 
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.


#include "qpyqmlobject.h"

#include "sipAPIQtQml.h"


// Forward declarations.
static void bad_result(PyObject *res, const char *context);

// The list of registered Python types.
QList<PyTypeObject *> QPyQmlObjectProxy::pyqt_types;

// The set of proxies in existence.
QSet<QObject *> QPyQmlObjectProxy::proxies;


// The ctor.
QPyQmlObjectProxy::QPyQmlObjectProxy(QObject *parent) : QObject(parent),
        py_proxied(0)
{
    proxies.insert(this);
}


// The dtor.
QPyQmlObjectProxy::~QPyQmlObjectProxy()
{
    proxies.remove(this);

    SIP_BLOCK_THREADS
    Py_XDECREF(py_proxied);
    SIP_UNBLOCK_THREADS

    if (!proxied.isNull())
        delete proxied.data();
}


// Called when QML has connected to a signal of the proxied object.
void QPyQmlObjectProxy::connectNotify(const QMetaMethod &sig)
{
    QByteArray signal_sig = signalSignature(sig);

    // The signal has actually been connected to the proxy, so do the same from
    // the proxied object to the proxy.
    QObject::connect(proxied, signal_sig.constData(), this,
            signal_sig.constData());
}


// Called when QML has disconnected to a signal of the proxied object.
void QPyQmlObjectProxy::disconnectNotify(const QMetaMethod &sig)
{
    QByteArray signal_sig = signalSignature(sig);

    // The signal has actually been disconnected from the proxy, so do the same
    // from the proxied object to the proxy.
    QObject::disconnect(proxied, signal_sig.constData(), this,
            signal_sig.constData());
}


// Return what SIGNAL() would return for a method.
QByteArray QPyQmlObjectProxy::signalSignature(const QMetaMethod &signal)
{
    QByteArray signal_sig(signal.methodSignature());
    signal_sig.prepend('2');

    return signal_sig;
}


// Delegate to the real object.
const QMetaObject *QPyQmlObjectProxy::metaObject() const
{
    return !proxied.isNull() ? proxied->metaObject() : QObject::metaObject();
}


// Delegate to the real object.
void *QPyQmlObjectProxy::qt_metacast(const char *_clname)
{
    return !proxied.isNull() ? proxied->qt_metacast(_clname) : 0;
}


// Delegate to the real object.
int QPyQmlObjectProxy::qt_metacall(QMetaObject::Call call, int idx, void **args)
{
    if (idx < 0)
        return idx;

    // If the sender is the proxied object then it has emitted a signal.
    if (call == QMetaObject::InvokeMetaMethod && sender() == proxied)
    {
        const QMetaObject *proxied_mo = proxied->metaObject();

        // Relay the signal to QML.
        QMetaObject::activate(this, proxied_mo,
                idx - proxied_mo->methodOffset(), args);

        return idx - (proxied_mo->methodCount() - proxied_mo->methodOffset());
    }

    return !proxied.isNull() ? proxied->qt_metacall(call, idx, args) : QObject::qt_metacall(call, idx, args);
}


// Add a new Python type and return its number.
int QPyQmlObjectProxy::addType(PyTypeObject *type)
{
    pyqt_types.append(type);

    return pyqt_types.size() - 1;
}


// Create the Python instance.
void QPyQmlObjectProxy::createPyObject(QObject *parent)
{
    SIP_BLOCK_THREADS

    py_proxied = sipCallMethod(NULL, (PyObject *)pyqt_types.at(typeNr()), "D",
            parent, sipType_QObject, NULL);

    if (py_proxied)
        proxied = reinterpret_cast<QObject *>(
                sipGetAddress((sipSimpleWrapper *)py_proxied));
    else
        PyErr_Print();

    SIP_UNBLOCK_THREADS
}


// Resolve any proxy.
void *QPyQmlObjectProxy::resolveProxy(void *proxy)
{
    QObject *qobj = reinterpret_cast<QObject *>(proxy);

    // We have to search for proxy instances because we have subverted the
    // usual sub-class detection mechanism.
    if (proxies.contains(qobj))
        return static_cast<QPyQmlObjectProxy *>(qobj)->proxied.data();

    // It's not a proxy.
    return proxy;
}


// Create an instance of the attached properties.
QObject *QPyQmlObjectProxy::createAttachedProperties(PyTypeObject *py_type,
        QObject *parent)
{
    QObject *qobj = 0;

    SIP_BLOCK_THREADS

    PyObject *obj = sipCallMethod(NULL, (PyObject *)py_type, "D", parent,
            sipType_QObject, NULL);

    if (obj)
    {
        qobj = reinterpret_cast<QObject *>(
                sipGetAddress((sipSimpleWrapper *)obj));

        // It should always have a parent, but just in case...
        if (parent)
            Py_DECREF(obj);
    }
    else
    {
        PyErr_Print();
    }

    SIP_UNBLOCK_THREADS

    return qobj;
}


// Invoked when a class parse begins.
void QPyQmlObjectProxy::pyClassBegin()
{
    if (!py_proxied)
        return;

    SIP_BLOCK_THREADS

    bool ok = false;

    static PyObject *method_name = 0;

    if (!method_name)
#if PY_MAJOR_VERSION >= 3
        method_name = PyUnicode_FromString("classBegin");
#else
        method_name = PyString_FromString("classBegin");
#endif

    if (method_name)
    {
        PyObject *res = PyObject_CallMethodObjArgs(py_proxied, method_name,
                NULL);

        if (res)
        {
            if (res == Py_None)
                ok = true;
            else
                bad_result(res, "classBegin()");

            Py_DECREF(res);
        }
    }

    if (!ok)
        PyErr_Print();

    SIP_UNBLOCK_THREADS
}


// Invoked when a component parse completes.
void QPyQmlObjectProxy::pyComponentComplete()
{
    if (!py_proxied)
        return;

    SIP_BLOCK_THREADS

    bool ok = false;

    static PyObject *method_name = 0;

    if (!method_name)
#if PY_MAJOR_VERSION >= 3
        method_name = PyUnicode_FromString("componentComplete");
#else
        method_name = PyString_FromString("componentComplete");
#endif

    if (method_name)
    {
        PyObject *res = PyObject_CallMethodObjArgs(py_proxied, method_name,
                NULL);

        if (res)
        {
            if (res == Py_None)
                ok = true;
            else
                bad_result(res, "componentComplete()");

            Py_DECREF(res);
        }
    }

    if (!ok)
        PyErr_Print();

    SIP_UNBLOCK_THREADS
}


// Invoked to set the target property of a property value source.
void QPyQmlObjectProxy::pySetTarget(const QQmlProperty &target)
{
    if (!py_proxied)
        return;

    SIP_BLOCK_THREADS

    bool ok = false;

    static PyObject *method_name = 0;

    if (!method_name)
#if PY_MAJOR_VERSION >= 3
        method_name = PyUnicode_FromString("setTarget");
#else
        method_name = PyString_FromString("setTarget");
#endif

    if (method_name)
    {
        QQmlProperty *target_heap = new QQmlProperty(target);

        PyObject *py_target = sipConvertFromNewType(target_heap,
                sipType_QQmlProperty, 0);

        if (!py_target)
        {
            delete target_heap;
        }
        else
        {
            PyObject *res = PyObject_CallMethodObjArgs(py_proxied, method_name,
                    py_target, NULL);

            Py_DECREF(py_target);

            if (res)
            {
                if (res == Py_None)
                    ok = true;
                else
                    bad_result(res, "setTarget()");

                Py_DECREF(res);
            }
        }
    }

    if (!ok)
        PyErr_Print();

    SIP_UNBLOCK_THREADS
}


// Raise an exception for an unexpected result.
static void bad_result(PyObject *res, const char *context)
{
#if PY_MAJOR_VERSION >= 3
    PyErr_Format(PyExc_TypeError, "unexpected result from %s: %S", context,
            res);
#else
    PyObject *res_s = PyObject_Str(res);

    if (res_s != NULL)
    {
        PyErr_Format(PyExc_TypeError, "unexpected result from %s: %s", context,
                PyString_AsString(res_s));

        Py_DECREF(res_s);
    }
#endif
}


// The proxy type implementations.
#define QPYQML_PROXY_IMPL(n) \
QPyQmlObject##n::QPyQmlObject##n(QObject *parent) : QPyQmlObjectProxy(parent) \
{ \
    createPyObject(parent); \
} \
QObject *QPyQmlObject##n::attachedProperties(QObject *parent) \
{ \
    return createAttachedProperties(attachedPyType, parent); \
} \
void QPyQmlObject##n::classBegin() \
{ \
    pyClassBegin(); \
} \
void QPyQmlObject##n::componentComplete() \
{ \
    pyComponentComplete(); \
} \
void QPyQmlObject##n::setTarget(const QQmlProperty &target) \
{ \
    pySetTarget(target); \
} \
QMetaObject QPyQmlObject##n::staticMetaObject; \
PyTypeObject *QPyQmlObject##n::attachedPyType


QPYQML_PROXY_IMPL(0);
QPYQML_PROXY_IMPL(1);
QPYQML_PROXY_IMPL(2);
QPYQML_PROXY_IMPL(3);
QPYQML_PROXY_IMPL(4);
QPYQML_PROXY_IMPL(5);
QPYQML_PROXY_IMPL(6);
QPYQML_PROXY_IMPL(7);
QPYQML_PROXY_IMPL(8);
QPYQML_PROXY_IMPL(9);
QPYQML_PROXY_IMPL(10);
QPYQML_PROXY_IMPL(11);
QPYQML_PROXY_IMPL(12);
QPYQML_PROXY_IMPL(13);
QPYQML_PROXY_IMPL(14);
QPYQML_PROXY_IMPL(15);
QPYQML_PROXY_IMPL(16);
QPYQML_PROXY_IMPL(17);
QPYQML_PROXY_IMPL(18);
QPYQML_PROXY_IMPL(19);
QPYQML_PROXY_IMPL(20);
QPYQML_PROXY_IMPL(21);
QPYQML_PROXY_IMPL(22);
QPYQML_PROXY_IMPL(23);
QPYQML_PROXY_IMPL(24);
QPYQML_PROXY_IMPL(25);
QPYQML_PROXY_IMPL(26);
QPYQML_PROXY_IMPL(27);
QPYQML_PROXY_IMPL(28);
QPYQML_PROXY_IMPL(29);
QPYQML_PROXY_IMPL(30);
QPYQML_PROXY_IMPL(31);
QPYQML_PROXY_IMPL(32);
QPYQML_PROXY_IMPL(33);
QPYQML_PROXY_IMPL(34);
QPYQML_PROXY_IMPL(35);
QPYQML_PROXY_IMPL(36);
QPYQML_PROXY_IMPL(37);
QPYQML_PROXY_IMPL(38);
QPYQML_PROXY_IMPL(39);
QPYQML_PROXY_IMPL(40);
QPYQML_PROXY_IMPL(41);
QPYQML_PROXY_IMPL(42);
QPYQML_PROXY_IMPL(43);
QPYQML_PROXY_IMPL(44);
QPYQML_PROXY_IMPL(45);
QPYQML_PROXY_IMPL(46);
QPYQML_PROXY_IMPL(47);
QPYQML_PROXY_IMPL(48);
QPYQML_PROXY_IMPL(49);
QPYQML_PROXY_IMPL(50);
QPYQML_PROXY_IMPL(51);
QPYQML_PROXY_IMPL(52);
QPYQML_PROXY_IMPL(53);
QPYQML_PROXY_IMPL(54);
QPYQML_PROXY_IMPL(55);
QPYQML_PROXY_IMPL(56);
QPYQML_PROXY_IMPL(57);
QPYQML_PROXY_IMPL(58);
QPYQML_PROXY_IMPL(59);
