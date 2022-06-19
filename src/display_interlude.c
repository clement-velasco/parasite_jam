/*
** EPITECH PROJECT, 2022
** parasite
** File description:
** display_interlude
*/

#include "my.h"
#include "parasite.h"

void display_interlude(sfRenderWindow *win)
{
    int stat = 0;
    sfClock *clock = sfClock_create();
    sfTime time;
    float sec;

    while (stat == 0) {
        time = sfClock_getElapsedTime(clock);
        sec = time.microseconds / 1000000.0;
        sfRenderWindow_clear(win, sfBlack);
        sfRenderWindow_display(win);
        if (sec >= 1)
            stat = 1;
    }
    sfClock_destroy(clock);
}