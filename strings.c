#include "main.h"

/**
 * _atoi - changes strings to integer
 * @s: string to be converteed
 *
 * Return: string converted
 */
int _atoi(char *str)
{
	unsigned int result = 0;
	int i = 0;

	for (i = 0; str[i] != '\0'; i++) 
	{
		if (str[i] == '-')
		{
			return (-1);
		}
		else if ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
		{
			return (-1);
		}
		else if (str[i] >= '0'  && str[i] <= '9')
		{
			result = (result * 10) + (str[i] - '0');
		}
		else if (result > 0)
		{
			break;
		}
	}

	return (result);
}

/**
 * _strchr - finds a character c in a string s
 * @s: string where c is to be searched
 * @c: the character to be checked which is c
 *
 * Return: the first occurrence of character `c` in string `s`
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			return (s + i);
		}
		i++;
	}

	return NULL;
}

/**
 * _strcspn - finds char not found in the charset
 * @s: the string 's' to be checked
 * @charset: the  string 'charset' to be checked
 *
 * Return: the point where a char in `s` is found in `charset`
 */
int _strcspn(char *s, char *charset)
{
	int count = 0, i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (_strchr(charset, s[i]) != NULL)
		{
			break;
		}
		count++;
	}

	return (count);
}

/**
 * _strcmp - it  compares two str
 * @s: first str 's' to be compared
 * @c: second str 'c' to be compared
 *
 * Return: returns 1 when str in 's' and 'c' matches
 */
int _strcmp(char *s, char *c)
{
	int i;

	for (i = 0; s[i] && c[i]; i++)
	{
		if (s[i] != c[i])
		{
			return (0);
		}
	}

	return (1);
}
