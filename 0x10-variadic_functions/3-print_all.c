#include "variadic_functions.h"
/**
  * print_all - a function that prints anything
  *
  * @format: list of types of arguments passed to the function
  */
void print_all(const char * const format, ...)
{
	int k, check_status; /*Arg data and declared variables*/
	char *chars;
	va_list boro;

	va_start(boro, format); /* starting of va_arg arguments */
	k = 0;
	while (format != NULL && format[k] != '\0')
	{
		switch (format[k]) /* execution of one code among given alternatives */
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
				if (chars == NULL)
					chars = "(nil)";
				printf("%s", chars);
				check_status = 0;
				break;
			default:
				check_status = 1;
				break; /* end of switch statement */
		}
		if (format[k + 1] != '\0' && check_status == 0) /* if NULL */
			printf(", ");
		k++;
	}
	printf("\n");
	va_end(boro); /* end of argument */

}
