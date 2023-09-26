#include "lists.h"
/**
  * sum_listint - return the sum of all data(n) of linked list
  * @head: pointer to the first node of the linked list
  * Return: sum of all data
  */
int sum_listint(listint_t *head)
{
	listint_t *current_node = head;
	int sum = 0;

	while (current_node != NULL)
	{
		sum += current_node->n;
		current_node = current_node->next;
	}
	return (sum);
}
