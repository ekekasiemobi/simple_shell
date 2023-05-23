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
