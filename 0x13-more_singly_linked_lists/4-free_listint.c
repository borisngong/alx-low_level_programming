#include "lists.h"
/**
  * free_lintint -  a function that frees a listint_t list
  * @head: refence or pointer to list first node
  * Return: (void)
  */
void free_listint(listint_t *head)
{
	listint_t *temporal;

	while ((temporal = head) != NULL)
	{
		head = head->next;
		free(temporal);
	}
}
