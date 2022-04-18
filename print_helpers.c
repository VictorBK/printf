#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 */
int _putchar(char c)
{
	return(write(1, &c, 1));
}

/**
 * print_percent - prints string
 * @ap: argument pointer
 *
 * Return: number chars printed
 */
int print_percent(va_list ap)
{
	(void)ap;
	return (_putchar('%'));
}

/**
 * print_char - prints character
 * @ap: argument pointer
 *
 * Retun: number chars printed
 */
int print_char(va_list ap)
{
	unsigned int sum = 0, ch = va_arg(ap, int);
	sum += _putchar(ch);
	return (sum);
}
