#include "lists.h"
/**
  * print_listint - function to print elements of the link list
  * @h: head pointer variable
  * Return: number of nodes in the list
  */
size_t print_listint(const listint_t *h)
{
	size_t bytes;

	if (h == NULL)
		return (0);

	for (bytes = 0; h != NULL; bytes++)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
	return (bytes);
}
