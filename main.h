#ifndef MAIN_H
#define MAIN_H
#define MAX_ARGS 100

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#include "debug.h"

extern char **environ;
void execute(char **args);
char **get_arg(char *user_input);
size_t _strlen(const char *str);

#endif
