#include "lists.h"
/**
  * *insert_nodeint_at_index - a function that inserts a new node at
  * a given position
  * @idx: index where new node should be inserted in the linked list
  * @head: double pointer to the head of linked list
  * @n: value to be stored in new node
  * Return: address of new node, Null if failed
  * if not possible to add new node at idx, don't add and return Null
  */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node;

	new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return (NULL);
	new_node->n = n;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
	}
	else
	{
		listint_t *current_node = *head;
		unsigned int k;

		for (k = 0; k < idx - 1 && current_node != NULL; k++)
		{
			current_node = current_node->next;
		}
		if (current_node == NULL)
		{
			free(new_node);
			return (NULL);
		}
		new_node->next = current_node->next;
		current_node->next = new_node;
	}
	return (new_node);
}
