#include "main.h"

/**
 * print_handler - a function to print any type of argument;
 * @format: is multibytes character string to be used;
 * @x: is number of arguments to be printed;
 * @arg: is list of arguments;
 * @buffer: is an array buffer as Random Access Memmory for print;
 * @flags: is number of active flags;
 * @width: is resulting width of format specification;
 * @precision: is resulting precision of format specification;
 * @size: is size of a given argument;
 *
 * Return: resulted format type otherwise value -1 or 1.
 */
int print_handler(const char *format, int *x, va_list arg, char buffer[],
		int flags, int width, int precision, int size)
{
	fmt_func fmt_type[] = {
		{'%', print_percent}, {'c', print_char}, {'s', print_string},
		{'u', print_uns}, {'i', print_int}, {'d', print_int},
		{'b', print_binary}, {'o', print_octal}, {'x', print_haxadec},
		{'X', print_upper_hexa}, {'p', print_pointer}, {'r', print_rev},
		{'S', print_non_printable}, {'R', print_rot13}, {'\0', NULL}
	};
	int z, ulen = 0;

	z = 0;
	while (fmt_type[z].format != '\0')
	{
		if (format[*x] == fmt_type[z].format)
			return (fmt_type[z].func(arg, buffer, flags, width,
						precision, size));
		z++;
	}
	if (fmt_type[z].format == '\0')
	{
		if (format[*x] == '\0')
			return (-1);
		ulen += write(1, "%%", 1);
		if (format[*x] == ' ')
			ulen += write(1, " ", 1);
		else if (width)
		{
			--(*x);
			while (format[*x] != ' ' && format[*x] != '%')
				--(*x);
			if (format[*x] == ' ')
				--(*x);
			return (1);
		}
		ulen += write(1, &format[*x], 1);
		return (ulen);
	}

	return (-1);
}
