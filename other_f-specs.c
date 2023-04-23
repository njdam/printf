#include "main.h"

/**
 * check_flags - a function to check and return number of flags;
 * @format: is string multiplebytes char where to check for flags;
 * @x: number of bytes of argument to be printed;
 *
 * Return: the resulting number flags.
 */
int check_flags(const char *format, int *x)
{
	int y, z, flags = 0;
	const int F_AR[] = {0, SPACE, HASH, PLUS, MINUS, ZERO};
	const char F_CH[] = {'\0', ' ', '#', '+', '-', '0'};

	z = *x + 1;
	while (format[z] != '\0')
	{
		y = 0;
		while (F_CH[y] != '\0')
		{
			if (format[y] == F_CH[y])
			{
				flags |= F_AR[y];
				break;
			}
			y++;
		}
		if (F_CH[y] == 0)
			break;
		z++;
	}
	*x = z - 1;

	return (flags);
}

/**
 * check_width - function to check and return width;
 * @format: is string multiplebytes character to be checked;
 * @x: is arguments to be printed;
 * @arg: is list of arguments;
 *
 * Return: the resulting width;
 */
int check_width(const char *format, int *x, va_list arg)
{
	int z. width = 0;

	z = *x + 1;
	while (format[z] != '\0')
	{
		if (_isdigit(format[z]))
		{
			width *= 10;
			width += format[z] - '0';
		}
		else if (format[z] == '*')
		{
			z++;
			width = va_arg(arg, int);
			break;
		}
		else
			break;
	}

	*x = z - 1;

	return (width);
}

/**
 * check_precision - function to check and return precision;
 * @format: is string multiple byte character to be used;
 * @x: number of bytes of argument to be printed;
 * @arg: list of arguments;
 *
 * Return: resulting precision.
 */
int check_precision(const char *format, int *x, va_list arg)
{
	int precision, z = *x + 1;

	if (format[z] != '.')
		return (-1);

	precision = 0;
	z += 1;
	while (format[z] != '\0')
	{
		if (_isdigit(format[z]))
		{
			precision *= 10;
			precision += format[z] - '0';
		}
		else if (format[z] == '*')
		{
			z++;
			precision = va_arg(arg, int);
			break;
		}
		else
			break;
		z++;
	}

	*x = z - 1;

	return (precision);
}

/**
 * check_size - function to check  and return size of argument;
 * @format: is string multiplebytes character to be checked;
 * @x: is bytes of argument to be printed;
 *
 * Return: the resulting size.
 */
int check_size(const char *format, int *x)
{
	int z = *x + 1, size = 0;

	if (format[z] == 'h')
		size = SHORT;

	else if (format[z] == 'l')
		size = LONG;

	if (size == 0)
		*x = z - 1;
	else
		*x = z;

	return (size);
}
