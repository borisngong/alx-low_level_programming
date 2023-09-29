#include "main.h"
/**
  * get_endianness - function use to determine the endianness of underlying
  * system and takes no arguments.
  * Return: integer value indicating endianness of system
  */
int get_endianness(void)
{
	unsigned int value = 1;
	char *ptr = (char *) &value;

	return (*ptr);
}

