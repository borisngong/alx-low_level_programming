#include "lists.h"
/**
  * *find_listint_loop - responsible for finding loop in the linked list
  * @head: pointer to the head of a linked list
  * Return: address of node where loop starts, null if there's no loop
  */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *steady = head;
	listint_t *rapid = head;

	while (steady && rapid && rapid->next)
	{
		steady = steady->next;
		rapid = rapid->next->next;

		if (steady == rapid)
		{
			steady = head;
			while (steady != rapid)
			{
				steady = steady->next;
				rapid = rapid->next;
			}
			return (steady);
		}
	}

	return (NULL); 
}
