/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** my_rpg
*/

#include "my.h"
#include "parasite.h"

static int scene_management(sfRenderWindow *win, char **conf)
{
    int stat = 1;

    while (stat > 0) {
        if (stat == 1)
            stat = main_menu(win);
        if (stat == 2)
            stat = intro_scene(win, conf);
        if (stat == 2)
            stat = game_management(win, conf);
    }
    return stat;
}

int parasite(void)
{
    int err = 0;
    sfVideoMode mode = {1920, 1080, 30};
    sfRenderWindow *win = sfRenderWindow_create(mode, "parasite",
    sfClose | sfResize, NULL);
    char *conf = open_file("fichier.conf");
    char **tab = NULL;

    if (conf == NULL)
        return -1;
    tab = my_str_to_word_array(conf);
    if (tab == NULL)
        return -1;
    sfRenderWindow_setFramerateLimit(win, 60);
    err = scene_management(win, tab);
    sfRenderWindow_destroy(win);
    return err;
}