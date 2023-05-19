#include "main.h"
#include <unistd.h>

/**
 * main - Entry point of the shell program
 * @ac: Argument count
 * @argv: Array of arguments
 * Return: Exit status
 */
int main(int ac, char **argv)
{
	data_shell datash;

	datash._environ = environ;
	(void)ac;
	(void)argv;

	process_input(&datash);

	return (0);
}

/**
 * process_input - Process user input and execute commands
 * @datash: Data structure for shell variables
 */
void process_input(data_shell *datash)
{
	char *user_input;
	ssize_t fd_check;
	char **receive_argv;

	while (1)
	{
		user_input = prompt_read(&fd_check);
		receive_argv = parse_input(user_input, &fd_check);

		if (receive_argv == NULL || receive_argv[0] == NULL)
		{
			continue;
		}

		if (strcmp(receive_argv[0], "exit") == 0)
		{
			free(user_input);
			exit_shell(receive_argv);
			continue;
		}
		else if (strcmp(receive_argv[0], "env") == 0)
		{
			free(user_input);
			_env(datash);
			continue;
		}
		else
		{
			execute(receive_argv);
		}

		free(user_input);
		free_array(receive_argv);
	}
}

/**
 * parse_input - Parse user input into an array of arguments
 * @input: User input string
 * @fd_check: Pointer to store the number of bytes read
 * Return: Array of arguments
 */
char **parse_input(char *input, ssize_t *fd_check)
{
	char **receive_argv;

	receive_argv = tokenization(input, NULL, *fd_check);

	if (receive_argv == NULL || receive_argv[0] == NULL)
		return (NULL);

	if (handle_env_commands(receive_argv) != 0)
	{
		free_array(receive_argv);
		return (NULL);
	}

	return (receive_argv);
}

/**
 * execute - Execute the given command
 * @receive_argv: Array of command and arguments
 */
void execute(char **receive_argv)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execvp(receive_argv[0], receive_argv) == -1)
		{
			if (errno == ENOENT)
				print_error(receive_argv, "Command not found\n");
			else
				perror("Execution error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}

/**
 * free_array - Frees a dynamically allocated array of strings.
 * @argv: The array of strings to be freed.
 *
 */
void free_array(char **argv)
{
	char **temp = argv;

	for (; *temp != NULL; temp++)
	{
		free(*temp);
		*temp = NULL;
	}
	free(argv);
}
