/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** analyse_events
*/

#include "my.h"
#include "parasite.h"

static int test_life(all_obj_t *obj)
{
    int life = 0;

    if (obj->enemy->stat.life > 0 && obj->cho_gath->stat.life > 0)
        return 0;
    return 1;
}

int analyse_events(sfRenderWindow *win, sfEvent evt, all_obj_t *obj, char **conf)
{
    if (evt.type == sfEvtClosed)
        sfRenderWindow_close(win);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(win);
    if (sfKeyboard_isKeyPressed(sfKeySpace))
        pause_menu(win, obj, conf);
    if (touch_enemy(win, obj) == 1)
        return 1;
    return 0;
}
