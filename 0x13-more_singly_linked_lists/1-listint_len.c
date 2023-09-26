#include "lists.h"
/**
  * listint_len -  determine number of elements in single linke list
  * @h: holds the refernce and pointer counts number of elements or nodes
  * Return: number of elements
  */
size_t listint_len(const listint_t *h)
{
	size_t tally;

	if (h == NULL)
		return (0);

	for (tally = 0; h != NULL; tally++)
	{
		h = h->next;
	}
	return (tally);
}
