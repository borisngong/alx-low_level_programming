#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - function that returns the length of a string
 * @s: string to evaluate
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int k;

	k = 0;

	while (s[k] != '\0')
	{
		k++;
	}

	return (k);
}

/**
 * *_strcpy - function that copiescopies the string pointed to by src
 * including the terminating null byte (\0)
 * to the buffer pointed to by dest
 * @dest: pointer to the buffer in which string is copied
 * @src: string to be copied
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int longi, k;

	longi = 0;

	while (src[longi] != '\0')
	{
		longi++;
	}

	for (k = 0; k < longi; k++)
	{
		dest[k] = src[k];
	}
	dest[k] = '\0';

	return (dest);
}

/**
 * new_dog - creates a new dog with new members
 * @name: dog's name
 * @age: new dog's age
 * @owner: new dog's owner
 * Return: pointer to the new dog (Success), NULL otherwise
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;
	int longi1, longi2;

	longi1 = _strlen(name);
	longi2 = _strlen(owner);

	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	dog->name = malloc(sizeof(char) * (longi1 + 1));
	if (dog->name == NULL)
	{
		free(dog);
		return (NULL);
	}

	dog->owner = malloc(sizeof(char) * (longi2 + 1));
	if (dog->owner == NULL)
	{
		free(dog);
		free(dog->name);
		return (NULL);
	}
	_strcpy(dog->name, name);
	_strcpy(dog->owner, owner);
	dog->age = age;

	return (dog);
}

