#include "main.h"

/**
 * parse_user_input - split user's command strings
 * @take_user_input: pointer to user_input
 * @argv: array of pointer to strings
 * @fd_check: size of input read in bytes
 * Return: array of pointer to strings
 */

char **parse_user_input(char *take_user_input, char **argv, ssize_t fd_check)
{
        char *user_input_copy, *parse_token;
        const char *delimiter;
        int token_count = 0, num;

        delimiter = " \n";

        user_input_copy = malloc(sizeof(char) * (fd_check + 1));
        if (user_input_copy == NULL)
        {
                perror("Error: cannot allocate memory");
                return (NULL);
        }
        /* add null byte to end */
        s_copy(user_input_copy, take_user_input);
        user_input_copy[fd_check] = '\0';
        parse_token = strtok(user_input_copy, delimiter);

        while (parse_token != NULL)
        {
                token_count++;
                parse_token = strtok(NULL, delimiter);
        }
        token_count++;

        argv = malloc(sizeof(char *) * token_count);
        if (argv == NULL)
        {
                perror("Error: cannot allocate memory");
                return (NULL);
        }

        parse_token = strtok(take_user_input, delimiter);
        for (num = 0; parse_token != NULL; num++)
        {
                argv[num] = malloc(sizeof(char) * (s_len(parse_token) + 1));
                if (argv[num] == NULL)
                {
                        perror("Error: cannot allocate memory");
                        return (NULL);
                }
                s_copy(argv[num], parse_token);
                parse_token = strtok(NULL, delimiter);
        }
        argv[num] = NULL;

        free(user_input_copy);

        return (argv);
}
