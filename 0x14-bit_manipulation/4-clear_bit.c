#include "main.h"
/**
  * clear_bit - responsible for clearing the bit at a specified index position
  * @n: unsinged long int pointer
  * @index: unsigned int of the position that needs to be cleared
  * Return: 1 on success, -1 on error
  */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);
	*n = (~(1UL << index) & *n);
	return (1);
}
