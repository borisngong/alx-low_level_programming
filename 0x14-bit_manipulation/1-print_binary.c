#include "main.h"
/**
  * print_binary - prints the binary representation of an unsigned long int.
  * @n: unsigned long int
  * Return: (void)
  */
void print_binary(unsigned long int n)
{
	int k;
	int significant_bits = 0;
	unsigned long int current_bit;

	for (k = 63; k >= 0; k--)
	{
		current_bit = n >> k;

		if (current_bit & 1)
		{
			_putchar('1');
			significant_bits++;
		}
		else if (significant_bits++)
		{
			_putchar('0');
		}
	}
	if (!significant_bits)
		_putchar('0');
}
