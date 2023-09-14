#include "variadic_functions.h"
/**
  * print_strings - prints strings, followed by a new line
  *
  * @n: number of strings passed to the function
  *
  * @separator: strings printed between the strings
  *
  * Description: If separator is NULL, string is not printed
  * and if one of the string is NULL (nil) is printed
  *
  * Return: void
  */
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int k;
	char *chars;

	va_list boro_argn;

	va_start(boro_argn, n);

	for (k = 0; k < n; k++)
	{
		chars = va_arg(boro_argn, char *);

		if (chars == NULL)
		{
			printf("nil");
		}
		else
		{
			printf("%s", chars);
		}
		if (k != (n - 1) && separator != NULL)
		{
			printf("%s", separator);
		}
	}
	printf("\n");
	va_end(boro_argn);
}
