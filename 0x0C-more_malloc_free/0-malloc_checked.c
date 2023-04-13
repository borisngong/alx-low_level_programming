#include <stdio.h>
#include "main.h"

/**
  **malloc_checked - function that allocates memory using malloc
  *@b: Bytes to allocate
  *Return: pointer 
  */
void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);

	if (ptr == NULL)
		exit(98);

	return (ptr);
}

