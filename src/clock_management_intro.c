/*
** EPITECH PROJECT, 2022
** parasite
** File description:
** clock_management_intro
*/

#include "my.h"
#include "parasite.h"

static void move_para(sfRenderWindow *win, all_clock_t *clock, obj_t *para)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win);
    sfVector2f pos = para->pos;
    int test = (mouse.x - pos.x);
    int add = 20;

    if (test >= -13 && test <= 7)
        return;
    if (mouse.x > pos.x)
        para->pos.x += add;
    if (mouse.x < pos.x)
        para->pos.x -= add;
    if (mouse.y > pos.y)
        para->pos.y += add;
    if (mouse.y < pos.y)
        para->pos.y -= add;
    sfSprite_setPosition(para->sprite, para->pos);
}

static void move_para_anime(all_clock_t *clock, obj_t *para)
{
    para->rect.top += 64;
    if (para->rect.top >= 6 * 50)
        para->rect.top = 0;
    sfSprite_setTextureRect(para->sprite, para->rect);
}

void clock_management_intro(sfRenderWindow *win, all_clock_t *clock, all_obj_t *obj)
{
    obj_t *para = obj->cho_gath;

    clock->time = sfClock_getElapsedTime(clock->clock);
    clock->anime.sec = clock->time.microseconds / 1000000.0;
    clock->move.sec = clock->time.microseconds / 1000000.0;
    if (clock->anime.sec >= clock->anime.ref) {
        move_para_anime(clock, obj->cho_gath);
        clock->anime.ref = clock->anime.sec + 0.2;
    }
    if (clock->move.sec >= clock->move.ref) {
        move_para(win, clock, obj->cho_gath);
        clock->move.ref = clock->move.sec + 0.05;
    }
}