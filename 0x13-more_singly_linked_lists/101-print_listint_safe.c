#include "lists.h"
/**
 * print_listint_safe - prints elements of  a listint_t linked list
 * safe even if it contains a loop
 * @head: pointer to the head of the linked list
 * Return: number of nodes in the list, exit 98 on failure
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current_node = head;
	size_t aggregate = 0;

	while (current_node != NULL)
	{
		printf("[%p] %d\n", (void *)current_node, current_node->n);
		aggregate++;

		if (current_node <= current_node->next)
		{
			printf("-> [%p] %d\n", (void *)current_node->next, current_node->next->n);
			exit(98);
		}
		current_node = current_node->next;
	}

	return (aggregate);
}
