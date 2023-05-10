#include "main.h"

/** determine_command_type - determines the type of the command
 * @command: command to be parsed
 *
 * Return: constant representing the type of the command
 * Description -
 *               EXT_COMMAND -> commands like /bin/ls
 *               INT_COMMAND -> commands like exit, env
 *               PATH_COMMAND -> commands found in the PATH like ls
 *               INVALID_COMMAND  -> invalid commands
 */

int determine_command_type(char *command)
{
        int i;
        char *internal_command[] = {"env", "exit", NULL};
        char *path = NULL;

        for (i = 0; command[i] != '\0'; i++)
        {
                if (command[i] == '/')
                        return (EXT_COMMAND);
        }
        for (i = 0; internal_command[i] != NULL; i++)
        {
                if (strcmp(command, internal_command[i]) == 0)
                        return (INT_COMMAND);
        }
        /* check if a command is found in the PATH */
        path = find_path(command);
        if (path != NULL)
        {
                free(path);
                return (PATH_COMMAND);
        }

        return (INVALID_COMMAND);
}
