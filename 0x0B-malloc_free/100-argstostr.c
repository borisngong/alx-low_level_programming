#include "main.h"
#include <stdlib.h>
/**
 * argstostr - concatenates all the arguments of your program
 * @ac: argument counts
 * @av: array of argument
 * Return: pointer to a new string, or NULL (failure)
 */
char *argstostr(int ac, char **av)
{
	int x, y, m, n;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (x = 0; x < ac; x++)
	{
		for (y = 0; av[x][y] != '\0'; y++)
			n++;
	}
	n += ac;

	str = malloc(sizeof(char) * (n + 1));

	if (str == NULL)
		return (NULL);

	m = 0;

	for (x = 0; x < ac; x++)
	{
		for (y = 0; av[x][y] != '\0'; y++)
		{
			str[m] = av[x][y];
			m++;
		}
		str[m] = '\n';
		m++;
	}
	return (str);
}


