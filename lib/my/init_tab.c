/*
** EPITECH PROJECT, 2021
** day08
** File description:
** init_tab
*/

#include <stdlib.h>

int clc_cara(char c);

static int clc_len_word(char const *str, int nb)
{
    int len = 0;
    int test = 0;
    int cond = 0;
    int next = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        test = clc_cara(str[i]);
        next = clc_cara(str[i + 1]);
        if (test == 1 && i == 0)
            cond--;
        len++;
        if (test != 0 && cond == nb)
            return len - 1;
        if (test != 0 && cond != nb && next == 0) {
            len = 0;
            cond++;
        }
        next = 0;
    }
    return len;
}

int clc_len_all_word(char const *str)
{
    int len = 0;
    int test = 0;
    int next = 0;
    int first = clc_cara(str[0]);

    for (int i = 0; str[i] != '\0'; i++) {
        test = clc_cara(str[i]);
        next = clc_cara(str[i + 1]);
        if (first == 0) {
            len++;
            first = 1;
        }
        if (test != 0 && next == 0)
            len = len + 1;
        test = 0;
    }
    return len;
}

char **init_tab(char const *str)
{
    int len_all_word = clc_len_all_word(str);
    int len_word = 0;
    char **tab = malloc(sizeof(char *) * (len_all_word + 1));

    for (int i = 0; i < len_all_word; i++) {
        len_word = clc_len_word(str, i);
        tab[i] = malloc(sizeof(char) * (len_word + 1));
        }
    return tab;
}
