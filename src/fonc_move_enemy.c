/*
** EPITECH PROJECT, 2022
** parasite
** File description:
** fonc_move_enemy
*/

#include "my.h"
#include "parasite.h"

sfVector2f move_a(sfVector2f pos, int value)
{
    pos.x += value;
    pos.y += value;
    return pos;
}

sfVector2f move_b(sfVector2f pos, int value)
{
    pos.x -= value;
    pos.y += value;
    return pos;
}

sfVector2f move_c(sfVector2f pos, int value)
{
    pos.x += value;
    pos.y -= value;
    return pos;
}

sfVector2f move_d(sfVector2f pos, int value)
{
    pos.x -= value;
    pos.y -= value;
    return pos;
}

void *set_fonc_move(sfVector2f pos)
{
    if (pos.x == 0 && pos.y <= (1080 / 2))
        return &move_a;
    if (pos.y == 0 && pos.x <= (1920 / 2))
        return &move_a;
    if (pos.x == 1920 && pos.y <= (1080 / 2))
        return &move_b;
    if (pos.y == 0 && pos.x >= (1920 / 2))
        return &move_b;
    if (pos.x == 0 && pos.y >= (1080 / 2))
        return &move_c;
    if (pos.y == 1080 && pos.x <= (1920 / 2))
        return &move_c;
    if (pos.x == 1920 && pos.y >= (1080 / 2))
        return &move_d;
    if (pos.y == 1080 && pos.x >= (1920 / 2))
        return &move_d;
    return NULL;
}
