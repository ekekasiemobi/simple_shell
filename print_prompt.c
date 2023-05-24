#include "main.h"

/**
 * prompt_read - read prompts and displays inputs
 * @fd_check: the number of bytes read by getline
 * Return: user_input
 */

char *prompt_read(ssize_t *fd_check)
{
        char *display_prompt = "$ ";
        char *user_input = NULL;
        size_t bufsize = 0;
		ssize_t read_bytes;

        /* interactive_mode() */
        if (isatty(STDIN_FILENO))
        {
                write(STDOUT_FILENO, display_prompt, 2);
        }

        read_bytes = getline(&user_input, &bufsize, stdin);
        if (read_bytes == -1)
        {
                if (isatty(STDIN_FILENO))
                        write(STDOUT_FILENO, "\n", 1);
                free(user_input);
                exit(EXIT_SUCCESS);
        }
        *fd_check = read_bytes;

        if (*fd_check == 1 && user_input[0] == '\n')
        {
                free(user_input);
                return prompt_read(fd_check);
        }

        user_input[strcspn(user_input, "\n")] = '\0';
        return user_input;
}

