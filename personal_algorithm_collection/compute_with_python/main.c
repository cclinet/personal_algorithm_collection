#define PY_SSIZE_T_CLEAN

#include <Python.h>

enum Operation {
    ADD, SUBTRACT, MULTIPLY, DIVIDE
};

typedef enum Operation operation_t;

PyObject *str_to_decimal(PyObject *decimal_module, char *str) {
    PyObject *decimal_class = PyObject_GetAttrString(decimal_module, "Decimal");
    PyObject *value = PyUnicode_FromString(str);
    PyObject *decimal = PyObject_CallOneArg(decimal_class, value);
    Py_DECREF(decimal_class);
    Py_DECREF(value);
    return decimal;
}


char *decimal_to_str(PyObject *decimal) {
    PyObject *str = PyObject_Str(decimal);
    char *result = (char *) PyUnicode_AsUTF8(str);
    Py_DECREF(str);
    return result;
}

char *binary_operation(PyObject *decimal_module, char *a, char *b, operation_t operation) {
    PyObject *decimal_a = str_to_decimal(decimal_module, a);
    PyObject *decimal_b = str_to_decimal(decimal_module, b);
    PyObject *(*operate)(PyObject *, PyObject *);
    switch (operation) {
        case ADD:
            operate = PyNumber_Add;
            break;
        case SUBTRACT:
            operate = PyNumber_Subtract;
            break;
        case MULTIPLY:
            operate = PyNumber_Multiply;
            break;
        case DIVIDE:
            operate = PyNumber_TrueDivide;
            break;
    }
    PyObject *decimal_result = operate(decimal_a, decimal_b);
    char *result = decimal_to_str(decimal_result);
    Py_DECREF(decimal_a);
    Py_DECREF(decimal_b);
    Py_DECREF(decimal_result);
    return result;
}


char *add(PyObject *decimal_module, char *a, char *b) {
    return binary_operation(decimal_module, a, b, ADD);
}

char *subtract(PyObject *decimal_module, char *a, char *b) {
    return binary_operation(decimal_module, a, b, SUBTRACT);
}

char *multiply(PyObject *decimal_module, char *a, char *b) {
    return binary_operation(decimal_module, a, b, MULTIPLY);
}

char *divide(PyObject *decimal_module, char *a, char *b) {
    return binary_operation(decimal_module, a, b, DIVIDE);
}

char *log_(PyObject *decimal_module, char *a, char *b) {
    PyObject *decimal_a = str_to_decimal(decimal_module, a);
    PyObject *decimal_b = str_to_decimal(decimal_module, b);
    PyObject *ln_func_a = PyObject_GetAttrString(decimal_a, "ln");
    PyObject *ln_func_b = PyObject_GetAttrString(decimal_b, "ln");
    Py_DECREF(decimal_a);
    Py_DECREF(decimal_b);
    PyObject *log_a = PyObject_CallNoArgs(ln_func_a);
    PyObject *log_b = PyObject_CallNoArgs(ln_func_b);
    Py_DECREF(ln_func_a);
    Py_DECREF(ln_func_b);
    PyObject *decimal_result = PyNumber_TrueDivide(log_a, log_b);
    char *result = decimal_to_str(decimal_result);
    Py_DECREF(log_a);
    Py_DECREF(log_b);
    Py_DECREF(decimal_result);
    return result;
}

int main() {
    Py_Initialize();
    PyObject *decimal_module = PyImport_ImportModule("decimal");
    char *add_result = divide(decimal_module, "0.1", "0.2");
    printf("add: %s\n", add_result);
    char *log_result = log_(decimal_module, "100", "10");
    printf("log: %s\n", log_result);
    Py_Finalize();
    return 0;
}
