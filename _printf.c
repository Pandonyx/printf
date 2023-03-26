#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);
int count = 0;
while (*format)
{
if (*format == '%')
{
switch (*(format + 1))
{
case 'c':
{
char c = (char) va_arg(args, int);
putchar(c);
count++;
break;
}
case 's':
{
char *s = va_arg(args, char*);
while (*s)
{
putchar(*s);
s++;
count++;
}
break;
}
case '%':
{
putchar('%');
count++;
break;
}
default:
{
break;
}
}
format += 2;
}
else
{
putchar(*format);
format++;
count++;
}
}
va_end(args);
return count;
}
