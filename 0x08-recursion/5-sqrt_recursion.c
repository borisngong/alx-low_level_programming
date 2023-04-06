#include "main.h"
int actual_sqrt_recursion(int n, int i);
/**
  *_sqrt_recursion - returns actual square root of a number
  *@n: number used to calculate actual square root
  *Return: The square root of number
  */
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	return (actual_sqrt_recursion(n, 0));
}

/**
  *actual_sqrt_recursion - recurse to find natural square root
  *@n: number to calculate square root
  *@i: iterator
  *Return: Natural sqare root of number
  */
int actual_sqrt_recursion(int n, int i)
{
	if (i * i > n)
	{
	return (-1);
	}
	if (i * i == n)
	{
		return (i);
	}
	return (actual_sqrt_recursion(n, i + 1));
}
