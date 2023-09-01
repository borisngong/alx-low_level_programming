#include "main.h"
/**
 * _atoi - a function to convert a string into an integer
 * @s: the string to use
 * Return: integer
 */
int _atoi(char *s)
{
	int str = 1, t = 0;
	unsigned int inte = 0;

	while (!(s[t] <= '9' && s[t] >= '0') && s[t] != '\0')
	{
		if (s[t] == '-')
			str *= -1;
		t++;
	}
	while (s[t] <= '9' && (s[t] >= '0' && s[t] != '\0'))
	{
		inte = (inte * 10) + (s[t] - '0');
		t++;
	}
	inte *= str;
	return (inte);
}


