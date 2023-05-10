#include "main.h"



/**
 * s_len - counts the length of a string
 * @string: string whose length is to be counted
 * Return: the length of the string
 */
int s_len(char *string)
{
	int num = 0;

	while (*string++)
		num++;

	return (num);
}


/**
 * s_copy - copy strings
 * @to: destination it is copying to
 * @from: where it is copying from
 * Return: void
 */
void s_copy(char *to, char *from)
{
	while ((*to++ = *from++))
		;
}


/**
 * s_cat - cat two strings
 * @text_add: where is it adding to
 * @text: where it is adding from
 * Return: void
 */
void s_cat(char *text_add, char *text)
{
	while (*text_add)
                text_add++;
        while ((*text_add++ = *text++))
                ;
}
