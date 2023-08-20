#include "main.h"
/**
 * _printf - will print anything
 * @format: the format string
 * Return: number of chars printed
 */
int _printf(const char *format, ...)
{
	int total = 0;
	va_list br;
	char *b, *start;
	params_t par = PARAMS_INIT;

	va_start(br, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (b = (char *)format; *b; b++)
	{
		itp(&par, br);
		if (*b != '%')
		{
			total += _putchar(*b);
			continue;
		}
		start = b;
		b++;
		while (gf(b, &par))
		{
			b++;
		}
		b = gw(b, &par, br);
		b = gp(b, &par, br);
		if (gm(b, &par))
			b++;
		if (!gs(b))
			total += pft(start, b,
				par.l_m || par.h_m ? b - 1 : 0);
		else
			total += gpf(b, br, &par);
	}
	_putchar(BUF_FLUSH);
	va_end(br);
	return (total);
}

