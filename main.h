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


int main(int ac, char **)
char *prompt_read(ssize_t *);
int determine_command_type(char *);
void initializer(char **, int);


#endif
