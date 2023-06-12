#include "main.h"
#include <stdlib.h>
/**
 * alloc_grid - a function that concatenates two strings
 * @width: width input
 * @height: height input
 * Return: NULL on failure and a pointer to 2 dim array
 */
int **alloc_grid(int width, int height)
{
	int **br;
	int i, j;

	if (width <= 0 || height <= 0)
		return (NULL);

	br = malloc(sizeof(int *) * height);

	if (br == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		br[i] = malloc(sizeof(int) * width);

		if (br[i] == NULL)
		{
			for (; j >= 0; j--)
				free(br[i]);

			free(br);
			return (NULL);
		}
	}

	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
			br[i][j] = 0;
	}

	return (br);
}
