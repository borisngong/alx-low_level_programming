#include "main.h"
/**
  * set_bit - set bit at the specified index position in unsigned long int to 1
  * @n: pointer to the unsigned long int
  * @index: unsigned int of position of bit that needs to be set
  * Return: 1 on success, -1 on failure
  */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);
	*n = ((1UL << index) | *n);
	return (1);
}
