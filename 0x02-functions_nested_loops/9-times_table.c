#include "main.h"
/**
  *print_times_table - Starting with 0, print times table
  *Return: 0
  */
void print_times_table(void)
{
	int x, y, z, u, d;

	for (x = 0; x <= 9 ; x++)
	{
		for (y = 0; y <= 9; y++)
		{
			z = x = u;
			if (z > 0)
			{
				u = z % 10;
				d = (z - u) / 10;
				_putchar(44);
				_putchar(32);
				_putchar(d + '0');
				_putchar(u + '0');
			}
			else
			{
				if (y != 0)
				{
					_putchar(44);
					_putchar(32);
					_putchar(32);
				}
				_putchar(z + '0');
			}
		}
		putchar('\n');
	}
}
