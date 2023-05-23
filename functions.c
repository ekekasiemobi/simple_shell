#include "main.h"

/**
 * free_array - Frees a dynamically allocated array of strings.
 * @argv: The array of strings to be freed.
 *
 */
void free_array(char **argv)
{
	char **temp = argv;

	for (; *temp != NULL; temp++)
	{
		free(*temp);
		*temp = NULL;
	}
	free(argv);
}


/**
 * s_len - checks how many words are in a string
 * @str: the string whoses word it to be counted
 * Return: the num of words counted
 */
int s_len(char *str)
{
	int i;
	int count;

	count = 0;

	for (i = 0; str[i] != '\0'; i++)
		count++;

	return (count);
}


/**
 * s_copy - copy a string from A to B
 * @to: the place it is coping it to
 * @from: the place it is copying it from
 * Return: void
 */
void s_copy(char *to, char *from)
{
	int i;

	for (i = 0; from[i] != '\0'; i++)
		to[i] = from[i];

	to[i] = '\0';
}


/**
 * s_cat - cat two strings
 * @text_add: where is it adding to
 * @text: where it is adding from
 * Return: void
 */
void s_cat(char *text_add, char *text)
{
	int i;
	int num;

	i = 0;
	num = 0;
	while (text_add[i] != '\0')
		i++;
	for (num = 0; text[num] != '\0'; num++)
		text_add[i++] = text[num];
	text_add[i] = '\0';
}


