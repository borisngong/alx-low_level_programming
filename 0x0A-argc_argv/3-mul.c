#include <stdio.h>
#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 * Return: the int converted from the string
 */
int _atoi(char *s)
{
	int j; int k; int l; int longi;  int figure; int m;

	j = 0;
	k = 0;
	l = 0;
	longi = 0;
	m = 0;
	figure = 0;

	while (s[longi] != '\0')
		longi++;

	while (j < longi && m == 0)
	{
		if (s[j] == '-')
			++k;

		if (s[j] >= '0' && s[j] <= '9')
		{
			figure = s[j] - '0';
			if (k % 2)
				figure = -figure;
			l = l * 10 + figure;
			m = 1;
			if (s[j + 1] < '0' || s[j + 1] > '9')
				break;
			m = 0;
		}
		j++;
	}

	if (m == 0)
		return (0);

	return (l);
}

/**
 * main - A programm that multiplies two numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 if succesful and 1 (Error)
 */
int main(int argc, char *argv[])
{
	int solution; int digit1; int digit2;

	if (argc < 3 || argc > 3)
	{
		printf("Error\n");
		return (1);
	}

	digit1 = _atoi(argv[1]);
	digit2 = _atoi(argv[2]);
	solution = digit1 * digit2;

	printf("%d\n", solution);

	return (0);
}

