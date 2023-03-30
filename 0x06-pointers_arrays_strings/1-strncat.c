#include "main.h"
/**
  *_strncat - Write a function that concatenates two strings.
  *@dest: copying to
  *@src: copying from
  *@n: Number of character to be copied
  *Return: void
  */

char *_strncat(char *dest, char *src, int n)
{
	int d;
	int s;

	d = 0;
	while (dest[d] != '\0')
	{
		d++;
	}
	s = 0;
	while (s < n && src[s] != '\0')
	{
		dest[d] = src[s];
		d++;
		s++;
	}
	dest[d] = '\0';
	return (dest);
}

