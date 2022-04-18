#include "main.h"

/**
 * convert - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convert(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	unsigned long n;
	char sign = 0;
	char *ptr;
	(void)flags;

	if (num < 0)
	{
		n = -num;
		sign = '-';
	}
	else
	{
		n = num;
	}
	array = "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * print_number - prints a number with options
 * @str: the base number as a string
 *
 * Return: chars printed
 */
int print_number(char *str)
{

	return (print_number_right_shift(str));
}

/**
 * print_number_right_shift - prints a number with options
 * @str: the base number as a string
 *
 * Return: chars printed
 */
int print_number_right_shift(char *str)
{
	unsigned int n = 0;

	n += _puts(str);

	return (n);
}

/**
 * print_int - prints integer
 * @ap: argument pointer
 *
 * Return: number chars printed
 */
int print_int(va_list ap)
{
	long l;

	l = (int)va_arg(ap, int);

	return (print_number(convert(l, 10, 0)));
}

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

