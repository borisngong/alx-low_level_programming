#include "lists.h"
/**
  * *get_nodeint_at_index - reponsible for for locating and returning the node
  *  at specified index in the linked list
  * @head: represents the first node of the linked list.
  * @index: specifies the position of the desired node in the linked lis
  * Return: pointer to node at desired index, NULL (if empty) 
  */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *current_node = head;
	unsigned int ind_positn = 0;

	while (current_node != NULL)
	{
		if (ind_positn == index)
		{
			return (current_node);
		}
		current_node = current_node->next;
		ind_positn++;

	}
	
	return (NULL);
}
