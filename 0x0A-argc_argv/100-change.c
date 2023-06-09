#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - A program that prints min number of coins to change an amount
 * @argc: argument counts
 * @argv: argument vector
 *
 * Return: 0 (Success), 1 (Error)
 */
int main(int argc, char *argv[])
{
	int min_num, i, total;
	int coins[] = {25, 10, 5, 2, 1};

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	min_num = atoi(argv[1]);
	total = 0;

	if (min_num < 0)
	{
		printf("0\n");
		return (0);
	}

	for (i = 0; i < 5 && min_num >= 0; i++)
	{
		while (min_num >= coins[i])
		{
			total++;
			min_num -= coins[i];
		}
	}

	printf("%d\n", total);
	return (0);
}

