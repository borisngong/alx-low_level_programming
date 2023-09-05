#include "main.h"
#include <stdlib.h>
/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers
 * @width: width
 * @height: height
 * Return: pointer to 2 dimensional array, return NULL on failure
 * If width or height is 0 or negative, return NULL
 */
int **alloc_grid(int width, int height)
{
	int **boro;
	int k, j;

	if (width <= 0 || height <= 0)
		return (NULL);

	boro = malloc(sizeof(int *) * height);

	if (boro == NULL)
		return (NULL);

	for (k = 0; k < height; k++)
	{
		boro[k] = malloc(sizeof(int) * width);

		if (boro[k] == NULL)
		{
			for (; k >= 0; k--)
				free(boro[k]);

			free(boro);
			return (NULL);
		}
	}

	for (k = 0; k < height; k++)
	{
		for (j = 0; j < width; j++)
			boro[k][j] = 0;
	}

	return (boro);
}
