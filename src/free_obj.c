/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** free_obj
*/

#include "my.h"
#include "parasite.h"

void free_obj(obj_t *obj)
{
    obj_t *tmp = obj;

    while (obj != NULL) {
        tmp = obj->next;
        sfSprite_destroy(obj->sprite);
        sfTexture_destroy(obj->texture);
        free(obj);
        obj = tmp;
    }
}

void free_all_obj(all_obj_t *obj)
{
    free_obj(obj->background);
}