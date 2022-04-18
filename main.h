#ifndef main_h
#define main_h
#include <stdarg.h>

typedef struct specifier
{
	char *specifier;
	int (*f)(va_list);
}specifier_t;

int _putchar(char c);
int print_percent(va_list ap);
int get_print_func(char *s, va_list ap);
int (*get_specifier(char *s))(va_list ap);
int _printf(const char *format, ...);
int print_string(va_list ap);
int _puts(char *str);

#endif

