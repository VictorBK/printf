#include "holberton.h"

/**
 * print_str_rev - print string everything that is not %
 * @list: start of string.
 * Return: string length for count.
 */

int print_str_rev(va_list list)
{
	char *aux;

	aux = va_arg(list, char*);
	if (!aux)
		return (0);
	_print_rev_recursion(aux);
	return (_strlen(aux));
}

/**
 * print_rot_13 - print % in case that %% is typed into the _printf function
 * @list: % to print.
 *
 * Return: % char length for count.
 */

int print_rot_13(va_list list)
{
	int position = 0, count, f, counter = 0;
	char *s = va_arg(list, char*);
	char enco_in[53] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char enco_out[53] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	if (!s)
		s = "(null)";
	while (s[position])
	{
		f = 0;
		for (count = 0; count < 52; count++)
			if (enco_in[count] == s[position])
			{
				_putchar(enco_out[count]);
				count = 52;
				f = 1;
				counter++;
			}
		if (!f)
		{
			_putchar(s[position]);
			counter++;
		}
		position++;
	}
	return (counter);
}

/**
 * _pow - calculates an exponent
 * @base: base of exponent
 * @exponent: exponent of number
 *
 * Return: base ^ exponent
 */

static unsigned long _pow(unsigned int base, unsigned int exponent)
{
	unsigned int i;
	unsigned long ans = base;

	for (i = 1; i < exponent; i++)
		ans *= base;
	return (ans);
}


/**
 * print_p - prints an address
 * @list: address to print
 *
 * Return: number of characters to print
 */
int print_p(va_list list)
{
	int count = 0;
	unsigned int a[16];
	unsigned int i, sum;
	unsigned long n, m;
	char *str = "(nil)";

	n = va_arg(list, unsigned long);

	if (n == 0)
	{
		for (i = 0; str[i]; i++)
		{
			_putchar(str[i]);
			count++;
		}
		return (count);
	}
	_putchar('0');
	_putchar('x');
	count = 2;
	m = _pow(16, 15);
	a[0] = n / m;
	for (i = 1; i < 16; i++)
	{
		m /= 16;
		a[i] = (n / m) % 16;
	}
	for (i = 0, sum = 0; i < 16; i++)
	{
		sum += a[i];
		if (sum || i == 15)
		{
			if (a[i] < 10)
				_putchar('0' + a[i]);
			else
				_putchar('0' + ('a' - ':') + a[i]);
			count++;
		}
	}
	return (count);
}
