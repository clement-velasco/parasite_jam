/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** is_overlap
*/

#include "my.h"
#include "parasite.h"

int is_overlap(sfRenderWindow *win, obj_t *obj)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(win);

    while (obj) {
        if (sfFloatRect_contains(&obj->collider, mouse_pos.x, mouse_pos.y)) {
            sfSprite_setColor(obj->sprite, sfBlue);
            return obj->option.type;
        }
        else
            sfSprite_setColor(obj->sprite, sfWhite);
        obj = obj->next;
    }
    return 0;
}