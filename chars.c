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
/**
 * print_s - prints a string
 * @s: string to print
 *
 * Return: number of chars printed
 */
int print_s(va_list s)
{
	char *str = va_arg(s, char *);
	int num;

	if (str == NULL)
		str = "(null)";
	for (num = 0; str[num]; num++)
	{
		_putchar(str[num]);
	}
	return (num);
}


/**
 * print_S - prints a string and nonprintable character ascii values
 * @S: string to print
 *
 * Return: number of chars printed
 */
int print_S(va_list S)
{
	unsigned int i;
	int num = 0;
	char *str = va_arg(S, char *);

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			num += 2;
			num += hex_print(str[i]);
		}
		else
		{
			_putchar(str[i]);
			num++;
		}
	}
	return (num);
}

/**
 * print_r - prints astring in reverse
 * @r: string to print
 *
 * Return: number of chars printed
 */
int print_r(va_list r)
{
	char *str;
	int x, num = 0;

	str = va_arg(r, char *);
	if (str == NULL)
		str = ")llun(";
	for (x = 0; str[x]; x++)
		;
	for (x -= 1; x >= 0; x--)
	{
		_putchar(str[x]);
		num++;
	}
	return (num);
}
