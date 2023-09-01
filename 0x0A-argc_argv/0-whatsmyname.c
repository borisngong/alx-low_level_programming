#include <stdio.h>
#include "main.h"

/**
 * main - A programm that prints its name
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 (Always Successful)
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", *argv);

	return (0);
}

