#ifndef MAIN_H
#define MAIN_H


#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define BUFFER_SIZE 1024

extern char **environ;
char *_getline(void);
void handle_exit(char *user_input, char **receive_argv);

int shell_setenv(char **args);
int shell_unsetenv(char **args);
int handle_env_commands(char **args);

typedef struct data_shell {
    char **_environ;
    int status;
} data_shell;
void execute_shell(void *datash, char **receive_argv);
int _env(data_shell *datash);

char *_strtok(char *str, const char *delim);
 char *_strdup(char *dup, char *str);
char *get_path(char *first_command);

typedef int (*command_func)(void);

typedef struct {
    char *name;
    int (*func)(void);
} command_t;

char *prompt_read(ssize_t *fd_check);
int execute_command(char **receive_argv);
char **tokenization(char *take_user_input, char **argv, ssize_t fd_check);

char *accept_user_input(void);

int main(int ac, char **argv);
void (*get_command(char *cmd))(void);

/* strings related */
int s_len(char *string);
void s_copy(char *to, char *from);
void s_cat(char *text_add, char *text);

/* function related */
char **handle_path(void);
int check_ifCommand_exist(char *string);
char **split_string(char *string);

void print_error(char **av, char *err);
int _errputs(char *str);
void print_error(char **av, char *err);

char *_strchr(char *s, char c);
int _strcspn(char *s, char *charset);
int _strcmp(char *s, char *c);

void exit_shell(char **tokenized_command);
void execute_cmd(char **command, int command_type);
int determine_command_type(char *command);
 int _atoi(char *s);

 void free_array(char **argv);

typedef struct {
    char** argv;
} info_t;
int _mycd(info_t* info);
 char *_getenv(const char *name);

#endif

