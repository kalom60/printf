#include "main.h"

/**
 * print_b - takes an unsigned int and prints it in binary notation
 * @b: unsigned in to print
 *
 * Return: number of digits printed
 */
int print_b(va_list b)
{
	unsigned int n, m, i, total;
	unsigned int a[32];
	int num;

	n = va_arg(b, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, total = 0, num = 0; i < 32; i++)
	{
		total += a[i];
		if (total || i == 31)
		{
			_putchar('0' + a[i]);
			num++;
		}
	}
	return (num);
}

