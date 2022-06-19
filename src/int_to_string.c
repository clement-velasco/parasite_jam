/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** int_to_string
*/

#include "my.h"
#include "parasite.h"

char *int_to_string(int nb)
{
    char *str = NULL;
    int len = 0;

    if (nb == 0)
        return "0";
    for (int i = nb; i >= 1; i = i / 10, len++);
    str = malloc(sizeof(char) * (len + 1));
    str[len] = '\0';
    while (len != 0) {
        len -= 1;
        str[len] = (nb % 10) + '0';
        nb = nb / 10;
    }
    return str;
}