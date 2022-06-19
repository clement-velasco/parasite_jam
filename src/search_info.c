/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** search_info
*/

#include "my.h"
#include "parasite.h"

char *test_nb_cara(char *str, char *test, int nb)
{
    char *new = NULL;
    int length = my_strlen(str) - (nb + 1);

    for (int i = 0; i < nb; i++) {
        if (str[i] != test[i])
            return NULL;
    }
    new = malloc(sizeof(char) * (length + 1));
    if (new == NULL)
        return NULL;
    nb += 1;
    for (int i = 0; str[nb]; i++, nb++)
        new[i] = str[nb];
    new[length] = '\0';
    return new;
}

static char *set_filename(char *dos_conf)
{
    char *test = test_nb_cara(dos_conf, my_strdup("sprite:"), 7);

    return test;
}

static sfVector2f set_pos_or_scale(char *dos_conf, char *str_test, int size)
{
    char *test = test_nb_cara(dos_conf, str_test, size);
    sfVector2f value = (sfVector2f) {0, 0};
    int i = 0;
    char *copy = test;

    if (test == NULL) {
        return value;
    }
    value.x = my_getnbr(test);
    for (i = 0; test[i] != ' '; i++);
    test = &test[i + 1];
    value.y = my_getnbr(test);
    free(copy);
    return value;
}

int *set_rect_or_stat(char *dos_conf, char *str_test, int size)
{
    char *test = test_nb_cara(dos_conf, str_test, size);
    int *list = NULL;

    if (test == NULL)
        return NULL;
    list = set_nb_in_tab(test);
    free(test);
    return list;
}

info_sprite_t *search_info(char *key, char **dos_conf)
{
    info_sprite_t *info = malloc(sizeof(info_sprite_t));
    int i = 0;

    for (; my_strcmp(key, dos_conf[i]) != 0 && dos_conf[i] != NULL; i++);
    if (dos_conf[i] == NULL)
        return NULL;
    info->filename = set_filename(dos_conf[i + 1]);
    info->pos = set_pos_or_scale(dos_conf[i + 2], "pos:", 4);
    info->scale = set_pos_or_scale(dos_conf[i + 3], "scale:", 6);
    info->rect = set_rect_or_stat(dos_conf[i + 4], "rect:", 5);
    info->stat = set_rect_or_stat(dos_conf[i + 5], "stat:", 5);
    return info;
}