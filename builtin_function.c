#include "main.h"
/**
 * exit_shell - this function exits the simple_shell
 * @receive_argv: this is the cmd entered
 *
 * Return: returns nothing when the shell is exited
 */
void exit_shell(char **receive_argv)
{
	char **cmds = NULL;
	int status = 0;
	int i = 0, arg;
	const char *error_msg = "$: too many arguments\n";

	while (receive_argv[i] != NULL)
		i++;
	{

		if (i == 1)
		{
			free_array(receive_argv);
			free(cmds);
			exit(status);
		}
		else if (i == 2)
		{
			arg = _atoi(receive_argv[1]);
			if (arg == -1)
			{
				print_error(receive_argv, "Illegal number: ");
				_errputs(receive_argv[1]);
				_errputs("\n");
				status = 2;
			}
			else
			{
				free_array(receive_argv);
				free(cmds);
				exit(arg);
			}
		}
		else
		write(STDERR_FILENO, error_msg, strlen(error_msg));
	}
}



