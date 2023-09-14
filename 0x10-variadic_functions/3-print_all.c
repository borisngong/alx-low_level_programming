#include "variadic_functions.h"
/**
  * print_all - a function that prints anything
  * @format: list of types of arguments passed to the function
  */
void print_all(const char * const format, ...)
{
	int k, check_status;
	char *chars;

	va_list boro_argn;

	va_start(boro_argn, format);

	k = 0;
	while (format != NULL && format[k] != '\0')
	{
		switch (format[k])
		{
			case 'c':
				printf("%c", va_arg(boro_argn, int));
				check_status = 0;
				break;
			case 'i':
				printf("%d", va_arg(boro_argn, int));
				check_status = 0;
				break;
			case 'f':
				printf("%f", va_arg(boro_argn, double));
				check_status = 0;
				break;
			case 's':
				chars = va_arg(boro_argn, char *);
				if (chars == NULL)
					chars = "nil";
				printf("%s", chars);
				break;
			default:
				check_status = 1;
				break;
		}
		if (format[k + 1] != '\0' && check_status != 1)
			printf(", ");
		k++;
	}
	printf("\n");
	va_end(boro_argn);
}
