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

