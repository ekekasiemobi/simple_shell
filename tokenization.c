#include "main.h"


/**
 * parse_user_input - split user's command strings
 * @take_user_input: pointer to user_input
 * @argv: array of pointer to strings
 * @fd_check: size of input read in bytes
 * Return: array of pointer to strings
 */

char **parse_user_input(char *take_user_input, char **argv, ssize_t fd_check)
{
	char *user_input_copy, *parse_token;
	const char *delimiter;
	int token_count = 0, num = 0;
	int token_length;

	delimiter = " \n";

	user_input_copy = malloc(sizeof(char) * fd_check);
	if (user_input_copy == NULL)
	{
		perror("Error: cannot allocate memory");
		return (NULL);
	}
	/* add null byte to end */
	s_copy(user_input_copy, take_user_input);
	user_input_copy[sizeof(char) * fd_check - 1] = '\0';
	parse_token = strtok(take_user_input, delimiter);

	while (parse_token != NULL)
	{
		token_count++;
		parse_token = strtok(NULL, delimiter);
	}
	token_count++;


	argv = malloc(sizeof(char *) * token_count);
	parse_token = strtok(user_input_copy, delimiter);
	for (num = 0; parse_token != NULL; num++)
	{
		token_length = s_len(parse_token);
		argv[num] = malloc(sizeof(char) * token_length + 1);
		argv[num][token_length] = '\0';
		s_copy(argv[num], parse_token);
		parse_token = strtok(NULL, delimiter);
	}
	argv[num] = NULL;
	return (argv);
}
