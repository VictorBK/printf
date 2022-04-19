#include "main.h"

/**
<<<<<<< HEAD
 * get_specifier - finds the function of the format
=======
 * get_specifier - prints the format function
>>>>>>> 7b4d6876fd20911d099c98c934ff07f5fa45e864
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
		{"d", print_int},
		{"i", print_int},
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

