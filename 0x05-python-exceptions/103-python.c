#include "Python.h"
#include <stdio.h>
#include <float.h>

void print_python_list(PyObject *p);
void print_python_bytes(PyObject *p);
void print_python_float(PyObject *p);

/**
 * print_python_list - Prints information about Python list. Such as size, and
 * amount of memory allcoated. What type each element is and if it is a type
 * 'bytes' or 'float', print additional information on the element.
 *
 * @p: Pointer to a Python object.
 *
 * Return: void.
 */
void print_python_list(PyObject *p)
{
	Py_ssize_t p_size;
	Py_ssize_t idx;
	PyObject *n;

	printf("[*] Python list info\n");
	if (PyList_Check(p))
	{
		p_size = ((PyVarObject *)(p))->ob_size;
		printf("[*] Size of the Python List = %zd\n", p_size);
		printf("[*] Allocated = %zd\n", ((PyListObject *) (p))->allocated);
		for (idx = 0; idx < p_size; idx++)
		{
			n = ((PyListObject *) (p))->ob_item[idx];
			printf("Element %zd: %s\n", idx, (n->ob_type)->tp_name);
			if (PyBytes_Check(n))
				print_python_bytes(n);
			else if (PyFloat_Check(n))
				print_python_float(n);
		}
	}
	else
	{
		printf("  [ERROR] Invalid List Object\n");
	}
	fflush(stdout);
}
