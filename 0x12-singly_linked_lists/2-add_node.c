#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - a function thatadds a new node at the beginning of a linked list
 * @head: list_t lists double pointer
 * @str: additional string to node
 *
 * Return: new element's address, and on failuere (NULL)
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	unsigned int len = 0;

	while (str[len])
		len++;

	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);
	new->str = strdup(str);
	new->len = len;
	new->next = (*head);
	(*head) = new;

	return (*head);
}

