#include <stdlib.h>
#include "dog.h"
/**
  * init_dog - function to intialize struct  dog with members
  * @d: pointer to struct dog
  * @name: first memebr, dog's name initialize
  * @age: second member, dog's age to intialize
  * @owner: third member, dog's owner to initialize
  */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		d = malloc(sizeof(struct dog));
	(*d).name = name;
	d->age = age;
	d->owner = owner;
}
