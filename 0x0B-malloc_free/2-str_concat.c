#include "main.h"
#include <stdlib.h>
/**
 * str_concat - concatenates two strings
 * @s1: input one to concatenate
 * @s2: input two to concatenate
 * Return: contents of s1 and s2 and NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	char *concat;
	int k, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	k = j = 0;
	while (s1[k] != '\0')
		k++;
	while (s2[j] != '\0')
		j++;
	concat = malloc(sizeof(char) * (k + j + 1));

	if (concat == NULL)
		return (NULL);
	k = j = 0;
	while (s1[k] != '\0')
	{
		concat[k] = s1[k];
		k++;
	}

	while (s2[j] != '\0')
	{
		concat[k] = s2[j];
		k++, j++;
	}
	concat[k] = '\0';
	return (concat);
}
