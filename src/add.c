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
static PyObject * add_c_func(PyObject *self, PyObject *args)
{
    int a=0;
    int b=0;

    //printf("%s", args);

    // How does it write to the pointer
    if (!PyArg_ParseTuple(args, "ii", &a, &b))
    {
        return NULL;
    }
    
    printf("%i\n", a+b);

    Py_RETURN_NONE;
}


// This defines the function used by 
static PyMethodDef AddMethods[] = {
    {"add_py_func", add_c_func, METH_VARARGS, "Add two numbers."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef addpymod =
{
    PyModuleDef_HEAD_INIT,
    "addpymod",     /* name of module */
    "",          /* module documentation, may be NULL */
    -1,          /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    AddMethods
};

PyMODINIT_FUNC PyInit_addpymod(void)
{
    return PyModule_Create(&addpymod);
}
