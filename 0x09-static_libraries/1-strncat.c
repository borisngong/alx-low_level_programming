#include "main.h"
/**
 * _strncat - a function to concatenate two strings uding
 * n bytes from src
 * @dest: input value
 * @src: input value
 * @n: input value
 * Return: dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int t;
	int m;

	t = 0;
	while (dest[t] != '\0')
	{
		t++;
	}
	m = 0;
	while (m < n && src[m] != '\0')
	{
		dest[t] = src[m];
		t++;
		m++;
	}
	dest[t] = '\0';
	return (dest);
}
