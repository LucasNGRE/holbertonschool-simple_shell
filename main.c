#include "main.h"
#define MAX_COMMAND_LENGTH 100
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
	char *args[2];

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		fflush(stdout);
		bytes_numb = getline(&user_input, &len, stdin);
		strtok(user_input, "\n");

		if (bytes_numb == -1)
		{
			printf("\n");
			break;
		}
		if (strlen(user_input) == 0)
			continue;
		args[0] = user_input;
        args[1] = NULL;

		if (execve(user_input, args, NULL) == -1 && bytes_numb != 1)
		{
			perror("./shell");
		}
	}
	free(user_input);
	return (0);
}
