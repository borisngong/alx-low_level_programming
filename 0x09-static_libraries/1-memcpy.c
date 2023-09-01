#include "main.h"
/**
 *_memcpy - a function that copies memory area
 *@dest: stored memory
 *@src: memory to copy
 *@n: number of bytes
 *Return: copied memory with n byted changed
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int r = 0;
	int t = n;

	for (; r < t; r++)
	{
		dest[r] = src[r];
		n--;
	}
	return (dest);
}

