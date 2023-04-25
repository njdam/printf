#include "main.h"

/**
 * print_rev - Prints a string in reverse
 * @arg: List of arguments passed to function
 * @buffer: Buffer array used to handle printing
 * @flags: Calculates active flags (not used in this function)
 * @width: Specifies minimum width of printed field (not used too)
 * @precision: Specifies maximum number of characters to print (not used too)
 * @size: Size specifier (not used too)
 * Return: Number of characters printed
 */
int print_rev(va_list arg, char buffer[], int flags,
		int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);
	/* Get string from arguments */
	str = va_arg(arg, char *);

	if (str == NULL)
	{
		UNUSED(precision);
		str = ")Null(";
	}
	/* Iterate through string backwards and print each character */
	for (i = 0; str[i]; i++)
		;
	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/**
 * print_rot13 - Prints a string in ROT13 encryption.
 * @arg: List of arguments passed to function
 * @buffer: Buffer array used to handle printing
 * @flags: Calculates active flags (not used in this function)
 * @width: Specifies minimum width of printed field (not used in this function)
 * @precision: Specifies maximum number of characters to print (not used too)
 * @size: Size specifier (not used in this function)
 * Return: Number of characters printed
 */
int print_rot13(va_list arg, char buffer[], int flags,
		int width, int precision, int size)
{
	unsigned int i, j;
	int count = 0;
	char *string;
	char x;
	/* Iterate through string and apply ROT13 encryption */
	char original[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char hashed[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	/* Get string from arguments */
	string = va_arg(arg, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (string == NULL)
		string = "(AHYY)";

	for (i = 0; string[i]; i++)
	{
		for (j = 0; original[j]; j++)
		{
			if (original[j] == string[i])
			{
				x = hashed[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!original[j])
		{
			x = string[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
