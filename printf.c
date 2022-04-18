#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
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
 * _printf - produces output according to a format
 * @format: a pointer to the format string
 *
 * Return: on success, returns the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	char *p;
	char *start;
	int count = 0;
	va_start(args, format);


	if (!format || (format[0] == '%' && !format[1]))
	{
		return (-1);
	}
	if (format[0] == '%' && format[1] == ' ' && !format[2])
	{
		return (-1);
	}

	for (p = (char *)format; *p; p++)
	{
		if (*p != '%')
		{
			count += _putchar(*p);
			continue;
		}
		start = p;
		++p;
		if (!get_specifier(p))
		{
			count += print_from_to(start, p, 0);
		}
		else
		{
			count += get_print_func(p, args);
		}

	}
	va_end(args);
	return count;
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

/**
 * get_specifier - fints the format function
 * @s: the format string
 *
 * Return: the number of bytes printed
 */
int (*get_specifier(char *s))(va_list ap)
{
	specifier_t specifiers[] = {
		{"%", print_percent},
		{"c", print_char},
		{"s", print_string},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}

	return (NULL);
}

/**
 * get_print_func - finds the format func
 * @s: the format string
 * @ap: argument pointer
 *
 * Return: the number of bytes printed
 */
int get_print_func(char *s, va_list ap)
{
	int (*f)(va_list) = get_specifier(s);
	if (f)
	{
		return (f(ap));
	}
	return (0);
}

/**
 * _puts - prints a string with newline
 * @str: the string to print
 *
 * Return: int
 */
int _puts(char *str)
{
	char *a = str;

	while (*str)
	{
		_putchar(*str++);
	}
	return (str - a);
}

/**
 * print_string - prints string
 * @ap: argument pointer
 *
 * Return: number chars printed
 */
int print_string(va_list ap)
{
	char *str = va_arg(ap, char *);
	unsigned int sum = 0;
	sum += _puts(str);
	return (sum);
}

/**
 * print_from_to - prints range of char addresses
 * @start: starting address
 * @stop: stopping address
 * @except: except address
 *
 * Return: number bytes printed
 */
int print_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

