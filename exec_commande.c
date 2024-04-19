#include "main.h"
/**
 * execute - Execute a command with its arguments
 * @user_input: The command to execute
 * @args: An array of strings containing the command and its arguments
 */
void execute(char **args)
{
	pid_t pid;
	int status = EXIT_SUCCESS;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
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

void get_path(char **get_args)
{
	char *path = getenv("PATH");
	char *copy = _strdup(path);
	char *path_token;
	char alloc_memory_path[512];

	if (copy == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}
	path_token = strtok(copy, ":");

	while (path_token != NULL)
	{
		copy = alloc_memory_path;
		if (access(alloc_memory_path, X_OK) == 0)
		{
			derror("alloc_memory_path: %s\n", alloc_memory_path);
			get_args[0] = _strdup(alloc_memory_path);
			free(copy);
			break;
		}
		path_token = strtok(NULL, ":");

	}
	free(copy);
}
