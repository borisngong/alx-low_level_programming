#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - free the memory allocated for the dog's structure
 * @d: dog's structure to free
 */
void free_dog(dog_t *d)
{
	if (d)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}

