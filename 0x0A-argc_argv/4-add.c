#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/**
 * check_num - check - string there are digit
 * @str: array str
 * Return: Always 0 (Success)
 */
int check_num(char *str)
{
	unsigned int sumup;

	sumup = 0;
	while (sumup < strlen(str))

	{
		if (!isdigit(str[sumup]))
		{
			return (0);
		}

		sumup++;
	}
	return (1);
}

/**
 * main - Print the name of the program
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 (Always Successful)
 */

int main(int argc, char *argv[])

{
	int sumup;
	int str_to_int;
	int addup = 0;

	sumup = 1;
	while (sumup < argc)
	{
		if (check_num(argv[sumup]))

		{
			str_to_int = atoi(argv[sumup]);
			addup += str_to_int;
		}
		else
		{
			printf("Error\n");
			return (1);
		}

		sumup++;
	}

	printf("%d\n", addup);

	return (0);
}

