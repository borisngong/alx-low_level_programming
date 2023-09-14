#include "variadic_functions.h"
/**
  * print_all - a function that prints anything
  * @format: list of types of arguments passed to the function
  */
void print_all(const char * const format, ...)
{
	int k = 0;
	char *chars, *comma = ", ";
	va_list boro_argn;

	va_start(boro_argn, format);
	if (format)
	{
		while (format[k])
		{
			switch (format[k])
			{
				case 'c':
					printf("%s%c", comma, va_arg(boro_argn, int));
					break;
				case 'i':
					printf("%s%d", comma, va_arg(boro_argn, int));
					break;
				case 'f':
					printf("%s%f", comma, va_arg(boro_argn, double));
					break;
				case 's':
					chars = va_arg(boro_argn, char *);
					if (!chars)
						chars = "(nil)";
					printf("%s%s", comma, chars);
					break;
				default:
					k++;
					continue;
			}
			comma = ", ";
			k++;
		}
	}

	printf("\n");
	va_end(boro_argn);
}

