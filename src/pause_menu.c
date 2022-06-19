/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** pause_menu
*/

#include "my.h"
#include "parasite.h"

static obj_t *init_obj_pause(char **conf)
{
    info_sprite_t *info = search_info("$button", conf);
    obj_t *button = set_elem(NULL, info->filename, info->pos, info->scale);
    sfVector2f new_pos = (sfVector2f) {info->pos.x, info->pos.y + 200};
    int *tmp = info->rect;
    sfIntRect rect = (sfIntRect) {tmp[3], tmp[4], tmp[0], tmp[1]};

    sfSprite_setTextureRect(button->sprite, rect);
    tmp = info->stat;
    rect = (sfIntRect) {tmp[3], tmp[4], tmp[0], tmp[1]};
    button = set_elem(button, info->filename, new_pos, info->scale);
    sfSprite_setTextureRect(button->next->sprite, rect);
    return button;
}

static int analyse_events_pause(sfRenderWindow *win, sfEvent evt, obj_t *obj,
int c)
{
    int stat = is_overlap(win, obj);

    if (c == 0)
        return 0;
    if (evt.type == sfEvtClosed)
        sfRenderWindow_close(win);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(win);
    if (sfKeyboard_isKeyPressed(sfKeySpace))
        return 1;
    if (sfMouse_isButtonPressed(sfMouseLeft) && stat != 0)
        return 1;
    return 0;
}

void pause_menu(sfRenderWindow *win, all_obj_t *obj, char **conf)
{
    obj_t *button = init_obj_pause(conf);
    sfEvent evt;
    int stat = 0;
    int start = 0;

    sfSprite_setColor(obj->background->sprite, sfRed);
    while (sfRenderWindow_isOpen(win) && stat == 0) {
        while (sfRenderWindow_pollEvent(win, &evt))
            stat = analyse_events_pause(win, evt, button, start);
        display(win, obj->background);
        sfRenderWindow_display(win);
        start = 1;
    }
    free_obj(button);
    sfSprite_setColor(obj->background->sprite, sfWhite);
}
