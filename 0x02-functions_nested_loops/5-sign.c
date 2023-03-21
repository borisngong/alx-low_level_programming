#include "main.h"
/**
  *print_sign - print sign of a either gretaer than 0, less than 0 or 0
  *@n: interger as an input number
  *Return: 1 is greater than zero, 0 is zero and -1 is less than 0
  */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar(43);
		return (1);
	}
	else if (n == 0)
	{
		_putchar(48);
		return (0);
	}
	else
	{
		_putchar(45);
		return (-1);
	}
	_putchar('\n');
}
