#include "variadic_functions.h"
/**
  * print_all - a function that prints anything
  * @format: list of types of arguments passed to the function
  * Return: void
  */
void print_all(const char * const format, ...)
{
	int k, check_status;
	char *chars;
	va_list boro;

	va_start(boro, format);
	k = 0;
	while (format != NULL && format[k] != '\0')
	{
		switch (format[k])
		{
			case 'i':
				printf("%d", va_arg(boro, int));
				check_status = 0;
				break;
			case 'c':
				printf("%c", va_arg(boro, int));
				check_status = 0;
				break;
			case 'f':
				printf("%f", va_arg(boro, double));
				break;
			case 's':
				chars = va_arg(boro, char *);
				if (!chars)
					chars = "(nil)";
				printf("%s", chars);
				check_status = 0;
				break;
			default:
				check_status = 1;
				break;
		}
		if (format[k + 1] != '\0' && check_status == 0)
			printf(", ");
		k++;
	}
	printf("\n");

	va_end(boro);

}
