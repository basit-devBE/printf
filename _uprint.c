#include "main.h"

/**
 * p_h - prints an unsigned lowercase hex num
 * @pr: argument pointer
 * @par: parameters struct
 * Return: bytes printed
 * On error, -1 is returned, and error is set appropriately.
 */
int p_h(va_list pr, params_t *par)
{
unsigned long hex_value;
int byte_count = 0;
char *converted_string;

if (par->l_m)
hex_value = (unsigned long)va_arg(pr, unsigned long);
else if (par->h_m)
hex_value = (unsigned short int)va_arg(pr, unsigned int);
else
hex_value = (unsigned int)va_arg(pr, unsigned int);

converted_string = con(hex_value, 16, CON_UNSIGNED | CON_LOWERCASE, par);
if (par->hashtag_f && hex_value)
{
*--converted_string = 'x';
*--converted_string = '0';
}
par->unsign = 1;
return (byte_count += pn(converted_string, par));
}

/**
 * pb - prints unsigned binary number
 * @pr: argument pointer
 * @par: parameters struct
 * Return: bytes printed
 */
int pb(va_list pr, params_t *par)
{
unsigned int binary_value = va_arg(pr, unsigned int);
char *converted_string = con(binary_value, 2, CON_UNSIGNED, par);
int byte_count = 0;

if (par->hashtag_f && binary_value)
*--converted_string = '0';
par->unsign = 1;
return (byte_count += pn(converted_string, par));
}

/**
 * p_H - prints unsigned hex numbers in uppercase
 * @pr: argument pointer
 * @par: parameters struct
 * Return: bytes printed
 */
int p_H(va_list pr, params_t *par)
{
unsigned long hex_value;
int byte_count = 0;
char *converted_string;

if (par->l_m)
hex_value = (unsigned long)va_arg(pr, unsigned long);
else if (par->h_m)
hex_value = (unsigned short int)va_arg(pr, unsigned int);
else
hex_value = (unsigned int)va_arg(pr, unsigned int);

converted_string = con(hex_value, 16, CON_UNSIGNED, par);
if (par->hashtag_f && hex_value)
{
*--converted_string = 'X';
*--converted_string = '0';
}
par->unsign = 1;
return (byte_count += pn(converted_string, par));
}

/**
 * po - prints unsigned octal num
 * @pr: argument pointer
 * @par: parameters struct
 * Return: bytes printed
 */
int po(va_list pr, params_t *par)
{
unsigned long oct_value;
char *converted_string;
int byte_count = 0;

if (par->l_m)
oct_value = (unsigned long)va_arg(pr, unsigned long);
else if (par->h_m)
oct_value = (unsigned short int)va_arg(pr, unsigned int);
else
oct_value = (unsigned int)va_arg(pr, unsigned int);
converted_string = con(oct_value, 8, CON_UNSIGNED, par);

if (par->hashtag_f && oct_value)
*--converted_string = '0';
par->unsign = 1;
return (byte_count += pn(converted_string, par));
}

