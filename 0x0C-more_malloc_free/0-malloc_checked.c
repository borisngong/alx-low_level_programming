#include <stdlib.h>
#include "main.h"

/**
 * *malloc_checked - allocates memory using malloc
 * @b: bytes to be allocated
 *
 * Return: a pointer to the allocated memory and
 * on failure process termination of  status value 98
 */
void *malloc_checked(unsigned int b)
{
	char *pt;

	pt = malloc(b);

	if (pt == NULL)
		exit(98);

	return (pt);
}

