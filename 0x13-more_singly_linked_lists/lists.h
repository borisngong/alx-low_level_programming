#ifndef _LISTS_H_
#define _LISTS_H_

#include <stdlib.h>
#include <stdio.h>

/**
  * struct listint_s - a data struct that represents a linked list
  * of integers whichallows for the creation and manupulation of linked lists
  *
  * @n: inteder value and pointer to the next node
  * @next: holds the refernce or poirter to the next node
  */

typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

size_t print_listint(const listint_t *h);
size_t listint_len(const listint_t *h);
listint_t *add_nodeint(listint_t **head, const int n);
listint_t *add_nodeint_end(listint_t **head, const int n);
void free_listint(listint_t *head);
void free_listint2(listint_t **head);
int pop_listint(listint_t **head);


#endif /* _LISTS_H_ */
