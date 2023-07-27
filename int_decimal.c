#include "main.h"

int conv_i(int i)
{
	int total_n_chars = 0, n_chars;
	unsigned int u;

	if (i < 0)
	{
		n_chars = _putchar ('-');
		if (n_chars < 0)
		{
			return (n_chars);
		}
		total_n_chars += n_chars;
		
		u = (unsigned int)-i;
	}
	else 
	{
		u = (unsigned int)i;
	}

	if (u >= 10)
	{
		n_chars = conv_i(u / 10);
		if (n_chars < 0)
		{
			return (n_chars);
		}
		total_n_chars += n_chars;
	}

	n_chars = _putchar('0' + u % 10);
	if (n_chars < 0)
	{
		return (n_chars);
	}

	return (total_n_chars + n_chars);
}
