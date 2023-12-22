#include "hash_tables.h"
/**
 * hash_table_set - responsible for adding an element to the hash table.
 * @ht: a pointer to the hash table.
 * @key: represents the key to add the element.
 * @value: respresents the value to add the element.
 * Return: 1 if it succeeded, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index = 0;
	char *value_copy, *key_copy;
	hash_node_t *current_node, *new_node;

	if (!ht || !key || !*key || !value)
		return (0);
	value_copy = strdup(value);
	if (!value_copy)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	current_node = ht->array[index];
	while (current_node)
	{
		if (!strcmp(key, current_node->key))
		{
			free(current_node->value);
			current_node->value = value_copy;
			return (1);
		}
		current_node = current_node->next;
	}
	new_node = calloc(1, sizeof(hash_node_t));
	if (new_node == NULL)
	{
		free(value_copy);
		return (0);
	}
	key_copy = strdup(key);
	if (!key_copy)
	{
		free(value_copy);
		free(new_node);
		return (0);
	}
	new_node->key = key_copy;
	new_node->value = value_copy;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	return (1);
}
