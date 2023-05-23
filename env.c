#include "main.h"

/**
 * _env - lists the enviromental variables
 *
 * @datash: the date.
 * Return: return 1 when successful
 */
int _env(data_shell *datash)
{
	int i, j;

	for (i = 0; datash->_environ[i]; i++)
	{

		for (j = 0; datash->_environ[i][j]; j++)
			;

		write(STDOUT_FILENO, datash->_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}


/**
 * handle_env - Handle 'env' command
 * @user_input: User input string
 * @datash: Shell data structure
 */

void handle_env(char *user_input, data_shell *shell_data)
{
	free(user_input);
	_env(shell_data);
}
