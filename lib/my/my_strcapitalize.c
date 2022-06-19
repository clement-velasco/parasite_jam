/*
** EPITECH PROJECT, 2021
** day06
** File description:
** my_strcapitalize
*/

#include <stdio.h>

static void maj_cara(char *str, int i)
{
    if (i == 0)
        return;
    if (str[i - 1] >= 'A' && str[i - 1] <= 'Z') {
        str[i] = str[i] + 32;
    }
    if (str[i - 1] >= 'a' && str[i - 1] <= 'z') {
        str[i] = str[i] + 32;
    }
    if (str[i - 1] >= '1' && str[i - 1] <= '9')
        str[i] = str[i] + 32;
}

static void min_cara(char *str, int i)
{
    if (i == 0) {
        str[i] = str[i] - 32;
        return;
    }
    if (str[i - 1] == ' ')
        str[i] = str[i] - 32;
    if (str[i - 1] >= '!' && str[i - 1] <= '.')
        str[i] = str[i] - 32;
    if (str[i - 1] >= ':' && str[i - 1] <= '@')
        str[i] = str[i] - 32;
    if (str[i - 1] >= '{' && str[i - 1] <= '~')
        str[i] = str[i] - 32;
}

char *my_strcapitalize(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z')
            maj_cara(str, i);
        if (str[i] >= 'a' && str[i] <= 'z')
            min_cara(str, i);
        i++;
    }
    return str;
}
