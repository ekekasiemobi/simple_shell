#include "main.h"
/**
 * main - shell clone
 * @ac: argument count
 * @argv: array of pointer to strings
 * Return: 1 or 0
 */
int main(int ac, char **argv)
{
	char *user_input, **receive_argv;
	ssize_t fd_check;
	int i, execution_status;
	data_shell datash;

	datash._environ = environ;
	(void)ac;
	(void)argv;

	while (1 == 1)
	{
		user_input = NULL;
		fd_check = 0;
		user_input = prompt_read(&fd_check);
		receive_argv = tokenization(user_input, receive_argv, fd_check);
		if (receive_argv[0] == NULL)
			continue;
		if (_strcmp(receive_argv[0], "exit") == 0)
			handle_exit(user_input, receive_argv);
		if (_strcmp(receive_argv[0], "env") == 0)
		{
			free(user_input);
			_env(&datash);
			continue;
		}
		i = handle_env_commands(receive_argv);
		if (i != 0)
		{
			free(user_input);
			free_array(receive_argv);
			continue;
		}
		execution_status = execute_command(receive_argv);
		if (execution_status == 1)
			print_error(receive_argv, "Command not found\n");
		free(user_input);
		free_array(receive_argv);
	}
	return (0);
}


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
