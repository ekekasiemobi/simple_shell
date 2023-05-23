#include "main.h"

/**
 * _errputs - Print a string to the standard error
 * @str: The string to be printed
 *
 * Return: The number of characters printed
 */
int _errputs(char *str)
{
	int i;

	if (!(str))
	{
		return (0);
	}
	for (i = 0; str[i]; i++)
	{
		write(2, &str[i], 1);
	}

	return (i);
}
/**
 * print_error - Print an error message to the standard error
 * @av: The array of command and arguments
 * @err: The error message to be printed
 */
void print_error(char **av, char *err)
{
	_errputs(_getenv("_"));
	_errputs(": 1: ");
	_errputs(av[0]);
	_errputs(": ");
	_errputs(err);
}


/**
 * display_exit_error - Display exit error message
 * @shell_name: Name of the shell
 * @arg: Argument causing the error
 */
void display_exit_error(char *shell_name, char *arg)
{
	write(STDERR_FILENO, shell_name, strlen(shell_name));
	write(STDERR_FILENO, ": 1: exit: error ", strlen(": 1: exit: error "));
	write(STDERR_FILENO, arg, strlen(arg));
	write(STDERR_FILENO, "\n", 1);
}
/**
 * cd_check_args - Check and process the arguments for the cd command
 *
 * @args: The command arguments
 * @new_dir: Pointer to store the new directory path
 *
 * Return: 0 on success, -1 on failure
 */
int cd_check_args(char **args, char **new_dir)
{
	if (args[1] == NULL || _strcmp(args[1], "~") == 0)
		*new_dir = _getenv("HOME");
	else if (_strcmp(args[1], "-") == 0)
	{
		*new_dir = _getenv("OLDPWD");
		if (*new_dir == NULL)
		{
			write(STDERR_FILENO, "cd: OLDPWD not set\n", 19);
			return (-1);
		}
	}
	else if (args[1][0] == '$')
	{
		char *env_var = _getenv(args[1] + 1);

		if (env_var == NULL)
		{
			write(STDERR_FILENO, "cd: No such variable\n", 21);
			return (-1);
		}
		*new_dir = env_var;
	}
	else
		*new_dir = args[1];

	if (*new_dir == NULL)
	{
		print_error(args, "HOME not set\n");
		return (-1);
	}

	return (0);
}
/**
 * cd_command - Change the current working directory
 *
 * @args: The command arguments
 *
 * Return: 1 on success, -1 on failure
 */
int cd_command(char **args)
{
	char *new_dir;
	char old_dir[PATH_MAX];
	int result;

	if (cd_check_args(args, &new_dir) == -1)
		return (-1);

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

		if (setenv("PWD", old_dir, 1) == -1)
		{
			print_error(args, "setenv error\n");
			return (-1);
		}
	}

	return (1);
}
