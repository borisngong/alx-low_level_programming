#include "main.h"
#include <stdlib.h>
/**
 * *string_nconcat - concatenates n bytes of a string to another string
 * @s1: string to add
 * @s2: string to join end-t0-end
 * @n: number of bytes from s2 to join to s1
 * Return: pointer to the resulting string, NULL (if fails)
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *boro;
	unsigned int longi1 = 0, longi2 = 0, k = 0, l = 0;

	while (s1 && s1[longi1])
		longi1++;
	while (s2 && s2[longi2])
		longi2++;

	if (n < longi2)
		boro = malloc(sizeof(char) * (longi1 + n + 1));
	else
		boro = malloc(sizeof(char) * (longi1 + longi2 + 1));

	if (!boro)
		return (NULL);

	while (k < longi1)
	{
		boro[k] = s1[k];
		k++;
	}

	while (n < longi2 && k < (longi1 + n))
		boro[k++] = s2[l++];

	while (n >= longi2 && k < (longi1 + longi2))
		boro[k++] = s2[l++];

	boro[k] = '\0';

	return (boro);
}

