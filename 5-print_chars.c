#include "main.h"

/**
 * print_string - s function is for printing strings
 * @arg: Is a list of arguments passed to the function
 * @buffer: Is the buffer array for handling the way of printing
 * @flags: Is for calcutating active flags
 * @width: Is for width specification
 * @precision: Is for precision specification
 * @size: Is for size specification
 * Return: The length of printed string
 */
int print_string(va_list arg, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = 0;
	char *str = va_arg(arg, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	/* check if string is null */
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}
	/* get length of string */
	while (str[length] != '\0')
		length++;
	/* handle precision */
	if (precision >= 0 && precision < length)
		length = precision;
	/* handle width */
	if (width > length)
	{
		return (justify_string(str, length, width, flags));
	}
	/* no width and no precision */
	return (write(1, str, length));
}

/**
 * justify_string - Writes a string justified left or right
 * @str: The string to write
 * @length: The length of the string
 * @width: The desired width
 * @flags: The active flags, including the F_MINUS flag for left justification
 * Return: The number of characters written
 */
int justify_string(char *str, int length, int width, int flags)
{
	int i, written = 0;

	if (flags & MINUS)
	{
		/* left justify */
		written += write(1, str, length);
		for (i = width - length; i > 0; i--)
			written += write(1, " ", 1);
	}
	else
	{
		/* right justify */
		for (i = width - length; i > 0; i--)
			written += write(1, " ", 1);
		written += write(1, str, length);
	}

	return (written);
}

/**
 * print_char - This function is for printing a character
 * @arg: Is the list of arguments passed to the function
 * @buffer: Is the buffer array for handling the way of printing
 * @flags: Is for calculating active flags
 * @width: Is for width specification
 * @precision: Is for precision specification
 * @size: Is for size specification
 * Return: The length of printed string
 */
int print_char(va_list arg, char buffer[],
		int flags, int width, int precision, int size)
{
	char c = va_arg(arg, int);

	return (write_char(c, buffer, flags, width, precision, size));
}
/**
 * print_percent - This function is for printing a '%'
 * @arg: Is the list of arguments passed
 * @buffer: Is a buffer array for handling the way of printing
 * @flags: Is for calculating active flags
 * @width: Is for width specification
 * @precision: Is for precision specification
 * @size: Is for size specification
 * Return: The length of printed string
 */
int print_percent(va_list arg, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(arg);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
