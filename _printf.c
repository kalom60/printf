#include "main.h"
#include <stdlib.h>

/**
 * check_for_specifiers - check for a valid format specifier
 * @format: possible format specifier
 *
 * Return: pointer to valid function or NULL
 */
static int (*check_for_specifiers(const char *format))(va_list)
{
	unsigned int i;
	print_t pt[] = {
		{"i", print_i},
		{"d", print_d},
		{"u", print_u},
		{"b", print_b},
		{"S", print_S},
		{"r", print_r},
		{"R", print_R},
		{"o", print_o},
		{"x", print_x},
		{"c", print_c},
		{"s", print_s},
		{"X", print_X},
		{"p", print_p},
		{NULL, NULL}
	};

	for (i = 0; pt[i].t != NULL; i++)
	{
		if (*(pt[i].t) == *format)
		{
			break;
		}
	}
	return (pt[i].f);
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
