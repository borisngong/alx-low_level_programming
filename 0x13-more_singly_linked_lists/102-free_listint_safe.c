#include "lists.h"
/**
  * free_listpp- responsible for freeing the memory allocated
  * for a linked list
  * @head: pointer to the head of the linked list
  * Return: (void)
  */
void free_listpp(listp_t **head)
{
	listp_t *temporal_node;
	listp_t *current_node;

	if (head != NULL)
	{
		current_node = *head;
		while ((temporal_node = current_node) != NULL)
		{
			current_node = current_node->next;
			free(temporal_node);
		}
		*head = NULL;
	}

}
/**
  * free_listint_safe - frees a linked list safe with loop.
  * @h: pointer to head of list
  * Return: number of nodes on success, 98 exit on failure
  */
size_t free_listint_safe(listint_t **h)
{
	listp_t *headptr, *node_new, *node_add;
	size_t node_aggregate = 0;
	listint_t *current_node;

	headptr = NULL;

	while (*h != NULL)
	{
		node_new = malloc(sizeof(listp_t));
		if (node_new == NULL)
			exit(98);
		node_new->p = (void *)*h;
		node_new->next = headptr;
		headptr = node_new;

		node_add = headptr;

		while (node_add->next != NULL)
		{
			node_add = node_add->next;
			if (*h == node_add->p)
			{
				*h = NULL;
				free_listpp(&headptr);
				return (node_aggregate);
			}
		}
		current_node = *h;
		*h = (*h)->next;
		free(current_node);
		node_aggregate++;
	}
	*h = NULL;
	free_listpp(&headptr);
	return (node_aggregate);
}
