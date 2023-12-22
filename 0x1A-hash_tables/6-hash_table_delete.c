#include "hash_tables.h"

/**
 * hash_table_delete - responsible for freeing the hash table and all its nodes
 * @ht: represents a pointer to the hash table
 * Return: always void
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *current_node, *node_to_free;
	unsigned long int i = 0;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{
		current_node = ht->array[i];
		while (current_node)
		{
			node_to_free = current_node;
			current_node = current_node->next;
			if (node_to_free->key)
				free(node_to_free->key);
			if (node_to_free->value)
				free(node_to_free->value);
			free(node_to_free);
		}
	}
	free(ht->array);
	free(ht);
}
