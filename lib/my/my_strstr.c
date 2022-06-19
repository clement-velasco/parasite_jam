/*
** EPITECH PROJECT, 2021
** day06
** File description:
** my_strstr
*/

#include <stddef.h>

int my_strlen(char const *str);

static int verif(char *str, char const *to_find, int i)
{
    int len = my_strlen(to_find);

    for (int c = 0; c < len; c++) {
        if (str[i] != to_find[c])
            return 84;
        i++;
    }
    return 0;
}

char *my_strstr(char *str, char const *to_find)
{
    int len = my_strlen(to_find);
    int i = 0;

    while (str[i + len] != '\0') {
        if (verif(str, to_find, i) == 0)
            return &str[i];
        i++;
    }
    return NULL;
}
