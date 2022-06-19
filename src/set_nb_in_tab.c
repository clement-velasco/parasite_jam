/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** set_nb_in_tab
*/

#include "my.h"
#include "parasite.h"

static int calc_len(char *str)
{
    int len = 1;

    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ')
            len += 1;
    }
    return len;
}

static int set_nb(char *str, int index)
{
    int i = 0;
    int nb = 0;

    for (int c = 0; c != index; i++) {
        if (str[i] == ' ')
            c++;
    }
    nb = my_getnbr(&str[i]);
    return nb;
}

int *set_nb_in_tab(char *str)
{
    int len = calc_len(str);
    int *tab = malloc(sizeof(int) * len);

    for (int i = 0; i < len; i++)
        tab[i] = set_nb(str, i);
    return tab;
}

int *copy_tab(int *tab)
{
    int *new = malloc(sizeof(int) * 11);

    for (int i = 0; i < 11; i++)
        new[i] = tab[i];
    return new;
}