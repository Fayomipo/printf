#include "main.h"

int conv_o(unsigned int u)
{
	int total_n_chars = 0, n_chars;

	if (u >= 8)
	{
		n_chars = conv_o(u / 8);
		if (n_chars < 0)
		{
			return (n_chars);
		}
		total_n_chars += n_chars;
	}

	n_chars = _putchar('0' + u % 8);
	if (n_chars < 0)
	{
		return (n_chars);
	}

	return (total_n_chars + n_chars);
}

int conv_b(unsigned int u)
{
	int total_n_chars = 0, n_chars;

	if (u >= 2)
	{
		n_chars = conv_b(u / 2);
		if (n_chars < 0)
		{
			return (n_chars);
		}
		total_n_chars += n_chars;
	}

	n_chars = _putchar('0' + u % 2);
	if (n_chars < 0)
	{
		return (n_chars);
	}

	return (total_n_chars + n_chars);
}
