#include "lists.h"

/**
 * insert_dnodeint_at_index - reponsible for inserting a new node at a given
 * position in a dlistint_t linked list
 * @h: represents a double pointer to the head of the list
 * @idx: represents an index where the new node should be added,
 * starting from 0
 * @n: represents an integer value for the new node
 * Return: Address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *current;
	unsigned int aggregate = 0;

	if (h == NULL)
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));

	current = *h;
	while (current != NULL && aggregate < idx - 1)
	{
		current = current->next;
		aggregate++;
	}
	if (current == NULL)
		return (NULL);

	/* Create the new node */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = current->next;
	new_node->prev = current;

	if (current->next != NULL)
		current->next->prev = new_node;
	current->next = new_node;

	return (new_node);
}
