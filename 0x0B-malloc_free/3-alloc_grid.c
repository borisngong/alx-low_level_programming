#include <stdlib.h>
#include "main.h"

/**
 * **alloc_grid - creates a two dimensional array of integers
 * @width: width of the grid
 * @height: height of the grid
 *
 * Return: pointer to grid (Success)or NULL (failure)
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int n, m;

	if (height <= 0 || width <= 0)
		return (NULL);

	grid = (int **) malloc(sizeof(int *) * height);

	if (grid == NULL)
		return (NULL);
	for (n = 0; n < height; n++)
	{
		grid[n] = (int *) malloc(sizeof(int) * width);
		if (grid[n] == NULL)
		{
			free(grid);
			for (m = 0; m <= n; m++)
				free(grid[m]);
			return (NULL);
		}
	}

	for (n = 0; n < height; n++)
	{
		for (m = 0; m < width; m++)
		{
			grid[n][m] = 0;
		}
	}
	return (grid);
}

