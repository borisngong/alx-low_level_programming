#include "main.h"
/**
  * flip_bits - calculates number of flip bits bewtween two uunsigned long ints
  * @n: unsigned long int first number
  * @m: unsigned long int second number
  * Return: flipped bits count
  */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int bit_position, flipped_bit_count = 0;
	unsigned long int current_bit;
	unsigned long int xor_result = n ^ m;

	for (bit_position = 63; bit_position >= 0; bit_position--)
	{
		current_bit = xor_result >> bit_position;
		if (current_bit & 1)
			flipped_bit_count++;
	}

	return flipped_bit_count;
}
