#include "main.h"

/**
 * pc - prints character
 * @pr: argument pointer
 * @par: parameters struct
 * Return: number chars printed
 */
int pc(va_list pr, params_t *par)
{
    char character = ' ';
    unsigned int k = 1, sum = 0, number = va_arg(pr, int);

    if (par->minus_f)
        sum += _putchar(number);
    while (k++ < par->w)
        sum += _putchar(character);
    if (!par->minus_f)
        sum += _putchar(number);
    return (sum);
}

/**
 * pp - prints string
 * @pr: argument pointer
 * @par: parameters struct
 * Return: number chars printed
 */
int pp(va_list pr, params_t *par)
{
    (void)pr;
    (void)par;
    return (_putchar('%'));
}

/**
 * pi - prints integer
 * @pr: argument pointer
 * @par: parameters struct
 * Return: number chars printed
 */
int pi(va_list pr, params_t *par)
{
    long integer_value;

    if (par->l_m)
        integer_value = va_arg(pr, long);
    else if (par->h_m)
        integer_value = (short int)va_arg(pr, int);
    else
        integer_value = (int)va_arg(pr, int);
    return (pn(con(integer_value, 10, 0, par), par));
}

/**
 * p_S - custom format specifier
 * @pr: argument pointer
 * @par: parameters struct
 * Return: number chars printed
 */
int p_S(va_list pr, params_t *par)
{
    char *input_string = va_arg(pr, char *);
    char *hex_value;
    int sum = 0;

    if ((int)(!input_string))
        return (_puts(NULL_STRING));
    for (; *input_string; input_string++)
    {
        if ((*input_string > 0 && *input_string < 32) || *input_string >= 127)
        {
            sum += _putchar('\\');
            sum += _putchar('x');
            hex_value = con(*input_string, 16, 0, par);
            if (!hex_value[1])
                sum += _putchar('0');
            sum += _puts(hex_value);
        }
        else
        {
            sum += _putchar(*input_string);
        }
    }
    return (sum);
}

/**
 * pst - prints string
 * @pr: argument pointer
 * @par: parameters struct
 * Return: number chars printed
 */
int pst(va_list pr, params_t *par)
{
    char *input_string = va_arg(pr, char *);
    char character = ' ';
    unsigned int index = 0, sum = 0, count = 0, length;

    (void)par;
    switch ((int)(!input_string))
    {
        case 1:
            input_string = NULL_STRING;
    }

    length = index = _st(input_string);
    if (par->p < length)
        length = index = par->p;

    if (par->minus_f)
    {
        if (par->p != UINT_MAX)
        {
            for (count = 0; count < length; count++)
                sum += _putchar(*input_string++);
        }
        else
            sum += _puts(input_string);
    }
    while (index++ < par->w)
        sum += _putchar(character);
    if (!par->minus_f)
    {
        if (par->p != UINT_MAX)
        {
            for (count = 0; count < length; count++)
                sum += _putchar(*input_string++);
        }
        else
            sum += _puts(input_string);
    }
    return (sum);
}

