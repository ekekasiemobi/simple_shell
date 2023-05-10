#include "main.h"

/**
 * main - shell clone
 * @ac: argument count
 * @argv: array of pointer to strings
 * Return: 1 or 0
 */


int main(int ac, char **argv)
{
	char **current_cmd = NULL;
        int i, cmd_type = 0;
        size_t n = 0;

	char *user_input;
	ssize_t fd_check;
	char **args;
	(void)ac;
	(void)argv;

	 signal(SIGINT, SIG_IGN);
         shell_name = argv[0];

	args = malloc(sizeof(char *) * 10);
	/* TODO: you'll need a way to create a dynamic array */

	while (1 == 1)
	{
		void (*command)(void);

		user_input = NULL;
		fd_check = 0;

		user_input = prompt_read(&fd_check);
		cmds = tokenizer(line, ";");
                for (i = 0; cmds[i] != NULL; i++)
                {
                        current_cmd = tokenizer(cmds[i], " ");
                        if (current_cmd[0] == NULL)
                        {
                                free(current_cmd);
                                break;
                        }
                        cmd_type = determine_command_type(current_cmd[0]);
			initializer(current_cmd, cmd_type);
                        free(current_cmd);
		 }
                free(cmds);
	}
}
