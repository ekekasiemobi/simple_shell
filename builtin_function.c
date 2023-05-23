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


/**
 * cd_command - change the current directory
 * @args: array of command arguments
 * @environ: environment variables
 * Return: 1 on success, -1 on error
 */
int cd_command(char **args)
{
	char *new_dir;
	char old_dir[PATH_MAX];
	int result;

	if (args[1] == NULL || _strcmp(args[1], "~") == 0)
		new_dir = _getenv("HOME");
	else if (_strcmp(args[1], "-") == 0)
	{
		new_dir = _getenv("OLDPWD");
		if (new_dir == NULL)
		{
			print_error(args, "OLDPWD not set\n");
			return (-1);
		}
	}
	else
		new_dir = args[1];

	if (new_dir == NULL)
	{
		print_error(args, "HOME not set\n");
		return (-1);
	}

	if (getcwd(old_dir, sizeof(old_dir)) == NULL)
	{
		print_error(args, "getcwd error\n");
		return (-1);
	}

	result = chdir(new_dir);
	if (result != 0)
	{
		print_error(args, "chdir error\n");
		return (-1);
	}
	 /* use custom setenv */
	if (setenv("OLDPWD", old_dir, 1) == -1)
	{
		print_error(args, "setenv error\n");
		return (-1);
	}
	if (_strcmp(args[0], "cd") == 0 || _strcmp(args[0], "PWD") == 0)
	{
		if (getcwd(old_dir, sizeof(old_dir)) == NULL)
		{
			print_error(args, "getcwd error\n");
			return (-1);
		}
		/* use custom setenv */
		if (setenv("PWD", old_dir, 1) == -1)
		{
			print_error(args, "setenv error\n");
			return (-1);
		}
	}

	return (1);
}
