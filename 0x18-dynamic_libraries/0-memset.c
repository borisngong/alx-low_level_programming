#include "main.h"
/**
 * _memset - fill a block of memory with a specific value
 * @s: first address to be filled
 * @b: sought after value
 * @n: bytes to change
 * Return: use n bytes to change value of array
 */
char *_memset(char *s, char b, unsigned int n)
{
	int j = 0;

	for (; n > 0; j++)
	{
		s[j] = b;
		n--;
	}
	return(s);
}


