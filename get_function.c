#include "main.h"

/**
*get_function - function.
* @t_step: conversion specifiers.
* @args: arguments.
* Return: char count.
*/

int get_function(char t_step, va_list args)
{
	int i = 0;
	int count = 0;

	op_t step[] = {
		{'c', printchar},
		{'s', printstring},
		{'%', printsign},
		{'d', printdigit},
		{'i', printdigit},
		{0, NULL}
	};

	while (step[i].op)
	{
		if (t_step == step[i].op)
			count += step[i].f(args);
		i++;
	}

	if (count == 0)
	{
		count += _putchar('%');
		count += _putchar(t_step);
	}

	return (count);
}

#include "main.h"
#include <unistd.h>

/**
*printchar - print char
*@args: argument.
*Return: count chars.
*/

int printchar(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);

	return (1);
}

#include "main.h"
#include <unistd.h>

/**
*printdigit - print integers.
*@args: argument.
*Return: count chars.
*/

int printdigit(va_list args)
{
	int decimal = 1;
	int count = 0;
	long int digit = va_arg(args, int);
	long int digit2;

	if (digit < 0)
	{
		count += _putchar('-');
		digit *= -1;
	}

	if (digit < 10)
		return (count += _putchar(digit + '0'));

	digit2 = digit;

	while (digit2 > 9)
	{
		decimal *= 10;
		digit2 /= 10;
	}
	while (decimal >= 1)
	{
		count += _putchar(((digit / decimal) % 10) + '0');
		decimal /= 10;
	}

	return (count);
}

#include "main.h"
#include <unistd.h>

/**
*printsign - print sign.
*@args: arguments.
* Return: count chars.
*/

int printsign(va_list args)
{
	(void)args;

	_putchar('%');

	return (1);
}

#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
*printstring - print string.
*@args: argument.
*Return: character count.
*/

int printstring(va_list args)
{
	int i;
	int count = 0;
	char *str = va_arg(args, char *);

	if (!str)
		str = "(null)";

	if (str[0] == '\0')
		return (-1);

	for (i = 0; str[i] != '\0'; i++)
		count += _putchar(str[i]);

	return (count);
}
