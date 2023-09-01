#include "main.h"
#include <stddef.h>
/**
 * _strchr - Entry point
 * @s: input
 * @c: input
 * Return: 0 (Always Successful)
 */
char *_strchr(char *s, char c)
{
	int t = 0;

	for (; s[t] >= '\0'; t++)
	{
		if (s[t] == c)
			return (&s[t]);
	}
	return (0);
}

