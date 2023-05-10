#include "main.h"
/**
 * get_command - returns a function poiner
 *
 * @cmd: the command to be evaluated
 *
 * Return: a function pointer corresponding to the input command
 */

void (*get_command(char *cmd))(void)
{
	if (! (cmd && *cmd))
		return (NULL);

	/* Check if cmd is "exit" */
	if (strcmp(cmd, "exit") == 0)
	{
		/* Return function pointer to exit_program */
		 _exit(0);	
	}

	/* If cmd is not "exit", return NULL */
	return (NULL);
}

