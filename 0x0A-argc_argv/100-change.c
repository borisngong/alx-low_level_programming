#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - A programm that prints the minimum number of 
 * coins to make change for an amount of money
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 (Always Success), 1 (Error)
 */
int main(int argc, char *argv[])
{
	int digit, k, cents;
	int coins[] = {25, 10, 5, 2, 1};

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	digit = atoi(argv[1]);
	cents = 0;

	if (digit < 0)
	{
		printf("0\n");
		return (0);
	}

	for (k = 0; k < 5 && digit >= 0; k++)
	{
		while (digit >= coins[k])
		{
			cents++;
			digit -= coins[k];
		}
	}

	printf("%d\n", cents);
	return (0);
}

