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
	char **args;
	(void)ac;
	(void)argv;

	args = malloc(sizeof(char *) * 10);
	/* TODO: you'll need a way to create a dynamic array */

	while (1 == 1)
	{
		void (*command)(void);

		user_input = NULL;
		fd_check = 0;

		user_input = prompt_read(&fd_check);
		/* parse user's command */
		receive_argv = parse_user_input(user_input, args, fd_check);
		/* execute user's command */

		command = get_command(receive_argv[0]);
		if (command != NULL)
		{
			(*command)();
			continue;
		}
		execute_command(receive_argv);
		fflush(stdout);
	}
}

