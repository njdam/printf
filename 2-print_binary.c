#include "main.h"

/**
 * print_binary - This function prints an unsigned number in binary format
 * @arg: Is the list of arguments
 * @buffer: Is the buffer array to handle print
 * @flags: Is used to calculate the active flags
 * @width: Is the width specification
 * @precision: Is the precision specification
 * @size: Is the size specifier
 * Return: Number of printed chatacters
 */
int print_binary(va_list arg, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned int num = va_arg(arg, unsigned int);
	unsigned int mask = 1u << (sizeof(unsigned int) * 8 - 1);
	int count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	/* Find the most significant bit and print the binary representation */
	while (mask > 0)
	{
		if (num & mask)
		{
			write(1, "1", 1);
			count++;
		}
		else if (count > 0 || mask == 1)
		{
			write(1, "0", 1);
			count++;
		}
		mask >>= 1;
	}

	return (count);
}
