#include "lists.h"
/**
  * delete_nodeint_at_index - a function that deletes the node
  * at an index of linked list
  * @head: pointer to the first node of the list
  * @index: index of node that should be deleted
  * Return: 1 on success, -1 if failed
  */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current_node = *head;
	listint_t *previous_node = NULL;
	unsigned int aggregate = 0;

	if (*head == NULL)
	{
		return (-1);
	}
	if (index == 0)
	{
		listint_t (*temp) = (*head);
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	while (current_node != NULL)
	{
		if (aggregate == index)
		{
			previous_node->next = current_node->next;
			free(current_node);
			return(1);
		}
		previous_node = current_node;
		current_node = current_node->next;
		aggregate++;

	}
	return (-1);
}
