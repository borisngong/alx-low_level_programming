#include "main.h"

int actual_prime(int n, int i);

/**
 * is_prime_number - function that checks if an integer
 *is a prime number or otherwise
 * @n: input number to check
 * Return: 1 if n is a prime number, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (actual_prime(n, n - 1));
}

/**
 * actual_prime - recursively calculate if number is a prime number
 * @n: number to check
 * @itr: iterator
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int actual_prime(int n, int itr)
{
	if (itr == 1)
		return (1);
	if (n % itr == 0 && itr > 0)
		return (0);
	return (actual_prime(n, itr - 1));
}

