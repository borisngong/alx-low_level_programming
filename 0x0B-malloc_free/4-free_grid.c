#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * free_grid - A function that frees 2 dimensional grid
 * @grid: 2d grid
 * @height: height of grid
 * Description: frees memory of grid previously created
 * Return: 0
 *
 */
void free_grid(int **grid, int height)
{
	int j;

	for (j = 0; j < height; j++)
	{
		free(grid[j]);
	}
	free(grid);
}

