#include "lists.h"
/**
  * *add_nodeint_end - adds nodes at the end of the lisnt_int_t list
  * @n: new list data
  * @head: holds reference or pointer to the head
  * Return: the address of new element on success, NULL if failed
  */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new;
	listint_t *temporal;

	(void) temporal;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;
	temporal = *head;
	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		while (temporal->next != NULL)
		{
			temporal = temporal->next;
		}
		temporal->next = new;
	}

	return (*head);
}
