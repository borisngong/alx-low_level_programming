#include "main.h"
#include <stdlib.h>
/**
 * argstostr - a function that concatenates all the arguments of your program
 * @ac: integer input
 * @av: double pointer array
 * Return:  a pointer to a new string, or NULL if it fails
 * and  NULL if ac == 0 or av == NULL
 */
char *argstostr(int ac, char **av)
{
	int x, y, z, longi;
	char *s;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (x = 0; x < ac; x++)
	{
		for (y = 0; av[x][y] != '\0'; y++)
			longi++;
		longi++;
	}

	s = malloc(sizeof(char) * (longi + 1));

	if (s == NULL)
		return (NULL);

	z = 0;

	for (x = 0; x < ac; x++)
	{
		for (y = 0; av[x][y] != '\0'; y++)
		{
			s[z] = av[x][y];
			z++;
		}
		if (s[z] == '\0')
		{
			s[z++] = '\n';
		}
	}
	return (s);
}

