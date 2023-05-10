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


int main(int ac, char **argv)
char *prompt_read(ssize_t *fd_check);
int determine_command_type(char *command);
void initializer(char **tokenized_cmd, int cmd_type);


#endif
