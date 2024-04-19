#include <stdio.h>

size_t _strlen(const char *str)
{
	const char *s = str;

	while (*s)
		++s;
	return (s - str);
}

char *_strdup(const char *str)
{
	char *new_str;
	size_t len = _strlen(str);

	new_str = malloc(len + 1);
	if (new_str == NULL)
		return (NULL);
	for (size_t i = 0; i < len; i++)
		new_str[i] = str[i];
	new_str[len] = '\0';
	return (new_str);
}

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