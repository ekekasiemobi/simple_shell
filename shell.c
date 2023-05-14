#include "main.h"


/**
 * main - shell clone
 * @ac: argument count
 * @argv: array of pointer to strings
 * Return: 1 or 0
 */
int main(int ac, char **argv)
{
    char *user_input;
    ssize_t fd_check;
    char **receive_argv;
    char **args = NULL;
	int i;
    (void)ac;
    (void)argv;


    /* TODO: you'll need a way to create a dynamic array */

    while (1)
    {
        user_input = NULL;
        fd_check = 0;

        user_input = prompt_read(&fd_check);
        /* parse user's command */
        receive_argv = tokenization(user_input, args, fd_check);

        if (strcmp(receive_argv[0], "exit") == 0)
        {
		free(user_input);
            exit_shell(receive_argv);
            continue;
        }

       i = execute_command(receive_argv);
        fflush(stdout);
	if (i == 1)
		 print_error(receive_argv, "command not found\n");		
	free(user_input);

        free_array(receive_argv);

    }
	
}

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
