#include "variadic_functions.h"
/**
  * print_numbers - a function that prints numbers, followed by a new line
  * @n: number of intergers passed to the function
  * @separator: string to  print between numbers
  * Return: void
  */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int k, nums;

	va_list boro_argn;

	va_start(boro_argn, n);

	for (k = 0 ; k < n; k++)
	{
		nums = va_arg(boro_argn, unsigned int);
		printf("%d", nums);

		if (k != (n - 1) && separator != NULL)
		{
			printf("%s", separator);
		}
	}
	printf("\n");

	va_end(boro_argn);
}
