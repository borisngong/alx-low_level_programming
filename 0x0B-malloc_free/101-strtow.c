#include <stdlib.h>
#include "main.h"

/**
 * count_word - helper function to count the number of words in a string
 * @s: string to evaluate
 *
 * Return: number of words
 */
int count_word(char *s)
{
	int flag, c, w;

	flag = 0;
	w = 0;

	for (c = 0; s[c] != '\0'; c++)
	{
		if (s[c] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			w++;
		}
	}

	return (w);
}
/**
 * **strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success)
 * or NULL (Failure)
 */
char **strtow(char *str)
{
	char **grid, *tmp;
	int x, y = 0, n = 0, words, c = 0, start, end;

	while (*(str + n))
		n++;
	words = count_word(str);
	if (words == 0)
		return (NULL);

	grid = (char **) malloc(sizeof(char *) * (words + 1));
	if (grid == NULL)
		return (NULL);

	for (x = 0; x <= n; x++)
	{
		if (str[x] == ' ' || str[x] == '\0')
		{
			if (c)
			{
				end = x;
				tmp = (char *) malloc(sizeof(char) * (c + 1));
				if (tmp == NULL)
					return (NULL);
				while (start < end)
					*tmp++ = str[start++];
				*tmp = '\0';
				grid[y] = tmp - c;
				y++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = x;
	}

	grid[y] = NULL;

	return (grid);
}

