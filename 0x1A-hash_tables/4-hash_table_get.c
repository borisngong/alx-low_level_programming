#include "hash_tables.h"

/**
 * hash_table_get - responsible for retrieving the value associated with a key
 * @ht: represnts a pointer to the hash table
 * @key: represents the Key to retrieve the value
 *
 * Return: Value associated with the key, or NULL if the key does not exist
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index = 0;
	hash_node_t *current_node;

	if (!ht || !key || !*key)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	current_node = ht->array[index];

	while (current_node)
	{
		if (!strcmp(key, current_node->key))
			return (current_node->value);

		current_node = current_node->next;
	}

	return (NULL);
}
