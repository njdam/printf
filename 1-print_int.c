#include "main.h"

/**
 * print_int - Prints an integer with specified format flags
 *
 * @arg: List of arguments
 * @buffer: Buffer to store printed string
 * @flags: Format flags
 * @width: Minimum field width
 * @precision: Precision (number of digits after decimal point)
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */
int print_int(va_list arg, char buffer[],
		int flags, int width, int precision, int size)
{
	/* Start at second to last index to leave room for sign character */
	int i = BUFFER_SIZE - 2;
	int is_negative = 0;
	long int num = va_arg(arg, long int);
	unsigned long int unsigned_num;

	/* Convert the number based on the size specifier */
	num = convert_size_number(num, size);
	if (num == 0)
		buffer[i--] = '0';

	/* Null-terminate the buffer */
	buffer[BUFFER_SIZE - 1] = '\0';
	unsigned_num = (unsigned long int)num;

	if (num < 0)
	{
		unsigned_num = (unsigned long int)((-1) * num);
		is_negative = 1;
	}

	/* Convert num to string and store it in buffer */
	while (unsigned_num > 0)
	{
		buffer[i--] = (unsigned_num % 10) + '0';
		unsigned_num /= 10;
	}
	i++;

	/* Write the number string with format flags */
	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}
