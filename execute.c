#include "main.h"

/**
 * execute_command - execute user's command
 * @receive_argv: array to pointer of strings
 * Return: nothing
 */


void execute_command(char **receive_argv)
{
	char *first_command;
	char *final_cmd;
	pid_t child_process;
	int process_status;

	first_command = NULL;
	final_cmd = NULL;
	child_process = -1;

	if (receive_argv)
	{
		child_process = fork();

		if (child_process == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (child_process == 0)
		{
			first_command = receive_argv[0];
			final_cmd = get_path(first_command);

			if (execve(final_cmd, receive_argv, NULL) == -1)
			{
				perror("execve");
				_exit(EXIT_FAILURE);
			}
		}
		else
		{
			pid_t terminated_process = waitpid(child_process, &process_status, 0);
			if (terminated_process == -1)
			{
				perror("waitpid");
				exit(EXIT_FAILURE);
			}
		}
	}
}
