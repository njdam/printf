#include "main.h"

/**
 * print_pointer - This function prints the value of a variable in a pointer
 *
 * @arg: Is the list of arguments passed
 * @buffer: Is a buffer array for handling the way of printing
 * @flags: Are the bitwise flags
 * @width: Is the minimum width for the field
 * @precision: Is the precision specification
 * @size: Is the size specification
 *
 * Return: The length of the printed string
 */
int print_pointer(va_list arg, char buffer[],
		int flags, int width, int precision, int size)
{
	char padding_char = ' ';
	int buffer_index = BUFF_SIZE - 2, length = 2;
	unsigned long address_num;
	char hex_map[] = "0123456789abcdef";
	void *address = va_arg(arg, void *);

	UNUSED(width);
	UNUSED(size);
	/* If pointer is null, print (nil) and return 5 */
	if (address == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	/* Convert the pointer value to hexadecimal */
	address_num = (unsigned long) address;
	while (address_num > 0)
	{
		buffer[buffer_index--] = hex_map[address_num % 16];
		address_num /= 16;
		length++;
	}

	/* Check for flags */
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padding_char = '0';

	if (flags & (F_PLUS | F_SPACE))
		length++;

	/* Set index to point to the first character to be printed */
	buffer_index++;

	return (write_pointer(buffer, buffer_index, length, width,
				flags, padding_char, padding_char != ' ', 1));
}

/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @arg: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Bitwise flags
 * @width: Minimum field width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int print_non_printable(va_list arg, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(arg, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	/* If string is null, print (null) and return 6 */
	if (str == NULL)
		return (write(1, "(null)", 6));

	/* Check each character and convert non-printables to hex codes */
	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hex_code(str[i], buffer, i + offset);
		i++;
	}
	buffer[i + offset] = '\0';

	/* Write the converted string to the output buffer */
	return (write(1, buffer, i + offset));
}
