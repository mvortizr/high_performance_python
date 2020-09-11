#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdlib.h>

/*Headers*/
static PyObject* HelloError;
static char* hello(char* what); 


static PyObject* hello_wrapper(PyObject* self, PyObject* args)
{
  char* input;
  

  // parse arguments
  if (!PyArg_ParseTuple(args, "s", &input)) {
    return NULL;
  }

  // run the actual function
  hello(input);
  

  return Py_None;
}

static char* hello(char* what){
   printf("Hello %s", what);
}


static PyMethodDef HelloMethods[] = {
 { "hello", hello_wrapper, METH_VARARGS, "Say hello" },
 { NULL, NULL, 0, NULL }
};


static PyModuleDef hellomodule = {
    PyModuleDef_HEAD_INIT,
    "hello",
    "An example Python C extension module.",
    -1,
    HelloMethods,
};

PyMODINIT_FUNC PyInit_hello() {
    PyObject* module;

    module = PyModule_Create(&hellomodule);
    if (module == NULL) {
        return NULL;
    }
    HelloError = PyErr_NewException("hello.Error", NULL, NULL);
    Py_INCREF(HelloError); 
    PyModule_AddObject(module, "Error", HelloError);
    return module;
}