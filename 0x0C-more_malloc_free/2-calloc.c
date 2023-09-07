#include "main.h"
/**
 * *string_nconcat - concatenates n bytes of a string to another string
 * @s1: string to add to
 * @s2: string to join end-to-end
 * @n: number of bytes to joing s2 t0 s1
 * Return: pointer to the resulting string
 * if nmemb or size is 0, returns NULL
 * if malloc fails, returns NULL.

 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int k;

	for (k = 0; k < n; k++)
	{
		s[k] = b;
	}

	return (s);
}

/**
 * *_calloc - allocates memory for an array
 * @nmemb: number of elements in the array
 * @size: size of each element
 *
 * Return: pointer to allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *pt;

	if (nmemb == 0 || size == 0)
		return (NULL);

	pt = malloc(size * nmemb);

	if (pt == NULL)
		return (NULL);

	_memset(pt, 0, nmemb * size);

	return (pt);
}

