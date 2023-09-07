#include "main.h"

/**
 * *array_range - creates an array of integers
 * @min: minimum range of values
 * @max: maximum range of values
 * Return: pointer to the new array
 * If min > max, return NULL
 * If malloc fails, return NULL
 */
int *array_range(int min, int max)
{
	int *pt;
	int k;
	int magn;

	if (min > max)
		return (NULL);

	magn = max - min + 1;

	pt = malloc(sizeof(int) * magn);

	if (pt == NULL)
		return (NULL);

	for (k = 0; min <= max; k++)
		pt[k] = min++;

	return (pt);
}


