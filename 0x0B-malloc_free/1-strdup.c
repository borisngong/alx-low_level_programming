#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _strdup - duplicate to a newly memory space location.
 * @str: character string
 * Description:a function that returns a pointer to a newly allocated
 *space in memory, which contains a copy of the string given as a parameter.
 * Return: pointer to duplicate string and NULL for unavailable memory
 */

char *_strdup(char *str)
{
	char *b;
	int j, n = 0;

	if (str == NULL)
		return (NULL);
	j = 0;
	while (str[j] != '\0')
		j++;

	b = malloc(sizeof(char) * (j + 1));

	if (b == NULL)
		return (NULL);

	for (n = 0; str[n]; n++)
		b[n] = str[n];

	return (b);
}

