#include "main.h"
#include <stdlib.h>
/**
 * *array_range - creates an array of integers
 * @min: minimum values
 * @max: maximum values
 *
 * Return: a pointer to the newly created array
 * if malloc fails return NULL, if  min > max return NULL
 */
int *array_range(int min, int max)
{
	int *pt;
	int x, size;

	if (min > max)
		return (NULL);

	size = max - min + 1;

	pt = malloc(sizeof(int) * size);

	if (pt == NULL)
		return (NULL);

	for (x = 0; min <= max; x++)
		pt[x] = min++;

	return (pt);
}

