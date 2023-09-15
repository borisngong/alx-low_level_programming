#include <stdio.h>
#include <stdlib.h>

/**
 * main - a programm that prints  opcodes with its main function
 * @argc: number of arguments
 * @argv: argument vector
 * Return: 0 (Always Successful)
 */
int main(int argc, char *argv[])
{
	int count, k;
	char *boro;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	count = atoi(argv[1]);

	if (bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	boro = (char *)main;

	for (k = 0; k < count; k++)
	{
		if (k == count - 1)
		{
			printf("%02hhx\n", boro[k]);
			break;
		}
		printf("%02hhx ", boro[k]);
	}
	return (0);
}
