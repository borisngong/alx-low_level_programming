#include "lists.h"
/**
 * *get_dnodeint_at_index - reponsible for returning the nth node
 * of a dlistint_t linked list
 * @head: represents the pointer at the head of a list
 * @index: node's index, starting from 0
 * Return:  Pointer to the nth node, or NULL if the node does not exist
*/
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int aggregate = 0;
	dlistint_t *current = head;

	while (current != NULL)
	{
		if (aggregate == index)
		{
			return (current);
		}
		current = current->next;
		aggregate++;
	}
	return (NULL);
}
