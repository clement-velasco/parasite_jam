/*
** EPITECH PROJECT, 2021
** day08
** File description:
** my_strdup
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *dest = malloc(sizeof(char) * (len + 1));

    for (int i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[len] = '\0';
    return dest;
}
