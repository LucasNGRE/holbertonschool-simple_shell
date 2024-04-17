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
	ssize_t bytes_numb;
	char **args;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		fflush(stdout);
		bytes_numb = getline(&user_input, &len, stdin);
		user_input[_strlen(user_input) - 1] = '\0';
		dinfo("user_input: %s", user_input);

		if (bytes_numb == -1)
		{
			printf("\n");
			break;
		}
		if (_strlen(user_input) == 0)
			continue;
		if (bytes_numb <= 1)
			continue;
		args = get_arg(user_input);
		execute(args), free_args(args);
	}
	return (0);
}
