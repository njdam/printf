#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 1024
#define UNUSED(x) ((void)(x))

/* SIZES TO BE USED */
#define SHORT 1
#define LONG 2

/* FLAGS TO BE USED */
#define SPACE 1
#define HASH 2
#define MINUS 4
#define PLUS 8
#define ZERO 16

/**
 * struct format - structure operator;
 *
 * @format: associated format;
 * @func: a pointer to a function;
 */
typedef struct format
{
	char format;
	int (*func)(va_list, char[], int, int, int, int);
}
/* a pointer to pointed to a function */
fmt_func;

/* Functions for making Printf like */
int print_handler(const char *format, int *x, va_list, char buffer[],
		int flags, int width, int precision, int size);

/**** Functions for UTILS ****/
int _isdigit(char c);
int _isprintable(char c);
long int conv_size_num(long int num, int size);
long int conv_size_uns(unsigned long int num, int size);
int append_hexacode(char ascii_code, char buffer[], int x);

/******* Functions for Project Questions *******/

/* Qu.0: _printf function */
int _printf(const char *format, ...);
void flush_buffer(char buffer[], int *buff_len);

/** Qu.1: Functions for printing Integers **/
int print_int(va_list arg, char buffer[], int flags, int width,
		int precision, int size);

/*** Qu.2: Binary printer ***/
int print_binary(va_list arg, char buffer[], int flags, int width,
		int precision, int size);

/**** Qu.3: cunstom Conversion specifiers ****/
int print_uns(va_list arg, char buffer[], int flags, int width,
		int precision, int size);
int print_octal(va_list arg, char buffer[], int flags, int width,
		int precision, int size);
int print_haxadec(va_list arg, char buffer[], int flags, int width,
		int precision, int size);
int print_upper_hexa(va_list arg, char buffer[], int flags, int width,
		int precision, int size);
int print_uplo_hexa(va_list arg, char buffer[], int flags, int width,
		int precision, int size);

/***** Qu.4: write handler functions *****/
int write_char(char c, char buffer[], int flags, int width,
		int precision, int size);
int write_nsign(int is_negative, int x, char buffer[],
		int flags, int width, int precision, int size);
int write_num(int x, char buffer[], int flags, int width, int precision,
		int len, char pc, char ext_c);
int write_uns(int is_negative, int x, char buffer[], int flags,
		int width, int precision, int size);
int write_pointer(char buffer[], int x, int len, int flags,
		int width, char pc, char ext_c, int p_start);

/****** Qu.5: Custom specification for string printer function *****/
int print_string(va_list arg, char buffer[], int flags, int width,
		int precision, int size);
int print_char(va_list arg, char buffer[], int flags, int width,
		int precision, int size);
int print_percent(va_list arg, char buffer[], int flags, int width,
		int precision, int size);

/******* Qu.6: function to print address of where pointer point to *******/
int print_pointer(va_list arg, char buffer[], int flags, int width,
		int precision, int size);
int print_non_printable(va_list arg, char buffer[], int flags,
		int width, int precision, int size);

/******** Qu.7 - Qu.12: 100 - non-custom conversion specifiers ********/
int check_flags(const char *format, int *x);
int check_width(const char *format, int *x, va_list arg);
int check_precision(const char *format, int *x, va_list arg);
int check_size(const char *format, int *x);

/********* Qu.13-Qu.14: 101 - prototype to printing reverse or tr rot13 ********/
int print_rev(va_list arg, char buffer[], int flags, int width,
		int precision, int size);
int print_rot13(va_list arg, char buffer[], int flags, int width,
		int precision, int size);

#endif /* MAIN_H */
