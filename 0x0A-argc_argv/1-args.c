#include <stdio.h>
#include "main.h"

/**
 * main - A programm that print all received arguments passed to it
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 (Always Successful)
 */

int main(int argc, char *argv[])
{
	(void) argv;
	printf("%d\n", argc - 1);

	return (0);
}

