#include "main.h"i

/**
 * _strcspn - computes segment of str 
 * @s: string to be searched
 * @charset: string to be used
 *
 * Return: index at which a char in `s` exists in `charset`
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
 * _strchr - locates a char in a string
 * @s: string to be searched
 * @c: char to be checked
 *
 * Return: pointer to the first occurrence of `c` in `s`
 */
char *_strchr(char *s, char c)
{
        int i = 0;

        for (; s[i] != c && s[i] != '\0'; i++)
                ;
        if (s[i] == c)
	{
                return (s + i);
	}
        else				
	{
                return (NULL);
	}
	return (0);
}

/**
  * _strcmp - compares two strings
  * @s: first string to compare
  * @c: second string to compare
  *
  * Return: return 1 when strings matches
  */



int _strcmp(char *s, char *c)
{
        int i;

        for (i = 0; s[i] && c[i]; i++)
        {
                if (s[i] != c[i])
                        return (0);
        }
        return (1);
}
