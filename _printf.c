#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - custom printf function that handles %c and %s format specifiers
 * @format: string containing format specifiers
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
va_list args; // declare va_list variable to hold additional arguments
va_start(args, format); // initialize args to point to first optional argument
int count = 0; // initialize count to 0
// loop through the format string
while (*format)
{
// check if current character is a format specifier (%)
if (*format == '%')
{
switch (*(format + 1)) // check the next character to determine the format specifier
{
// case for %c format specifier
case 'c':
{
char c = (char) va_arg(args, int); // retrieve the next argument as a character
putchar(c); // print the character
count++; // increment count
break;
}
// case for %s format specifier
case 's':
{
char *s = va_arg(args, char*); // retrieve the next argument as a string
while (*s) // loop through the string
{
putchar(*s); // print each character of the string
s++; // move to the next character
count++; // increment count for each character printed
}
break;
}
// case for %% format specifier (literal %)
case '%':
{
putchar('%'); // print the literal %
count++; // increment count
break;
}
// default case for unknown format specifier (ignore it)
default:
{
// Unknown conversion specifier, ignore it
break;
}
}
format += 2; // Move to next format specifier (skip over the % and the specifier character)
}
else // current character is not a format specifier
{
putchar(*format); // print the character
format++; // move to the next character in the format string
count++; // increment count
}
}
va_end(args); // free any memory associated with the va_list variable
return count; // return the total number of characters printed
}
