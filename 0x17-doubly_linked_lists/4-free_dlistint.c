#include "lists.h"
/**
 * free_dlistint - responsible for freeing a dlistint_t list
 * @head: represents a double pointer to the head of a list
*/
void free_dlistint(dlistint_t *head)
{
    dlistint_t *current;
    while (head != NULL)
    {
        current = head;
        head = head->next;
        free(current);
    }
}