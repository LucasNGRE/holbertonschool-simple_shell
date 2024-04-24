#include "main.h"

/**
 * free_args - Free args
 * @args: Arguments
 * Return: void
 */
void free_args(char **args)
{
	int i = 0;

	while (args[i])
	{
		dinfo("Freeing args[%d]: %s", i, args[i]);
		free(args[i]);
		i++;
	};
	dinfo("Freeing args");
	free(args);
}

/**
 * is_path - checks if the command is a path
 * @command: command to check
 * Return: 1 if it is a path, 0 if not
 */
int is_path(char *command)
{
    int i = 0;

    while (command[i])
    {
        if (command[i] == '/')
            return (1);
        i++;
    };
    return (0);
}

/**
 * main - Entry point for the simple_shell
 *
 * Return: Always 0
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	char *user_input = NULL;
	size_t len = 0;
	ssize_t bytes_numb = 0;
	char **args;
	char *name = argv[0];
	int is_interactive = isatty(STDIN_FILENO);

	while (bytes_numb != -1)
	{
		if (is_interactive)
			printf("#cisfun$ ");
		fflush(stdout);
		bytes_numb = getline(&user_input, &len, stdin);
		if (bytes_numb == -1)
		{
			if (is_interactive)
				printf("\n");
			free(user_input);
			exit(EXIT_SUCCESS);
		}
		user_input[_strlen(user_input) - 1] = '\0';
		if (_strcmp(user_input, "exit") == 0)
		{
			free(user_input);
			exit(EXIT_SUCCESS);
		}
		else if (_strcmp(user_input, "env") == 0)
		{
			environnement();
			continue;
		}
		args = get_arg(user_input);
		if (args[0] == NULL)
		{
			free_args(args);
			continue;
		}
		args = get_path(args);
		if (!is_path(args[0]))
		{
			fprintf(stderr,
        	"%s: %s: command not found\n",
    		name,
    		user_input);
			free_args(args);
			continue;
		}
		execute(args), free_args(args);
	}
	return (0);
}