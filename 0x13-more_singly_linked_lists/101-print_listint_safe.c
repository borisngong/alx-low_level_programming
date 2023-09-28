#include "lists.h"
/**
  * free_listp - responsible for freeing the memory allocated
  * for a linked list
  * @head: pointer to the head of the linked list
  * Return: (void)
  */
void free_listp(listp_t **head)
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
  * print_listint_safe - prints a linked list safe with loop.
  * @head: pointer to head of list
  * Return: number of nodes on success, 98 exit on failure
  */
size_t print_listint_safe(const listint_t *head)
{
	listp_t *headptr, *node_new, *node_add;
	size_t node_aggregate = 0;

	headptr = NULL;

	while (head != NULL)
	{
		node_new = malloc(sizeof(listp_t));
		if (node_new == NULL)
			exit(98);
		node_new->p = (void *)head;
		node_new->next = headptr;
		headptr = node_new;

		node_add = headptr;

		while (node_add->next != NULL)
		{
			node_add = node_add->next;
			if (head == node_add->p)
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free_listp(&headptr);
				return (node_aggregate);
			}
		}
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
		node_aggregate++;
	}
	free_listp(&headptr);
	return (node_aggregate);
}
