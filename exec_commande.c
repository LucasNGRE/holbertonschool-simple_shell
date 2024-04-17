#include "main.h"

void execute(char *user_input, char **args)
{
    pid_t pid;
    int status = EXIT_SUCCESS;

    
    pid = fork();
    if (pid == 0)
    {
        if (execve(user_input, args, environ) == -1)
        {
            perror("./shell");
            exit(status);
        }
        exit(status);
    }
    else if (pid < 0)
    {
        perror("fork failed.");
    }
    else
    {
        wait(&status);
    }
  
}