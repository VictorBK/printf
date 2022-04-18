#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int _putchar(char c)
{
	return(write(1, &c, 1));
}

int _printf(const char *format, ...)
{
	va_list args;
	char *p;
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
		++p;
		count = get_print_func(p, args);

	}
	va_end(args);
	return count;
}

int print_percent(va_list ap)
{
	(void)ap;
	return (_putchar('%'));
}

int print_char(va_list ap)
{
	unsigned int sum = 0, ch = va_arg(ap, int);
	sum += _putchar(ch);
	return (sum);
}

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

int get_print_func(char *s, va_list ap)
{
	int (*f)(va_list) = get_specifier(s);
	if (f)
	{
		return (f(ap));
	}
	return (0);
}

int _puts(char *str)
{
	char *a = str;

	while (*str)
	{
		_putchar(*str++);
	}
	return (str - a);
}

int print_string(va_list ap)
{
	char *str = va_arg(ap, char *);
	unsigned int sum = 0;
	sum += _puts(str);
	return (sum);
}

