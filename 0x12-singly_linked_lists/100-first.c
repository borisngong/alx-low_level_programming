#include <stdio.h>

void first(void) __attribute__ ((constructor));

/**
 * first - function to print sentences before the execution of main
 */
void first(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}

