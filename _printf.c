#include "main.h"
#include <stdlib.h>

/**
 * get_print - selects the right printing function
 * depending on the conversion specifier passed to _printf
 * @s: character that holds the conversion specifier
 * Description: the function loops through the structs array
 * func_arr[] to find a match between the specifier passed to _printf
 * and the first element of the struct, and then the approriate
 * printing function
 * Return: a pointer to the matching printing function
 */
int (*get_print(char s))(va_list, mods *)
{
	ph func_arr[] = {
		{'i', print_int},
		{'s', print_string},
		{'c', print_char},
		{'d', print_int},
		{'u', print_unsigned},
		{'x', print_hex},
		{'X', print_hex_big},
		{'b', print_binary},
		{'o', print_octal},
		{'R', print_rot13},
		{'r', print_rev},
		{'S', print_bigS},
		{'p', print_address},
		{'%', print_percent},
		{NUL, NULL}
		};

	register short i;

	for (i = 0; func_arr[i].c; i++)
		if (func_arr[i].c == s)
			return (func_arr[i].f);
	return (NULL);
}


/**
 * _printf - prints almost anything
 * @format: list of argument types passed to the function
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	register short len = 0;
	int (*printFunc)(va_list, mods *);
	mods prefixes = PF_INIT;
	const char *p = format;
	va_list arguments;

	va_start(arguments, format);
	assert(invalidInputs(p));
	for (; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				len += _putchar('%');
				continue;
			}
			while (get_flags(*p, &prefixes))
				p++;
			printFunc = get_print(*p);
			len += (printFunc)
				? printFunc(arguments, &prefixes)
				: _printf("%%%c", *p);
		} else
			len += _putchar(*p);
	}
	_putchar(FLUSH);
	va_end(arguments);
	return (len);
}

