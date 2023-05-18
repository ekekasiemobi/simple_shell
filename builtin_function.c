#include "main.h"

/**
 * exit_shell - exits shell
 * @tokenized_command: command entered
 *
 * Return: void
 */
void exit_shell(char **tokenized_command)
{
	char *shell_name = NULL;
	char *line = NULL;
	char **cmds = NULL;
	int status = 0;
	int num_token = 0, arg;
	const char *error_message = "$: too many arguments\n";

	for (; tokenized_command[num_token] != NULL; num_token++)
		;
	{

		if (num_token == 1)
		{
			free_array(tokenized_command);
			free(line);
			free(cmds);
			exit(status);
		}
		else if (num_token == 2)
		{
			arg = _atoi(tokenized_command[1]);
		

			if (arg == -1)
			{
				write(STDERR_FILENO, shell_name, strlen(shell_name));
				write(STDERR_FILENO, ": 1: exit: error ", strlen(": 1: exit: error "));
				write(STDERR_FILENO, tokenized_command[1], strlen(tokenized_command[1]));
				write(STDERR_FILENO, "\n", 1);
				status = 2;
			}
			else
			{
				free(line);
				free(tokenized_command);
				free(cmds);
				exit(arg);
			}
		}
		else
		write(STDERR_FILENO, error_message, strlen(error_message));
	}
}
