#include "lists.h"

/**
 * delete_dnodeint_at_index - responsible for deleting the node at a given
 * index in a dlistint_t linked list
 * @head: represnts a double pointer to the head of the list
 * @index: represents the index of the node to be deleted, starting from 0
 * Return: 1 if the deletion succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current, *temp;
	unsigned int aggregate = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;

	if (index == 0)
	{
		*head = current->next;
		if (*head != NULL)
			(*head)->prev = NULL;

		free(current);
		return (1);
	}

	while (current != NULL && aggregate < index)
	{
		current = current->next;
		aggregate++;
	}

	if (current == NULL)
		return (-1);

	temp = current;
	current->prev->next = current->next;
	if (current->next != NULL)
		current->next->prev = current->prev;

	free(temp);
	return (1);
}
