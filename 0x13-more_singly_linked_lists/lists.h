#ifndef _LISTS_H_
#define _LIST_H_

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


#endif /* _LIST_H_ */
