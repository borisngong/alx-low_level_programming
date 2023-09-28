#include "main.h"
/**
  * get_bit - returns the given bit at a given bit value at the spcified
  * index position
  * @n: unsigned long int
  * @index: unsigned (position of the bit)
  * Return: value of the bit at position index; -1 (error)
  */
int get_bit(unsigned long int n, unsigned int index)
{
	int binary_digit;

	if (index > 63)
		return (-1);

	binary_digit = (n >> index) & 1;

	return (binary_digit);
}
