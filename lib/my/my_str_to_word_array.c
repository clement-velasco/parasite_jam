/*
** EPITECH PROJECT, 2021
** day08
** File description:
**  my_str_to_word_array
*/

#include <stdlib.h>

typedef struct set_params {
    int len;
    int index;
    int test;
    int next;
    int cond;
} set_params;

char **init_tab(char const *str);

int clc_len_all_word(char const *str);

int clc_cara(char c)
{
    int test = 0;

    if (c == '\n')
        test++;
    return test;
}

static set_params *init_struct(void)
{
    set_params *params = malloc(sizeof(set_params));

    params->len = 0;
    params->index = 0;
    params->cond = 0;
    params->next = 0;
    params->next = 0;
    return params;
}

static int clc_end(set_params *params, char *ligne, int nb)
{
    int res = 0;

    if (params->test != 0 && params->cond == nb) {
        ligne[params->index] = '\0';
        free(params);
        return 1;
        }
        if (params->test != 0 && params->cond != nb && params->next == 0)
            params->cond++;
    return res;
}

static char *set_ligne(char *ligne, char const *str, int nb)
{
    set_params *params = init_struct();

    for (int i = 0; str[i] != '\0'; i++) {
        params->test = clc_cara(str[i]);
        params->next = clc_cara(str[i + 1]);
        if (params->test == 1 && i == 0)
            params->cond--;
        if (params->cond == nb && params->test == 0) {
            ligne[params->index] = str[i];
            params->index++;
        }
        if (clc_end(params, ligne, nb) == 1)
            return ligne;
        params->test = 0;
    }
    ligne[params->index] = '\0';
    free(params);
    return ligne;
}

char **my_str_to_word_array(char const *str)
{
    char **tab = init_tab(str);
    int len = clc_len_all_word(str);

    for (int i = 0; i < len; i++) {
        tab[i] = set_ligne(tab[i], str, i);
    }
    tab[len] = NULL;
    return tab;
}
