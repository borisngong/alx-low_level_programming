#include "hash_tables.h"

/**
 * hash_table_print - responsible for printing the key-value pairs from
 * the hash table
 * @ht: Pointer to the hash table
 * Return: Always void
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i = 0;
	hash_node_t *current_node;
	int is_first_pair = 1;

	if (!ht)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		current_node = ht->array[i];
		while (current_node)
		{
			if (!is_first_pair)
				printf(", ");
			printf("'%s': '%s'", current_node->key, current_node->value);
			is_first_pair = 0;
			current_node = current_node->next;
		}
	}
	printf("}\n");
}
