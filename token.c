#include "main.h"
/**
 * command_counter - Counts the number of individual commands in a string.
 * @user_input: The input string to be analyzed.
 *
 * Return: The number of individual commands.
 */
int command_counter(char *user_input)
{
	int i = 0;
	int count = 0;
	
	while (user_input[i])
	{
		if (user_input[i] == ' ')
		{
			if (user_input[i + 1] != ' ' && user_input[i + 1] != '\n')
				count++;
		}
		i++;
	}
	dinfo("counter : %d", count);
	return (count);
}
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

	len = command_counter(user_input);
	args = malloc(sizeof(char *) * (len + 2));
	tok = strtok(user_input, " ");

	while (tok)
	{
		dinfo("Current token: %s", tok);
		if (_strcmp(tok, " ") != 0 && _strcmp(tok, "\n") != 0)
		{
			dinfo("token : adding '%s' to args", tok);
			args[count] = _strdup(tok);
			count++;
		}
		tok = strtok(NULL, " ");
		dinfo("Setted token to: %s\n", args[count - 1]);
	}
	dsuccess("token count is %d\n", count);
	args[count] = NULL;
	return (args);
}