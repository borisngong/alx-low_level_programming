#include "lists.h"
/**
  * free_listint2 - frees listint2
  * @head: reference and pointer to the lists first node
  * Retrun: NULL (void)
  */
void free_listint2(listint_t **head)
{
	listint_t *temporal;

	if (head == NULL || *head == NULL)
		return;
	while ((*head)->next != NULL)
	{
		temporal = (*head)->next;
		free(*head);
		*head = temporal;
	}
	free(*head);
	*head = NULL;

}
