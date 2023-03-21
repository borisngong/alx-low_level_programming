#include "main.h"
/**
  *_islower - show 1 if the input is lowercase
  * and 0 for others
  *@c: ASCII code characters
  *Return: 1 for lowercase characters, 0 for others
  */

int _islower(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (1);
	}
	else
	{
		return (0);
	}
	_putchar('\n');
}

