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

/**
 * initializer - executes a command based on it's type
 * @tokenized_cmd: tokenized form of the command (ls -l == {ls, -l, NULL})
 * @cmd_type: type of the command
 *
 * Return: void
 */
void initializer(char **tokenized_cmd, int cmd_type)
{
        void (*func)(char **cmd);

        if (cmd_type == EXT_COMMAND)
        {
                if (execve(tokenized_cmd[0], tokenized_cmd, NULL) == -1)
                {
                        perror(_getenv("PWD"));
                        exit(2);
                }
        }
        if (cmd_type == PATH_COMMAND)
        {
                if (execve(find_path(tokenized_cmd[0]), tokenized_cmd, NULL) == -1)
                {
                        perror(_getenv("PWD"));
                        exit(2);
                }
        }
        if (cmd_type == INT_COMMAND)
        {
                func = get_func(tokenized_cmd[0]);
                func(tokenized_cmd);
        }
        if (cmd_type == INVALID_COMMAND)
        {
                print(shell_name, STDERR_FILENO);
                print(": 1: ", STDERR_FILENO);
                print(tokenized_cmd[0], STDERR_FILENO);
                print(": not found\n", STDERR_FILENO);
                status = 127;
        }
}
