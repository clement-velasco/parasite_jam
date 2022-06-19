/*
** EPITECH PROJECT, 2022
** parasite
** File description:
** touch_enemy
*/

#include "my.h"
#include "parasite.h"

static int is_touch_mt(sfRenderWindow *win, obj_t *mt, obj_t *para)
{
    sfVector2i ref = sfMouse_getPositionRenderWindow(win);
    sfVector2f pos = mt->pos;
    int test = 0;

    if (pos.x >= (ref.x - 30) && pos.y <= (ref.x + 30))
        test ++;
    if (pos.y >= (ref.y - 30) && pos.y <= (ref.y + 30))
        test ++;
    if (test == 2) {
        return 1;
    }
    return 0;
}

int touch_enemy(sfRenderWindow *win, all_obj_t *obj)
{
    obj_t *mt = obj->enemy;
    obj_t *para = obj->cho_gath;

    while (mt) {
        if (is_touch_mt(win, mt, para) == 1)
            return 1;
        mt = mt->next;
    }
    return 0;
}