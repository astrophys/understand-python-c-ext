/*********************************************************************
AUTHOR  : Ali Snedden 
DATE    : 4/11/22
LICENSE : MIT
PURPOSE :
INSTALL : 
    1. Create new Virtual Env. :
        a) python3 -m venv ~/.local/virtualenv/py-ext-test
        #) python setup.py install
REFERENCES: 
    1. https://docs.python.org/3/library/venv.html
    #. https://stackoverflow.com/a/59292985/4021436
***********************************************************************/
#include <Python.h>

// The C function that actually does the work
static PyObject * hello_c_func(PyObject *self, PyObject *args)
{
    const char *name;

    if (!PyArg_ParseTuple(args, "s", &name))
    {
        return NULL;
    }
    
    printf("Hello %s!\n", name);

    Py_RETURN_NONE;
}


// This defines the function used by hellopymod.
static PyMethodDef HelloMethods[] = {
    {"hello_py_func", hello_c_func, METH_VARARGS, "Greet an entity."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef hellopymod =
{
    PyModuleDef_HEAD_INIT,
    "hellopymod",     /* name of module */
    "",          /* module documentation, may be NULL */
    -1,          /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    HelloMethods
};

PyMODINIT_FUNC PyInit_hellopymod(void)
{
    return PyModule_Create(&hellopymod);
}
