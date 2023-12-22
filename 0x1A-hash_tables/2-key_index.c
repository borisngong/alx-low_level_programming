#include "hash_tables.h"
/**
 * key_index - responsible for computing the index of a key in a hash table
 * @key: represents the key to compute the index for
 * @size: represents the size of the hash table
 *
 * Return: the computed index of the key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
