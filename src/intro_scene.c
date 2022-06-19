/*
** EPITECH PROJECT, 2022
** parasite
** File description:
** intro_scene
*/

#include "my.h"
#include "parasite.h"

static void display_obj_intro(sfRenderWindow *win, all_obj_t *obj)
{
    display(win, obj->background);
    display(win, obj->cho_gath);
    display(win, obj->enemy);
    display(win, obj->info);
    display_text(win, obj->quest);
    sfRenderWindow_display(win);
}

static int test_start_game(obj_t *para)
{
    sfVector2f pos = para->pos;
    int test = 0;

    if (pos.x >= 900 && pos.x <= 940)
        test ++;
    if (pos.y >= 360 && pos.y <= 720)
        test ++;
    if (test == 2)
        return 1;
    return 0;
}

int analyse_events_intro(sfRenderWindow *win, sfEvent evt, all_obj_t *obj, char **conf)
{
    int sad = 0;

    if (evt.type == sfEvtClosed)
        sfRenderWindow_close(win);
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(win);
    if (sfKeyboard_isKeyPressed(sfKeySpace))
        pause_menu(win, obj, conf);
    if (test_start_game(obj->cho_gath) == 1)
        return 1;
    return sad;
}

static all_clock_t *init_clock(void)
{
    all_clock_t *clock_elem = malloc(sizeof(all_clock_t));

    clock_elem->clock = sfClock_create();
    clock_elem->anime = (sec_info_t) {0, 0.2};
    clock_elem->move = (sec_info_t) {0, 0.05};
    return clock_elem;
}

int intro_scene(sfRenderWindow *win, char **conf)
{
    sfEvent evt;
    all_obj_t *obj = init_obj_intro(conf);
    all_clock_t *clock = init_clock();
    int stat = 0;

    if (obj == NULL)
        return ERROR;
    sfRenderWindow_clear(win, sfWhite);
    while (sfRenderWindow_isOpen(win) && stat == 0) {
        while (sfRenderWindow_pollEvent(win, &evt))
            stat = analyse_events_intro(win, evt, obj, conf);
        clock_management_intro(win, clock, obj);
        display_obj_intro(win, obj);
    }
    display_interlude(win);
    return 2;
}