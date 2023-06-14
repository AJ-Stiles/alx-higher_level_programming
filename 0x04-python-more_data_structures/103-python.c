#include <Python.h>
#include <stdio.h>

/**
 * print_python_list - Prints basic info about a Python list
 * @p: Pointer to the Python list object
 */
void print_python_list(PyObject *p)
{
	Py_ssize_t i, size;

	printf("[*] Python list info\n");
	size = PyList_Size(p);
	printf("[*] Size of the Python List = %zd\n", size);
	printf("[*] Allocated = %zd\n", ((PyListObject *)p)->allocated);

	for (i = 0; i < size; i++)
	{
		PyObject *element = PyList_GetItem(p, i);
		const char *type = element->ob_type->tp_name;

		printf("Element %zd: %s\n", i, type);
	}
}

/**
 * print_python_bytes - Prints basic info about a Python bytes object
 * @p: Pointer to the Python bytes object
 */
void print_python_bytes(PyObject *p)
{
	Py_ssize_t i, size;
	const char *str;

	printf("[.] bytes object info\n");
	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}

	size = PyBytes_Size(p);
	str = PyBytes_AsString(p);
	printf("  size: %zd\n", size);
	printf("  trying string: %s\n", str ? str : "(no allocation)");
	printf("  first %zd bytes:", size < 10 ? size : 10);
	for (i = 0; i < (size < 10 ? size : 10); i++)
		printf(" %02x", (unsigned char)str[i]);
	printf("\n");
}

