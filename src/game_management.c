/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** game_management
*/

#include "my.h"
#include "parasite.h"

static all_clock_t *init_clock(void)
{
    all_clock_t *clock_elem = malloc(sizeof(all_clock_t));

    clock_elem->clock = sfClock_create();
    clock_elem->anime = (sec_info_t) {0, 0.15};
    clock_elem->move = (sec_info_t) {0, 0.05};
    clock_elem->add = (sec_info_t) {0, 3};
    clock_elem->usage = (sec_info_t) {0, 3};
    clock_elem->move_n = (sec_info_t) {0, 0.15};
    clock_elem->rec = (sec_info_t) {0, 3};
    return clock_elem;
}

int game_management(sfRenderWindow *win, char **conf)
{
    sfEvent evt;
    all_obj_t *obj = init_obj(conf);
    all_clock_t *clock = init_clock();
    int stat = 0;

    if (obj == NULL || clock == NULL)
        return ERROR;
    sfRenderWindow_clear(win, sfWhite);
    while (sfRenderWindow_isOpen(win) && stat == 0) {
        while (sfRenderWindow_pollEvent(win, &evt) && stat == 0)
            stat = analyse_events(win, evt, obj, conf);
        clock_management_intro(win, clock, obj);
        obj->enemy = management_evt(clock, obj, conf);
        display_obj(win, obj);
        // printf("spped: %d, time: %d\n", obj->add.speed, obj->add.time);
    }
    free_all_obj(obj);
    return 0;
}