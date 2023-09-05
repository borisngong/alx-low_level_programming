#include "main.h"
#include <stdlib.h>
/**
 * create_array - a function create array of size
 * size and initialize it with specific char c
 * @size: array size
 * @c: char to initialize
 * Return: pointer to array or NULL if fail
 *
 */
char *create_array(unsigned int size, char c)
{
	char *s;
	unsigned int k;

	s = malloc(sizeof(char) * size);
	if (size == 0 || s == NULL)
		return (NULL);

	for (k = 0; k < size; k++)
		s[k] = c;
	return (s);
}

