#include "lists.h"
/**
  * *reverse_listint - reponsible for reversing the link list
  * @head: pointer to the first node of the linke list
  * Return: pointer to the first node of reversed list
  */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *previous = NULL;
	listint_t *next = NULL;

	while ((*head) != NULL)
	{
		next = (*head)->next;
		(*head)->next = previous;
		previous = (*head);
		(*head) = next;

	}
	(*head) = previous;

	return (*head);
}
