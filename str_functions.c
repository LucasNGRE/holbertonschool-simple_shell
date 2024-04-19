#include "main.h"
/**
 * _strlen - Calculate the length of a string.
 * @str: The string to calculate the length of.
 *
 * Return: The length of the string.
 */
size_t _strlen(const char *str)
{
	const char *s = str;

	while (*s)
		++s;
	return (s - str);
}

/**
 * _strdup - Duplicate a string.
 * @str: The string to duplicate.
 *
 * Return: A pointer to the newly allocated memory
 * containing a copy of the string.
 */
char *_strdup(const char *str)
{
	char *new_str;
	size_t len = _strlen(str);
	size_t i;

	new_str = malloc(len + 1);
	if (new_str == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		new_str[i] = str[i];
	new_str[len] = '\0';
	return (new_str);
}

/**
 * _strcpy - Copy a string.
 * @dest: The destination buffer.
 * @src: The source string to copy.
 *
 * Return: A pointer to the destination buffer.
 */
char *_strcpy(char *dest, const char *src)
{
	size_t i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp - Compare two strings.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 *
 * Return: An integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
