#include "lists.h"
/**
 * *add_dnodeint_end - responsible for adding a  new node at the end
 * of a dlistint_t list
 * @n: represents the integer value of the new node
 * @head: represents a double pointer to the list
 * Return: the address of the new element, or NULL if it failed
*/
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *current;

	dlistint_t *new_node = malloc(sizeof(dlistint_t));

	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->next = NULL;
	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
	}
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
		current->prev = current;
	}
	return (new_node);





}
