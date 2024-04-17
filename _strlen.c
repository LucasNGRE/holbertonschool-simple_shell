#include <stdio.h>

size_t _strlen(const char *str)
{
    const char *s = str;
    while (*s)
        ++s;
    return (s - str);
}
