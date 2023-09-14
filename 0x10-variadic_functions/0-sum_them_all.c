#include "variadic_functions.h"
/**
  * sum_them_all - returns the sum of all its parameters
  * @n: argument passed
  * Return: sum
  */
int sum_them_all(const unsigned int n, ...)
{
	unsigned int k, sum = 0;

	va_list boroargn;

	va_start(boroargn, n);

	for (k = 0; k < n; k++)
	{
		if (n == 0)
		{
			return (0);
		}
		else
		{
			sum += (va_arg(boroargn, unsigned int));
		}
	}
	va_end(boroargn);

	return (sum);
}
