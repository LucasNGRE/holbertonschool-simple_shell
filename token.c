#include "main.h"
/**
 * get_arg - Tokenize a string into an array of strings
 * @user_input: The string to tokenize
 *
 * Return: An array of strings containing the tokens,
 * or NULL if an error occurs
 */
char **get_arg(char *user_input)
{
	char *tok;
	unsigned int count = 0;
	char **args;
	size_t len = 0;

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