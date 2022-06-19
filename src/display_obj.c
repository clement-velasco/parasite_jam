/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_obj
*/

#include "my.h"
#include "parasite.h"

void display(sfRenderWindow *win, obj_t *obj)
{
    while (obj) {
        sfRenderWindow_drawSprite(win, obj->sprite, sfFalse);
        obj = obj->next;
    }
}

void display_text(sfRenderWindow *win, text_t *quest)
{
    while (quest) {
        sfRenderWindow_drawText(win, quest->text, sfFalse);
        quest = quest->next;
    }
}

void display_obj(sfRenderWindow *win, all_obj_t *obj)
{
    display(win, obj->background);
    display(win, obj->cho_gath);
    display(win, obj->enemy);
    if (obj->info->option.value != 1) {
        display(win, obj->info);
        display_text(win, obj->quest);
    }
    sfRenderWindow_display(win);
}