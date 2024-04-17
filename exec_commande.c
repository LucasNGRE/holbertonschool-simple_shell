#include "main.h"
/**
 * execute - Execute a command with its arguments
 * @user_input: The command to execute
 * @args: An array of strings containing the command and its arguments
 */
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
