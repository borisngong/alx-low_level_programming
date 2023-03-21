#include "main.h"
/**
  *Main - Print_alphabet
  *Descrition: Print alphabet in lowercase followed by line
  *Return: Always 0 (Success)
  */

void print_alphabet(void);
{
	int i;
	for (i = 97; i <= 122; i++)
	{
		putchar(i);
	}
	_putchar('\n');
	return (0);
}
