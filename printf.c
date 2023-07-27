#include <stdarg.h>
#include <unistd.h>
#include "main.h"
#include "conv.h"

int _putchar(int c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

int _puts(const char *s)
{
	int n_chars;
	const char *t = s;

	while (*t)
	{
		n_chars = write(STDOUT_FILENO, t++, 1);
		if (n_chars < 0)
			return (n_chars);
	}

	return (t - s);
}

int _printf(const char *format, ...)
{
	char c;
	int n_chars = 0;
	int total_n_chars = 0;
	va_list args;

	if (!*format)
	{
		return (0);
	}

	va_start(args, format);

	while (n_chars >= 0 && (c = *format++))
	{
		if (c != '%')
		{
			n_chars = _putchar(c);
			if (n_chars < 0)
				break;
			total_n_chars += n_chars;
			continue;
		}

		switch (c = *format++)
		{
			case 'c':
				n_chars = conv_c((unsigned char)va_arg(args, int));
				break;
			case 's':
				n_chars = conv_s(va_arg(args, char *));
				break;
			case 'd':
			case 'i':
				n_chars = conv_i(va_arg(args, int));
				break;
			case '%':
				n_chars = _putchar('%');
				break;
			default:
				n_chars = _putchar(c);
				break;
		}
		if (n_chars < 0)
			break;
		total_n_chars += n_chars;
	}

	va_end(args);

	return ((n_chars > 0) ? total_n_chars : n_chars);
}
