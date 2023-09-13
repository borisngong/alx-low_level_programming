#include "function_pointers.h"
/**
  * int_index - a function that searches for an integer
  * @array: target array
  * @size: number of elements in an array
  * @cmp: pointer to the function used to compare integer values
  * Return: -1 if no element matches and
  * if size <= 0
  */
int int_index(int *array, int size, int (*cmp)(int))
{
	int k;

	if (array == NULL || cmp == NULL)
		return (-1);
	for (k = 0; k < size; k++)
	{
		if (cmp(array[k]) != 0)
			return (k);
	}
	return (-1);
}
