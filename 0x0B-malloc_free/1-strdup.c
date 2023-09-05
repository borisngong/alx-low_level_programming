#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * _strdup - function returns a pointer to a new string
 * which is a duplicate of the string
 * @str: string duplicate
 * Return: pointer to duplicate str amd NULL if str == NUULL
 */
char *_strdup(char *str)
{
	char *boro;
	int k, j = 0;

	if (str == NULL)
		return (NULL);
	k = 0;
	while (str[k] != '\0')
		k++;

	boro = malloc(sizeof(char) * (k + 1));

	if (boro == NULL)
		return (NULL);

	for (j = 0; str[j]; j++)
		boro[j] = str[j];

	return (boro);
}

