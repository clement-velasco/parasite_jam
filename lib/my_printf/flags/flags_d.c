/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** flags_d
*/

#include "my.h"

info_t flags_d(info_t info, va_list ap)
{
    int nb = va_arg(ap, int);
    int len = my_nblen(nb);

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
        len -= 1;
    }
    for (int i = len; i < info.precision; i++) {
        info.nb_cara += 1;
        my_putchar('0');
    }
    my_put_nbr(nb);
    info.nb_cara += len;
    return info;
}
