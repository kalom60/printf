#include "main.h"
#include <stdlib.h>

/**
 * print_c - prints a char
 * @c: char to print
 *
 * Return: always 1
 */
int print_c(va_list c)
{
	char ch = (char)va_arg(c, int);

	_putchar(ch);
	return (1);
}

/**
 * hex_print - prints a char's ascii value in hex
 * @c: char to print
 *
 * Return: number of chars printed (always 2)
 */
static int hex_print(char c)
{
	char diff = 'A' - ':';
	char d[2];
	int num;

	d[0] = c / 16;
	d[1] = c % 16;
	for (num = 0; num < 2; num++)
	{
		if (d[num] >= 10)
			_putchar('0' + diff + d[num]);
		else
			_putchar('0' + d[num]);
	}
	return (num);
}
