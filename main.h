#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
<<<<<<< HEAD
=======
#include <sys/wait.h>
extern char **environ;
void execute(char *user_input, char **args);
void get_arg(char *user_input, char **args, size_t max_args);
>>>>>>> ad4c583a8f61117809699da72ba40b1bba345e35

#endif