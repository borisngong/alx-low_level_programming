#include "main.h"
/**
  *_isalpha - show 1 if character, lowercase or uppercase,
  *0 otherwise
  *@c: ASCII character code
  *Return: 1 if c letter,lowercase or uppercase, 0 otherwise
  */
int _isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
	{
		return (1);
	}
	else
	{
		return (0);
	}
	_putchar('\n');
}

