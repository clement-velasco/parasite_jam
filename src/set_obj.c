/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** set_obj
*/

#include "my.h"
#include "parasite.h"

static obj_t *set_scale(obj_t *new, sfVector2f scale)
{
    sfSprite_setScale(new->sprite, scale);
    new->scale = scale;
    new->option.value = 0;
    new->option.type = 0;
    return new;
}

obj_t *set_elem(obj_t *prev, char *path, sfVector2f pos, sfVector2f scale)
{
    obj_t *new = malloc(sizeof(obj_t));
    obj_t *tmp = prev;

    if (new == NULL)
        return NULL;
    new->texture = sfTexture_createFromFile(path, sfFalse);
    new->sprite = sfSprite_create();
    new->pos = pos;
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    sfSprite_setPosition(new->sprite, new->pos);
    new = set_scale(new, scale);
    new->collider = sfSprite_getGlobalBounds(new->sprite);
    new->next = NULL;
    if (prev == NULL)
        return new;
    while (prev->next)
        prev = prev->next;
    prev->next = new;
    return tmp;
}