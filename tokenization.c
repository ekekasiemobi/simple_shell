#include "main.h"

/**
 * tokenize_string - Splits a string into an array of tokens.
 * @string: The string to tokenize.
 * @delimiter: The character to use as a delimiter.
 *
 * Return: An array of tokens.
 */
char **tokenizer(char *string, char *delimiter)
{
        int num_delimiter = 0;
        char **av = NULL;
        char *token = NULL;
        char *save_ptr = NULL;

        token = _strtok_r(string, delimiter, &save_ptr);

        while (token != NULL)
        {
                av = realloc(av, sizeof(*av) * (num_delimiter + 1));
                av[num_delimiter] = token;
                token = _strtok_r(NULL, delimiter, &save_ptr);
                num_delimiter++;
        }

        av = realloc(av, sizeof(*av) * (num_delimiter + 1));
        av[num_delimiter] = NULL;

        return (av);
}
