#include "hash_tables.h"

/**
 * sorted_list - responsible for inserting a new node in a sorted manner.
 * @ht: represents a pointer to the sorted hash table.
 * @new_node: represents a node to be inserted.
 * Return: Always void
 */
void sorted_list(shash_table_t *ht, shash_node_t *new_node)
{
    shash_node_t *current = ht->shead;

    if (current == NULL)
    {
        ht->shead = ht->stail = new_node;
        new_node->snext = new_node->sprev = NULL;
        return;
    }

    while (current)
    {
        if (strcmp(new_node->key, current->key) < 0)
        {
            new_node->snext = current;
            new_node->sprev = current->sprev;

            if (!current->sprev)
                ht->shead = new_node;
            else
                current->sprev->snext = new_node;

            current->sprev = new_node;
            return;
        }

        current = current->snext;
    }

    new_node->sprev = ht->stail;
    new_node->snext = ht->stail->snext;
    ht->stail->snext = new_node;
    ht->stail = new_node;
}

/**
 * shash_table_create - responsible for creating a sorted hash table.
 * @size: Represents the size of the hash table.
 *
 * Return: A pointer to the created hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *ht;

    if (size == 0)
        return NULL;

    ht = calloc(1, sizeof(shash_table_t));
    if (ht == NULL)
        return NULL;

    ht->size = size;
    ht->array = calloc(size, sizeof(shash_node_t *));
    if (ht->array == NULL)
    {
        free(ht);
        return NULL;
    }

    return ht;
}

/**
 * shash_table_set - function that adds an element to the sorted hash table
 * @ht: represents a pointer to sorted hash table
 * @key: represnts the key to add the element
 * @value: represents the value to add the element
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index = 0;
    char *value_copy, *key_copy;
    shash_node_t *node, *new_node;

    if (!ht || !key || !*key || !value)
        return 0;
    value_copy = strdup(value);
    if (!value_copy)
        return 0;
    index = key_index((const unsigned char *)key, ht->size);
    node = ht->array[index];

    while (node)
    {
        if (!strcmp(key, node->key))
        {
            free(node->value);
            node->value = value_copy;
            return 1;
        }
        node = node->next;
    }
    new_node = calloc(1, sizeof(shash_node_t));
    if (new_node == NULL)
    {
        free(value_copy);
        return 0;
    }
    key_copy = strdup(key);
    if (!key_copy)
    {
        free(new_node);
        return 0;
    }
    new_node->key = key_copy;
    new_node->value = value_copy;
    new_node->next = ht->array[index];
    ht->array[index] = new_node;
    sorted_list(ht, new_node);
    return 1;
}

/**
 * shash_table_get - responsible for retrieving the value associated with a key.
 * @ht: Pointer to the hash table.
 * @key: Key to retrieve the value.
 *
 * Return: Value associated with the key, or NULL if the key does not exist.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    unsigned long int index = 0;
    shash_node_t *node;

    if (!ht || !key || !*key)
        return NULL;

    index = key_index((const unsigned char *)key, ht->size);
    node = ht->array[index];

    while (node)
    {
        if (!strcmp(key, node->key))
            return node->value;

        node = node->next;
    }

    return NULL;
}

/**
 * shash_table_print - responsible for printing the key-value pairs
 * from a hash table.
 * @ht: Pointer to the hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *node;
    int not_first = 0;

    if (ht == NULL)
        return;

    printf("{");
    node = ht->shead;

    while (node)
    {
        if (not_first)
            printf(", ");
        printf("'%s': '%s'", node->key, node->value);
        not_first = 1;
        node = node->snext;
    }

    printf("}\n");
}

/**
 * shash_table_print_rev - responsible for printing the key-value pairs from
 * a hash table in reverse.
 * @ht: Pointer to the hash table.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *node;
    int not_first = 0;

    if (ht == NULL)
        return;

    printf("{");
    node = ht->stail;

    while (node)
    {
        if (not_first)
            printf(", ");
        printf("'%s': '%s'", node->key, node->value);
        not_first = 1;
        node = node->sprev;
    }

    printf("}\n");
}

/**
 * shash_table_delete - responsible for deleting a sorted hash table.
 * @ht: Pointer to the hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
    shash_node_t *node, *temp;
    unsigned long int i;

    if (ht == NULL)
        return;

    for (i = 0; i < ht->size; i++)
    {
        node = ht->array[i];
        while (node)
        {
            temp = node;
            node = node->next;
            free(temp->key);
            free(temp->value);
            free(temp);
        }
    }

    free(ht->array);
    free(ht);
}