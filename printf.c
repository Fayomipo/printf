#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int _putchar(int c)
{
    return write(STDOUT_FILENO, &c, 1);
}

int _puts(const char *s)
{
    const char *t = s;

    while (*t) {
        write(STDOUT_FILENO, t++, 1);
    }

    return (t - s);
}

int _printf(const char *format, ...)
{
    char c;
    size_t n_chars = 0;
    va_list args;

    if (!*format) return 0;

    va_start(args, format);

    while ((c = *format++)) {
        if (c != '%') {
            _putchar(c);
            n_chars++;
            continue;
        }
        switch (c = *format++) {
            case 'c':
                _putchar((unsigned char)va_arg(args, int));
                n_chars++;
                break;
            case 's':
                n_chars += _puts(va_arg(args, char *));
                break;
            case '%':
                _putchar('%');
                break;
        }
    }

    va_end(args);

    return n_chars;
}
