#include "main.h"
#define MAX_COMMAND_LENGTH 100

int main(void)
{
	char *user_input = NULL;
	size_t len = 0;
	ssize_t bytes_numb;

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
		char *args[] = {user_input, NULL};
        if (execve(user_input, args, NULL) == -1 && bytes_numb != 1)
        {
            perror("./prompt");
        }
	}
	free(user_input);
	return (0);
}

