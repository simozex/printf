#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
* struct format - struct
*@specifiers: struct format
*@f: the function
*/

typedef struct op
{
	char op;
	int (*f)(va_list);
} op_t;

/*prototypes*/
int _printf(const char *format, ...);
int get_function(char s, va_list args);
int _putchar(char c);

/*conversion*/
int printchar(va_list args);
int printstring(va_list args);
int printdigit(va_list args);
int printsign(va_list args);

#endif
