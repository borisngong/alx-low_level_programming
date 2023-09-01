#include <stdio.h>
#include "main.h"

/**
 * main - programm that prints all arguments it receives
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 (Always Successful)
 */
int main(int argc, char *argv[])
{
	int k;

	for (k = 0; k < argc; k++)
	{
		printf("%s\n", argv[k]);
	}

	return (0);
}

