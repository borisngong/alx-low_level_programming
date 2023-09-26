#include "lists.h"
/**
  * *add_nodeint - adds a new node at the beginning of a listint_t list
  * @head: holds reference and pointer
  * @n: new integer to be  created
  * Return: address of element on success, NULL on failure
  */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	if (head == NULL)
		return (0);

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	if (*head == NULL)
		new->next = NULL;
	else
		new->next = *head;
	new->n = n;
	*head = new;

	return (*head);
}
