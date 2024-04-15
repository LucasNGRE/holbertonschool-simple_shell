#include "main.h"
#define MAX_COMMAND_LENGTH 100

int main(void)
{
char *user_input = NULL;
size_t len = 0;
ssize_t bytes_numb;

	while (1)
	{
		printf("#cisfun$ ");
		fflush(stdout);
		bytes_numb = getline(&user_input, &len, stdin);
		if (strcmp(user_input, "exit"))
			break;
		if (bytes_numb == -1)
		{
			if (isatty(STDIN_FILENO))
			{
				printf("\n");
				break;
			}
			break;
		}
	}
	return (0);
}

