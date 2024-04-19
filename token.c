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
 */
char **get_arg(char *user_input)
{
	char *tok;
	unsigned int count = 0;
	char **args;
	size_t len;

	len = _strlen(user_input);
	args = malloc(sizeof(char *) * len);
	tok = strtok(user_input, " ");
	while (tok)
	{
		dinfo("Current token: %s", tok);
		args[count] = _strdup(tok);
		count++;
		tok = strtok(NULL, " ");
		dinfo("Setted token to: %s\n", args[count - 1]);
	}
	dsuccess("token count is %d\n", count);
	args[count] = NULL;
	return (args);
}
