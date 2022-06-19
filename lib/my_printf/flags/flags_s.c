/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** flags_s
*/

#include "my.h"

info_t flags_s(info_t info, va_list ap)
{
    char *str = va_arg(ap, char *);
    int max = my_strlen(str);

    if (info.precision == 1)
        info.precision = max;
    for (int i = 0; i < info.precision && str[i] != '\0'; i++) {
        my_putchar(str[i]);
        info.nb_cara += 1;
    }
    return info;
}

