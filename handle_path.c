#include "main.h"

/**
 * get_path - get the path of each command
 * @first_command: user input
 * Return: command path
 */

char *get_path(char *first_command)
{
	struct stat path_test;
	char *cmd_path, *cmd_path_copy, *delimiter;
	char *parse_token, *path_to_file;
	int dir_len, length_user_command, path_to_file_len;

	delimiter = ":";
	cmd_path = getenv("PATH");

	if (!cmd_path)
		return (NULL);
	cmd_path_copy = strdup(cmd_path);
	length_user_command = strlen(first_command);

	parse_token = strtok(cmd_path_copy, delimiter);

	while (parse_token != NULL)
	{
		dir_len = strlen(parse_token);
		path_to_file_len = length_user_command + dir_len + 2;
		/* added ↑ */
		path_to_file = malloc(path_to_file_len);

		if (!path_to_file)
		{
			free(cmd_path_copy);
			return (NULL);
		}

		strcpy(path_to_file, parse_token);
		strcpy(path_to_file, "/");
		strcpy(path_to_file, first_command);


		if (stat(path_to_file, &path_test) == 0)
		{
			free(cmd_path_copy);
			return (path_to_file);
		}
		free(path_to_file);
		parse_token = strtok(NULL, delimiter);
	}

	free(cmd_path_copy);
	if (stat(first_command, &path_test) == 0)
		return (strdup(first_command));
	return (NULL);
}
