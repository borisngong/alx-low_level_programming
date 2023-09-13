#include "function_pointers.h"
/**
  * array_iterator -  executes a function given as a parameter
  * on each element of an array
  * @ array: target array
  * @ size: size of the array
  * @action: function pointer to array
  * Return: nothing
  */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int k;
	
	if (array == NULL || action == NULL)
		return;
	for (k = 0; k < size; k++)
	{
		action(array[k]);
	}

}
