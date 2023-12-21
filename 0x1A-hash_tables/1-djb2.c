#include "hash_tables.h"
/**
 * hash_djb2 - Hash function responsible to compute hash of a
 * string using djb2 algorithm
 * @str: represents the string to hash
 *
 * Return: Value of the hash
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}
	return (hash);
}
