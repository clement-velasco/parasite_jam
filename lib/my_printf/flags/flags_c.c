/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** flags_c
*/

#include "my.h"

info_t flags_c(info_t info, va_list ap)
{
    char c = va_arg(ap, int);
    int len = 1;

    my_putchar(c);
    info.nb_cara += len;
    info.index += 1;
    return info;
}
