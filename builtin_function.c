#include "main.h"
/**
 * exit_shell - exits shell
 * @tokenized_command: command entered
 *
 * Return: void
 */
void exit_shell(char **command)
{
	char *shell_name = NULL;
	char *line = NULL;
	char **cmds = NULL;
	int status = 0;
	int i = 0, arg;
	const char *error_msg = "$: too many arguments\n";

	while (command[i] != NULL)
		i++;
	{

		if (i == 1)
		{
			free_array(command);
			free(line);
			free(cmds);
			exit(status);
		}
		else if (i == 2)
		{
			arg = _atoi(command[1]);
			if (arg == -1)
			{
				display_exit_error(shell_name, command[1]);
				status = 2;
			}
			else
			{
				free(line);
				free(command);
				free(cmds);
				exit(arg);
			}
		}
		else
		write(STDERR_FILENO, error_msg, strlen(error_msg));
	}
}


/**
 * handle_exit - Handle 'exit' command
 * @user_input: User input string
 * @receive_argv: Array of command arguments
 */
void handle_exit(char *user_input, char **receive_argv)
{
	free(user_input);
	exit_shell(receive_argv);
}
