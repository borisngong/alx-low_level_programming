#include "lists.h"
/**
  * pop_listint - deletes head of node linked list, and returns
  * head node's data
  * @head: reference or pointer to the linked list first node
  * Return: return heads node data on success, if empty return 0
  */
int pop_listint(listint_t **head)
{
	int n;
	listint_t *temporal;

	if (head == NULL || *head == NULL)
		return (0);

	n = (*head)->n;
	temporal = *head;
	*head = (*head)->next;
	free(temporal);

	return (n);
}
