/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_nblen
*/

#include "my.h"

int my_nblen(int nb)
{
    int len = 0;

    if (nb < 0) {
        nb = nb * -1;
        len++;
    }
    while (nb != 0) {
        nb = nb / 10;
        len ++;
    }
    return len;
}
