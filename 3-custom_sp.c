#include "main.h"

/**
 * print_uns - This function prints an unsigned number in decimal format
 *
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Is for width specification
 * @precision: Is for precision specification
 * @size: Is for size specification
 *
 * Return: Number of characters printed
 */
int print_uns(va_list args, char buffer[], int flags,
		int width, int precision, int size)
{
	int buffer_index = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);

	num = convert_size_unsgnd(num, size);

	/* If the number is zero, print it as '0' */
	if (num == 0)
		buffer[buffer_index--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	/* Convert the number to a string and add each to the buffer */
	while (num > 0)
	{
		buffer[buffer_index--] = (num % 10) + '0';
		num /= 10;
	}

	buffer_index++;

	/* Write the unsigned number to the buffer */
	return (write_unsgnd(0, buffer_index, buffer, flags, width, precision, size));
}

/**
 * print_octal - This function prints an unsigned number in octal form
 *
 * @arg: Is a list of arguments passed
 * @buffer: Is a buffer array for handling the way of printing
 * @flags: Is for calculating all active flags
 * @width: Is the number length specification
 * @precision: Is for specifying numbers after the .
 * @size: Is the size specifier
 *
 * Return: The number of printed characters
 */
int print_octal(va_list arg, char buffer[],
		int flags, int width, int precision, int size)
{
	int index = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(arg, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	/* Convert number based on size specifier */
	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer[index--] = '0';

	/* Set null terminator for buffer */
	buffer[BUFFER_SIZE - 1] = '\0';

	/* Convert number to octal and store in buffer */
	while (num > 0)
	{
		buffer[index--] = (num % 8) + '0';
		num /= 8;
	}

	/* Handle case where '#' flag is set and number is not 0 */
	if (flags & F_HASH && init_num != 0)
		buffer[index--] = '0';
	index++;

	/* Write buffer to output stream and return size of printed string */
	return (write_unsgnd(0, index, buffer, flags, width, precision, size));
}
/**
 * print_hexadec - This function prints unsigned number as hexadecimal
 *
 * @arg: Is the list of arguments passed
 * @buffer: Is a buffer array for handling the way of printing
 * @flags:  Is for calculating active flags
 * @width: Is for specifying length
 * @precision: Is for specifying precision
 * @size: Is for specifying size
 *
 * Return: The length of printed string
 */
int print_hexadec(va_list arg, char buffer[],
		int flags, int width, int precision, int size)
{
	/* Call print_uplo_hexa with lowercase hexadecimal characters */
	return (print_uplo_hexa(types, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}

/**
 * print_upper_hexa - This function print unsigned number as upperhexadecimal
 * @arg: Is the list of arguments
 * @buffer: is the buffer array for handling the way of printing
 * @flags:  Calculates active flags
 * @width: Is the length of a number
 * @precision: Is for precision specification
 * @size: Is for size specification
 * Return: Length of printed string
 */
int print_upper_hexa(va_list arg, char buffer[],
		int flags, int width, int precision, int size)
{
	/* Call print_uplo_hexa with uppercase hexadecimal characters */
	return (print_hexa(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}

/**
 * print_uplo_hexa - This function prints a hexadecimal number in either
 * uppercase or lowercase letters depending on the value of flag_ch
 *
 * @arg: Is the list of arguments passed
 * @ref_to: Is an array of values to map the number to
 * @buffer: is the buffer array for handling the way of printing
 * @flags:  Is for calculating active flags
 * @flag_ch: A character that determines whether the letters in the printed
 * number are uppercase or lowercase
 * @width: Is the length of a number
 * @precision: Is for precision specification
 * @size: Is for size specification
 *
 * Return: The length of printed string
 */
int print_uplo_hexa(va_list arg, char ref_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	/* Convert the number to hexadecimal&store it in the buffer array */
	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}
	/* Add the prefix '0x' or '0X' if the F_HASH flag exist & number !=0 */
	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
