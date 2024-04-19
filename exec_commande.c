#include "main.h"
/**
 * execute - Execute a command with its arguments
 * @args: An array of strings containing the command and its arguments
 */
void execute(char **args)
{
	pid_t pid;
	int status = EXIT_SUCCESS;

	pid = fork();
	if (pid == 0)
	{
		dinfo("Command is %s", args[0]);
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
/**
 * get_path - Recherche le chemin complet d'un exécutable dans le PATH
 * @args: Un tableau de chaînes de caractères contenant la
 * commande et ses arguments
 *
 * Return: Un tableau de chaînes de caractères contenant
 * le chemin complet de l'exécutable,
 *         ou NULL s'il n'est pas trouvé dans le PATH ou en cas d'erreur.
 */
char **get_path(char **args)
{
	char *path = getenv("PATH");
	char *copy = _strdup(path);
	char *path_token;
	char *alloc_memory_path;

	if (copy == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}
	path_token = strtok(copy, ":");

	while (path_token != NULL)
	{
		dinfo("path_token: %s\n", path_token);
		alloc_memory_path = malloc(sizeof(char) *
		(_strlen(path_token) + _strlen(args[0]) + 2));
		if (alloc_memory_path == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		sprintf(alloc_memory_path, "%s/%s", path_token, args[0]);
		if (access(alloc_memory_path, X_OK) == 0)
		{
			dsuccess("alloc_memory_path: %s\n", alloc_memory_path);
			_strcpy(args[0], alloc_memory_path);
			free (copy);
			return (args);
		}
		free(alloc_memory_path);
		path_token = strtok(NULL, ":");
	}
	free(copy);

	return (NULL);
}
