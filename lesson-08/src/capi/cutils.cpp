#include <iostream>
#include <Python.h>

PyObject* cutils_sum(PyObject* self, PyObject* args)
{
    PyObject* list;
    long list_size;
    if (! PyArg_ParseTuple(args, "Ol", &list, &list_size)) {
        std::cerr << "Failed to parse arguments" << std::endl;
        return nullptr;
    }
    long res = 0;
    for (long i = 0; i < list_size; ++i) {
        PyObject* num = PyList_GetItem(list, i);
        res += PyLong_AsLong(num);
    }

    return Py_BuildValue("l", res);
}

int _fibonacci(int n)
{
    if (n < 2)
        return 1;
    return _fibonacci(n-2) + _fibonacci(n-1);
}

PyObject* cutils_fibonacci(PyObject* self, PyObject* args)
{
    int n;
    if (!PyArg_ParseTuple(args, "i", &n)) {
        std::cerr << "Failed to parse arguments" << std::endl;
        return nullptr;
    }
    int res = _fibonacci(n);
    return Py_BuildValue("i", res);
}

static PyMethodDef module_funcs[] = {
  {"sum", cutils_sum, METH_VARARGS, "Accumulate elements of a list."},
  {"fibonacci", cutils_fibonacci, METH_VARARGS, "Calculate n-th element of Fibonacci sequence."},
  {NULL, NULL, 0, NULL}
};

static PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "cutils",
    "Module with different utils.",
    -1,
    module_funcs
};

PyMODINIT_FUNC PyInit_cutils()
{
    return PyModule_Create(&module);
}
