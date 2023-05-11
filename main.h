#ifndef MAIN_H
#define MAIN_H

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


char *get_path(char *first_command);

typedef int (*command_func)(void);

typedef struct {
    char *name;
    int (*func)(void);
} command_t;
char *prompt_read(ssize_t *fd_check);
void execute_command(char **receive_argv);
char **parse_user_input(char *take_user_input, ssize_t fd_check);
char **tokenize_user_input(char *user_input);
char *accept_user_input(void);

void exit_program(void);
void exit_shell(int status, char* message);
int main(int ac, char **argv);
typedef struct data_shell data_shell;
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

#endif
