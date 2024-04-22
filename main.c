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
 * main - Entry point for the simple_shell
 *
 * Return: Always 0
 */
int main(void)
{
	char *user_input = NULL;
	size_t len = 0;
	ssize_t bytes_numb = 0;
	char **args;
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
			break;
		}
		user_input[_strlen(user_input) - 1] = '\0';
		if (_strcmp(user_input, "exit") == 0)
			break;
		else if (_strcmp(user_input, "env") == 0)
		{
			environnement();
			continue;
		}
		dinfo("user_input: %s", user_input);

		if (_strlen(user_input) == 0)
			continue;
		if (bytes_numb <= 1)
			continue;
		args = get_arg(user_input);
		args = get_path(args);
		execute(args), free_args(args);
	}
	return (0);
}