#include "main.h"
/**
 * get_arg - Parse user input into arguments.
 *
 * Description: This function parses a user input string into
 * individual arguments and stores
 * them in an array of strings. It uses space (' ') as the
 * delimiter to separate
 * the arguments.
 *
 * @user_input: The input string to be parsed.
 * @args: An array of strings where the parsed
 * arguments will be stored.
 * @max_args: The maximum number of arguments that can
 * be stored in `args`.
 */
void get_arg(char *user_input, char **args, size_t max_args)
{
	char *tok;
	unsigned int count = 0;

	user_input[strlen(user_input) - 1] = '\0';
	tok = strtok(user_input, " ");

	while (tok && count < max_args - 1)
	{
		args[count] = tok;
		count++;
		tok = strtok(NULL, " ");
	}
	args[count] = NULL;
}
