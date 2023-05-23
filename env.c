#include "main.h"

/**
 * _env - lists the enviromental variables
 *
 * @shell_data: the date.
 * Return: return 1 when successful
 */
int _env(data_shell *shell_data)
{
	int i = 0;

	while (shell_data->_environ[i])
	{
		int j = 0;

		while (shell_data->_environ[i][j])
		{
			write(STDOUT_FILENO, &shell_data->_environ[i][j], 1);
			j++;
		}

		write(STDOUT_FILENO, "\n", 1);
		i++;
	}

	shell_data->status = 0;

	return (1);
}
