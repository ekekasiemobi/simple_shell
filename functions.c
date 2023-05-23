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
