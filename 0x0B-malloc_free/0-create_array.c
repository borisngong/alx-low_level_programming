#include "main.h"
#include <stdlib.h>
/**
  **create_array - creates an array of chars,
  *and initializes it with a specific char c
  *@size: size of an array
  *@c: character to be assigned
  *Description: Create an array an assign an char c to it
  *Return: Null if fails 0r pointer to the array
  */
char *create_array(unsigned int size, char c)
{
	unsigned int j;
	char *string;

	/*Dynamically allocate memory using malloc*/
	string = malloc(sizeof(char) * size);
	if ((size == 0) || (string == NULL))
		return (NULL);
	for (j = 0; j < size; j++)
		string[j] = c;
	return (string);
}


