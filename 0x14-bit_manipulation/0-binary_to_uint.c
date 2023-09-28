#include "main.h"
/**
  * binary_to_uint - responsible for converting a binary number to usinged int
  * @b: pointer to the binary string
  * Return: the converted number, or 0 if there is one or more characters not
  * 0 0r and b is NULL
  */
unsigned int binary_to_uint(const char *b)
{
	int k;
	unsigned int converted_result;

	if (!b)
		return (0);
	converted_result = 0;

	for (k = 0; b[k]; k++)
	{
		if (b[k] < '0' || b[k] > '1')
			return (0);
		converted_result = 2 * converted_result + (b[k] - '0');
	}
	return (converted_result);
}
